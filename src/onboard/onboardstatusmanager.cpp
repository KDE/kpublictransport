/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "onboardstatusmanager_p.h"
#include "logging.h"

#include "backend/scriptedrestonboardbackend_p.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMetaProperty>
#include <QNetworkAccessManager>

using namespace KPublicTransport;

void initResources()
{
    Q_INIT_RESOURCE(data);
}

OnboardStatusManager::OnboardStatusManager(QObject *parent)
    : QObject(parent)
{
    qCDebug(Log);
    initResources();

    m_positionUpdateTimer.setSingleShot(true);
    m_positionUpdateTimer.setTimerType(Qt::VeryCoarseTimer);
    connect(&m_positionUpdateTimer, &QTimer::timeout, this, [this]() {
        if (m_backend) {
            m_pendingPositionUpdate = true;
            m_backend->requestPosition(nam());
        }
    });
    m_journeyUpdateTimer.setSingleShot(true);
    m_journeyUpdateTimer.setTimerType(Qt::VeryCoarseTimer);
    connect(&m_journeyUpdateTimer, &QTimer::timeout, this, [this]() {
        if (m_backend) {
            m_pendingJourneyUpdate = true;
            m_backend->requestJourney(nam());
        }
    });

    connect(&m_wifiMonitor, &WifiMonitor::statusChanged, this, &OnboardStatusManager::wifiChanged);
    connect(&m_wifiMonitor, &WifiMonitor::wifiChanged, this, &OnboardStatusManager::wifiChanged);
    wifiChanged();
}

OnboardStatusManager::~OnboardStatusManager() = default;

OnboardStatusManager* OnboardStatusManager::instance()
{
    static OnboardStatusManager mgr;
    return &mgr;
}

OnboardStatus::Status OnboardStatusManager::status() const
{
    return m_status;
}

void OnboardStatusManager::setStatus(OnboardStatus::Status status)
{
    if (m_status == status) {
        return;
    }

    m_status = status;
    Q_EMIT statusChanged();
}

PositionData OnboardStatusManager::currentPosition() const
{
    return m_currentPos;
}

Journey OnboardStatusManager::currentJourney() const
{
    return m_journey;
}

void OnboardStatusManager::registerFrontend(const OnboardStatus *status)
{
    qCDebug(Log) << "registering onboard frontend";
    connect(status, &OnboardStatus::updateIntervalChanged, this, &OnboardStatusManager::requestUpdate);
    m_frontends.push_back(status);
    requestForceUpdate();
}

void OnboardStatusManager::unregisterFrontend(const OnboardStatus *status)
{
    qCDebug(Log) << "unregistering onboard frontend";
    disconnect(status, &OnboardStatus::updateIntervalChanged, this, &OnboardStatusManager::requestUpdate);
    const auto it = std::find(m_frontends.begin(), m_frontends.end(), status);
    if (it != m_frontends.end()) {
        m_frontends.erase(it);
    }
    requestUpdate();
}

void OnboardStatusManager::wifiChanged()
{
    qCDebug(Log) << m_wifiMonitor.ssid();
    if (m_wifiMonitor.ssid().isEmpty() || m_wifiMonitor.status() != WifiMonitor::Available) {
        setStatus(OnboardStatus::NotConnected);
        return;
    }

    loadAccessPointData();
    const auto it = std::lower_bound(m_accessPointData.begin(), m_accessPointData.end(), m_wifiMonitor.ssid());
    if (it == m_accessPointData.end() || (*it).ssid != m_wifiMonitor.ssid()) {
        setStatus(OnboardStatus::NotConnected);
        return;
    }

    loadBackend((*it).backendId);
    if (m_backend) {
        setStatus(OnboardStatus::Onboard);
    } else {
        setStatus(OnboardStatus::NotConnected);
    }

    requestForceUpdate();
}

void OnboardStatusManager::loadAccessPointData()
{
    if (!m_accessPointData.empty()) {
        return;
    }

    QFile f(QStringLiteral(":/org.kde.kpublictransport.onboard/accesspoints.json"));
    if (!f.open(QFile::ReadOnly)) {
        qCWarning(Log) << "Failed to load access point database:" << f.errorString() << f.fileName();
        return;
    }

    const auto aps = QJsonDocument::fromJson(f.readAll()).array();
    m_accessPointData.reserve(aps.size());
    for (const auto &apVal : aps) {
        const auto ap = apVal.toObject();
        AccessPointInfo info;
        info.ssid = ap.value(QLatin1String("ssid")).toString();
        info.backendId = ap.value(QLatin1String("id")).toString();
        m_accessPointData.push_back(std::move(info));
    }

    std::sort(m_accessPointData.begin(), m_accessPointData.end());
}

void OnboardStatusManager::loadBackend(const QString &id)
{
    m_backend = createBackend(id);
    if (!m_backend) {
        return;
    }

    connect(m_backend.get(), &AbstractOnboardBackend::positionReceived, this, &OnboardStatusManager::positionUpdated);
    connect(m_backend.get(), &AbstractOnboardBackend::journeyReceived, this, &OnboardStatusManager::journeyUpdated);
}

std::unique_ptr<AbstractOnboardBackend> OnboardStatusManager::createBackend(const QString& id)
{
    std::unique_ptr<AbstractOnboardBackend> backend;

    QFile f(QLatin1String(":/org.kde.kpublictransport.onboard/") + id + QLatin1String(".json"));
    if (!f.open(QFile::ReadOnly)) {
        qCWarning(Log) << "Failed to open onboard API configuration:" << f.errorString() << f.fileName();
        return backend;
    }

    const auto config = QJsonDocument::fromJson(f.readAll()).object();
    const auto backendTypeName = config.value(QLatin1String("backend")).toString();
    if (backendTypeName == QLatin1String("ScriptedRestOnboardBackend")) { // TODO use names from QMetaObject
        backend.reset(new ScriptedRestOnboardBackend);
    }

    if (!backend) {
        qCWarning(Log) << "Failed to create onboard API backend:" << backendTypeName;
        return backend;
    }

    const auto mo = backend->metaObject();
    const auto options = config.value(QLatin1String("options")).toObject();
    for (auto it = options.begin(); it != options.end(); ++it) {
        const auto idx = mo->indexOfProperty(it.key().toUtf8().constData());
        if (idx < 0) {
            qCWarning(Log) << "Unknown backend setting:" << it.key();
            continue;
        }
        const auto mp = mo->property(idx);
        mp.write(backend.get(), it.value().toVariant());
    }

    return backend;
}

void OnboardStatusManager::positionUpdated(const PositionData &pos)
{
    m_pendingPositionUpdate = false;
    m_previousPos = m_currentPos;
    m_currentPos = pos;
    // TODO compute speed/heading if not set
    Q_EMIT positionChanged();
    requestUpdate();
}

void OnboardStatusManager::journeyUpdated(const Journey &jny)
{
    m_pendingJourneyUpdate = false;
    m_journey = jny;
    Q_EMIT journeyChanged();
    requestUpdate();
}

QNetworkAccessManager* OnboardStatusManager::nam()
{
    if (!m_nam) {
        m_nam = new QNetworkAccessManager(this);
        m_nam->setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);
    }
    return m_nam;
}

void OnboardStatusManager::requestUpdate()
{
    scheduleUpdate(false);
}

void OnboardStatusManager::requestForceUpdate()
{
    scheduleUpdate(true);
}

void OnboardStatusManager::scheduleUpdate(bool force)
{
    if (!m_backend || m_frontends.empty()) {
        m_positionUpdateTimer.stop();
        m_journeyUpdateTimer.stop();
        return;
    }

    if (!m_pendingPositionUpdate) {
        int interval = std::numeric_limits<int>::max();
        for (auto f : m_frontends) {
            if (f->positionUpdateInterval() > 0) {
                interval = std::min(interval, f->positionUpdateInterval());
            }
        }
        if (m_positionUpdateTimer.isActive()) {
            interval = std::min(m_positionUpdateTimer.remainingTime() / 1000, interval);
        }
        if (interval < std::numeric_limits<int>::max()) {
            qCDebug(Log) << "next position update:" << interval << force;
            m_positionUpdateTimer.start(std::chrono::seconds(force ? 0 : interval));
        }
    }

    if (!m_pendingJourneyUpdate) {
        int interval = std::numeric_limits<int>::max();
        for (auto f : m_frontends) {
            if (f->journeyUpdateInterval() > 0) {
                interval = std::min(interval, f->journeyUpdateInterval());
            }
        }
        if (m_journeyUpdateTimer.isActive()) {
            interval = std::min(m_journeyUpdateTimer.remainingTime() / 1000, interval);
        }
        if (interval < std::numeric_limits<int>::max()) {
            qCDebug(Log) << "next journey update:" << interval << force;
            m_journeyUpdateTimer.start(std::chrono::seconds(force ? 0 : interval));
        }
    }
}

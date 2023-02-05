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
    connect(&m_positionUpdateTimer, &QTimer::timeout, this, &OnboardStatusManager::requestPosition);
    m_journeyUpdateTimer.setSingleShot(true);
    m_journeyUpdateTimer.setTimerType(Qt::VeryCoarseTimer);
    connect(&m_journeyUpdateTimer, &QTimer::timeout, this, &OnboardStatusManager::requestJourney);
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
    if (m_status != OnboardStatus::Onboard) {
        m_previousPos = {};
        m_currentPos = {};
        m_journey = {};
    }

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
    connect(status, &OnboardStatus::updateIntervalChanged, this, &OnboardStatusManager::requestForceUpdate);
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

void OnboardStatusManager::requestPosition()
{
    if (m_backend && !m_pendingPositionUpdate) {
        m_pendingPositionUpdate = true;
        m_backend->requestPosition(nam());
    }
}

void OnboardStatusManager::requestJourney()
{
    if (m_backend && !m_pendingJourneyUpdate) {
        m_pendingJourneyUpdate = true;
        m_backend->requestJourney(nam());
    }
}

void OnboardStatusManager::wifiChanged()
{
    qCDebug(Log) << m_wifiMonitor.ssid() << m_wifiMonitor.status();
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

    QJsonParseError error;
    const auto aps = QJsonDocument::fromJson(f.readAll(), &error).array();
    if (error.error != QJsonParseError::NoError) {
        qCWarning(Log) << "Failed to parse access point data:" << error.errorString();
        return;
    }

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

constexpr inline double degToRad(double deg)
{
    return deg / 180.0 * M_PI;
}

constexpr inline double radToDeg(double rad)
{
    return rad / M_PI * 180.0;
}

void OnboardStatusManager::positionUpdated(const PositionData &pos)
{
    m_pendingPositionUpdate = false;
    m_previousPos = m_currentPos;
    m_currentPos = pos;
    if (!m_currentPos.timestamp.isValid()) {
        m_currentPos.timestamp = QDateTime::currentDateTime();
    }

    // compute heading based on previous position, if we actually moved sufficiently
    if (std::isnan(m_currentPos.heading) &&
        m_previousPos.hasCoordinate() &&
        m_currentPos.hasCoordinate() &&
        Location::distance(m_currentPos.latitude, m_currentPos.longitude, m_previousPos.latitude, m_previousPos.longitude) > 10.0)
    {
        const auto deltaLon = degToRad(m_currentPos.longitude) - degToRad(m_previousPos.longitude);
        const auto y = std::cos(degToRad(m_currentPos.latitude)) * std::sin(deltaLon);
        const auto x = std::cos(degToRad(m_previousPos.latitude)) * std::sin(degToRad(m_previousPos.latitude)) - std::sin(degToRad(m_previousPos.latitude)) * std::cos(degToRad(m_currentPos.latitude)) * std::cos(deltaLon);
        m_currentPos.heading = std::fmod(radToDeg(std::atan2(y, x)) + 360.0, 360.0);
    }

    // compute speed based on previous position if necessary
    if (std::isnan(m_currentPos.speed) && m_previousPos.hasCoordinate() && m_currentPos.hasCoordinate())
    {
        const auto dist = Location::distance(m_currentPos.latitude, m_currentPos.longitude, m_previousPos.latitude, m_previousPos.longitude);
        const double timeDelta = m_previousPos.timestamp.secsTo(m_currentPos.timestamp);
        if (timeDelta > 0) {
            m_currentPos.speed = 3.6 * dist / timeDelta;
        }
    }

    Q_EMIT positionChanged();
    requestUpdate();
}

void OnboardStatusManager::journeyUpdated(const Journey &jny)
{
    m_pendingJourneyUpdate = false;
    m_journey = jny;

    // check if the journey is at least remotely plausible
    // sometimes the onboard systems are stuck on a previous journey...
    if (jny.expectedArrivalTime().addSecs(60 * 60) < QDateTime::currentDateTime()) {
        m_journey = {};
    }

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

/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "scriptedrestonboardbackend_p.h"
#include "logging.h"
#include "positiondata_p.h"

#include "../lib/datatypes/journeyutil_p.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>

#include <QFile>
#include <QJSEngine>
#include <QJsonValue>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QScopeGuard>
#include <QTimer>
#include <QTimeZone>

using namespace KPublicTransport;

ScriptedRestOnboardBackend::ScriptedRestOnboardBackend(QObject *parent)
    : RestOnboardBackend(parent)
{
}

ScriptedRestOnboardBackend::~ScriptedRestOnboardBackend()
{
    if (m_watchdogTimer) {
        m_watchdogTimer->deleteLater();
    }
    m_watchdogThread.quit();
    m_watchdogThread.wait();
}

bool ScriptedRestOnboardBackend::supportsPosition() const
{
    return m_positionEndpoint.isValid();
}

bool ScriptedRestOnboardBackend::supportsJourney() const
{
    return m_journeyEndpoint.isValid();
}

QNetworkRequest ScriptedRestOnboardBackend::createPositionRequest() const
{
    return QNetworkRequest(m_positionEndpoint);
}

QNetworkRequest ScriptedRestOnboardBackend::createJourneyRequest() const
{
    return QNetworkRequest(m_journeyEndpoint);
}

static double strictToNumber(const QJSValue &val)
{
    if (val.isNumber()) {
        return val.toNumber();
    }
    if (val.isString()) {
        bool result = false;
        const auto n = val.toString().toDouble(&result);
        return result ? n : NAN;
    }
    return NAN;
}

PositionData ScriptedRestOnboardBackend::parsePositionData(const QJsonValue &response) const
{
    setupEngine();

    // watchdog setup
    QMetaObject::invokeMethod(m_watchdogTimer, qOverload<>(&QTimer::start));
    const auto watchdogStop = qScopeGuard([this]() {
        QMetaObject::invokeMethod(m_watchdogTimer, qOverload<>(&QTimer::stop));
    });
    m_engine->setInterrupted(false);

    auto func = m_engine->globalObject().property(m_positionFunction);
    if (!func.isCallable()) {
        qCWarning(Log) << "Script entry point not found!" << m_positionFunction;
        return {};
    }

    const auto arg = m_engine->toScriptValue(response);
    const auto result = func.call(QJSValueList{arg});
    if (result.isError()) {
        printScriptError(result);
        return {};
    }

    // convert JS result
    PositionData pos;
    pos.timestamp = QDateTime::fromString(result.property(QStringLiteral("timestamp")).toString(), Qt::ISODate);
    pos.latitude = strictToNumber(result.property(QStringLiteral("latitude")));
    pos.longitude = strictToNumber(result.property(QStringLiteral("longitude")));
    pos.speed = strictToNumber(result.property(QStringLiteral("speed")));
    pos.heading = strictToNumber(result.property(QStringLiteral("heading")));
    pos.altitude = strictToNumber(result.property(QStringLiteral("altitude")));
    return pos;
}

Journey ScriptedRestOnboardBackend::parseJourneyData(const QJsonValue &response) const
{
    setupEngine();

    // watchdog setup
    QMetaObject::invokeMethod(m_watchdogTimer, qOverload<>(&QTimer::start));
    const auto watchdogStop = qScopeGuard([this]() {
        QMetaObject::invokeMethod(m_watchdogTimer, qOverload<>(&QTimer::stop));
    });
    m_engine->setInterrupted(false);

    auto func = m_engine->globalObject().property(m_journeyFunction);
    if (!func.isCallable()) {
        qCWarning(Log) << "Script entry point not found!" << m_journeyFunction;
        return {};
    }

    const auto arg = m_engine->toScriptValue(response);
    const auto result = func.call(QJSValueList{arg});
    if (result.isError()) {
        printScriptError(result);
        return {};
    }

    // convert JS result
    auto jny = Journey::fromJson(QJsonValue::fromVariant(result.toVariant()).toObject());
    auto sections = jny.takeSections();

    for (auto &section : sections) {
        auto stops = section.takeIntermediateStops();
        // many backends will have the entire trip as intermediate stops, redistribute
        // that for our format
        if (section.from().isEmpty() && !stops.empty()) {
            const auto s = stops.front();
            section.setDeparture(s);
            stops.erase(stops.begin());
        }

        if (section.to().isEmpty() && !stops.empty()) {
            const auto s = stops.back();
            section.setArrival(s);
            stops.pop_back();
        }

        section.setIntermediateStops(std::move(stops));
    }

    jny.setSections(std::move(sections));
    JourneyUtil::propagateTimeZones(jny);
    return jny;
}

void ScriptedRestOnboardBackend::setupEngine() const
{
    if (m_engine) {
        return;
    }
    m_engine.reset(new QJSEngine);
    m_engine->installExtensions(QJSEngine::ConsoleExtension);

    m_watchdogThread.start();
    m_watchdogTimer = new QTimer;
    m_watchdogTimer->setInterval(std::chrono::milliseconds(500));
    m_watchdogTimer->setSingleShot(true);
    m_watchdogTimer->moveToThread(&m_watchdogThread);
    QObject::connect(m_watchdogTimer, &QTimer::timeout, this, [this]() { m_engine->setInterrupted(true); }, Qt::DirectConnection);

    // load script
    QFile f(QLatin1String(":/org.kde.kpublictransport.onboard/") + m_scriptName);
    if (!f.open(QFile::ReadOnly)) {
        qCWarning(Log) << "Failed to open extractor script" << f.fileName() << f.errorString();
        return;
    }

    const auto result = m_engine->evaluate(QString::fromUtf8(f.readAll()), f.fileName());
    if (result.isError()) {
        printScriptError(result);
        return;
    }
}

void ScriptedRestOnboardBackend::printScriptError(const QJSValue &error) const
{
    qCWarning(Log) << "JS ERROR: " << m_scriptName << error.property(QLatin1String("lineNumber")).toInt() << ": " << error.toString();
}

/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "scriptedrestonboardbackend_p.h"
#include "logging.h"
#include "positiondata_p.h"

#include "../lib/datatypes/stopoverutil_p.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>

#include <KTimeZone>

#include <QFile>
#include <QJSEngine>
#include <QJsonValue>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QTimeZone>

using namespace KPublicTransport;

ScriptedRestOnboardBackend::ScriptedRestOnboardBackend(QObject *parent)
    : RestOnboardBackend(parent)
{
}

ScriptedRestOnboardBackend::~ScriptedRestOnboardBackend() = default;

QNetworkRequest ScriptedRestOnboardBackend::createPositionRequest() const
{
    return QNetworkRequest(m_positionEndpoint);
}

QNetworkRequest ScriptedRestOnboardBackend::createJourneyRequest() const
{
    return QNetworkRequest(m_journeyEndpoint);
}

PositionData ScriptedRestOnboardBackend::parsePositionData(const QJsonValue &response) const
{
    setupEngine();
    // TODO start watchdog timer

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
    pos.latitude = result.property(QStringLiteral("latitude")).toNumber();
    pos.longitude = result.property(QStringLiteral("longitude")).toNumber();
    pos.speed = result.property(QStringLiteral("speed")).toNumber();
    pos.heading = result.property(QStringLiteral("heading")).toNumber();
    return pos;
}

Journey ScriptedRestOnboardBackend::parseJourneyData(const QJsonValue &response) const
{
    setupEngine();
    // TODO start watchdog timer

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
        // fill in missing titmezones
        for (auto &stop : stops) {
            QTimeZone tz(stop.stopPoint().timeZone());

            if (!tz.isValid() && stop.stopPoint().hasCoordinate()) {
                if (const auto tzId = KTimeZone::fromLocation(stop.stopPoint().latitude(), stop.stopPoint().longitude())) {
                    tz = QTimeZone(tzId);
                }
            }

            if (tz.isValid()) {
                StopoverUtil::applyTimeZone(stop, tz);
            }
        }

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
    return jny;
}

void ScriptedRestOnboardBackend::setupEngine() const
{
    if (m_engine) {
        return;
    }
    m_engine.reset(new QJSEngine);
    m_engine->installExtensions(QJSEngine::ConsoleExtension);

    // TODO watchdog timer

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

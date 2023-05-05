/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_SCRIPTEDRESTONBOARDBACKEND_H
#define KPUBLICTRANSPORT_SCRIPTEDRESTONBOARDBACKEND_H

#include "restonboardbackend_p.h"

#include <QThread>
#include <QUrl>

#include <memory>

class QJSEngine;
class QJSValue;
class QTimer;

namespace KPublicTransport {

/** REST onboard API backend with response parsing done in JS. */
class ScriptedRestOnboardBackend : public RestOnboardBackend
{
    Q_OBJECT
    Q_PROPERTY(QUrl positionEndpoint MEMBER m_positionEndpoint)
    Q_PROPERTY(QUrl journeyEndpoint MEMBER m_journeyEndpoint)
    Q_PROPERTY(QString script MEMBER m_scriptName)
    Q_PROPERTY(QString positionFunction MEMBER m_positionFunction)
    Q_PROPERTY(QString journeyFunction MEMBER m_journeyFunction)

public:
    explicit ScriptedRestOnboardBackend(QObject *parent = nullptr);
    ~ScriptedRestOnboardBackend();

    bool supportsPosition() const override final;
    bool supportsJourney() const override final;

    QNetworkRequest createPositionRequest() const override final;
    QNetworkRequest createJourneyRequest() const override final;

    Journey parseJourneyData(const QJsonValue &response) const override final;
    PositionData parsePositionData(const QJsonValue &response) const override final;

private:
    void setupEngine() const;
    void printScriptError(const QJSValue &error) const;

    QUrl m_positionEndpoint;
    QUrl m_journeyEndpoint;

    QString m_scriptName;
    QString m_positionFunction;
    QString m_journeyFunction;

    mutable std::unique_ptr<QJSEngine> m_engine;

    mutable QThread m_watchdogThread;
    mutable QTimer *m_watchdogTimer = nullptr;
};

}

#endif // KPUBLICTRANSPORT_SCRIPTEDRESTONBOARDBACKEND_H

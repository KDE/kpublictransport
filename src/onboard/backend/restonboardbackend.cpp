/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "restonboardbackend_p.h"
#include "logging.h"
#include "positiondata_p.h"

#include "../../lib/json/jsonp_p.h"

#include <KPublicTransport/Journey>

#include <QFile>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

using namespace KPublicTransport;

RestOnboardBackend::RestOnboardBackend(QObject *parent)
    : AbstractOnboardBackend(parent)
{
}

RestOnboardBackend::~RestOnboardBackend() = default;

static QString fakeResponseFile(QLatin1String key)
{
    QFile configFile(qEnvironmentVariable("KPUBLICTRANSPORT_ONBOARD_FAKE_CONFIG"));
    if (!configFile.open(QFile::ReadOnly)) {
        qCWarning(Log) << configFile.errorString() << configFile.fileName();
        return {};
    }

    const auto path = QJsonDocument::fromJson(configFile.readAll()).object().value(key).toString();
    if (QFileInfo(path).isAbsolute()) {
        return path;
    }

    return QFileInfo(configFile.fileName()).absolutePath() + QLatin1Char('/') + path;
}

static QJsonObject fakeResponse(QLatin1String key)
{
    QFile f(fakeResponseFile(key));
    if (!f.open(QFile::ReadOnly)) {
        qCWarning(Log) << f.errorString() << f.fileName();
        return {};
    }

    const auto doc = QJsonDocument::fromJson(JsonP::decode(f.readAll()));
    return doc.object();
}

void RestOnboardBackend::requestPosition(QNetworkAccessManager *nam)
{
    if (Q_UNLIKELY(qEnvironmentVariableIsSet("KPUBLICTRANSPORT_ONBOARD_FAKE_CONFIG"))) {
        Q_EMIT positionReceived(parsePositionData(fakeResponse(QLatin1String("positionResponse"))));
        return;
    }

    auto reply = nam->get(createPositionRequest());
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(Log) << reply->url() << reply->errorString();
            Q_EMIT positionReceived({});
            return;
        }

        const auto doc = QJsonDocument::fromJson(JsonP::decode(reply->readAll()));
        Q_EMIT positionReceived(parsePositionData(doc.object()));
    });
}

void RestOnboardBackend::requestJourney(QNetworkAccessManager *nam)
{
    if (Q_UNLIKELY(qEnvironmentVariableIsSet("KPUBLICTRANSPORT_ONBOARD_FAKE_CONFIG"))) {
        Q_EMIT journeyReceived(parseJourneyData(fakeResponse(QLatin1String("journeyResponse"))));
        return;
    }

    auto reply = nam->get(createJourneyRequest());
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(Log) << reply->url() << reply->errorString();
            Q_EMIT journeyReceived({});
            return;
        }

        const auto doc = QJsonDocument::fromJson(reply->readAll());
        Q_EMIT journeyReceived(parseJourneyData(doc.object()));
    });
}

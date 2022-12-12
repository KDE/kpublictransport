/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "restonboardbackend_p.h"
#include "logging.h"
#include "positiondata_p.h"

#include <KPublicTransport/Journey>

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

void RestOnboardBackend::requestPosition(QNetworkAccessManager *nam)
{
    auto reply = nam->get(createPositionRequest());
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCWarning(Log) << reply->url() << reply->errorString();
            Q_EMIT positionReceived({});
            return;
        }

        const auto doc = QJsonDocument::fromJson(reply->readAll());
        Q_EMIT positionReceived(parsePositionData(doc.object()));
    });
}

void RestOnboardBackend::requestJourney(QNetworkAccessManager *nam)
{
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

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "accessibilitycloudbackend.h"
#include "accessibilitycloudparser.h"
#include "cache.h"

#include <KPublicTransport/Location>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/LocationReply>

#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

AccessibilityCloudBackend::AccessibilityCloudBackend() = default;
AccessibilityCloudBackend::~AccessibilityCloudBackend() = default;

AbstractBackend::Capabilities AccessibilityCloudBackend::capabilities() const
{
    return AbstractBackend::Secure; // hardcoded below
}

bool AccessibilityCloudBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((req.types() & Location::Equipment) == 0 || !req.hasCoordinate()) {
        return false;
    }

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(QStringLiteral("accessibility-cloud.freetls.fastly.net"));
    url.setPath(QStringLiteral("/equipment-infos"));
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("latitude"), QString::number(req.latitude()));
    query.addQueryItem(QStringLiteral("longitude"), QString::number(req.longitude()));
    query.addQueryItem(QStringLiteral("accuracy"), QString::number(req.maximumDistance()));
    query.addQueryItem(QStringLiteral("appToken"), m_token);
    url.setQuery(query);

    QNetworkRequest netReq(url);
    netReq.setRawHeader("Accept", "application/json");
    logRequest(req, netReq);

    auto netReply = nam->get(netReq);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, netReply, reply] {
        netReply->deleteLater();
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);
        if (netReply->error()) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        AccessibilityCloudParser parser;
        if (parser.parseLocations(data)) {
            if (parser.locations.empty()) {
                addError(reply, Reply::NotFoundError, {});
            } else {
                Cache::addLocationCacheEntry(backendId(), reply->request().cacheKey(), parser.locations, parser.attributions, std::chrono::minutes(5));
                addAttributions(reply, std::move(parser.attributions));
                addResult(reply, std::move(parser.locations));
            }
        } else {
            addError(reply, Reply::UnknownError, {});
        }
    });

    return true;
}

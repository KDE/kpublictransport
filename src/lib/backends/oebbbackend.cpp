/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "oebbbackend.h"
#include "oebbvehiclelayoutparser.h"
#include "cache.h"

#include <KPublicTransport/Stopover>
#include <KPublicTransport/VehicleLayoutReply>
#include <KPublicTransport/VehicleLayoutRequest>

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

using namespace KPublicTransport;

bool OebbBackend::queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const
{
    const auto ibnr = request.stopover().stopPoint().identifier(QLatin1String("ibnr"));
    if (ibnr.size() != 7) {
        return false;
    }

    const auto dt = request.stopover().scheduledDepartureTime().isValid() ? request.stopover().scheduledDepartureTime() : request.stopover().scheduledArrivalTime();
    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(QStringLiteral("live.oebb.at"));
    url.setPath(QLatin1String("/backend/api/train/") + request.stopover().route().line().name()
        + QLatin1String("/stationEva/") + ibnr
        + QLatin1String("/departure/") +  dt.toString(QStringLiteral("dd.MM.yyyy")));

    QNetworkRequest netReq(url);
    logRequest(request, netReq);
    auto netReply = nam->get(netReq);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() == QNetworkReply::NoError) {
            OebbVehicleLayoutParser p;
            if (p.parse(data)) {
                Cache::addVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey(), p.stopover, {}, std::chrono::minutes(2));
                addResult(reply, p.stopover);
            } else {
                Cache::addNegativeVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey());
                addError(reply, Reply::NotFoundError, {});
            }
        } else {
            addError(reply, Reply::NetworkError, reply->errorString());
        }
        netReply->deleteLater();
    });

    return true;
}

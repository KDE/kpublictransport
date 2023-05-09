/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "oebbbackend.h"
#include "oebbvehiclelayoutparser.h"
#include "cache.h"
#include "uic/uicstationcode.h"

#include <KPublicTransport/Stopover>
#include <KPublicTransport/VehicleLayoutReply>
#include <KPublicTransport/VehicleLayoutRequest>

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QRegularExpression>
#include <QUrl>
#include <QUrlQuery>

using namespace KPublicTransport;

static QString trainNumber(Line line)
{
    static QRegularExpression regex(QStringLiteral("(?:ICE|IC|EC|RJ|RJX|NJ)\\s*(\\d+)"));
    const auto match = regex.match(line.modeString() + line.name());
    if (match.hasMatch()) {
        return match.captured(1);
    }
    return {};
}

bool OebbBackend::queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const
{
    const auto ibnr = request.stopover().stopPoint().identifier(QStringLiteral("ibnr"));
    if (!UicStationCode::isValid(ibnr) || UicStationCode::country(ibnr) != QLatin1String("81")) {
        return false;
    }
    const auto trainNum = trainNumber(request.stopover().route().line());
    if (trainNum.isEmpty()) {
        return false;
    }
    const auto dt = request.stopover().scheduledDepartureTime().isValid() ? request.stopover().scheduledDepartureTime() : request.stopover().scheduledArrivalTime();

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(QStringLiteral("live.oebb.at"));
    url.setPath(QLatin1String("/backend/info"));
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("trainNr"), trainNum);
    query.addQueryItem(QStringLiteral("station"), ibnr);
    query.addQueryItem(QStringLiteral("date"), dt.toString(QStringLiteral("yyyy-MM-dd")));
    url.setQuery(query);

    QNetworkRequest netReq(url);
    logRequest(request, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() == QNetworkReply::NoError) {
            OebbVehicleLayoutParser p;
            if (p.parse(data)) {
                Cache::addVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey(), p.stopover, {}, std::chrono::minutes(2));
                addResult(reply, p.stopover);
            } else {
                addError(reply, Reply::UnknownError, {});
            }
        } else if (netReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 404) {
            Cache::addNegativeVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey());
            addError(reply, Reply::NotFoundError, reply->errorString());
        } else {
            addError(reply, Reply::NetworkError, reply->errorString());
        }
        netReply->deleteLater();
    });

    return true;
}

/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "deutschebahnbackend.h"
#include "deutschebahnvehiclelayoutparser.h"
#include "cache.h"
#include "datatypes/vehiclelayoutresult_p.h"

#include <KPublicTransport/Stopover>
#include <KPublicTransport/VehicleLayoutReply>
#include <KPublicTransport/VehicleLayoutRequest>

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QRegularExpression>
#include <QUrl>

using namespace KPublicTransport;

static QString extractTrainNumber(const Line &line)
{
    qDebug() << line.modeString() << line.name();
    QRegularExpression regex(QStringLiteral("(?:ICE|IC|EC)\\s*(\\d+)"));
    const auto match = regex.match(line.modeString() + line.name());
    if (match.hasMatch()) {
        return match.captured(1);
    }
    return {};
}

bool DeutscheBahnBackend::queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const
{
    // unlike the rest of the DB API, this only works in Germany, so do our own geo filtering here.
    const auto germanyBBox = QPolygonF({ {5.56384, 55.0492}, {6.131, 47.2565}, {15.4307, 47.4737}, {14.6794, 54.7568} });
    if (!germanyBBox.containsPoint({request.departure().stopPoint().longitude(), request.departure().stopPoint().latitude()}, Qt::WindingFill)) {
        qDebug() << "request outside of bounding box";
        return false;
    }

    // we need two parameters for the online API: the train number (numeric only), and the departure time
    // note: data is only available withing the upcoming 24h
    // checking this early is useful as the error response from the online service is extremely verbose...
    auto dt = request.departure().scheduledDepartureTime();
    const auto trainNum = extractTrainNumber(request.departure().route().line());
    if (!dt.isValid() || trainNum.isEmpty()) {
        return false;
    }

    // there are only valid results for a 24h time window, so try to adjust the date accordingly
    const auto now = QDateTime::currentDateTime();
    if (dt.daysTo(now) > 1 || dt.daysTo(now) < -1) {
        qDebug() << "adjusting departure time to today:" << dt;
        dt.setDate(QDate::currentDate());
    }

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(QStringLiteral("www.apps-bahn.de"));
    url.setPath(QLatin1String("/wr/wagenreihung/1.0/") + trainNum + QLatin1Char('/') + dt.toString(QStringLiteral("yyyyMMddhhmm")));

    QNetworkRequest netReq(url);
    logRequest(request, netReq);
    auto netReply = nam->get(netReq);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() == QNetworkReply::NoError) {
            DeutscheBahnVehicleLayoutParser p;
            if (p.parse(data)) {
                Cache::addVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey(), {p.vehicle, p.platform, p.departure}, {}, std::chrono::minutes(2));
                addResult(reply, p.vehicle, p.platform, p.departure);
            } else {
                addError(reply, p.error, p.errorMessage);
                if (p.error == Reply::NotFoundError) {
                    Cache::addNegativeVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey(), std::chrono::hours(24));
                }
            }
        } else {
            addError(reply, Reply::NetworkError, reply->errorString());
        }
        netReply->deleteLater();
    });

    return true;
}

/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "deutschebahnbackend.h"
#include "deutschebahnvehiclelayoutparser.h"
#include "deutschebahnproducts.h"
#include "cache.h"

#include <KPublicTransport/Stopover>
#include <KPublicTransport/VehicleLayoutReply>
#include <KPublicTransport/VehicleLayoutRequest>

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QRegularExpression>
#include <QUrl>

using namespace Qt::Literals;
using namespace KPublicTransport;

struct TrainNum {
    QString category;
    QString number;
};

static TrainNum extractTrainNumber(const Route &route)
{
    TrainNum trainNum;
    QRegularExpression rx(u"([A-Z]+)?\\s*(\\d+)"_s);

    if (!route.name().isEmpty()) {
        const auto match = rx.match(route.name());
        if (match.hasMatch()) {
            trainNum = { match.captured(1), match.captured(2) };
        }
    }

    const auto line = route.line();
    const auto match = rx.match(line.modeString() + line.name());
    if (match.hasMatch()) {
        if (trainNum.category.isEmpty()) {
            trainNum.category = match.captured(1);
        }
        if (trainNum.number.isEmpty()) {
            trainNum.number = match.captured(2);
        }
    }

    return trainNum;
}

bool DeutscheBahnBackend::queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const
{
    // unlike the rest of the DB API, this only works in Germany, so do our own geo filtering here.
    const auto germanyBBox = QPolygonF({ {5.56384, 55.0492}, {6.131, 47.2565}, {15.4307, 47.4737}, {14.6794, 54.7568} });
    if (!germanyBBox.containsPoint({request.stopover().stopPoint().longitude(), request.stopover().stopPoint().latitude()}, Qt::WindingFill)) {
        qDebug() << "request outside of bounding box";
        return false;
    }

    // we need two parameters for the online API: the train number (numeric only), and the departure time
    // note: data is only available withing the upcoming 24h
    // checking this early is useful as the error response from the online service is extremely verbose...
    auto dt = request.stopover().scheduledDepartureTime().isValid() ? request.stopover().scheduledDepartureTime() : request.stopover().scheduledArrivalTime();
    const auto [trainCategory, trainNum] = extractTrainNumber(request.stopover().route());
    if (!dt.isValid() || trainNum.isEmpty() || !DeutscheBahnProducts::isValid(trainCategory)) {
        return false;
    }
    dt = dt.toTimeZone(QTimeZone("Europe/Berlin"));

    // there are only valid results for a 24h time window, so try to adjust the date accordingly
    const auto now = QDateTime::currentDateTime();
    if (dt.daysTo(now) > 1 || dt.daysTo(now) < -1) {
        qDebug() << "adjusting departure time to today:" << dt;
        dt.setDate(QDate::currentDate());
    }

    QUrl url;
    url.setScheme(QStringLiteral("https"));
    url.setHost(QStringLiteral("ist-wr.noncd.db.de"));
    url.setPath(QLatin1String("/wagenreihung/1.0/") + trainNum + QLatin1Char('/') + dt.toString(QStringLiteral("yyyyMMddhhmm")));

    QNetworkRequest netReq(url);
    logRequest(request, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() == QNetworkReply::NoError) {
            DeutscheBahnVehicleLayoutParser p;
            if (p.parse(data)) {
                Cache::addVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey(), p.stopover, {}, std::chrono::minutes(2));
                addResult(reply, p.stopover);
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

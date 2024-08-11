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
#include <QUrlQuery>

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

    const auto ibnr = request.stopover().stopPoint().identifier("ibnr"_L1);
    const auto dt = request.stopover().scheduledDepartureTime().isValid() ? request.stopover().scheduledDepartureTime() : request.stopover().scheduledArrivalTime();
    const auto [trainCategory, trainNum] = extractTrainNumber(request.stopover().route());
    if (!dt.isValid() || trainNum.isEmpty() || !DeutscheBahnProducts::isValid(trainCategory) || ibnr.isEmpty()) {
        return false;
    }

    QUrl url;
    url.setScheme(u"https"_s);
    url.setHost(u"www.bahn.de"_s);
    url.setPath(u"/web/api/reisebegleitung/wagenreihung/vehicle-sequence"_s);
    QUrlQuery query;
    query.addQueryItem(u"category"_s, trainCategory);
    query.addQueryItem(u"number"_s, trainNum);
    query.addQueryItem(u"date"_s, dt.date().toString(u"yyyy-MM-dd"));
    query.addQueryItem(u"time"_s, dt.toUTC().toString(Qt::ISODate));
    query.addQueryItem(u"evaNumber"_s, ibnr);
    url.setQuery(query);
    qDebug() << url;

    QNetworkRequest netReq(url);
    logRequest(request, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);

        if (netReply->error() == QNetworkReply::NoError) {
            auto res = DeutscheBahnVehicleLayoutParser::parse(data);
            Cache::addVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey(), res, {}, std::chrono::minutes(2));
            addResult(reply, res);
        } else {
            addError(reply, Reply::NotFoundError, reply->errorString());
            Cache::addNegativeVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey(), std::chrono::hours(24));
        }
        netReply->deleteLater();
    });

    return true;
}

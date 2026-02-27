/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "opentransportswissbackend.h"
#include "opentransportswissformationparser.h"

#include "cache.h"
#include "logging.h"

#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/VehicleLayoutReply>
#include <KPublicTransport/VehicleLayoutRequest>

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>

using namespace Qt::Literals;
using namespace KPublicTransport;

bool OpenTransportSwissBackend::queryVehicleLayout(const VehicleLayoutRequest &request, VehicleLayoutReply *reply, QNetworkAccessManager *nam) const
{
    if (request.stopover().route().name().isEmpty()) {
        return false;
    }

    const auto uicStop = request.stopover().stopPoint().identifier("uic"_L1).toInt();
    if (uicStop < 85'00000 || uicStop > 85'99999) {
        return false;
    }

    const auto evu = m_formationOperatorMap.value(request.stopover().route().line().operatorIdentifier(backendId())).toString();
    if (evu.isEmpty()) {
        qCWarning(Log) << "No formation operator mapping for" << request.stopover().route().line().operatorIdentifier(backendId());
        return false;
    }

    auto dt = request.stopover().scheduledDepartureTime().isValid() ? request.stopover().scheduledDepartureTime() : request.stopover().scheduledArrivalTime();
    dt = dt.toTimeZone(QTimeZone("Europe/Zurich"));

    QUrlQuery query;
    query.addQueryItem(u"evu"_s, evu);
    query.addQueryItem(u"operationDate"_s, dt.toString(u"yyyy-MM-dd"));
    query.addQueryItem(u"trainNumber"_s, request.stopover().route().name());

    QUrl url;
    url.setScheme(u"https"_s);
    url.setHost(u"api.opentransportdata.swiss"_s);
    url.setPath(u"/formation/v2/formations_full"_s);
    url.setQuery(query);
    qDebug() << url;

    auto netReq = QNetworkRequest(url);
    if (!m_formationAuthorization.isEmpty()) {
        netReq.setRawHeader("Authorization", m_formationAuthorization.toUtf8());
    }
    logRequest(request, netReq);
    auto netReply = nam->get(netReq);
    netReply->setParent(reply);

    QObject::connect(netReply, &QNetworkReply::finished, reply, [this, reply, netReply] {
        const auto data = netReply->readAll();
        logReply(reply, netReply, data);
        qDebug() << netReply->errorString();
        qDebug().noquote() << data;

        if (netReply->error() == QNetworkReply::NoError) {
            OpenTransportSwissFormationParser p;
            if (p.parse(data, backendId())) {
                qDebug() << Stopover::toJson(p.stopover);
                Cache::addVehicleLayoutCacheEntry(backendId(), reply->request().cacheKey(), p.stopover, {}, std::chrono::minutes(2));
                addResult(reply, p.stopover);
            } else {
                addError(reply, Reply::UnknownError, {});
            }
        } else {
            addError(reply, Reply::NetworkError, reply->errorString());
        }
        netReply->deleteLater();
    });

    return true;
}

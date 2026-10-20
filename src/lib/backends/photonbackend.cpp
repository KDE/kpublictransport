/*
    SPDX-FileCopyrightText: 2026 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "photonbackend.h"

#include "backends/abstractbackend.h"
#include "geo/geojson_p.h"
#include "http/useragent_p.h"
#include "locationreply.h"
#include "locationrequest.h"
#include "photonparser.h"

#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>
#include <QUrlQuery>

#include <utility>

using namespace KPublicTransport;

using namespace Qt::StringLiterals;

const QStringView NOMINATIM_DETAILS_ENDPOINT = u"https://nominatim.openstreetmap.org/details";

AbstractBackend::Capabilities KPublicTransport::PhotonBackend::capabilities() const
{
    return m_url.scheme() == "https"_L1 ? Secure : NoCapability;
}

bool PhotonBackend::queryLocation(const LocationRequest &request,
                                  LocationReply *reply,
                                  QNetworkAccessManager *nam) const
{
    if (request.name().size() <= 3) {
        return false;
    }

    QUrl url = m_url;
    QUrlQuery query;
    query.addQueryItem(u"q"_s, request.name());
    if (request.location().hasCoordinate()) {
        query.addQueryItem(u"lat"_s, QString::number(request.location().latitude()));
        query.addQueryItem(u"lon"_s, QString::number(request.location().longitude()));
    }
    url.setQuery(query);

    QNetworkRequest req(url);
    req.setHeader(QNetworkRequest::KnownHeaders::UserAgentHeader, Http::userAgent().toUtf8());
    logRequest(request, req);
    qDebug() << url;

    auto *netReply = nam->get(req);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [=, this]() {
        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        const auto body = netReply->readAll();
        logReply(reply, netReply, body);
        qDebug() << body;
        auto locations = std::make_shared<std::vector<Location>>(PhotonParser::parseLocations(body));

        auto reqs = std::make_shared<int>(0);
        for (auto &loc : *locations) {
            if (loc.type() == Location::Area && loc.polygons().empty() && !loc.identifier(u"osm").isEmpty()) {
                QUrl url(NOMINATIM_DETAILS_ENDPOINT.toString());
                QUrlQuery query;
                query.addQueryItem(u"osmtype"_s, u"R"_s);
                query.addQueryItem(u"osmid"_s, loc.identifier(u"osm"));
                query.addQueryItem(u"format"_s, u"json"_s);
                query.addQueryItem(u"polygon_geojson"_s, u"1"_s);
                url.setQuery(query);

                QNetworkRequest req(url);
                qWarning() << url;
                req.setHeader(QNetworkRequest::KnownHeaders::UserAgentHeader, Http::userAgent().toUtf8());
                logRequest(request, req);

                (*reqs)++;

                auto *netReply = nam->get(req);

                QObject::connect(netReply, &QNetworkReply::finished, reply, [=, &loc]() mutable {
                    if (netReply->error() == QNetworkReply::NoError) {
                        auto const json = QJsonDocument::fromJson(netReply->readAll()).object();

                        loc.setData(QVariant::fromValue(GeoJson::readOuterPolygons(json.value("geometry"_L1).toObject())));

                        qWarning() << GeoJson::writePolygons(loc.polygons());
                    }

                    (*reqs)--;

                    if (*reqs == 0) {
                        addResult(reply, std::move(*locations));
                    }
                });
            }
        }

        if (*reqs == 0) {
            addResult(reply, std::move(*locations));
        }
    });

    // async
    return true;
}

Location::Types PhotonBackend::supportedLocationTypes() const
{
    return Location::Type::Address | Location::Type::Place | Location::Type::Stop | Location::Type::Area;
}

/*
    SPDX-FileCopyrightText: 2026 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "photonbackend.h"

#include "backends/abstractbackend.h"
#include "datatypes/line.h"
#include "datatypes/stopinformation.h"
#include "geo/geojson_p.h"
#include "http/useragent_p.h"
#include "locationreply.h"
#include "locationrequest.h"
#include "reply.h"

#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QString>
#include <QUrlQuery>

#include <utility>
#include <vector>

using namespace KPublicTransport;

using namespace Qt::StringLiterals;

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

    auto *netReply = nam->get(req);
    QObject::connect(netReply, &QNetworkReply::finished, reply, [=, this]() {
        if (netReply->error() != QNetworkReply::NoError) {
            addError(reply, Reply::NetworkError, netReply->errorString());
            return;
        }

        const auto body = netReply->readAll();
        const auto geojson = QJsonDocument::fromJson(body).object();
        const auto features = geojson.value("features"_L1).toArray();

        std::vector<Location> locations;
        for (const auto feature : features) {
            const auto featureObj = feature.toObject();
            const auto geo = featureObj.value("geometry"_L1).toObject();
            const auto properties = featureObj.value("properties"_L1).toObject();

            Location loc;

            if (properties.contains("name"_L1)) {
                loc.setName(properties.value("name"_L1).toString());
            }
            if (properties.contains("countrycode"_L1)) {
                loc.setCountry(properties.value("countrycode"_L1).toString());
            }
            if (properties.contains("postcode"_L1)) {
                loc.setPostalCode(properties.value("postcode"_L1).toString());
            }
            if (properties.contains("city"_L1)) {
                loc.setLocality(properties.value("city"_L1).toString());
            }

            StopInformation stop;
            Line line;

            if (properties.contains("osm_key"_L1) && properties.contains("osm_value"_L1)) {
                auto const key = properties.value("osm_key"_L1).toStringView();
                auto const value = properties.value("osm_value"_L1).toStringView();

                if (key == "railway") {
                    if (value == "station" || value == "halt" || value == "stop"
                        || value == "platform") {
                        loc.setType(Location::Stop);
                        line.setMode(Line::Mode::Train);
                    } else if (value == "tram_stop") {
                        loc.setType(Location::Stop);
                        line.setMode(Line::Mode::Tramway);
                    }
                }
                if (key == "building" && value == "train_station") {
                    loc.setType(Location::Stop);
                    line.setMode(Line::Mode::Train);
                } else if (key == "highway" && value == "bus_stop") {
                    loc.setType(Location::Stop);
                    line.setMode(Line::Mode::Bus);
                } else if (key == "aerialway" && value == "station") {
                    loc.setType(Location::Stop);
                    line.setMode(Line::Mode::AerialLift);
                } else if (key == "aeroway" && value == "aerodrome") {
                    loc.setType(Location::Stop);
                    line.setMode(Line::Mode::Air);
                } else if (key == "aeroway" && value == "terminal") {
                    loc.setType(Location::Stop);
                    line.setMode(Line::Mode::Air);
                } else if (loc.type() == Location::Place && properties.contains("housenumber"_L1)) {
                    loc.setType(Location::Address);
                }
            }

            if (loc.type() == Location::Stop) {
                stop.addLine(line);
                loc.setData(stop);
            }

            if (geo.value("type"_L1) == "Point"_L1) {
                const auto point = GeoJson::readPoint(geo);

                loc.setCoordinate(point.y(), point.x());
            }

            locations.push_back(std::move(loc));
        }

        addResult(reply, std::move(locations));
    });

    // async
    return true;
}

Location::Types PhotonBackend::supportedLocationTypes() const
{
    return Location::Type::Address | Location::Type::Place | Location::Type::Stop;
}

/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "motis2parser.h"
#include "geo/polylinedecoder_p.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/RentalVehicle>
#include <KPublicTransport/Stopover>

#include <QColor>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimeZone>
#include <QUrl>

#include <cmath>
#include <limits>

using namespace KPublicTransport;
using namespace Qt::Literals::StringLiterals;

Motis2Parser::Motis2Parser(QString locIdentifierType)
    : m_locIdentifierType(std::move(locIdentifierType))
{
}

/** Convert from MOTIS time stamp to QDateTime. */
[[nodiscard]] static QDateTime parseTime(const QJsonValue &timestamp)
{
    return QDateTime::fromString(timestamp.toString(), Qt::ISODate);
}

struct {
    const char *name;
    Line::Mode lineMode;
    JourneySection::Mode jnyMode;
    IndividualTransport::Mode ivMode;
    IndividualTransport::Qualifier ivQualifier;
    RentalVehicle::VehicleType rentalType;
} static constexpr const mode_map[] = {
    { "WALK", Line::Mode::Unknown, JourneySection::Walking, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "BIKE", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Bike, IndividualTransport::None, RentalVehicle::Unknown },
    { "CAR", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Car, IndividualTransport::None, RentalVehicle::Unknown },
    { "BIKE_RENTAL", Line::Mode::Unknown, JourneySection::RentedVehicle, IndividualTransport::Bike, IndividualTransport::Rent, RentalVehicle::Bicycle },
    { "BIKE_TO_PARK", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Bike, IndividualTransport::Park, RentalVehicle::Unknown },
    { "CAR_TO_PARK", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Car, IndividualTransport::Park, RentalVehicle::Unknown },
    { "CAR_HAILING", Line::Mode::Taxi, JourneySection::PublicTransport, IndividualTransport::Car, IndividualTransport::None, RentalVehicle::Unknown },
    { "CAR_SHARING", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Car, IndividualTransport::None, RentalVehicle::Car }, // TODO not properly modelled yet
    { "CAR_PICKUP", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Car, IndividualTransport::Pickup, RentalVehicle::Unknown },
    { "CAR_RENTAL", Line::Mode::Unknown, JourneySection::RentedVehicle, IndividualTransport::Car, IndividualTransport::Rent, RentalVehicle::Car },
    { "FLEXIBLE", Line::Mode::Taxi, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown }, // TODO not properly modelled yet
    { "SCOOTER_RENTAL", Line::Mode::Unknown, JourneySection::RentedVehicle, IndividualTransport::Bike, IndividualTransport::Rent, RentalVehicle::ElectricKickScooter },
    { "TRANSIT", Line::Mode::Unknown, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "TRAM", Line::Mode::Tramway, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "SUBWAY", Line::Mode::Metro, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "FERRY", Line::Mode::Ferry, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "AIRPLANE", Line::Mode::Air, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "BUS", Line::Mode::Bus, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "COACH", Line::Mode::Coach, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "RAIL", Line::Mode::Train, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "METRO", Line::Mode::RapidTransit, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "HIGHSPEED_RAIL", Line::Mode::LongDistanceTrain, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "LONG_DISTANCE", Line::Mode::LongDistanceTrain, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "NIGHT_RAIL", Line::Mode::LongDistanceTrain, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "REGIONAL_FAST_RAIL", Line::Mode::LocalTrain, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "REGIONAL_RAIL", Line::Mode::LocalTrain, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "OTHER", Line::Mode::Unknown, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
};

struct {
    const char *name;
    Location::Type type;
} static constexpr const vertex_map[] = {
    { "NORMAL", Location::Place },
    { "BIKESHARE", Location::RentedVehicleStation },
    { "BIKEPARK", Location::Place }, // TODO we don't have parking as a location type yet!
    { "TRANSIT", Location::Stop },
};

Stopover Motis2Parser::parsePlace(const QJsonObject &obj, bool hasRealTime) const
{
    Location l;
    l.setName(obj.value("name"_L1).toString());
    l.setIdentifier(m_locIdentifierType, obj.value("stopId"_L1).toString());
    l.setLatitude(obj.value("lat"_L1).toDouble(NAN));
    l.setLongitude(obj.value("lon"_L1).toDouble(NAN));
    l.setFloorLevel(obj.value("level"_L1).toInt(std::numeric_limits<int>::lowest()));
    const auto type = obj.value("vertexType"_L1).toString();
    for (const auto &m : vertex_map ) {
        if (QLatin1StringView(m.name) == type) {
            l.setType(m.type);
            break;
        }
    }

    Stopover s;
    s.setStopPoint(l);
    s.setScheduledPlatform(obj.value("scheduledTrack"_L1).toString());
    s.setScheduledDepartureTime(parseTime(obj.value("departure"_L1)));
    s.setScheduledArrivalTime(parseTime(obj.value("arrival"_L1)));
    if (hasRealTime) {
        s.setExpectedPlatform(obj.value("track"_L1).toString());
        s.setExpectedDepartureTime(s.scheduledDepartureTime().addMSecs(obj.value("departureDelay"_L1).toInteger()));
        s.setExpectedArrivalTime(s.scheduledArrivalTime().addMSecs(obj.value("arrivalDelay"_L1).toInteger()));
    }

    return s;
}

[[nodiscard]] static QPolygonF parsePolyLine(const QJsonObject &encodedPolyline)
{
    QPolygonF poly;
    poly.reserve(encodedPolyline.value("length"_L1).toInteger());
    const auto points = encodedPolyline.value("points"_L1).toString().toUtf8();
    PolylineDecoder<2, 7> decoder(points.constData());
    decoder.readPolygon(poly);
    return poly;
}

std::vector<Journey> Motis2Parser::parseItineraries(const QByteArray &data)
{
    const auto content = QJsonDocument::fromJson(data).object();
    const auto itineraries = content.value("itineraries"_L1).toArray();
    std::vector<Journey> result;
    result.reserve(itineraries.size());
    for (const auto &itineraryV :itineraries) {
        const auto itinerary = itineraryV.toObject();
        const auto legs = itinerary.value("legs"_L1).toArray();
        std::vector<JourneySection> sections;
        sections.reserve(legs.size());

        for (const auto &legV : legs) {
            const auto leg = legV.toObject();
            JourneySection s;

            const auto mode = leg.value("mode"_L1).toString();
            auto it = std::find_if(std::begin(mode_map), std::end(mode_map), [mode](const auto &m) {
                return QLatin1StringView(m.name) == mode;
            });
            if (it == std::end(mode_map)) {
                qWarning() << "Unknown mode:" << mode;
                continue;
            }
            s.setMode((*it).jnyMode);

            const auto hasRealTime = leg.value("realTime"_L1).toBool();
            const auto from = parsePlace(leg.value("from"_L1).toObject(), hasRealTime);
            s.setDeparture(from);
            const auto to = parsePlace(leg.value("to"_L1).toObject(), hasRealTime);
            s.setArrival(to);
            s.setDistance(leg.value("distance"_L1).toInt());

            s.setScheduledDepartureTime(parseTime(leg.value("startTime"_L1)));
            s.setScheduledArrivalTime(parseTime(leg.value("endTime"_L1)));
            if (hasRealTime) {
                s.setExpectedDepartureTime(s.scheduledDepartureTime().addMSecs(leg.value("departureDelay"_L1).toInteger()));
                s.setExpectedArrivalTime(s.scheduledArrivalTime().addMSecs(leg.value("arrivalDelay"_L1).toInteger()));
            }

            if (s.mode() == JourneySection::PublicTransport) {
                Line line;
                line.setMode((*it).lineMode);
                line.setName(leg.value("routeShortName"_L1).toString());
                line.setOperatorName(leg.value("agencyName"_L1).toString());
                line.setColor(QColor::fromString('#'_L1 + leg.value("routeColor"_L1).toString()));
                line.setTextColor(QColor::fromString('#'_L1 + leg.value("routeTextColor"_L1).toString()));

                Route route;
                route.setDirection(leg.value("headsign"_L1).toString());
                route.setLine(line);

                s.setRoute(route);

                const auto intermediateStops = leg.value("intermediateStops"_L1).toArray();
                std::vector<Stopover> stops;
                stops.reserve(intermediateStops.size());
                for (const auto &intermediateStopV : intermediateStops) {
                    const auto intermediateStop = intermediateStopV.toObject();
                    stops.push_back(parsePlace(intermediateStop, hasRealTime));
                }
                s.setIntermediateStops(std::move(stops));
            } else if (s.mode() == JourneySection::IndividualTransport) {
                IndividualTransport iv;
                iv.setMode((*it).ivMode);
                iv.setQualifier((*it).ivQualifier);
                s.setIndividualTransport(iv);
            } else if (s.mode() == JourneySection::RentedVehicle) {
                const auto rentalObj = leg.value("rental"_L1).toObject();
                // TODO booking deep links, url

                RentalVehicleNetwork rvNetwork;
                rvNetwork.setName(rentalObj.value("systemName"_L1).toString());

                RentalVehicle rv;
                rv.setType((*it).rentalType);
                rv.setNetwork(rvNetwork);
                s.setRentalVehicle(rv);
            }

            if (const auto legGeoArray = leg.value("steps"_L1).toArray(); !legGeoArray.empty()) {
                std::vector<PathSection> pathSections;
                pathSections.reserve(legGeoArray.size());
                for (const auto &legGeoV : legGeoArray) {
                    const auto legGeoObj = legGeoV.toObject();
                    PathSection pathSec;
                    pathSec.setStartFloorLevel(legGeoObj.value("fromLevel"_L1).toInt(std::numeric_limits<int>::lowest()));
                    if (pathSec.hasStartFloorLevel()) {
                        pathSec.setFloorLevelChange(legGeoObj.value("toLevel"_L1).toInt() - pathSec.startFloorLevel());
                    }
                    pathSec.setPath(parsePolyLine(legGeoObj.value("polyline"_L1).toObject()));
                    if (const auto streetName = legGeoObj.value("streetName"_L1).toString(); !streetName.isEmpty()) {
                        pathSec.setDescription(streetName);
                    }
                    if (!pathSec.path().isEmpty()) {
                        pathSections.push_back(std::move(pathSec));
                    }
                }
                if (!pathSections.empty()) {
                    Path path;
                    path.setSections(std::move(pathSections));
                    s.setPath(path);
                }
            }
            if (const auto geometryObj = leg.value("legGeometry"_L1).toObject(); !geometryObj.empty() && s.path().isEmpty()) {
                PathSection pathSec;
                pathSec.setPath(parsePolyLine(geometryObj));
                if (!pathSec.path().isEmpty()) {
                    Path path;
                    path.setSections({pathSec});
                    s.setPath(path);
                }
            }

            sections.push_back(std::move(s));
        }

        Journey jny;
        jny.setSections(std::move(sections));
        result.push_back(std::move(jny));
    }

    parseCursors(content);
    return result;
}

std::vector<Stopover> Motis2Parser::parseStopTimes(const QByteArray &data)
{
    std::vector<Stopover> result;

    const auto response = QJsonDocument::fromJson(data).object();
    const auto stopTimes = response.value("stopTimes"_L1).toArray();
    result.reserve(stopTimes.size());
    for (const auto &stopV : stopTimes) {
        const auto stop = stopV.toObject();
        Line line;
        const auto mode = stop.value("mode"_L1).toString();
        for (const auto &m : mode_map) {
            if (QLatin1StringView(m.name) == mode) {
                line.setMode(m.lineMode);
                break;
            }
        }
        line.setName(stop.value("routeShortName"_L1).toString());
        line.setOperatorName(stop.value("agencyName"_L1).toString());
        line.setColor(QColor::fromString('#'_L1 + stop.value("routeColor"_L1).toString()));
        line.setTextColor(QColor::fromString('#'_L1 + stop.value("routeTextColor"_L1).toString()));
        Route route;
        route.setLine(line);
        route.setDirection(stop.value("headsign"_L1).toString());

        const auto hasRealTime = stop.value("realTime"_L1).toBool();
        auto s = parsePlace(stop.value("place"_L1).toObject(), hasRealTime);
        s.setRoute(route);
        result.push_back(std::move(s));
    }

    parseCursors(response);
    return result;
}

struct {
    const char* name;
    Location::Type type;
} static constexpr const location_type_map[] = {
    { "ADDRESS", Location::Address },
    { "PLACE", Location::Place },
    { "STOP", Location::Stop },
};

std::vector<Location> Motis2Parser::parseLocations(const QByteArray &data) const
{
    const auto locations = QJsonDocument::fromJson(data).array();

    std::vector<Location> result;
    result.reserve(locations.size());

    for (const auto &locationV : locations) {
        const auto locObj = locationV.toObject();
        Location l;
        const auto type = locObj.value("type"_L1).toString();
        for (const auto &m :location_type_map) {
            if (QLatin1StringView(m.name) == type) {
                l.setType(m.type);
                break;
            }
        }
        l.setName(locObj.value("name"_L1).toString());
        l.setIdentifier(m_locIdentifierType, locObj.value("id"_L1).toString());
        l.setLatitude(locObj.value("lat"_L1).toDouble());
        l.setLongitude(locObj.value("lon"_L1).toDouble());
        l.setFloorLevel(locObj.value("level"_L1).toInt(std::numeric_limits<int>::lowest()));
        const auto areas = locObj.value("area"_L1).toArray();
        for (const auto &areaV : areas) {
            const auto area = areaV.toObject();
            if (const auto level = area.value("adminLevel"_L1).toInt(); level <= 8) {
                // TODO needs a proper country-specific admin-level mapping, for now taken from Motis v1 parser
                // see https://wiki.openstreetmap.org/wiki/Key:admin_level
                l.setLocality(area.value("name"_L1).toString());
            }
        }
        l.setPostalCode(locObj.value("zip"_L1).toString());
        l.setStreetAddress(locObj.value("street"_L1).toString() + ' '_L1 + locObj.value("houseNumber"_L1).toString());
        result.push_back(std::move(l));
    }

    return result;
}

std::vector<Location> Motis2Parser::parseMapStops(const QByteArray &data) const
{
    const auto locations = QJsonDocument::fromJson(data).array();

    std::vector<Location> result;
    result.reserve(locations.size());

    for (const auto &locationV : locations) {
        const auto stop = parsePlace(locationV.toObject(), false);
        auto loc = stop.stopPoint();
        loc.setType(Location::Stop);
        result.push_back(loc);
    }

    return result;
}

void Motis2Parser::parseCursors(const QJsonObject &obj)
{
    m_previousPageCursor = obj.value("previousPageCursor"_L1).toString();
    m_nextPageCursor = obj.value("nextPageCursor"_L1).toString();
}

/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "motis2parser.h"

#include "datatypes/rentalvehicleutil_p.h"
#include "gbfs/gbfsvehicletypes.h"
#include "geo/polylinedecoder_p.h"
#include "gtfs/hvt.h"

#include <KPublicTransport/Feature>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/RentalVehicle>
#include <KPublicTransport/StopInformation>
#include <KPublicTransport/Stopover>

#include <KCountry>
#include <KCountrySubdivision>

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

static void parseTimeZone(const QJsonObject &obj, Location &loc)
{
    const auto tzId = obj.value("tz"_L1).toString().toUtf8();
    if (tzId.isEmpty()) {
        return;
    }
    if (const auto tz = QTimeZone(tzId); tz.isValid()) {
        loc.setTimeZone(tz);
    }
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
    { "CABLE_CAR", Line::Mode::Tramway, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "FUNICULAR", Line::Mode::Funicular, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "AREAL_LIFT", Line::Mode::AerialLift, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "OTHER", Line::Mode::Unknown, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "AERIAL_LIFT", Line::Mode::RapidTransit, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "SUBURBAN", Line::Mode::RapidTransit, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
    { "RIDE_SHARING", Line::Mode::RideShare, JourneySection::PublicTransport, IndividualTransport::Car, IndividualTransport::None, RentalVehicle::Car },
    { "ODM", Line::Mode::Taxi, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None, RentalVehicle::Unknown },
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

constexpr inline auto PICKUP_DROPOFF_NOT_ALLED = "NOT_ALLOWED"_L1;

template <typename T>
void parseAlerts(T &elem, const QJsonArray &alerts)
{
    for (const auto &alertV : alerts) {
        const auto alertObj = alertV.toObject();
        const auto headline = alertObj.value("headerText"_L1).toString();
        const auto desc = alertObj.value("descriptionText"_L1).toString();
        if (!headline.isEmpty() && !desc.isEmpty()) {
            elem.addNote("<b>"_L1 + headline + "</b><br/>"_L1 + desc);
        } else {
            elem.addNote(headline);
            elem.addNote(desc);
        }
        if (alertObj.value("effect"_L1).toString() == "NO_SERVICE"_L1) {
            elem.setDisruptionEffect(Disruption::NoService);
        }
    }
}

static void parseStopModes(Location &loc, const QJsonArray &modes)
{
    StopInformation stopInfo;
    for (const auto &mode : modes) {
        const auto it = std::ranges::find_if(mode_map, [&mode](const auto &m) {
            return QLatin1StringView(m.name) == mode;
        });
        if (it == std::end(mode_map)) {
            qWarning() << "Unknown mode:" << mode;
            continue;
        }
        Line l;
        l.setMode((*it).lineMode);
        stopInfo.addLine(l);
    }
    if (!stopInfo.lines().empty()) {
        loc.setData(stopInfo);
    }
}

Stopover Motis2Parser::parsePlace(const QJsonObject &obj, bool hasRealTime) const
{
    Location l;
    l.setName(obj.value("name"_L1).toString());
    l.setIdentifier(m_locIdentifierType, obj.value("stopId"_L1).toString());
    l.setLatitude(obj.value("lat"_L1).toDouble(NAN));
    l.setLongitude(obj.value("lon"_L1).toDouble(NAN));
    l.setFloorLevel(obj.value("level"_L1).toInt(std::numeric_limits<int>::lowest()));
    parseTimeZone(obj, l);
    const auto type = obj.value("vertexType"_L1).toString();
    for (const auto &m : vertex_map ) {
        if (QLatin1StringView(m.name) == type) {
            l.setType(m.type);
            break;
        }
    }
    if (l.type() == Location::Stop) {
        parseStopModes(l, obj.value("modes"_L1).toArray());
    }

    Stopover s;
    s.setStopPoint(l);
    s.setScheduledPlatform(obj.value("scheduledTrack"_L1).toString());
    s.setScheduledDepartureTime(parseTime(obj.value("scheduledDeparture"_L1)));
    s.setScheduledArrivalTime(parseTime(obj.value("scheduledArrival"_L1)));
    if (hasRealTime) {
        s.setExpectedPlatform(obj.value("track"_L1).toString());
        s.setExpectedDepartureTime(parseTime(obj.value("departure"_L1)));
        s.setExpectedArrivalTime(parseTime(obj.value("arrival"_L1)));
    }

    if (obj.value("cancelled"_L1).toBool()) {
        s.setDisruptionEffect(Disruption::NoService);
    }

    if (obj.value("pickupType"_L1).toString() == PICKUP_DROPOFF_NOT_ALLED) {
        s.setPickupType(PickupDropoff::NotAllowed);
    }
    if (obj.value("dropoffType"_L1).toString() == PICKUP_DROPOFF_NOT_ALLED) {
        s.setDropoffType(PickupDropoff::NotAllowed);
    }

    parseAlerts(s, obj.value("alerts"_L1).toArray());

    return s;
}

Route Motis2Parser::parseRoute(const QJsonObject &obj) const
{
    Line line;
    Route route;

    if (const auto mode = Gtfs::Hvt::typeToMode(obj.value("routeType"_L1).toInt(-1)); mode != Line::Unknown) {
        line.setMode(mode);
    } else {
        const auto modeClass = obj.value("mode"_L1).toString();
        for (const auto &m : mode_map) {
            if (QLatin1StringView(m.name) == modeClass) {
                line.setMode(m.lineMode);
                break;
            }
        }
    }

    line.setName(obj.value("displayName"_L1).toString());
    if (line.name().isEmpty()) {
        line.setName(obj.value("routeShortName"_L1).toString());
    }
    if (const auto tripName = obj.value("tripShortName"_L1).toString(); !tripName.isEmpty() && !line.name().contains(tripName)) {
        route.setName(tripName);
    }

    line.setOperatorName(obj.value("agencyName"_L1).toString());
    line.setOperatorUrl(QUrl(obj.value("agencyUrl"_L1).toString()));
    line.setColor(QColor::fromString('#'_L1 + obj.value("routeColor"_L1).toString()));
    line.setTextColor(QColor::fromString('#'_L1 + obj.value("routeTextColor"_L1).toString()));

    route.setDirection(obj.value("headsign"_L1).toString());
    route.setDestination(parsePlace(obj.value("tripTo"_L1).toObject(), false).stopPoint());
    route.setLine(line);

    return route;
}

[[nodiscard]] static QPolygonF parsePolyLine(const QJsonObject &encodedPolyline)
{
    QPolygonF poly;
    poly.reserve(encodedPolyline.value("length"_L1).toInteger());
    const auto points = encodedPolyline.value("points"_L1).toString().toUtf8();
    PolylineDecoder<2> decoder(points.constData(), encodedPolyline.value("precision"_L1).toInt(7));
    decoder.readPolygon(poly);
    return poly;
}

std::vector<Journey> Motis2Parser::parseItineraries(const QByteArray &data)
{
    const auto content = QJsonDocument::fromJson(data).object();
    const auto itineraries = content.value("itineraries"_L1).toArray();
    const auto directs = content.value("direct"_L1).toArray();
    std::vector<Journey> result;
    result.reserve(itineraries.size() + directs.size());
    for (const auto &itineraryV : itineraries) {
        result.push_back(parseItinerary(itineraryV.toObject()));
    }
    for (const auto &directV : directs) {
        result.push_back(parseItinerary(directV.toObject()));
    }

    parseCursors(content);
    return result;
}

struct {
    const char *direction;
    PathSection::Maneuver maneuver;
} static constexpr const path_maneuver_map[] = {
    { "STAIRS", PathSection::Stairs },
    { "ELEVATOR", PathSection::Elevator },
};

Journey Motis2Parser::parseItinerary(const QJsonObject &itinerary) const
{
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
        auto from = parsePlace(leg.value("from"_L1).toObject(), hasRealTime);
        std::vector<Feature> features;
        if (leg["mode"_L1] == "NIGHT_RAIL"_L1) {
            features.push_back(Feature(Feature::SleeperCompartment));
        }
        if (leg["bikesAllowed"_L1].toBool()) {
            features.push_back(Feature(Feature::BikeStorage));
        }
        from.setFeatures(std::move(features));
        s.setDeparture(from);
        const auto to = parsePlace(leg.value("to"_L1).toObject(), hasRealTime);
        s.setArrival(to);
        s.setDistance(leg.value("distance"_L1).toInt());

        s.setScheduledDepartureTime(parseTime(leg.value("scheduledStartTime"_L1)));
        s.setScheduledArrivalTime(parseTime(leg.value("scheduledEndTime"_L1)));
        if (hasRealTime) {
            s.setExpectedDepartureTime(parseTime(leg.value("startTime"_L1)));
            s.setExpectedArrivalTime(parseTime(leg.value("endTime"_L1)));
        }

        if (s.mode() == JourneySection::PublicTransport) {
            s.setIdentifier(m_locIdentifierType, leg.value("tripId"_L1).toString());
            s.setRoute(parseRoute(leg));

            const auto intermediateStops = leg.value("intermediateStops"_L1).toArray();
            std::vector<Stopover> stops;
            stops.reserve(intermediateStops.size());
            for (const auto &intermediateStopV : intermediateStops) {
                const auto intermediateStop = intermediateStopV.toObject();
                stops.push_back(parsePlace(intermediateStop, hasRealTime));
            }
            s.setIntermediateStops(std::move(stops));

            if (leg.value("cancelled"_L1).toBool()) {
                s.setDisruptionEffect(Disruption::NoService);
            }

            parseAlerts(s, leg.value("alerts"_L1).toArray());
        } else if (s.mode() == JourneySection::IndividualTransport) {
            IndividualTransport iv;
            iv.setMode((*it).ivMode);
            iv.setQualifier((*it).ivQualifier);
            s.setIndividualTransport(iv);
        } else if (s.mode() == JourneySection::RentedVehicle) {
            const auto rentalObj = leg.value("rental"_L1).toObject();
            // TODO url

            RentalVehicleNetwork rvNetwork;
            rvNetwork.setName(rentalObj.value("systemName"_L1).toString());
            rvNetwork.setUrl(QUrl(rentalObj.value("url"_L1).toString()));

            RentalVehicle rv;
            rv.setType((*it).rentalType);
            rv.setNetwork(rvNetwork);
            rv.setWebBookingUrl(QUrl(rentalObj.value("rentalUriWeb"_L1).toString()));
#ifdef Q_OS_ANDROID
            rv.setAppBookingUrl(QUrl(rentalObj.value("rentalUriAndroid"_L1).toString()));
#elif defined(Q_OS_IOS)
            rv.setAppBookingUrl(QUrl(rentalObj.value("rentalUriIOS"_L1).toString()));
#endif

            s.setRentalVehicle(rv);
        }

        if (const auto legGeoArray = leg.value("steps"_L1).toArray(); !legGeoArray.empty()) {
            std::vector<PathSection> pathSections;
            pathSections.reserve(legGeoArray.size());
            for (const auto &legGeoV : legGeoArray) {
                const auto legGeoObj = legGeoV.toObject();
                PathSection pathSec;
                const auto relDir = legGeoObj.value("relativeDirection"_L1).toString();
                for (const auto &m : path_maneuver_map) {
                    if (QLatin1StringView(m.direction) == relDir) {
                        pathSec.setManeuver(m.maneuver);
                        break;
                    }
                }
                pathSec.setStartFloorLevel(legGeoObj.value("fromLevel"_L1).toInt(std::numeric_limits<int>::lowest()));
                if (pathSec.hasStartFloorLevel()) {
                    pathSec.setFloorLevelChange(legGeoObj.value("toLevel"_L1).toInt() - pathSec.startFloorLevel());
                }
                pathSec.setPath(parsePolyLine(legGeoObj.value("polyline"_L1).toObject()));
                if (const auto streetName = legGeoObj.value("streetName"_L1).toString(); !streetName.isEmpty()) {
                    pathSec.setDescription(streetName);
                }
                if (!pathSec.path().isEmpty() || pathSec.maneuver() != PathSection::Move) {
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
    return jny;
}

std::vector<Stopover> Motis2Parser::parseStopTimes(const QByteArray &data, bool isArrivals)
{
    std::vector<Stopover> result;

    const auto response = QJsonDocument::fromJson(data).object();
    const auto stopTimes = response.value("stopTimes"_L1).toArray();
    result.reserve(stopTimes.size());
    for (const auto &stopV : stopTimes) {
        const auto stop = stopV.toObject();
        const auto hasRealTime = stop.value("realTime"_L1).toBool();
        auto s = parsePlace(stop.value("place"_L1).toObject(), hasRealTime);
        s.setTripIdentifier(m_locIdentifierType, stop.value("tripId"_L1).toString());
        s.setRoute(parseRoute(stop));

        if (stop.value("cancelled"_L1).toBool()) {
            s.setDisruptionEffect(Disruption::NoService);
        }
        if (stop.value("pickupDropoffType"_L1).toString() == PICKUP_DROPOFF_NOT_ALLED) {
            isArrivals ? s.setDropoffType(PickupDropoff::NotAllowed) : s.setPickupType(PickupDropoff::NotAllowed);
        }

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

// see https://github.com/osm-search/Nominatim/blob/master/settings/address-levels.json
constexpr inline auto DEFAULT_REGION_LEVEL = 4;
struct {
    const char code[3];
    uint8_t level;
} static constexpr const region_admin_level_map[] = {
    { "BE", 6 },
    { "NO", 0 },
    { "SE", 0 },
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
        l.setCountry(locObj.value("country"_L1).toString());

        const auto areas = locObj.value("areas"_L1).toArray();
        std::vector<QJsonObject> adminLevels(12);
        for (const auto &areaV : areas) {
            const auto area = areaV.toObject();
            const auto level = area.value("adminLevel"_L1).toInt();
            if (level < 0 || level >= (int)adminLevels.size()) {
                continue;
            }
            adminLevels[level] = area;
        }

        // resolve country if needed
        // we need to do this here rather than relying on post-processing as the subsequent admin level mapping depends on it
        auto country = KCountry::fromAlpha2(l.country());
        if (!country.isValid()) {
            const auto countryName = adminLevels[2].value("name"_L1).toString();
            country = KCountry::fromName(countryName);
            if (!country.isValid()) {
                country = KCountry::fromLocation((float)l.latitude(), (float)l.longitude());
            }
            l.setCountry(country.isValid() ? country.alpha2() : countryName);
        }

        // resolve region
        if (const auto r = KCountrySubdivision::fromLocation((float)l.latitude(), (float)l.longitude()); r.isValid()) {
            l.setRegion(r.code());
        }
        if (country.isValid() && l.region().isEmpty()) {
            const auto it = std::find_if(std::begin(region_admin_level_map), std::end(region_admin_level_map), [country](const auto &m) {
                return QLatin1StringView(m.code, 2) == country.alpha2();
            });
            l.setRegion(adminLevels[it != std::end(region_admin_level_map) ? (*it).level :DEFAULT_REGION_LEVEL].value("name"_L1).toString());
        }

        // city name
        // TODO needs a proper country-specific admin-level mapping, for now taken from Motis v1 parser
        // see https://wiki.openstreetmap.org/wiki/Key:admin_level
        for (int i = 8; i < (int)adminLevels.size(); ++i) {
            if (const auto n = adminLevels[i].value("name"_L1).toString(); !n.isEmpty()) {
                l.setLocality(n);
                break;
            }
        }

        l.setPostalCode(locObj.value("zip"_L1).toString());
        l.setStreetAddress(QString(locObj.value("street"_L1).toString() + ' '_L1 + locObj.value("houseNumber"_L1).toString()).trimmed());

        parseTimeZone(locObj, l);

        if (l.type() == Location::Stop) {
            parseStopModes(l, locObj.value("modes"_L1).toArray());
        }

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

template <typename T>
static void readRentalBookingUrls(const QJsonObject &obj, T &rental)
{
    rental.setWebBookingUrl(QUrl(obj.value("rentalUriWeb"_L1).toString()));
#ifdef Q_OS_ANDROID
    rental.setAppBookingUrl(QUrl(obj.value("rentalUriAndroid"_L1).toString()));
#elif defined(Q_OS_IOS)
    rental.setAppBookingUrl(QUrl(obj.value("rentalUriIOS"_L1).toString()));
#endif
}

std::vector<Location> Motis2Parser::parseRentals(const QByteArray &data) const
{
    const auto rentalsObj = QJsonDocument::fromJson(data).object();

    const auto providersArray = rentalsObj.value("providers"_L1).toArray();
    std::unordered_map<QString, RentalVehicleNetwork> providers;
    providers.reserve(providersArray.size());
    std::unordered_map<QString, std::unordered_map<QString, GBFSVehicleType>> vehicleTypes;

    for (const auto &providerV : providersArray) {
        const auto providerObj = providerV.toObject();
        RentalVehicleNetwork provider;
        provider.setName(providerObj.value("name"_L1).toString());
        if (const auto purchaseUrl = providerObj.value("purchaseUrl"_L1).toString(); !purchaseUrl.isEmpty()) {
            provider.setUrl(QUrl(purchaseUrl));
        } else {
            provider.setUrl(QUrl(providerObj.value("url"_L1).toString()));
        }
        const auto providerId = providerObj.value("id"_L1).toString();

        std::unordered_map<QString, GBFSVehicleType> providerVehicleTypes;
        const auto typesArray = providerObj.value("vehicleTypes"_L1).toArray();
        providerVehicleTypes.reserve(typesArray.size());
        for (const auto &typeV : typesArray) {
            const auto typeObj = typeV.toObject();

            GBFSVehicleType vt;
            vt.typeId = typeObj.value("id"_L1).toString();
            vt.name = typeObj.value("name"_L1).toString();
            vt.formFactor = GBFSVehicleType::parseFormFactor(typeObj.value("formFactor"_L1).toString());
            vt.propulsionType = GBFSVehicleType::parsePropulsionType(typeObj.value("propulsionType"_L1).toString());

            provider.setVehicleTypes(provider.vehicleTypes() | RentalVehicleUtil::fromGbfsVehicleType(vt));
            providerVehicleTypes[vt.typeId] = std::move(vt);
        }

        providers[providerId] = std::move(provider);
        vehicleTypes[providerId] = std::move(providerVehicleTypes);
    }

    const auto stations = rentalsObj.value("stations"_L1).toArray();
    const auto vehicles = rentalsObj.value("vehicles"_L1).toArray();
    std::vector<Location> result;
    result.reserve(stations.size() + vehicles.size());

    for (const auto &stationV : stations) {
        const auto &stationObj = stationV.toObject();
        const auto providerId = stationObj.value("providerId"_L1).toString();

        Location l;
        l.setType(Location::RentedVehicleStation);
        l.setCoordinate(stationObj.value("lat"_L1).toDouble(), stationObj.value("lon"_L1).toDouble());
        l.setName(stationObj.value("name"_L1).toString());
        l.setIdentifier(m_locIdentifierType, providerId + ':'_L1 + stationObj.value("id"_L1).toString());
        if (const auto addr = stationObj.value("address"_L1).toString(); !addr.isEmpty()) {
            l.setStreetAddress(addr);
        }

        RentalVehicleStation s;
        readRentalBookingUrls(stationObj, s);
        s.setAvailableVehicles(stationObj.value("numVehiclesAvailable"_L1).toInt(-1));

        s.setNetwork(providers[providerId]);
        std::unordered_map<RentalVehicle::VehicleType, std::pair<int, int>> docks;
        const auto availableVehicles = stationObj.value("vehicleTypesAvailable"_L1).toObject();
        for (auto it = availableVehicles.begin(); it != availableVehicles.end(); ++it) {
            const auto t = RentalVehicleUtil::fromGbfsVehicleType(vehicleTypes[providerId][it.key()]);
            s.setAvailableVehicles(t, std::max(0, s.availableVehicles(t)) + it.value().toInt());
            docks[t].first = s.availableVehicles(t);
        }
        const auto availableDocks = stationObj.value("vehicleDocksAvailable"_L1).toObject();
        for (auto it = availableDocks.begin(); it != availableDocks.end(); ++it) {
            const auto t = RentalVehicleUtil::fromGbfsVehicleType(vehicleTypes[providerId][it.key()]);
            docks[t].second += it.value().toInt();
        }
        if (!availableDocks.isEmpty()) {
            for (auto it = docks.begin(); it != docks.end(); ++it) {
                s.setCapacity((*it).first, (*it).second.first + (*it).second.second);
            }
        }

        l.setData(std::move(s));
        result.push_back(std::move(l));
    }

    for (const auto &vehicleV : vehicles) {
        const auto vehicleObj = vehicleV.toObject();
        const auto providerId = vehicleObj.value("providerId"_L1).toString();

        if (vehicleObj.value("isReserved"_L1).toBool() || vehicleObj.value("isDisabled"_L1).toBool() || !vehicleObj.value("stationId"_L1).toString().isEmpty()) {
            continue;
        }

        Location l;
        l.setType(Location::RentedVehicle);
        l.setCoordinate(vehicleObj.value("lat"_L1).toDouble(), vehicleObj.value("lon"_L1).toDouble());
        l.setIdentifier(m_locIdentifierType, providerId + ':'_L1 + vehicleObj.value("id"_L1).toString());

        RentalVehicle v;
        readRentalBookingUrls(vehicleObj, v);
        v.setNetwork(providers[providerId]);

        const auto &vt = vehicleTypes[providerId][vehicleObj.value("typeId"_L1).toString()];
        v.setType(RentalVehicleUtil::fromGbfsVehicleType(vt));
        if (!vt.name.isEmpty()) {
            l.setName(vt.name);
        } else {
            l.setName(v.network().name());
        }
        l.setData(std::move(v));

        result.push_back(std::move(l));
    }

    return result;
}

void Motis2Parser::parseCursors(const QJsonObject &obj)
{
    m_previousPageCursor = obj.value("previousPageCursor"_L1).toString();
    m_nextPageCursor = obj.value("nextPageCursor"_L1).toString();
}

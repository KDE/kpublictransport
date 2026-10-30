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
} static constexpr const mode_map[] = {
    { "WALK", Line::Mode::Unknown, JourneySection::Walking, IndividualTransport::Walk, IndividualTransport::None },
    { "BIKE", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Bike, IndividualTransport::None },
    { "CAR", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Car, IndividualTransport::None },
    { "BIKE_TO_PARK", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Bike, IndividualTransport::Park },
    { "CAR_TO_PARK", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Car, IndividualTransport::Park },
    { "CAR_HAILING", Line::Mode::Taxi, JourneySection::PublicTransport, IndividualTransport::Car, IndividualTransport::None },
    { "CAR_PICKUP", Line::Mode::Unknown, JourneySection::IndividualTransport, IndividualTransport::Car, IndividualTransport::Pickup },
    { "FLEX", Line::Mode::Taxi, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None }, // TODO not properly modelled yet
    { "TRANSIT", Line::Mode::Unknown, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "TRAM", Line::Mode::Tramway, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "SUBWAY", Line::Mode::Metro, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "FERRY", Line::Mode::Ferry, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "AIRPLANE", Line::Mode::Air, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "BUS", Line::Mode::Bus, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "COACH", Line::Mode::Coach, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "RAIL", Line::Mode::Train, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "METRO", Line::Mode::RapidTransit, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "HIGHSPEED_RAIL", Line::Mode::LongDistanceTrain, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "LONG_DISTANCE", Line::Mode::LongDistanceTrain, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "NIGHT_RAIL", Line::Mode::LongDistanceTrain, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "REGIONAL_FAST_RAIL", Line::Mode::LocalTrain, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "REGIONAL_RAIL", Line::Mode::LocalTrain, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "CABLE_CAR", Line::Mode::Tramway, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "FUNICULAR", Line::Mode::Funicular, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "AREAL_LIFT", Line::Mode::AerialLift, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "OTHER", Line::Mode::Unknown, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "AERIAL_LIFT", Line::Mode::RapidTransit, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "SUBURBAN", Line::Mode::RapidTransit, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "RIDE_SHARING", Line::Mode::RideShare, JourneySection::PublicTransport, IndividualTransport::Car, IndividualTransport::None },
    { "ODM", Line::Mode::Taxi, JourneySection::PublicTransport, IndividualTransport::Walk, IndividualTransport::None },
    { "RENTAL", Line::Mode::Unknown, JourneySection::RentedVehicle, IndividualTransport::Walk, IndividualTransport::None },
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

static void alertPeriodRange(const QJsonArray &periodA, QDateTime &rangeStart, QDateTime &rangeEnd)
{
    for (const auto &periodV : periodA) {
        const auto period = periodV.toObject();
        const auto s = QDateTime::fromString(period.value("start"_L1).toString(), Qt::ISODate);
        if (s.isValid()) {
            rangeStart = rangeStart.isValid() ? std::min(s, rangeStart) : s;
        }
        auto e = QDateTime::fromString(period.value("end"_L1).toString(), Qt::ISODate);
        if (e.isValid()) {
            if (e.toSecsSinceEpoch() == 0) {
                e = QDateTime::currentDateTime().addDays(1000); // indefinite
            }
            rangeEnd = rangeEnd.isValid() ? std::max(e, rangeEnd) : e;
        }
    }
}

template <typename T>
static void parseAlerts(T &elem, const QJsonArray &alerts, QDateTime relevantTimeStart, QDateTime relevantTimeEnd)
{
    if (relevantTimeEnd.isValid() && !relevantTimeStart.isValid()) {
        relevantTimeStart = relevantTimeEnd;
    } else if (relevantTimeStart.isValid() && !relevantTimeEnd.isValid()) {
        relevantTimeEnd = relevantTimeStart;
    }

    for (const auto &alertV : alerts) {
        const auto alertObj = alertV.toObject();

        // discard alerts too far into the future or already in the past
        QDateTime start, end;
        alertPeriodRange(alertObj.value("communicationPeriod"_L1).toArray(), start, end);
        alertPeriodRange(alertObj.value("impactPeriod"_L1).toArray(), start, end);
        if (start.isValid() && relevantTimeEnd.date().addDays(30) < start.date()) {
            continue;
        }
        if (end.isValid() && relevantTimeStart.date().addDays(-1) > end.date()) {
            continue;
        }

        const auto headline = alertObj.value("headerText"_L1).toString();
        const auto desc = alertObj.value("descriptionText"_L1).toString();
        if (!headline.isEmpty() && !desc.isEmpty()) {
            elem.addNote("<b>"_L1 + headline + "</b><br/>"_L1 + desc);
        } else {
            elem.addNote(headline);
            elem.addNote(desc);
        }
        // we also get NO_SERVICE alerts for intermediate stops not serviced here from e.g. RER
        // that doesn't imply the entire section is out of service though
        if constexpr (!std::is_same_v<JourneySection, T>) {
            if (alertObj.value("effect"_L1).toString() == "NO_SERVICE"_L1) {
                elem.setDisruptionEffect(Disruption::NoService);
            }
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
    if (obj.value("name"_L1).toStringView() != u"START" && obj.value("name"_L1).toStringView() != u"END") {
        l.setName(obj.value("name"_L1).toString());
    }
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

    parseAlerts(s, obj.value("alerts"_L1).toArray(), s.scheduledArrivalTime(), s.scheduledDepartureTime());

    return s;
}

[[nodiscard]] static QStringView stripLeadingZeros(QStringView s)
{
    auto res = s;
    while (res.startsWith('0'_L1)) {
        res = res.mid(1);
    }
    return res;
}

Motis2Parser::MotisRoute Motis2Parser::parseRoute(const QJsonObject &obj) const
{
    Line line;
    MotisRoute res;

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
    if (const auto tripName = obj.value("tripShortName"_L1).toString(); !tripName.isEmpty()) {
        const auto cleanedTripName = stripLeadingZeros(tripName);
        if (line.name().endsWith(" ("_L1 + cleanedTripName + ')'_L1)) {
            line.setName(line.name().chopped(cleanedTripName.size() + 3));
            res.route.setName(cleanedTripName.toString());
        } else if (!line.name().contains(cleanedTripName)) {
            res.route.setName(tripName);
        }
    }

    line.setOperatorName(obj.value("agencyName"_L1).toString());
    line.setOperatorUrl(QUrl(obj.value("agencyUrl"_L1).toString()));
    line.setColor(QColor::fromString('#'_L1 + obj.value("routeColor"_L1).toString()));
    line.setTextColor(QColor::fromString('#'_L1 + obj.value("routeTextColor"_L1).toString()));

    res.route.setDirection(obj.value("headsign"_L1).toString());
    res.route.setDestination(parsePlace(obj.value("tripTo"_L1).toObject(), false).stopPoint());

    res.bookingUrl = QUrl(obj.value("agencyFareUrl"_L1).toString());
    if (obj.contains("ticketUrls"_L1)) {
        const auto urls = obj.value("ticketUrls"_L1).toObject();
        // prefer web url even on android
        // in the hope that it requires installing less third-party apps
        res.bookingUrl = QUrl(urls.value("web"_L1).toString());
#ifdef Q_OS_ANDROID
        if (res.bookingUrl.isEmpty()) {
            res.bookingUrl = QUrl(urls.value("android"_L1).toString());
        }
#endif
    }

    // Amarillo rideshare workarounds
    if (line.mode() == Line::RideShare) {
        // routeUrl has the booking URL
        if (res.bookingUrl.isEmpty()) {
            res.bookingUrl = QUrl(obj.value("routeUrl"_L1).toString());
        }
        // deal with the unreasonably long display names
        if (line.name().size() > 20 && line.name().contains(" -> "_L1) && !line.operatorName().isEmpty() && line.operatorName().size() < line.name().size()) {
            line.setName(line.operatorName());
        }
    }

    res.route.setLine(line);
    return res;
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

        if (leg["wheelchairAccessible"_L1] == "ACCESSIBLE"_L1) {
            features.emplace_back(Feature::WheelchairAccessible);
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
            const auto [route, bookingUrl] = parseRoute(leg);
            s.setRoute(route);
            s.setBookingUrl(bookingUrl);

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

            parseAlerts(s, leg.value("alerts"_L1).toArray(), s.scheduledDepartureTime(), s.scheduledArrivalTime());
        } else if (s.mode() == JourneySection::IndividualTransport) {
            IndividualTransport iv;
            iv.setMode((*it).ivMode);
            iv.setQualifier((*it).ivQualifier);
            s.setIndividualTransport(iv);
        } else if (s.mode() == JourneySection::RentedVehicle) {
            const auto rentalObj = leg.value("rental"_L1).toObject();

            RentalVehicleType vt;
            vt.setFormFactor(GBFSVehicleType::toFormFactor(rentalObj.value("formFactor"_L1).toString()));
            vt.setPropulsionType(GBFSVehicleType::toPropulsionType(rentalObj.value("propulsionType"_L1).toString()));

            RentalVehicleNetwork rvNetwork;
            rvNetwork.setName(rentalObj.value("systemName"_L1).toString());
            rvNetwork.setUrl(QUrl(rentalObj.value("url"_L1).toString()));
            rvNetwork.setBrandColor(QColor::fromString(rentalObj.value("color"_L1).toString()));

            RentalVehicle rv;
            rv.setVehicleType(vt);
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

                // ensure elevators have a position as well, for displaying them on a map
                if (pathSec.path().isEmpty() && pathSec.maneuver() == PathSection::Elevator && !pathSections.empty()) {
                    const auto prevPath = pathSections.back().path();
                    if (!prevPath.empty()) {
                        pathSec.setPath(QPolygonF({prevPath.back()}));
                    }
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
    jny.setIdentifier(m_locIdentifierType, itinerary.value("id"_L1).toString());
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
        s.setRoute(parseRoute(stop).route);

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

// basically the reverse to https://wiki.openstreetmap.org/wiki/OpenStreetMap_Carto/Symbols
// sorted by category, multiple tags to be applied can be listed sequentially
// categories we don't expect in geocoding are omitted'
struct {
    const char* category;
    const char* tagKey;
    const char* tagValue;
} static constexpr const category_tag_map[] = {
    {"aerodrome", "aeroway", "aerodrome"},
    {"alcohol_16", "shop", "alcohol"},
    {"alpinehut", "tourism", "alpine_hut"},
    {"amenity_bus_station", "amenity", "bus_station"},
    {"amusement_arcade_14", "leisure", "amusement_arcade"},
    {"apartment", "tourism", "appartment"},
    {"archaeological_site_16", "historic", "archaeological_site"},
    {"art_14", "shop", "art"},
    {"arts_centre", "amenity", "arts_centre"},
    {"artwork_14", "tourism", "artwork"},
    {"bag_14", "shop", "bag"},
    {"bakery_16", "shop", "bakery"},
    {"bank_16", "amenity", "bank"},
    {"bar_16", "amenity", "bar"},
    {"bbq_14", "amenity", "bbq"},
    {"beach_resort_14", "leisure", "beach_resort"},
    {"beauty_14", "shop", "beauty"},
    {"bed_14", "shop", "bed"},
    {"beverages_14", "shop", "beverages"},
    {"bicycle_16", "shop", "bicycle"},
    {"bicycle_repair_station_14", "amenity", "bicycle_repair_station"},
    {"biergarten_16", "amenity", "biergarten"},
    {"bird_hide_14", "leisure", "bird_hide"},
    {"boat_rental_14", "amenity", "boat_rental"},
    {"bookmaker_14", "shop", "bookmaker"},
    {"books_16", "shop", "books"},
    {"bowling_alley_14", "leisure", "bowling_alley"},
    {"buddhist_16", "amenity", "place_of_worship"},
    {"buddhist_16", "religion", "buddhist"},
    {"bureau_de_change_14", "amenity", "bureau_de_change"},
    {"bus_stop_12", "highway", "bus_stop"},
    {"butcher", "shop", "butcher"},
    {"cafe_16", "amenity", "cafe"},
    {"camping_16", "tourism", "camp_site"},
    {"car_parts_14", "shop", "car_parts"},
    {"car_repair_14", "shop", "car_repair"},
    {"car_wash_14", "amenity", "car_wash"},
    {"caravan_16", "tourism", "caravan_site"},
    {"carpet_14", "shop", "carpet"},
    {"carto_shrine", "historic", "wayside_shrine"},
    {"casino_14", "amenity", "casino"},
    {"castle_14", "historic", "castle"},
    {"cave_14", "natural", "cave_entrance"},
    {"chalet", "tourism", "chatlet"},
    {"charging_station_16", "amenity", "charging_station"},
    {"charity_14", "shop", "charity"},
    {"chemist_14", "shop", "chemist"},
    {"christian_16", "amenity", "place_of_worship"},
    {"christian_16", "religion", "christian"},
    {"cinema_16", "amenity", "cinema"},
    {"city_gate_14", "historic", "city_gate"},
    {"clothes_16", "shop", "clothes"},
    {"coffee_14", "shop", "coffee"},
    {"community_centre_14", "amenity", "community_centre"},
    {"computer_14", "shop", "computer"},
    {"confectionery_14", "shop", "confectionery"},
    {"convenience_14", "shop", "convenience"},
    {"copyshop_14", "shop", "copyshop"},
    {"courthouse_16", "amenity", "courthouse"},
    {"dairy", "shop", "dairy"},
    {"dam_node", "waterway", "dam"},
    {"deli_14", "shop", "deli"},
    {"dentist_14", "amenity", "dentist"},
    {"department_store_16", "shop", "department_store"},
    {"diplomatic", "office", "diplomatic"},
    {"diplomatic", "diplomatic", "embassy"},
    {"doctors_14", "amenity", "doctors"},
    {"dog_park", "leisure", "dog_park"},
    {"doityourself_16", "shop", "doityourself"},
    {"electronics_16", "shop", "electronics"},
    {"fabric_14", "shop", "fabric"},
    {"fast_food_16", "amenity", "fast_food"},
    {"ferry_icon", "amenity", "ferry_terminal"},
    {"fire_station_16", "amenity", "fire_station"},
    {"fishing_14", "leisure", "fishing"},
    {"fitness", "leisure", "fitness_centre"},
    {"florist_16", "shop", "florist"},
    {"ford_16", "ford", "yes"},
    {"fortress_14", "historic", "castle"},
    {"fortress_14", "castle", "fortress"},
    {"fountain_14", "amenity", "fountain"},
    {"fuel_16", "amenity", "fuel"},
    {"furniture_16", "shop", "furniture"},
    {"gallery_14", "tourism", "gallery"},
    {"garden_centre_14", "shop", "garden_centre"},
    {"gift_16", "shop", "gift"},
    {"golf_icon", "leisure", "golf_course"},
    {"greengrocer_14", "shop", "greengrocer"},
    {"hairdresser_16", "shop", "hairdresser"},
    {"hearing_aids", "shop", "hearing_aids"},
    {"helipad_16", "aeroway", "helipad"},
    {"hifi_14", "shop", "hifi"},
    {"hinduist_16", "amenity", "place_of_worship"},
    {"hinduist_16", "religion", "hinduist"},
    {"historic_fort", "historic", "fort"},
    {"hospital_14", "amenity", "hospital"},
    {"hostel_16", "tourism", "hostel"},
    {"hotel_16", "tourism", "hotel"},
    {"houseware_14", "shop", "houseware"},
    {"ice_cream_14", "amenity", "ice_cream"},
    {"interior_decoration_14", "shop", "interior_decoration"},
    {"internet_cafe_14", "amenity", "internet_cafe"},
    {"jewellery_16", "shop", "jewellery"},
    {"jewish_16", "amenity", "place_of_worship"},
    {"jewish_16", "religion", "jewish"},
    {"laundry_14", "shop", "laundry"},
    {"leisure_dance", "leisure", "dance"},
    {"library_16", "amenity", "library"},
    {"manor_14", "historic", "manor"},
    {"marketplace_14", "amenity", "marketplace"},
    {"massage_14", "shop", "massage"},
    {"medical_supply", "shop", "medical_supply"},
    {"memorial_16", "historic", "memorial"},
    {"miniature_golf", "leisure", "miniature_golf"},
    {"mobile_phone_16", "shop", "mobile_phone"},
    {"monument_16", "historic", "monument"},
    {"motel_16", "tourism", "motel"},
    {"mountain_pass_8", "mountain_pass", "yes"},
    {"museum_16", "tourism", "museum"},
    {"musical_instrument_14", "shop", "musical_instrument"},
    {"muslim_16", "amenity", "place_of_worship"},
    {"muslim_16", "religion", "muslim"},
    {"newsagent_14", "shop", "kiosk"},
    {"nightclub_16", "amenity", "nightclub"},
    {"obelisk_14", "man_made", "obelisk"},
    {"office_14", "tourism", "information"},
    {"office_14", "information", "office"},
    {"office_diplomatic_consulate", "office", "diplomatic"},
    {"office_diplomatic_consulate", "diplomatic", "consulate"},
    {"optician_16", "shop", "optician"},
    {"outdoor_14", "shop", "outdoor"},
    {"paint_14", "shop", "paint"},
    {"palace_14", "historic", "castle"},
    {"palace_14", "castle_type", "palace"},
    {"parking_16", "amenity", "parking"},
    {"parking_bicycle_16", "amenity", "bicycle_parking"},
    {"parking_motorcycle_16", "amenity", "motorcycle_parking"},
    {"peak_8", "natural", "peak"},
    {"perfumery_14", "shop", "cosmetics"},
    {"pet_16", "shop", "pet"},
    {"pharmacy_14", "amenity", "pharmacy"},
    {"photo_14", "shop", "photo"},
    {"picnic_site", "tourism", "picnic_site"},
    {"place_of_worship_16", "amenity", "place_of_worship"},
    {"playground_16", "leisure", "playground"},
    {"police_16", "amenity", "police"},
    {"post_office_14", "amenity", "post_office"},
    {"prison_16", "amenity", "prison"},
    {"pub_16", "amenity", "pub"},
    {"public_bath", "amenity", "public_bath"},
    {"public_bookcase_14", "amenity", "public_bookcase"},
    {"purple_car", "shop", "car"},
    {"rental_bicycle_16", "amenity", "bicycle_rental"},
    {"rental_car_16", "amenity", "car_rental"},
    {"restaurant_14", "amenity", "restaurant"},
    {"saddle_8", "natural", "saddle"},
    {"sauna_14", "leisure", "sauna"},
    {"seafood_14", "shop", "seafood"},
    {"second_hand_14", "shop", "second_hand"},
    {"shintoist_16", "amenity", "place_of_worship"},
    {"shintoist_16", "religion", "shintoist"},
    {"shoes_16", "shop", "shoes"},
    {"shop_motorcycle", "shop", "motorcycle"},
    {"shop_music", "shop", "music"},
    {"sikhist_16", "amenity", "place_of_worship"},
    {"sikhist_16", "religion", "sikhist"},
    {"social_facility_14", "amenity", "social_facility"},
    {"sports_14", "shop", "sports"},
    {"spring_14", "natural", "spring"},
    {"stationery_14", "shop", "stationery"},
    {"statue_14", "historic", "memorial"},
    {"statue_14", "memorial", "statue"},
    {"supermarket_14", "shop", "supermarket"},
    {"swimming_16", "leisure", "water_park"},
    {"taoist_16", "amenity", "place_of_worship"},
    {"taoist_16", "religion", "taoist"},
    {"taxi_16", "amenity", "taxi"},
    {"tea_14", "shop", "tea"},
    {"theatre_16", "amenity", "theatre"},
    {"ticket_14", "shop", "ticket"},
    {"tobacco_14", "shop", "tobacco"},
    {"toilets_16", "amenity", "toilets"},
    {"toll_booth", "barrier", "toll_booth"},
    {"tourism_guest_house", "tourism", "guest_house"},
    {"town_hall_16", "amenity", "townhall"},
    {"toys_14", "shop", "toys"},
    {"trade_14", "shop", "trade"},
    {"transport_slipway", "leisure", "slipway"},
    {"travel_agency_14", "shop", "travel_agency"},
    {"tyres", "shop", "tyres"},
    {"variety_store_14", "shop", "variety_store"},
    {"vehicle_inspection_14", "amenity", "vehicle_inspection"},
    {"veterinary_14", "amenity", "veterinary"},
    {"video_14", "shop", "video"},
    {"video_games_14", "shop", "video_games_14"},
    {"viewpoint_16", "tourism", "viewpoint"},
    {"volcano_8", "natural", "volcano"},
    {"waterfall_14", "waterway", "waterfall"},
    {"weir_node", "waterway", "weir"},
    {"wilderness_hut", "tourism", "wilderness_hut"},
};

#if __cplusplus > 201703L && defined(__GNUC__) && !defined(__clang__)
static_assert(std::is_sorted(std::begin(category_tag_map), std::end(category_tag_map), [](const auto &lhs, const auto &rhs) {
    return std::strcmp(lhs.category, rhs.category) < 0;
}));
#endif

#if 0 // TODO
  "shop_other_16",
  "office_16",
  "social_amenity_darken_16",

  "storage_tank_14",
  "tower_freestanding",
  "tower_cantilever_communication",
  "generator_wind_14",
  "hunting_stand_16",
  "christian_9",
  "water_tower_16",
  "mast_general",
  "bunker_osmcarto",
  "chimney_14",
  "tower_observation",
  "tower_bell_tower",
  "tower_lighting",
  "lighthouse_16",
  "column_14",
  "crane_14",
  "windmill_16",
  "tower_lattice_communication",
  "mast_lighting",
  "mast_communications",
  "communication_tower_14",
  "tower_defensive",
  "tower_cooling",
  "tower_lattice",
  "tower_lattice_lighting",
  "tower_dish",
  "tower_dome",
  "telescope_dish_14",
  "telescope_dome_14",

  "place_6",
  "place_capital_8",

  "country",
  "state",
  "region",
  "province",
  "district",
  "county",
  "subdistrict",
  "municipality",
  "city",
  "borough",
  "suburb",
  "quarter",
  "neighbourhood",
  "city_block",
  "plot",
  "town",
  "village",
  "hamlet",
  "isolated_dwelling",
  "farm",
  "allotments",
  "continent",
  "archipelago",
  "island",
  "islet",
  "square",
  "locality",
  "polder",
  "sea",
  "ocean",
  "extra"
#endif
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
        if (const auto street = locObj.value("street"_L1).toString(); !street.isEmpty()) {
            l.setStreetAddress(QString(street + ' '_L1 + locObj.value("houseNumber"_L1).toString()).trimmed());
        }

        parseTimeZone(locObj, l);

        if (l.type() == Location::Stop) {
            parseStopModes(l, locObj.value("modes"_L1).toArray());
        }

        if (const auto category = locObj.value("category"_L1).toStringView(); !category.isEmpty()) {
            auto it = std::lower_bound(std::begin(category_tag_map), std::end(category_tag_map), category, [](const auto &lhs, const auto &rhs) {
                return lhs.category < rhs;
            });
            for (; it != std::end(category_tag_map) && (*it).category == category; ++it) {
                l.setTagValue(QLatin1StringView((*it).tagKey), QLatin1StringView((*it).tagValue));
            }
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
    std::unordered_map<QString, std::unordered_map<QString, RentalVehicleType>> vehicleTypes;

    for (const auto &providerV : providersArray) {
        const auto providerObj = providerV.toObject();
        RentalVehicleNetwork provider;
        provider.setName(providerObj.value("name"_L1).toString());
        if (const auto purchaseUrl = providerObj.value("purchaseUrl"_L1).toString(); !purchaseUrl.isEmpty()) {
            provider.setUrl(QUrl(purchaseUrl));
        } else {
            provider.setUrl(QUrl(providerObj.value("url"_L1).toString()));
        }
        provider.setBrandColor(QColor::fromString(providerObj.value("color"_L1).toString()));
        const auto providerId = providerObj.value("id"_L1).toString();

        std::unordered_map<QString, RentalVehicleType> providerVehicleTypes;
        const auto typesArray = providerObj.value("vehicleTypes"_L1).toArray();
        providerVehicleTypes.reserve(typesArray.size());
        for (const auto &typeV : typesArray) {
            const auto typeObj = typeV.toObject();

            RentalVehicleType vt;
            vt.setId(typeObj.value("id"_L1).toString());
            vt.setName(typeObj.value("name"_L1).toString());
            vt.setFormFactor(GBFSVehicleType::toFormFactor(typeObj.value("formFactor"_L1).toString()));
            vt.setPropulsionType(GBFSVehicleType::toPropulsionType(typeObj.value("propulsionType"_L1).toString()));
            vt.setReturnConstraint(GBFSVehicleType::toReturnConstraint(typeObj.value("returnConstraint"_L1).toString()));

            providerVehicleTypes[vt.id()] = std::move(vt);
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
        std::unordered_map<QString, std::pair<int, int>> docks;
        const auto availableVehicles = stationObj.value("vehicleTypesAvailable"_L1).toObject();
        for (auto it = availableVehicles.begin(); it != availableVehicles.end(); ++it) {
            const auto &vt = vehicleTypes[providerId][it.key()];
            s.setAvailableVehicles(vt, it.value().toInt());
            docks[vt.id()].first = it.value().toInt();
        }
        const auto availableDocks = stationObj.value("vehicleDocksAvailable"_L1).toObject();
        for (auto it = availableDocks.begin(); it != availableDocks.end(); ++it) {
            docks[vehicleTypes[providerId][it.key()].id()].second += it.value().toInt();
        }
        if (!availableDocks.isEmpty()) {
            for (auto it = docks.begin(); it != docks.end(); ++it) {
                s.setCapacity({vehicleTypes[providerId][(*it).first]}, (*it).second.first + (*it).second.second);
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
        v.setVehicleType(vt);
        if (!vt.name().isEmpty()) {
            l.setName(vt.name());
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

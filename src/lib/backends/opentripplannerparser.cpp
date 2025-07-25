/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "opentripplannerparser.h"
#include "gtfs/hvt.h"
#include "geo/polylinedecoder_p.h"
#include "ifopt/ifoptutil.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Stopover>

#include <QColor>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QTimeZone>

#include <bitset>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

OpenTripPlannerParser::OpenTripPlannerParser(const QString &identifierType, const QString &ifoptPrefix)
    : m_identifierType(identifierType)
    , m_ifoptPrefix(ifoptPrefix)
{
}

OpenTripPlannerParser::~OpenTripPlannerParser() = default;

void OpenTripPlannerParser::setKnownRentalVehicleNetworks(const QHash<QString, RentalVehicleNetwork> &networks)
{
    m_rentalVehicleNetworks = networks;
}

QVariant OpenTripPlannerParser::parseRentalVehicleData(const QJsonObject &obj) const
{
    RentalVehicleNetwork network;
    // TODO id
    const auto networks = obj.value(QLatin1String("networks")).toArray();
    if (!networks.empty()) {
        const auto it = m_rentalVehicleNetworks.find(networks.at(0).toString());
        if (it != m_rentalVehicleNetworks.end()) {
            network = it.value();
        } else {
            network.setName(networks.at(0).toString());
        }
    }

    const auto capacity = obj.value(QLatin1String("spacesAvailable")).toInt(-1);
    const auto available = obj.value(QLatin1String("bikesAvailable")).toInt(-1);
    if (capacity == 0 && available == 1) { // heuristic for distinguishing floating vehicles and docks
        RentalVehicle v;
        v.setNetwork(network);
        v.setType(static_cast<RentalVehicle::VehicleType>(static_cast<int>(network.vehicleTypes())));
        return v;
    }

    RentalVehicleStation s;
    s.setNetwork(network);
    s.setCapacity(capacity);
    s.setAvailableVehicles(available);
    return s;
}

bool OpenTripPlannerParser::parseLocationFragment(const QJsonObject &obj, Location &loc) const
{
    const auto parentObj = obj.value(QLatin1String("parentStation")).toObject();
    if (!parentObj.isEmpty()) {
        loc.setType(Location::Stop);
        return parseLocationFragment(parentObj, loc);
    }

    if (loc.name().isEmpty()) {
        loc.setName(obj.value(QLatin1String("name")).toString());
    }
    loc.setLatitude(obj.value(QLatin1String("lat")).toDouble(loc.latitude()));
    loc.setLongitude(obj.value(QLatin1String("lon")).toDouble(loc.longitude()));

    const auto tzId = obj.value(QLatin1String("timezone")).toString();
    if (!tzId.isEmpty()) {
        loc.setTimeZone(QTimeZone(tzId.toUtf8()));
    }

    const auto id = obj.value(QLatin1String("id")).toString();
    if (!id.isEmpty()) {
        loc.setIdentifier(m_identifierType, id);
    }
    if (!m_ifoptPrefix.isEmpty() && id.size() > m_ifoptPrefix.size() + 1 && id.startsWith(m_ifoptPrefix) && id.at(m_ifoptPrefix.size()) == QLatin1Char(':')) {
        const auto ifopt = QStringView(id).mid(m_ifoptPrefix.size() + 1);
        if (IfoptUtil::isValid(ifopt)) {
            loc.setIdentifier(IfoptUtil::identifierType(), ifopt.toString());
        }
    }

    const auto bss = obj.value(QLatin1String("bikeRentalStation")).toObject();
    if (!bss.isEmpty()) {
        loc.setData(parseRentalVehicleData(bss));
        loc.setType(loc.data().userType() == qMetaTypeId<RentalVehicle>() ? Location::RentedVehicle : Location::RentedVehicleStation);
        return loc.rentalVehicleStation().network().isValid() || loc.rentalVehicle().network().isValid();
    }

    const auto mode = obj.value(QLatin1String("vehicleMode")).toString();
    if (mode == QLatin1String("CARPOOL")) {
        loc.setType(Location::CarpoolPickupDropoff);
    } else if (!mode.isEmpty() && loc.type() == Location::Place) {
        loc.setType(Location::Stop);
    }

    return true;
}

Location OpenTripPlannerParser::parseLocation(const QJsonObject &obj) const
{
    const auto stop = obj.value(QLatin1String("stop")).toObject();
    const auto bikeRental = obj.value(QLatin1String("bikeRentalStation")).toObject();

    Location loc;
    auto valid = parseLocationFragment(bikeRental, loc);
    if (!stop.empty()) {
        loc.setType(Location::Stop);
        valid &= parseLocationFragment(stop, loc);
    }
    valid &= parseLocationFragment(obj, loc);
    return valid ? loc : Location();
}

std::vector<Location> OpenTripPlannerParser::parseLocationsByCoordinate(const QJsonObject &obj) const
{
    std::vector<Location> locs;
    const auto stopArray = obj.value(QLatin1String("stopsByRadius")).toObject().value(QLatin1String("edges")).toArray();
    locs.reserve(stopArray.size());
    for (const auto &stop : stopArray) {
        auto l = parseLocation(stop.toObject().value(QLatin1String("node")).toObject());
        if (!l.isEmpty()) {
            locs.push_back(std::move(l));
        }
    }

    // deduplicate elements, which we get due to searching for stops rather than stations
    std::stable_sort(locs.begin(), locs.end(), [this](const auto &lhs, const auto &rhs) {
        return lhs.identifier(m_identifierType) < rhs.identifier(m_identifierType);
    });
    locs.erase(std::unique(locs.begin(), locs.end(), [this](const auto &lhs, const auto &rhs) {
        return lhs.identifier(m_identifierType) == rhs.identifier(m_identifierType);
    }), locs.end());

    return locs;
}

std::vector<Location> OpenTripPlannerParser::parseLocationsByName(const QJsonObject &obj) const
{
    std::vector<Location> locs;
    const auto stationArray = obj.value(QLatin1String("stations")).toArray();
    locs.reserve(stationArray.size());
    for (const auto &station : stationArray) {
        auto l = parseLocation(station.toObject());
        if (!l.isEmpty()) {
            locs.push_back(std::move(l));
        }
    }
    return locs;
}

std::vector<Location> OpenTripPlannerParser::parseLocationsArray(const QJsonArray &array) const
{
    std::vector<Location> locs;
    locs.reserve(array.size());
    for (const auto &l : array) {
        locs.push_back(parseLocation(l.toObject()));
    }
    return locs;
}

std::vector<Location> OpenTripPlannerParser::parseGeocodeResult(const QJsonArray &array) const
{
    std::vector<Location> locs;
    locs.reserve(array.size());
    for (const auto &v : array) {
        const auto obj = v.toObject();
        Location loc;
        loc.setLatitude(obj.value(QLatin1String("lat")).toDouble());
        loc.setLongitude(obj.value(QLatin1String("lng")).toDouble()); // sic!
        auto desc = obj.value(QLatin1String("description")).toString();
        if (desc.startsWith(QLatin1String("stop "))) {
            desc = desc.mid(5);
        }
        loc.setName(desc);
        loc.setIdentifier(m_identifierType, obj.value(QLatin1String("id")).toString());
        locs.push_back(loc);
    }
    return locs;
}

void OpenTripPlannerParser::parseAlerts(const QJsonArray& alertsArray) const
{
    m_alerts.reserve(alertsArray.size());
    for (const auto &alertValue : alertsArray) {
        const auto alertObj = alertValue.toObject();
        const auto descsArray = alertObj.value("alertDescriptionTextTranslations"_L1).toArray();
        if (descsArray.empty()) {
            // new OTP2 alerts API
            const auto hdr = alertObj.value("alertHeaderText"_L1).toString();
            const auto desc = alertObj.value("alertDescriptionText"_L1).toString();
            if (hdr.isEmpty() && desc.isEmpty()) {
            } else if (hdr == desc || desc.isEmpty()) {
                m_alerts.push_back(hdr);
            } else if (hdr.isEmpty() || desc.startsWith(hdr)) {
                m_alerts.push_back(desc);
            } else {
                m_alerts.push_back("<b>"_L1 + hdr + "</b><br/>"_L1 + desc);
            }
            continue;
        }

        // find the best language
        const auto uiLangs = QLocale().uiLanguages();
        int minIdx = 0, minWeight = std::numeric_limits<int>::max();
        for (int i = 0; i < descsArray.size(); ++i) {
            const auto lang = descsArray.at(i).toObject().value("language"_L1).toString();
            for (int j = 0; j < uiLangs.size() && j < minWeight; ++j) {
                if (uiLangs.at(j).startsWith(lang)) {
                    minIdx = i;
                    minWeight = j;
                    break;
                }
            }
        }

        m_alerts.push_back(descsArray.at(minIdx).toObject().value("text"_L1).toString());
    }
}

static QColor parseColor(const QJsonValue &value)
{
    if (value.isNull()) {
        return {};
    }
    return QColor(QLatin1Char('#') + value.toString());
}

OpenTripPlannerParser::RouteData OpenTripPlannerParser::parseLine(const QJsonObject &obj) const
{
    parseAlerts(obj.value(QLatin1String("alerts")).toArray());

    Line line;
    for (const auto &key : {"shortName"_L1, "longName"_L1, "name"_L1}) {
        line.setName(obj.value(key).toString());
        if (!line.name().isEmpty()) {
            break;
        }
    }
    line.setOperatorName(obj.value("agency"_L1).toObject().value("name"_L1).toString());

    const auto type = obj.value(QLatin1String("type"));
    if (type.isString()) {
        line.setMode(Gtfs::Hvt::typeToMode(type.toString()));
    } else if (type.isDouble()) {
        line.setMode(Gtfs::Hvt::typeToMode(type.toInt(-1)));
    }
    if (line.mode() == Line::Unknown) {
        line.setMode(Gtfs::Hvt::typeToMode(obj.value(QLatin1String("transportMode")).toString()));
    }

    auto presentation = obj.value(QLatin1String("presentation")).toObject();
    if (presentation.isEmpty()) {
        presentation = obj;
    }
    line.setColor(parseColor(presentation.value(QLatin1String("color"))));
    line.setTextColor(parseColor(presentation.value(QLatin1String("textColor"))));

    RouteData data;
    data.route.setLine(line);

    return data;
}

struct {
    const char *name;
    const char *enturName;
    Load::Category occupancy;
} constexpr inline const occupancy_map[] = {
    { "CRUSHED_STANDING_ROOM_ONLY", "crushedStandingRoomOnly", Load::High },
    { "EMPTY", "empty", Load::Low },
    { "FEW_SEATS_AVAILABLE", "fewSeatsAvailable", Load::Medium },
    { "FULL", "full", Load::Full },
    { "MANY_SEATS_AVAILABLE", "manySeatsAvailable", Load::Low },
    { "NOT_ACCEPTING_PASSENGERS", "notAcceptingPassengers", Load::Full },
    { "NO_DATA_AVAILABLE", "noData", Load::Unknown },
    { "STANDING_ROOM_ONLY", "standingRoomOnly", Load::High },
};

[[nodiscard]] static Load::Category parseOccupancy(const QJsonValue &v)
{
    QString occupancy;
    if (v.isString()) {
        occupancy = v.toString();
    } else {
        occupancy = v.toObject().value("occupancyStatus"_L1).toString();
    }

     for (const auto &m : occupancy_map) {
        if (QLatin1StringView(m.name) == occupancy || QLatin1StringView(m.enturName) == occupancy) {
            return m.occupancy;
        }
    }

    if (!occupancy.isEmpty()) {
        qDebug() << "Unknown OTP2 occupancy level:" << occupancy;
    }
    return Load::Unknown;
}

struct {
    const char *name;
    Feature::Availability availability;
} static constexpr const bikes_allowed_map[] = {
    { "ALLOWED", Feature::Available },
    { "NOT_ALLOWED", Feature::Unavailable },
    { "NO_INFORMATION", Feature::Unknown },
    { "allowed", Feature::Available },
    { "noInformation", Feature::Unknown },
    { "notAllowed", Feature::Unavailable },
};

struct {
    const char *name;
    Feature::Availability availability;
} static constexpr const wheelchair_access_map[] = {
    { "NOT_POSSIBLE", Feature::Unavailable },
    { "NO_INFORMATION", Feature::Unknown },
    { "POSSIBLE", Feature::Available },
    { "noInformation", Feature::Unknown },
    { "notPossible", Feature::Unavailable },
    { "possible", Feature::Available },
};

OpenTripPlannerParser::RouteData OpenTripPlannerParser::parseRoute(const QJsonObject &obj) const
{
    auto data = parseLine(obj.value("route"_L1).toObject());
    auto line = data.route.line();
    if (const auto name = obj.value("tripShortName"_L1).toString(); !name.isEmpty()) {
        line.setName(name);
    }

    data.route.setLine(line);
    data.route.setDirection(obj.value("tripHeadsign"_L1).toString());
    data.occupancy = parseOccupancy(obj.value("occupancy"_L1));

    {
        const auto bikesAllowed = obj.value("bikesAllowed"_L1).toString();
        const auto it = std::find_if(std::begin(bikes_allowed_map), std::end(bikes_allowed_map), [&bikesAllowed](auto m) {
            return bikesAllowed == QLatin1StringView(m.name);
        });
        if (it != std::end(bikes_allowed_map)) {
            data.features.emplace_back(Feature::BikeStorage, (*it).availability);
        }
    }

    {
        const auto wheelchairAccess = obj.value("wheelchairAccessible"_L1).toString();
        const auto it = std::find_if(std::begin(wheelchair_access_map), std::end(wheelchair_access_map), [&wheelchairAccess](auto m) {
            return wheelchairAccess == QLatin1StringView(m.name);
        });
        if (it != std::end(wheelchair_access_map)) {
            data.features.emplace_back(Feature::WheelchairAccessible, (*it).availability);
        }
    }

    return data;
}

OpenTripPlannerParser::RouteData OpenTripPlannerParser::parseInlineRoute(const QJsonObject &obj) const
{
    Line line;
    line.setMode(Gtfs::Hvt::typeToMode(obj.value(QLatin1String("routeType")).toInt(-1)));
    line.setName(obj.value(QLatin1String("tripShortName")).toString());
    line.setColor(parseColor(obj.value(QLatin1String("routeColor"))));
    line.setTextColor(parseColor(obj.value(QLatin1String("routeTextColor"))));

    RouteData data;
    data.route.setDirection(obj.value(QLatin1String("headsign")).toString());
    data.route.setLine(line);

    return data;
}

OpenTripPlannerParser::RouteData OpenTripPlannerParser::detectAndParseRoute(const QJsonObject &obj) const
{
    const auto trip = obj.value(QLatin1String("trip")).toObject();
    if (!trip.isEmpty()) {
        return parseRoute(trip);
    }

    const auto line = obj.value(QLatin1String("line")).toObject();
    if (!line.isEmpty()) {
        return parseLine(obj.value(QLatin1String("line")).toObject());
    }

    return parseInlineRoute(obj);
}

struct {
    const char *name;
    PickupDropoff::Type type;
} constexpr inline const pickupDropoff_map[] = {
    { "CALL_AGENCY", PickupDropoff::CallAgency },
    { "COORDINATE_WITH_DRIVER", PickupDropoff::CoordinateWithDriver },
    { "NONE", PickupDropoff::NotAllowed },
    { "SCHEDULED", PickupDropoff::Normal },
};

[[nodiscard]] PickupDropoff::Type parsePickupDropoffType(QStringView name)
{
    for (const auto &m :pickupDropoff_map) {
        if (QLatin1StringView(m.name) == name) {
            return m.type;
        }
    }
    if (!name.isEmpty()) {
        qDebug() << "Unknown pickup/dropoff value:" << name;
    }
    return PickupDropoff::Normal;
}

Stopover OpenTripPlannerParser::parseStoptime(const QJsonObject &obj) const
{
    Stopover s;
    s.setStopPoint(parseLocation(obj));
    s.setScheduledPlatform(obj.value("stop"_L1).toObject().value("platformCode"_L1).toString());

    if (const auto occupancy = parseOccupancy(obj.value("occupancyStatus"_L1)); occupancy != Load::Category::Unknown) {
        s.setLoadInformation({occupancy});
    }
    auto routeData = detectAndParseRoute(obj);
    s.setRoute(routeData.route);
    s.setFeatures(std::move(routeData.features));
    if (routeData.occupancy != Load::Unknown) {
        s.setLoadInformation({routeData.occupancy});
    }

    // OTP
    s.setPickupType(parsePickupDropoffType(obj.value("pickupType"_L1).toString()));
    s.setDropoffType(parsePickupDropoffType(obj.value("dropoffType"_L1).toString()));

    // Entur
    const auto requestStop = obj.value("requestStop"_L1).toBool(false);
    if (const auto v = obj.value("forBoarding"_L1); v.isBool()) {
        s.setPickupType(v.toBool() ? (requestStop ? PickupDropoff::CoordinateWithDriver : PickupDropoff::Normal) : PickupDropoff::NotAllowed);
    }
    if (const auto v = obj.value("forAlighting"_L1); v.isBool()) {
        s.setDropoffType(v.toBool() ? (requestStop ? PickupDropoff::CoordinateWithDriver : PickupDropoff::Normal) : PickupDropoff::NotAllowed);
    }

    return s;
}

static QDateTime parseDepartureDateTime(qint64 baseTime, const QJsonValue &value)
{
    if (value.isDouble()) { // encoded as seconds offset to baseTime
        // UNIX timestamp of midnight in local timezone + UNIX timestamp of local time
        auto dt = QDateTime::fromSecsSinceEpoch(baseTime + value.toInteger());
        dt = dt.toTimeZone(QTimeZone::UTC);
        return dt;
    }
    return QDateTime::fromString(value.toString(), Qt::ISODate);
}

Stopover OpenTripPlannerParser::parseDeparture(const QJsonObject &obj) const
{
    auto dep = parseStoptime(obj);
    dep.setTripIdentifier(m_identifierType, obj.value("trip"_L1).toObject().value("id"_L1).toString());
    const auto baseTime = obj.value("serviceDay"_L1).toInteger();
    dep.setScheduledArrivalTime(parseDepartureDateTime(baseTime, obj.value("scheduledArrival"_L1)));
    dep.setScheduledDepartureTime(parseDepartureDateTime(baseTime, obj.value("scheduledDeparture"_L1)));
    if (obj.value("realtime"_L1).toBool()) {
        dep.setExpectedArrivalTime(parseDepartureDateTime(baseTime, obj.value("realtimeArrival"_L1)));
        dep.setExpectedDepartureTime(parseDepartureDateTime(baseTime, obj.value("realtimeDeparture"_L1)));
    }
    dep.addNotes(m_alerts);
    m_alerts.clear();

    return dep;
}

void OpenTripPlannerParser::parseDeparturesForStop(const QJsonObject &obj, std::vector<Stopover> &deps) const
{
    const auto loc = parseLocation(obj);
    const auto stopTimes = obj.value(QLatin1String("stoptimes")).toArray();
    for (const auto &stopTime : stopTimes) {
        auto dep = parseDeparture(stopTime.toObject());
        dep.setStopPoint(loc);
        deps.push_back(dep);
    }
}

std::vector<Stopover> OpenTripPlannerParser::parseDepartures(const QJsonObject &obj) const
{
    std::vector<Stopover> deps;

    const auto depsArray = obj.value(QLatin1String("nearest")).toObject().value(QLatin1String("edges")).toArray();
    for (const auto &depsV : depsArray) {
        parseDeparturesForStop(depsV.toObject().value(QLatin1String("node")).toObject().value(QLatin1String("place")).toObject(), deps);
    }

    return deps;
}

std::vector<Stopover> OpenTripPlannerParser::parseDeparturesArray(const QJsonArray &array) const
{
    std::vector<Stopover> deps;
    for (const auto &pattern : array) {
        const auto obj = pattern.toObject();
        const auto times = obj.value(QLatin1String("times")).toArray();
        for (const auto &time : times) {
            deps.push_back(parseDeparture(time.toObject()));
        }
    }
    return deps;
}


static QDateTime parseJourneyDateTime(const QJsonValue &val)
{
    if (val.isDouble()) {
        // timestamp, as UTC value
        auto dt = QDateTime::fromMSecsSinceEpoch(val.toInteger());
        dt = dt.toTimeZone(QTimeZone::UTC);
        return dt;
    }
    if (val.isString()) {
        return QDateTime::fromString(val.toString(), Qt::ISODate);
    }
    return {};
}

static RentalVehicle::VehicleType vehicleTypeFromTypes(RentalVehicle::VehicleTypes types, RentalVehicle::VehicleType fallback = RentalVehicle::Unknown)
{
    if (std::bitset<sizeof(types)>(types).count() == 1) {
        return static_cast<RentalVehicle::VehicleType>(static_cast<int>(types));
    }
    return fallback;
}

JourneySection OpenTripPlannerParser::parseJourneySection(const QJsonObject &obj) const
{
    auto dep = parseStoptime(obj.value("fromStoptime"_L1).toObject()); // Entur only
    auto arr = parseStoptime(obj.value("toStoptime"_L1).toObject());

    dep.setScheduledDepartureTime(parseJourneyDateTime(obj.value("startTime"_L1)));
    arr.setScheduledArrivalTime(parseJourneyDateTime(obj.value("endTime"_L1)));
    if (obj.value("realTime"_L1).toBool()) {
        dep.setExpectedDepartureTime(parseJourneyDateTime(obj.value("expectedStartTime"_L1)));
        if (!dep.expectedDepartureTime().isValid()) {
            dep.setExpectedDepartureTime(dep.scheduledDepartureTime().addSecs(obj.value("departureDelay"_L1).toInteger()));
        }
        arr.setExpectedArrivalTime(parseJourneyDateTime(obj.value("expectedEndTime"_L1)));
        if (!arr.expectedArrivalTime().isValid()) {
            arr.setExpectedArrivalTime(arr.scheduledArrivalTime().addSecs(obj.value("arrivalDelay"_L1).toInteger()));
        }
    }

    const auto fromObj = obj.value("from"_L1).toObject();
    const auto fromStop = fromObj.value("stop"_L1).toObject();
    const auto from = parseLocation(fromObj);
    dep.setStopPoint(from);
    dep.setScheduledPlatform(fromStop.value("platformCode"_L1).toString());

    const auto toObj = obj.value("to"_L1).toObject();
    const auto toStop = toObj.value("stop"_L1).toObject();
    const auto to = parseLocation(toObj);
    arr.setStopPoint(to);
    arr.setScheduledPlatform(toStop.value("platformCode"_L1).toString());

    // OTP only
    if (const auto pickup = obj.value("pickupType"_L1).toString(); !pickup.isEmpty()) {
        dep.setPickupType(parsePickupDropoffType(pickup));
    }
    if (const auto dropoff = obj.value("dropoffType"_L1).toString(); !dropoff.isEmpty()) {
        arr.setDropoffType(parsePickupDropoffType(dropoff));
    }

    JourneySection section;
    section.setDeparture(dep);
    section.setArrival(arr);
    section.setDistance(obj.value("distance"_L1).toDouble());

    if (obj.value("transitLeg"_L1).toBool()) {
        section.setMode(JourneySection::PublicTransport);
        section.setIdentifier(m_identifierType, obj.value("trip"_L1).toObject().value("id"_L1).toString());
        if (const auto occupancy = parseOccupancy(obj.value("occupancy"_L1)); occupancy != Load::Category::Unknown) {
            section.setLoadInformation({occupancy});
        }
        auto routeData = detectAndParseRoute(obj);
        section.setRoute(routeData.route);
        section.setFeatures(std::move(routeData.features));
        if (routeData.occupancy != Load::Unknown) {
            section.setLoadInformation({routeData.occupancy});
        }
    } else {
        const auto mode = obj.value(QLatin1String("mode")).toString();
        const auto isRented = obj.value(QLatin1String("rentedBike")).toBool();

        if (mode.compare(QLatin1String("WALK"), Qt::CaseInsensitive) == 0 || mode.compare(QLatin1String("FOOT"), Qt::CaseInsensitive) == 0) {
            section.setMode(JourneySection::Walking);
        } else if (mode.compare(QLatin1String("BICYCLE"), Qt::CaseInsensitive) == 0) {
            RentalVehicle v;
            if (from.rentalVehicleStation().network().isValid()) {
                v.setNetwork(from.rentalVehicleStation().network());
            } else if (from.type() == Location::RentedVehicle) {
                v = from.data().value<RentalVehicle>();
            } else if (to.rentalVehicleStation().network().isValid()) {
                v.setNetwork(to.rentalVehicleStation().network());
            }
            v.setType(vehicleTypeFromTypes(v.network().vehicleTypes(), RentalVehicle::Bicycle));
            if (v.network().isValid() || isRented) {
                section.setMode(JourneySection::RentedVehicle);
                section.setRentalVehicle(v);
            } else {
                section.setMode(JourneySection::IndividualTransport);
                section.setIndividualTransport({ IndividualTransport::Bike });
            }
        } else if (mode.compare(QLatin1String("CAR"), Qt::CaseInsensitive) == 0) {
            section.setMode(JourneySection::IndividualTransport);
            section.setIndividualTransport({ IndividualTransport::Car });
        } else {
            qWarning() << "Unhandled OTP mode:" << mode;
        }
    }

    section.addNotes(m_alerts);
    m_alerts.clear();

    const auto stopsA = obj.value(QLatin1String("intermediateStops")).toArray();
    std::vector<Stopover> stops;
    stops.reserve(stopsA.size());
    for (const auto &stopV : stopsA) {
        const auto stopObj = stopV.toObject();

        auto stop = parseStoptime(stopObj);
        stop.setScheduledArrivalTime(parseJourneyDateTime(stopObj.value(QLatin1String("scheduledArrivalTime"))));
        stop.setScheduledDepartureTime(parseJourneyDateTime(stopObj.value(QLatin1String("scheduledDepartureTime"))));
        stop.setExpectedArrivalTime(parseJourneyDateTime(stopObj.value(QLatin1String("expectedArrivalTime"))));
        stop.setExpectedDepartureTime(parseJourneyDateTime(stopObj.value(QLatin1String("expectedDepartureTime"))));

        stops.push_back(stop);
    }
    section.setIntermediateStops(std::move(stops));

    const auto geometryObj = obj.value(QLatin1String("legGeometry")).toObject();
    QPolygonF poly;
    if (!geometryObj.empty()) {
        poly.reserve(geometryObj.value(QLatin1String("length")).toInt());
        const auto points = geometryObj.value(QLatin1String("points")).toString().toUtf8();
        PolylineDecoder<2> decoder(points.constData());
        decoder.readPolygon(poly);
    }

    const auto stepsArray = obj.value(QLatin1String("steps")).toArray();
    if (!stepsArray.empty()) {
        std::vector<PathSection> pathSections;
        pathSections.reserve(stepsArray.size());
        PathSection prevPathSec;
        int prevPolyIdx = 0;
        bool isFirstSection = true;
        for (const auto &stepsV : stepsArray) {
            const auto stepsObj = stepsV.toObject();
            PathSection pathSec;
            pathSec.setDescription(stepsObj.value(QLatin1String("legStepText")).toString());

            if (!isFirstSection) {
                const QPointF coord(stepsObj.value(QLatin1String("lon")).toDouble(), stepsObj.value(QLatin1String("lat")).toDouble());
                const auto it = std::min_element(poly.begin() + prevPolyIdx, poly.end(), [coord](QPointF lhs, QPointF rhs) {
                    return Location::distance(lhs.y(), lhs.x(), coord.y(), coord.x()) < Location::distance(rhs.y(), rhs.x(), coord.y(), coord.x());
                });
                int polyIdx = std::distance(poly.begin(), it);

                QPolygonF subPoly;
                subPoly.reserve(polyIdx - prevPolyIdx + 1);
                std::copy(poly.begin() + prevPolyIdx, poly.begin() + polyIdx + 1, std::back_inserter(subPoly));
                prevPathSec.setPath(std::move(subPoly));
                prevPolyIdx = polyIdx;
                pathSections.push_back(std::move(prevPathSec));
            } else {
                isFirstSection = false;
            }
            prevPathSec = pathSec;
        }

        QPolygonF subPoly;
        subPoly.reserve(prevPolyIdx - poly.size() + 1);
        std::copy(poly.begin() + prevPolyIdx, poly.end(), std::back_inserter(subPoly));
        prevPathSec.setPath(std::move(subPoly));
        pathSections.push_back(std::move(prevPathSec));

        Path path;
        path.setSections(std::move(pathSections));
        section.setPath(std::move(path));
    } else if (!poly.isEmpty()) {
        PathSection pathSec;
        pathSec.setPath(std::move(poly));
        Path path;
        path.setSections({std::move(pathSec)});
        section.setPath(std::move(path));
    }

    return section;
}

Journey OpenTripPlannerParser::parseJourney(const QJsonObject &obj) const
{
    std::vector<JourneySection> sections;
    const auto sectionsArray = obj.value(QLatin1String("legs")).toArray();
    for (const auto &sectionObj : sectionsArray) {
        sections.push_back(parseJourneySection(sectionObj.toObject()));
    }

    Journey journey;
    journey.setSections(std::move(sections));
    return journey;
}

std::vector<Journey> OpenTripPlannerParser::parseJourneys(const QJsonObject& obj)
{
    std::vector<Journey> journeys;

    const auto plan = obj.value(QLatin1String("plan")).toObject();
    const auto journeysArray = plan.value(QLatin1String("itineraries")).toArray();
    journeys.reserve(journeysArray.size());
    for (const auto &journeyObj : journeysArray) {
        journeys.push_back(parseJourney(journeyObj.toObject()));
    }

    m_nextJourneyContext.dateTime = parseJourneyDateTime(plan.value(QLatin1String("nextDateTime")));
    m_prevJourneyContext.dateTime = parseJourneyDateTime(plan.value(QLatin1String("prevDateTime")));
    m_nextJourneyContext.searchWindow = m_prevJourneyContext.searchWindow = plan.value(QLatin1String("searchWindowUsed")).toInt();

    return journeys;
}

JourneySection OpenTripPlannerParser::parseTrip(const QJsonObject &obj) const
{
    const auto tripObj = obj.value("trip"_L1).toObject();
    JourneySection section;
    section.setMode(JourneySection::PublicTransport);
    section.setIdentifier(m_identifierType, tripObj.value("id"_L1).toString());

    auto routeData = parseRoute(tripObj);
    section.setRoute(routeData.route);
    // TODO bikesAllowed, wheelcharAccessible

    const auto stoptimesA = tripObj.value("stoptimes"_L1).toArray();
    std::vector<Stopover> stops;
    stops.reserve(stoptimesA.size());
    for (const auto &stoptimeV :stoptimesA) {
        const auto stopObj = stoptimeV.toObject();
        auto stop = parseStoptime(stopObj);
        const auto serviceDay = stopObj.value("serviceDay"_L1).toInteger();
        stop.setScheduledDepartureTime(QDateTime::fromSecsSinceEpoch(serviceDay + stopObj.value("scheduledDeparture"_L1).toInteger()));
        stop.setScheduledArrivalTime(QDateTime::fromSecsSinceEpoch(serviceDay + stopObj.value("scheduledArrival"_L1).toInteger()));
        if (stopObj.value("realtime"_L1).toBool()) {
            stop.setExpectedDepartureTime(stop.scheduledDepartureTime().addSecs(stopObj.value("departureDelay"_L1).toInteger()));
            stop.setExpectedArrivalTime(stop.scheduledArrivalTime().addSecs(stopObj.value("arrivalDelay"_L1).toInteger()));
        }

        stops.push_back(std::move(stop));
    }

    // split off departure/arrival
    if (stops.size() >= 2) {
        section.setDeparture(stops.front());
        section.setArrival(stops.back());
        stops.pop_back();
        stops.erase(stops.begin(), std::next(stops.begin()));
    }
    section.setIntermediateStops(std::move(stops));

    const auto geometryObj = tripObj.value("tripGeometry"_L1).toObject();
    if (!geometryObj.empty()) {
        QPolygonF poly;
        poly.reserve(geometryObj.value("length"_L1).toInt());
        const auto points = geometryObj.value("points"_L1).toString().toUtf8();
        PolylineDecoder<2> decoder(points.constData());
        decoder.readPolygon(poly);

        if (!poly.isEmpty()) {
            PathSection pathSec;
            pathSec.setPath(poly);
            Path path;
            path.setSections({std::move(pathSec)});
            section.setPath(path);
        }
    }

    parseAlerts(obj.value("alerts"_L1).toArray());
    section.addNotes(m_alerts);
    m_alerts.clear();

    return section;
}

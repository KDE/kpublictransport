/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "location.h"

#include "datatypes_p.h"
#include "equipment.h"
#include "equipmentutil.h"
#include "json_p.h"
#include "mergeutil_p.h"
#include "rentalvehicle.h"
#include "rentalvehicleutil_p.h"
#include "ifopt/ifoptutil.h"

#include <KTimeZone>
#include <KCountry>
#include <KCountrySubdivision>

#include <QDebug>
#include <QHash>
#include <QJsonArray>
#include <QJsonObject>
#include <QRegularExpression>
#include <QTimeZone>

#include <cmath>

using namespace KPublicTransport;
using namespace Qt::Literals;

namespace KPublicTransport {

class LocationPrivate : public QSharedData
{
public:
    Location::Type type = Location::Place;
    QString name;
    double latitude = NAN;
    double longitude = NAN;
    QTimeZone timeZone;
    QHash<QString, QString> ids;

    QString streetAddress;
    QString postalCode;
    QString locality;
    QString region;
    QString country;

    int floorLevel = std::numeric_limits<int>::lowest();

    QVariant data;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(Location)
KPUBLICTRANSPORT_MAKE_PROPERTY(Location, Location::Type, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(Location, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(Location, double, latitude, setLatitude)
KPUBLICTRANSPORT_MAKE_PROPERTY(Location, double, longitude, setLongitude)
KPUBLICTRANSPORT_MAKE_PROPERTY(Location, QString, streetAddress, setStreetAddress)
KPUBLICTRANSPORT_MAKE_PROPERTY(Location, QString, postalCode, setPostalCode)
KPUBLICTRANSPORT_MAKE_PROPERTY(Location, QString, locality, setLocality)
KPUBLICTRANSPORT_MAKE_PROPERTY(Location, int, floorLevel, setFloorLevel)

void Location::setRegion(const QString &regionCode)
{
    d.detach();
    d->region = regionCode;
}

QString Location::region() const
{
    if (d->region.isEmpty() && hasCoordinate()) {
        auto subdivision = KCountrySubdivision::fromLocation((float)latitude(), (float)longitude());
        const_cast<Location *>(this)->setRegion(subdivision.code());
    }

    return d->region;
}

void Location::setCountry(const QString &countryCode)
{
    d.detach();
    d->country = countryCode;
}

QString Location::country() const
{
    if (d->country.isEmpty() && hasCoordinate()) {
        auto country = KCountry::fromLocation((float)latitude(), (float)longitude());
        const_cast<Location *>(this)->setCountry(country.alpha2());
    }

    return d->country;
}

KPUBLICTRANSPORT_MAKE_PROPERTY(Location, QVariant, data, setData)

void Location::setCoordinate(double latitude, double longitude)
{
    d.detach();
    d->latitude = latitude;
    d->longitude = longitude;
}

bool Location::hasCoordinate() const
{
    return !std::isnan(d->latitude) && !std::isnan(d->longitude) && std::abs(d->latitude) <= 90.0 && std::abs(d->longitude) <= 180.0;
}

bool Location::hasFloorLevel() const
{
    return d->floorLevel > std::numeric_limits<int>::lowest() && d->floorLevel < std::numeric_limits<int>::max();
}

bool Location::isEmpty() const
{
    return !hasCoordinate() && d->name.isEmpty() && d->ids.isEmpty() && d->streetAddress.isEmpty();
}

QTimeZone Location::timeZone() const
{
    if (d->timeZone.isValid()) {
        return d->timeZone;
    }
    if (hasCoordinate()) {
        if (const auto tzId = KTimeZone::fromLocation((float)latitude(), (float)longitude()); tzId) {
            return QTimeZone(tzId);
        }
    }
    return {};
}

void Location::setTimeZone(const QTimeZone &tz)
{
    d.detach();
    d->timeZone = tz;
}

QString Location::identifier(const QString &identifierType) const
{
    return d->ids.value(identifierType);
}

void Location::setIdentifier(const QString &identifierType, const QString &id)
{
    d.detach();
    d->ids.insert(identifierType, id);
}

bool Location::hasIdentifier(const QString &identifierType) const
{
    return !d->ids.value(identifierType).isEmpty();
}

QStringList Location::identifierTypes() const
{
    return d->ids.keys();
}

RentalVehicleStation Location::rentalVehicleStation() const
{
    return d->data.value<RentalVehicleStation>();
}

RentalVehicle Location::rentalVehicle() const
{
    return d->data.value<RentalVehicle>();
}

KPublicTransport::Equipment Location::equipment() const
{
    return d->data.value<KPublicTransport::Equipment>();
}

// keep this sorted by key
struct {
    const char *key;
    const char *value;
} static const name_normalization_map[] = {
    { "bahnhof", nullptr },
    { "bhf", nullptr },
    { "centraal", "central" },
    { "cs", "central" },
    { "de", nullptr },
    { "flughafen", "airport" },
    { "gare", nullptr },
    { "hbf", "hauptbahnhof" },
    { "rer", nullptr },
    { "st", "saint" },
    { "str", "strasse" },
};

static QStringList splitAndNormalizeName(const QString &name)
{
    static const QRegularExpression splitRegExp(uR"([, \(\)-/\.\[\]])"_s);
    auto l = name.split(splitRegExp, Qt::SkipEmptyParts);

    for (auto it = l.begin(); it != l.end();) {
        // ignore single-letter fragments, with the exception of the 'H' used in Denmark
        // this seem to be mostly transport mode abbreviations (such as 'S' and 'U' in Germany)
        if ((*it).size() == 1) {
            it = l.erase(it);
            continue;
        }

        *it = (*it).toCaseFolded();
        const auto b = (*it).toUtf8();
        const auto entry = std::lower_bound(std::begin(name_normalization_map), std::end(name_normalization_map), b.constData(), [](const auto &lhs, const auto rhs) {
            return strcmp(lhs.key, rhs) < 0;
        });
        if (entry != std::end(name_normalization_map) && strcmp((*entry).key, b.constData()) == 0) {
            if (!(*entry).value) {
                it = l.erase(it);
                continue;
            }
            *it = QString::fromUtf8((*entry).value);
        }
        ++it;
    }

    l.removeDuplicates();
    std::sort(l.begin(), l.end());
    return l;
}

static QString stripDiacritics(const QString &s)
{
    QString res;
    res.reserve(s.size());

    // if the character has a canonical decomposition use that and skip the combining diacritic markers following it
    // see https://en.wikipedia.org/wiki/Unicode_equivalence
    // see https://en.wikipedia.org/wiki/Combining_character
    for (const auto &c : s) {
        if (c.decompositionTag() == QChar::Canonical) {
            res.push_back(c.decomposition().at(0));
        } else {
            res.push_back(c);
        }
    }

    return res;
}

// keep this ordered (see https://en.wikipedia.org/wiki/List_of_Unicode_characters)
struct {
    ushort key;
    const char* replacement;
} static const transliteration_map[] = {
    { 0x00DF, "ss" }, // ß
    { 0x00E4, "ae" }, // ä
    { 0x00F6, "oe" }, // ö
    { 0x00F8, "oe" }, // ø
    { 0x00FC, "ue" }, // ü
};

static QString applyTransliterations(const QString &s)
{
    QString res;
    res.reserve(s.size());

    for (const auto c : s) {
        const auto it = std::lower_bound(std::begin(transliteration_map), std::end(transliteration_map), c, [](const auto &lhs, const auto rhs) {
            return QChar(lhs.key) < rhs;
        });
        if (it != std::end(transliteration_map) && QChar((*it).key) == c) {
            res += QString::fromUtf8((*it).replacement);
            continue;
        }

        if (c.decompositionTag() == QChar::Canonical) { // see above
            res += c.decomposition().at(0);
        } else {
            res += c;
        }
    }

    return res;
}

static bool isCompatibleLocationType(Location::Type lhs, Location::Type rhs)
{
    return lhs == rhs
        || (lhs == Location::Place && rhs == Location::Stop)
        || (rhs == Location::Place && lhs == Location::Stop);
}

static int isSameDistanceThreshold(Location::Type type)
{
    switch (type) {
        case Location::Place:
        case Location::Stop:
        case Location::Address:
            return 25; // meter
        case Location::CarpoolPickupDropoff:
            return 10;
        case Location::RentedVehicleStation:
            return 5;
        case Location::Equipment:
        case Location::RentedVehicle:
            return 3;
    }
    Q_UNREACHABLE();
}

bool Location::isSame(const Location &lhs, const Location &rhs)
{
    const auto dist = Location::distance(lhs.latitude(), lhs.longitude(), rhs.latitude(), rhs.longitude());
    // further than 1km apart is certainly not the same
    if (lhs.hasCoordinate() && rhs.hasCoordinate() && dist > 1000) {
        return false;
    }
    // incompatible types are also unmergable
    if (!isCompatibleLocationType(lhs.type(), rhs.type())) {
        return false;
    }

    // ids - IFOPT takes priority here due to its special hierarchical handling, but only for stations
    const auto lhsIfopt = lhs.identifier(IfoptUtil::identifierType());
    const auto rhsIfopt = rhs.identifier(IfoptUtil::identifierType());
    if (!lhsIfopt.isEmpty() && !rhsIfopt.isEmpty() && (lhs.type() == Location::Stop || rhs.type() == Location::Stop)) {
        return IfoptUtil::isSameStopPlace(lhsIfopt, rhsIfopt);
    }

    const auto lhsIds = lhs.d->ids;
    bool foundEqualId = false;
    for (auto it = lhsIds.constBegin(); it != lhsIds.constEnd(); ++it) {
        const auto rhsId = rhs.identifier(it.key());
        if (it.value().isEmpty() || rhsId.isEmpty()) {
            continue;
        }
        if (it.value() != rhsId) {
            return false;
        } else if (it.value() == rhsId) {
            foundEqualId = true;
        }
    }
    if (foundEqualId) {
        return true;
    }

    if (lhs.rentalVehicleStation().isValid() && rhs.rentalVehicleStation().isValid()
        && !RentalVehicleStation::isSame(lhs.rentalVehicleStation(), rhs.rentalVehicleStation())) {
        return false;
    }
    if (lhs.type() == Location::Equipment && lhs.equipment().type() != rhs.equipment().type()) {
        return false;
    }

    // name
    if (isSameName(lhs.name(), rhs.name())) {
        return true;
    }

    // TODO consider the address properties here?

    // anything sufficiently close together is assumed to be the same
    if (lhs.hasCoordinate() && rhs.hasCoordinate() && dist < std::min(isSameDistanceThreshold(lhs.type()), isSameDistanceThreshold(rhs.type()))) {
        return true;
    }

    return false;
}

bool Location::isSameName(const QString &lhs, const QString &rhs)
{
    // simple prefix test, before we do the expensive fragment-based comparison below
    if (lhs.startsWith(rhs, Qt::CaseInsensitive) || rhs.startsWith(lhs, Qt::CaseSensitive)) {
        return true;
    }

    const auto lhsNameFragments = splitAndNormalizeName(lhs);
    const auto rhsNameFragments = splitAndNormalizeName(rhs);

    // first try with stripping diacritics
    std::vector<QString> lhsNormalized;
    lhsNormalized.reserve(lhsNameFragments.size());
    std::transform(lhsNameFragments.begin(), lhsNameFragments.end(), std::back_inserter(lhsNormalized), stripDiacritics);
    std::sort(lhsNormalized.begin(), lhsNormalized.end());
    lhsNormalized.erase(std::unique(lhsNormalized.begin(), lhsNormalized.end()), lhsNormalized.end());

    std::vector<QString> rhsNormalized;
    rhsNormalized.reserve(rhsNameFragments.size());
    std::transform(rhsNameFragments.begin(), rhsNameFragments.end(), std::back_inserter(rhsNormalized), stripDiacritics);
    std::sort(rhsNormalized.begin(), rhsNormalized.end());
    rhsNormalized.erase(std::unique(rhsNormalized.begin(), rhsNormalized.end()), rhsNormalized.end());

    if (lhsNormalized == rhsNormalized) {
        return true;
    }

    // if that didn't help, try to apply alternative transliterations of diacritics
    lhsNormalized.clear();
    std::transform(lhsNameFragments.begin(), lhsNameFragments.end(), std::back_inserter(lhsNormalized), applyTransliterations);
    rhsNormalized.clear();
    std::transform(rhsNameFragments.begin(), rhsNameFragments.end(), std::back_inserter(rhsNormalized), applyTransliterations);
    return lhsNormalized == rhsNormalized;
}

static double mergeCoordinate(double lhs, double rhs)
{
    if (std::isnan(lhs)) {
        return rhs;
    }
    if (std::isnan(rhs)) {
        return lhs;
    }

    return (lhs + rhs) / 2.0;
}

Location Location::merge(const Location &lhs, const Location &rhs)
{
    Location l(lhs);
    l.setType(std::max(lhs.type(), rhs.type()));

    // merge identifiers
    const auto rhsIds = rhs.d->ids;
    for (auto it = rhsIds.constBegin(); it != rhsIds.constEnd(); ++it) {
        if (it.key() == IfoptUtil::identifierType()) {
            l.setIdentifier(IfoptUtil::identifierType(), IfoptUtil::merge(l.identifier(IfoptUtil::identifierType()), it.value()).toString());
            continue;
        }
        if (lhs.identifier(it.key()).isEmpty()) {
            l.setIdentifier(it.key(), it.value());
        }
    }

    if (!lhs.hasCoordinate()) {
        l.setCoordinate(rhs.latitude(), rhs.longitude());
    }

    l.setName(MergeUtil::mergeString(lhs.name(), rhs.name()));

    if (!lhs.d->timeZone.isValid()) {
        l.setTimeZone(rhs.d->timeZone);
    }

    l.setLatitude(mergeCoordinate(lhs.latitude(), rhs.latitude()));
    l.setLongitude(mergeCoordinate(lhs.longitude(), rhs.longitude()));

    l.setStreetAddress(MergeUtil::mergeString(lhs.streetAddress(), rhs.streetAddress()));
    l.setPostalCode(MergeUtil::mergeString(lhs.postalCode(), rhs.postalCode()));
    l.setLocality(MergeUtil::mergeString(lhs.locality(), rhs.locality()));
    l.setRegion(MergeUtil::mergeString(lhs.region(), rhs.region()));
    l.setCountry(MergeUtil::mergeString(lhs.country(), rhs.country()));

    switch (l.type()) {
        case Place:
        case CarpoolPickupDropoff:
        case Stop:
        case Address:
            break;
        case RentedVehicleStation:
            l.setData(RentalVehicleUtil::merge(lhs.rentalVehicleStation(), rhs.rentalVehicleStation()));
            break;
        case RentedVehicle:
            l.setData(RentalVehicleUtil::merge(lhs.rentalVehicle(), rhs.rentalVehicle()));
            break;
        case Equipment:
            l.setData(EquipmentUtil::merge(lhs.equipment(), rhs.equipment()));
            break;
    }

    return l;
}

// see https://en.wikipedia.org/wiki/Haversine_formula
double Location::distance(double lat1, double lon1, double lat2, double lon2)
{
    const auto degToRad = M_PI / 180.0;
    const auto earthRadius = 6371000.0; // in meters

    const auto d_lat = (lat1 - lat2) * degToRad;
    const auto d_lon = (lon1 - lon2) * degToRad;

    const auto a = pow(sin(d_lat / 2.0), 2) + cos(lat1 * degToRad) * cos(lat2 * degToRad) * pow(sin(d_lon / 2.0), 2);
    return 2.0 * earthRadius * atan2(sqrt(a), sqrt(1.0 - a));
}

double Location::distance(const Location &lhs, const Location &rhs)
{
    if (!lhs.hasCoordinate() || !rhs.hasCoordinate()) {
        return NAN;
    }
    return Location::distance(lhs.latitude(), lhs.longitude(), rhs.latitude(), rhs.longitude());
}

QJsonObject Location::toJson(const Location &loc)
{
    auto obj = Json::toJson(loc);
    if (loc.d->timeZone.isValid()) {
        obj.insert("timezone"_L1, QString::fromUtf8(loc.d->timeZone.id()));
    }
    if (!loc.hasFloorLevel()) {
        obj.remove("floorLevel"_L1);
    }

    if (!loc.d->ids.isEmpty()) {
        QJsonObject ids;
        for (auto it = loc.d->ids.constBegin(); it != loc.d->ids.constEnd(); ++it) {
            ids.insert(it.key(), it.value());
        }
        obj.insert("identifier"_L1, ids);
    }

    switch (loc.type()) {
        case Place:
            obj.remove("type"_L1);
            [[fallthrough]];
        case Address:
        case Stop:
        case CarpoolPickupDropoff:
            break;
        case RentedVehicleStation:
            obj.insert("rentalVehicleStation"_L1, RentalVehicleStation::toJson(loc.rentalVehicleStation()));
            break;
        case RentedVehicle:
            obj.insert("rentalVehicle"_L1, RentalVehicle::toJson(loc.rentalVehicle()));
            break;
        case Equipment:
            obj.insert("equipment"_L1, Equipment::toJson(loc.equipment()));
            break;
    }

    return obj;
}

QJsonArray Location::toJson(const std::vector<Location> &locs)
{
    return Json::toJson(locs);
}

QString Location::iconName() const
{
    switch (d->type) {
        case Location::Stop:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-stop.svg"_s;
        case Location::RentedVehicleStation:
            return rentalVehicleStation().iconName();
        case Location::RentedVehicle:
            return rentalVehicle().vehicleTypeIconName();
        case Location::Equipment:
            return equipment().iconName();
        case Location::CarpoolPickupDropoff:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-car.svg"_s;
        case Location::Address:
        case Location::Place:
            break;
    }
    return u"map-symbolic"_s;
}

Location Location::fromJson(const QJsonObject &obj)
{
    auto loc = Json::fromJson<Location>(obj);
    const auto tz = obj.value("timezone"_L1).toString();
    if (!tz.isEmpty()) {
        loc.setTimeZone(QTimeZone(tz.toUtf8()));
    }

    const auto ids = obj.value("identifier"_L1).toObject();
    for (auto it = ids.begin(); it != ids.end(); ++it) {
        loc.setIdentifier(it.key(), it.value().toString());
    }

    switch (loc.type()) {
        case Place:
        case Address:
        case Stop:
        case CarpoolPickupDropoff:
            break;
        case RentedVehicleStation:
            loc.setData(RentalVehicleStation::fromJson(obj.value("rentalVehicleStation"_L1).toObject()));
            break;
        case RentedVehicle:
            loc.setData(RentalVehicle::fromJson(obj.value("rentalVehicle"_L1).toObject()));
            break;
        case Equipment:
            loc.setData(Equipment::fromJson(obj.value("equipment"_L1).toObject()));
            break;
    }

    return loc;
}

std::vector<Location> Location::fromJson(const QJsonArray &a)
{
    return Json::fromJson<Location>(a);
}

#include "moc_location.cpp"

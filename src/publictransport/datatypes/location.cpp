/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "location.h"

#include "datatypes_p.h"
#include "json.h"

#include <QDebug>
#include <QHash>
#include <QJsonArray>
#include <QJsonObject>
#include <QRegularExpression>
#include <QTimeZone>

#include <cmath>

using namespace KPublicTransport;

namespace KPublicTransport {

class LocationPrivate : public QSharedData
{
public:
    QString name;
    float latitude = NAN;
    float longitude = NAN;
    QTimeZone timeZone;
    QHash<QString, QString> ids;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(Location)

QString Location::name() const
{
    return d->name;
}

void Location::setName(const QString &name)
{
    d.detach();
    d->name = name;
}

float Location::latitude() const
{
    return d->latitude;
}

void Location::setLatitude(float latitude)
{
    d.detach();
    d->latitude = latitude;
}

float Location::longitude() const
{
    return d->longitude;
}

void Location::setLongitude(float longitude)
{
    d.detach();
    d->longitude = longitude;
}

void Location::setCoordinate(float latitude, float longitude)
{
    d.detach();
    d->latitude = latitude;
    d->longitude = longitude;
}

bool Location::hasCoordinate() const
{
    return !std::isnan(d->latitude) && !std::isnan(d->longitude);
}

QTimeZone Location::timeZone() const
{
    return d->timeZone;
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

QHash<QString, QString> Location::identifiers() const
{
    return d->ids;
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
    { "s", nullptr },
    { "st", "saint" },
    { "u", nullptr }
};

static QStringList splitAndNormalizeName(const QString &name)
{
    static const QRegularExpression splitRegExp(QStringLiteral(R"([, \(\)-/\.\[\]])"));
    auto l = name.split(splitRegExp, QString::SkipEmptyParts);

    for (auto it = l.begin(); it != l.end();) {
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

bool Location::isSame(const Location &lhs, const Location &rhs)
{
    // ids
    for (auto it = lhs.identifiers().constBegin(); it != lhs.identifiers().constEnd(); ++it) {
        if (rhs.identifier(it.key()) == it.value() && !it.value().isEmpty()) {
            return true;
        }
    }

    // name
    const auto lhsNameFragments = splitAndNormalizeName(lhs.name());
    const auto rhsNameFragments = splitAndNormalizeName(rhs.name());
    if (lhsNameFragments == rhsNameFragments) {
        return true;
    }

    // coordinates: anything less than 10m apart is assumed to be the same
    if (lhs.hasCoordinate() && rhs.hasCoordinate() && distance(lhs.latitude(), lhs.longitude(), rhs.latitude(), rhs.longitude()) < 10) {
        return true;
    }

    return false;
}

Location Location::merge(const Location &lhs, const Location &rhs)
{
    Location l(lhs);

    // merge identifiers
    for (auto it = rhs.identifiers().constBegin(); it != rhs.identifiers().constEnd(); ++it) {
        if (lhs.identifier(it.key()).isEmpty()) {
            l.setIdentifier(it.key(), it.value());
        }
    }

    return lhs;
}

// see https://en.wikipedia.org/wiki/Haversine_formula
int Location::distance(float lat1, float lon1, float lat2, float lon2)
{
    const auto degToRad = M_PI / 180.0;
    const auto earthRadius = 6371000.0; // in meters

    const auto d_lat = (lat1 - lat2) * degToRad;
    const auto d_lon = (lon1 - lon2) * degToRad;

    const auto a = pow(sin(d_lat / 2.0), 2) + cos(lat1 * degToRad) * cos(lat2 * degToRad) * pow(sin(d_lon / 2.0), 2);
    return 2.0 * earthRadius * atan2(sqrt(a), sqrt(1.0 - a));
}

QJsonObject Location::toJson(const Location &loc)
{
    auto obj = Json::toJson(loc);
    if (loc.timeZone().isValid()) {
        obj.insert(QLatin1String("timezone"), QString::fromUtf8(loc.timeZone().id()));
    }

    QJsonObject ids;
    for (auto it = loc.d->ids.begin(); it != loc.d->ids.end(); ++it) {
        ids.insert(it.key(), it.value());
    }
    obj.insert(QLatin1String("identifier"), ids);

    return obj;
}

QJsonArray Location::toJson(const std::vector<Location> &locs)
{
    return Json::toJson(locs);
}

Location Location::fromJson(const QJsonObject &obj)
{
    auto loc = Json::fromJson<Location>(obj);
    const auto tz = obj.value(QLatin1String("timezone")).toString();
    if (!tz.isEmpty()) {
        loc.setTimeZone(QTimeZone(tz.toUtf8()));
    }

    const auto ids = obj.value(QLatin1String("identifier")).toObject();
    for (auto it = ids.begin(); it != ids.end(); ++it) {
        loc.setIdentifier(it.key(), it.value().toString());
    }

    return loc;
}

std::vector<Location> Location::fromJson(const QJsonArray &a)
{
    return Json::fromJson<Location>(a);
}

#include "moc_location.cpp"

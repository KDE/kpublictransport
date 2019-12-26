/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#include "vehicle.h"
#include "json_p.h"
#include "datatypes_p.h"

#include <QDebug>
#include <QMetaEnum>
#include <QVariant>

#include <limits>

using namespace KPublicTransport;

namespace KPublicTransport {

class VehicleSectionPrivate : public QSharedData
{
public:
    QString name;
    float platformPositionBegin = -1.0;
    float platformPositionEnd = -1.0;
    VehicleSection::Type type = VehicleSection::UnknownType;
    VehicleSection::Classes classes = VehicleSection::UnknownClass;
    VehicleSection::Features features = VehicleSection::NoFeatures;
};

class VehiclePrivate : public QSharedData
{
public:
    QString name;
    std::vector<VehicleSection> sections;
    Vehicle::Direction direction = Vehicle::UnknownDirection;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(VehicleSection)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, float, platformPositionBegin, setPlatformPositionBegin)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, float, platformPositionEnd, setPlatformPositionEnd)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, VehicleSection::Type, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, VehicleSection::Classes, classes, setClasses)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, VehicleSection::Features, features, setFeatures)

QJsonObject VehicleSection::toJson(const VehicleSection &section)
{
    return Json::toJson(section);
}

QJsonArray VehicleSection::toJson(const std::vector<VehicleSection> &sections)
{
    return Json::toJson(sections);
}

VehicleSection VehicleSection::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<VehicleSection>(obj);
}

std::vector<VehicleSection> VehicleSection::fromJson(const QJsonArray &array)
{
    return Json::fromJson<VehicleSection>(array);
}

QVariantList VehicleSection::featureList() const
{
    QVariantList l;
    const auto me = QMetaEnum::fromType<VehicleSection::Features>();
    for (int i = 0; i < me.keyCount(); ++i) {
        if (features() & static_cast<VehicleSection::Feature>(1 << i))
            l.push_back(static_cast<VehicleSection::Feature>(1 << i));
    }
    return l;
}

KPUBLICTRANSPORT_MAKE_GADGET(Vehicle)
KPUBLICTRANSPORT_MAKE_PROPERTY(Vehicle, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(Vehicle, Vehicle::Direction, direction, setDirection)

const std::vector<VehicleSection>& Vehicle::sections() const
{
    return d->sections;
}

std::vector<VehicleSection>&& Vehicle::takeSections()
{
    return std::move(d->sections);
}

void Vehicle::setSections(std::vector<VehicleSection> &&sections)
{
    d.detach();
    d->sections = std::move(sections);
}

QVariantList Vehicle::sectionsVariant() const
{
    QVariantList l;
    l.reserve(d->sections.size());
    std::transform(d->sections.begin(), d->sections.end(), std::back_inserter(l), [](const auto &sec) { return QVariant::fromValue(sec); });
    return l;
}

float Vehicle::platformPositionBegin() const
{
    float p = std::numeric_limits<float>::max();
    for (const auto &section : sections()) {
        p = std::min(p, section.platformPositionBegin());
    }
    return p;
}

float Vehicle::platformPositionEnd() const
{
    float p = -1.0f;
    for (const auto &section : sections()) {
        p = std::max(p, section.platformPositionEnd());
    }
    return p;
}

QJsonObject Vehicle::toJson(const Vehicle &vehicle)
{
    auto obj = Json::toJson(vehicle);
    if (!vehicle.sections().empty()) {
        obj.insert(QStringLiteral("sections"), VehicleSection::toJson(vehicle.sections()));
    }
    return obj;
}

Vehicle Vehicle::fromJson(const QJsonObject &obj)
{
    auto v = Json::fromJson<Vehicle>(obj);
    v.setSections(VehicleSection::fromJson(obj.value(QLatin1String("sections")).toArray()));
    return v;
}

#include "moc_vehicle.cpp"

/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "vehicle.h"
#include "json_p.h"
#include "datatypes_p.h"
#include "mergeutil_p.h"

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
    int deckCount = 1;
    VehicleSection::Sides connectedSides = VehicleSection::Front | VehicleSection::Back;
    QString platformSectionName;
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
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, int, deckCount, setDeckCount)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, VehicleSection::Sides, connectedSides, setConnectedSides)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, QString, platformSectionName, setPlatformSectionName)

VehicleSection VehicleSection::merge(const VehicleSection &lhs, const VehicleSection &rhs)
{
    if (lhs.name() != rhs.name()) { // safety check, as we don't properly check for equalness before merging yet
        return lhs;
    }

    auto res = lhs;
    res.setPlatformPositionBegin(lhs.platformPositionBegin() < 0.0 ? rhs.platformPositionBegin() : lhs.platformPositionBegin());
    res.setPlatformPositionEnd(lhs.platformPositionEnd() < 0.0 ? rhs.platformPositionEnd() : lhs.platformPositionEnd());
    res.setType(std::max(lhs.type(), rhs.type()));
    if (res.type() == VehicleSection::PassengerCar && lhs.type() != VehicleSection::UnknownType && rhs.type() != VehicleSection::UnknownType) {
        res.setType(std::min(lhs.type(), rhs.type()));
    }
    res.setClasses(lhs.classes() | rhs.classes());
    res.setFeatures(lhs.features() | rhs.features());
    res.setDeckCount(std::max(lhs.deckCount(), rhs.deckCount()));
    res.setConnectedSides(lhs.connectedSides() & rhs.connectedSides());
    return res;
}

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

bool Vehicle::isEmpty() const
{
    return d->name.isEmpty() && d->sections.empty() && d->direction == Vehicle::UnknownDirection;
}

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

void Vehicle::setSections(const std::vector<VehicleSection> &sections)
{
    d.detach();
    d->sections = sections;
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

float Vehicle::platformPositionForSection(const QString &sectionName) const
{
    for (const auto &section : sections()) {
        if (section.name() == sectionName) {
            return (section.platformPositionBegin() + section.platformPositionEnd()) / 2.0f;
        }
    }
    return -1.0f;
}

Vehicle Vehicle::merge(const Vehicle &lhs, const Vehicle &rhs)
{
    Vehicle res;
    res.setDirection(lhs.direction() == Vehicle::UnknownDirection ? rhs.direction() : lhs.direction());
    res.setName(MergeUtil::mergeString(lhs.name(), rhs.name()));

    if (lhs.sections().size() == rhs.sections().size()) {
        std::vector<VehicleSection> secs;
        secs.reserve(lhs.sections().size());
        for (std::size_t i = 0; i < lhs.sections().size(); ++i) {
            const auto &lhsSec = lhs.sections()[i];
            const auto &rhsSec = rhs.sections()[i];
            secs.push_back(VehicleSection::merge(lhsSec, rhsSec));
        }
        res.setSections(std::move(secs));
    } else {
        res.setSections(lhs.sections().size() < rhs.sections().size() ? rhs.sections() : lhs.sections());
    }

    return res;
}

QJsonObject Vehicle::toJson(const Vehicle &vehicle)
{
    auto obj = Json::toJson(vehicle);
    if (!vehicle.sections().empty()) {
        obj.insert(QStringLiteral("sections"), VehicleSection::toJson(vehicle.sections()));
    }
    return obj;
}

QJsonArray Vehicle::toJson(const std::vector<Vehicle> &vehicles)
{
    return Json::toJson(vehicles);
}

Vehicle Vehicle::fromJson(const QJsonObject &obj)
{
    auto v = Json::fromJson<Vehicle>(obj);
    v.setSections(VehicleSection::fromJson(obj.value(QLatin1String("sections")).toArray()));
    return v;
}

std::vector<Vehicle> Vehicle::fromJson(const QJsonArray &array)
{
    return Json::fromJson<Vehicle>(array);
}

#include "moc_vehicle.cpp"

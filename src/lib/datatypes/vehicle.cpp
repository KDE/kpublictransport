/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "vehicle.h"
#include "json_p.h"
#include "datatypes_p.h"
#include "featureutil_p.h"
#include "mergeutil_p.h"

#include <QDebug>
#include <QMetaEnum>
#include <QVariant>

#include <limits>

using namespace Qt::Literals::StringLiterals;
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
    int deckCount = 1;
    VehicleSection::Sides connectedSides = VehicleSection::Front | VehicleSection::Back;
    QString platformSectionName;
    std::vector<Feature> sectionFeatures;
    Disruption::Effect disruptionEffect = Disruption::NormalService;
    Load::Category load = Load::Unknown;
};

class VehiclePrivate : public QSharedData
{
public:
    QString name;
    std::vector<VehicleSection> sections;
    Vehicle::Direction direction = Vehicle::UnknownDirection;
    std::vector<Feature> features;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(VehicleSection)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, float, platformPositionBegin, setPlatformPositionBegin)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, float, platformPositionEnd, setPlatformPositionEnd)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, VehicleSection::Type, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, VehicleSection::Classes, classes, setClasses)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, int, deckCount, setDeckCount)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, VehicleSection::Sides, connectedSides, setConnectedSides)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, QString, platformSectionName, setPlatformSectionName)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, KPublicTransport::Disruption::Effect, disruptionEffect, setDisruptionEffect)
KPUBLICTRANSPORT_MAKE_PROPERTY(VehicleSection, KPublicTransport::Load::Category, load, setLoad)

const std::vector<KPublicTransport::Feature>& VehicleSection::sectionFeatures() const
{
    return d->sectionFeatures;
}

std::vector<KPublicTransport::Feature>&& VehicleSection::takeSectionFeatures()
{
    return std::move(d->sectionFeatures);
}

void VehicleSection::setSectionFeatures(std::vector<KPublicTransport::Feature> &&features)
{
    d.detach();
    FeatureUtil::set(d->sectionFeatures, std::move(features));
}

KPublicTransport::Feature VehicleSection::feature(KPublicTransport::Feature::Type type) const
{
    return FeatureUtil::findByType(d->sectionFeatures, type);
}

QString VehicleSection::vehicleTypeIconName(VehicleSection::Type type)
{
    switch (type) {
        case VehicleSection::UnknownType:
        case VehicleSection::Engine:
        case VehicleSection::PowerCar:
            break;
        case VehicleSection::PassengerCar:
        case VehicleSection::ControlCar:
            return u"qrc:///org.kde.kpublictransport/assets/images/train-coach-passenger.svg"_s;
        case VehicleSection::SleepingCar:
            return u"qrc:///org.kde.kpublictransport/assets/images/train-coach-sleeping.svg"_s;
        case VehicleSection::CouchetteCar:
            return u"qrc:///org.kde.kpublictransport/assets/images/train-coach-couchette.svg"_s;
        case VehicleSection::RestaurantCar:
            return u"qrc:///org.kde.kpublictransport/assets/images/train-coach-restaurant.svg"_s;
        case VehicleSection::CarTransportCar:
            return u"qrc:///org.kde.kpublictransport/assets/images/train-coach-cartransport.svg"_s;
    }
    return {};
}

QString VehicleSection::iconName() const
{
    return vehicleTypeIconName(type());
}

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
    res.setDeckCount(std::max(lhs.deckCount(), rhs.deckCount()));
    res.setConnectedSides(lhs.connectedSides() & rhs.connectedSides());
    res.setPlatformSectionName(MergeUtil::mergeString(lhs.platformSectionName(), rhs.platformSectionName()));
    res.setSectionFeatures(FeatureUtil::merge(lhs.sectionFeatures(), rhs.sectionFeatures()));
    return res;
}

QJsonObject VehicleSection::toJson(const VehicleSection &section)
{
    auto obj = Json::toJson(section);
    if (!section.d->sectionFeatures.empty()) {
        obj.insert("features"_L1, KPublicTransport::Feature::toJson(section.d->sectionFeatures));
    }
    if (section.disruptionEffect() == Disruption::NormalService) {
        obj.remove("disruptionEffect"_L1);
    }
    if (section.load() == Load::Unknown) {
        obj.remove("load"_L1);
    }
    return obj;
}

QJsonArray VehicleSection::toJson(const std::vector<VehicleSection> &sections)
{
    return Json::toJson(sections);
}

VehicleSection VehicleSection::fromJson(const QJsonObject &obj)
{
    auto v = Json::fromJson<VehicleSection>(obj);
    const auto fVal = obj.value("features"_L1);
    if (fVal.isArray()) {
        v.setSectionFeatures(KPublicTransport::Feature::fromJson(fVal.toArray()));
    }
    return v;
}

std::vector<VehicleSection> VehicleSection::fromJson(const QJsonArray &array)
{
    return Json::fromJson<VehicleSection>(array);
}

bool VehicleSection::hasPlatformPosition() const
{
    return d->platformPositionBegin >= 0.0 && d->platformPositionEnd >= 0.0;
}

KPUBLICTRANSPORT_MAKE_GADGET(Vehicle)
KPUBLICTRANSPORT_MAKE_PROPERTY(Vehicle, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(Vehicle, Vehicle::Direction, direction, setDirection)

bool Vehicle::isEmpty() const
{
    return d->name.isEmpty() && d->sections.empty() && d->direction == Vehicle::UnknownDirection && d->features.empty();
}

const std::vector<VehicleSection>& Vehicle::sections() const
{
    return d->sections;
}

std::vector<VehicleSection>&& Vehicle::takeSections()
{
    d.detach();
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

    res.setFeatures(FeatureUtil::merge(lhs.features(), rhs.features()));

    return res;
}

QJsonObject Vehicle::toJson(const Vehicle &vehicle)
{
    auto obj = Json::toJson(vehicle);
    if (!vehicle.sections().empty()) {
        obj.insert("sections"_L1, VehicleSection::toJson(vehicle.sections()));
    }
    if (!vehicle.features().empty()) {
        obj.insert("features"_L1, Feature::toJson(vehicle.features()));
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
    v.setSections(VehicleSection::fromJson(obj.value("sections"_L1).toArray()));
    v.setFeatures(Feature::fromJson(obj.value("features"_L1).toArray()));
    return v;
}

std::vector<Vehicle> Vehicle::fromJson(const QJsonArray &array)
{
    return Json::fromJson<Vehicle>(array);
}

bool Vehicle::hasPlatformPositions() const
{
    return std::all_of(d->sections.begin(), d->sections.end(), [](const auto &p) { return p.hasPlatformPosition(); });
}

bool Vehicle::hasPlatformSectionNames() const
{
    return std::none_of(d->sections.begin(), d->sections.end(), [](const auto &p) { return p.platformSectionName().isEmpty(); });
}

const std::vector<KPublicTransport::Feature>& Vehicle::features() const
{
    return d->features;
}

[[nodiscard]] std::vector<KPublicTransport::Feature>&& Vehicle::takeFeatures()
{
    return std::move(d->features);
}

void Vehicle::setFeatures(std::vector<KPublicTransport::Feature> &&features)
{
    d.detach();
    d->features = std::move(features);
}

std::vector<KPublicTransport::Feature> Vehicle::combinedFeatures() const
{
    std::vector<KPublicTransport::Feature> features(d->features);
    for (const auto &section : d->sections) {
        for (const auto &feature : section.sectionFeatures()) {
            FeatureUtil::aggregate(features, feature);
        }
    }
    return features;
}

#include "moc_vehicle.cpp"

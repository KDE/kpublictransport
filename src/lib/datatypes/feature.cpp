/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "feature.h"
#include "datatypes_p.h"
#include "json_p.h"
#include "mergeutil_p.h"

#include <KLocalizedString>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

namespace KPublicTransport {
class FeaturePrivate : public QSharedData {
public:
    QString name;
    QString description;
    Feature::Type type = Feature::NoFeature;
    Feature::Availability availability = Feature::Unknown;
    Disruption::Effect disruptionEffect = Disruption::NormalService;
    int quantity = 0;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(Feature)
KPUBLICTRANSPORT_MAKE_PROPERTY(Feature, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(Feature, QString, description, setDescription)
KPUBLICTRANSPORT_MAKE_PROPERTY(Feature, Feature::Type, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(Feature, Feature::Availability, availability, setAvailability)
KPUBLICTRANSPORT_MAKE_PROPERTY(Feature, Disruption::Effect, disruptionEffect, setDisruptionEffect)
KPUBLICTRANSPORT_MAKE_PROPERTY(Feature, int, quantity, setQuantity)

Feature::Feature(Type type, Availability availability)
    : Feature()
{
    d->type = type;
    d->availability = availability;
}

QString Feature::displayName() const
{
    return d->name.isEmpty() ? Feature::typeDisplayName(d->type) : d->name;
}

QString Feature::typeDisplayName(Feature::Type type)
{
    switch (type) {
        case Feature::AirConditioning:
            return i18nc("train coach feature", "Air conditioning");
        case Feature::Restaurant:
            return i18nc("train coach feature", "Bistro or restaurant");
        case Feature::ToddlerArea:
            return i18nc("train coach feature", "Toddler area");
        case Feature::FamilyArea:
            return i18nc("train coach feature", "Family area");
        case Feature::WheelchairAccessible:
            return i18nc("train coach feature", "Wheelchair accessible");
        case Feature::SilentArea:
            return i18nc("train coach feature", "Quiet area");
        case Feature::BusinessArea:
            return i18nc("train coach feature", "Business area");
        case Feature::BikeStorage:
            return i18nc("train coach feature", "Bike storage");
        case Feature::Toilet:
            return i18nc("train coach feature", "Toilet");
        case Feature::WheelchairAccessibleToilet:
            return i18nc("train coach feature", "Wheelchair accessible toilet");
        case Feature::InformationPoint:
            return i18nc("train coach feature", "Information point");
        case Feature::WiFi:
            return i18nc("train coach feature", "Wi-Fi");
        case Feature::PowerSockets:
            return i18nc("train coach feature", "Power sockets");
        case Feature::SleeperCompartment:
            return i18nc("train coach feature", "Sleeper Compartment");
        case Feature::Other:
        case Feature::NoFeature:
            break;
    }

    return {};
}

QString Feature::typeIconName() const
{
    return Feature::typeIconName(d->type);
}

QString Feature::typeIconName(Feature::Type type)
{
    switch (type) {
        case Feature::NoFeature:
            return {};
        case Feature::AirConditioning:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-airconditioning.svg"_s;
        case Feature::Restaurant:
            return u"qrc:///org.kde.kpublictransport/assets/images/train-coach-restaurant.svg"_s;
        case Feature::ToddlerArea:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-toddlerarea.svg"_s;
        case Feature::FamilyArea:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-family.svg"_s;
        case Feature::WheelchairAccessible:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-wheelchair-accessible.svg"_s;
        case Feature::SilentArea:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-silentarea.svg"_s;
        case Feature::BusinessArea:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-businessarea.svg"_s;
        case Feature::BikeStorage:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-bike.svg"_s;
        case Feature::Toilet:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-toilet.svg"_s;
        case Feature::WheelchairAccessibleToilet:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-wheelchair-toilet.svg"_s;
        case Feature::InformationPoint:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-information.svg"_s;
        case Feature::WiFi:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-wifi.svg"_s;
        case Feature::PowerSockets:
            return u"qrc:///org.kde.kpublictransport/assets/images/vehicle-feature-powersocket.svg"_s;
        case Feature::SleeperCompartment:
            return u"qrc:///org.kde.kpublictransport/assets/images/train-coach-sleeping.svg"_s;
        case Feature::Other:
            break;
    }

    return u"documentinfo"_s;
}

QJsonObject Feature::toJson(const Feature &feature)
{
    auto obj = Json::toJson(feature);
    if (!feature.d->quantity) {
        obj.remove("quantity"_L1);
    }
    return obj;
}

QJsonArray Feature::toJson(const std::vector<Feature> &features)
{
    return Json::toJson(features);
}

Feature Feature::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<Feature>(obj);
}

std::vector<Feature> Feature::fromJson(const QJsonArray &array)
{
    return Json::fromJson<Feature>(array);
}

bool Feature::isSame(const Feature &lhs, const Feature &rhs)
{
    if (lhs.type() != rhs.type()) {
        return false;
    }

    if (lhs.type() == Feature::Other) {
        return lhs.name().compare(rhs.name(), Qt::CaseInsensitive) == 0;
    }

    return true;
}

[[nodiscard]] static Feature::Availability mergeAvailability(Feature::Availability lhs, Feature::Availability rhs)
{
    if (lhs == Feature::Unknown) {
        return rhs;
    }
    if (rhs == Feature::Unknown) {
        return lhs;
    }

    if (lhs == Feature::Available) {
        return rhs;
    }
    if (rhs == Feature::Available) {
        return lhs;
    }

    if (lhs == Feature::Unavailable || rhs == Feature::Unavailable) {
        return Feature::Unavailable;
    }

    return lhs == Feature::Limited ? rhs : lhs;
}

Feature Feature::merge(const Feature &lhs, const Feature &rhs)
{
    Feature res(lhs);
    res.setAvailability(mergeAvailability(lhs.availability(), rhs.availability()));
    if (lhs.availability() == rhs.availability()) {
        res.setName(MergeUtil::mergeString(lhs.name(), rhs.name()));
        res.setDescription(MergeUtil::mergeString(lhs.description(), rhs.description()));
    } else if (rhs.availability() == res.availability()) {
        res.setName(rhs.name());
        res.setDescription(rhs.description());
    }
    res.setDisruptionEffect(std::max(lhs.disruptionEffect(), rhs.disruptionEffect()));
    res.setQuantity(std::max(lhs.quantity(), rhs.quantity()));
    return res;
}

#include "moc_feature.cpp"

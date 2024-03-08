/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "feature.h"
#include "datatypes_p.h"
#include "json_p.h"
#include "mergeutil_p.h"

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

    return lhs == Feature::Available ? rhs : lhs;
}

Feature Feature::merge(const Feature &lhs, const Feature &rhs)
{
    Feature res(lhs);
    res.setName(MergeUtil::mergeString(lhs.name(), rhs.name()));
    res.setDescription(MergeUtil::mergeString(lhs.description(), rhs.description()));
    res.setAvailability(mergeAvailability(lhs.availability(), rhs.availability()));
    res.setDisruptionEffect(std::max(lhs.disruptionEffect(), rhs.disruptionEffect()));
    res.setQuantity(std::max(lhs.quantity(), rhs.quantity()));
    return res;
}

#include "moc_feature.cpp"

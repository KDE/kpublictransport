/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "featureutil_p.h"

using namespace KPublicTransport;

static bool lessThanFeature(const Feature &lhs, const Feature &rhs)
{
    if (lhs.type() == rhs.type() && lhs.type() == Feature::Other) {
        return lhs.name().compare(rhs.name(), Qt::CaseInsensitive) < 0;
    }
    return lhs.type() < rhs.type();
}

void FeatureUtil::set(std::vector<Feature> &member, std::vector<Feature> &&features)
{
    std::sort(features.begin(), features.end(), lessThanFeature);
    member = std::move(features);
}

Feature FeatureUtil::findByType(const std::vector<Feature> &features, Feature::Type type)
{
    const auto it = std::find_if(features.begin(), features.end(), [type](const auto &f) { return f.type() == type; });
    if (it != features.end()) {
        return *it;
    }
    return {};
}

std::vector<Feature> FeatureUtil::merge(const std::vector<Feature> &lhs, const std::vector<Feature> &rhs)
{
    std::vector<Feature> res;
    auto lit = lhs.begin();
    auto rit = rhs.begin();

    while (lit != lhs.end() || rit != rhs.end()) {
        if (lit == lhs.end()) {
            res.push_back(*rit++);
            continue;;
        }
        if (rit == rhs.end()) {
            res.push_back(*lit++);
            continue;
        }

        if (Feature::isSame(*lit, *rit)) {
            res.push_back(Feature::merge(*lit++, *rit++));
        } else if ((*lit).type() < (*rit).type()) {
            res.push_back(*lit++);
        } else {
            res.push_back(*rit++);
        }
    }

    return res;
}

void FeatureUtil::add(std::vector<Feature> &features, Feature &&feature)
{
    if (feature.type() == Feature::NoFeature) {
        return;
    }

    auto it = std::lower_bound(features.begin(), features.end(), feature, lessThanFeature);
    if (it != features.end() && Feature::isSame(*it, feature)) {
        *it = Feature::merge(*it, feature);
    } else {
        features.insert(it, std::move(feature));
    }
}

static Feature aggregate(const Feature &lhs, const Feature &rhs)
{
    if (lhs.availability() == Feature::Unavailable && (rhs.availability() != Feature::Unavailable && rhs.availability() != Feature::Unknown)) {
        return rhs;
    }
    if (rhs.availability() == Feature::Unavailable && (lhs.availability() != Feature::Unavailable && lhs.availability() != Feature::Unknown)) {
        return lhs;
    }

    auto f = Feature::merge(lhs, rhs);
    f.setQuantity(lhs.quantity() + rhs.quantity());
    return f;
}

void FeatureUtil::aggregate(std::vector<Feature> &features, const Feature &feature)
{
   auto it = std::lower_bound(features.begin(), features.end(), feature, lessThanFeature);
    if (it != features.end() && Feature::isSame(*it, feature)) {
        *it = ::aggregate(*it, feature);
    } else {
        features.insert(it, feature);
    }
}

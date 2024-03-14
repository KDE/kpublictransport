/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_FEATUREUTIL_P_H
#define KPUBLICTRANSPORT_FEATUREUTIL_P_H

#include "feature.h"

namespace KPublicTransport {

/** Internal utility functions for dealing with features. */
namespace FeatureUtil
{
    /** Shared implementation for the features setter. */
    void set(std::vector<Feature> &member, std::vector<Feature> &&features);

    /** Shared implementation for the by type lookup API. */
    [[nodiscard]] Feature findByType(const std::vector<Feature> &features, Feature::Type type);

    /** Merge two sets of features. */
    [[nodiscard]] std::vector<Feature> merge(const std::vector<Feature> &lhs, const std::vector<Feature> &rhs);

    /** Add one Feature to an existing set.
     *  Inserts if not present yet, merges if already present.
     */
    void add(std::vector<Feature> &features, Feature &&feature);

    /** Compute union between a feature set and a feature to add.
     *  Unlike merging this doesn't assume both features refer to the same thing
     *  but to parts of the same thing, and thus information gets added rather than overridden.
     */
    void aggregate(std::vector<Feature> &features, const Feature &feature);
}

}

#endif

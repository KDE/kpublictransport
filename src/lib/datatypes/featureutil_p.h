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
}

}

#endif

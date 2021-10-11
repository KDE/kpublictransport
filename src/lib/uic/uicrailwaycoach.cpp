/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "uicrailwaycoach.h"

#include <QDebug>

using namespace KPublicTransport;

QStringView UicRailwayCoach::countryCode(QStringView coachNumber)
{
    // TODO handle different formatting of the coach number
    if (coachNumber.size() > 4) {
        return coachNumber.mid(2, 2);
    }
    return {};
}

static QStringView classificationDigit(QStringView coachNumber)
{
    // TODO handle different formatting
    if (coachNumber.size() > 5) {
        return coachNumber.mid(4, 1);
    }
    return {};
}

// see https://en.wikipedia.org/wiki/UIC_classification_of_railway_coaches
struct {
    const char prefix[5];
    VehicleSection::Classes classes;
    VehicleSection::Features features;
    VehicleSection::Type type;
    int deckCount;
} static constexpr const class_prefix_table[] = {
    { "AB", VehicleSection::FirstClass | VehicleSection::SecondClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 1 },
    { "AR", VehicleSection::FirstClass, VehicleSection::Restaurant, VehicleSection::UnknownType, 1 },
    { "A", VehicleSection::FirstClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 1 },
    { "BR", VehicleSection::SecondClass,  VehicleSection::Restaurant, VehicleSection::UnknownType, 1 },
    { "B", VehicleSection::SecondClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 1 },
    { "DAB", VehicleSection::FirstClass | VehicleSection::SecondClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 2 },
    { "DA", VehicleSection::FirstClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 2 },
    { "DB", VehicleSection::SecondClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 2 },
    { "DD", VehicleSection::UnknownClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 2 }, // TODO car transport coach
    { "WLAB", VehicleSection::FirstClass | VehicleSection::SecondClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 1 },
    { "WLA", VehicleSection::FirstClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 1 },
    { "WLB", VehicleSection::SecondClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 1 },
    { "WR", VehicleSection::UnknownClass, VehicleSection::Restaurant, VehicleSection::RestaurantCar, 1 },
    { "KA", VehicleSection::FirstClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 1 },
    { "KB", VehicleSection::SecondClass, VehicleSection::NoFeatures, VehicleSection::UnknownType, 1 },
};

VehicleSection::Classes UicRailwayCoach::coachClass(QStringView coachNumber, QStringView coachClassification)
{
    const auto it = std::find_if(std::begin(class_prefix_table), std::end(class_prefix_table), [coachClassification](const auto &prefix) {
        return coachClassification.startsWith(QLatin1String(prefix.prefix));
    });
    if (it != std::end(class_prefix_table)) {
        return (*it).classes;
    }

    const auto cls = classificationDigit(coachNumber);
    if (!cls.empty()) {
        switch (cls.at(0).cell()) {
            case '1':
                return VehicleSection::FirstClass;
            case '2':
            case '5':
                return VehicleSection::SecondClass;
            case '3':
                return VehicleSection::FirstClass | VehicleSection::SecondClass;
        }
    }

    return {};
}

int UicRailwayCoach::deckCount(QStringView coachNumber, QStringView coachClassification)
{
    Q_UNUSED(coachNumber);
    const auto it = std::find_if(std::begin(class_prefix_table), std::end(class_prefix_table), [coachClassification](const auto &prefix) {
        return coachClassification.startsWith(QLatin1String(prefix.prefix));
    });
    if (it != std::end(class_prefix_table)) {
        return (*it).deckCount;
    }
    return 1;
}

// see https://de.wikipedia.org/wiki/Code_f%C3%BCr_das_Austauschverfahren
struct {
    const char prefix[3];
    VehicleSection::Type type;
    VehicleSection::Features features;
} static constexpr const number_prefix_table[] = {
    { "50", VehicleSection::PassengerCar, VehicleSection::NoFeatures },
    { "70", VehicleSection::PassengerCar, VehicleSection::AirConditioning }, // also: air conditioned
    // { "71", VehicleSection:: TODO }, // TODO sleeping car
    { "73", VehicleSection::PassengerCar, VehicleSection::AirConditioning }, // also: air conditioned
    { "91", VehicleSection::Engine, VehicleSection::NoFeatures },
    { "92", VehicleSection::Engine, VehicleSection::NoFeatures },
};

// see https://en.wikipedia.org/wiki/UIC_classification_of_railway_coaches
struct UicClassificationSecondary {
    const char code[3];
    VehicleSection::Features features;
    VehicleSection::Type type;
};

// 80: Germany
static constexpr const UicClassificationSecondary secondary_80_table[] = {
    { "b", VehicleSection::WheelchairAccessible, VehicleSection::UnknownType },
    // "c" Couchettes - TODO needs enum
    { "d", VehicleSection::BikeStorage, VehicleSection::UnknownType },
    { "f", VehicleSection::NoFeatures, VehicleSection::ControlCar },
    { "k", VehicleSection::Restaurant, VehicleSection::UnknownType },
    { "p", VehicleSection::AirConditioning, VehicleSection::PassengerCar },
    { "q", VehicleSection::NoFeatures, VehicleSection::ControlCar },
};

// 81: Austria
static constexpr const UicClassificationSecondary secondary_81_table[] = {
    { "b", VehicleSection::WheelchairAccessible, VehicleSection::UnknownType }, // TODO wheelchair accessible toilets specifically
    // "c" Couchettes - TODO needs enum
    { "f", VehicleSection::NoFeatures, VehicleSection::ControlCar },
    { "p", VehicleSection::NoFeatures, VehicleSection::PassengerCar },
    { "-s", VehicleSection::NoFeatures, VehicleSection::ControlCar },
};

struct {
    const char country[3];
    const UicClassificationSecondary *begin;
    const UicClassificationSecondary *end;
} static constexpr const secondary_tables[] = {
    { "80", std::begin(secondary_80_table), std::end(secondary_80_table) },
    { "81", std::begin(secondary_81_table), std::end(secondary_81_table) },
};

VehicleSection::Features UicRailwayCoach::features(QStringView coachNumber, QStringView coachClassification)
{
    VehicleSection::Features f = {};
    const auto it = std::find_if(std::begin(class_prefix_table), std::end(class_prefix_table), [coachClassification](const auto &prefix) {
        return coachClassification.startsWith(QLatin1String(prefix.prefix));
    });
    if (it != std::end(class_prefix_table)) {
        f |= (*it).features;
    }

    const auto it2 = std::find_if(std::begin(number_prefix_table), std::end(number_prefix_table), [coachNumber](const auto &prefix) {
        return coachNumber.startsWith(QLatin1String(prefix.prefix));
    });
    if (it2 != std::end(number_prefix_table)) {
        f |= (*it2).features;
    }

    const auto country = UicRailwayCoach::countryCode(coachNumber);
    if (country.empty()) {
        return f;
    }

    for (const auto &tab : secondary_tables) {
        if (country != QLatin1String(tab.country)) {
            continue;
        }
        for (auto it = tab.begin; it != tab.end; ++it) {
            if (coachClassification.contains(QLatin1String((*it).code))) {
                f |= (*it).features;
            }
        }
    }

    return f;
}

VehicleSection::Type UicRailwayCoach::type(QStringView coachNumber, QStringView coachClassification)
{
    bool seenPassengerCar = false;
    const auto it = std::find_if(std::begin(class_prefix_table), std::end(class_prefix_table), [coachClassification](const auto &prefix) {
        return prefix.type != VehicleSection::UnknownType && coachClassification.startsWith(QLatin1String(prefix.prefix));
    });
    if (it != std::end(class_prefix_table)) {
        if ((*it).type == VehicleSection::PassengerCar) {
            seenPassengerCar = true;
        } else {
            return (*it).type;
        }
    }

    const auto it2 = std::find_if(std::begin(number_prefix_table), std::end(number_prefix_table), [coachNumber](const auto &prefix) {
        return prefix.type != VehicleSection::UnknownType && coachNumber.startsWith(QLatin1String(prefix.prefix));
    });
    if (it2 != std::end(number_prefix_table)) {
        if ((*it2).type == VehicleSection::PassengerCar) {
            seenPassengerCar = true;
        } else {
            return (*it2).type;
        }
    }

    const auto country = UicRailwayCoach::countryCode(coachNumber);
    if (!country.empty()) {
        for (const auto &tab : secondary_tables) {
            if (country != QLatin1String(tab.country)) {
                continue;
            }
            const auto it = std::find_if(tab.begin, tab.end, [coachClassification](const auto &prefix) {
                return prefix.type != VehicleSection::UnknownType && coachClassification.contains(QLatin1String(prefix.code));
            });
            if (it != tab.end) {
                if ((*it).type == VehicleSection::PassengerCar) {
                    seenPassengerCar = true;
                } else {
                    return (*it).type;
                }
            }
        }
    }

    return seenPassengerCar ? VehicleSection::PassengerCar : VehicleSection::UnknownType;
}

/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "uicrailwaycoach.h"
#include "datatypes/featureutil_p.h"

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
    Feature::Type feature;
    VehicleSection::Type type;
    int deckCount;
} static constexpr const class_prefix_table[] = {
    { "AB", VehicleSection::FirstClass | VehicleSection::SecondClass, Feature::NoFeature, VehicleSection::UnknownType, 1 },
    { "AR", VehicleSection::FirstClass, Feature::Restaurant, VehicleSection::PassengerCar, 1 },
    { "A", VehicleSection::FirstClass, Feature::NoFeature, VehicleSection::UnknownType, 1 },
    { "BR", VehicleSection::SecondClass,  Feature::Restaurant, VehicleSection::PassengerCar, 1 },
    { "B", VehicleSection::SecondClass, Feature::NoFeature, VehicleSection::UnknownType, 1 },
    { "DAB", VehicleSection::FirstClass | VehicleSection::SecondClass, Feature::NoFeature, VehicleSection::UnknownType, 2 },
    { "DA", VehicleSection::FirstClass, Feature::NoFeature, VehicleSection::UnknownType, 2 },
    { "DB", VehicleSection::SecondClass, Feature::NoFeature, VehicleSection::UnknownType, 2 },
    { "DD", VehicleSection::UnknownClass, Feature::NoFeature, VehicleSection::CarTransportCar, 2 },
    { "WLAB", VehicleSection::FirstClass | VehicleSection::SecondClass, Feature::NoFeature, VehicleSection::SleepingCar, 1 },
    { "WLA", VehicleSection::FirstClass, Feature::NoFeature, VehicleSection::UnknownType, 1 },
    { "WLB", VehicleSection::SecondClass, Feature::NoFeature, VehicleSection::UnknownType, 1 },
    { "WR", VehicleSection::UnknownClass, Feature::Restaurant, VehicleSection::RestaurantCar, 1 },
    { "KA", VehicleSection::FirstClass, Feature::NoFeature, VehicleSection::UnknownType, 1 },
    { "KB", VehicleSection::SecondClass, Feature::NoFeature, VehicleSection::UnknownType, 1 },
};

VehicleSection::Classes UicRailwayCoach::coachClass(QStringView coachNumber, QStringView coachClassification)
{
    const auto it = std::find_if(std::begin(class_prefix_table), std::end(class_prefix_table), [coachClassification](const auto &prefix) {
        return coachClassification.startsWith(QLatin1String(prefix.prefix));
    });
    if (it != std::end(class_prefix_table)) {
        return (*it).classes;
    }

    const auto type = UicRailwayCoach::type(coachNumber, coachClassification);
    if (type == VehicleSection::PassengerCar || type == VehicleSection::SleepingCar) {
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
    }

    return {};
}

// see https://de.wikipedia.org/wiki/Code_f%C3%BCr_das_Austauschverfahren
struct {
    const char prefix[3];
    VehicleSection::Type type;
    Feature::Type feature;
} static constexpr const number_prefix_table[] = {
    { "50", VehicleSection::PassengerCar, Feature::NoFeature },
    { "70", VehicleSection::PassengerCar, Feature::AirConditioning },
    { "71", VehicleSection::SleepingCar, Feature::NoFeature },
    { "73", VehicleSection::PassengerCar, Feature::AirConditioning },
    { "91", VehicleSection::Engine, Feature::NoFeature },
    { "92", VehicleSection::Engine, Feature::NoFeature },
};

// see https://en.wikipedia.org/wiki/UIC_classification_of_railway_coaches
struct UicClassificationSecondary {
    const char code[4];
    Feature::Type feature;
    VehicleSection::Type type;
    int deckCount;
};

// 54: Czech Republic
static constexpr const UicClassificationSecondary secondary_54_table[] = {
    { "b", Feature::WheelchairAccessible, VehicleSection::UnknownType, 1 },
    { "c", Feature::NoFeature, VehicleSection::CouchetteCar, 1 },
    { "d", Feature::BikeStorage, VehicleSection::UnknownType, 1 },
    { "f", Feature::NoFeature, VehicleSection::ControlCar, 1 },
    { "o", Feature::NoFeature, VehicleSection::UnknownType, 2 }, // ### could also be 't'?
    { "z", Feature::AirConditioning, VehicleSection::PassengerCar, 1 },
};

// 80: Germany
static constexpr const UicClassificationSecondary secondary_80_table[] = {
    { "b", Feature::WheelchairAccessible, VehicleSection::UnknownType, 1 },
    { "c", Feature::NoFeature, VehicleSection::CouchetteCar, 1 },
    { "d", Feature::BikeStorage, VehicleSection::UnknownType, 1 },
    { "f", Feature::NoFeature, VehicleSection::ControlCar, 1 },
    { "k", Feature::Restaurant, VehicleSection::UnknownType, 1 },
    { "p", Feature::AirConditioning, VehicleSection::PassengerCar, 1 },
    { "q", Feature::NoFeature, VehicleSection::ControlCar, 1 },
};

// 81: Austria
static constexpr const UicClassificationSecondary secondary_81_table[] = {
    { "b", Feature::WheelchairAccessible, VehicleSection::UnknownType, 1 }, // TODO wheelchair accessible toilets specifically
    { "c", Feature::NoFeature, VehicleSection::CouchetteCar, 1 },
    { "f", Feature::NoFeature, VehicleSection::ControlCar, 1 },
    { "p", Feature::NoFeature, VehicleSection::PassengerCar, 1 },
    { "-s", Feature::NoFeature, VehicleSection::ControlCar, 1 },
    { "-dl", Feature::NoFeature, VehicleSection::PassengerCar, 2 },
    { "-ds", Feature::NoFeature, VehicleSection::ControlCar, 2 },
};

// 85: Switzerland
static constexpr const UicClassificationSecondary secondary_85_table[] = {
    { "c", Feature::NoFeature, VehicleSection::CouchetteCar, 1 },
    { "r", Feature::Restaurant, VehicleSection::UnknownType, 1 },
    { "t", Feature::NoFeature, VehicleSection::ControlCar, 1 },
};

// 87: France
static constexpr const UicClassificationSecondary secondary_87_table[] = {
    { "c", Feature::NoFeature, VehicleSection::CouchetteCar, 1 },
    { "e", Feature::NoFeature, VehicleSection::UnknownType, 2 },
    { "h", Feature::WheelchairAccessible, VehicleSection::UnknownType, 1 },
    { "u", Feature::AirConditioning, VehicleSection::UnknownType, 1 },
};

struct {
    const char country[3];
    const UicClassificationSecondary *begin;
    const UicClassificationSecondary *end;
} static constexpr const secondary_tables[] = {
    { "54", std::begin(secondary_54_table), std::end(secondary_54_table) },
    { "80", std::begin(secondary_80_table), std::end(secondary_80_table) },
    { "81", std::begin(secondary_81_table), std::end(secondary_81_table) },
    { "85", std::begin(secondary_85_table), std::end(secondary_85_table) },
    { "87", std::begin(secondary_87_table), std::end(secondary_87_table) },
};

int UicRailwayCoach::deckCount(QStringView coachNumber, QStringView coachClassification)
{
    int decks = 1;
    const auto it = std::find_if(std::begin(class_prefix_table), std::end(class_prefix_table), [coachClassification](const auto &prefix) {
        return coachClassification.startsWith(QLatin1String(prefix.prefix));
    });
    if (it != std::end(class_prefix_table)) {
        decks = std::max(decks, (*it).deckCount);
    }

    const auto country = UicRailwayCoach::countryCode(coachNumber);
    for (const auto &tab : secondary_tables) {
        if (country != QLatin1String(tab.country)) {
            continue;
        }
        for (auto it = tab.begin; it != tab.end; ++it) {
            if (coachClassification.contains(QLatin1String((*it).code))) {
                decks = std::max(decks, (*it).deckCount);
            }
        }
    }

    return decks;
}

std::vector<Feature> UicRailwayCoach::features(QStringView coachNumber, QStringView coachClassification)
{
    std::vector<Feature> f;
    const auto it = std::find_if(std::begin(class_prefix_table), std::end(class_prefix_table), [coachClassification](const auto &prefix) {
        return coachClassification.startsWith(QLatin1String(prefix.prefix));
    });
    if (it != std::end(class_prefix_table) && (*it).feature != Feature::NoFeature) {
        FeatureUtil::add(f, Feature((*it).feature, Feature::Available));
    }

    const auto it2 = std::find_if(std::begin(number_prefix_table), std::end(number_prefix_table), [coachNumber](const auto &prefix) {
        return coachNumber.startsWith(QLatin1String(prefix.prefix));
    });
    if (it2 != std::end(number_prefix_table) && (*it2).feature != Feature::NoFeature) {
        FeatureUtil::add(f, Feature((*it2).feature, Feature::Available));
    }

    const auto country = UicRailwayCoach::countryCode(coachNumber);
    for (const auto &tab : secondary_tables) {
        if (country != QLatin1String(tab.country)) {
            continue;
        }
        for (auto it = tab.begin; it != tab.end; ++it) {
            if (coachClassification.contains(QLatin1String((*it).code)) && (*it).feature != Feature::NoFeature) {
                FeatureUtil::add(f, Feature((*it).feature, Feature::Available));
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

    return seenPassengerCar ? VehicleSection::PassengerCar : VehicleSection::UnknownType;
}

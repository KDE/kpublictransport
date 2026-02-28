/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "opentransportswissformationparser.h"

#include <datatypes/featureutil_p.h>
#include <uic/uicrailwaycoach.h>

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace Qt::Literals;
using namespace KPublicTransport;

struct {
    const char *key;
    Feature::Type feature = Feature::NoFeature;
    VehicleSection::Class classType = VehicleSection::UnknownClass;
} static constexpr const vehicle_property_map[] = {
    { .key = "numberRestaurantSpace", .feature = Feature::Restaurant },
    { .key = "numberBeds", .feature = Feature::SleeperCompartment },
    { .key = "numberBikeHooks", .feature = Feature::BikeStorage },
    { .key = "number1class", .classType = VehicleSection::FirstClass },
    { .key = "number2class", .classType = VehicleSection::SecondClass },
    // bikePlatform ??
    // lowFloorTrolley ??
    // disabledCompartment ??
    { .key = "climated", .feature = Feature::AirConditioning },
    { .key = "numberWheelchairSpaces", .feature = Feature::WheelchairAccessible },
    { .key = "numberWheelchairSpaces1class", .feature = Feature::WheelchairAccessible, .classType = VehicleSection::FirstClass },
    { .key = "numberWheelchairSpaces2class", .feature = Feature::WheelchairAccessible, .classType = VehicleSection::SecondClass },
    { .key = "wheelchairToilet", .feature = Feature::WheelchairAccessibleToilet },
    { .key = "wheelchairAccessibleRestaurant", .feature = Feature::WheelchairAccessible },
    // foldingRamp, heightBoardingPlatform, gapBridging
    { .key = "wheelchairPicto", .feature = Feature::WheelchairAccessible },
    { .key = "bikePicto", .feature = Feature::BikeStorage },
    // { .key = "strollerPicto", .feature = Feature::FamilyArea }, ??
    { .key = "familyZonePicto", .feature = Feature::FamilyArea },
    { .key = "businessZonePicto", .feature = Feature::BusinessArea },
};

static void parseVehicleProperties(const QJsonObject &obj, VehicleSection &coach)
{
    auto features = coach.takeSectionFeatures();
    for (auto it = obj.begin(); it != obj.end(); ++it) {
        if (!(*it).isBool() && !(*it).isDouble()) {
            continue;
        }
        if ((*it).isBool() && !(*it).toBool()) {
            continue;
        }
        if ((*it).isDouble() && (*it).toDouble() == 0) {
            continue;
        }

        const auto key = it.key();
        const auto it2 = std::ranges::find_if(vehicle_property_map, [key](const auto &m) {
            return QLatin1StringView(m.key) == key;
        });
        if (it2 == std::end(vehicle_property_map)) {
            continue;
        }

        if (coach.type() == VehicleSection::UnknownType) {
            coach.setType(VehicleSection::PassengerCar);
        }

        coach.setClasses(coach.classes() | (*it2).classType);
        if ((*it2).feature == Feature::NoFeature) {
            continue;
        }

        Feature f((*it2).feature);
        if ((*it).isDouble()) {
            f.setQuantity((*it).toInt());
        }
        FeatureUtil::add(features, std::move(f));
    }
    coach.setSectionFeatures(std::move(features));
}

bool OpenTransportSwissFormationParser::parse(const QByteArray &data, const QString &identifierType)
{
    const auto obj = QJsonDocument::fromJson(data).object();
    errorMsg = obj.value("error"_L1).toString();
    if (!errorMsg.isEmpty()) {
        return false;
    }

    const auto formations = obj.value("formations"_L1).toArray();
    for (const auto &formationV : formations) {
        Vehicle vehicle;
        std::vector<VehicleSection> coaches;

        const auto formation = formationV.toObject();
        const auto formationVehicles = formation.value("formationVehicles"_L1).toArray();
        for (const auto &formationVehicleV : formationVehicles) {
            VehicleSection coach;

            const auto formationVehicle = formationVehicleV.toObject();
            if (const auto coachNum = formationVehicle.value("number"_L1).toInt(); coachNum > 0) {
                coach.setName(QString::number(coachNum));
            }

            const auto vehicleIdentification = formationVehicle.value("vehicleIdentifier"_L1).toObject();
            const auto uicTypeCode = vehicleIdentification.value("typeCodeName"_L1).toString();
            auto evn = vehicleIdentification.value("evn"_L1).toString();
            evn.erase(std::remove_if(evn.begin(), evn.end(), [](QChar c) { return !c.isDigit(); }), evn.end());
            coach.setType(UicRailwayCoach::type(evn, uicTypeCode));
            coach.setClasses(UicRailwayCoach::coachClass(evn, uicTypeCode));
            coach.setDeckCount(UicRailwayCoach::deckCount(evn, uicTypeCode));
            coach.setSectionFeatures(UicRailwayCoach::features(evn, uicTypeCode));

            const auto vehicleProperties = formationVehicle.value("vehicleProperties"_L1).toObject();
            if (vehicleProperties.value("closed"_L1).toBool()) {
                coach.setDisruptionEffect(Disruption::NoService);
            }
            parseVehicleProperties(vehicleProperties, coach);
            parseVehicleProperties(vehicleProperties.value("accessibilityProperties"_L1).toObject(), coach);
            parseVehicleProperties(vehicleProperties.value("pictoProperties"_L1).toObject(), coach);
            coaches.push_back(std::move(coach));
        }

        vehicle.setSections(std::move(coaches));
        stopover.setVehicleLayout(vehicle); // TODO temporary
    }

    const auto jidObj = obj.value("journeyMetaInformation"_L1).toObject();
    stopover.setTripIdentifier(identifierType, jidObj.value("SJYID"_L1).toString() + '|'_L1 + jidObj.value("operationDate"_L1).toString());

    const auto trainObj = obj.value("trainMetaInformation"_L1).toObject();
    Route route;
    route.setName(QString::number(trainObj.value("trainNumber"_L1).toInt()));
    Line line;
    line.setOperatorIdentifier(identifierType, trainObj.value("toCode"_L1).toString());
    route.setLine(line);
    stopover.setRoute(route);

    return true;
}

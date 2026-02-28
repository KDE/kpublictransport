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

#include <unordered_map>

using namespace Qt::Literals;
using namespace KPublicTransport;

struct {
    const char code[3];
    VehicleSection::Type type = VehicleSection::UnknownType;
    VehicleSection::Classes classes = VehicleSection::UnknownClass;
    bool skip = false;
} constexpr static const formation_string_type_map[] = {
    { .code = "12", .type = VehicleSection::PassengerCar, .classes = VehicleSection::FirstClass|VehicleSection::SecondClass },
    { .code = "1", .type = VehicleSection::PassengerCar, .classes = VehicleSection::FirstClass },
    { .code = "2", .type = VehicleSection::PassengerCar, .classes = VehicleSection::SecondClass },
    { .code = "CC", .type = VehicleSection::CouchetteCar },
    { .code = "FA", .type = VehicleSection::PassengerCar }, // TODO family car?
    { .code = "WL", .type = VehicleSection::SleepingCar },
    { .code = "WR", .type = VehicleSection::RestaurantCar },
    { .code = "W1", .type = VehicleSection::RestaurantCar, .classes = VehicleSection::FirstClass }, // TODO or should this be PassengerCar + Restaurant feature?
    { .code = "W2", .type = VehicleSection::RestaurantCar, .classes = VehicleSection::SecondClass }, // TODO or should this be PassengerCar + Restaurant feature?
    { .code = "LK", .type = VehicleSection::Engine },
    { .code = "D" }, // TODO baggage car?
    { .code = "F", .skip = true },
    { .code = "X", .skip = true },
};

struct {
    const char code[4];
    Feature::Type type = Feature::NoFeature;
    Feature::Availability avail = Feature::Available;
} constexpr static const formation_string_feature_map[] = {
    { .code = "BHP", .type = Feature::WheelchairAccessible },
    { .code = "BZ", .type = Feature::BusinessArea },
    { .code = "FZ", .type = Feature::FamilyArea },
    // { .code = "KW", .type = Feature::FamilyArea }, // TODO stroller storage
    // { .code = "NF", .type = Feature::WheelchairAccessible }, // TODO low floor
    { .code = "VH", .type = Feature::BikeStorage },
    { .code = "VR", .type = Feature::BikeStorage, .avail = Feature::Conditional },
};

static void parsePlatformSectorString(QStringView s, const QString &sectorName, std::vector<VehicleSection> &coaches)
{
    for (auto coachStr : QStringTokenizer(s, ','_L1, Qt::SkipEmptyParts)) {
        VehicleSection coach;
        std::vector<Feature> features;

        // ignore vehicle group markers, we don't support that yet
        if (coachStr.startsWith('['_L1)) {
            coachStr = coachStr.mid(1);
        }
        if (coachStr.endsWith(']'_L1)) {
            coachStr = coachStr.chopped(1);
        }

        // status marker
        if (coachStr.startsWith('-'_L1)) {
            coach.setDisruptionEffect(Disruption::NoService);
            coachStr = coachStr.mid(1);
        } else if (coachStr.startsWith('%'_L1)) {
            FeatureUtil::add(features, Feature(Feature::Restaurant, Feature::Unavailable));
            coachStr = coachStr.mid(1);
        } else if (coachStr.startsWith('>'_L1)  || coachStr.startsWith('='_L1)) {
            coachStr = coachStr.mid(1);
        }

        if (coachStr.startsWith('('_L1)) {
            coach.setConnectedSides(coach.connectedSides() & ~VehicleSection::Front);
            coachStr = coachStr.mid(1);
        }

        const auto it = std::ranges::find_if(formation_string_type_map, [coachStr](const auto &m) {
            return coachStr.startsWith(QLatin1StringView(m.code));
        });
        if (it != std::end(formation_string_type_map)) {
            if ((*it).skip) {
                continue;
            }
            if ((*it).type != VehicleSection::UnknownType) {
                coach.setType((*it).type);
            }
            if ((*it).classes != VehicleSection::UnknownClass) {
                coach.setClasses((*it).classes);
            }
            coachStr = coachStr.mid((qsizetype)std::strlen((*it).code));
        } else {
            qDebug() << "unknown coach type in formation string:" << coachStr;
        }

        if (coachStr.startsWith(')'_L1)) {
            coach.setConnectedSides(coach.connectedSides() & ~VehicleSection::Back);
            coachStr = coachStr.mid(1);
        }

        if (coachStr.startsWith(':'_L1)) {
            const auto idx = coachStr.indexOf('#'_L1);
            if (idx < 0) {
                coach.setName(coachStr.mid(1).toString());
            } else {
                coach.setName(coachStr.mid(1, idx - 1).toString());
            }
            coachStr = coachStr.mid(idx);
        }

        if (coachStr.startsWith('#'_L1)) {
            for (const auto &featStr :QStringTokenizer(coachStr.mid(1), ';'_L1)) {
                const auto it = std::ranges::find_if(formation_string_feature_map, [featStr](const auto &m) {
                    return QLatin1StringView(m.code) == featStr;
                });
                if (it != std::end(formation_string_feature_map)) {
                    FeatureUtil::add(features, Feature((*it).type, (*it).avail));
                }
            }
        }

        coach.setPlatformSectionName(sectorName);
        coach.setSectionFeatures(std::move(features));
        coaches.push_back(std::move(coach));
    }
}

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

[[nodiscard]] static double findPlatformSectionStart(const std::vector<PlatformSection> &platform, QStringView sectorName)
{
    if (const auto it = std::ranges::find_if(platform, [sectorName](const auto &p) { return p.name() == sectorName; }); it != platform.end()) {
        return (*it).begin();
    }
    return 0.0;
}

struct {
    const char *code;
    PickupDropoff::Type alight = PickupDropoff::Normal;
    PickupDropoff::Type boarding = PickupDropoff::Normal;
} constexpr static const stop_type_map[] = {
    { .code = "H" },
    { .code = "A", .boarding = PickupDropoff::NotAllowed },
    { .code = "+A", .boarding = PickupDropoff::NotAllowed },
    { .code = "B", .alight = PickupDropoff::CoordinateWithDriver, .boarding = PickupDropoff::CoordinateWithDriver },
    { .code = "BA", .alight = PickupDropoff::CoordinateWithDriver, .boarding = PickupDropoff::NotAllowed },
    { .code = "BE", .alight = PickupDropoff::NotAllowed, .boarding = PickupDropoff::CoordinateWithDriver },
    { .code = "D", .alight = PickupDropoff::NotAllowed, .boarding = PickupDropoff::NotAllowed },
    { .code = "+D", .alight = PickupDropoff::CoordinateWithDriver, .boarding = PickupDropoff::NotAllowed },
    { .code = "E", .alight = PickupDropoff::NotAllowed },
    { .code = "-H" },
    { .code = "+H" },
};

bool OpenTransportSwissFormationParser::parse(const QByteArray &data, const QString &identifierType, int uicCode)
{
    const auto obj = QJsonDocument::fromJson(data).object();
    errorMsg = obj.value("error"_L1).toString();
    if (!errorMsg.isEmpty()) {
        return false;
    }

    Platform platform;
    std::vector<PlatformSection> platformSections;
    Vehicle vehicle;
    std::vector<VehicleSection> coaches;

    for (const auto &formationsAtScheduledStopV : obj.value("formationsAtScheduledStops"_L1).toArray()) {
        const auto formationsAtScheduledStop = formationsAtScheduledStopV.toObject();
        const auto scheduledStop = formationsAtScheduledStop.value("scheduledStop"_L1).toObject();
        const auto stopPoint = scheduledStop.value("stopPoint"_L1).toObject();
        if (stopPoint.value("uic"_L1).toInt() != uicCode) {
            continue;
        }

        Location loc;
        loc.setName(stopPoint.value("name"_L1).toString());
        loc.setIdentifier(u"uic"_s, QString::number(uicCode));
        stopover.setStopPoint(loc);

        const auto stopTime = scheduledStop.value("stopTime"_L1).toObject();
        stopover.setScheduledArrivalTime(QDateTime::fromString(stopTime.value("arrivalTime"_L1).toString(), Qt::ISODate));
        stopover.setScheduledDepartureTime(QDateTime::fromString(stopTime.value("departureTime"_L1).toString(), Qt::ISODate));
        stopover.setScheduledPlatform(scheduledStop.value("track"_L1).toString());

        const auto stopType = scheduledStop.value("stopType"_L1);
        for (const auto &m : stop_type_map) {
            if (QLatin1StringView(m.code) != stopType) {
                continue;
            }
            stopover.setDropoffType(m.alight);
            stopover.setPickupType(m.boarding);
            break;
        }

        const auto formationString = formationsAtScheduledStop.value("formationShort"_L1).toObject().value("formationShortString"_L1).toString();
        if (formationString.startsWith('@'_L1)) {
            for (const auto sector : QStringTokenizer(formationString, '@'_L1, Qt::SkipEmptyParts)) {
                const auto idx = sector.indexOf(','_L1);
                if (idx <= 0) {
                    break;
                }
                PlatformSection sec;
                sec.setName(sector.left(idx).toString());
                parsePlatformSectorString(sector.mid(idx), sec.name(), coaches);
                platformSections.push_back(std::move(sec));
            }
        } else {
            parsePlatformSectorString(formationString, QString(), coaches);
        }
        vehicle.setDirection(Vehicle::Forward);
        break;
    }

    const auto formations = obj.value("formations"_L1).toArray();
    for (const auto &formationV : formations) {
        std::unordered_map<QString, double> platformLengthMap;
        double maxCoachLength = 0.0;

        const auto formation = formationV.toObject();

        const auto formationVehicles = formation.value("formationVehicles"_L1).toArray();
        for (const auto &formationVehicleV : formationVehicles) {
            const auto formationVehicle = formationVehicleV.toObject();

            const auto vehicleProperties = formationVehicle.value("vehicleProperties"_L1).toObject();
            const auto coachLength = vehicleProperties.value("length"_L1).toDouble();
            maxCoachLength = std::max(maxCoachLength, coachLength);

            const auto coachNum = formationVehicle.value("number"_L1).toInt();
            if (coachNum <= 0) {
                continue;
            }
            const auto it = std::ranges::find_if(coaches, [coachNum](const auto &coach) {
                return coach.name() == QString::number(coachNum);
            });
            if (it == coaches.end()) {
                continue;
            }
            auto &coach = *it;

            const auto vehicleIdentification = formationVehicle.value("vehicleIdentifier"_L1).toObject();
            const auto uicTypeCode = vehicleIdentification.value("typeCodeName"_L1).toString();
            auto evn = vehicleIdentification.value("evn"_L1).toString();
            evn.erase(std::remove_if(evn.begin(), evn.end(), [](QChar c) { return !c.isDigit(); }), evn.end());
            if (const auto uicType = UicRailwayCoach::type(evn, uicTypeCode); coach.type() == VehicleSection::UnknownType || uicType == VehicleSection::ControlCar) {
                coach.setType(uicType);
            }
            if (coach.classes() == VehicleSection::UnknownClass) {
                coach.setClasses(UicRailwayCoach::coachClass(evn, uicTypeCode));
            }
            coach.setDeckCount(UicRailwayCoach::deckCount(evn, uicTypeCode));
            coach.setSectionFeatures(FeatureUtil::merge(coach.takeSectionFeatures(), UicRailwayCoach::features(evn, uicTypeCode)));

            coach.setLength(coachLength);
            if (vehicleProperties.value("closed"_L1).toBool()) {
                coach.setDisruptionEffect(Disruption::NoService);
            }
            parseVehicleProperties(vehicleProperties, coach);
            parseVehicleProperties(vehicleProperties.value("accessibilityProperties"_L1).toObject(), coach);
            parseVehicleProperties(vehicleProperties.value("pictoProperties"_L1).toObject(), coach);
        }

        // populate missing lengths
        for (auto &coach : coaches) {
            if (!coach.hasLength()) {
                coach.setLength(maxCoachLength);
            }
            platformLengthMap[coach.platformSectionName()] += coach.length();
        }
        for (const auto &sec : platformSections) {
            if (const auto it = platformLengthMap.find(sec.name()); it == platformLengthMap.end()) {
                platformLengthMap[sec.name()] = maxCoachLength; // default sectors sizes when we didn't get any
            }
        }

        // compute platform coordinates
        const auto platformLength = std::accumulate(platformLengthMap.begin(), platformLengthMap.end(), 0.0, [](double l, const auto &sec) {
            return l + sec.second;
        });
        if (platformLength > 0.0) {
            double platformPos = 0.0;
            for (auto &sec : platformSections) {
                sec.setBegin((float)(platformPos / platformLength));
                platformPos += platformLengthMap[sec.name()];
                sec.setEnd((float)(platformPos / platformLength));
            }
            platform.setLength((int)std::round(platformLength));
        }

        // compute vehicle layout
        if (vehicle.direction() == Vehicle::Forward) {
            double pos = -1.0;
            for (auto &coach : coaches) {
                if (pos < 0.0f) {
                    pos = findPlatformSectionStart(platformSections, coach.platformSectionName());
                }
                coach.setPlatformPositionBegin((float)pos);
                pos += coach.length() / platformLength;
                coach.setPlatformPositionEnd((float)pos);
            }
        }

        vehicle.setSections(std::move(coaches));
        stopover.setVehicleLayout(vehicle);
        break;
    }

    platform.setSections(std::move(platformSections));
    stopover.setPlatformLayout(platform);

    const auto jidObj = obj.value("journeyMetaInformation"_L1).toObject();
    stopover.setTripIdentifier(identifierType, jidObj.value("SJYID"_L1).toString() + '|'_L1 + jidObj.value("operationDate"_L1).toString());

    const auto trainObj = obj.value("trainMetaInformation"_L1).toObject();
    Route route;
    route.setName(QString::number(trainObj.value("trainNumber"_L1).toInt()));
    Line line;
    line.setOperatorIdentifier(identifierType, trainObj.value("toCode"_L1).toString());
    route.setLine(line);
    if (trainObj.value("runs"_L1) == "N"_L1) {
        stopover.setDisruptionEffect(Disruption::NoService);
    }
    stopover.setRoute(route);

    return true;
}

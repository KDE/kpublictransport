/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "deutschebahnvehiclelayoutparser.h"
#include "deutschebahnproducts.h"
#include "datatypes/featureutil_p.h"
#include "uic/uicrailwaycoach.h"

#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <cmath>

using namespace Qt::Literals;
using namespace KPublicTransport;

Stopover DeutscheBahnVehicleLayoutParser::parse(const QByteArray &data)
{
    Stopover stopover;

    const auto doc = QJsonDocument::fromJson(data);
    const auto obj = doc.object();

    // platform
    Platform platform;
    const auto platformObj = obj.value("platform"_L1).toObject();
    platform.setName(platformObj.value("name"_L1).toString());
    platform.setLength(std::ceil(platformObj.value("end"_L1).toDouble() - platformObj.value("start"_L1).toDouble()));
    const auto sectorArray = platformObj.value("sectors"_L1).toArray();
    for (const auto &sectorV : sectorArray) {
        parsePlatformSection(platform, sectorV.toObject());
    }
    stopover.setScheduledPlatform(obj.value("departurePlatformSchedule"_L1).toString());
    stopover.setExpectedPlatform(obj.value("departurePlatformSchedule"_L1).toString());

    // vehicles
    Vehicle vehicle;
    // TODO dobule segment ICE trains technically are two Vehicle objects...
    const auto vehiclesArray = obj.value("groups"_L1).toArray();
    for (const auto &vehicleV : vehiclesArray) {
        // if only one: read "transport" TODO
        const auto sectionsArray = vehicleV.toObject().value("vehicles"_L1).toArray();
        for (const auto &sectionV : sectionsArray) {
            parseVehicleSection(vehicle, sectionV.toObject(), platform);
        }
    }
    // direction is implied by section order
    if (vehicle.sections().size() >= 2) {
        vehicle.setDirection(vehicle.sections()[0].platformPositionBegin() < vehicle.sections()[1].platformPositionBegin() ? Vehicle::Forward : Vehicle::Backward);
    }

    // departure information
    // TODO two-segment trains with the same destination could be handled here already
    if (vehiclesArray.size() == 1) {
        const auto transport = vehiclesArray[0].toObject().value("transport"_L1).toObject();
        Line line;
        const auto modeStr = transport.value("category"_L1).toString();
        line.setMode(DeutscheBahnProducts::modeType(modeStr));
        if (line.mode() == Line::Unknown) {
            line.setMode(Line::Train);
        }
        if (const auto num = transport.value("number"_L1).toInt(); num > 0) {
            line.setName(modeStr + ' '_L1 + QString::number(num));
        } else {
            line.setModeString(modeStr);
        }
        Route route;
        route.setDirection(transport.value("destination"_L1).toObject().value("name"_L1).toString());
        route.setLine(line);
        stopover.setRoute(route);
    }

    fillMissingPositions(vehicle, platform);
    stopover.setVehicleLayout(vehicle);
    stopover.setPlatformLayout(platform);

    return stopover;
}

struct {
    const char *name;
    Feature::Type type;
} constexpr const feature_map[] = {
    { "AIR_CONDITION", Feature::AirConditioning },
    { "BIKE_SPACE", Feature::BikeStorage },
    { "BISTRO", Feature::Restaurant },
    { "CABIN_INFANT", Feature::ToddlerArea },
    { "INFO", Feature::InformationPoint },
    { "TOILET", Feature::Toilet },
    { "TOILET_WHEELCHAIR", Feature::WheelchairAccessibleToilet },
    { "WHEELCHAIR_SPACE", Feature::WheelchairAccessible },
    { "WIFI", Feature::WiFi },
    { "ZONE_FAMILY", Feature::FamilyArea },
    { "ZONE_QUIET", Feature::SilentArea },
};

void DeutscheBahnVehicleLayoutParser::parseVehicleSection(Vehicle &vehicle, const QJsonObject &obj, const Platform &platform)
{
    VehicleSection section;
    if (const auto num = obj.value("wagonIdentificationNumber"_L1).toInt(); num > 0) {
        section.setName(QString::number(num));
    }

    const double length = std::max(1, platform.length());
    const auto pos = obj.value("platformPosition"_L1).toObject();
    section.setPlatformPositionBegin(pos.value("start"_L1).toDouble() / length);
    section.setPlatformPositionEnd(pos.value("end"_L1).toDouble() / length);

    const auto typeObj = obj.value("type"_L1).toObject();
    const auto cat = typeObj.value("category"_L1).toString();
    if (cat.compare("LOCOMOTIVE"_L1, Qt::CaseInsensitive) == 0) {
        section.setType(VehicleSection::Engine);
    } else if (cat.compare("POWERCAR"_L1, Qt::CaseInsensitive) == 0) {
        section.setType(VehicleSection::PowerCar);
    } else if (cat.contains("CONTROLCAR"_L1, Qt::CaseInsensitive)) {
        section.setType(VehicleSection::ControlCar);
    } else {
        section.setType(VehicleSection::PassengerCar);
    }

    // see https://en.wikipedia.org/wiki/UIC_classification_of_railway_coaches
    const auto num = obj.value("vehicleID"_L1).toString();
    const auto cls = typeObj.value("constructionType"_L1).toString();
    section.setClasses(UicRailwayCoach::coachClass(num, cls));
    section.setDeckCount(UicRailwayCoach::deckCount(num, cls));
    if (const auto type = UicRailwayCoach::type(num, cls); section.type() == VehicleSection::PassengerCar && type != VehicleSection::UnknownType) {
        section.setType(type);
    }
    auto features = UicRailwayCoach::features(num, cls);

    const auto equipmentArray = obj.value("amenities"_L1).toArray();
    for (const auto &equipmentV : equipmentArray) {
        const auto equipmentObj = equipmentV.toObject();
        const auto type = equipmentObj.value("type"_L1).toString();
        // TODO this has a status field, is this ever set?
        const auto it = std::lower_bound(std::begin(feature_map), std::end(feature_map), type, [](const auto &lhs, const auto &rhs) {
            return QLatin1StringView(lhs.name).compare(rhs, Qt::CaseInsensitive) < 0;
        });
        if (it != std::end(feature_map) && type.compare(QLatin1StringView((*it).name), Qt::CaseInsensitive) == 0) {
            Feature f{(*it).type};
            const auto amount = equipmentObj.value("amount"_L1).toInt();
            if (amount > 0) {
                f.setQuantity(amount);
            }
            FeatureUtil::add(features, std::move(f));
        } else {
            qDebug() << "Unhandled vehicle section equipment:" << type;
        }
    }
    section.setSectionFeatures(std::move(features));

    // TODO what is the actual value for closed sections?
    if (const auto status = obj.value("status"_L1).toString(); !status.isEmpty() && status != "OPEN"_L1) {
        section.setDisruptionEffect(Disruption::NoService);
    }

    auto sections = vehicle.takeSections();
    sections.push_back(section);
    vehicle.setSections(std::move(sections));
}

void DeutscheBahnVehicleLayoutParser::parsePlatformSection(Platform &platform, const QJsonObject &obj)
{
    PlatformSection section;
    section.setName(obj.value("name"_L1).toString());

    const double length = std::max(1, platform.length());
    section.setBegin(obj.value("start"_L1).toDouble() / length);
    section.setEnd(obj.value("end"_L1).toDouble() / length);

    auto sections = platform.takeSections();
    sections.push_back(section);
    platform.setSections(std::move(sections));
}

void DeutscheBahnVehicleLayoutParser::fillMissingPositions(Vehicle &vehicle, Platform &platform)
{
    if (vehicle.sections().empty()) {
        return;
    }

    const auto noPositions = std::all_of(vehicle.sections().begin(), vehicle.sections().end(), [](const auto &sec) {
        return sec.platformPositionBegin() == sec.platformPositionEnd();
    });

    if (!noPositions) {
        return;
    }

    auto sections = vehicle.takeSections();
    for (std::size_t i = 0; i < sections.size(); ++i) {
        sections[i].setPlatformPositionBegin((float)i / (float)sections.size());
        sections[i].setPlatformPositionEnd((float)(i + 1) / (float)sections.size());
    }
    vehicle.setSections(std::move(sections));
    if (platform.length() <= 0.0) {
        platform.setLength(vehicle.sections().size() * 25.0);
    }
}

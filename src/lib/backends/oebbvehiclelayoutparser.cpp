/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "oebbvehiclelayoutparser.h"

#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace KPublicTransport;

struct {
    const char *propName;
    VehicleSection::Feature feature;
} static constexpr const vehicle_section_feature_map[] = {
    { "speisewagen", VehicleSection::Restaurant },
    { "kinderspielwagen", VehicleSection::ToddlerArea },
    { "kinderkino", VehicleSection::ToddlerArea },
    { "rollstuhlgerecht", VehicleSection::WheelchairAccessible },
    { "fahrradmitnahme", VehicleSection::BikeStorage },
    { "ruhebereich", VehicleSection::SilentArea },
    { "infoPoint", VehicleSection::NoFeatures }, // TODO
};

static Vehicle::Direction parseDirection(const QJsonObject &haltepunktObj)
{
    const auto v = haltepunktObj.value(QLatin1String("departureDirectionSectorA"));
    if (v.isBool()) {
        return v.toBool() ? Vehicle::Forward : Vehicle::Backward;
    }
    return Vehicle::UnknownDirection;
}

bool OebbVehicleLayoutParser::parse(const QByteArray &data)
{
    const auto obj = QJsonDocument::fromJson(data).object();

    // platform
    Platform platform;
    const auto platformObj = obj.value(QLatin1String("platform")).toObject();
    platform.setName(platformObj.value(QLatin1String("platform")).toString());
    const auto sectorArray = platformObj.value(QLatin1String("sectors")).toArray();
    std::vector<PlatformSection> platformSections;
    platformSections.reserve(sectorArray.size());
    float prevSectorEnd = 0.0;
    for (const auto &sectorV : sectorArray) {
        const auto sectorObj = sectorV.toObject();
        PlatformSection section;
        section.setName(sectorObj.value(QLatin1String("sectorName")).toString());
        section.setBegin(prevSectorEnd);
        section.setEnd(prevSectorEnd += sectorObj.value(QLatin1String("length")).toDouble());
        platformSections.push_back(section);
    }
    platform.setLength(prevSectorEnd);
    // TODO platform.egress lists relevant features like escalators/elevators on the platform

    // vehicle
    Vehicle vehicle;
    const auto haltepunktObj = platformObj.value(QLatin1String("haltepunkt")).toObject();
    vehicle.setDirection(parseDirection(haltepunktObj));

    const auto wagonsA = obj.value(QLatin1String("wagons")).toArray();
    std::vector<VehicleSection> vehicleSections;
    vehicleSections.reserve(wagonsA.size());
    float prevVehicleEnd = haltepunktObj.value(QLatin1String("haltepunktInMeters")).toDouble(); // TODO check departureDirectionSectorA, how does this look like for "false"?
    for (const auto &wagonV : wagonsA) {
        const auto wagonObj = wagonV.toObject();
        VehicleSection section;
        if (wagonObj.value(QLatin1String("triebfahrzeug")).toBool()) {
            section.setType(VehicleSection::Engine);
            section.setConnectedSides(VehicleSection::NoSide);
        } else {
            section.setName(QString::number(wagonObj.value(QLatin1String("ordnungsNummer")).toInt()));
            // TODO: autoreizezug -> we lack support for car carrying cars
            section.setType(VehicleSection::PassengerCar);
            VehicleSection::Features features = {};
            for (const auto &map : vehicle_section_feature_map) {
                if (wagonObj.value(QLatin1String(map.propName)).toBool()) {
                    features |= map.feature;
                }
            }
            section.setFeatures(features);

            VehicleSection::Classes classes = {};
            if (wagonObj.value(QLatin1String("secondClass")).toInt() > 0) {
                classes |= VehicleSection::SecondClass;
            }
            if (wagonObj.value(QLatin1String("firstClass")).toInt() > 0 || wagonObj.value(QLatin1String("businessClass")).toInt() > 0) {
                classes |= VehicleSection::FirstClass;
            }
            section.setClasses(classes);

            // TODO we lack support for sleeper cars
            const auto sleeperCar = wagonObj.value(QLatin1String("schlafplaetze")).toInt() > 0 || wagonObj.value(QLatin1String("liegeplaetze")).toInt() > 0;

            // sort out Restaurant feature vs. dedicated RestaurantCar
            if (classes == VehicleSection::UnknownClass && !sleeperCar && (features & VehicleSection::Restaurant)) {
                section.setType(VehicleSection::RestaurantCar);
            }
        }

        section.setPlatformPositionBegin(prevVehicleEnd);
        section.setPlatformPositionEnd(prevVehicleEnd += (wagonObj.value(QLatin1String("laengeUeberPuffer")).toInt() / 100.0));

        vehicleSections.push_back(section);
    }
    // guess platform length if we didn't get platform sectors
    platform.setLength(std::max<int>(platform.length(), prevVehicleEnd));

    // adjust vehicle and platform section positions to normalized platform coordinates
    if (platform.length() > 0.0) {
        for (auto &sec : platformSections) {
            sec.setBegin(sec.begin() / platform.length());
            sec.setEnd(sec.end() / platform.length());
        }
        for (auto &sec : vehicleSections) {
            sec.setPlatformPositionBegin(sec.platformPositionBegin() / platform.length());
            sec.setPlatformPositionEnd(sec.platformPositionEnd() / platform.length());
        }
    }

    vehicle.setSections(std::move(vehicleSections));
    platform.setSections(std::move(platformSections));

    // departure
    // TODO recover destination when possible
    Location stop;
    const auto trainStationObj = obj.value(QLatin1String("trainStation")).toObject();
    stop.setName(trainStationObj.value(QLatin1String("name")).toString());
    stop.setIdentifier(QStringLiteral("ibnr"), trainStationObj.value(QLatin1String("evaCode")).toString());
    stop.setType(Location::Stop);
    Line line;
    line.setMode(Line::LongDistanceTrain); // TODO is this actually true for ÖBB?
    line.setName(obj.value(QLatin1String("trainName")).toString());
    Route route;
    route.setLine(line);
    stopover.setRoute(route);
    stopover.setStopPoint(stop);
    stopover.setScheduledArrivalTime(QDateTime::fromString(obj.value(QLatin1String("scheduledArrival")).toString(), Qt::ISODate));
    stopover.setScheduledDepartureTime(QDateTime::fromString(obj.value(QLatin1String("scheduledDeparture")).toString(), Qt::ISODate));
    stopover.setScheduledPlatform(platform.name());
    stopover.setVehicleLayout(std::move(vehicle));
    stopover.setPlatformLayout(std::move(platform));

    return !platform.isEmpty() || !vehicle.isEmpty()
         || stopover.scheduledArrivalTime().isValid() || stopover.scheduledDepartureTime().isValid();
}

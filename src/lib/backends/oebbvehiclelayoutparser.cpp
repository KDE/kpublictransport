/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "oebbvehiclelayoutparser.h"
#include "uic/uicrailwaycoach.h"

#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace KPublicTransport;

struct {
    const char *propName;
    VehicleSection::Feature feature;
    VehicleSection::Class coachClass;
} static constexpr const vehicle_section_feature_map[] = {
    { "capacityBusinessClass", VehicleSection::NoFeatures, VehicleSection::FirstClass },
    { "capacityFirstClass", VehicleSection::NoFeatures, VehicleSection::FirstClass },
    { "capacitySecondClass", VehicleSection::NoFeatures, VehicleSection::SecondClass },
    { "capacityCouchette", VehicleSection::NoFeatures, VehicleSection::UnknownClass }, // TODO
    { "capacitySleeper", VehicleSection::NoFeatures, VehicleSection::UnknownClass }, // TODO
    { "capacityWheelChair", VehicleSection::WheelchairAccessible, VehicleSection::UnknownClass },
    { "capacityBicycle", VehicleSection::BikeStorage, VehicleSection::UnknownClass },
    { "isBicycleAllowed", VehicleSection::BikeStorage, VehicleSection::UnknownClass },
    { "isWheelChairAccessible", VehicleSection::WheelchairAccessible, VehicleSection::UnknownClass },
    { "hasWifi", VehicleSection::NoFeatures, VehicleSection::UnknownClass }, // TODO
    { "isInfoPoint", VehicleSection::NoFeatures, VehicleSection::UnknownClass }, // TODO
    { "isChildCinema", VehicleSection::ToddlerArea, VehicleSection::UnknownClass },
    { "isDining", VehicleSection::Restaurant, VehicleSection::UnknownClass },
    { "isQuietZone", VehicleSection::SilentArea, VehicleSection::UnknownClass },
};

struct {
    const char *modeName;
    Line::Mode mode;
} static constexpr const line_mode_map[] = {
    { "RJ", Line::LongDistanceTrain },
    { "NJ", Line::LongDistanceTrain },
    { "RE", Line::LocalTrain },
    { "S",  Line::RapidTransit },
    { "IC", Line::LongDistanceTrain },
    { "EC", Line::LongDistanceTrain },
};

static Vehicle::Direction parseDirection(const QJsonObject &haltepunktObj)
{
    const auto v = haltepunktObj.value(QLatin1String("departureTowardsFirstSector"));
    if (v.isBool()) {
        return v.toBool() ? Vehicle::Forward : Vehicle::Backward;
    }
    return Vehicle::UnknownDirection;
}

static QDateTime parseDateTime(const QDate &date, const QJsonValue &timeVal)
{
    const auto timeObj = timeVal.toObject();
    QDateTime dt(date, {0, 0});
    dt = dt.addSecs(timeObj.value(QLatin1String("days")).toInt() * 24 * 3600);
    dt = dt.addSecs(timeObj.value(QLatin1String("hours")).toInt() * 3600);
    dt = dt.addSecs(timeObj.value(QLatin1String("minutes")).toInt() * 60 );
    return dt;
}

static QString parsePlatformName(const QJsonObject &platformObj, const QJsonObject &sectorsObj, const char *propName)
{
    const auto nameVal = platformObj.value(QLatin1String(propName));
    if (nameVal.isUndefined()) {
        return {};
    }
    const auto name = QString::number(nameVal.toInt());
    if (name.isEmpty()) {
        return name;
    }

    const auto sectorName = sectorsObj.value(QLatin1String(propName)).toString();
    if (!sectorName.isEmpty()) {
        return name + QLatin1Char(' ') + sectorName;
    }
    return name;
}

bool OebbVehicleLayoutParser::parse(const QByteArray &data)
{
    const auto obj = QJsonDocument::fromJson(data).object();

    // platform
    Platform platform;
    const auto platformObj = obj.value(QLatin1String("platform")).toObject();
    const auto platformNameVal = platformObj.value(QLatin1String("platform"));
    if (!platformNameVal.isUndefined()) {
        platform.setName(QString::number(platformNameVal.toInt()));
    }
    const auto sectorArray = platformObj.value(QLatin1String("sectors")).toArray();
    std::vector<PlatformSection> platformSections;
    platformSections.reserve(sectorArray.size());
    float prevSectorEnd = 0.0;
    for (const auto &sectorV : sectorArray) {
        const auto sectorObj = sectorV.toObject();
        PlatformSection section;
        section.setName(sectorObj.value(QLatin1String("name")).toString());
        section.setBegin(prevSectorEnd);
        section.setEnd(prevSectorEnd += sectorObj.value(QLatin1String("length")).toDouble());
        platformSections.push_back(section);
    }
    platform.setLength(std::max<float>(prevSectorEnd, platformObj.value(QLatin1String("length")).toDouble()));
    // TODO accesses lists relevant features like escalators/elevators on the platform

    // vehicle
    Vehicle vehicle;
    const auto trainOnPlatform = obj.value(QLatin1String("trainOnPlatform")).toObject();
    vehicle.setDirection(parseDirection(trainOnPlatform));
    const auto trainObj = obj.value(QLatin1String("train")).toObject();
    const auto wagonsA = trainObj.value(QLatin1String("wagons")).toArray();
    std::vector<VehicleSection> vehicleSections;
    vehicleSections.reserve(wagonsA.size());
    float prevVehicleEnd = trainOnPlatform.value(QLatin1String("position")).toDouble(); // TODO check how this looks like for backward departure
    for (const auto &wagonV : wagonsA) {
        const auto wagonObj = wagonV.toObject();
        VehicleSection section;
        const auto uicNum = wagonObj.value(QLatin1String("uicNumber")).toString();
        const auto uicCls = wagonObj.value(QLatin1String("kind")).toString();
        section.setType(UicRailwayCoach::type(uicNum, uicCls));
        section.setDeckCount(UicRailwayCoach::deckCount(uicNum, uicCls));

        if (section.type() == VehicleSection::Engine) {
            section.setConnectedSides(VehicleSection::NoSide);
        } else {
            const auto ranking = wagonObj.value(QLatin1String("ranking")).toInt();
            if (ranking > 0) {
                section.setName(QString::number(ranking));
            }
            auto cls = UicRailwayCoach::coachClass(uicNum, uicCls);
            auto features = UicRailwayCoach::features(uicNum, uicCls);
            for (const auto &map : vehicle_section_feature_map) {
                const auto val = wagonObj.value(QLatin1String(map.propName));
                if ((val.isBool() && val.toBool()) || (val.isDouble() && val.toInt() > 0)) {
                    cls |= map.coachClass;
                    features |= map.feature;
                }
            }
            section.setClasses(cls);
            section.setFeatures(features);
        }

        section.setPlatformPositionBegin(prevVehicleEnd);
        section.setPlatformPositionEnd(prevVehicleEnd += wagonObj.value(QLatin1String("lengthOverBuffers")).toDouble());

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
    const auto timeTableInfo = obj.value(QLatin1String("timeTableInfo")).toObject();
    stop.setName(timeTableInfo.value(QLatin1String("stationName")).toString());
    stop.setType(Location::Stop);
    Line line;
    line.setName(timeTableInfo.value(QLatin1String("trainName")).toString());
    line.setMode(Line::Train);
    for (const auto &m : line_mode_map) {
        if (line.name().startsWith(QLatin1String(m.modeName))) {
            line.setMode(m.mode);
            break;
        }
    }
    Route route;
    route.setLine(line);
    stopover.setRoute(route);
    stopover.setStopPoint(stop);

    const auto date = QDate::fromString(timeTableInfo.value(QLatin1String("date")).toString(), QStringLiteral("yyyy-MM-dd"));
    const auto timeObj = timeTableInfo.value(QLatin1String("time")).toObject();
    stopover.setScheduledDepartureTime(parseDateTime(date, timeObj.value(QLatin1String("scheduled"))));
    stopover.setExpectedDepartureTime(parseDateTime(date, timeObj.value(QLatin1String("reported"))));

    {
        const auto platformObj = timeTableInfo.value(QLatin1String("platform")).toObject();
        const auto sectorsObj = timeTableInfo.value(QLatin1String("sectors")).toObject();
        stopover.setScheduledPlatform(parsePlatformName(platformObj, sectorsObj, "scheduled"));
        stopover.setExpectedPlatform(parsePlatformName(platformObj, sectorsObj, "reported"));
    }

    stopover.setVehicleLayout(std::move(vehicle));
    stopover.setPlatformLayout(std::move(platform));

    return !platform.isEmpty() || !vehicle.isEmpty()
         || stopover.scheduledArrivalTime().isValid() || stopover.scheduledDepartureTime().isValid();
}

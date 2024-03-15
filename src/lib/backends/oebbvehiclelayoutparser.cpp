/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "oebbvehiclelayoutparser.h"
#include "datatypes/featureutil_p.h"
#include "uic/uicrailwaycoach.h"

#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

struct {
    const char *propName;
    Feature::Type feature;
    VehicleSection::Class coachClass;
    Feature::Availability postitive;
    Feature::Availability negative;
} static constexpr const vehicle_section_feature_map[] = {
    { "capacityBusinessClass", Feature::NoFeature, VehicleSection::FirstClass, Feature::Unknown, Feature::Unknown },
    { "capacityFirstClass", Feature::NoFeature, VehicleSection::FirstClass, Feature::Unknown, Feature::Unknown },
    { "capacitySecondClass", Feature::NoFeature, VehicleSection::SecondClass, Feature::Unknown, Feature::Unknown },
    { "capacityCouchette", Feature::NoFeature, VehicleSection::UnknownClass, Feature::Unknown, Feature::Unknown }, // TODO
    { "capacitySleeper", Feature::NoFeature, VehicleSection::UnknownClass, Feature::Unknown, Feature::Unknown }, // TODO
    { "capacityWheelChair", Feature::WheelchairAccessible, VehicleSection::UnknownClass, Feature::Available, Feature::Unknown }, // 0 capacity + isWheelChairAccessible = true occur
    { "capacityBicycle", Feature::BikeStorage, VehicleSection::UnknownClass, Feature::Available, Feature::Unknown }, // any conflicting combination of those two occurs
    { "isBicycleAllowed", Feature::BikeStorage, VehicleSection::UnknownClass, Feature::Available, Feature::Unknown },
    { "isWheelChairAccessible", Feature::WheelchairAccessible, VehicleSection::UnknownClass, Feature::Available, Feature::Unknown },
    { "hasWifi", Feature::WiFi, VehicleSection::UnknownClass, Feature::Available, Feature::Unavailable },
    { "isInfoPoint", Feature::InformationPoint, VehicleSection::UnknownClass, Feature::Available, Feature::Unknown },
    { "isPlayZone", Feature::FamilyArea, VehicleSection::UnknownClass, Feature::Available, Feature::Unknown },
    { "isChildCinema", Feature::FamilyArea, VehicleSection::UnknownClass, Feature::Available, Feature::Unknown },
    { "isDining", Feature::Restaurant, VehicleSection::UnknownClass, Feature::Available, Feature::Unknown },
    { "isQuietZone", Feature::SilentArea, VehicleSection::UnknownClass, Feature::Available, Feature::Unknown },
    // isLocked
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

struct {
    int flag;
    Feature::Type feature;
} static constexpr const feature_map[] = {
    { 1, Feature::BikeStorage }, // Fahrradabstellplatz
    { 2, Feature::WheelchairAccessible }, // Rollstuhlplatz
    { 8, Feature::InformationPoint }, // Info-Point/Defibrillator
    { 16, Feature::FamilyArea }, // Familienzone
    { 32, Feature::FamilyArea }, // Familienzone
    { 64, Feature::Restaurant },
    { 128, Feature::SilentArea }, // Ruhezone
    { 256, Feature::NoFeature }, // Niederflur-Wagen
    { 512, Feature::NoFeature }, // Wagen abgesperrt
};

struct {
    int kind;
    VehicleSection::Type type;
} static constexpr const kind_map[] = {
    { 0, VehicleSection::PassengerCar },
    { 1, VehicleSection::ControlCar },
    { 256, VehicleSection::Engine },
};

static Vehicle::Direction parseDirection(const QJsonObject &haltepunktObj)
{
    const auto v = haltepunktObj.value("departureTowardsFirstSector"_L1);
    if (v.isBool()) {
        return v.toBool() ? Vehicle::Forward : Vehicle::Backward;
    }
    return Vehicle::UnknownDirection;
}

static QDateTime parseDateTime(const QDate &date, const QJsonValue &timeVal)
{
    if (timeVal.isObject()) {
        const auto timeObj = timeVal.toObject();
        QDateTime dt(date, {0, 0});
        dt = dt.addSecs(timeObj.value("days"_L1).toInteger() * 24 * 3600);
        dt = dt.addSecs(timeObj.value("hours"_L1).toInteger() * 3600);
        dt = dt.addSecs(timeObj.value("minutes"_L1).toInteger() * 60 );
        return dt;
    }
    if (timeVal.isString()) {
        QDateTime dt(date, QTime::fromString(QStringView(timeVal.toString()).mid(2)));
        // TODO what does the leading 0. mean? extra day for wrap around at midnight?
        return dt;
    }

    return {};
}

static QString parsePlatformName(const QJsonObject &platformObj, const QJsonObject &sectorsObj, const char *propName)
{
    const auto nameVal = platformObj.value(QLatin1String(propName));
    if (nameVal.isUndefined()) {
        return {};
    }
    auto name = QString::number(nameVal.toInt());
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
    const auto platformObj = obj.value("platform"_L1).toObject();
    const auto platformNameVal = platformObj.value("platform"_L1);
    if (!platformNameVal.isUndefined()) {
        platform.setName(QString::number(platformNameVal.toInt()));
    }
    const auto sectorArray = platformObj.value("sectors"_L1).toArray();
    std::vector<PlatformSection> platformSections;
    platformSections.reserve(sectorArray.size());
    float prevSectorEnd = 0.0;
    for (const auto &sectorV : sectorArray) {
        const auto sectorObj = sectorV.toObject();
        PlatformSection section;
        section.setName(sectorObj.value("name"_L1).toString());
        section.setBegin(prevSectorEnd);
        section.setEnd(prevSectorEnd += sectorObj.value("length"_L1).toDouble());
        platformSections.push_back(section);
    }
    platform.setLength(std::max<float>(prevSectorEnd, platformObj.value("length"_L1).toDouble()));
    // TODO accesses lists relevant features like escalators/elevators on the platform

    // vehicle
    Vehicle vehicle;
    const auto trainOnPlatform = obj.value("trainOnPlatform"_L1).toObject();
    vehicle.setDirection(parseDirection(trainOnPlatform));
    const auto trainObj = obj.value("train"_L1).toObject();
    const auto wagonsA = trainObj.value("wagons"_L1).toArray();
    std::vector<VehicleSection> vehicleSections;
    vehicleSections.reserve(wagonsA.size());
    float prevVehicleEnd = (float)trainOnPlatform.value("position"_L1).toDouble(); // TODO check how this looks like for backward departure
    bool vehicleForward = true;

    const auto stoppingPointObj = platformObj.value("stoppingPoint"_L1).toObject();
    if (!stoppingPointObj.isEmpty()) {
        prevVehicleEnd = (float)stoppingPointObj.value("distance"_L1).toDouble();
        vehicle.setDirection(stoppingPointObj.value("direction"_L1).toString() == "Back"_L1 ? Vehicle::Backward : Vehicle::Forward);
        if (vehicle.direction() == Vehicle::Backward && stoppingPointObj.value("position"_L1).toString() == "Top"_L1) {
            vehicleForward = false;
        }
    }

    for (const auto &wagonV : wagonsA) {
        const auto wagonObj = wagonV.toObject();
        VehicleSection section;
        const auto uicNum = wagonObj.value("uicNumber"_L1).toString();
        const auto kind = wagonObj.value("kind"_L1);
        const auto uicCls = kind.toString();
        section.setType(UicRailwayCoach::type(uicNum, uicCls));
        section.setDeckCount(UicRailwayCoach::deckCount(uicNum, uicCls));

        if (section.type() == VehicleSection::Engine) {
            section.setConnectedSides(VehicleSection::NoSide);
        } else {
            const auto ranking = wagonObj.value("ranking"_L1).toInt();
            if (ranking > 0) {
                section.setName(QString::number(ranking));
            }
            auto cls = UicRailwayCoach::coachClass(uicNum, uicCls);
            auto features = UicRailwayCoach::features(uicNum, uicCls);
            for (const auto &map : vehicle_section_feature_map) {
                const auto val = wagonObj.value(QLatin1String(map.propName));
                if (!val.isBool() && !val.isDouble()) {
                    continue;
                }
                if ((val.isBool() && val.toBool()) || (val.isDouble() && val.toInt() > 0)) {
                    cls |= map.coachClass;
                }
                if (map.feature != Feature::NoFeature) {
                    Feature f(map.feature, Feature::Unknown);
                    if (val.isBool()) {
                        f.setAvailability(val.toBool() ? map.postitive : map.negative);
                    } else if (val.isDouble()) {
                        const auto quantity = val.toInt();
                        f.setAvailability(quantity ? map.postitive : map.negative);
                        f.setQuantity(quantity);
                    }
                    if (f.availability() != Feature::Unknown) {
                        FeatureUtil::add(features, std::move(f));
                    }
                }
            }

            if (const auto featureVal = wagonObj.value("features"_L1); featureVal.isDouble()) {
                const auto flags = featureVal.toInt();
                for (const auto &m :feature_map) {
                    if (m.flag & flags && m.feature != Feature::NoFeature) {
                        FeatureUtil::add(features, Feature(m.feature));
                    }
                }
            }

            if (section.type() == VehicleSection::UnknownType && kind.isDouble()) {
                const auto kindNum = kind.toInt();
                const auto it = std::find_if(std::begin(kind_map), std::end(kind_map), [kindNum](auto m) { return m.kind == kindNum; });
                if (it != std::end(kind_map)) {
                    section.setType((*it).type);
                }
            }

            section.setClasses(cls);
            section.setSectionFeatures(std::move(features));
        }

        if (vehicleForward) {
            section.setPlatformPositionBegin(prevVehicleEnd);
            section.setPlatformPositionEnd(prevVehicleEnd += (float)wagonObj.value("lengthOverBuffers"_L1).toDouble());
        } else {
            section.setPlatformPositionEnd(prevVehicleEnd);
            section.setPlatformPositionBegin(prevVehicleEnd -= (float)wagonObj.value("lengthOverBuffers"_L1).toDouble());
        }

        vehicleSections.push_back(section);
    }
    // guess platform length if we didn't get platform sectors
    if (platform.length() == 0 && vehicleForward) {
        platform.setLength((int)prevVehicleEnd);
    }

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
    const auto timeTableInfo = obj.value("timeTableInfo"_L1).toObject();
    stop.setName(timeTableInfo.value("stationName"_L1).toString());
    stop.setType(Location::Stop);
    Line line;
    line.setName(timeTableInfo.value("trainName"_L1).toString());
    if (line.name().isEmpty()) {
        line.setName(timeTableInfo.value("renderedTrainName"_L1).toString());
    }
    line.setMode(Line::Train);
    for (const auto &m : line_mode_map) {
        if (line.name().startsWith(QLatin1String(m.modeName))) {
            line.setMode(m.mode);
            break;
        }
    }
    Route route;
    if (line.mode() == Line::LocalTrain || line.mode() == Line::RapidTransit) {
        route.setName(QString::number(timeTableInfo.value("trainNr"_L1).toInt()));
    }
    route.setLine(line);
    stopover.setRoute(route);
    stopover.setStopPoint(stop);

    const auto date = QDate::fromString(timeTableInfo.value("date"_L1).toString(), u"yyyy-MM-dd"_s);
    const auto timeVal = timeTableInfo.value("time"_L1);
    stopover.setScheduledDepartureTime(parseDateTime(date, timeVal.isObject() ? timeVal.toObject().value("scheduled"_L1) : timeVal.toString()));
    stopover.setExpectedDepartureTime(parseDateTime(date, timeVal.isObject() ? timeVal.toObject().value("reported"_L1) : timeVal.toString()));

    {
        const auto platformVal = timeTableInfo.value("platform"_L1);
        if (platformVal.isObject()) {
            const auto platformObj = platformVal.toObject();
            const auto sectorsObj = timeTableInfo.value("sectors"_L1).toObject();
            stopover.setScheduledPlatform(parsePlatformName(platformObj, sectorsObj, "scheduled"));
            stopover.setExpectedPlatform(parsePlatformName(platformObj, sectorsObj, "reported"));
        } else if (platformVal.isString()) {
            stopover.setScheduledPlatform(platformVal.toString());
        }
    }

    stopover.setVehicleLayout(std::move(vehicle));
    stopover.setPlatformLayout(std::move(platform));

    return !platform.isEmpty() || !vehicle.isEmpty()
         || stopover.scheduledArrivalTime().isValid() || stopover.scheduledDepartureTime().isValid();
}

/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasvehiclelayoutparser.h"

#include <KPublicTransport/Platform>
#include <KPublicTransport/Vehicle>

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QXmlStreamReader>

using namespace KPublicTransport;

static VehicleSection::Feature attributeCodeToFeature(const QString &code)
{
    struct {
        const char *code;
        VehicleSection::Feature feature;
    } static constexpr const code_feature_map[] = {
        { "AbteilBusiness", VehicleSection::NoFeatures }, // TODO
        { "AbteilFamilien", VehicleSection::NoFeatures }, // TODO
        { "AbteilKinderwagen", VehicleSection::NoFeatures }, // TODO
        { "AbteilRollstuhl", VehicleSection::WheelchairAccessible },
        { "AbteilVeloPl", VehicleSection::BikeStorage },
        { "AbteilVeloRes", VehicleSection::BikeStorage },
        { "FA", VehicleSection::NoFeatures }, // TODO family area
        { "NiederflurEinstieg", VehicleSection::NoFeatures }, // TODO
    };

    for (const auto &map : code_feature_map) {
        if (code == QLatin1String(map.code)) {
            return map.feature;
        }
    }

    qDebug() << "Unknown vehicle section feature code:" << code;
    return VehicleSection::NoFeatures;
}

static VehicleSection::Classes typeToClasses(const QString &type)
{
    if (type == QLatin1Char('1')) {
        return VehicleSection::FirstClass;
    }
    if (type == QLatin1Char('2') || type == QLatin1String("W2")) {
        return VehicleSection::SecondClass;
    }
    return VehicleSection::UnknownClass;
}

static VehicleSection::Type typeToType(const QString &type)
{
    if (type == QLatin1String("WR")) {
        return VehicleSection::RestaurantCar;
    }
    if (type == QLatin1String("LK")) {
        return VehicleSection::Engine;
    }
    return VehicleSection::PassengerCar;
}

std::vector<Vehicle> HafasVehicleLayoutParser::parseVehicleLayouts(const QJsonObject &commonObj)
{
    // stcLiL - type map
    const auto stcLiL = commonObj.value(QLatin1String("stcLiL")).toArray();

    // stcCarL - vehicle section list
    const auto stcCarL = commonObj.value(QLatin1String("stcCarL")).toArray();
    std::vector<VehicleSection> cars;
    cars.reserve(stcCarL.size());
    for (const auto &stcCarV : stcCarL) {
        const auto stcCarObj = stcCarV.toObject();

        VehicleSection car;
        VehicleSection::Features features = {};
        car.setName(stcCarObj.value(QLatin1String("number")).toString());

        const auto type = stcCarObj.value(QLatin1String("type")).toInt();
        if (type >= 0 && type < stcLiL.size()) {
            const auto id = stcLiL.at(type).toObject().value(QLatin1String("id")).toString();
            car.setType(typeToType(id));
            car.setClasses(typeToClasses(id));
            // TODO type == FA?
        }

        const auto attrL = stcCarObj.value(QLatin1String("attrL")).toArray();
        for (const auto &attrV : attrL) {
            features |= attributeCodeToFeature(attrV.toObject().value(QLatin1String("c")).toString());
        }

        car.setFeatures(features);
        cars.push_back(std::move(car));
    }

    // stcGrpL - vehicles
    const auto stcGrpL = commonObj.value(QLatin1String("stcGrpL")).toArray();
    std::vector<Vehicle> vehicles;
    vehicles.reserve(stcGrpL.size());
    for (const auto stcGrpV : stcGrpL) {
        const auto carL = stcGrpV.toObject().value(QLatin1String("carL")).toArray();
        std::vector<VehicleSection> sections;
        sections.reserve(carL.size());
        for (const auto carV : carL) {
            const auto carIdx = carV.toInt();
            if (carIdx >= 0 && carIdx < (int)cars.size()) {
                sections.push_back(cars[carIdx]);
            }
        }

        Vehicle vehicle;
        vehicle.setSections(std::move(sections));
        vehicles.push_back(std::move(vehicle));
    }

    return vehicles;
}

static void parseTrainFormationCars(std::vector<VehicleSection> &vehicleSections, const QJsonArray &cars)
{
    vehicleSections.reserve(vehicleSections.size() + cars.size());
    for (const auto &carV : cars) {
        const auto carObj = carV.toObject();
        VehicleSection sec;
        sec.setName(carObj.value(QLatin1String("number")).toString());

        const auto type = carObj.value(QLatin1String("type")).toString();
        sec.setType(typeToType(type));
        sec.setPlatformSectionName(carObj.value(QLatin1String("section")).toString());
        sec.setClasses(typeToClasses(type));
        // TODO type == FA

        // TODO there are also translated names for those features we could use
        VehicleSection::Features features = {};
        const auto attrs = carObj.value(QLatin1String("CarAttributes")).toObject().value(QLatin1String("Attr"));
        if (attrs.isObject()) {
            features |= attributeCodeToFeature(attrs.toObject().value(QLatin1String("code")).toString());
        } else if (attrs.isArray()) {
            const auto attrsA = attrs.toArray();
            for (const auto &attrV : attrsA) {
                features |= attributeCodeToFeature(attrV.toObject().value(QLatin1String("code")).toString());
            }
        }
        sec.setFeatures(features);

        vehicleSections.push_back(sec);
    }
}

Vehicle HafasVehicleLayoutParser::parseTrainFormation(const QByteArray &data)
{
    QJsonParseError parserError;
    const auto jsonEndIdx = data.lastIndexOf('}') + 1;
    const auto sformation = QJsonDocument::fromJson(data.mid(0, jsonEndIdx), &parserError).object().value(QLatin1String("SFormation")).toObject();
    if (parserError.error != QJsonParseError::NoError) {
        qDebug() << parserError.errorString();
    }

    const auto trainGroups = sformation.value(QLatin1String("TrainGroups")).toObject();
    const auto trainGroup = trainGroups.value(QLatin1String("TrainGroup"));
    std::vector<VehicleSection> vehicleSections;
    if (trainGroup.isObject()) {
        const auto cars = trainGroup.toObject().value(QLatin1String("Car")).toArray();
        parseTrainFormationCars(vehicleSections, cars);
    } else if (trainGroup.isArray()) {
        const auto trainGroupA = trainGroup.toArray();
        if (!trainGroupA.isEmpty()) {
            // the following array entries are how the train changes over time, something we can't model yet?
            const auto cars = trainGroupA.at(0).toObject().value(QLatin1String("Car")).toArray();
            parseTrainFormationCars(vehicleSections, cars);
        }
    }

    Vehicle vehicle;
    vehicle.setSections(std::move(vehicleSections));
    return vehicle;
}

std::vector<Platform> HafasVehicleLayoutParser::parsePlatforms(const QJsonObject &commonObj)
{
    const auto tcpdL = commonObj.value(QLatin1String("tcpdL")).toArray();
    std::vector<Platform> platforms;
    platforms.reserve(tcpdL.size());

    for (const auto &tcpdV : tcpdL) {
        const auto tcpdObj = tcpdV.toObject();
        const auto sectors = tcpdObj.value(QLatin1String("PS")).toArray();

        Platform platform;
        std::vector<PlatformSection> platformSections;
        platformSections.reserve(sectors.size());

        for (const auto &secV : sectors) {
            const auto secObj = secV.toObject();
            PlatformSection section;
            section.setName(secObj.value(QLatin1String("n")).toString());
            section.setBegin(secObj.value(QLatin1String("s")).toInt());
            section.setEnd(secObj.value(QLatin1String("e")).toInt());

            platform.setLength(std::max<int>(section.begin(), std::max<int>(section.end(), platform.length())));
            platformSections.push_back(std::move(section));
        }

        // scale sector lengths to relative coordinates
        if (platform.length() > 0.0) {
            for (auto &sec : platformSections) {
                sec.setBegin(sec.begin() / platform.length());
                sec.setEnd(sec.end() / platform.length());
            }
        }
        // we don't have an absolute value as the actual value we get here are of an unknown unit
        platform.setLength(1.0);

        platform.setSections(std::move(platformSections));
        platforms.push_back(std::move(platform));
    }

    return platforms;
}

Platform HafasVehicleLayoutParser::parsePlatformSectors(const QByteArray &data)
{
    Platform platform;
    std::vector<PlatformSection> platformSections;

    QXmlStreamReader reader(data);
    while (!reader.atEnd()) {
        if (reader.readNext() != QXmlStreamReader::StartElement) {
            continue;
        }
        if (reader.name() == QLatin1String("PS")) {
            PlatformSection sec;
            sec.setName(reader.attributes().value(QLatin1String("n")).toString());
            sec.setBegin(reader.attributes().value(QLatin1String("s")).toInt());
            sec.setEnd(reader.attributes().value(QLatin1String("e")).toInt());

            platform.setLength(std::max<int>(sec.begin(), std::max<int>(sec.end(), platform.length())));
            platformSections.push_back(std::move(sec));
        }
    }
    if (reader.hasError()) {
        qDebug() << reader.errorString();
    }

    // scale sector lengths to relative coordinates
    if (platform.length() > 0.0) {
        for (auto &sec : platformSections) {
            sec.setBegin(sec.begin() / platform.length());
            sec.setEnd(sec.end() / platform.length());
        }
    }
    // we don't have an absolute value as the actual value we get here are of an unknown unit
    platform.setLength(1.0);

    platform.setSections(std::move(platformSections));
    return platform;
}

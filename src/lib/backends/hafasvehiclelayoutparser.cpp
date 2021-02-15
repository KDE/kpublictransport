/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasvehiclelayoutparser.h"

#include <KPublicTransport/Platform>
#include <KPublicTransport/Vehicle>

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
    };

    for (const auto &map : code_feature_map) {
        if (code == QLatin1String(map.code)) {
            return map.feature;
        }
    }

    qDebug() << "Unknown vehicle section feature code:" << code;
    return VehicleSection::NoFeatures;
}

Vehicle HafasVehicleLayoutParser::parseTrainFormation(const QByteArray &data)
{
    const auto sformation = QJsonDocument::fromJson(data).object().value(QLatin1String("SFormation")).toObject();
    const auto trainGroups = sformation.value(QLatin1String("TrainGroups")).toObject();
    // TODO how does this look for multiple train groups?
    const auto trainGroup = trainGroups.value(QLatin1String("TrainGroup")).toObject();
    const auto cars = trainGroup.value(QLatin1String("Car")).toArray();

    std::vector<VehicleSection> vehicleSections;
    vehicleSections.reserve(cars.size());
    for (const auto &carV : cars) {
        const auto carObj = carV.toObject();
        VehicleSection sec;
        sec.setName(carObj.value(QLatin1String("number")).toString());
        sec.setType(VehicleSection::PassengerCar);

        const auto type = carObj.value(QLatin1String("type")).toString();
        if (type == QLatin1String("LK")) {
            sec.setType(VehicleSection::Engine);
        } else if (type == QLatin1String("1")) {
            sec.setClasses(VehicleSection::FirstClass);
        } else if (type == QLatin1String("2")) {
            sec.setClasses(VehicleSection::SecondClass);
        }
        // TODO type == FA

        // TODO how do we make section information to coordinates?

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

    Vehicle vehicle;
    vehicle.setSections(std::move(vehicleSections));
    return vehicle;
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

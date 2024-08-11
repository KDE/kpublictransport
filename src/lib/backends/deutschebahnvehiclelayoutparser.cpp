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

bool DeutscheBahnVehicleLayoutParser::parse(const QByteArray &data)
{
    const auto doc = QJsonDocument::fromJson(data);

    const auto err = doc.object().value(QLatin1String("error")).toObject();
    if (!err.isEmpty()) {
        error = err.value(QLatin1String("id")).toInt() == 404 ? Reply::NotFoundError : Reply::UnknownError;
        errorMessage = err.value(QLatin1String("msg")).toString();
        return false;
    }

    // vehicles
    Vehicle vehicle;
    const auto obj = doc.object().value(QLatin1String("data")).toObject().value(QLatin1String("istformation")).toObject();
    const auto trainType = obj.value(QLatin1String("zuggattung")).toString() ;
    vehicle.setName(trainType + QLatin1Char(' ') + obj.value(QLatin1String("zugnummer")).toString());

    // TODO dobule segment ICE trains technically are two Vehicle objects...
    const auto vehiclesArray = obj.value(QLatin1String("allFahrzeuggruppe")).toArray();
    for (const auto &vehicleV : vehiclesArray) {
        const auto sectionsArray = vehicleV.toObject().value(QLatin1String("allFahrzeug")).toArray();
        for (const auto &sectionV : sectionsArray) {
            parseVehicleSection(vehicle, sectionV.toObject());
        }
    }
    // direction is implied by section order
    if (vehicle.sections().size() >= 2) {
        vehicle.setDirection(vehicle.sections()[0].platformPositionBegin() < vehicle.sections()[1].platformPositionBegin() ? Vehicle::Forward : Vehicle::Backward);
    }

    // platform
    Platform platform;
    const auto halt = obj.value(QLatin1String("halt")).toObject();
    platform.setName(halt.value(QLatin1String("gleisbezeichnung")).toString());
    const auto sectorArray = halt.value(QLatin1String("allSektor")).toArray();
    for (const auto &sectorV : sectorArray) {
        parsePlatformSection(platform, sectorV.toObject());
    }

    // departure
    Location stop;
    stop.setName(halt.value(QLatin1String("bahnhofsname")).toString());
    stop.setIdentifier(QStringLiteral("ibnr"), halt.value(QLatin1String("evanummer")).toString());
    stop.setType(Location::Stop);
    Route route;
    Line line;

    line.setMode(DeutscheBahnProducts::modeType(trainType));
    if (line.mode() == Line::Unknown) {
        line.setMode(Line::Train);
    }

    if (const auto lineNumber = obj.value(QLatin1String("liniebezeichnung")).toString(); !lineNumber.isEmpty() && line.mode() != Line::LongDistanceTrain) {
        line.setName(trainType + QLatin1Char(' ') + lineNumber);
        route.setName(vehicle.name());
    } else {
        line.setName(vehicle.name());
    }
    route.setLine(line);

    stopover.setRoute(route);
    stopover.setStopPoint(stop);
    stopover.setScheduledArrivalTime(QDateTime::fromString(halt.value(QLatin1String("ankunftszeit")).toString(), Qt::ISODate));
    stopover.setScheduledDepartureTime(QDateTime::fromString(halt.value(QLatin1String("abfahrtszeit")).toString(), Qt::ISODate));
    stopover.setScheduledPlatform(platform.name());

    fillMissingPositions(vehicle, platform);
    stopover.setVehicleLayout(vehicle);
    stopover.setPlatformLayout(platform);

    return true;
}

struct {
    const char *name;
    Feature::Type type;
} constexpr const feature_map[] = {
    { "ABTEILKLEINKIND", Feature::ToddlerArea },
    { "BISTRO", Feature::Restaurant },
    { "FAMILIE", Feature::FamilyArea },
    { "INFO", Feature::InformationPoint },
    { "KLIMA", Feature::AirConditioning },
    { "PLAETZEFAHRRAD", Feature::BikeStorage },
    { "PLAETZEROLLSTUHL", Feature::WheelchairAccessible },
    { "ROLLSTUHLTOILETTE", Feature::WheelchairAccessibleToilet },
    { "RUHE", Feature::SilentArea },
};

void DeutscheBahnVehicleLayoutParser::parseVehicleSection(Vehicle &vehicle, const QJsonObject &obj)
{
    VehicleSection section;
    section.setName(obj.value(QLatin1String("wagenordnungsnummer")).toString());

    const auto pos = obj.value(QLatin1String("positionamhalt")).toObject();
    section.setPlatformPositionBegin(pos.value(QLatin1String("startprozent")).toString().toDouble() / 100.0);
    section.setPlatformPositionEnd(pos.value(QLatin1String("endeprozent")).toString().toDouble() / 100.0);

    const auto cat = obj.value(QLatin1String("kategorie")).toString();
    if (cat.compare(QLatin1String("LOK"), Qt::CaseInsensitive) == 0) {
        section.setType(VehicleSection::Engine);
    } else if (cat.compare(QLatin1String("TRIEBKOPF"), Qt::CaseInsensitive) == 0) {
        section.setType(VehicleSection::PowerCar);
    } else if (cat.contains(QLatin1String("STEUERWAGEN"), Qt::CaseInsensitive)) {
        section.setType(VehicleSection::ControlCar);
    } else {
        section.setType(VehicleSection::PassengerCar);
    }

    // see https://en.wikipedia.org/wiki/UIC_classification_of_railway_coaches
    const auto num = obj.value(QLatin1String("fahrzeugnummer")).toString();
    const auto cls = obj.value(QLatin1String("fahrzeugtyp")).toString();
    section.setClasses(UicRailwayCoach::coachClass(num, cls));
    section.setDeckCount(UicRailwayCoach::deckCount(num, cls));
    if (const auto type = UicRailwayCoach::type(num, cls); section.type() == VehicleSection::PassengerCar && type != VehicleSection::UnknownType) {
        section.setType(type);
    }
    auto f = UicRailwayCoach::features(num, cls);

    const auto equipmentArray = obj.value("allFahrzeugausstattung"_L1).toArray();
    for (const auto &equipmentV : equipmentArray) {
        const auto equipmentObj = equipmentV.toObject();
        const auto type = equipmentObj.value("ausstattungsart"_L1).toString();
        // TODO this has a status field, is this ever set?
        const auto it = std::lower_bound(std::begin(feature_map), std::end(feature_map), type, [](const auto &lhs, const auto &rhs) {
            return QLatin1StringView(lhs.name).compare(rhs, Qt::CaseInsensitive) < 0;
        });
        if (it != std::end(feature_map) && type.compare(QLatin1StringView((*it).name), Qt::CaseInsensitive) == 0) {
            FeatureUtil::add(f, Feature{(*it).type});
        } else {
            qDebug() << "Unhandled vehicle section equipment:" << type;
        }
    }
    section.setSectionFeatures(std::move(f));

    // TODO what is the actual value for closed sections?
    if (const auto status = obj.value("status"_L1).toString(); !status.isEmpty() && status != "OFFEN"_L1) {
        section.setDisruptionEffect(Disruption::NoService);
    }

    auto sections = vehicle.takeSections();
    sections.push_back(section);
    vehicle.setSections(std::move(sections));
}

void DeutscheBahnVehicleLayoutParser::parsePlatformSection(Platform &platform, const QJsonObject &obj)
{
    PlatformSection section;
    section.setName(obj.value(QLatin1String("sektorbezeichnung")).toString());

    const auto pos = obj.value(QLatin1String("positionamgleis")).toObject();
    section.setBegin(pos.value(QLatin1String("startprozent")).toString().toDouble() / 100.0);
    section.setEnd(pos.value(QLatin1String("endeprozent")).toString().toDouble() / 100.0);

    auto sections = platform.takeSections();
    sections.push_back(section);
    platform.setSections(std::move(sections));

    const auto length = std::max(pos.value(QLatin1String("startmeter")).toString().toDouble(), pos.value(QLatin1String("endemeter")).toString().toDouble());
    if (length > 0) {
        platform.setLength(std::max(platform.length(), (int)std::ceil(length)));
    }
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

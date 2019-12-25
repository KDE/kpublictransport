/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "deutschebahnvehiclelayoutparser.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace KPublicTransport;

bool DeutscheBahnVehicleLayoutParser::parse(const QByteArray &data)
{
    auto doc = QJsonDocument::fromJson(data);
    auto obj = doc.object().value(QLatin1String("data")).toObject().value(QLatin1String("istformation")).toObject();

    vehicle.setName(obj.value(QLatin1String("zuggattung")).toString() + QLatin1Char(' ') + obj.value(QLatin1String("zugnummer")).toString());

    // vehicles
    // TODO dobule segment ICE trains technically are two Vehicle objects...
    const auto vehiclesArray = obj.value(QLatin1String("allFahrzeuggruppe")).toArray();
    for (const auto &vehicleV : vehiclesArray) {
        const auto sectionsArray = vehicleV.toObject().value(QLatin1String("allFahrzeug")).toArray();
        for (const auto &sectionV : sectionsArray) {
            parseVehicleSection(sectionV.toObject());
        }
    }

    // platform
    const auto halt = obj.value(QLatin1String("halt")).toObject();
    platform.setName(halt.value(QLatin1String("gleisbezeichnung")).toString());
    const auto sectorArray = halt.value(QLatin1String("allSektor")).toArray();
    for (const auto &sectorV : sectorArray) {
        parsePlatformSection(sectorV.toObject());
    }

    // TODO departure
    return true;
}

void DeutscheBahnVehicleLayoutParser::parseVehicleSection(const QJsonObject &obj)
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
    } else if (cat.startsWith(QLatin1String("STEUERWAGEN"), Qt::CaseInsensitive)) {
        section.setType(VehicleSection::ControlCar);
    } else {
        section.setType(VehicleSection::PassengerCar);
    }

    // see https://en.wikipedia.org/wiki/UIC_classification_of_railway_coaches
    const auto cls = obj.value(QLatin1String("fahrzeugtyp")).toString();
    VehicleSection::Classes c = VehicleSection::UnknownClass;
    if (cls.startsWith(QLatin1Char('A')) || cls.startsWith(QLatin1String("DA"))) {
        c |= VehicleSection::FirstClass;
    }
    if (cls.startsWith(QLatin1Char('B')) || cls.startsWith(QLatin1String("AB")) || cls.startsWith(QLatin1String("DB"))) {
        c |= VehicleSection::SecondClass;
    }
    section.setClasses(c);

    auto sections = vehicle.takeSections();
    sections.push_back(section);
    vehicle.setSections(std::move(sections));
}

void DeutscheBahnVehicleLayoutParser::parsePlatformSection(const QJsonObject &obj)
{
    PlatformSection section;
    section.setName(obj.value(QLatin1String("sektorbezeichnung")).toString());

    const auto pos = obj.value(QLatin1String("positionamgleis")).toObject();
    section.setBegin(pos.value(QLatin1String("startprozent")).toString().toDouble() / 100.0);
    section.setEnd(pos.value(QLatin1String("endeprozent")).toString().toDouble() / 100.0);

    auto sections = platform.takeSections();
    sections.push_back(section);
    platform.setSections(std::move(sections));
}

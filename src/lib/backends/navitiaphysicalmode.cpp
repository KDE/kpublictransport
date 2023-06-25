/*
    SPDX-FileCopyrightText: 2018-2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "navitiaphysicalmode.h"

#include <QUrlQuery>

#include <cstring>
#include <vector>

using namespace KPublicTransport;

struct {
    const char *name;
    Line::Mode mode;
} static constexpr const navitia_physical_modes[] = {
    { "Air", Line::Air },
    { "Boat", Line::Boat },
    { "Bus", Line::Bus },
    { "BusRapidTransit", Line::BusRapidTransit },
    { "Coach", Line::Coach },
    { "Ferry", Line::Ferry },
    { "Funicular", Line::Funicular },
    { "LocalTrain", Line::LocalTrain },
    { "LongDistanceTrain", Line::LongDistanceTrain },
    { "Metro", Line::Metro },
    { "RailShuttle", Line::RailShuttle },
    { "RapidTransit", Line::RapidTransit },
    { "Shuttle", Line::Shuttle },
    { "Taxi", Line::Taxi },
    { "Train", Line::Train },
    { "Tramway", Line::Tramway }
};

static constexpr const char pm_prefix[] = "physical_mode:";

Line::Mode NavitiaPhysicalMode::parsePhysicalMode(QStringView mode)
{
    if (!mode.startsWith(QLatin1String(pm_prefix))) {
        return Line::Unknown;
    }
    const auto modeStr = mode.mid(14).toLatin1();
    for (const auto &m : navitia_physical_modes) {
        if (std::strcmp(modeStr.constData(), m.name) == 0) {
            return m.mode;
        }
    }

    return Line::Unknown;
}

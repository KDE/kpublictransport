/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hvt.h"

#include <QDebug>

using namespace KPublicTransport;

Line::Mode Gtfs::Hvt::typeToMode(int hvt)
{
    if (hvt < 0) {
        return Line::Unknown;
    }

    // individually handled cases - https://developers.google.com/transit/gtfs/reference/extended-route-types
    switch (hvt) {
        case 101:
        case 102:
            return Line::LongDistanceTrain;
        case 106:
            return Line::LocalTrain;
        case 108:
            return Line::RailShuttle;
        case 109:
            return Line::RapidTransit;
        case 203:
            return Line::Shuttle;
        case 401:
        case 402:
            return Line::Metro;
        case 403:
            return Line::RapidTransit;
        case 405: // monorail
            return Line::Tramway;
        case 711:
            return Line::Shuttle;
        case 717:
            return Line::Taxi;
        case 905:
            return Line::RailShuttle;
        case 1502:
            return Line::Boat;
    }

    // coarse top-level types - https://developers.google.com/transit/gtfs/reference/#routestxt
    switch (hvt) {
        case 0:
        case 5: // cable car
            return Line::Tramway;
        case 1:
            return Line::Metro;
        case 2:
            return Line::Train;
        case 3:
            return Line::Bus;
        case 4:
            return Line::Ferry;
        case 6:
            return Line::AerialLift;
        case 7:
            return Line::Funicular;
        case 11: // trolleybus
            return Line::Bus;
        case 12: // monorail
            return Line::Tramway;
    }

    // type ranges - https://developers.google.com/transit/gtfs/reference/extended-route-types
    if (hvt >= 100 && hvt < 199) {
        return Line::Train;
    }
    if (hvt >= 200 && hvt < 299) {
        return Line::Coach;
    }
    if (hvt >= 400 && hvt < 499) {
        return Line::RapidTransit;
    }
    if (hvt >= 700 && hvt < 899) {
        return Line::Bus;
    }
    if (hvt >= 900 && hvt < 999) {
        return Line::Tramway;
    }
    if (hvt >= 1000 && hvt < 1099) {
        return Line::Boat;
    }
    if (hvt >= 1100 && hvt < 1199) {
        return Line::Air;
    }
    if (hvt >= 1200 && hvt < 1299) {
        return Line::Ferry;
    }
    if (hvt >= 1300 && hvt < 1399) {
        return Line::AerialLift;
    }
    if (hvt >= 1400 && hvt < 1499) {
        return Line::Funicular;
    }
    if (hvt >= 1500 && hvt < 1599) {
        return Line::Taxi;
    }
    if (hvt == 1700) { // not officially specified, but de-facto standard in a number of OTP deployments
        return Line::RideShare;
    }

    qDebug() << "encountered unknown GTFS (extended) route type:" << hvt;
    return Line::Unknown;
}

// top-level types, complete list
struct {
    const char *typeName;
    Line::Mode mode;
} static const coarse_mode_map[] = {
    { "air", Line::Air },
    { "bus", Line::Bus },
    { "cableway", Line::AerialLift },
    { "coach", Line::Coach },
    { "funicular", Line::Funicular },
    { "lift", Line::AerialLift },
    { "metro", Line::Metro },
    { "rail", Line::Train },
    { "subway", Line::Metro },
    { "tram", Line::Tramway },
    { "unknown", Line::Unknown },
    { "water", Line::Boat },
};

// fine-grained types, special cases that can't be found by pattern matches
struct {
    const char *typeName;
    Line::Mode mode;
} static const fine_mode_map[] = {
    { "airportlinkrail", Line::RapidTransit },
    { "airshipservice", Line::Air },
    { "blackcab", Line::Taxi },
    { "canalbarge", Line::Boat },
    { "cablecar", Line::AerialLift },
    { "helicopterservice", Line::Air },
    { "international", Line::LongDistanceTrain },
    { "interregionalrail", Line::Train },
    { "local", Line::LocalTrain },
    { "longdistance", Line::LongDistanceTrain },
    { "minicab", Line::Taxi },
    { "regionalrail", Line::LocalTrain },
    { "riverbus", Line::Boat },
    { "streetcablecar", Line::Tramway },
    { "suburbanrailway", Line::RapidTransit },
    { "trainFerry", Line::Ferry }, // disambiguate as this matches multiple patterns
    { "tube", Line::Metro },
    { "urbanrailway", Line::RapidTransit },
    { "watertaxi", Line::Boat },
};

// patterns for groups of fine-grained types
struct {
    const char *namePattern;
    Line::Mode mode;
} static const mode_pattern_map[] = {
    { "boat", Line::Boat },
    { "bus", Line::Bus },
    { "coach", Line::Coach },
    { "ferry", Line::Ferry },
    { "flight", Line::Air },
    { "funicular", Line::Funicular },
    { "highspeed", Line::LongDistanceTrain },
    { "lift", Line::AerialLift },
    { "rail", Line::Train },
    { "taxi", Line::Taxi },
    { "telecabin", Line::AerialLift },
    { "train", Line::Train },
    { "tram", Line::Tramway },
};

Line::Mode Gtfs::Hvt::typeToMode(const QString &hvt)
{
    if (hvt.isEmpty()) {
        return Line::Unknown;
    }

    // fine-grained types, exact matches
    for (const auto &m : fine_mode_map) {
        if (hvt.compare(QLatin1String(m.typeName), Qt::CaseInsensitive) == 0) {
            return m.mode;
        }
    }

    // top-level types, exact matches
    for (const auto &m : coarse_mode_map) {
        if (hvt.compare(QLatin1String(m.typeName), Qt::CaseInsensitive) == 0) {
            return m.mode;
        }
    }

    // pattern matches on fine grained types
    for (const auto &m : mode_pattern_map) {
        if (hvt.contains(QLatin1String(m.namePattern), Qt::CaseInsensitive)) {
            return m.mode;
        }
    }

    qDebug() << "encountered unknown GTFS (extended) route type:" << hvt;
    return Line::Unknown;
}

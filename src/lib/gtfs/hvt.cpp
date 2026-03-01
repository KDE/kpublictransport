/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hvt.h"

#include <siri/mode.h>

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

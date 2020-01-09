/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#include "hvt.h"

#include <QDebug>

using namespace KPublicTransport;

Line::Mode Gtfs::Hvt::typeToMode(int hvt)
{
    // individually handled cases - https://developers.google.com/transit/gtfs/reference/extended-route-types
    switch (hvt) {
        case 101:
        case 102:
            return Line::LongDistanceTrain;
        case 106:
            return Line::LocalTrain;
        case 109:
            return Line::RapidTransit;
        case 401:
        case 402:
            return Line::Metro;
        case 403:
            return Line::RapidTransit;
        case 717:
            return Line::Taxi;
        case 1502:
            return Line::Boat;
    }

    // coarse top-level types - https://developers.google.com/transit/gtfs/reference/#routestxt
    switch (hvt) {
        case 0:
        case 5: // cable car
        case 6: // TODO gondola
            return Line::Tramway;
        case 1:
            return Line::Metro;
        case 2:
            return Line::Train;
        case 3:
            return Line::Bus;
        case 4:
            return Line::Ferry;
        case 7:
            return Line::Funicular;
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
        return Line::Tramway; // TODO gondola/aerial lift
    }
    if (hvt >= 1400 && hvt < 1499) {
        return Line::Funicular;
    }
    if (hvt >= 1500 && hvt < 1599) {
        return Line::Taxi;
    }

    qDebug() << "encountered unknown GTFS (extended) route type:" << hvt;
    return Line::Unknown;
}

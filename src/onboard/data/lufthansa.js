/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-FileCopyrightText: 2023 Kai Uwe Broulik <kde@broulik.de>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parsePosition(response)
{
    return {
        latitude = response.lat,
        longitude = response.lon,
        speed = response.groundSpeed * 1.852,
        heading = response.heading,
        altitude = response.altitude * 0.3048
        // TODO timestamp, temperature
    };
}

function stringToMinutes(str) { // turns "HH:mm" into minutes int.
    const parts = str.split(":");
    return parseInt(parts[0], 10) * 60 + parseInt(parts[1], 10);
}

function parseJourney(response)
{
    const section = {
        mode = 'PublicTransport',
        route = {
            line = {
                mode = 'Air',
                name = response.flightNumber
            }
        },
        from = {
            identifier = { iata = response.orig.code },
            latitude = response.orig.lat,
            longitude = response.orig.lon,
            name = response.orig.code
        },
        to = {
            identifier = { iata = response.dest.code },
            latitude = response.dest.lat,
            longitude = response.dest.lon,
            name = response.dest.code
        },
        distance = Math.round(response.distDest * 1852),
        scheduledArrivalTime: response.dest.localTimeAtArrival
    };

    const elapsedMinutes = stringToMinutes(response.elapsedFlightTime);
    section.expectedDepartureTime = new Date(response.orig.localTime);
    section.expectedDepartureTime.setMinutes(section.expectedDepartureTime.getMinutes() - elapsedMinutes);

    const remainingMinutes = stringToMinutes(response.timeDest);
    section.expectedArrivalTime = new Date(response.dest.localTime);
    section.expectedArrivalTime.setMinutes(section.expectedArrivalTime.getMinutes() + remainingMinutes);

    return { sections = [section] };
}

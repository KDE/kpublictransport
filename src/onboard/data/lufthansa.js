/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
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
        scheduledArrivalTime: response.dest.localTimeAtArrival
        // TODO elapsedFlightTime would allow to compute departureTime
        // TODO eta or timeDest ould allow to compute expectedArrivalTime
    };
    return { sections = [section] };
}

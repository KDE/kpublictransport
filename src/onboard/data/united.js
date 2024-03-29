/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parseDateTime(s) {
   const r = s.match(/(\d+ [A-Z][a-z]+ \d+) (\d+):(\d\d) (AM|PM)/);
    let dt = new Date(Date.parse(r[1] + ' ' + (r[2].length == 1 ? '0' : '') + r[2] + ':' + r[3]));
    if (r[4] == 'PM') {
        dt.setHours(dt.getHours() + 12);
    }
    return dt.toJSON().substr(0, 19);
}

function parseJourney(response)
{
    const section = {
        mode = 'PublicTransport',
        route = {
            line = {
                mode = 'Air',
                name = response.flifo.flightNumber
            }
        },
        from = {
            identifier = { iata = response.flifo.originAirportCode },
            name = response.flifo.originCity
        },
        to = {
            identifier = { iata = response.flifo.destinationAirportCode },
            name = response.flifo.destinationCity
        },
        scheduledArrivalTime: parseDateTime(response.flifo.scheduledArrivalTimeLocal),
        expectedArrivalTime: parseDateTime(response.flifo.estimatedArrivalTimeLocal), // also: actualArrivalTime
        scheduledDepartureTime: parseDateTime(response.flifo.scheduledDepartureTimeLocal),
        expectedDepartureTime: parseDateTime(response.flifo.actualDepartureTimeLocal), // also: estimatedDepartureTime
        schedluedDeparturePlatform: response.flifo.departureGate,
        scheduledArrivalPlatform: response.flifo.arrivalGate
    };
    return { sections = [section] };
}

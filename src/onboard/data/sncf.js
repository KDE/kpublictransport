/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parseGps(response)
{
    return {
        latitude: response.latitude,
        longitude: response.longitude,
        speed: response.speed * 3.6, // m/s -> km/h
        heading: response.heading,
        altitude: response.altitude
    };
}

function parseDetails(response)
{
    let section = {};
    section.mode = 'PublicTransport';
    section.route = {};
    section.route.line = {};
    section.route.line.name = ((response.carrier ?? '') + ' ' + response.number).trim();
    section.route.line.mode = 'LongDistanceTrain';
    section.intermediateStops = [];
    for (s of response.stops) {
        let stop = {};
        stop.stopPoint = {};
        stop.stopPoint.type = 'Stop';
        stop.stopPoint.name = s.label;
        stop.stopPoint.latitude = s.coordinates.latitude;
        stop.stopPoint.longitude = s.coordinates.longitude;
        stop.stopPoint.identifier = {};
        stop.stopPoint.identifier.sncf = s.code;
        stop.scheduledDepartureTime = s.theoricDate;
        stop.expectedDepartureTime = s.realDate;
        section.intermediateStops.push(stop);
    }

    const idx = section.intermediateStops.length - 1;
    section.intermediateStops[idx].scheduledArrivalTime = section.intermediateStops[idx].scheduledDepartureTime;
    section.intermediateStops[idx].expectedArrivalTime = section.intermediateStops[idx].expectedDepartureTime;

    let jny = {};
    jny.sections = [section];
    return jny;
}

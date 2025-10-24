/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parseGps(response)
{
    return {
        latitude: response.Latitude,
        longitude: response.Longitude,
        speed: response.JSON?.speed * 3.6,
        heading: response.JSON?.heading,
        altitude: response.JSON?.altitude,
    };
}

function parseJourney(response)
{
    let section = {};
    section.mode = 'PublicTransport';
    section.route = {};
    section.route.line = {};
    section.route.line.name = response.trainType + ' ' + response.lineNumber;
    section.route.line.mode = 'LongDistanceTrain';
    section.intermediateStops = [];
    const dt = response.latestStatus.dateTime.substr(0, 11);
    for (s of response.stations) {
        let stop = {};
        stop.stopPoint = {};
        stop.stopPoint.type = 'Stop';
        stop.stopPoint.name = s.name.de;
        stop.stopPoint.identifier = { ibnr: s.id };
        stop.scheduledDepartureTime = dt + s.departure.scheduled;
        stop.expectedDepartureTime = dt + s.departure.forecast;
        stop.scheduledArrivalTime = dt + s.arrival.scheduled;
        stop.expectedArrivalTime = dt + s.arrival.forecast;
        stop.expectedPlatform = s.track?.de;
        section.intermediateStops.push(stop);
    }

    let jny = {};
    jny.sections = [section];
    return jny;
}

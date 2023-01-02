/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parseICEStatus(response)
{
    let pos = {};
    pos.latitude = response.latitude;
    pos.longitude = response.longitude;
    pos.speed = response.speed;
    pos.timestamp = new Date(response.serverTime).toISOString();
    return pos;
}

/** @see https://github.com/derhuerst/wifi-on-ice-portal-client */
function parseICETrip(response)
{
    let section = {};
    section.mode = 'PublicTransport';
    section.route = {};
    section.route.direction = response.trip.stopInfo.finalStationName; // TODO destination object
    section.route.line = {};
    section.route.line.name = response.trip.trainType + ' ' + response.trip.vzn;
    section.route.line.mode = 'LongDistanceTrain';
    section.distance = response.trip.totalDistance;
    section.intermediateStops = [];
    for (s of response.trip.stops) {
        let stop = {};
        stop.stopPoint = {};
        stop.stopPoint.type = 'Stop';
        stop.stopPoint.name = s.station.name;
        stop.stopPoint.latitude = s.station.geocoordinates.latitude;
        stop.stopPoint.longitude = s.station.geocoordinates.longitude;
        stop.stopPoint.identifier = {};
        stop.stopPoint.identifier.ibnr = s.station.evaNr.substr(0, 7);
        stop.scheduledPlatform = s.track.scheduled;
        stop.expectedPlatform = s.track.actual;
        stop.scheduledDepartureTime = new Date(s.timetable.scheduledDepartureTime).toISOString();
        stop.expectedDepartureTime = new Date(s.timetable.actualDepartureTime).toISOString();
        stop.scheduledArrivalTime = new Date(s.timetable.scheduledArrivalTime).toISOString();
        stop.expectedArrivalTime = new Date(s.timetable.actualArrivalTime).toISOString();
        if (s.delayReasons) {
            stop.notes = [];
            for (d of s.delayReasons) {
                stop.notes.push(d.text);
            }
        }
        section.intermediateStops.push(stop);
    }

    let jny = {};
    jny.sections = [section];
    return jny;
}

/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parseRealtime(response)
{
    return {
        latitude: response.gpsLat,
        longitude: response.gpsLng,
        speed: response.speed,
        altitude: response.altitude
    };
}

function parseCurrent(response)
{
    let section = {};
    section.mode = 'PublicTransport';
    section.route = {};
    section.route.line = {};
    section.route.line.name = response.name;
    section.route.line.mode = 'LongDistanceTrain';
    section.intermediateStops = [];
    for (s of response.connexionTimes) {
        let stop = {};
        stop.stopPoint = {};
        stop.stopPoint.type = 'Stop';
        stop.stopPoint.name = s.station.name;
        stop.stopPoint.latitude = s.station.gpsLat;
        stop.stopPoint.longitude = s.station.gpsLng;
        stop.stopPoint.locality = s.station.city.name;
        // TODO track/platform: present but null in existing samples
        stop.scheduledDepartureTime = s.timeDeparture;
        stop.scheduledArrivalTime = s.timeArrival;
        section.intermediateStops.push(stop);
    }

    let jny = {};
    jny.sections = [section];
    return jny;
}

/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parseICEStatus(response)
{
    if (response.gpsStatus != 'VALID') {
        return {};
    }
    return {
        latitude = response.latitude,
        longitude = response.longitude,
        speed = response.speed,
        timestamp = new Date(response.serverTime).toISOString()
    };
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
        if (s.info.status === 1 && s.info.distanceFromStart === 0) {
            stop.disruptionEffect = 'NoService';
        }
        section.intermediateStops.push(stop);
    }

    let jny = {};
    jny.sections = [section];
    return jny;
}

function parseZugportalTrip(response)
{
    let section = {
        mode = 'PublicTransport',
        route = {
            line = {
                name = response.name,
                // TODO complete map from response.type
                mode = response.type == 'CITY_TRAIN' ? 'RapidTransit' : 'Train'
            }
        },
        intermediateStops = [],
        notes = []
    };
    for (s of response.stops) {
        let stop = {
            stopPoint = {
                type = 'Stop',
                name = s.station.name,
                identifier = { ibnr = s.station.evaNo }
            },
            scheduledPlatform = s.track.target,
            expectedPlatform = s.track.prediction,
            notes = []
        };
        if (s.station.position) {
            stop.stopPoint.latitude = s.station.position.latitude;
            stop.stopPoint.longitude = s.station.position.longitude;
        }
        if (s.departureTime) {
            stop.scheduledDepartureTime = s.departureTime.target;
            stop.expectedDepartureTime = s.departureTime.predicted;
        }
        if (s.arrivalTime) {
            stop.scheduledArrivalTime = s.arrivalTime.target;
            stop.expectedArrivalTime = s.arrivalTime.predicted;
        }

        if (s.status === "Canceled" || s.canceled === true) {
            stop.disruptionEffect = 'NoService';
        }

        for (message of s.messages) {
            if (message.type === "CUSTOMER_REASON") {
                notes.push(message.textShort || message.text);
            }
        }

        section.intermediateStops.push(stop);
    }

    for (him of response.hims) {
        section.notes.push(him.captionHtml || him.caption);
    }

    // TODO uic, trainNo
    return { sections = [section] };
}

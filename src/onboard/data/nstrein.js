// SPDX-FileCopyrightText: 2024 Carl Schwan <carl@carlschwan.eu>
// SPDX-License-Identifier: LGPL-2.0-or-later

.import QtQml 1.0 as QtQml

function parseMonth(s) {
    let months = ['January', 'February', 'Mars', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'];
    return months.indexOf(s) + 1;
}

function parseDateTime(s, delay) {
    const r = s.match(/([A-Z][a-z]+), (\d+) (\d+) (\d\d:\d\d:\d\d) ((\+|-)\d\d)(\d\d)/);
    let timestamp = Date.parse(r[3] + '-' + parseMonth(r[1]) + '-' + r[2] + 'T' + r[4] + '.000' + r[5] + ':' + r[7]);
    if (delay !== null) {
        timestamp += delay * 60000;
    }
    return (new Date(timestamp)).toJSON().substr(0, 19);
}

function parseJourney(response)
{
    let section = {};
    section.mode = 'PublicTransport';
    section.route = {
        line: {
            name = response.trip.trainTypeFull,
            mode = 'Train'
        }
    };
    section.intermediateStops = [];
    for (s of response.trip.stops) {
        let stop = {};
        stop.stopPoint = {
            type: 'Stop',
            name: s.station.languages.nl.longName,
            identifier: { uic: s.station.uic, nstrein: s.station.code },
            latitude: s.station.latitude,
            longitude: s.station.longitude,
        };

        if (s.fromDateTime) {
            stop.scheduledDepartureTime = parseDateTime(s.fromDateTime, null);
            stop.expectedDepartureTime = parseDateTime(s.fromDateTime, s.fromDelay);
        }

        if (s.arrivalDateTime) {
            stop.scheduledArrivalTime = parseDateTime(s.arrivalDateTime, null);
            stop.expectedArrivalTime = parseDateTime(s.arrivalDateTime, s.arrivalDelay);
        }

        stop.scheduledPlatform = s.platform;
        stop.platformChanged = s.platFormChanged;

        section.intermediateStops.push(stop);
    }

    return { sections: [section] };
}

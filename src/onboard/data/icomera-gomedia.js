/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

/** Icomera GoMedia position API.
 *  @see https://github.com/derhuerst/live-gomedia-position/
 */
function parsePosition(response)
{
    return {
        latitude: response.latitude,
        longitude: response.longitude,
        speed: response.speed
    };
}

function parseJourney(response)
{
    let section = {};
    section.mode = 'PublicTransport';
    section.intermediateStops = [];
    for (s of response.journey.calling_points) {
        let stop = {};
        stop.stopPoint = {};
        stop.stopPoint.type = 'Stop';
        stop.stopPoint.name = Object.values(s.display_name.values)[0]; // TODO pick the right language
        stop.stopPoint.identifier = { uic: s.calling_point.id.id };
        stop.stopPoint.timezone = s.calling_point.timezone;
        stop.scheduledDepartureTime = s.calling_point.departure_times.scheduled_time;
        stop.expectedDepartureTime = s.calling_point.departure_times.actual_time;
        stop.scheduledArrivalTime = s.calling_point.arrival_times.scheduled_time;
        stop.expectedArrivalTime = s.calling_point.arrival_times.actual_time;
        stop.scheduledPlatform = s.calling_point.platform;
        section.intermediateStops.push(stop);
    }

    return { sections: [section] };
}

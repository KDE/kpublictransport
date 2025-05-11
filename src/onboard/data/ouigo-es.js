/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parsePosition(response)
{
    if (!response.success)
        return;
    return {
        latitude: response.latitude,
        longitude: response.longitude,
        speed: response.speed * 3.6, // m/s -> km/h
        heading: response.heading,
        altitude: response.altitude,
        timetamp: new Date(response.timestamp).toISOString()
    };
}

function parseJourney(response)
{
    let section = {
        mode: 'PublicTransport',
        route: {
            line: {
                name: response.commercialId,
                mode: 'LongDistanceTrain'
            }
        },
        intermediateStops: []
    };

    for (const s of response.stations) {
        const stop = {
            stopPoint: {
                type: 'Stop',
                name: s.name,
                latitude: s.coords.coordYLat,
                longitude: s.coords.coordXLng,
                identifier: { "uic": "71" + s.code }
            },
            expectedDepartureTime: s.departAt,
            expectedArrivalTime: s.arrivalAt,
            scheduledDepartureTime: s.theoricalDepartTime,
            scheduledArrivalTime: s.theoricalArrivalTime
        };
        section.intermediateStops.push(stop);
    }

    let coords = [];
    for (const c of response.path) {
        coords.push([c.longitude, c.latitude]);
    }
    section.path = {
        sections: [{
            path: {
                coordinates: coords,
                type: "LineString"
            }
        }]
    };

    let jny = {};
    jny.sections = [section];
    return jny;
}

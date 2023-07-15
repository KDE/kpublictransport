/*
    SPDX-FileCopyrightText: 2023 Kai Uwe Broulik <kde@broulik.de>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parsePositions(response)
{
    let mostRecentTime = 0;
    let mostRecentIdx = 0;

    // TODO pass ?from_timestamp= URL query to limit number of results.
    for (let i = 0; i < response.length; ++i) {
        const position = response[i];
        const timeStamp = new Date(position.created_at).getTime();

        if (timeStamp > mostRecentTime) {
            mostRecentTime = timeStamp;
            mostRecentIdx = i;
        }
    }

    const position = response[mostRecentIdx];

    let result = {
        latitude = position.latitude,
        longitude = position.longitude,
        altitude = position.altitude_meters,
        timestamp = position.created_at,
    };

    if (position.speed_kilometers_per_hour !== null) {
        result.speed = position.speed_kilometers_per_hour;
    }
    if (position.bearing_in_degree !== null) {
        result.heading = position.bearing_in_degree;
    }

    return result
}


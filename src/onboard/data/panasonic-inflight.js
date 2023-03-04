/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parseCurrentPositionV1(response)
{
    return {
        latitude = response.td_id_fltdata_present_position_latitude / 1000.0,
        longitude = response.td_id_fltdata_present_position_longitude / 1000.0,
        speed = response.td_id_fltdata_ground_speed * 1.852,
        heading = response.td_id_fltdata_true_heading
        // TODO timestamp?
        // TODO altitude?
    };
}

function parseCurrentPositionV2(response)
{
    return {
        latitude = response.current_coordinates.latitude,
        longitude = response.current_coordinates.longitude,
        speed = response.ground_speed_knots * 1.852,
        heading = response.true_heading_degree,
        timestamp = response.current_utc_date + 'T' + response.current_utc_time + 'Z'
        // TODO altitude ?
    };
}

function parseFlightV1(response)
{
    // TODO
}

function parseFlightV2(response)
{
    // TODO
}

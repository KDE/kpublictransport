/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function toDegreeV1(val)
{
    if (val > 80000000) {
        val -= 80000000;
        val *= -1;
    }
    return val / 1000.0;
}

function parseCurrentPositionV1(response)
{
    return {
        latitude = toDegreeV1(response.td_id_fltdata_present_position_latitude),
        longitude = toDegreeV1(response.td_id_fltdata_present_position_longitude),
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
    const section = {
        mode = 'PublicTransport',
        route = {
            line = {
                mode = 'Air',
                name = response.td_id_fltdata_flight_number
            }
        },
        from = {
            identifier = {
                iata = response.td_id_fltdata_departure_baggage_id,
                icao = response.td_id_fltdata_departure_id
            },
            latitude = toDegreeV1(response.td_id_fltdata_departure_latitude),
            longitude = toDegreeV1(response.td_id_fltdata_departure_longitude)
        },
        to = {
            identifier = {
                iata = response.td_id_fltdata_destination_baggage_id,
                icao = response.td_id_fltdata_destination_id
            },
            latitude = toDegreeV1(response.td_id_fltdata_destination_latitude),
            longitude = toDegreeV1(response.td_id_fltdata_destination_longitude)
        },
        distance = (Math.max(response.td_id_fltdata_distance_from_origin, response.td_id_fltdata_distance_traveled) + response.td_id_fltdata_distance_to_destination) * 1852
        // TODO times?
    };
    return { sections = [section] };
}

function parseFlightV2(response)
{
    const section = {
        mode = 'PublicTransport',
        route = {
            line = {
                mode = 'Air',
                name = response.flight_number
            }
        },
        from = {
            identifier = {
                iata = response.departure_iata,
                icao = response.departure_icao
            },
            latitude = response.departure_coordinates.latitude,
            longitude = response.departure_coordinates.longitude
        },
        to = {
            identifier = {
                iata = response.destination_icao,
                icao = response.destination_iata
            },
            latitude = response.destination_coordinates.latitude,
            longitude = response.destination_coordinates.longitude
        },
        distance = (Math.max(response.distance_from_departure_nautical_miles, response.distance_from_departure_nautical_miles) + response.distance_to_destination_nautical_miles) * 1852,
        expectedDepartureTime = response.takeoff_time_utc,
        expectedArrivalTime = response.current_utc_date + 'T' + response.estimated_arrival_time_utc + ':00' // this is called "utc", but it is local time...
    };
    return { sections = [section] };
}

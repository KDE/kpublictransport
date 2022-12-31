/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

/** Generic support for Icomera omboard.info Wifi/portals.
 *  @see https://github.com/derhuerst/live-icomera-position
 */
function parsePosition(response)
{
    if (response.mode < 2)
        return;

    return {
        latitude: response.latitude,
        longitude: response.longitude,
        speed: response.speed,
        heading: response.cmg
    };
}

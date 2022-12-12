/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

function parsePosition(response)
{
    let pos = {};
    pos.latitude = response.latitude;
    pos.longitude = response.longitude;
    pos.speed = response.speed;
    pos.heading = response.cmg;
    return pos;
}

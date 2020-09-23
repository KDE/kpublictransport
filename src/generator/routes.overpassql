/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

/** List all local public transport routes. */
[bbox:{{bbox}}][out:xml][timeout:90];
(
    rel["route"="train"]["line"="light_rail"];
    rel["route"="train"]["service"="commuter"];
    rel["route"="subway"];
    rel["route"="tram"];
)->.routes;
rel(br.routes)->.routeMasters;
(
    .routes;
    .routeMasters;
);
out bb qt;

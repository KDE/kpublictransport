<!--
SPDX-FileCopyrightText: 2024 Jonah Brüchert <jbb@kaidan.im>

SPDX-License-Identifier: LGPL-2.0-or-later
-->

# Auxillary Station Data

Some APIs do not provide geo data for their Stations.
These are commonly needed to find intersecting providers.

This directory contains processed exports from OpenStreetMap.

The simplest way to export this data is to export the result of a query like this with [overpass turbo](https://overpass-turbo.eu/), and to download the result as GeoJSON.

```
(
    area["ISO3166-1"="RS"];
    area["ISO3166-1"="ME"];
);
(
    nwr[railway~"station|halt"](area);
);
out;
```

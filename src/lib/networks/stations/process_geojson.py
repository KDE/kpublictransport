#!/usr/bin/env python3

# SPDX-FileCopyrightText: 2024 Jonah Brüchert <jbb@kaidan.im>
# SPDX-License-Identifier: LGPL-2.0-or-later

import json

import sys

if len(sys.argv) < 3:
    print("Usage: ./process_geojson.py input.geojson country_network.json")
    sys.exit(1)

geojson_path = sys.argv[1]
output_path = sys.argv[2]

geojson = json.load(open(geojson_path, "r"))
if geojson["type"] != "FeatureCollection":
    print("Error: Unsupported GeoJSON type, this script only understands FeatureCollection")
    sys.exit(1)

timestamp = geojson["timestamp"]
features = geojson["features"]

stations = []

for feature in features:
    if feature["type"] != "Feature":
        print("Error: Unsupported feature type, this script only understands Feature")
        sys.exit(1)

    if feature["geometry"]["type"] != "Point":
        print("Error: Unsupported geometry, this script only understands Point. Make sure not to use geo in your Overpass Turbo query")
        sys.exit(1)

    properties = feature["properties"]
    name_keys = filter(lambda k: k.startswith("name") or k.startswith("alt_name") or k.startswith("int_name"), properties.keys())
    station = {k: properties[k] for k in name_keys}
    station["longitude"] = feature["geometry"]["coordinates"][1]
    station["latitude"] = feature["geometry"]["coordinates"][0]
    stations.append(station)

station_file = open(output_path, "w")
json.dump(stations, station_file, ensure_ascii=False)

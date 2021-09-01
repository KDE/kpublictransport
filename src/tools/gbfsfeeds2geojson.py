#!/usr/bin/env python3
#
# SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: LGPL-2.0-or-later
#
# Converts our GBFS feed repository into GeoJSON
# Useful for inspecting GBFS coverage areas

import argparse
import json
import os
import re

parser = argparse.ArgumentParser(description='Generates a GeoJSON document from GBFS feed repository')
parser.add_argument('--feeds', type=str, required=True, help='Path to the GBFS feed repository file')
arguments = parser.parse_args()

output = {}
output['type'] = 'FeatureCollection'
output['name'] = 'GBFS Feeds'
output['features'] = []

inFile = open(arguments.feeds, 'r')
inJson = json.load(inFile)

for feed in inJson:
    properties = {}
    properties['name'] = feed['systemId']
    properties['url'] = feed['discoveryUrl']
    feature = {}
    feature['type'] = 'Feature'
    feature['properties'] = properties

    geometry = {}
    geometry['type'] = 'Polygon'
    bb = feed['boudingBox']
    coords = [[bb['x1'], bb['y1']], [bb['x2'], bb['y1']], [bb['x2'], bb['y2']], [bb['x1'], bb['y2']], [bb['x1'], bb['y1']]]
    geometry['coordinates'] = [coords]
    feature['geometry'] = geometry

    output['features'].append(feature)

print(json.dumps(output))


#!/usr/bin/env python3
#
# SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: LGPL-2.0-or-later
#
# Converts a serialized journey query response into GeoJSON
# Useful for inspecting navigation path details in QGIS
#

import argparse
import json
import os
import re

parser = argparse.ArgumentParser(description='Generates a GeoJSON document from journey query result')
parser.add_argument('--journey', type=str, required=True, help='Path to the journey JSON')
arguments = parser.parse_args()

output = {}
output['type'] = 'FeatureCollection'
output['name'] = 'Journey Paths'
output['features'] = []

inFile = open(arguments.journey, 'r')
inJson = json.load(inFile)

for journey in inJson:
    for section in journey['sections']:
        for path in section['path']['sections']:
            properties = {}
            properties['name'] = path.get('description', '<anonymous>')
            feature = {}
            feature['type'] = 'Feature'
            feature['properties'] = properties
            feature['geometry'] = path['path']
            output['features'].append(feature)

print(json.dumps(output))

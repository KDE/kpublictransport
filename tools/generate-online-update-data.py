#!/usr/bin/env python3
#
# SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: LGPL-2.0-or-later
#
# Generates the online update data and manifest file from a current source code
# checkout.
#
# Usage:
# - Clone and/or update kpublictransport and autoconfig-kde-org to the latest state each.
# - Run generate-online-update-data.py --source <kpublictransport root folder> --output <autoconfig-kde-org root folder>/kpublictransport
# - Commit/push the changes in autoconfig-kde-org, if any

import argparse
import filecmp
import json
import os
import re
import shutil
import sys

parser = argparse.ArgumentParser(description='Generate KPublicTransport online update repository')
parser.add_argument('--source', type=str, required=True, help='Path of the kpublictransport source code root folder')
parser.add_argument('--output', type=str, required=True, help='Path of the online update data. Reuses pre-existing data for incremental updates')
parser.add_argument('--release', action='store_true', help='Current source code repository state is a release tag')
arguments = parser.parse_args()


def get_current_version():
    with open(os.path.join(arguments.source, "CMakeLists.txt"), 'r') as f:
        data = f.read()
        major = re.search(r'RELEASE_SERVICE_VERSION_MAJOR "(\d+)"', data).group(1)
        minor = re.search(r'RELEASE_SERVICE_VERSION_MINOR "(\d+)"', data).group(1)
        patch = re.search(r'RELEASE_SERVICE_VERSION_MICRO "(\d+)"', data).group(1)
        return f"{major}.{minor}.{patch}"
    sys.exit(1)


allowed_types = ['.json', '.geojson', '.pem', '.p12']
ignore_patterns = ['ch_sbb.json', 'eu_motislocal.json', 'un_transitous_staging.json']


def is_ignored(f: str) -> bool:
    if f in ignore_patterns:
        return True
    if any([f.endswith(t) for t in allowed_types]) is False:
        return True
    return False


current_version = get_current_version()
print(f"Updating to {current_version}…")

# resolve absolute in/out paths, wont work below anymore as we change the working dir
absSourcePath = os.path.abspath(arguments.source)
absOutputPath = os.path.abspath(arguments.output)

# load existing manifest, if available
manifest = None
try:
    with open(os.path.join(absOutputPath, 'manifest'), 'r') as f:
        manifest = json.load(f)
except Exception:
    pass
if not manifest:
    manifest = {}

old_entries = {}
for entry in manifest.get('entries', []):
    old_entries[entry['name']] = entry

manifest['entries'] = []
manifest['version'] = 2

# look for new or changed files
os.chdir(os.path.join(absSourcePath, 'src/lib/'))
for subdir, _, files in os.walk('networks'):
    print(f"Processing folder {subdir}…")
    for f in sorted(files):
        if is_ignored(f):
            continue

        entry = {}
        entry['version'] = current_version
        entry['name'] = f"{subdir}/{f}"
        if entry['name'] in old_entries:
            old_src = old_entries[entry['name']].get('source', '')
        f_base, f_ext = os.path.splitext(f)

        os.makedirs(os.path.join(absOutputPath, subdir), exist_ok=True)
        if not old_src or not os.path.isfile(os.path.join(absOutputPath, old_src)):
            print(f"Adding new file {f}…")
            entry['source'] = f"{subdir}/{f_base}-{current_version}{f_ext}"
            shutil.copy(os.path.join(subdir, f), os.path.join(absOutputPath, entry['source']))
            manifest['entries'].append(entry)
            continue

        if filecmp.cmp(os.path.join(subdir, f), os.path.join(absOutputPath, old_src), shallow=False):
            manifest['entries'].append(old_entries.get(f"{subdir}/{f}", entry))
            continue

        entry = old_entries.get(entry['name'], entry).copy()
        if entry['version'] == current_version and not arguments.release:
            entry['version'] = f"{current_version}.1"
        elif entry['version'].startswith(current_version) and not entry['version'] == current_version:
            entry['version'] = f"{current_version}.{int(entry['version'][len(current_version)+1:])+1}"
        else:
            entry['version'] = current_version
        entry['source'] = f"{subdir}/{f_base}-{entry['version']}{f_ext}"
        shutil.copy(os.path.join(subdir, f), os.path.join(absOutputPath, entry['source']))
        print(f"Updating file {subdir}/{f} to {entry['version']}…")
        manifest['entries'].append(entry)

# look for removed files
os.chdir(absOutputPath)
for subdir, _, files in os.walk('.'):
    for f in files:
        if f == "manifest":
            continue
        f_full = f"{subdir.lstrip('./')}/{f}"
        if not any([e.get('source', '') == f_full for _, e in old_entries.items()]) and not any([e['source'] == f_full for e in manifest['entries']]):
            print(f"Removing file {subdir}/{f}…")
            os.remove(os.path.join(absOutputPath, subdir, f))

with open(os.path.join(absOutputPath, 'manifest'), 'w') as f:
    s = json.dumps(manifest)
    s = re.sub(r'}, {', '},\n{', s)
    f.write(s)

#!/bin/sh
# SPDX-License-Identifier: LGPL-2.0-or-later
# SPDX-FileCopyrightText: Volker Krause <vkrause@kde.org>

for f in `find -name "*.svg"`; do
    if [ -f "$f.license" ]; then
        continue
    fi
    echo -e "SPDX-License-Identifier: CC0-1.0\\nSPDX-FileCopyrightText: https://github.com/gravitystorm/openstreetmap-carto" > $f.license
done

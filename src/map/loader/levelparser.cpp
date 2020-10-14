/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "levelparser_p.h"
#include "logging.h"

#include <osm/element.h>

#include <cstdlib>
#include <limits>

using namespace KOSMIndoorMap;

void LevelParser::parse(QByteArray &&level, OSM::Element e, const std::function<void(int, OSM::Element)> &callback)
{
    int rangeBegin = std::numeric_limits<int>::max();
    int numStartIdx = -1;

    for (int i = 0; i < level.size(); ++i) {
        auto c = level[i];

        if (c == ',') { // fix decimal separator errors
            qCDebug(Log) << "syntax error in level tag:" << level << e.url();
            c = '.';
        }

        if (std::isdigit(c) || c == '.') {
            if (numStartIdx < 0) {
                numStartIdx = i;
            }
            continue;
        }

        if (c == ';') {
            const auto l = std::atof(level.constData() + numStartIdx) * 10;
            if (rangeBegin <= l) {
                for (int j = rangeBegin; j <= l; j += 10) {
                    callback(j, e);
                }
                rangeBegin = std::numeric_limits<int>::max();
            } else {
                callback(l, e);
            }
            numStartIdx = -1;
            continue;
        }

        if (c == QLatin1Char('-')) {
            if (numStartIdx < 0) {
                numStartIdx = i;
            } else {
                rangeBegin = std::atof(level.constData() + numStartIdx) * 10;
                numStartIdx = -1;
            }
        }
    }

    if (numStartIdx >= level.size() || numStartIdx < 0) {
        return;
    }
    const auto l = std::atof(level.constData() + numStartIdx) * 10;
    if (rangeBegin <= l) {
        for (int j = rangeBegin; j <= l; j += 10) {
            callback(j, e);
        }
    } else {
        callback(l, e);
    }
}

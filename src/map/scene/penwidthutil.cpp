/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "penwidthutil.h"
#include "style/mapcssdeclaration.h"

using namespace KOSMIndoorMap;

double PenWidthUtil::penWidth(OSM::Element e, const MapCSSDeclaration *decl, Unit &unit)
{
    // literal value, possibly with a unit
    if (decl->keyValue().isEmpty()) {
        if (decl->unit() != MapCSSDeclaration::NoUnit) {
            unit = decl->unit() == MapCSSDeclaration::Meters ? Unit::Meter : Unit::Pixel;
        }
        return decl->doubleValue();
    }

    // referenced value from a tag value
    // see https://wiki.openstreetmap.org/wiki/Map_Features/Units
    double unitConversionFactor = 1.0;
    const auto value = e.tagValue(decl->keyValue().constData()).constData();
    const auto valueLen = std::strlen(value);

    char* numEnd;
    const auto num = std::strtod(value, &numEnd);
    while (numEnd < value + valueLen) {
        if (std::isspace(*numEnd)) {
            ++numEnd;
        }

        // there is an explicit unit suffix;
        if (std::strcmp(numEnd, "ft") == 0) {
            unitConversionFactor = 0.3048;
        }

        break;
    }
    // no explicit unit, use default unit for this tag
    if (numEnd == value + valueLen) {
        if (std::strcmp(decl->keyValue().constData(), "gauge") == 0) {
            unitConversionFactor = 0.001;
        }
    }

    unit = Unit::Meter;
    return num * unitConversionFactor;
}

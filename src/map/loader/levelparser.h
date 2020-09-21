/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_LEVELPARSER_H
#define KOSMINDOORMAP_LEVELPARSER_H

#include <functional>

namespace OSM {
class Element;
}

class QByteArray;

namespace KOSMIndoorMap {

/**
 * Parses OSM level tags
 * @see https://wiki.openstreetmap.org/wiki/Key:level
 * @see https://wiki.openstreetmap.org/wiki/Key:repeat_on
 * @see https://wiki.openstreetmap.org/wiki/Simple_Indoor_Tagging#Multi-level_features_and_repeated_features
 */
namespace LevelParser
{
    void parse(QByteArray &&level, OSM::Element e, const std::function<void(int, OSM::Element)> &callback);
}

}

#endif // KOSMINDOORMAP_LEVELPARSER_H

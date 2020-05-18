/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "maploader.h"

#include <osm/element.h>
#include <osm/xmlparser.h>

#include <QDebug>
#include <QFile>

using namespace KOSMIndoorMap;

void MapLoader::loadFromOsmXml(const QString &fileName)
{
    QFile f(fileName);
    if (!f.open(QFile::ReadOnly)) {
        qCritical() << f.fileName() << f.errorString();
        return;
    }

    OSM::XmlParser p(&m_dataSet);
    p.parse(&f);

    determineLevels();
}

void MapLoader::determineLevels()
{
    OSM::for_each(m_dataSet, [this](auto e) {
        const auto level = e.tagValue("level");
        const auto ls = level.splitRef(QLatin1Char(';'), QString::SkipEmptyParts);
        if (ls.isEmpty()) {
            return;
        }
        for (const auto &l : ls) {
            auto it = std::lower_bound(m_levels.begin(), m_levels.end(), l);
            if (it != m_levels.end() && (*it) == l) {
                return;
            }
            m_levels.insert(it, l.toString());
        }
    }, OSM::IncludeRelations | OSM::IncludeWays);
}

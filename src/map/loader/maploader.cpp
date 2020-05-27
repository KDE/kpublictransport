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
#include <osm/o5mparser.h>

#include <QDebug>
#include <QElapsedTimer>
#include <QFile>

inline void initResources()  // needs to be outside of a namespace
{
    Q_INIT_RESOURCE(assets);
}

using namespace KOSMIndoorMap;

MapLoader::MapLoader()
{
    initResources();
}

void MapLoader::loadFromO5m(const QString &fileName)
{
    QElapsedTimer loadTime;
    loadTime.start();

    QFile f(fileName);
    if (!f.open(QFile::ReadOnly)) {
        qCritical() << f.fileName() << f.errorString();
        return;
    }
    const auto data = f.map(0, f.size());

    OSM::DataSet ds;
    OSM::O5mParser p(&ds);
    p.parse(data, f.size());
    m_data.setDataSet(std::move(ds));
    qDebug() << "o5m loading took" << loadTime.elapsed() << "ms";
}

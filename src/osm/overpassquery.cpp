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

#include "overpassquery.h"

using namespace OSM;

OverpassQuery::OverpassQuery(QObject* parent)
    : QObject(parent)
{
}

OverpassQuery::~OverpassQuery() = default;

QString OverpassQuery::query() const
{
    return m_query;
}

QString OverpassQuery::query(const QRectF &bbox) const
{
    const QString bboxStr = QString::number(bbox.y()) + QLatin1Char(',') + QString::number(bbox.x()) + QLatin1Char(',') + QString::number(bbox.y() + bbox.height()) + QLatin1Char(',') + QString::number(bbox.x() + bbox.width());
    auto q = m_query;
    return q.replace(QLatin1String("{{bbox}}"), bboxStr);
}

void OverpassQuery::setQuery(const QString &query)
{
    m_query = query;
}

QRectF OverpassQuery::boundingBox() const
{
    return m_bbox;
}

void OverpassQuery::setBoundingBox(const QRectF &bbox)
{
    m_bbox = bbox;
}

QSizeF OverpassQuery::tileSize() const
{
    return m_tileSize;
}

void OverpassQuery::setTileSize(const QSizeF &tileSize)
{
    m_tileSize = tileSize;
}

OverpassQuery::Error OverpassQuery::error() const
{
    return m_error;
}

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

#ifndef KOSMINDOORMAP_SCENEGRAPHITEM_H
#define KOSMINDOORMAP_SCENEGRAPHITEM_H

#include <QBrush>
#include <QColor>
#include <QPen>
#include <QPolygonF>
#include <QString>

namespace KOSMIndoorMap {

/** Base class for scene graph items. */
class SceneGraphItem
{
public:
    virtual ~SceneGraphItem();

    int z = 0;
};


/** A path/way/line item in the scenegraph. */
class PolylineItem : public SceneGraphItem
{
public:
    QPolygonF path;
    QPen pen;
};


/** A single filled polygon. */
class PolygonItem : public SceneGraphItem
{
public:
    QPolygonF polygon;
    QBrush brush = Qt::NoBrush;
    QPen pen = Qt::NoPen;
};


/** A text or item label */
class LabelItem : public SceneGraphItem
{
public:
    QPointF pos;
    QString text;
    QColor color;
};


}

#endif // KOSMINDOORMAP_SCENEGRAPHITEM_H

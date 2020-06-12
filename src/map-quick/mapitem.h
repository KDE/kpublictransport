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

#ifndef KOSMINDOORMAP_MAPITEM_H
#define KOSMINDOORMAP_MAPITEM_H

#include "floorlevelmodel.h"
#include "osmelement.h"

#include <KOSMIndoorMap/MapData>
#include <KOSMIndoorMap/MapCSSStyle>
#include <KOSMIndoorMap/MapLoader>
#include <KOSMIndoorMap/PainterRenderer>
#include <KOSMIndoorMap/SceneController>
#include <KOSMIndoorMap/SceneGraph>
#include <KOSMIndoorMap/View>

#include <QQuickPaintedItem>

namespace KOSMIndoorMap {

/** Map renderer for the IndoorMap QML item.
 *  @internal Do not use directly!
 */
class MapItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(KOSMIndoorMap::MapLoader* loader READ loader CONSTANT)
    Q_PROPERTY(KOSMIndoorMap::View* view READ view CONSTANT)
    Q_PROPERTY(QString styleSheet READ styleSheetName WRITE setStylesheetName NOTIFY styleSheetChanged)
    Q_PROPERTY(KOSMIndoorMap::FloorLevelModel* floorLevels READ floorLevelModel CONSTANT)
public:
    explicit MapItem(QQuickItem *parent = nullptr);
    ~MapItem();

    void paint(QPainter *painter) override;

    MapLoader* loader() const;
    View* view() const;

    QString styleSheetName() const;
    void setStylesheetName(const QString &styleSheet);

    FloorLevelModel *floorLevelModel() const;

    Q_INVOKABLE KOSMIndoorMap::OSMElement elementAt(double x, double y) const;

Q_SIGNALS:
    void styleSheetChanged();
    void currentFloorLevelChanged();

protected:
    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry) override;

private:
    void clear();
    void loaderDone();

    MapLoader *m_loader = nullptr;
    MapData m_data;
    SceneGraph m_sg;
    View *m_view = nullptr;
    QString m_styleSheetName;
    MapCSSStyle m_style;
    SceneController m_controller;
    PainterRenderer m_renderer;
    FloorLevelModel *m_floorLevelModel = nullptr;
};

}

#endif // KOSMINDOORMAP_MAPITEM_H

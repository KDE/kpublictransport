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
public:
    explicit MapItem(QQuickItem *parent = nullptr);
    ~MapItem();

    void paint(QPainter *painter) override;

    MapLoader* loader() const;
    View* view() const;

    QString styleSheetName() const;
    void setStylesheetName(const QString &styleSheet);

Q_SIGNALS:
    void styleSheetChanged();

protected:
    void geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry) override;

private:
    void loaderDone();

    MapLoader *m_loader = nullptr;
    MapData m_data;
    SceneGraph m_sg;
    View *m_view = nullptr;
    QString m_styleSheetName;
    MapCSSStyle m_style;
    SceneController m_controller;
    PainterRenderer m_renderer;
};

}

#endif // KOSMINDOORMAP_MAPITEM_H

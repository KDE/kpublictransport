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

#include "mapitem.h"

#include <KOSMIndoorMap/MapCSSParser>

#include <QDebug>
#include <QPainter>

using namespace KOSMIndoorMap;

MapItem::MapItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
    , m_loader(new MapLoader(this))
    , m_view(new View(this))
    , m_floorLevelModel(new FloorLevelModel(this))
{
    connect(m_loader, &MapLoader::done, this, &MapItem::loaderDone);

    m_view->setScreenSize({100, 100}); // FIXME this breaks view when done too late!
    m_controller.setView(m_view);
    connect(m_view, &View::floorLevelChanged, this, [this]() { update(); });
}

MapItem::~MapItem() = default;

void MapItem::paint(QPainter *painter)
{
    m_controller.updateScene(m_sg);
    m_renderer.setPainter(painter);
    m_renderer.render(m_sg, m_view);
}

MapLoader* MapItem::loader() const
{
    return m_loader;
}

View* MapItem::view() const
{
    return m_view;
}

QString MapItem::styleSheetName() const
{
    return m_styleSheetName;
}

void MapItem::setStylesheetName(const QString &styleSheet)
{
    if (m_styleSheetName == styleSheet) {
        return;
    }
    m_styleSheetName = styleSheet;

    MapCSSParser cssParser;
    m_style = cssParser.parse(m_styleSheetName);
    m_style.compile(m_data.dataSet());
    m_controller.setStyleSheet(&m_style);

    emit styleSheetChanged();
    update();
}

FloorLevelModel* MapItem::floorLevelModel() const
{
    return m_floorLevelModel;
}

void MapItem::geometryChanged(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    QQuickPaintedItem::geometryChanged(newGeometry, oldGeometry);
    m_view->setScreenSize(newGeometry.size().toSize());
    qDebug() << newGeometry << m_view->zoomLevel();
}

void MapItem::loaderDone()
{
    m_floorLevelModel->setMapData(nullptr);
    m_sg.clear();
    m_data = m_loader->takeData();
    m_view->setSceneBoundingBox(m_data.boundingBox());
    m_controller.setDataSet(&m_data);
    m_style.compile(m_data.dataSet());
    m_controller.setStyleSheet(&m_style);
    m_view->setLevel(0);
    m_floorLevelModel->setMapData(&m_data);
    m_view->floorLevelChanged();
    update();
}

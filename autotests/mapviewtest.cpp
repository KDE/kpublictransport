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

#include <map/renderer/view.h>

#include <QTest>

using namespace KOSMIndoorMap;

class MapViewTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testProjection()
    {
        View v;
        QCOMPARE(v.mapGeoToScene(OSM::Coordinate{0.0, 0.0}), QPointF(128.0, 128.0));
        QCOMPARE(v.mapGeoToScene(OSM::Coordinate{0.0, -180.0}), QPointF(0.0, 128.0));
        QCOMPARE(v.mapGeoToScene(OSM::Coordinate{0.0, 180.0}), QPointF(256.0, 128.0));

        QCOMPARE(v.mapGeoToScene(OSM::Coordinate{90.0, 0.0}).toPoint().y(), 0);
        QCOMPARE(v.mapGeoToScene(OSM::Coordinate{85.0512, 0.0}).toPoint().y(), 0);
        QCOMPARE(v.mapGeoToScene(OSM::Coordinate{60.0, 0.0}).toPoint().y(), 74);
        QCOMPARE(v.mapGeoToScene(OSM::Coordinate{-60.0, 0.0}).toPoint().y(), 182);
        QCOMPARE(v.mapGeoToScene(OSM::Coordinate{-85.0512, 0.0}).toPoint().y(), 256.0);
        QCOMPARE(v.mapGeoToScene(OSM::Coordinate{-90.0, 0.0}).toPoint().y(), 256.0);

        QCOMPARE(v.mapGeoToScene(OSM::BoundingBox{OSM::Coordinate{-90.0, -180.0}, OSM::Coordinate{90.0, 180.0}}).toRect(), QRect(0, 0, 256, 256));
        QCOMPARE(v.mapGeoToScene(OSM::BoundingBox{OSM::Coordinate{0.0, 0.0}, OSM::Coordinate{90.0, 90.0}}).toRect(), QRect(128, 0, 64, 128));
    }

    void testViewport()
    {
        {
            View v;
            v.setScreenSize({100, 200});
            v.setSceneBoundingBox(QRectF{QPointF{13.0, 52.0}, QPointF{14.0, 54.0}});
            QCOMPARE(v.viewport(), QRectF(QPointF{13.0, 52.0}, QPointF{14.0, 54.0}));
        } {
            View v;
            v.setScreenSize({200, 100});
            v.setSceneBoundingBox(QRectF(QPointF{13.0, 52.0}, QPointF{14.0, 54.0}));
            QCOMPARE(v.viewport(), QRectF(QPointF{13.0, 52.0}, QPointF{14.0, 52.5}));
        } {
            View v;
            v.setScreenSize({100, 100});
            v.setSceneBoundingBox(QRectF(QPointF{13.0, 52.0}, QPointF{14.0, 54.0}));
            QCOMPARE(v.viewport(), QRectF(QPointF{13.0, 52.0}, QPointF{14.0, 53.0}));
        }
    }

    void testTransform()
    {
        {
            View v;
            v.setScreenSize({100, 100});
            v.setSceneBoundingBox(QRectF(QPointF{13.0, 53.0}, QPointF{14.0, 54.0}));
            QCOMPARE(v.sceneToScreenTransform().m11(), 100.0);
            QCOMPARE(v.sceneToScreenTransform().m22(), 100.0);
            QCOMPARE(v.sceneToScreenTransform().m31(), -1300.0);
            QCOMPARE(v.sceneToScreenTransform().m32(), -5300.0);
        } {
            View v;
            v.setScreenSize({100, 100});
            v.setSceneBoundingBox(QRectF(QPointF{13.0, 52.0}, QPointF{15.0, 53.0}));
            QCOMPARE(v.sceneToScreenTransform().m11(), 100.0);
            QCOMPARE(v.sceneToScreenTransform().m22(), 100.0);
            QCOMPARE(v.sceneToScreenTransform().m31(), -1300.0);
            QCOMPARE(v.sceneToScreenTransform().m32(), -5200.0);
        } {
            View v;
            v.setScreenSize({100, 200});
            v.setSceneBoundingBox(QRectF(QPointF{13.0, 52.0}, QPointF{13.1, 52.5}));
            QCOMPARE(v.sceneToScreenTransform().m11(), 1000.0);
            QCOMPARE(v.sceneToScreenTransform().m22(), 1000.0);
            QCOMPARE(v.sceneToScreenTransform().m31(), -13000.0);
            QCOMPARE(v.sceneToScreenTransform().m32(), -52000.0);
        }
    }

    void testZoomLevel()
    {
        View v;
        v.setScreenSize({512, 256});
        v.setSceneBoundingBox(QRectF(QPointF{-180.0, -90.0}, QPointF{180.0, 90.0}));
        QCOMPARE(v.zoomLevel(), 1.0);
        v.setScreenSize({1024, 512});
        v.setSceneBoundingBox(QRectF(QPointF{-180.0, -90.0}, QPointF{180.0, 90.0}));
        QCOMPARE(v.zoomLevel(), 2.0);
        v.zoomIn();
        QCOMPARE(v.zoomLevel(), 3.0);
        v.zoomOut();
        QCOMPARE(v.zoomLevel(), 2.0);
    }
};

QTEST_GUILESS_MAIN(MapViewTest)

#include "mapviewtest.moc"

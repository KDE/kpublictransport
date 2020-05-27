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

#include <map/scene/scenegeometry.h>

#include <QFile>
#include <QTest>

using namespace KOSMIndoorMap;

class SceneGeometryTest: public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testPolygonCenter()
    {
        QPolygonF p1{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
        QCOMPARE(SceneGeometry::polygonCentroid(p1), QPointF(0, 0));

        QPolygonF p2{{{0, 1}, {1, 1}, {1, 0}, {0, 0}}};
        QCOMPARE(SceneGeometry::polygonCentroid(p2), QPointF(0.5, 0.5));

        QPolygonF p3{{{0, 1}, {1, 0}, {0, -1}, {-0.5, -0.5}, {-1, 0}}};
        QCOMPARE(SceneGeometry::polygonCentroid(p3), QPointF(0, 0));

        QPolygonF p4{{{0.273, 0.146}, {0.423, 0.496}, {0.415, 0.499}, {0.266, 0.149}}};
//         QCOMPARE((SceneGeometry::polygonCentroid(p4) * 1000000).toPoint(), QPoint(345669, 325821));
        // make the test pass on 32bit platforms too
        QCOMPARE((SceneGeometry::polygonCentroid(p4) * 1000000).toPoint().x(), 345669);
        QVERIFY((SceneGeometry::polygonCentroid(p4) * 1000000).toPoint().y() >= 325821);
        QVERIFY((SceneGeometry::polygonCentroid(p4) * 1000000).toPoint().y() <= 325822);

        QPolygonF p5{{{273, 146}, {423, 496}, {415, 499}, {266, 149}}};
//         QCOMPARE((SceneGeometry::polygonCentroid(p5) * 1000).toPoint(), QPoint(345669, 325821));
        // make the test pass on 32bit platforms too
        QCOMPARE((SceneGeometry::polygonCentroid(p5) * 1000).toPoint().x(), 345669);
        QVERIFY((SceneGeometry::polygonCentroid(p5) * 1000).toPoint().y() >= 325821);
        QVERIFY((SceneGeometry::polygonCentroid(p5) * 1000).toPoint().y() <= 325822);
    }

    void testLineMidPoint()
    {
        QPolygonF p1{{{1,1}, {2,2}, {2,2}}};
        QCOMPARE(SceneGeometry::polylineMidPoint(p1), QPointF(1.5, 1.5));

        QPolygonF p2{{{1,1}, {2,2}, {3,3}}};
        QCOMPARE(SceneGeometry::polylineMidPoint(p2), QPointF(2, 2));

        QPolygonF p3{{{1,1}, {2,2}, {21,21}}};
        QCOMPARE(SceneGeometry::polylineMidPoint(p3), QPointF(11, 11));
    }

    void testPathAngle()
    {
        QPolygonF p1{{{1,1}, {2,2}, {2,2}}};
        QCOMPARE(SceneGeometry::polylineMidPointAngle(p1), 45.0);

        QPolygonF p2{{{1,1}, {2,2}, {2,20}}};
        QCOMPARE(SceneGeometry::polylineMidPointAngle(p2), 90.0);
    }
};

QTEST_GUILESS_MAIN(SceneGeometryTest)

#include "scenegeometrytest.moc"

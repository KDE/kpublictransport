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

#include <map/loader/marblegeometryassembler.h>

#include <QDateTime>
#include <QTest>

using namespace KOSMIndoorMap;

#define ADD_NODE(_id, lat, lon) { OSM::Node n; n.id = _id; n.coordinate = OSM::Coordinate(lat, lon); dataSet.addNode(std::move(n)); }

class MarbleGeometryAssemblerTest : public QObject
{
    Q_OBJECT
private Q_SLOTS:
    void testAreaMerge()
    {
        OSM::DataSet dataSet;
        OSM::DataSetMergeBuffer mergeBuffer;
        auto mxoidKey = dataSet.makeTagKey("mx:oid");

        // a 1x1 square around 0,0, cut along the 0 y-axis
        ADD_NODE(1, 1.0, -1.0)
        ADD_NODE(2, -1.0, -1.0)
        ADD_NODE(3, -1.0, 1.0)
        ADD_NODE(4, 1.0, 1.0)

        ADD_NODE(-1, 1.0, 0.0)
        ADD_NODE(-2, -1.0, 0.0)
        ADD_NODE(-3, 1.0, 0.0) // synthectic nodes are duplicated for each part
        ADD_NODE(-4, -1.0, 0.0)

        {
            OSM::Way w;
            w.id = 42;
            w.nodes = {-2, -1, 1, 2, -2};
            dataSet.addWay(std::move(w));
        }
        {
            OSM::Way w;
            w.id = -23;
            w.nodes = { 3, 4, -3, -4, 3};
            OSM::setTagValue(w, mxoidKey, QString::number(42));
            mergeBuffer.ways.push_back(std::move(w));
        }

        MarbleGeometryAssembler assembler;
        assembler.merge(&dataSet, &mergeBuffer);

        QCOMPARE(dataSet.ways.size(), 1);
        const auto &way = dataSet.ways.front();
        QCOMPARE(way.id, 42);
        QCOMPARE(way.nodes.size(), 5);
        QCOMPARE(way.isClosed(), true);
        QCOMPARE(way.nodes, std::vector<OSM::Id>({3, 4, 1, 2, 3}));
    }
};

QTEST_GUILESS_MAIN(MarbleGeometryAssemblerTest)

#include "marblegeometryassemblertest.moc"

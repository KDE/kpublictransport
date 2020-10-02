/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <map/loader/maploader.h>

#include <osm/xmlwriter.h>

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>

using namespace KOSMIndoorMap;

static void filterByBbox(OSM::DataSet &dataSet, OSM::BoundingBox bbox)
{
    dataSet.relations.erase(std::remove_if(dataSet.relations.begin(), dataSet.relations.end(), [bbox](const auto &rel) {
        return !OSM::intersects(rel.bbox, bbox);
    }), dataSet.relations.end());
    dataSet.ways.erase(std::remove_if(dataSet.ways.begin(), dataSet.ways.end(), [bbox](const auto &way) {
        return !OSM::intersects(way.bbox, bbox);
    }), dataSet.ways.end());
    dataSet.nodes.erase(std::remove_if(dataSet.nodes.begin(), dataSet.nodes.end(), [bbox](const auto &nd) {
        return !OSM::contains(bbox, nd.coordinate);
    }), dataSet.nodes.end());
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QCommandLineParser parser;
    parser.addHelpOption();
    QCommandLineOption bboxOpt({QStringLiteral("b"), QStringLiteral("bbox")}, QStringLiteral("bounding box to download"), QStringLiteral("minlat,minlon,maxlat,maxlon"));
    parser.addOption(bboxOpt);
    QCommandLineOption outOpt({QStringLiteral("o"), QStringLiteral("out")}, QStringLiteral("output file"), QStringLiteral("file"));
    parser.addOption(outOpt);
    parser.process(app);

    if (!parser.isSet(bboxOpt) || !parser.isSet(outOpt)) {
        parser.showHelp(1);
        return 1;
    }

    OSM::BoundingBox bbox;
    const auto coords = parser.value(bboxOpt).splitRef(QLatin1Char(','));
    if (coords.size() == 4) {
        bbox.min = OSM::Coordinate(coords[0].toDouble(), coords[1].toDouble());
        bbox.max = OSM::Coordinate(coords[2].toDouble(), coords[3].toDouble());
    }
    if (!bbox.isValid()) {
        qCritical() << "Invalid bounding box!";
        return 1;
    }
    qDebug() << bbox << bbox.center();

    MapLoader loader;
    loader.loadForCoordinate(bbox.center().latF(), bbox.center().lonF()); // TODO add the ability to load an entire bbox
    QObject::connect(&loader, &MapLoader::done, &app, &QCoreApplication::quit);
    app.exec();

    auto data = loader.takeData();
    filterByBbox(data.dataSet(), bbox);

    QFile f(parser.value(outOpt));
    if (!f.open(QFile::WriteOnly)) {
        qCritical() << f.errorString();
        return 1;
    }
    OSM::XmlWriter::write(data.dataSet(), &f);
    return 0;
}

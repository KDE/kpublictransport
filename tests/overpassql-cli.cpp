/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <overpassquery.h>
#include <overpassquerymanager.h>

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QJsonDocument>

#include <iostream>

#define S(x) QStringLiteral(x)

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QCommandLineParser parser;
    parser.setApplicationDescription(S("overpassql-cli"));
    parser.addHelpOption();
    QCommandLineOption queryOption({ S("q"), S("query") }, S("Overpass QL query to run"), S("query-string"));
    parser.addOption(queryOption);
    QCommandLineOption queryFileOption({ S("f"), S("query-file") }, S("File to read Overpass QL query from"), S("query-file"));
    parser.addOption(queryFileOption);
    QCommandLineOption bboxOption({ S("b"), S("bbox") }, S("Query bounding box"), S("x,y,w,h"));
    parser.addOption(bboxOption);
    QCommandLineOption tileSizeOption({ S("t"), S("tile-size") }, S("Query tile size"), S("w,h"));
    parser.addOption(tileSizeOption);
    parser.process(app);

    OSM::OverpassQueryManager mgr;
    OSM::OverpassQuery query;

    if (parser.isSet(queryFileOption)) {
        QFile f(parser.value(queryFileOption));
        if (!f.open(QFile::ReadOnly)) {
            std::cerr << "failed to read query file: " << qPrintable(f.errorString()) << std::endl;
            return 1;
        }
        query.setQuery(QString::fromUtf8(f.readAll()));
    } else {
        query.setQuery(parser.value(queryOption));
    }

    if (parser.isSet(bboxOption)) {
        const auto s = parser.value(bboxOption).split(QLatin1Char(','));
        if (s.size() != 4) {
            std::cerr << "invalid bbox format" << std::endl;
            return 1;
        }
        QRectF bbox(s[0].toDouble(), s[1].toDouble(), s[2].toDouble(), s[3].toDouble());
        query.setBoundingBox(bbox);
    }

    if (parser.isSet(tileSizeOption)) {
        const auto s = parser.value(tileSizeOption).split(QLatin1Char(','));
        if (s.size() != 2) {
            std::cerr << "invalid tile size format" << std::endl;
            return 1;
        }
        QSizeF tileSize(s[0].toDouble(), s[1].toDouble());
        query.setTileSize(tileSize);
    }

    QObject::connect(&query, &OSM::OverpassQuery::finished, [&query, &app]() {
        if (query.error() != OSM::OverpassQuery::NoError) {
            std::cerr << "query error" << std::endl;
            app.exit(1);
        }

        // ### for testing only
        const auto &res = query.result();
        for (const auto &node : res.nodes) {
            qDebug() << "Node" << node.id << node.coordinate.latitude << node.coordinate.longitude;
            for (const auto &tag : node.tags) {
                qDebug() << "  tag" << tag.key.name() << tag.value;
            }
        }
        for (const auto &rel : res.relations) {
            qDebug() << "Relation" << rel.id << rel.bbox.min.latitude << rel.bbox.min.longitude << rel.bbox.max.latitude << rel.bbox.max.longitude;
            for (const auto &mem : rel.members) {
                qDebug() << "  member" << mem.id << (int)mem.type() << mem.role().name();
            }
            for (const auto &tag : rel.tags) {
                qDebug() << "  tag" << tag.key.name() << tag.value;
            }
        }

        app.quit();
    });
    mgr.execute(&query);

    return app.exec();
}

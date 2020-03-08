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

#include <overpassquery.h>
#include <overpassquerymanager.h>

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QJsonDocument>

#include <iostream>

#define S(x) QStringLiteral(x)

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QCommandLineParser parser;
    parser.setApplicationDescription(S("overpassql-cli"));
    parser.addHelpOption();
    QCommandLineOption queryOption({ S("q"), S("query") }, S("GraphQL query to run"), S("query-string"));
    parser.addOption(queryOption);
    QCommandLineOption bboxOption({ S("b"), S("bbox") }, S("Query bounding box"), S("x,y,w,h"));
    parser.addOption(bboxOption);
    QCommandLineOption tileSizeOption({ S("t"), S("tile-size") }, S("Query tile size"), S("w,h"));
    parser.addOption(tileSizeOption);
    parser.process(app);

    OSM::OverpassQueryManager mgr;
    OSM::OverpassQuery query;
    query.setQuery(parser.value(queryOption));

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
                qDebug() << "  tag" << tag.key << tag.value;
            }
        }

        app.quit();
    });
    mgr.execute(&query);

    return app.exec();
}

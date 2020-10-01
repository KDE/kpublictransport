/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <map/loader/maploader.h>

#include <osm/xmlwriter.h>

#include <QCoreApplication>

using namespace KOSMIndoorMap;

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    MapLoader loader;
    loader.loadForCoordinate(53.55267, 9.93517); // TODO make this a CLI argument, add the ability to load an entire bbox
    QObject::connect(&loader, &MapLoader::done, &app, &QCoreApplication::quit);
    app.exec();

    const auto data = loader.takeData();
    QFile f(QStringLiteral("out.xml")); // TODO
    if (!f.open(QFile::WriteOnly)) {
        qCritical() << f.errorString();
        return 1;
    }
    OSM::XmlWriter::write(data.dataSet(), &f);
    return 0;
}

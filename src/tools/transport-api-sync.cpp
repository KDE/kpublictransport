/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <QCoreApplication>
#include <QDirIterator>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

#include <iostream>

/** Sync network configurations with upstream transport API repository. */
int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    if (app.arguments().size() <= 1) {
        std::cerr << "Usage: " << argv[0] << " [path to network configs]" << std::endl;
        return 1;
    }

    // ### temporary to migrate our format closer to the standard format
    QDirIterator it(app.arguments().at(1), QDir::Files);
    while (it.hasNext()) {
        const auto fileName = it.next();
        QFile f(fileName);
        if (!f.fileName().endsWith(QLatin1String(".json"))) {
            continue;
        }
        if (!f.open(QFile::ReadOnly)) {
            qWarning() << "Failed to open" << f.fileName() << f.errorString();
            continue;
        }

        const auto doc = QJsonDocument::fromJson(f.readAll());
        auto topObj = doc.object();

        qDebug() << "Updating" << fileName;
        auto poly = topObj.value(QLatin1String("filter")).toObject().value(QLatin1String("geo")).toArray();
        if (poly.empty()) {
            continue;
        }
        poly.push_back(poly.at(0)); // close the polygon, required by GeoJSON

        QJsonObject area;
        area.insert(QLatin1String("type"), QLatin1String("Polygon"));
        area.insert(QLatin1String("coordinates"), QJsonArray({poly}));
        QJsonObject anyCoverage;
        anyCoverage.insert(QLatin1String("area"), area);
        QJsonObject coverage;
        coverage.insert(QLatin1String("anyCoverage"), anyCoverage);
        topObj.insert(QLatin1String("coverage"), coverage);
        topObj.remove(QLatin1String("filter"));

        f.close();
        f.open(QFile::WriteOnly | QFile::Truncate);
        f.write(QJsonDocument(topObj).toJson());
    }
}

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../lib/geo/geojson_p.h"

#include <QCoreApplication>
#include <QDebug>
#include <QDirIterator>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QPolygonF>
#include <QRectF>

#include <iostream>

static void fillNetworkConfig(QNetworkReply *reply, QJsonObject &obj)
{
    const auto desc = QJsonDocument::fromJson(reply->readAll()).object();

    // clean up the coverage polygon we get, that often contains bogus outliers
    using namespace KPublicTransport;
    auto poly = GeoJson::readOuterPolygon(desc.value(QLatin1String("polygon")).toObject());
    // TODO: more elaborate outlier detection, null points is just one of the problems
    poly.erase(std::remove_if(poly.begin(), poly.end(), [](auto p) { return p.isNull(); }), poly.end());
    if (poly.empty()) {
        return;
    }
    if (!poly.isClosed()) {
        poly.push_back(poly.front());
    }

    auto coverage = obj.value(QLatin1String("coverage")).toObject();
    auto rtCoverage = coverage.value(QLatin1String("realtimeCoverage")).toObject();
    rtCoverage.insert(QLatin1String("area"), GeoJson::writePolygon(poly));
    coverage.insert(QLatin1String("realtimeCoverage"), rtCoverage);
    obj.insert(QLatin1String("coverage"), coverage);
}

/** Inspects OTP-based backends and queries their bounding boxes. */
int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    if (app.arguments().size() <= 1) {
        std::cerr << "Usage: " << argv[0] << " [path to network configs]" << std::endl;
        return 1;
    }

    QNetworkAccessManager nam;
    nam.setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);

    int jobCount = 0;
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
        const auto obj = doc.object();
        const auto typeObj = obj.value(QLatin1String("type")).toObject();
        if (!typeObj.contains(QLatin1String("otpRest")) && !typeObj.contains(QLatin1String("otpGraphQl"))) {
            continue;
        }

        qDebug() << "Updating" << fileName;
        const auto options = obj.value(QLatin1String("options")).toObject();
        const auto url = options.value(QLatin1String("endpoint")).toString();
        const auto caCerts = QSslCertificate::fromPath(it.path() + QStringLiteral("/certs/") + options.value(QLatin1String("customCaCertificate")).toString());
        ++jobCount;
        auto req = QNetworkRequest(QUrl(url));
        if (!caCerts.empty()) {
            auto sslConfig = req.sslConfiguration();
            sslConfig.setCaCertificates(caCerts);
            req.setSslConfiguration(std::move(sslConfig));
        }
        auto reply = nam.get(req);
        QObject::connect(reply, &QNetworkReply::finished, &nam, [reply, &jobCount, obj, fileName]() {
            if (reply->error() == QNetworkReply::NoError) {
                auto newConfig = obj;
                fillNetworkConfig(reply, newConfig);
                QFile f(fileName);
                if (!f.open(QFile::WriteOnly)) {
                    qWarning() << "Failed to open network config for writing:" << fileName << f.errorString();
                } else {
                    f.write(QJsonDocument(newConfig).toJson());
                }
            } else {
                qWarning() << reply->errorString();
            }
            reply->deleteLater();
            --jobCount;
            if (jobCount == 0) {
                QCoreApplication::quit();
            }
        });
    }

    return jobCount ? app.exec() : 0;
}

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <QCoreApplication>
#include <QDebug>
#include <QDirIterator>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QRectF>

#include <iostream>

static void fillNetworkConfig(QNetworkReply *reply, QJsonObject &obj)
{
    const auto desc = QJsonDocument::fromJson(reply->readAll()).object();
    QRectF boundingBox;
    boundingBox.setBottom(desc.value(QLatin1String("lowerLeftLatitude")).toDouble());
    boundingBox.setLeft(desc.value(QLatin1String("lowerLeftLongitude")).toDouble());
    boundingBox.setTop(desc.value(QLatin1String("upperRightLatitude")).toDouble());
    boundingBox.setRight(desc.value(QLatin1String("upperRightLongitude")).toDouble());
    QJsonArray geoFilter;
    for (const auto &point : {boundingBox.topLeft(), boundingBox.topRight(), boundingBox.bottomRight(), boundingBox.bottomLeft()}) {
        QJsonArray p;
        p.push_back(point.x());
        p.push_back(point.y());
        geoFilter.push_back(p);
    }
    QJsonObject filter;
    filter.insert(QStringLiteral("geo"), geoFilter);
    obj.insert(QStringLiteral("filter"), filter);
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

        QJsonParseError docError;
        const auto doc = QJsonDocument::fromJson(f.readAll(), &docError);
        if (docError.error != QJsonParseError::NoError) {
            qWarning() << "JSON parser error in" << fileName << docError.errorString();
            continue;
        }
        const auto obj = doc.object();
        if (!obj.value(QLatin1String("type")).toString().startsWith(QLatin1String("otp_"))) {
            continue;
        }

        qDebug() << "Updating" << fileName;
        const auto url = obj.value(QLatin1String("options")).toObject().value(QLatin1String("endpoint")).toString();
        ++jobCount;
        auto reply = nam.get(QNetworkRequest(QUrl(url)));
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

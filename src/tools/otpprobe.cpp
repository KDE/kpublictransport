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

#include <cmath>
#include <iostream>

class OtpProbeJob : public QObject
{
    Q_OBJECT
public:
    explicit OtpProbeJob(const QString &fileName, const QJsonDocument &doc, QNetworkAccessManager *nam, QObject *parent = nullptr);
    void start();

Q_SIGNALS:
    void finished();

private:
    void applySslConfig(QNetworkRequest &req);
    void bboxFetchDone(QNetworkReply *reply);
    void stopsFetchDone(QNetworkReply *reply);
    void writeConfigFile();

    QString m_configFileName;
    QJsonDocument m_configDoc;
    QNetworkAccessManager *m_nam;
    QUrl m_endpointUrl;
    QPolygonF m_boundingPolygon;
    QList<QSslCertificate> m_caCerts;
};

OtpProbeJob::OtpProbeJob(const QString &fileName, const QJsonDocument &doc, QNetworkAccessManager *nam, QObject *parent)
    : QObject(parent)
    , m_configFileName(fileName)
    , m_configDoc(doc)
    , m_nam(nam)
{
}

void OtpProbeJob::applySslConfig(QNetworkRequest &req)
{
    if (!m_caCerts.empty()) {
        auto sslConfig = req.sslConfiguration();
        sslConfig.setCaCertificates(m_caCerts);
        req.setSslConfiguration(std::move(sslConfig));
    }
}

void OtpProbeJob::start()
{
    const auto options = m_configDoc.object().value(QLatin1String("options")).toObject();
    m_endpointUrl = QUrl(options.value(QLatin1String("endpoint")).toString());
    m_caCerts = QSslCertificate::fromPath(QFileInfo(m_configFileName).path() + QStringLiteral("/certs/") + options.value(QLatin1String("customCaCertificate")).toString());
    auto req = QNetworkRequest(m_endpointUrl);
    applySslConfig(req);
    auto reply = m_nam->get(req);
    connect(reply, &QNetworkReply::finished, this, [reply, this]() { bboxFetchDone(reply); });
}

void OtpProbeJob::bboxFetchDone(QNetworkReply *reply)
{
    reply->deleteLater();
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << reply->errorString() << reply->url();
    }

    const auto desc = QJsonDocument::fromJson(reply->readAll()).object();
    m_boundingPolygon = KPublicTransport::GeoJson::readOuterPolygon(desc.value(QLatin1String("polygon")).toObject());
    // TODO: more elaborate outlier detection, null points is just one of the problems
    m_boundingPolygon.erase(std::remove_if(m_boundingPolygon.begin(), m_boundingPolygon.end(), [](auto p) { return p.isNull(); }), m_boundingPolygon.end());

    auto req = QNetworkRequest(QUrl(m_endpointUrl.toString() + QLatin1String("index/stops")));
    applySslConfig(req);
    auto stopReply = m_nam->get(req);
    connect(stopReply, &QNetworkReply::finished, this, [stopReply, this]() { stopsFetchDone(stopReply); });
}

static void filterOutliers(std::vector<double> vec, double &lowerBound, double &upperBound)
{
    std::sort(vec.begin(), vec.end());

    const auto n = vec.size();
    const auto mean = std::accumulate(vec.begin(), vec.end(), 0.0, [n](auto a, auto b) { return a + b / n; });
    auto sigma = std::accumulate(vec.begin(), vec.end(), 0.0, [n](auto a, auto b) {
        return a + (std::pow(b, 2.0) / n);
    });
    sigma = std::sqrt(sigma - std::pow(mean, 2.0)) * 3.0;

    lowerBound = mean - sigma;
    auto it = std::lower_bound(vec.begin(), vec.end(), lowerBound);
    if (it != vec.end()) {
        lowerBound = (*it);
    }
    upperBound = mean + sigma;
    it = std::lower_bound(vec.begin(), vec.end(), upperBound);
    if (it != vec.begin()) {
        upperBound = *(std::prev(it));
    }

    lowerBound = std::max(lowerBound, vec.front());
    upperBound = std::min(upperBound, vec.back());
}

void OtpProbeJob::stopsFetchDone(QNetworkReply *reply)
{
    reply->deleteLater();
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << reply->errorString() << reply->url();
    }

    std::vector<double> lats, lons;
    const auto stops = QJsonDocument::fromJson(reply->readAll()).array();
    lats.reserve(stops.size());
    lons.reserve(stops.size());
    for (const auto &stopV : stops) {
        const auto stopObj = stopV.toObject();
        const auto lat = stopObj.value(QLatin1String("lat")).toDouble();
        const auto lon = stopObj.value(QLatin1String("lon")).toDouble();

        if (std::abs(lat) < 1.0 && std::abs(lon) < 1.0) {
            continue;
        }

        lats.push_back(lat);
        lons.push_back(lon);
    }


    if (lons.size() > 2 || lats.size() > 2) {
        double latMin, latMax, lonMin, lonMax;
        filterOutliers(lats, latMin, latMax);
        filterOutliers(lons, lonMin, lonMax);
        // TODO even better would be computing the concave hull of all points after outlier filtering
        QRectF box(QPointF(lonMin, latMin), QPointF(lonMax, latMax));
        m_boundingPolygon = m_boundingPolygon.intersected(box);
    } else {
        qDebug() << "didn't get stop data:" << reply->url();
    }

    writeConfigFile();
}

void OtpProbeJob::writeConfigFile()
{
    if (m_boundingPolygon.size() >= 4) {
        if (!m_boundingPolygon.isClosed()) {
            m_boundingPolygon.push_back(m_boundingPolygon.front());
        }

        auto obj = m_configDoc.object();
        auto coverage = obj.value(QLatin1String("coverage")).toObject();
        auto rtCoverage = coverage.value(QLatin1String("realtimeCoverage")).toObject();
        rtCoverage.insert(QLatin1String("area"), KPublicTransport::GeoJson::writePolygon(m_boundingPolygon));
        coverage.insert(QLatin1String("realtimeCoverage"), rtCoverage);
        obj.insert(QLatin1String("coverage"), coverage);

        QFile f(m_configFileName);
        if (!f.open(QFile::WriteOnly)) {
            qWarning() << "Failed to open network config for writing:" << m_configFileName << f.errorString();
        } else {
            f.write(QJsonDocument(obj).toJson());
        }
    }

    Q_EMIT finished();
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
        auto job = new OtpProbeJob(fileName, doc, &nam);
        QObject::connect(job, &OtpProbeJob::finished, &nam, [&jobCount, job]() {
            --jobCount;
            job->deleteLater();
            if (jobCount == 0) {
                QCoreApplication::quit();
            }
        });
        ++jobCount;
        job->start();
    }

    return jobCount ? app.exec() : 0;
}

#include "otpprobe.moc"

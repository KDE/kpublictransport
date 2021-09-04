
/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <gbfs/gbfsjob.h>
#include <gbfs/gbfsservice.h>

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
#include <QTimer>

#include <iostream>
#include <random>

using namespace KPublicTransport;

/** Determine bounding boxes of the initial set of GBFS feeds we ship. */
class GBFSProbe : public QObject
{
    Q_OBJECT
public:
    explicit GBFSProbe(QObject *parent = nullptr);

    void start();
    void getFeedList();
    void discoverNextFeed();
    void writeFeeds();

    QNetworkAccessManager m_nam;
    QStringList m_gbfsFeeds;
    int m_currentFeedIdx = -1;
    int m_throttleTime = 0;
    QStringList m_throttledFeeds;

    std::vector<GBFSService> m_services;
    QString m_outputFileName;
};

GBFSProbe::GBFSProbe(QObject *parent)
    : QObject(parent)
{
    m_nam.setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);
}

void GBFSProbe::start()
{
    getFeedList();
}

void GBFSProbe::getFeedList()
{
    auto reply = m_nam.get(QNetworkRequest(QUrl(QStringLiteral("https://raw.githubusercontent.com/NABSA/gbfs/master/systems.csv"))));
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCritical() << reply->errorString();
            QCoreApplication::exit(1);
            return;
        }

        reply->readLine(); // skip header line
        while (!reply->atEnd()) {
            auto line = reply->readLine();
            line.replace("http:", "https:");
            const auto idx = line.lastIndexOf("https");
            if (idx < 0) {
                continue;
            }
            line = line.mid(idx).trimmed();
            if (line.endsWith('"')) {
                line.chop(1);
            }
            m_gbfsFeeds.push_back(QString::fromUtf8(line));
        }

        std::sort(m_gbfsFeeds.begin(), m_gbfsFeeds.end());
        m_gbfsFeeds.erase(std::unique(m_gbfsFeeds.begin(), m_gbfsFeeds.end()), m_gbfsFeeds.end());

        QFile extraFeeds(QStringLiteral("gbfs-feeds.txt"));
        if (!extraFeeds.open(QFile::ReadOnly)) {
            qCritical() << extraFeeds.errorString();
            QCoreApplication::exit(1);
            return;
        }
        const auto lines = QString::fromUtf8(extraFeeds.readAll()).split(QLatin1Char('\n'));
        for (const auto &line : lines) {
            const auto extraFeed = line.trimmed();
            if (extraFeed.isEmpty()) {
                continue;
            }

            const auto it = std::lower_bound(m_gbfsFeeds.begin(), m_gbfsFeeds.end(), extraFeed);
            if (it != m_gbfsFeeds.end() && (*it) == extraFeed) {
                qDebug() << "Extra feed already in NABSA systems.csv:" << extraFeed;
                continue;
            }
            m_gbfsFeeds.insert(it, extraFeed);
        }

        qDebug() << "Found" << m_gbfsFeeds.size() << "possible feeds - running discovery on them...";
        std::shuffle(m_gbfsFeeds.begin(), m_gbfsFeeds.end(), std::default_random_engine()); // reduce risk of spamming the same service with too many requests
        discoverNextFeed();
    });
}

void GBFSProbe::discoverNextFeed()
{
    ++m_currentFeedIdx;
    if (m_currentFeedIdx >= m_gbfsFeeds.size()) {
        if (!m_throttledFeeds.isEmpty()) {
            qDebug() << "Retrying for" << m_throttledFeeds.size() << "throttled feeds";
            m_gbfsFeeds = std::move(m_throttledFeeds);
            std::shuffle(m_gbfsFeeds.begin(), m_gbfsFeeds.end(), std::default_random_engine());
            m_throttledFeeds.clear();
            m_currentFeedIdx = 0;
            m_throttleTime = m_throttleTime == 0 ? 500 : (2 * m_throttleTime);
        } else {
            writeFeeds();
            return;
        }
    }

    auto job = new GBFSJob(&m_nam);
    job->setRequestedData({GBFS::StationInformation, GBFS::FreeBikeStatus, GBFS::GeofencingZones}); // everything we can use for the bounding box
    QObject::connect(job, &GBFSJob::finished, this, [job, this]() {
        job->deleteLater();
        if (job->error() == GBFSJob::TooManyRequestsError) {
            m_throttledFeeds.push_back(m_gbfsFeeds[m_currentFeedIdx]);
            qWarning() << "Scheduling for later:" << m_gbfsFeeds[m_currentFeedIdx] << job->errorMessage();
        } else if (job->error() != GBFSJob::NoError) {
            qWarning() << m_gbfsFeeds[m_currentFeedIdx] << job->error() << job->errorMessage() << "- skipping";
        } else if (job->service().boundingBox.isEmpty()) {
            qWarning() << m_gbfsFeeds[m_currentFeedIdx] << "has an empty bounding box - skipping";
        } else {
            m_services.push_back(job->service());
        }
        QTimer::singleShot(m_throttleTime, this, &GBFSProbe::discoverNextFeed);
    });

    GBFSService service;
    service.discoveryUrl = QUrl(m_gbfsFeeds[m_currentFeedIdx]);
    job->discoverAndUpdate(service);
}

void GBFSProbe::writeFeeds()
{
    std::sort(m_services.begin(), m_services.end(), [](const auto &lhs, const auto &rhs) { return lhs.systemId < rhs.systemId; });
    QJsonArray array;
    for (const auto &service : m_services) {
        array.push_back(GBFSService::toJson(service));
    };

    auto b = QJsonDocument(array).toJson(QJsonDocument::Compact);
    b.replace("},{", "},\n {");
    b.replace("[{", "[\n {");
    b.replace("}]", "}\n]\n");

    QFile f(m_outputFileName);
    if (!f.open(QFile::WriteOnly)) {
        qCritical() << f.errorString();
        QCoreApplication::exit(1);
        return;
    }
    f.write(b);
    f.close();

    qDebug() << m_services.size() << "valid feeds discovered";
    QCoreApplication::quit();
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    if (app.arguments().size() <= 1) {
        std::cerr << "Usage: " << argv[0] << " [path to GBFS services file]" << std::endl;
        return 1;
    }

    GBFSProbe probe;
    probe.m_outputFileName = app.arguments().at(1);
    QMetaObject::invokeMethod(&probe, &GBFSProbe::start, Qt::QueuedConnection);

    return app.exec();
}

#include "gbfsprobe.moc"

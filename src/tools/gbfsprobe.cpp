
/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <gbfs/gbfsjob.h>
#include <gbfs/gbfsservice.h>

#include <QCommandLineParser>
#include <QCommandLineOption>
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

#ifdef Q_OS_UNIX
#include <signal.h>
#endif

using namespace Qt::Literals;
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
    void checkDuplicateSystemIds();
    void writeFeeds();

    QNetworkAccessManager m_nam;
    QStringList m_gbfsFeeds;
    int m_currentFeedIdx = -1;
    int m_throttleTime = 0;
    QStringList m_throttledFeeds;
    bool m_syntheticSystemId = false;
    bool m_incremental = false;

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
    if (m_incremental) {
        QFile file(m_outputFileName);
        if (!file.open(QFile::ReadOnly)) {
            qFatal() << file.errorString() << file.fileName();
        }
        m_services = GBFSService::fromJson(QJsonDocument::fromJson(file.readAll()).array());
    }

    if (m_gbfsFeeds.empty()) {
        getFeedList();
    } else {
        discoverNextFeed();
    }
}

[[nodiscard]] static std::vector<QByteArrayView> splitCsvLine(QByteArrayView line)
{
    std::vector<QByteArrayView> fields;
    while (!line.empty()) {
        if (line[0] == '\n' || line[0] == '\r') {
            fields.emplace_back();
            break;
        }
        if (line[0] == ',') {
            fields.emplace_back();
            line = line.mid(1);
            continue;
        }
        if (line[0] == '"') {
            line = line.mid(1);
            const auto idx = line.indexOf('"');
            fields.push_back(line.left(idx));
            line = line.mid(idx + 2);
            continue;
        }
        if (const auto idx = line.indexOf(','); idx > 0) {
            fields.push_back(line.left(idx));
            line = line.mid(idx + 1);
        } else {
            while (line.endsWith('\n') || line.endsWith('\r')) {
                line = line.chopped(1);
            }
            fields.push_back(line);
            break;
        }
    }
    return fields;
}

void GBFSProbe::getFeedList()
{
    auto reply = m_nam.get(QNetworkRequest(QUrl(u"https://raw.githubusercontent.com/MobilityData/gbfs/refs/heads/master/systems.csv"_s)));
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        reply->deleteLater();
        if (reply->error() != QNetworkReply::NoError) {
            qCritical() << reply->errorString();
            QCoreApplication::exit(1);
            return;
        }

        reply->readLine(); // skip header line
        while (!reply->atEnd()) {
            const auto line = reply->readLine();
            const auto fields = splitCsvLine(line);
            if (fields.size() < 10) {
                qDebug() << "missing columns?" << fields;
                continue;
            }
            if (!fields[8].isEmpty() && fields[8] != "0") {
                qDebug() << "skipping feed needing authentication:" << fields;
            }

            auto url = fields[5].trimmed().toByteArray();
            url.replace("http:", "https:");
            m_gbfsFeeds.push_back(QString::fromUtf8(url));
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
                qDebug() << "Extra feed already in GBFS systems.csv:" << extraFeed;
                continue;
            }
            m_gbfsFeeds.insert(it, extraFeed);
        }

        qDebug() << "Found" << m_gbfsFeeds.size() << "possible feeds.";
        if (m_incremental) {
            for (const auto &service : m_services) {
                auto it = std::ranges::lower_bound(m_gbfsFeeds, service.discoveryUrl.toString());
                if (it != m_gbfsFeeds.end() && (*it) == service.discoveryUrl.toString()) {
                    m_gbfsFeeds.erase(it);
                }
            }
        }

        qDebug() << "Running discovery on" << m_gbfsFeeds.size() << "feeds...";
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
            checkDuplicateSystemIds();
            return;
        }
    }

    auto job = new GBFSJob(&m_nam);
    job->setRequestedData({GBFS::StationInformation, GBFS::VehicleStatus, GBFS::GeofencingZones}); // everything we can use for the bounding box
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
    if (m_syntheticSystemId) {
        service.generateSystemId();
    }
    // TODO make this configurable
    if (service.discoveryUrl.host().startsWith("api.entur"_L1)) {
        service.httpHeaders.insert("ET-Client-Name", "kde-kpublictransport");
    }
    job->discoverAndUpdate(service);
}

static bool sortBySystemId(const GBFSService &lhs, const GBFSService &rhs)
{
    return lhs.systemId < rhs.systemId;
}

void GBFSProbe::checkDuplicateSystemIds()
{
    m_gbfsFeeds.clear();

    std::sort(m_services.begin(), m_services.end(), sortBySystemId);
    for (auto it = m_services.begin(); it != m_services.end();) {
        const auto range = std::equal_range(it, m_services.end(), (*it), sortBySystemId);
        assert(range.first == it);
        if (std::next(it) == range.second) {
            it = range.second;
        } else {
            if (std::all_of(range.first, range.second, [&it](const auto &s) { return s.discoveryUrl == (*it).discoveryUrl; })) {
                // duplicated services rather that system id clashes
                qDebug() << "Dropping duplicated service" << (*it).systemId << (*it).discoveryUrl;
                it = m_services.erase(std::next(range.first), range.second);
                continue;
            }
            for (auto it2 = range.first; it2 != range.second; ++it2) {
                m_gbfsFeeds.push_back((*it2).discoveryUrl.toString());
            }
            it = m_services.erase(range.first, range.second);
        }
    }

    qWarning() << "Feeds with colliding system ids:" << m_gbfsFeeds.size() << m_gbfsFeeds;
    if (!m_gbfsFeeds.isEmpty() && !m_syntheticSystemId) {
        m_syntheticSystemId = true;
        m_currentFeedIdx = -1;
        m_throttleTime = 0;
        std::shuffle(m_gbfsFeeds.begin(), m_gbfsFeeds.end(), std::default_random_engine());
        discoverNextFeed();
    } else {
        writeFeeds();
    }
}

void GBFSProbe::writeFeeds()
{
    const auto array = GBFSService::toJson(m_services);
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

static GBFSProbe* s_probe = nullptr;

static void signalHandler([[maybe_unused]] int sig)
{
    if (s_probe) {
        s_probe->m_gbfsFeeds.clear();
        s_probe->m_syntheticSystemId = true;
        s_probe->checkDuplicateSystemIds();
    }
}

int main(int argc, char **argv)
{
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addPositionalArgument(u"file"_s, u"GBFS service file"_s);
    QCommandLineOption incrementalOpt(u"incremental"_s, u"Only check feeds not in the service file yet."_s);
    parser.addOption(incrementalOpt);
    QCommandLineOption addOpt(u"add"_s, u"Add the given URL only (implies incremental)"_s, u"url"_s);
    parser.addOption(addOpt);

    QCoreApplication app(argc, argv);
    parser.process(app);
    if (parser.positionalArguments().size() != 1) {
        parser.showHelp(-1);
    }

    GBFSProbe probe;
    probe.m_outputFileName = parser.positionalArguments().front();
    probe.m_incremental = parser.isSet(incrementalOpt);
    if (parser.isSet(addOpt)) {
        probe.m_gbfsFeeds.push_back(parser.value(addOpt));
        probe.m_incremental = true;
    }
    s_probe = &probe;
    QMetaObject::invokeMethod(&probe, &GBFSProbe::start, Qt::QueuedConnection);

#ifdef Q_OS_UNIX
    struct sigaction sa;
    sa.sa_handler = signalHandler;
    sigaction(SIGINT, &sa, nullptr);
#endif

    return QCoreApplication::exec();
}

#include "gbfsprobe.moc"

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsjob.h"

#include <KPublicTransport/Location>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkReply>

#include <cassert>
#include <cmath>

using namespace KPublicTransport;

GBFSJob::GBFSJob(QNetworkAccessManager *nam, QObject *parent)
    : QObject(parent)
    , m_nam(nam)
{
    assert(nam);
}

GBFSJob::~GBFSJob() = default;

GBFSJob::Error GBFSJob::error() const
{
    return m_error;
}

QString GBFSJob::errorMessage() const
{
    return m_errorMsg;
}

GBFSService GBFSJob::service() const
{
    return m_service;
}

void GBFSJob::discoverAndUpdate(const GBFSService &service)
{
    m_service = service;
    if (!m_service.systemId.isEmpty()) {
        m_store = GBFSStore(m_service.systemId);

        if (m_store.hasCurrentData(GBFS::Discovery)) {
            qDebug() << "reusing cached discovery data" << m_service.systemId;
            m_discoverDoc = m_store.loadData(GBFS::Discovery);
            parseDiscoverData(true);
            return;
        }
    }

    qDebug() << "fetching discovery data" << m_service.discoveryUrl;
    auto reply = m_nam->get(QNetworkRequest(m_service.discoveryUrl));
    connect(reply, &QNetworkReply::finished, this, [this, reply]() { discoverFinished(reply); });
}

void GBFSJob::discoverFinished(QNetworkReply *reply)
{
    reply->deleteLater();
    if (reply->error() != QNetworkReply::NoError) {
        m_error = NetworkError;
        m_errorMsg = reply->errorString();
        emit finished();
        return;
    }

    m_discoverDoc = QJsonDocument::fromJson(reply->readAll());
    parseDiscoverData(true);
}

void GBFSJob::parseDiscoverData(bool sysInfoOnly)
{
    const auto top = m_discoverDoc.object();
    //qDebug() << QJsonDocument(top).toJson();

    const auto data = top.value(QLatin1String("data")).toObject();
    // pick the feeds with the best language for our current locale
    QJsonArray feeds;
    if (data.size() == 1) {
        // only one set of feeds
        qDebug() << "only one set of feeds found";
        feeds = data.begin().value().toObject().value(QLatin1String("feeds")).toArray();
    } else if (!data.empty()) {
        const auto localeLangs = QLocale().uiLanguages();
        for (const auto &l : localeLangs) {
            feeds = data.value(l).toObject().value(QLatin1String("feeds")).toArray();
            if (feeds.isEmpty()) {
                feeds = data.value(l.toLower()).toObject().value(QLatin1String("feeds")).toArray();
            }
            if (feeds.empty() && l.size() > 2 && l[2] == QLatin1Char('-')) {
                feeds = data.value(l.left(2)).toObject().value(QLatin1String("feeds")).toArray();
            }
            if (!feeds.empty()) {
                break;
            }
        }
        // take the first one if we haven't found a better match
        if (feeds.empty()) {
            qDebug() << "picking first language, as none matches" << localeLangs;
            feeds = data.begin().value().toObject().value(QLatin1String("feeds")).toArray();
        }
    }
    if (feeds.empty()) {
        m_error = DataError;
        m_errorMsg = QStringLiteral("no feed found in discovery response!");
        emit finished();
        return;
    }

    for (const auto &feedVal : feeds) {
        const auto feed = feedVal.toObject();
        const auto name = feed.value(QLatin1String("name")).toString();
        const auto type = GBFS::typeForKeyName(name);
        const auto url = QUrl(feed.value(QLatin1String("url")).toString());

        if (sysInfoOnly) {
            if (type != GBFS::SystemInformation) {
                continue;
            }
            if (!m_store.isValid() || !m_store.hasCurrentData(GBFS::SystemInformation)) {
                auto reply = m_nam->get(QNetworkRequest(url));
                connect(reply, &QNetworkReply::finished, this, [this, reply]() { systemInformationFinished(reply); });
            } else {
                qDebug() << "reusing cached system information";
                parseDiscoverData(false);
            }
        } else {
            switch (type) {
                case GBFS::StationInformation:
                case GBFS::StationStatus:
                case GBFS::FreeBikeStatus:
                    if (!m_store.hasCurrentData(type)) {
                        qDebug() << "fetching" << name;
                        auto reply = m_nam->get(QNetworkRequest(url));
                        connect(reply, &QNetworkReply::finished, this, [this, reply, type]() { fetchFinished(reply, type); });
                        ++m_pendingJobs;
                    } else {
                        qDebug() << "reusing cached" << name;
                        parseData(m_store.loadData(type), type);
                    }
                    break;
                case GBFS::Discovery:
                case GBFS::SystemInformation:
                    break;
                default:
                    qDebug() << "Unhandled feed:" << name << url;
            }
        }
    }

    if (!sysInfoOnly && m_pendingJobs == 0) {
        finalize();
    }
}

void GBFSJob::systemInformationFinished(QNetworkReply *reply)
{
    reply->deleteLater();
    if (reply->error() != QNetworkReply::NoError) {
        m_error = NetworkError;
        m_errorMsg = reply->errorString();
        emit finished();
        return;
    }

    const auto sysInfoDoc = QJsonDocument::fromJson(reply->readAll());
    qDebug().noquote() << sysInfoDoc.toJson();
    const auto data = sysInfoDoc.object().value(QLatin1String("data")).toObject();
    const auto systemId = data.value(QLatin1String("system_id")).toString();
    if (systemId.isEmpty()) {
        m_error = DataError;
        m_errorMsg = QStringLiteral("unable to determine system_id!");
        emit finished();
        return;
    }
    m_service.systemId = systemId;
    m_store = GBFSStore(systemId);
    m_store.storeData(GBFS::Discovery, m_discoverDoc);
    m_store.storeData(GBFS::SystemInformation, sysInfoDoc);

    parseDiscoverData(false);
}

void GBFSJob::fetchFinished(QNetworkReply *reply, GBFS::FileType type)
{
    reply->deleteLater();
    --m_pendingJobs;

    if (reply->error() != QNetworkReply::NoError) {
        m_error = NetworkError;
        m_errorMsg = reply->errorString();
        if (m_pendingJobs == 0) { // wait for the rest to finish otherwise, to avoid double finished() emission
            emit finished();
        }
        return;
    }

    const auto doc = QJsonDocument::fromJson(reply->readAll());
    //qDebug().noquote() << doc.toJson();
    m_store.storeData(type, doc);
    parseData(doc, type);

    if (m_pendingJobs == 0) {
        finalize();
    }
}

void GBFSJob::parseData(const QJsonDocument &doc, GBFS::FileType type)
{
    switch (type) {
        case GBFS::StationInformation:
            parseStationInformation(doc);
            break;
        case GBFS::FreeBikeStatus:
            parseFreeBikeStatus(doc);
            break;
        default:
            break;
    }
}

void GBFSJob::parseStationInformation(const QJsonDocument &doc)
{
    const auto stations = doc.object().value(QLatin1String("data")).toObject().value(QLatin1String("stations")).toArray();
    computeBoundingBox(stations);
    qDebug() << stations.size() << "stations/docks";
    qDebug() << "station bounding box:" << m_minLat << m_minLon << m_maxLat << m_maxLon;
}

void GBFSJob::parseFreeBikeStatus(const QJsonDocument &doc)
{
    const auto bikes = doc.object().value(QLatin1String("data")).toObject().value(QLatin1String("bikes")).toArray();
    computeBoundingBox(bikes);
    qDebug() << bikes.size() << "free floating vehicles";
    qDebug() << "station bounding box:" << m_minLat << m_minLon << m_maxLat << m_maxLon;
}

static void filterOutliers(const std::vector<double> &values, double &minVal, double &maxVal, const std::function<double(double, double)> &distFunc)
{
    // first step: primitive distance-based trimming at the extremes
    auto beginIt = values.begin();
    while(std::next(beginIt) != values.end()) {
        if (distFunc(*beginIt, *std::next(beginIt)) > 50'000) {
            ++beginIt;
        } else {
            break;
        }
    }
    auto endIt = std::prev(values.end());
    while(endIt != beginIt && std::prev(endIt) != beginIt) {
        if (distFunc(*endIt, *std::prev(endIt)) > 50'000) {
            --endIt;
        } else {
            break;
        }
    }
    ++endIt;

    // second step: standard deviation
    const auto n = std::distance(beginIt, endIt);
    const auto mean = std::accumulate(beginIt, endIt, 0.0, [n](auto a, auto b) { return a + b / n; });
    auto sigma = std::accumulate(beginIt, endIt, 0.0, [n](auto a, auto b) {
        return a + (std::pow(b, 2.0) / n);
    });
    sigma = std::sqrt(sigma - std::pow(mean, 2.0)) * 3.0;
    minVal = std::min(minVal, std::max(mean - sigma, values.front())); // clamp by 3 sigma, but don't exceed the input range when not needed
    maxVal = std::max(maxVal, std::min(mean + sigma, values.back()));
}

void GBFSJob::computeBoundingBox(const QJsonArray &array)
{
    std::vector<double> lats, lons;
    lats.reserve(array.size());
    lons.reserve(array.size());

    for (const auto &statVal : array) {
        const auto station = statVal.toObject();
        const auto lat = station.value(QLatin1String("lat")).toDouble(NAN);
        if (!std::isnan(lat) && lat >= -90.0 && lat <= 90.0) {
            lats.push_back(lat);
        }
        const auto lon = station.value(QLatin1String("lon")).toDouble(NAN);
        if (!std::isnan(lon) && lon >= -180.0 && lon <= 180.0) {
            lons.push_back(lon);
        }
    }

    std::sort(lats.begin(), lats.end());
    std::sort(lons.begin(), lons.end());
    if (lats.empty() || lons.empty()) {
        return;
    }

    // covered area is reasonable, take as-is
    if (Location::distance(lats.front(), lons.front(), lats.back(), lons.back()) <= 50'000) {
        qDebug() << "coordinates look plausible, skipping outlier filter";
        m_minLat = lats.front();
        m_minLon = lons.front();
        m_maxLat = lats.back();
        m_maxLon = lons.back();
        return;
    }

    // try to filter out outliers
    qDebug() << "performing outlier filtering";
    filterOutliers(lats, m_minLat, m_maxLat, [](auto lat1, auto lat2) { return Location::distance(lat1, 0.0, lat2, 0.0); });
    filterOutliers(lons, m_minLon, m_maxLon, [this](auto lon1, auto lon2) {
        const auto lat = (m_maxLat - m_minLat) / 2.0;
        return Location::distance(lat, lon1, lat, lon2);
    });
}

void GBFSJob::finalize()
{
    if (m_maxLat > m_minLat && m_maxLon > m_minLon) {
        m_service.boundingBox = QRectF(QPointF(m_minLon, m_minLat), QPointF(m_maxLon, m_maxLat));
    }
    GBFSServiceRepository::store(m_service);
    emit finished();
}

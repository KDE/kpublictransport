/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsjob.h"

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

void GBFSJob::discover(const QUrl &url)
{
    m_discoverUrl = url;

    const auto sysId = GBFSStore::systemIdForUrl(url);
    if (!sysId.isEmpty()) {
        m_store = GBFSStore(sysId);

        if (m_store.hasCurrentData(GBFS::Discovery)) {
            qDebug() << "reusing cached discovery data" << sysId;
            m_discoverDoc = m_store.loadData(GBFS::Discovery);
            parseDiscoverData(true);
            return;
        }
    }

    qDebug() << "fetching discovery data" << url;
    auto reply = m_nam->get(QNetworkRequest(url));
    connect(reply, &QNetworkReply::finished, this, [this, reply]() { discoverFinished(reply); });
}

void GBFSJob::discoverFinished(QNetworkReply *reply)
{
    reply->deleteLater();
    // TODO error handling

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
        qWarning() << "no feeds found!?";
        qWarning().noquote() << m_discoverDoc.toJson();
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
}

void GBFSJob::systemInformationFinished(QNetworkReply *reply)
{
    reply->deleteLater();
    // TODO error handling

    const auto sysInfoDoc = QJsonDocument::fromJson(reply->readAll());
    qDebug().noquote() << sysInfoDoc.toJson();
    const auto data = sysInfoDoc.object().value(QLatin1String("data")).toObject();
    const auto systemId = data.value(QLatin1String("system_id")).toString();
    if (systemId.isEmpty()) {
        // TODO error handling!
        qWarning() << "could not determine systemId!";
        return;
    }
    if (!m_discoverUrl.isEmpty()) {
        GBFSStore::setSystemIdForUrl(m_discoverUrl, systemId);
    }
    m_store = GBFSStore(systemId);
    m_store.storeData(GBFS::Discovery, m_discoverDoc);
    m_store.storeData(GBFS::SystemInformation, sysInfoDoc);

    parseDiscoverData(false);
}

void GBFSJob::fetchFinished(QNetworkReply *reply, GBFS::FileType type)
{
    reply->deleteLater();
    // TODO error handling

    const auto doc = QJsonDocument::fromJson(reply->readAll());
    qDebug().noquote() << doc.toJson();
    m_store.storeData(type, doc);
    parseData(doc, type);
}

void GBFSJob::parseData(const QJsonDocument &doc, GBFS::FileType type)
{
    switch (type) {
        case GBFS::StationInformation:
            parseStationInformation(doc);
            break;
        default:
            break;
    }
}

void GBFSJob::parseStationInformation(const QJsonDocument &doc)
{
    const auto stations = doc.object().value(QLatin1String("data")).toObject().value(QLatin1String("stations")).toArray();
    for (const auto &statVal : stations) {
        const auto station = statVal.toObject();
        const auto lat = station.value(QLatin1String("lat")).toDouble(NAN);
        if (!std::isnan(lat)) {
            m_minLat = std::min(m_minLat, lat);
            m_maxLat = std::max(m_minLat, lat);
        }
        const auto lon = station.value(QLatin1String("lon")).toDouble(NAN);
        if (!std::isnan(lon)) {
            m_minLon = std::min(m_minLon, lon);
            m_maxLon = std::max(m_maxLon, lon);
        }
    }

    qDebug() << "station bounding box:" << m_minLat << m_minLon << m_maxLat << m_maxLon;
}

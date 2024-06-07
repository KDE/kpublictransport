/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "wikidataquery.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

using namespace Qt::Literals::StringLiterals;

namespace wd = Wikidata;

inline constexpr const auto WikidataGetEntitiesMaxCount = 50;
inline constexpr const auto WikidataQueryMaxCount = 50;

WikidataQuery::WikidataQuery(QObject *parent) :
    QObject(parent)
{
}

WikidataQuery::~WikidataQuery() = default;

WikidataQuery::Error WikidataQuery::error() const
{
    return m_error;
}

QUrlQuery WikidataQuery::commonUrlQuery()
{
    QUrlQuery query;
    query.addQueryItem(u"format"_s, u"json"_s);
    return query;
}


WikidataEntitiesQuery::WikidataEntitiesQuery(QObject* parent)
    : WikidataQuery(parent)
{
}

WikidataEntitiesQuery::~WikidataEntitiesQuery() = default;

void WikidataEntitiesQuery::setItems(std::vector<wd::Q> &&items)
{
    m_items = std::move(items);
}

QNetworkRequest WikidataEntitiesQuery::nextRequest()
{
    QUrl url(u"https://www.wikidata.org/w/api.php"_s);
    auto query = commonUrlQuery();
    query.addQueryItem(u"action"_s, u"wbgetentities"_s);
    query.addQueryItem(u"props"_s, u"claims"_s);

    QString ids;
    for (auto i = m_nextBatch; i < std::min(m_items.size(), m_nextBatch + WikidataGetEntitiesMaxCount); ++i) {
        if (i != m_nextBatch) {
            ids += '|'_L1;
        }
        ids += m_items[i].toString();
    }
    m_nextBatch += WikidataGetEntitiesMaxCount;
    query.addQueryItem(u"ids"_s, ids);
    url.setQuery(query);

    QNetworkRequest req(url);
    req.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
    return req;
}

std::vector<Wikidata::Item>&& WikidataEntitiesQuery::takeResult()
{
    return std::move(m_result);
}

bool WikidataEntitiesQuery::processReply(QNetworkReply *reply)
{
    const auto doc = QJsonDocument::fromJson(reply->readAll());
    const auto entities = doc.object().value("entities"_L1).toObject();
    m_result.reserve(entities.size());
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        m_result.emplace_back(wd::Q(it.key()), it.value().toObject());
    }
    Q_EMIT partialResult(this);

    if (m_nextBatch < m_items.size()) {
        return false;
    }

    Q_EMIT finished();
    return true;
}


WikidataImageMetadataQuery::WikidataImageMetadataQuery(QObject* parent)
    : WikidataQuery(parent)
{
}

WikidataImageMetadataQuery::~WikidataImageMetadataQuery() = default;

void WikidataImageMetadataQuery::setImages(std::vector<QString> &&images)
{
    m_images = std::move(images);
}

QNetworkRequest WikidataImageMetadataQuery::nextRequest()
{
    QUrl url(u"https://commons.wikimedia.org/w/api.php"_s);
    auto query = commonUrlQuery();
    query.addQueryItem(u"action"_s, u"query"_s);
    query.addQueryItem(u"prop"_s, u"imageinfo"_s);
    query.addQueryItem(u"iiprop"_s, u"extmetadata|mime|size"_s);
    QString ids;
    for (auto i = m_nextBatch; i < std::min(m_images.size(), m_nextBatch + WikidataQueryMaxCount); ++i) {
        if (i != m_nextBatch) {
            ids += '|'_L1;
        }
        ids += "File:"_L1 + m_images[i];
    }
    m_nextBatch += WikidataQueryMaxCount;
    query.addQueryItem(u"titles"_s, ids);
    url.setQuery(query);

    QNetworkRequest req(url);
    req.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
    return req;
}

std::vector<Wikidata::Image>&& WikidataImageMetadataQuery::takeResult()
{
    return std::move(m_result);
}

bool WikidataImageMetadataQuery::processReply(QNetworkReply *reply)
{
    const auto doc = QJsonDocument::fromJson(reply->readAll());
    const auto images = doc.object().value("query"_L1).toObject().value("pages"_L1).toObject();
    m_result.reserve(images.size());
    for (const auto &img : images) {
        m_result.emplace_back(img.toObject());
    }
    Q_EMIT partialResult(this);

    if (m_nextBatch < m_images.size()) {
        return false;
    }

    Q_EMIT finished();
    return true;
}

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
using namespace Wikidata;

inline constexpr const auto WikidataGetEntitiesMaxCount = 50;
inline constexpr const auto WikidataQueryMaxCount = 50;

Query::Query(QObject *parent) :
    QObject(parent)
{
}

Query::~Query() = default;

Query::Error Query::error() const
{
    return m_error;
}

QUrlQuery Query::commonUrlQuery()
{
    QUrlQuery query;
    query.addQueryItem(u"format"_s, u"json"_s);
    return query;
}


EntitiesQuery::EntitiesQuery(QObject* parent)
    : Query(parent)
{
}

EntitiesQuery::~EntitiesQuery() = default;

void EntitiesQuery::setItems(std::vector<Wikidata::Q> &&items)
{
    m_items = std::move(items);
}

QNetworkRequest EntitiesQuery::nextRequest()
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

std::vector<Wikidata::Item> EntitiesQuery::takeResult()
{
    std::vector<Wikidata::Item> r = std::move(m_result);
    return r;
}

bool EntitiesQuery::processReply(QNetworkReply *reply)
{
    const auto doc = QJsonDocument::fromJson(reply->readAll());
    const auto entities = doc.object().value("entities"_L1).toObject();
    m_result.reserve(entities.size());
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        m_result.emplace_back(Q(it.key()), it.value().toObject());
    }
    Q_EMIT partialResult(this);

    if (m_nextBatch < m_items.size()) {
        return false;
    }

    Q_EMIT finished();
    return true;
}


ImageMetadataQuery::ImageMetadataQuery(QObject* parent)
    : Query(parent)
{
}

ImageMetadataQuery::~ImageMetadataQuery() = default;

void ImageMetadataQuery::setImages(std::vector<QString> &&images)
{
    m_images = std::move(images);
}

QNetworkRequest ImageMetadataQuery::nextRequest()
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

std::vector<Wikidata::Image> ImageMetadataQuery::takeResult()
{
    std::vector<Wikidata::Image> r = std::move(m_result);
    return r;
}

bool ImageMetadataQuery::processReply(QNetworkReply *reply)
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

#include "moc_wikidataquery.cpp"

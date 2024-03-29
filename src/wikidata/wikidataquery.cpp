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

namespace wd = Wikidata;

enum {
    WikidataGetEntitiesMaxCount = 50,
    WikidataQueryMaxCount = 50
};

WikidataQuery::WikidataQuery(QObject *parent) :
    QObject(parent)
{
}

WikidataQuery::~WikidataQuery() = default;

WikidataQuery::Error WikidataQuery::error()
{
    return m_error;
}

QUrlQuery WikidataQuery::commonUrlQuery() const
{
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("format"), QStringLiteral("json"));
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
    QUrl url(QStringLiteral("https://www.wikidata.org/w/api.php"));
    auto query = commonUrlQuery();
    query.addQueryItem(QStringLiteral("action"), QStringLiteral("wbgetentities"));
    query.addQueryItem(QStringLiteral("props"), QStringLiteral("claims"));

    QString ids;
    for (auto i = m_nextBatch; i < std::min(m_items.size(), m_nextBatch + WikidataGetEntitiesMaxCount); ++i) {
        if (i != m_nextBatch) {
            ids += QLatin1Char('|');
        }
        ids += m_items[i].toString();
    }
    m_nextBatch += WikidataGetEntitiesMaxCount;
    query.addQueryItem(QStringLiteral("ids"), ids);
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
    const auto entities = doc.object().value(QLatin1String("entities")).toObject();
    m_result.reserve(entities.size());
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        m_result.push_back(wd::Item(wd::Q(it.key()), it.value().toObject()));
    }
    Q_EMIT partialResult(this);

    if (m_nextBatch < m_items.size()) {
        return false;
    } else {
        Q_EMIT finished();
        return true;
    }
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
    QUrl url(QStringLiteral("https://commons.wikimedia.org/w/api.php"));
    auto query = commonUrlQuery();
    query.addQueryItem(QStringLiteral("action"), QStringLiteral("query"));
    query.addQueryItem(QStringLiteral("prop"), QStringLiteral("imageinfo"));
    query.addQueryItem(QStringLiteral("iiprop"), QStringLiteral("extmetadata|mime|size"));
    QString ids;
    for (auto i = m_nextBatch; i < std::min(m_images.size(), m_nextBatch + WikidataQueryMaxCount); ++i) {
        if (i != m_nextBatch) {
            ids += QLatin1Char('|');
        }
        ids += QLatin1String("File:") + m_images[i];
    }
    m_nextBatch += WikidataQueryMaxCount;
    query.addQueryItem(QStringLiteral("titles"), ids);
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
    const auto images = doc.object().value(QLatin1String("query")).toObject().value(QLatin1String("pages")).toObject();
    m_result.reserve(images.size());
    for (const auto &img : images) {
        m_result.push_back(wd::Image(img.toObject()));
    }
    Q_EMIT partialResult(this);

    if (m_nextBatch < m_images.size()) {
        return false;
    } else {
        Q_EMIT finished();
        return true;
    }
}

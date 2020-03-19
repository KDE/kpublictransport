/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "wikidataquery.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>

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

void WikidataEntitiesQuery::setItems(std::vector<QString> &&items)
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
        ids += m_items[i];
    }
    m_nextBatch += WikidataGetEntitiesMaxCount;
    query.addQueryItem(QStringLiteral("ids"), ids);
    url.setQuery(query);

    QNetworkRequest req(url);
    req.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
    return req;
}

bool WikidataEntitiesQuery::processReply(QNetworkReply *reply)
{
    const auto doc = QJsonDocument::fromJson(reply->readAll());
    emit partialResult(doc.object().value(QLatin1String("entities")).toObject());

    if (m_nextBatch < m_items.size()) {
        return false;
    } else {
        emit finished();
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
    QUrl url(QStringLiteral("https://www.wikidata.org/w/api.php"));
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

bool WikidataImageMetadataQuery::processReply(QNetworkReply *reply)
{
    const auto doc = QJsonDocument::fromJson(reply->readAll());
    emit partialResult(doc.object().value(QLatin1String("query")).toObject().value(QLatin1String("pages")).toObject());

    if (m_nextBatch < m_images.size()) {
        return false;
    } else {
        emit finished();
        return true;
    }
}

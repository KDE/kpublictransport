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
    WikidataGetEntitiesMaxCount = 50
};

WikidataQuery::WikidataQuery(QObject *parent) :
    QObject(parent)
{
}

WikidataQuery::~WikidataQuery() = default;

void WikidataQuery::setItems(std::vector<QString> &&items)
{
    m_items = std::move(items);
}

WikidataQuery::Error WikidataQuery::error()
{
    return m_error;
}

QNetworkRequest WikidataQuery::nextRequest()
{
    QUrl url(QStringLiteral("https://www.wikidata.org/w/api.php"));
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("action"), QStringLiteral("wbgetentities"));
    query.addQueryItem(QStringLiteral("format"), QStringLiteral("json"));
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

bool WikidataQuery::processReply(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << reply->errorString();
        m_error = NetworkError;
        emit finished();
        return true;
    }

    const auto doc = QJsonDocument::fromJson(reply->readAll());
    emit partialResult(doc.object().value(QLatin1String("entities")).toObject());

    if (m_nextBatch < m_items.size()) {
        return false;
    } else {
        emit finished();
        return true;
    }
}

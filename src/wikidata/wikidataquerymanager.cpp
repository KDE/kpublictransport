/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "wikidataquerymanager.h"
#include "wikidataquery.h"

#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QNetworkReply>
#include <QStandardPaths>

WikidataQueryManager::WikidataQueryManager(QObject *parent)
    : QObject(parent)
{
    m_nam = new QNetworkAccessManager(this);
    m_nam->setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);
    m_nam->setStrictTransportSecurityEnabled(true);
    m_nam->enableStrictTransportSecurityStore(true, QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.osm/hsts/"));

    auto diskCache = new QNetworkDiskCache;
    diskCache->setCacheDirectory(QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.wikidata/http-cache/"));
    diskCache->setMaximumCacheSize(1'000'000'000); // 1GB
    m_nam->setCache(diskCache);
}

WikidataQueryManager::~WikidataQueryManager() = default;

void WikidataQueryManager::execute(WikidataQuery *query)
{
    executeNextSubQuery(query);
}

void WikidataQueryManager::executeNextSubQuery(WikidataQuery *query)
{
    auto req = query->nextRequest();
    // see https://www.mediawiki.org/wiki/API:Etiquette
    req.setHeader(QNetworkRequest::UserAgentHeader, QStringLiteral("KPublicTransport/KnowledgeDBGenerator (kde-pim@kde.org)"));
    const auto reply = m_nam->get(req);
    connect(reply, &QNetworkReply::finished, this, [query, reply, this]() { subQueryFinished(query, reply); });
}

void WikidataQueryManager::subQueryFinished(WikidataQuery *query, QNetworkReply *reply)
{
    reply->deleteLater();

    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << reply->errorString();
        query->m_error = WikidataQuery::NetworkError;
        emit query->finished();
        return;
    }

    if (query->processReply(reply)) {
        return;
    }
    executeNextSubQuery(query);
}

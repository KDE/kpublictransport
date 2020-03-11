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
    const auto reply = m_nam->get(query->nextRequest());
    connect(reply, &QNetworkReply::finished, this, [query, reply, this]() { subQueryFinished(query, reply); });
}

void WikidataQueryManager::subQueryFinished(WikidataQuery *query, QNetworkReply *reply)
{
    reply->deleteLater();
    if (query->processReply(reply)) {
        return;
    }
    reply = m_nam->get(query->nextRequest());
    connect(reply, &QNetworkReply::finished, this, [query, reply, this]() { subQueryFinished(query, reply); });
}

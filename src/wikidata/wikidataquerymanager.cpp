/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "wikidataquerymanager.h"
#include "wikidataquery.h"
#include "logging.h"

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QNetworkReply>
#include <QStandardPaths>

using namespace Qt::Literals::StringLiterals;
using namespace Wikidata;

WikidataQueryManager::WikidataQueryManager(QObject *parent)
    : QObject(parent)
{
}

WikidataQueryManager::~WikidataQueryManager() = default;

void WikidataQueryManager::setUserAgentEmailAddress(const QString &email)
{
    m_email = email;
}

void WikidataQueryManager::execute(WikidataQuery *query)
{
    executeNextSubQuery(query);
}

void WikidataQueryManager::executeNextSubQuery(WikidataQuery *query)
{
    if (m_email.isEmpty()) {
        qFatal("User-Agent email address not set!");
    }

    auto req = query->nextRequest();
    // see https://www.mediawiki.org/wiki/API:Etiquette
    req.setHeader(QNetworkRequest::UserAgentHeader, QString(QCoreApplication::applicationName() + '/'_L1 + QCoreApplication::applicationVersion() + " ("_L1 + m_email + ')'_L1));
    const auto reply = nam()->get(req);
    connect(reply, &QNetworkReply::finished, this, [query, reply, this]() { subQueryFinished(query, reply); });
}

void WikidataQueryManager::subQueryFinished(WikidataQuery *query, QNetworkReply *reply)
{
    reply->deleteLater();

    if (reply->error() != QNetworkReply::NoError) {
        qCWarning(Log) << reply->errorString();
        query->m_error = WikidataQuery::NetworkError;
        Q_EMIT query->finished();
        return;
    }

    if (query->processReply(reply)) {
        return;
    }
    executeNextSubQuery(query);
}

QNetworkAccessManager* WikidataQueryManager::nam()
{
    if (!m_nam) {
        m_nam = new QNetworkAccessManager(this);
        m_nam->setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);
        m_nam->setStrictTransportSecurityEnabled(true);
        m_nam->enableStrictTransportSecurityStore(true, QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + "/org.kde.wikidata/hsts/"_L1);

        auto diskCache = new QNetworkDiskCache;
        diskCache->setCacheDirectory(QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + "org.kde.wikidata/http-cache/"_L1);
#ifndef Q_OS_ANDROID
        diskCache->setMaximumCacheSize(1'000'000'000); // 1GB, when it's actually a user-wide shared cache
#endif
        m_nam->setCache(diskCache);
    }

    return m_nam;
}

#include "moc_wikidataquerymanager.cpp"

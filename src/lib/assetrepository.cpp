/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "assetrepository_p.h"
#include "logging.h"

#include <KPublicTransport/Attribution>

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QJsonArray>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QStandardPaths>
#include <QUrl>

using namespace KPublicTransport;

AssetRepository* AssetRepository::s_instance = nullptr;

AssetRepository::AssetRepository(QObject *parent)
    : QObject(parent)
{
    if (!s_instance) {
        s_instance = this;
    }
}

AssetRepository::~AssetRepository()
{
    if (s_instance == this) {
        s_instance = nullptr;
    }
}

AssetRepository* AssetRepository::instance()
{
    return s_instance;
}

void AssetRepository::setNetworkAccessManagerProvider(std::function<QNetworkAccessManager*()> namProvider)
{
    m_namProvider = namProvider;
}

static QString cachePath()
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.kpublictransport/assets/");
}

QUrl AssetRepository::localFile(const QUrl& url)
{
    if (!url.isValid() || url.fileName().isEmpty()) {
        return {};
    }

    QFileInfo fi(cachePath() + url.fileName());
    if (fi.exists() && fi.size() > 0) {
        return QUrl::fromLocalFile(fi.absoluteFilePath());
    }
    return {};
}

bool AssetRepository::download(const QUrl &url)
{
    if (!url.isValid() || url.scheme() != QLatin1String("https") || url.fileName().isEmpty() || !m_namProvider || !m_namProvider()) {
        return false;
    }

    if (QFileInfo::exists(cachePath() + url.fileName())) { // already downloaded, or persistent error
        return false;
    }

    if (std::find(m_queue.begin(), m_queue.end(), url) != m_queue.end()) {
        return false;
    }

    m_queue.push_back(url);
    if (m_queue.size() == 1) {
        downloadNext();
    }
    return true;
}

bool AssetRepository::isQueueEmpty()
{
    return m_queue.empty();
}

void AssetRepository::downloadNext()
{
    if (m_queue.empty()) {
        Q_EMIT downloadFinished();
        return;
    }

    QNetworkRequest req(m_queue.front());
    auto reply = m_namProvider()->get(req);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        reply->deleteLater();

        switch (reply->error()) {
            case QNetworkReply::NoError:
            {
                QDir().mkpath(cachePath());
                QFile f(cachePath() + reply->request().url().fileName());
                if (!f.open(QFile::WriteOnly)) {
                    qWarning() << "Failed to open file for storing asset" << f.errorString() << f.fileName();
                } else {
                    f.write(reply->readAll());
                }
                break;
            }
            // persistent errors, empty file prevents forther
            case QNetworkReply::ContentNotFoundError:
            case QNetworkReply::ContentGoneError:
            case QNetworkReply::UnknownContentError:
            case QNetworkReply::TooManyRedirectsError:
            {
                qWarning() << reply->errorString();
                QDir().mkpath(cachePath());
                QFile f(cachePath() + reply->request().url().fileName());
                f.open(QFile::WriteOnly);
                break;
            }
            // transient errors
            default:
                qWarning() << reply->errorString();
                break;
        }

        m_queue.pop_front();
        downloadNext();
    });
}

const std::vector<Attribution>& AssetRepository::attributions() const
{
    if (m_attributions.empty()) {
        QFile f(QStringLiteral(":/org.kde.kpublictransport/assets/asset-attributions.json"));
        if (!f.open(QFile::ReadOnly)) {
            qCWarning(Log) << f.fileName() << f.errorString();
            return m_attributions;
        }

        m_attributions = Attribution::fromJson(QJsonDocument::fromJson(f.readAll()).array());
    }

    return m_attributions;
}

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

#include "assetrepository_p.h"

#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QStandardPaths>
#include <QUrl>

using namespace KPublicTransport;

AssetRepository* AssetRepository::s_instance = nullptr;

AssetRepository::AssetRepository(QObject *parent)
    : QObject(parent)
{
    qDebug() << s_instance << this;
    if (!s_instance) {
        s_instance = this;
    }
}

AssetRepository::~AssetRepository()
{
    qDebug() << s_instance << this;
    if (s_instance == this) {
        s_instance = nullptr;
    }
}

AssetRepository* AssetRepository::instance()
{
    return s_instance;
}

void AssetRepository::setNetworkAccessManager(QNetworkAccessManager *nam)
{
    m_nam = nam;
}

static QString cachePath()
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.kpublictransport/assets/");
}

QString AssetRepository::localFile(const QUrl& url)
{
    if (!url.isValid() || url.fileName().isEmpty()) {
        return {};
    }

    QFileInfo fi(cachePath() + url.fileName());
    if (fi.exists() && fi.size() > 0) {
        return fi.absoluteFilePath();
    }
    return {};
}

bool AssetRepository::download(const QUrl &url)
{
    if (!url.isValid() || url.scheme() != QLatin1String("https") || url.fileName().isEmpty() || !m_nam) {
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

bool AssetRepository::isEmpty()
{
    return m_queue.empty();
}

void AssetRepository::downloadNext()
{
    if (m_queue.empty()) {
        emit downloadFinished();
        return;
    }

    QNetworkRequest req(m_queue.front());
    auto reply = m_nam->get(req);
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

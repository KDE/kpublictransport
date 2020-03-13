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

#ifndef KPUBLICTRANSPORT_ASSETREPOSITORY_P_H
#define KPUBLICTRANSPORT_ASSETREPOSITORY_P_H

#include <QObject>
#include <QUrl>

#include <deque>

class QNetworkAccessManager;

namespace KPublicTransport {

/**
 * Access and downloading of line logos.
 */
class AssetRepository : public QObject
{
    Q_OBJECT
public:
    ~AssetRepository();

    /** Returns the locally cached content for @p url
     *  if available, an empty string if none is available.
     */
    static QString localFile(const QUrl &url);

    /** Schedules the image at @p url for downloading.
     *  @returns @c true if a download job has been started,
     *  @c false if the requested item is already present or
     *  @p url is invalid.
     */
    bool download(const QUrl &url);

    /** Returns @c true if no further download jobs are queued or in progress. */
    bool isEmpty();

    static AssetRepository* instance();

Q_SIGNALS:
    /** Emitted whenever all pending downloads have been completed,
     *  successful or not.
     */
    void downloadFinished();

private:
    friend class Manager;

    AssetRepository(QObject *parent = nullptr);
    void setNetworkAccessManager(QNetworkAccessManager *nam);
    void downloadNext();

    static AssetRepository *s_instance;
    std::deque<QUrl> m_queue;
    QNetworkAccessManager *m_nam = nullptr;
};

}

#endif // KPUBLICTRANSPORT_ASSETREPOSITORY_P_H

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_ASSETREPOSITORY_P_H
#define KPUBLICTRANSPORT_ASSETREPOSITORY_P_H

#include "kpublictransport_export.h"

#include <QObject>
#include <QUrl>

#include <deque>

class QNetworkAccessManager;

namespace KPublicTransport {

class Attribution;

/**
 * Access and downloading of line logos.
 */
class KPUBLICTRANSPORT_EXPORT AssetRepository : public QObject
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
    bool isQueueEmpty();

    /** Returns attributions for the provided assets. */
    const std::vector<Attribution>& attributions() const;

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
    mutable std::vector<Attribution> m_attributions;
};

}

#endif // KPUBLICTRANSPORT_ASSETREPOSITORY_P_H

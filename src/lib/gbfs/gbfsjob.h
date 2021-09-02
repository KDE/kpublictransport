/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSJOB_H
#define KPUBLICTRANSPORT_GBFSJOB_H

#include "kpublictransport_export.h"
#include "gbfsservice.h"
#include "gbfsstore.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkReply;

namespace KPublicTransport {

/** GBFS fetch job.
 *  @internal exported for testing only
 *  @see https://github.com/NABSA/gbfs/blob/master/gbfs.md
 */
class KPUBLICTRANSPORT_EXPORT GBFSJob : public QObject
{
    Q_OBJECT
public:
    explicit GBFSJob(QNetworkAccessManager *nam, QObject *parent = nullptr);
    ~GBFSJob();

    /** Perform GBFS auto-discovery based on the given @p url and update the local state as far as necessary. */
    void discoverAndUpdate(const GBFSService &service);

    /** The service that is updated, or which has been discovered. */
    GBFSService service() const;

    enum Error {
        NoError,
        NetworkError,
        DataError,
    };
    Error error() const;
    QString errorMessage() const;

Q_SIGNALS:
    /** Emitted when the discovery and/or update process has finished.
     *  This can be immediately (if everything is still up to date).
     */
    void finished();

private:
    void discoverFinished(QNetworkReply *reply);
    void parseDiscoverData();
    void processFeeds(bool sysInfoOnly);
    void systemInformationFinished(QNetworkReply *reply);
    void fetchFinished(QNetworkReply *reply, GBFS::FileType type);
    void parseData(const QJsonDocument &doc, GBFS::FileType type);
    void parseStationInformation(const QJsonDocument &doc);
    void parseFreeBikeStatus(const QJsonDocument &doc);
    void computeBoundingBox(const QJsonArray &array);
    void parseVersionData(const QJsonDocument &doc);
    void finalize();

    QNetworkAccessManager *m_nam = nullptr;
    GBFSService m_service;
    GBFSStore m_store;
    QJsonDocument m_discoverDoc;
    QJsonArray m_feeds;

    double m_minLat = 90.0, m_maxLat = -90.0, m_minLon = 180.0, m_maxLon = -180.0;

    QString m_errorMsg;
    Error m_error = NoError;
    int m_pendingJobs = 0;
};

}

#endif // KPUBLICTRANSPORT_GBFSJOB_H

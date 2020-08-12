/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSJOB_H
#define KPUBLICTRANSPORT_GBFSJOB_H

#include "kpublictransport_export.h"
#include "gbfsstore.h"

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

    void discover(const QUrl &url);

private:
    void discoverFinished(QNetworkReply *reply);
    void parseDiscoverData(bool sysInfoOnly);
    void systemInformationFinished(QNetworkReply *reply);
    void fetchFinished(QNetworkReply *reply, GBFS::FileType type);
    void parseData(const QJsonDocument &doc, GBFS::FileType type);
    void parseStationInformation(const QJsonDocument &doc);

    QNetworkAccessManager *m_nam = nullptr;
    GBFSStore m_store;
    QUrl m_discoverUrl;
    QJsonDocument m_discoverDoc;

    double m_minLat = 90.0, m_maxLat = -90.0, m_minLon = 180.0, m_maxLon = -180.0;
};

}

#endif // KPUBLICTRANSPORT_GBFSJOB_H

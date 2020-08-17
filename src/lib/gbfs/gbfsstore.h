/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSSTORE_H
#define KPUBLICTRANSPORT_GBFSSTORE_H

#include "gbfs.h"

#include <QString>

class QJsonDocument;
class QUrl;

namespace KPublicTransport {

/** Local storage of GBFS data.
 *  @see https://github.com/NABSA/gbfs/blob/master/gbfs.md
 */
class GBFSStore
{
public:
    explicit GBFSStore();
    explicit GBFSStore(const QString &systemId);
    ~GBFSStore();

    /** Store is set up with a system id and is thus usable. */
    bool isValid() const;

    /** We have a file for @p type, but it could be outdated. */
    bool hasData(GBFS::FileType type) const;
    /** We have a file for @p type, and it's up-to-date. */
    bool hasCurrentData(GBFS::FileType type) const;
    /** Store data for @p type. */
    void storeData(GBFS::FileType type, const QJsonDocument &doc);
    /** Load data for @p type. */
    QJsonDocument loadData(GBFS::FileType type) const;

    /** Delete expired transient information. */
    static void expire();

private:
    QString fileName(GBFS::FileType type) const;

    QString m_systemId;
};

}

#endif // KPUBLICTRANSPORT_GBFSSTORE_H

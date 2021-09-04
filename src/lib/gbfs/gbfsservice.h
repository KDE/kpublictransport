/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSSERVICE_H
#define KPUBLICTRANSPORT_GBFSSERVICE_H

#include "kpublictransport_export.h"

#include <QRectF>
#include <QString>
#include <QUrl>

#include <vector>

class QJsonObject;

namespace KPublicTransport {

/** A single service offering a GBFS feed.
 *  @internal only exported for testing and the feed discovery tool
 */
class KPUBLICTRANSPORT_EXPORT GBFSService
{
    Q_GADGET
    Q_PROPERTY(QUrl discoveryUrl MEMBER discoveryUrl)
    Q_PROPERTY(QString systemId MEMBER systemId)
    Q_PROPERTY(QRectF boudingBox MEMBER boundingBox)

public:
    QUrl discoveryUrl;
    QString systemId;
    QRectF boundingBox;

    /** Generate a systemId based on the URL.
     *  This is used for cases of colliding systemIds.
     */
    void generateSystemId();

    static KPUBLICTRANSPORT_EXPORT QJsonObject toJson(const GBFSService &service);
    static GBFSService fromJson(const QJsonObject &obj);
};

/** All GBFS services.
 *  @internal only exported for testing
 */
class KPUBLICTRANSPORT_EXPORT GBFSServiceRepository
{
public:
    static const std::vector<GBFSService>& services();
    static void store(const GBFSService &service);

private:
    static void load();
    static std::vector<GBFSService> m_services;
};

}

#endif // KPUBLICTRANSPORT_GBFSSERVICE_H

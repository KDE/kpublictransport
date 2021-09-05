/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSREADER_H
#define KPUBLICTRANSPORT_GBFSREADER_H

class QJsonDocument;
class QJsonObject;
class QJsonValue;
class QLatin1String;

namespace KPublicTransport {

/** Utility methods for reading GBFS data. */
namespace GBFSReader
{
    /** Reads and sanity-checks geographic coordinates. */
    double readLatitude(const QJsonObject &obj);
    double readLongitude(const QJsonObject &obj);

    /** Returns the top-level data object.
     *  Also handles broken feeds missing the data object and having things
     *  on the top level directly.
     */
    QJsonObject dataObject(const QJsonDocument &doc);
    QJsonValue dataValue(const QJsonDocument &doc, QLatin1String name);
}

}

#endif // KPUBLICTRANSPORT_GBFSREADER_H

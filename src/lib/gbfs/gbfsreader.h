/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSREADER_H
#define KPUBLICTRANSPORT_GBFSREADER_H

class QJsonObject;

namespace KPublicTransport {

/** Utility methods for reading GBFS data. */
namespace GBFSReader
{
    /** Reads and sanity-checks geographic coordinates. */
    double readLatitude(const QJsonObject &obj);
    double readLongitude(const QJsonObject &obj);
}

}

#endif // KPUBLICTRANSPORT_GBFSREADER_H

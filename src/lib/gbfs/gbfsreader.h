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
class QString;

namespace KPublicTransport {

class RentalVehicleNetwork;

/** Utility methods for reading GBFS data. */
namespace GBFSReader
{
    /** Reads and sanity-checks geographic coordinates. */
    [[nodiscard]] double readLatitude(const QJsonObject &obj);
    [[nodiscard]] double readLongitude(const QJsonObject &obj);

    /** Returns the top-level data object.
     *  Also handles broken feeds missing the data object and having things
     *  on the top level directly.
     */
    [[nodiscard]] QJsonObject dataObject(const QJsonDocument &doc);
    [[nodiscard]] QJsonValue dataValue(const QJsonDocument &doc, QLatin1String name);

    /** Read a localized string value. */
    [[nodiscard]] QString readLocalizedString(const QJsonObject &obj, QLatin1String key);

    /** Read system information data. */
    [[nodiscard]] RentalVehicleNetwork readSystemInformation(const QJsonObject &sysInfo);
}

}

#endif // KPUBLICTRANSPORT_GBFSREADER_H

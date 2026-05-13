/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_GBFSREADER_H
#define KPUBLICTRANSPORT_GBFSREADER_H

#include <QJsonObject>

#include <initializer_list>

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
    [[nodiscard]] QJsonValue dataValue(const QJsonDocument &doc, QLatin1StringView name);
    [[nodiscard]] inline QJsonValue dataValue(const QJsonDocument &doc, std::initializer_list<QLatin1StringView> names)
    {
        const auto dataObj = dataObject(doc);
        for (const auto name : names) {
            const auto it = dataObj.find(name);
            if (it != dataObj.end()) {
                return (*it);
            }
        }
        return {};
    }

    /** Read a localized string value. */
    [[nodiscard]] QString readLocalizedString(const QJsonObject &obj, QLatin1StringView key);

    /** Read system information data. */
    [[nodiscard]] RentalVehicleNetwork readSystemInformation(const QJsonObject &sysInfo);
}

}

#endif // KPUBLICTRANSPORT_GBFSREADER_H

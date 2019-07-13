/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_ATTRIBUTION_H
#define KPUBLICTRANSPORT_ATTRIBUTION_H

#include "kpublictransport_export.h"
#include "datatypes.h"

#include <vector>

class QJsonArray;
class QJsonObject;
class QString;
class QUrl;

namespace KPublicTransport {

class AttributionPrivate;

/** Copyright and license information about the provided data.
 *  Should be displayed by the application in order to comply with licenses and/or terms and conditions
 *  of the data providers.
 */
class KPUBLICTRANSPORT_EXPORT Attribution
{
    KPUBLICTRANSPORT_GADGET(Attribution)
    /** Name of the entity providing the data. */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)
    /** Link to the entity providing the data. */
    KPUBLICTRANSPORT_PROPERTY(QUrl, url, setUrl)
    /** Name of the license for the provided data. */
    KPUBLICTRANSPORT_PROPERTY(QString, license, setLicense)
    /** Link to the license or terms and conditions text. */
    KPUBLICTRANSPORT_PROPERTY(QUrl, licenseUrl, setLicenseUrl)

    /** @c true if there is license information for this attribution object. */
    Q_PROPERTY(bool hasLicense READ hasLicense STORED false)

public:
    /** Returns @c true if this is an empty or default-constructed Attribution object. */
    bool isEmpty() const;

    bool hasLicense() const;

    /** Serializes one Attribution object to JSON. */
    static QJsonObject toJson(const Attribution &attr);
    /** Serializes an array of Attribution objects to JSON. */
    static QJsonArray toJson(const std::vector<Attribution> &attrs);
    /** Deserialize an Attribution object from JSON. */
    static Attribution fromJson(const QJsonObject &obj);
    /** Dezerializes an array of Attribution objects from JSON. */
    static std::vector<Attribution> fromJson(const QJsonArray &a);
};

}

Q_DECLARE_METATYPE(KPublicTransport::Attribution)

#endif // KPUBLICTRANSPORT_ATTRIBUTION_H

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

#ifndef KPUBLICTRANSPORT_BACKEND_H
#define KPUBLICTRANSPORT_BACKEND_H

#include "kpublictransport_export.h"
#include "datatypes.h"

namespace KPublicTransport {

class BackendPrivate;

/** Information about a backend service queried for location/departure/journey data.
 *  This is used to let the user (API user or end user) determine which backends to query.
 */
class KPUBLICTRANSPORT_EXPORT Backend
{
    KPUBLICTRANSPORT_GADGET(Backend)
    /** Internal identifier of this backend.
     *  Not intended for display, use for storing per-backend settings for example.
     */
    KPUBLICTRANSPORT_PROPERTY(QString, identifier, setIdentifier)
    /** Short, humand readable name of the backend. Typically the company providing the service */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)
    /** Humand readable description of this backend. */
    KPUBLICTRANSPORT_PROPERTY(QString, description, setDescription)
    /** Supports secrure network access.
     *  Yes, even in 2019 that is unfortunately not guaranteed.
     */
    KPUBLICTRANSPORT_PROPERTY(bool, isSecure, setIsSecure)

    /** ISO 3166-2 alpha 2 code of the country this backend service is primarity addressing.
     *  Returns an empty value for global/international services.
     */
    Q_PROPERTY(QString primaryCountryCode READ primaryCountryCode)

public:
    QString primaryCountryCode() const;
};

}

Q_DECLARE_METATYPE(KPublicTransport::Backend)

#endif // KPUBLICTRANSPORT_BACKEND_H

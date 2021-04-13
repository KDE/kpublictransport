/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_BACKEND_H
#define KPUBLICTRANSPORT_BACKEND_H

#include "kpublictransport_export.h"
#include "coveragearea.h"
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
    Q_PROPERTY(QString identifier READ identifier)
    /** Short, humand readable name of the backend. Typically the company providing the service */
    Q_PROPERTY(QString name READ name)
    /** Humand readable description of this backend. */
    Q_PROPERTY(QString description READ description)
    /** Supports secrure network access.
     *  Yes, even in 2019 that is unfortunately not guaranteed.
     */
    Q_PROPERTY(bool isSecure READ isSecure)

    /** ISO 3166-2 alpha 2 code of the country this backend service is primarity addressing.
     *  Returns an empty value for global/international services.
     */
    Q_PROPERTY(QString primaryCountryCode READ primaryCountryCode)

public:
    QString identifier() const;
    QString name() const;
    QString description() const;
    bool isSecure() const;
    QString primaryCountryCode() const;

    CoverageArea coverageArea(CoverageArea::Type coverageType) const;
};

}

Q_DECLARE_METATYPE(KPublicTransport::Backend)

#endif // KPUBLICTRANSPORT_BACKEND_H

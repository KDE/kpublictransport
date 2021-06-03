/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENTRIPPLANNERREQUESTCONTEXT_H
#define KPUBLICTRANSPORT_OPENTRIPPLANNERREQUESTCONTEXT_H

#include <QDateTime>
#include <QMetaType>
#include <QVariant>

namespace KPublicTransport {

/** Journey request context object for OTP2. */
class OpenTripPlannerRequestContext
{
public:
    QDateTime dateTime;
    int searchWindow;

    inline operator QVariant() const {
        return QVariant::fromValue(*this);
    }
};

}

Q_DECLARE_METATYPE(KPublicTransport::OpenTripPlannerRequestContext)

#endif // KPUBLICTRANSPORT_OPENTRIPPLANNERREQUESTCONTEXT_H

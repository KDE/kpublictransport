/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JSONP_H
#define KPUBLICTRANSPORT_JSONP_H

#include "kpublictransport_export.h"

class QByteArray;

namespace KPublicTransport {

/** Decode JSON-P wrapped JSON data.
 *  Also works for regular JSON, ie. this is safe to use unconditionally.
 *  @see https://en.wikipedia.org/wiki/JSONP
 *  @internal exported for onboard API and testing
 */
namespace JsonP
{
    KPUBLICTRANSPORT_EXPORT QByteArray decode(const QByteArray &data);
};

}

#endif // KPUBLICTRANSPORT_JSONP_H

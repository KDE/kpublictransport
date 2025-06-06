/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_USERAGENT_P_H
#define KPUBLICTRANSPORT_USERAGENT_P_H

class QString;

namespace KPublicTransport {
namespace Http {
/** User-Agent string. */
[[nodiscard]] QString userAgent();
}
}

#endif

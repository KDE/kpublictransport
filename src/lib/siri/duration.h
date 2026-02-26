/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_SIRI_DURATION_H
#define KPUBLICTRANSPORT_SIRI_DURATION_H

#include <QStringView>

#include <chrono>

namespace KPublicTransport {

namespace Siri {

/** Parse ISO 8601 durations. */
std::chrono::seconds fromDuration(QStringView duration);

}
}

#endif

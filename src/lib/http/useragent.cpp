/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "useragent_p.h"

#include "kpublictransport_version.h"

#include <QCoreApplication>

using namespace Qt::Literals;
using namespace KPublicTransport;

QString Http::userAgent()
{
    if (!QCoreApplication::applicationVersion().isEmpty()) {
       return "org.kde.kpublictransport/"_L1 + QCoreApplication::applicationName() + '/'_L1 + QCoreApplication::applicationVersion();
    }
    return "org.kde.kpublictransport/"_L1 + QCoreApplication::applicationName() + '/'_L1 + QLatin1StringView(KPUBLICTRANSPORT_VERSION_STRING);
}

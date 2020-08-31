/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "platformutils_p.h"

#include <QString>

using namespace KPublicTransport;

static const char *platform_prefixes[] = {
    "---",
    "bahnsteig",
    "bstg.",
    "gleis",
    "pl.",
    "platform"
};

QString PlatformUtils::normalizePlatform(const QString &platform)
{
    for (const auto prefix : platform_prefixes) {
        if (platform.startsWith(QLatin1String(prefix), Qt::CaseInsensitive)) {
            return platform.mid(strlen(prefix)).trimmed();
        }
    }

    return platform;
}

bool PlatformUtils::platformChanged(const QString &scheduledPlatform, const QString &expectedPlatform)
{
    return !scheduledPlatform.isEmpty() && !expectedPlatform.isEmpty() && scheduledPlatform != expectedPlatform;
}

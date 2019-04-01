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

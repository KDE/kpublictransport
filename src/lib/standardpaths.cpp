/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "standardpaths_p.h"

#include <QFile>
#include <QStandardPaths>

using namespace Qt::Literals;
using namespace KPublicTransport;

QStringList StandardPaths::dataSearchPaths()
{
    QStringList dirs;
#ifndef Q_OS_ANDROID
    dirs = QStandardPaths::standardLocations(QStandardPaths::GenericDataLocation);
    for (auto &dir : dirs) {
        dir += "/org.kde.kpublictransport/"_L1;
    }
#endif
    dirs.push_back(u":/org.kde.kpublictransport/"_s);

    return dirs;
}

QString StandardPaths::locateFile(const QString &name)
{
    const auto dirs = StandardPaths::dataSearchPaths();
    for (auto it = dirs.begin(); it != std::prev(dirs.end()); ++it) {
        const auto path = (*it) + '/'_L1 + name;
        if (QFile::exists(path)) {
            return path;
        }
    }
    return dirs.back() + name;
}

/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_STANDARDPATHS_P_H
#define KPUBLICTRANSPORT_STANDARDPATHS_P_H

#include <QStringList>

class QString;

namespace KPublicTransport {
/** Data file search paths and finding. */
namespace StandardPaths {
/** All folders to search for data files, in the correct order. */
[[nodiscard]] QStringList dataSearchPaths();
/** Locate a specific data file in any of the search paths. */
[[nodiscard]] QString locateFile(const QString &name);
}
}

#endif

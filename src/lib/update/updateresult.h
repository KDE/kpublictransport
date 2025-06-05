/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_UPDATEERROR_H
#define KPUBLICTRANSPORT_UPDATEERROR_H

#include "kpublictransport_export.h"

#include <qobjectdefs.h>

namespace KPublicTransport {
/** Online update result code. */
namespace UpdateResult {
Q_NAMESPACE_EXPORT(KPUBLICTRANSPORT_EXPORT)
enum Type {
    NoError,
    NoUpdate, ///< Update process successful, but nothing changed
    UpdateSuccessful,
    NetworkError,
    FilesystemError,
    IncompatibleVersion, ///< There are updates, but for an incompatible (newer) version.
    FileFormatError,
    UpdatesDisabled, ///< Updates have been disabled by environment/configuration.
    InProgress, ///< Update is currently ongoing.
};
Q_ENUM_NS(Type)
}
}

#endif

/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_MANIFEST_P_H
#define KPUBLICTRANSPORT_MANIFEST_P_H

#include "updateresult.h"

#include <QJsonObject>

class QJsonArray;

namespace KPublicTransport {

/** One entry in an update manifest, representing one file. */
class ManifestEntry {
public:
    explicit ManifestEntry(QJsonObject obj);

    [[nodiscard]] QString fileName() const;
    [[nodiscard]] QString source() const;
    /** Version of the file to update. */
    [[nodiscard]] QString fileVersion() const;

    /** Minimum library version this file is compatible with. */
    [[nodiscard]] QString minimumSupportedVersion() const;

private:
    QJsonObject m_entry;
};

/** The full inventory of files that could potentially be updated. */
class Manifest {
public:
    Manifest() = default;
    explicit Manifest(const QString &path);

    [[nodiscard]] UpdateResult::Type error() const;
    [[nodiscard]] QJsonArray entries() const;

private:
    QJsonObject m_manifest;
    UpdateResult::Type m_error = UpdateResult::NoError;
};

}

#endif

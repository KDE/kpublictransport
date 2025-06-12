/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_UPDATESTATE_P_H
#define KPUBLICTRANSPORT_UPDATESTATE_P_H

#include "updateresult.h"

#include <QVersionNumber>

#include <expected>

class QDateTime;
class QNetworkReply;
class QNetworkRequest;
class QString;
class QStringView;
class QUrl;

namespace KPublicTransport {

class ManifestEntry;
class UpdateTest;

class UpdateState {
public:
    /** Base path for all downloaded content. */
    [[nodiscard]] static QString basePath();

    /** Returns whether updates are disabled based on configuration/environment. */
    [[nodiscard]] static bool isEnabled();

    /** Current library version. */
    [[nodiscard]] static QVersionNumber currentVersion();

    /** Last update time. */
    [[nodiscard]] static QDateTime lastUpdate();

    /** Path to a not yet fully processed updated manifest. */
    [[nodiscard]] static QString manifestPath();

    /** Path to the lock file preventing multiple processes from simultaneous updates. */
    [[nodiscard]] static QString lockFilePath();

    /** Manifest download request, with caching headers set up correctly. */
    [[nodiscard]] QNetworkRequest manifestRequest() const;
    /** Handle manifest download, returns @c true when the manifest changed and there might be content to update. */
    [[nodiscard]] std::expected<bool, UpdateResult::Type> handleManifestReply(QNetworkReply *reply);

    /** Version of @p path.
     *  Null if the file doesn't exist, the current library version if it's bundled, the
     *  downloaded version if it has been updated.
     */
    [[nodiscard]] QVersionNumber fileVersion(const QString &path) const;

    /** Remove all downlaoded files of @p version or older. */
    static void purgeObsoleteFiles(const QVersionNumber &version = UpdateState::currentVersion());

    /** Generate a download request for the given manifest entry. */
    [[nodiscard]] QNetworkRequest fileRequest(const ManifestEntry &entry) const;
    /** Handle the result of a file download. */
    UpdateResult::Type handleFileReply(const ManifestEntry &entry, QNetworkReply *reply);

private:
    friend class UpdateTest;

    [[nodiscard]] static QString stateFilePath();
    [[nodiscard]] static QUrl remoteUrl(QStringView filePath);
};

}

#endif

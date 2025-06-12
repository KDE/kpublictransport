/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_UPDATEJOB_P_H
#define KPUBLICTRANSPORT_UPDATEJOB_P_H

#include "manifest_p.h"
#include "updatestate_p.h"

#include <QObject>

class QLockFile;
class QNetworkAccessManager;

namespace KPublicTransport {

/** Check for updates and download anything that's missing locally. */
class UpdateJob : public QObject
{
    Q_OBJECT
public:
    explicit UpdateJob(QObject *parent = nullptr);

    /** Start the update process. */
    void start(QNetworkAccessManager *nam);

    /** Update result or error code.
     *  Only valid after finished() has been emitted.
     */
    [[nodiscard]] UpdateResult::Type result() const;

Q_SIGNALS:
    void finished();

private:
    void aquireLock();
    void updateManifest();
    void processNextFile();

    UpdateState m_state;
    Manifest m_manifest;
    qsizetype m_currentIdx = 0;
    QNetworkAccessManager *m_nam = nullptr;
    UpdateResult::Type m_result = UpdateResult::NoError;

#ifndef Q_OS_ANDROID
    int m_lockRetryCount = 0;
    std::unique_ptr<QLockFile> m_lockFile;
#endif
};

}

#endif

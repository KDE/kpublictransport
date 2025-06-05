/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "updatejob_p.h"

#include <logging.h>

#include <QFile>
#include <QJsonArray>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QVersionNumber>

using namespace KPublicTransport;

UpdateJob::UpdateJob(QObject *parent)
    : QObject(parent)
{
}

void UpdateJob::start(QNetworkAccessManager *nam)
{
    if (!UpdateState::isEnabled()) {
        m_result = UpdateResult::UpdatesDisabled;
        QMetaObject::invokeMethod(this, &UpdateJob::finished, Qt::QueuedConnection);
        return;
    }

    m_nam = nam;

    auto reply = nam->get(m_state.manifestRequest());
    reply->setParent(this);
    connect(reply, &QNetworkReply::finished, [this, reply]() {
        const auto res = m_state.handleManifestReply(reply);
        if (!res.has_value()) {
            m_result = res.error();
            Q_EMIT finished();
            return;
        }

        if (!*res && !QFile::exists(UpdateState::manifestPath())) {
            // up to date
            m_result = UpdateResult::NoUpdate;
            Q_EMIT finished();
            return;
        }

        m_manifest = Manifest(UpdateState::manifestPath());
        if (m_result == UpdateResult::NoError) {
            m_result = m_manifest.error();
        }
        processNextFile();
    });
}

UpdateResult::Type UpdateJob::result() const
{
    return m_result;
}

void UpdateJob::processNextFile()
{
    const QVersionNumber libVersion = UpdateState::currentVersion();

    for (;m_currentIdx < m_manifest.entries().size() && (m_result == UpdateResult::NoError || m_result == UpdateResult::UpdateSuccessful); ++m_currentIdx) {
        ManifestEntry entry(m_manifest.entries().at(m_currentIdx).toObject());
        const auto fileName = entry.fileName();
        if (fileName.isEmpty()) {
            continue;
        }

        if (libVersion < QVersionNumber::fromString(entry.minimumSupportedVersion())) {
            qCDebug(Log) << "skipping update due to minimum version requirement" << fileName << entry.minimumSupportedVersion();
            continue;
        }

        const auto fileVersion = m_state.fileVersion(fileName);
        if (!fileVersion.isNull() && fileVersion >= QVersionNumber::fromString(entry.fileVersion())) {
            qCDebug(Log) << "skipping update, already up to date" << fileName << entry.fileVersion();
            continue;
        }

        qCDebug(Log) << "updating" << fileName << "from" << fileVersion << "to" << entry.fileVersion();
        auto reply = m_nam->get(m_state.fileRequest(entry));
        reply->setParent(this);
        connect(reply, &QNetworkReply::finished, [this, reply, entry]() {
            m_result = m_state.handleFileReply(entry, reply);
            ++m_currentIdx;
            processNextFile();
        });
        return;
    }

    if (m_result != UpdateResult::NetworkError) {
        // in case of a network error we can resume this later
        QFile::remove(UpdateState::manifestPath());
    }

    if (m_result == UpdateResult::NoError) {
        // manifest update but all files already up to date anyway
        m_result = UpdateResult::NoUpdate;
    }

    Q_EMIT finished();
}

#include "moc_updatejob_p.cpp"

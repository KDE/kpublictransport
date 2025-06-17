/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "manifest_p.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>

#include <algorithm>

using namespace Qt::Literals;
using namespace KPublicTransport;

constexpr inline auto MANIFEST_VERSION = 2;

ManifestEntry::ManifestEntry(QJsonObject obj)
    : m_entry(std::move(obj))
{
}

QString ManifestEntry::fileName() const
{
    auto s = m_entry.value("name"_L1).toString();
    // discard anything that would be an invalid filename character,
    // path traversal or interfere with how we organize things
    if (std::ranges::any_of(std::as_const(s), [](QChar c) { return c == '*'_L1 || c == ':'_L1 || c == '?'_L1; })
        || s.contains(".."_L1) || s.endsWith(".version"_L1) || !s.contains('/'_L1)) {
        qWarning() << "discarding update due to unsafe path:" << s;
        return {};
    }
    return s;
}

QString ManifestEntry::source() const
{
    return m_entry.value("source"_L1).toString();
}

QString ManifestEntry::fileVersion() const
{
    return m_entry.value("version"_L1).toString();
}

QString ManifestEntry::minimumSupportedVersion() const
{
    return m_entry.value("minSupportedVersion"_L1).toString();
}


Manifest::Manifest(const QString &path)
{
    QFile f(path);
    if (!f.open(QFile::ReadOnly)) {
        qWarning() << f.errorString() << f.fileName();
        m_error = UpdateResult::FilesystemError;
        return;
    }

    QJsonParseError error;
    const auto doc = QJsonDocument::fromJson(f.readAll(), &error);
    if (error.error != QJsonParseError::NoError) {
        qWarning() << error.errorString();
        m_error = UpdateResult::FileFormatError;
        return;
    }

    auto obj = doc.object();
    if (obj.value("version"_L1).toInt() != MANIFEST_VERSION) {
        qWarning() << "incompatbile manifest version" << obj.value("version"_L1);
        m_error = UpdateResult::IncompatibleVersion;
        return;
    }
    m_manifest = std::move(obj);
}

UpdateResult::Type Manifest::error() const
{
    return m_error;
}

QJsonArray Manifest::entries() const
{
    return m_manifest.value("entries"_L1).toArray();
}

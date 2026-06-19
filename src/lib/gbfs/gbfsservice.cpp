/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsservice.h"
#include "datatypes/json_p.h"
#include "standardpaths_p.h"

#include <QCryptographicHash>
#include <QDebug>
#include <QDirIterator>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>

using namespace Qt::Literals;
using namespace KPublicTransport;

void GBFSService::generateSystemId()
{
    if (discoveryUrl.isEmpty()) {
        return;
    }
    systemId = QString::fromUtf8(QCryptographicHash::hash(discoveryUrl.toString().toUtf8(), QCryptographicHash::Sha1).toBase64(QByteArray::Base64UrlEncoding));
}

QJsonObject GBFSService::toJson(const GBFSService &service)
{
    auto obj = Json::toJson(service);
    if (!service.httpHeaders.empty()) {
        QJsonObject headers;
        for (const auto [key, value] : service.httpHeaders.asKeyValueRange()) {
            headers.insert(QLatin1StringView(key), QLatin1StringView(value));
        }
        obj.insert("httpHeaders"_L1, headers);
    }
    return obj;
}

QJsonArray GBFSService::toJson(const std::vector<GBFSService> &services)
{
    return Json::toJson(services);
}

GBFSService GBFSService::fromJson(const QJsonObject &obj)
{
    auto service = Json::fromJson<GBFSService>(obj);
    const auto headersObj = obj.value("httpHeaders"_L1).toObject();
    for (auto it = headersObj.begin(); it != headersObj.end(); ++it) {
        service.httpHeaders.insert(it.key().toLatin1(), it.value().toString().toLatin1());
    }
    return service;
}

std::vector<GBFSService> GBFSService::fromJson(const QJsonArray &array)
{
    return Json::fromJson<GBFSService>(array);
}


std::vector<GBFSService> GBFSServiceRepository::m_services;

static QString basePath()
{
    return QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.kpublictransport/gbfs/services/");
}

const std::vector<GBFSService>& GBFSServiceRepository::services()
{
    if (m_services.empty()) {
        load();
    }
    return m_services;
}

void GBFSServiceRepository::store(const GBFSService &service)
{
    if (service.systemId.isEmpty() || service.systemId.contains(QLatin1String("..")) || service.systemId.contains(QLatin1Char('/'))) {
        qWarning() << "invalid service id:" << service.systemId << service.discoveryUrl;
        return;
    }

    const auto base = basePath();
    QDir().mkpath(base);
    const QString fileName = base + service.systemId + QLatin1String(".json");
    QFile f(fileName);
    if (!f.open(QFile::WriteOnly)) {
        qWarning() << f.errorString() << f.fileName();
        return;
    }

    f.write(QJsonDocument(GBFSService::toJson(service)).toJson(QJsonDocument::Compact));
}

void GBFSServiceRepository::reload()
{
    // next access will load on-demand again
    // clearing this is save as GBFSService is an implicitly shared type, existing instances will thus remain valid
    m_services.clear();
}

void GBFSServiceRepository::load()
{
    QDirIterator it(basePath(), QDir::Files);
    while (it.hasNext()) {
        auto n = it.next();
        if (!n.endsWith(QLatin1String(".json"))) {
            continue;
        }

        QFile f(n);
        if (!f.open(QFile::ReadOnly)) {
            qWarning() << f.errorString() << f.fileName();
            continue;
        }

        auto service = GBFSService::fromJson(QJsonDocument::fromJson(f.readAll()).object());
        if (service.systemId.isEmpty()) {
            continue;
        }
        m_services.push_back(std::move(service));
    }
    std::sort(m_services.begin(), m_services.end(), [](const auto &lhs, const auto &rhs) { return lhs.systemId < rhs.systemId; });

    // load missing ones from the initial built-in list
    QFile f(StandardPaths::locateFile(u"networks/gbfs/gbfs-feeds.json"_s));
    if (!f.open(QFile::ReadOnly)) {
        qWarning() << f.errorString();
        return;
    }

    const auto array = QJsonDocument::fromJson(f.readAll()).array();
    m_services.reserve(array.size());
    const auto endIdx = m_services.size();
    for (const auto &v : array) {
        const auto s = GBFSService::fromJson(v.toObject());
        const auto it = std::lower_bound(m_services.begin(), m_services.begin() + endIdx, s, [](const auto &lhs, const auto &rhs) { return lhs.systemId < rhs.systemId; });
        if (it != (m_services.begin() + endIdx) && (*it).systemId == s.systemId) {
            continue;
        }
        m_services.push_back(std::move(s));
    }
}

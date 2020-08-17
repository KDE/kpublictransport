/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsservice.h"
#include "datatypes/json_p.h"

#include <QDebug>
#include <QDirIterator>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>

using namespace KPublicTransport;

QJsonObject GBFSService::toJson(const GBFSService &service)
{
    return Json::toJson(service);
}

GBFSService GBFSService::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<GBFSService>(obj);
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
}

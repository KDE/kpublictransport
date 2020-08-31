/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "load.h"
#include "datatypes_p.h"
#include "json_p.h"

using namespace KPublicTransport;

namespace KPublicTransport {
class LoadInfoPrivate : public QSharedData
{
public:
    Load::Category load = Load::Unknown;
    QString seatingClass;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(LoadInfo)
KPUBLICTRANSPORT_MAKE_PROPERTY(LoadInfo, Load::Category, load, setLoad)
KPUBLICTRANSPORT_MAKE_PROPERTY(LoadInfo, QString, seatingClass, setSeatingClass)

QJsonObject LoadInfo::toJson(const LoadInfo &info)
{
    return Json::toJson(info);
}

QJsonArray LoadInfo::toJson(const std::vector<LoadInfo> &loadInfos)
{
    return Json::toJson(loadInfos);
}

LoadInfo LoadInfo::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<LoadInfo>(obj);
}

std::vector<LoadInfo> LoadInfo::fromJson(const QJsonArray &array)
{
    return Json::fromJson<LoadInfo>(array);
}

#include "moc_load.cpp"

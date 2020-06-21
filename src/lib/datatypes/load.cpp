/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
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

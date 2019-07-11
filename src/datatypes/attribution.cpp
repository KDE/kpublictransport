/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#include "attribution.h"
#include "datatypes_p.h"
#include "json_p.h"

#include <QString>
#include <QUrl>

using namespace KPublicTransport;

namespace KPublicTransport {

class AttributionPrivate : public QSharedData {
public:
    QString name;
    QUrl url;
    QString license;
    QUrl licenseUrl;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(Attribution)
KPUBLICTRANSPORT_MAKE_PROPERTY(Attribution, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(Attribution, QUrl, url, setUrl)
KPUBLICTRANSPORT_MAKE_PROPERTY(Attribution, QString, license, setLicense)
KPUBLICTRANSPORT_MAKE_PROPERTY(Attribution, QUrl, licenseUrl, setLicenseUrl)

std::vector<Attribution> Attribution::fromJson(const QJsonArray &a)
{
    return Json::fromJson<Attribution>(a);
}

Attribution Attribution::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<Attribution>(obj);
}

QJsonArray Attribution::toJson(const std::vector<Attribution> &attrs)
{
    return Json::toJson(attrs);
}

QJsonObject Attribution::toJson(const Attribution &attr)
{
    return Json::toJson(attr);
}

#include "moc_attribution.cpp"

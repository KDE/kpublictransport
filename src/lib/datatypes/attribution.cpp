/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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

bool Attribution::isEmpty() const
{
    return d->name.isEmpty() && d->license.isEmpty();
}

bool Attribution::hasLicense() const
{
    return !d->license.isEmpty() || !d->licenseUrl.isEmpty();
}

std::vector<Attribution> Attribution::fromJson(const QJsonArray &a)
{
    return Json::fromJson<Attribution>(a);
}

Attribution Attribution::fromJson(const QJsonObject &obj)
{
    // read compatibility with github.com/public-transport/transport-apis
    if (obj.value(QLatin1String("isProprietary")).toBool() == true) {
        return {};
    }

    auto attr = Json::fromJson<Attribution>(obj);
    if (attr.url().isEmpty()) {
        attr.setUrl(QUrl(obj.value(QLatin1String("homepage")).toString()));
    }

    return attr;
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

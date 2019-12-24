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

#include "platform.h"
#include "json_p.h"
#include "datatypes_p.h"

#include <QDebug>
#include <QVariant>

using namespace KPublicTransport;

namespace KPublicTransport {

class PlatformSectionPrivate : public QSharedData
{
public:
    QString name;
    float begin = -1.0f;
    float end = -1.0f;
};

class PlatformPrivate : public QSharedData
{
public:
    QString name;
    std::vector<PlatformSection> sections;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(PlatformSection)
KPUBLICTRANSPORT_MAKE_PROPERTY(PlatformSection, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(PlatformSection, float, begin, setBegin)
KPUBLICTRANSPORT_MAKE_PROPERTY(PlatformSection, float, end, setEnd)

QJsonObject PlatformSection::toJson(const PlatformSection &section)
{
    return Json::toJson(section);
}

QJsonArray PlatformSection::toJson(const std::vector<PlatformSection> &sections)
{
    return Json::toJson(sections);
}

PlatformSection PlatformSection::fromJson(const QJsonObject &obj)
{
    return Json::fromJson<PlatformSection>(obj);
}

std::vector<PlatformSection> PlatformSection::fromJson(const QJsonArray &array)
{
    return Json::fromJson<PlatformSection>(array);
}


KPUBLICTRANSPORT_MAKE_GADGET(Platform)
KPUBLICTRANSPORT_MAKE_PROPERTY(Platform, QString, name, setName)

const std::vector<PlatformSection>& Platform::sections() const
{
    return d->sections;
}

std::vector<PlatformSection>&& Platform::takeSections()
{
    return std::move(d->sections);
}

void Platform::setSections(std::vector<PlatformSection> &&sections)
{
    d.detach();
    d->sections = std::move(sections);
}

QJsonObject Platform::toJson(const Platform &platform)
{
    auto obj = Json::toJson(platform);
    if (!platform.sections().empty()) {
        obj.insert(QStringLiteral("sections"), PlatformSection::toJson(platform.sections()));
    }
    return obj;
}

Platform Platform::fromJson(const QJsonObject &obj)
{
    auto p = Json::fromJson<Platform>(obj);
    p.setSections(PlatformSection::fromJson(obj.value(QLatin1String("sections")).toArray()));
    return p;
}

QVariantList Platform::sectionsVariant() const
{
    QVariantList l;
    l.reserve(d->sections.size());
    std::transform(d->sections.begin(), d->sections.end(), std::back_inserter(l), [](const auto &sec) { return QVariant::fromValue(sec); });
    return l;
}

#include "moc_platform.cpp"

/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "platform.h"
#include "json_p.h"
#include "datatypes_p.h"

#include <KLocalizedString>

#include <QDebug>
#include <QVariant>

using namespace Qt::Literals;
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
    int length = -1;
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
KPUBLICTRANSPORT_MAKE_PROPERTY(Platform, int, length, setLength)

bool Platform::isEmpty() const
{
    return d->name.isEmpty() && d->length <= 0.0 && d->sections.empty();
}

const std::vector<PlatformSection>& Platform::sections() const
{
    return d->sections;
}

std::vector<PlatformSection>&& Platform::takeSections()
{
    d.detach();
    return std::move(d->sections);
}

void Platform::setSections(std::vector<PlatformSection> &&sections)
{
    d.detach();
    d->sections = std::move(sections);
}

bool Platform::hasAbsoluteLength() const
{
    return d->length > 1.0;
}

QString Platform::displayString(Line::Mode mode, const QString &name, QLocale::FormatType format)
{
    if (name.isEmpty()) {
        return {};
    }

    switch (mode) {
        case Line::Unknown:
        case Line::Funicular:
        case Line::LocalTrain:
        case Line::LongDistanceTrain:
        case Line::Metro:
        case Line::RailShuttle:
        case Line::RapidTransit:
        case Line::Train:
        case Line::Tramway:
            return format == QLocale::LongFormat ? i18nc("train platform", "Platform %1", name) : i18nc("abbreviated train platform", "Pl. %1", name);
        case Line::Bus:
        case Line::Coach:
        case Line::Shuttle:
            return format == QLocale::LongFormat ? i18nc("bus platform", "Platform %1", name) : i18nc("abbreviated bus platform", "Pl. %1", name);
        case Line::Boat:
        case Line::Ferry:
            return format == QLocale::LongFormat ? i18nc("boat/ferry pier/terminal", "Pier %1", name) : i18nc("abbreviated boat/ferry pier/terminal", "Pier %1", name);
        case Line::Air:
            return format == QLocale::LongFormat ? i18nc("airport gate", "Gate %1", name) : i18nc("abbreviated airport gate", "Gate %1", name);
        case Line::Taxi:
        case Line::RideShare:
        case Line::AerialLift:
            return {};
    }

    return {};
}

QString Platform::displayString(Line::Mode mode)
{
    switch (mode) {
        case Line::Unknown:
        case Line::Funicular:
        case Line::LocalTrain:
        case Line::LongDistanceTrain:
        case Line::Metro:
        case Line::RailShuttle:
        case Line::RapidTransit:
        case Line::Train:
        case Line::Tramway:
            return i18nc("train platform", "Platform");
        case Line::Bus:
        case Line::Coach:
        case Line::Shuttle:
            return i18nc("bus platform", "Platform");
        case Line::Boat:
        case Line::Ferry:
            return i18nc("boat/ferry pier/terminal", "Pier");
        case Line::Air:
            return i18nc("airport gate", "Gate");
        case Line::Taxi:
        case Line::RideShare:
        case Line::AerialLift:
            return {};
    }

    return {};
}

Platform Platform::merge(const Platform &lhs, const Platform &rhs)
{
    // TODO expand this
    return lhs.sections().empty() ? rhs : lhs;
}

QJsonObject Platform::toJson(const Platform &platform)
{
    auto obj = Json::toJson(platform);
    if (!platform.sections().empty()) {
        obj.insert("sections"_L1, PlatformSection::toJson(platform.sections()));
    }
    return obj;
}

QJsonArray Platform::toJson(const std::vector<Platform> &platforms)
{
    return Json::toJson(platforms);
}

Platform Platform::fromJson(const QJsonObject &obj)
{
    auto p = Json::fromJson<Platform>(obj);
    p.setSections(PlatformSection::fromJson(obj.value("sections"_L1).toArray()));
    return p;
}

std::vector<Platform> Platform::fromJson(const QJsonArray &array)
{
    return Json::fromJson<Platform>(array);
}

#include "moc_platform.cpp"

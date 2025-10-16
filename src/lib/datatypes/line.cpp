/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "line.h"
#include "lineutil_p.h"
#include "datatypes_p.h"
#include "json_p.h"
#include "mergeutil_p.h"
#include "assetrepository_p.h"

#include "knowledgedb/linemetadata.h"

#include <QColor>
#include <QDebug>
#include <QUrl>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

namespace KPublicTransport {
class LinePrivate : public QSharedData {
public:
    Line::Mode mode = Line::Unknown;
    QString modeString;
    QString name;
    QColor color;
    QColor textColor;
    LineMetaData metaData;
    QString operatorName;
    QUrl operatorUrl;
};

class RoutePrivate : public QSharedData {
public:
    Line line;
    QString direction;
    Location destination;
    QString name;
};

}

KPUBLICTRANSPORT_MAKE_GADGET(Line)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, QColor, textColor, setTextColor)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, Line::Mode, mode, setMode)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, QString, modeString, setModeString)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, QString, operatorName, setOperatorName)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, QUrl, operatorUrl, setOperatorUrl)

QColor Line::color() const
{
    return (!name().isEmpty() && d->metaData.color().isValid()) ? d->metaData.color() : d->color;
}

void Line::setColor(const QColor &value)
{
    d.detach();
    d->color = value;
}

bool Line::hasColor() const
{
    return d->color.isValid() || (!name().isEmpty() && d->metaData.color().isValid());
}

bool Line::hasTextColor() const
{
    return d->textColor.isValid();
}

QString Line::logo() const
{
    return !name().isEmpty() ? AssetRepository::localFile(d->metaData.logoUrl()).toString(QUrl::FullyEncoded) : QString();
}

bool Line::hasLogo() const
{
    return !logo().isEmpty();
}

QString Line::modeLogo() const
{
    return AssetRepository::localFile(d->metaData.modeLogoUrl()).toString(QUrl::FullyEncoded);
}

bool Line::hasModeLogo() const
{
    return !modeLogo().isEmpty();
}

QString Line::modeIconName() const
{
    return Line::modeIconName(mode());
}

QString Line::modeIconName(Line::Mode mode)
{
    // see https://invent.kde.org/frameworks/breeze-icons/-/issues/16
    switch (mode) {
        case Line::Unknown:
            break;
        case Line::Air:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-flight.svg"_s;
        case Line::Boat:
        case Line::Ferry:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-ferry.svg"_s;
        case Line::Bus:
        case Line::Shuttle:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-bus.svg"_s;
        case Line::Coach:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-bus-longdistance.svg"_s;
        case Line::Funicular:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-funicular.svg"_s;
        case Line::LocalTrain:
        case Line::Train:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-train.svg"_s;
        case Line::LongDistanceTrain:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-train-longdistance.svg"_s;
        case Line::Metro:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-subway.svg"_s;
        case Line::RailShuttle:
        case Line::RapidTransit:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-rapidtransit.svg"_s;
        case Line::Taxi:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-taxi.svg"_s;
        case Line::Tramway:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-tram.svg"_s;
        case Line::RideShare:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-car.svg"_s;
        case Line::AerialLift:
            return u"qrc:///org.kde.kpublictransport/assets/images/transport-mode-aeriallift.svg"_s;
    }

    return u"question"_s;
}

bool Line::modeIsRailBound(Line::Mode mode)
{
    switch (mode) {
        case Line::Train:
        case Line::Funicular:
        case Line::LocalTrain:
        case Line::LongDistanceTrain:
        case Line::Metro:
        case Line::RailShuttle:
        case Line::RapidTransit:
        case Line::Tramway:
            return true;
        default:
            return false;
    }
}

bool Line::isRailBound() const
{
    return modeIsRailBound(d->mode);
}

QString Line::iconName() const
{
    if (hasLogo()) {
        return logo();
    }
    if (hasModeLogo()) {
        return modeLogo();
    }
    return modeIconName();
}

bool Line::isSame(const Line &lhs, const Line &rhs)
{
    if (!LineUtil::isCompatibleMode(lhs.mode(), rhs.mode())) {
        return false;
    }

    // ### not really the most efficient way of doing this...
    using namespace LineUtil;
    return isSameLineNameFuzzy(lhs.name(), rhs.name())
        || isSameLineNameFuzzy(QString(lhs.modeString() + QLatin1Char(' ') + lhs.name()).trimmed(), rhs.name())
        || isSameLineNameFuzzy(lhs.name(), QString(rhs.modeString() + QLatin1Char(' ') + rhs.name()).trimmed())
        || isSameLineNameFuzzy(QString(lhs.modeString() + QLatin1Char(' ') + lhs.name()).trimmed(), QString(rhs.modeString() + QLatin1Char(' ') + rhs.name()).trimmed());
}

static QColor mergeColor(const QColor &lhs, const QColor &rhs)
{
    if (!lhs.isValid()) {
        return rhs;
    }
    if (!rhs.isValid()) {
        return lhs;
    }

    const auto lh = lhs.hue(), ls = lhs.saturation(), lv = lhs.value();
    const auto rh = rhs.hue(), rs = rhs.saturation(), rv = rhs.value();
    return std::tie(ls, lv, lh) < std::tie(rs, rv, rh) ? rhs : lhs;
}

Line Line::merge(const Line &lhs, const Line &rhs)
{
    Line l(lhs);

    l.setModeString(MergeUtil::mergeString(lhs.modeString(), rhs.modeString()));
    l.setName(MergeUtil::mergeString(lhs.name(), rhs.name()));
    if (l.name().startsWith(l.modeString(), Qt::CaseInsensitive)) {
        l.setName(QStringView(l.name()).mid(l.modeString().size()).trimmed().toString());
    }

    l.setColor(mergeColor(lhs.color(), rhs.color()));
    if (!l.textColor().isValid() && rhs.textColor().isValid()) {
        l.setTextColor(rhs.textColor());
    }
    if (l.mode() == Unknown || (l.mode() == Train && rhs.mode() != Unknown)) {
        l.setMode(rhs.mode());
    }

    l.setOperatorName(MergeUtil::mergeString(lhs.operatorName(), rhs.operatorName()));
    l.setOperatorUrl(MergeUtil::mergeUrl(lhs.operatorUrl(), rhs.operatorUrl()));
    return l;
}

void Line::applyMetaData(const Location &location, bool download)
{
    if (!location.hasCoordinate()) {
        return;
    }

    if (!name().isEmpty()) {
        d->metaData = LineMetaData::find(location.latitude(), location.longitude(), name(), mode());
    } else {
        d->metaData = LineMetaData::find(location.latitude(), location.longitude(), mode());
    }

    if (download && AssetRepository::instance()) {
        AssetRepository::instance()->download(d->metaData.logoUrl());
        AssetRepository::instance()->download(d->metaData.modeLogoUrl());
    }
}

QJsonObject Line::toJson(const Line &l)
{
    auto obj = Json::toJson(l);
    if (l.mode() == Unknown) {
        obj.remove(QLatin1String("mode"));
    }
    return obj;
}

QJsonArray Line::toJson(const std::vector<Line> &lines)
{
    return Json::toJson(lines);
}

Line Line::fromJson(const QJsonObject &obj)
{
    auto l = Json::fromJson<Line>(obj);
    return l;
}

std::vector<Line> Line::fromJson(const QJsonArray &array)
{
    return Json::fromJson<Line>(array);
}


KPUBLICTRANSPORT_MAKE_GADGET(Route)
KPUBLICTRANSPORT_MAKE_PROPERTY(Route, Line, line, setLine)
KPUBLICTRANSPORT_MAKE_PROPERTY(Route, Location, destination, setDestination)
KPUBLICTRANSPORT_MAKE_PROPERTY(Route, QString, name, setName)

QString Route::direction() const
{
    if (d->direction.isEmpty() && !d->destination.isEmpty()) {
        return d->destination.name();
    }
    return d->direction;
}

void Route::setDirection(const QString &value)
{
    d.detach();
    d->direction = value;
}

bool Route::isSame(const Route &lhs, const Route &rhs)
{
    const auto matchingDirection = (!lhs.destination().isEmpty() && !rhs.destination().isEmpty() && Location::isSame(lhs.destination(), rhs.destination()))
        || Location::isSameName(lhs.direction(), rhs.direction());

    const auto matchingRouteName = lhs.name().size() < 3 || rhs.name().size() < 3 || lhs.name().endsWith(rhs.name()) || rhs.name().endsWith(lhs.name());

    return matchingDirection && matchingRouteName && Line::isSame(lhs.line(), rhs.line());
}

Route Route::merge(const Route &lhs, const Route &rhs)
{
    Route r(lhs);
    r.setLine(Line::merge(lhs.line(), rhs.line()));
    r.setName(MergeUtil::mergeString(lhs.name(), rhs.name()));
    r.setDirection(MergeUtil::mergeString(lhs.direction(), rhs.direction()));
    r.setDestination(Location::merge(lhs.destination(), rhs.destination()));
    return r;
}

QJsonObject Route::toJson(const Route &r)
{
    auto obj = Json::toJson(r);
    const auto lineObj = Line::toJson(r.line());
    if (!lineObj.empty()) {
        obj.insert(QLatin1String("line"), lineObj);
    }
    if (!r.destination().isEmpty()) {
        obj.insert(QLatin1String("destination"), Location::toJson(r.destination()));
    }
    return obj;
}

Route Route::fromJson(const QJsonObject &obj)
{
    auto r = Json::fromJson<Route>(obj);
    r.setLine(Line::fromJson(obj.value(QLatin1String("line")).toObject()));
    r.setDestination(Location::fromJson(obj.value(QLatin1String("destination")).toObject()));
    return r;
}

#include "moc_line.cpp"

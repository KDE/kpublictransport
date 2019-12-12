/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#include "line.h"
#include "location.h"
#include "datatypes_p.h"
#include "json_p.h"
#include "mergeutil_p.h"

#include <QColor>
#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class LinePrivate : public QSharedData {
public:
    Line::Mode mode = Line::Unknown;
    QString modeString;
    QString name;
    QColor color;
    QColor textColor;
};

class RoutePrivate : public QSharedData {
public:
    Line line;
    QString direction;
    Location destination;
};

}

template <typename Iter>
static bool isSameLineName(const Iter &lBegin, const Iter &lEnd, const Iter &rBegin, const Iter &rEnd)
{
    auto lIt = lBegin;
    auto rIt = rBegin;
    while (lIt != lEnd && rIt != rEnd) {
        // ignore spaces etc.
        if (!(*lIt).isLetter() && !(*lIt).isDigit()) {
            ++lIt;
            continue;
        }
        if (!(*rIt).isLetter() && !(*rIt).isDigit()) {
            ++rIt;
            continue;
        }

        if ((*lIt).toCaseFolded() != (*rIt).toCaseFolded()) {
            return false;
        }

        ++lIt;
        ++rIt;
    }

    if (lIt == lEnd && rIt == rEnd) { // both inputs fully consumed, and no mismatch found
        return true;
    }

    // one input is prefix of the other, that is ok if there's a separator
    return (lIt != lEnd && (*lIt).isSpace()) || (rIt != rEnd && (*rIt).isSpace());
}

static bool isSameLineName(const QString &lhs, const QString &rhs)
{
    return isSameLineName(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
        || isSameLineName(lhs.rbegin(), lhs.rend(), rhs.rbegin(), rhs.rend());
}

KPUBLICTRANSPORT_MAKE_GADGET(Line)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, QColor, color, setColor)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, QColor, textColor, setTextColor)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, Line::Mode, mode, setMode)
KPUBLICTRANSPORT_MAKE_PROPERTY(Line, QString, modeString, setModeString)

bool Line::hasColor() const
{
    return d->color.isValid();
}

bool Line::hasTextColor() const
{
    return d->textColor.isValid();
}

static bool isCompatibleMode(Line::Mode lhs, Line::Mode rhs)
{
    if (lhs == rhs || lhs == Line::Unknown || rhs == Line::Unknown) {
        return true;
    }

    if (lhs == Line::Train) {
        return rhs == Line::LocalTrain || rhs == Line::LongDistanceTrain;
    }
    if (rhs == Line::Train) {
        return lhs == Line::LocalTrain || lhs == Line::LongDistanceTrain;
    }

    return false;
}

bool Line::isSame(const Line &lhs, const Line &rhs)
{
    if (!isCompatibleMode(lhs.mode(), rhs.mode())) {
        return false;
    }

    // ### not really the most efficient way of doing this...
    return isSameLineName(lhs.name(), rhs.name())
        || isSameLineName(QString(lhs.modeString() + QLatin1Char(' ') + lhs.name()).trimmed(), rhs.name())
        || isSameLineName(lhs.name(), QString(rhs.modeString() + QLatin1Char(' ') + rhs.name()).trimmed())
        || isSameLineName(QString(lhs.modeString() + QLatin1Char(' ') + lhs.name()).trimmed(), QString(rhs.modeString() + QLatin1Char(' ') + rhs.name()).trimmed());
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
        l.setName(l.name().midRef(l.modeString().size()).trimmed().toString());
    }

    l.setColor(mergeColor(lhs.color(), rhs.color()));
    if (!l.textColor().isValid() && rhs.textColor().isValid()) {
        l.setTextColor(rhs.textColor());
    }
    if (l.mode() == Unknown || (l.mode() == Train && rhs.mode() != Unknown)) {
        l.setMode(rhs.mode());
    }
    return l;
}

QJsonObject Line::toJson(const Line &l)
{
    auto obj = Json::toJson(l);
    return obj;
}

Line Line::fromJson(const QJsonObject &obj)
{
    auto l = Json::fromJson<Line>(obj);
    return l;
}


KPUBLICTRANSPORT_MAKE_GADGET(Route)
KPUBLICTRANSPORT_MAKE_PROPERTY(Route, Line, line, setLine)
KPUBLICTRANSPORT_MAKE_PROPERTY(Route, Location, destination, setDestination)

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

    return matchingDirection && Line::isSame(lhs.line(), rhs.line());
}

Route Route::merge(const Route &lhs, const Route &rhs)
{
    Route r(lhs);
    r.setLine(Line::merge(lhs.line(), rhs.line()));
    r.setDirection(MergeUtil::mergeString(lhs.direction(), rhs.direction()));
    r.setDestination(Location::merge(lhs.destination(), rhs.destination()));
    return r;
}

QJsonObject Route::toJson(const Route &r)
{
    auto obj = Json::toJson(r);
    obj.insert(QStringLiteral("line"), Line::toJson(r.line()));
    if (!r.destination().isEmpty()) {
        obj.insert(QStringLiteral("destination"), Location::toJson(r.destination()));
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

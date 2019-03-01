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
#include "json.h"
#include "mergeutil_p.h"

#include <QColor>
#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class LinePrivate : public QSharedData {
public:
    Line::Mode mode;
    QString modeString;
    QString name;
    QColor color;
    QColor textColor;
};

class RoutePrivate : public QSharedData {
public:
    Line line;
    QString direction;
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

QString Line::name() const
{
    return d->name;
}

void Line::setName(const QString &name)
{
    d.detach();
    d->name = name;
}

QColor Line::color() const
{
    return d->color;
}

void Line::setColor(const QColor &color)
{
    d.detach();
    d->color = color;
}

bool Line::hasColor() const
{
    return d->color.isValid();
}

QColor Line::textColor() const
{
    return d->textColor;
}

void Line::setTextColor(const QColor &textColor)
{
    d.detach();
    d->textColor = textColor;
}

bool Line::hasTextColor() const
{
    return d->textColor.isValid();
}

Line::Mode Line::mode() const
{
    return d->mode;
}

void Line::setMode(Line::Mode mode)
{
    d.detach();
    d->mode = mode;
}

QString Line::modeString() const
{
    return d->modeString;
}

void Line::setModeString(const QString &modeString)
{
    d.detach();
    d->modeString = modeString;
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

Line Line::merge(const Line &lhs, const Line &rhs)
{
    Line l(lhs);

    // TODO this needs to deal with duplication between mode and name!
    l.setModeString(MergeUtil::mergeString(lhs.modeString(), rhs.modeString()));
    l.setName(MergeUtil::mergeString(lhs.name(), rhs.name()));

    if (!l.color().isValid() && rhs.color().isValid()) {
        l.setColor(rhs.color());
    }
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

Line Route::line() const
{
    return d->line;
}

void Route::setLine(const Line &line)
{
    d.detach();
    d->line = line;
}

QString Route::direction() const
{
    return d->direction;
}

void Route::setDirection(const QString &direction)
{
    d.detach();
    d->direction = direction;
}

bool Route::isSame(const Route &lhs, const Route &rhs)
{
    return Location::isSameName(lhs.direction(), rhs.direction()) &&
        Line::isSame(lhs.line(), rhs.line());
}

Route Route::merge(const Route &lhs, const Route &rhs)
{
    Route r(lhs);
    r.setLine(Line::merge(lhs.line(), rhs.line()));
    r.setDirection(MergeUtil::mergeString(lhs.direction(), rhs.direction()));
    return r;
}

QJsonObject Route::toJson(const Route &r)
{
    auto obj = Json::toJson(r);
    obj.insert(QLatin1String("line"), Line::toJson(r.line()));
    return obj;
}

Route Route::fromJson(const QJsonObject &obj)
{
    auto r = Json::fromJson<Route>(obj);
    r.setLine(Line::fromJson(obj.value(QLatin1String("line")).toObject()));
    return r;
}

#include "moc_line.cpp"

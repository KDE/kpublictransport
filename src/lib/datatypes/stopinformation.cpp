/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "stopinformation.h"

#include "datatypes_p.h"
#include "json_p.h"
#include "line.h"

#include <QJsonObject>

using namespace Qt::Literals;
using namespace KPublicTransport;


namespace KPublicTransport {
class StopInformationPrivate : public QSharedData {
public:
    std::vector<Line> lines;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(StopInformation)

const std::vector<Line>& StopInformation::lines() const
{
    return d->lines;
}

void StopInformation::setLines(const std::vector<Line> &lines)
{
    d.detach();
    d->lines.clear();
    for (const auto &line : lines) {
        addLine(line);
    }
}

static constexpr const Line::Mode mode_sort_order[] = {
    Line::Unknown,
    Line::Air,
    Line::LongDistanceTrain,
    Line::Train,
    Line::LocalTrain,
    Line::RapidTransit,
    Line::Metro,
    Line::RailShuttle,
    Line::Tramway,
    Line::Funicular,
    Line::Coach,
    Line::Shuttle,
    Line::Bus,
    Line::Ferry,
    Line::Boat,
    Line::AerialLift,
    Line::Taxi,
    Line::RideShare,
};

void StopInformation::addLine(const KPublicTransport::Line &line)
{
    if (line.mode() == Line::Unknown) {
        return;
    }

    d.detach();
    for (auto &l : d->lines) {
        if (Line::isSame(l, line)) {
            l = Line::merge(l, line);
            return;
        }
        if (l.name().isEmpty() && l.mode() == line.mode()) {
            l = Line::merge(l, line);
            return;
        }
        if (line.name().isEmpty() && l.mode() == line.mode()) {
            return;
        }
    }
    d->lines.push_back(line);

    std::ranges::sort(d->lines, [](const Line &lhs, const Line &rhs) {
        if (lhs.mode() == rhs.mode()) {
            return lhs.name() < rhs.name();
        }
        return std::ranges::find(mode_sort_order, lhs.mode()) < std::ranges::find(mode_sort_order, rhs.mode());
    });
}

void StopInformation::applyMetaData(const Location &loc, bool download)
{
    for (auto &line : d->lines) {
        line.applyMetaData(loc, download);
    }
}

StopInformation StopInformation::merge(const StopInformation &lhs, const StopInformation &rhs)
{
    auto res = lhs;
    for (const auto &rhsLine : rhs.lines()) {
        res.addLine(rhsLine);
    }
    return res;
}

QJsonObject StopInformation::toJson(const StopInformation &info)
{
    auto obj = Json::toJson(info);
    if (!info.lines().empty()) {
        obj.insert("lines"_L1, Line::toJson(info.lines()));
    }
    return obj;
}

StopInformation StopInformation::fromJson(const QJsonObject &obj)
{
    auto info = Json::fromJson<StopInformation>(obj);
    info.d->lines = Line::fromJson(obj.value("lines"_L1).toArray());
    return info;
}

#include "moc_stopinformation.cpp"

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

#include "lineinfo.h"

#include <QDebug>

enum {
    BoundingBoxSizeWarning = 12'000'000, // warning threshold for bbox sizes, in 1/1e7-th degree
};

LineInfo::LineInfo() = default;
LineInfo::~LineInfo() = default;

bool LineInfo::isUseful(const LineInfo& info)
{
    return (info.mode != Unknown && info.mode != LongDistance)
        && !info.name.isEmpty()
        && (info.color.isValid() || !info.logoName.isEmpty());
}

static LineInfo::Mode lineModeStringToMode(const QString &s)
{
   if (s == QLatin1String("subway")) {
        return LineInfo::Subway;
    }
    if (s == QLatin1String("tram")) {
        return LineInfo::Tram;
    }
    if (s == QLatin1String("light_rail") || s == QLatin1String("commuter")) {
        return LineInfo::RapidTransit;
    }
    if (s == QLatin1String("national") || s == QLatin1String("long_distance") || s == QLatin1String("international")) {
        return LineInfo::LongDistance;
    }
    return LineInfo::Unknown;
}

LineInfo::Mode LineInfo::determineMode(const OSM::Relation &rel)
{
    auto m = lineModeStringToMode(OSM::tagValue(rel, QLatin1String("route_master")));
    if (m != Unknown) return m;

    m = lineModeStringToMode(OSM::tagValue(rel, QLatin1String("route")));
    if (m != Unknown) return m;

    m = lineModeStringToMode(OSM::tagValue(rel, QLatin1String("line")));
    if (m != Unknown) return m;

    m = lineModeStringToMode(OSM::tagValue(rel, QLatin1String("service")));
    if (m != Unknown) return m;

    return lineModeStringToMode(OSM::tagValue(rel, QLatin1String("passenger")));
}

LineInfo LineInfo::fromRelation(const OSM::Relation &rel)
{
    LineInfo info;
    info.relId = rel.id;

    // check for under constructions or out-of-service tags
    const auto underConstruction = OSM::tagValue(rel, QLatin1String("construction"));
    if (underConstruction == QLatin1String("yes")) {
        return info;
    }

    info.name = OSM::tagValue(rel, QLatin1String("ref"));
    // ### TEMPORARY normalize name, so a simple string comparison as currently
    // used in the generator does produce correct results.
    // this should eventually be replaced by using the same name comparison logic
    // as used in the library
    info.name = info.name.remove(QLatin1Char(' '));

    const auto colStr = OSM::tagValue(rel, QLatin1String("colour"));
    if (!colStr.isEmpty()) {
        info.color = QColor(colStr);
    }
    info.wdId = OSM::tagValue(rel, QLatin1String("wikidata"));
    info.mode = determineMode(rel);

    info.bbox = rel.bbox;
    if (isUseful(info) && (info.bbox.width() > BoundingBoxSizeWarning || info.bbox.height() > BoundingBoxSizeWarning)) {
        qWarning() << "Suspicious bbox size:" << info.relId << info.name << info.bbox;
    }

    return info;
}

void LineInfo::merge(LineInfo &lhs, const LineInfo &rhs)
{
    Q_ASSERT(!lhs.name.isEmpty());
    if (!rhs.name.isEmpty() && lhs.name != rhs.name) {
        qDebug() << "OSM name conflict:" << lhs.name << lhs.relId << rhs.name << rhs.relId;
    }

    if (lhs.color.isValid() && rhs.color.isValid() && lhs.color != rhs.color) {
        qWarning() << "OSM color conflict:" << lhs.relId << rhs.relId << lhs.name << lhs.color.name() << rhs.color.name();
    } else if (rhs.color.isValid()) {
        lhs.color = rhs.color;
    }
    if (!lhs.wdId.isEmpty() && !rhs.wdId.isEmpty() && lhs.wdId != rhs.wdId) {
        qWarning() << "wikidata id conflict:" << lhs.relId << rhs.relId << lhs.name << lhs.wdId << rhs.wdId;
    } else if (!rhs.wdId.isEmpty()) {
        lhs.wdId = rhs.wdId;
    }
    if (lhs.mode != Unknown && rhs.mode != Unknown && lhs.mode != rhs.mode) {
        qWarning() << "OSM mode conflict:" << lhs.relId << lhs.mode << rhs.relId << rhs.mode << lhs.name;
    }
    lhs.mode = std::max(lhs.mode, rhs.mode);
    lhs.bbox = OSM::unite(lhs.bbox, rhs.bbox);
    if (LineInfo::isUseful(lhs) && (lhs.bbox.width() > BoundingBoxSizeWarning || lhs.bbox.height() > BoundingBoxSizeWarning)) {
        qWarning() << "Suspicious bbox size after merging:" << lhs.relId << lhs.name << lhs.bbox << rhs.relId << rhs.name << rhs.bbox << lhs.bbox.width() << rhs.bbox.height();
    }
}

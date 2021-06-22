/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "lineinfo.h"
#include "../lib/datatypes/linecompare_p.h"

#include <QDebug>

enum {
    BoundingBoxSizeWarning = 12'000'000, // warning threshold for bbox sizes, in 1/1e7-th degree
};

LineInfo::LineInfo() = default;
LineInfo::~LineInfo() = default;

bool LineInfo::isUseful(const LineInfo& info)
{
    if (info.name.isEmpty())
        return false;

    switch (info.mode) {
        case Unknown:
            return false;
        case LongDistance:
        case LocalTrain:
            return false;
            //return !info.lineLogos.empty() || !info.productLogos.empty();
        case RapidTransit:
        case Tram:
        case Subway:
            return info.color.isValid() || !info.lineLogos.isEmpty() || !info.productLogos.isEmpty();
    }
    return false;
}

static LineInfo::Mode lineModeStringToMode(const QByteArray &s)
{
   if (s == "subway") {
        return LineInfo::Subway;
    }
    if (s == "tram") {
        return LineInfo::Tram;
    }
    if (s == "light_rail" || s == "commuter" || s == "suburban") {
        return LineInfo::RapidTransit;
    }
    if (s == "national" || s == "long_distance" || s == "international" || s == "high_speed") {
        return LineInfo::LongDistance;
    }
    if (s == "regional") {
        return LineInfo::LocalTrain;
    }
    return LineInfo::Unknown;
}

LineInfo::Mode LineInfo::determineMode(const OSM::Relation &rel)
{
    auto m = lineModeStringToMode(OSM::tagValue(rel, "route_master"));
    if (m != Unknown) return m;

    m = lineModeStringToMode(OSM::tagValue(rel, "route"));
    if (m != Unknown) return m;

    return std::max(lineModeStringToMode(OSM::tagValue(rel, "line")),
           std::max(lineModeStringToMode(OSM::tagValue(rel, "service")),
                    lineModeStringToMode(OSM::tagValue(rel, "passenger"))));
}

LineInfo LineInfo::fromRelation(const OSM::Relation &rel)
{
    LineInfo info;
    info.relId = rel.id;

    // check for under constructions or out-of-service tags
    const auto underConstruction = OSM::tagValue(rel, "construction");
    if (underConstruction == "yes") {
        return info;
    }

    info.name = QString::fromUtf8(OSM::tagValue(rel, "ref"));
    const auto colStr = OSM::tagValue(rel, "colour");
    if (!colStr.isEmpty()) {
        info.color = QColor(QString::fromUtf8(colStr));
    }
    info.wdId = Wikidata::Q(OSM::tagValue(rel, "wikidata"));
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
    if (!rhs.name.isEmpty() && !KPublicTransport::Internal::isSameLineName(lhs.name, rhs.name, KPublicTransport::Internal::StrictCompare)) {
        qDebug() << "OSM name conflict:" << lhs << rhs;
    }

    if (lhs.color.isValid() && rhs.color.isValid() && lhs.color != rhs.color) {
        qWarning() << "OSM color conflict:" << lhs << rhs;
    } else if (rhs.color.isValid()) {
        lhs.color = rhs.color;
    }
    if (lhs.wdId.isValid() && rhs.wdId.isValid() && lhs.wdId != rhs.wdId) {
        qWarning() << "wikidata id conflict:" << lhs << rhs;
    } else if (rhs.wdId.isValid()) {
        lhs.wdId = rhs.wdId;
    }
    if (lhs.mode != Unknown && rhs.mode != Unknown && lhs.mode != rhs.mode) {
        qWarning() << "OSM mode conflict:" << lhs << rhs;
    }
    lhs.mode = std::max(lhs.mode, rhs.mode);
    lhs.bbox = OSM::unite(lhs.bbox, rhs.bbox);
    if (LineInfo::isUseful(lhs) && (lhs.bbox.width() > BoundingBoxSizeWarning || lhs.bbox.height() > BoundingBoxSizeWarning)) {
        qWarning() << "Suspicious bbox size after merging:" << lhs << rhs;
    }
}

QDebug operator<<(QDebug debug, const LineInfo &info)
{
    QDebugStateSaver saver(debug);
    debug.noquote().nospace()
        << info.name
        << " https://openstreetmap.org/relation/" << info.relId
        << " " << info.mode
        << (info.color.isValid() ? (QLatin1Char(' ') + info.color.name()) : QString())
        << (info.wdId.isValid() ? QString(QLatin1Char(' ')) : QString()) << info.wdId
        << " " << info.bbox;
    return debug;
}

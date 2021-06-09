/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "efaparser.h"
#include "logging.h"
#include "scopedxmlstreamreader.h"

#include <KPublicTransport/Path>

using namespace KPublicTransport;

EfaParser::~EfaParser() = default;

void EfaParser::setLocationIdentifierType(const QString& locationIdentifierType)
{
    m_locationIdentifierType = locationIdentifierType;
}

Reply::Error EfaParser::error() const
{
    return m_error;
}

QString EfaParser::errorMessage() const
{
    return m_errorMsg;
}

Line::Mode EfaParser::motTypeToLineMode(int mot)
{
    // comments below are EFA names found in XML responses (usually translated)
    // the mapping isn't necessary 100% obvious everywhere
    switch (mot) {
        case 0: return Line::Train;
        case 1: return Line::RapidTransit; // "Commuter railway"
        case 2: return Line::Metro; // "Subway"
        case 3: return Line::RapidTransit; // "City rail" / "Stadtbahn"
        case 4: return Line::Tramway;
        case 5: return Line::Bus;
        case 6: return Line::Bus; // "Regional bus"
        case 7: return Line::BusRapidTransit; // "Express bus"
        case 8: return Line::Funicular; // "Cable car/Rack railway"
        case 9: return Line::Ferry;
        case 10: return Line::Taxi; // "Taxi on demand"
        case 11: return Line::Unknown; // "Other"
        case 12: return Line::Air; // "Airplane"
        case 13: return Line::LocalTrain;
        case 14:
        case 15:
        case 16:
            return Line::LongDistanceTrain; // "Train (intercity)"
        case 17: return Line::Bus; // "Rail replacement service"
        case 18: return Line::Train; // "Rail shuttle"
        case 19: return Line::Bus; // "Peoples bus" / "Bürgerbus"
    }
    qCDebug(Log) << "Unknown means ot transport: " << mot;
    return Line::Unknown;
}

Path EfaParser::parsePathCoordinatesElement(ScopedXmlStreamReader &reader)
{
    QPolygonF poly;
    // TODO do we need to support the format attributes, or is this always the same anyway?
    const auto coords = reader.readElementText().split(QLatin1Char(' '), Qt::SkipEmptyParts);
    poly.reserve(coords.size());
    for (const auto &coord : coords) {
        const auto p = coord.split(QLatin1Char(','));
        if (p.size() == 2) {
            poly.push_back({p[0].toDouble(), p[1].toDouble()});
        }
    }

    PathSection section;
    section.setPath(poly);
    Path path;
    path.setSections({section});
    return path;
}

bool EfaParser::isDummyStopId(QStringView id)
{
    return id == QLatin1String("99999997") || id == QLatin1String("99999998");
}

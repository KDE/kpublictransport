/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_EFAXMLPARSER_H
#define KPUBLICTRANSPORT_EFAXMLPARSER_H

#include "efaparser.h"

#include <KPublicTransport/Path>

#include <QPointF>

class QPolygonF;

namespace KPublicTransport {

class ScopedXmlStreamReader;

/** Parser for full XML responses from EFA services.
 *  @internal only exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT EfaXmlParser : public EfaParser
{
public:
    std::vector<Location> parseStopFinderResponse(const QByteArray &data) override;
    std::vector<Stopover> parseDmResponse(const QByteArray &data) override;
    std::vector<Journey> parseTripResponse(const QByteArray &data) override;

private:
    void parseLocationCommon(Location &loc, const ScopedXmlStreamReader &reader) const;
    Location parseItdOdvAssignedStop(const ScopedXmlStreamReader &reader) const;
    Location parseOdvNameElem(ScopedXmlStreamReader &reader) const;

    Stopover parseDmDeparture(ScopedXmlStreamReader &&reader) const;
    void parseTripDeparture(ScopedXmlStreamReader &&reader, JourneySection &section) const;
    void parseTripArrival(ScopedXmlStreamReader &&reader, JourneySection &section) const;

    Stopover parsePartialTripIntermediateStop(ScopedXmlStreamReader &&reader) const;
    std::vector<Stopover> parsePartialTripStopSequence(ScopedXmlStreamReader &&reader) const;

    std::vector<JourneySection> parseTripPartialRoute(ScopedXmlStreamReader &&reader) const;
    Journey parseTripRoute(ScopedXmlStreamReader &&reader) const;
    QStringList parseInfoLink(ScopedXmlStreamReader &&reader) const;
    QPolygonF parsePathCoordinates(ScopedXmlStreamReader &&reader) const;

    struct PathDescription {
        QPointF point;
        int fromIndex = -1;
        int toIndex = -1;
        QString description;
        int travelTime = 0;
        int niveau = 0;
        int niveauDelta = 0;
        PathSection::Maneuver maneuver = PathSection::Move;
    };

    std::vector<PathDescription> parsePathDescriptionList(ScopedXmlStreamReader &&reader) const;
    void resolvePathDescription(std::vector<PathDescription> &descs) const;
    Path assemblePath(const std::vector<PathDescription> &descs, const QPolygonF &poly) const;
    QHash<QString, QString> parseGenericAttributeList(ScopedXmlStreamReader &&reader) const;

    mutable QHash<QString, Location> m_locations;
};

}

#endif // KPUBLICTRANSPORT_EFAXMLPARSER_H

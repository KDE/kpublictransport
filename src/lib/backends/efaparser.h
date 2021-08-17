/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_EFAPARSER_H
#define KPUBLICTRANSPORT_EFAPARSER_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Line>
#include <KPublicTransport/Reply>

#include <QHash>
#include <QString>

#include <vector>

class QByteArray;
class QPolygonF;

namespace KPublicTransport {

class Journey;
class JourneySection;
class Location;
class Path;
class ScopedXmlStreamReader;
class Stopover;

/** Journey query context for previous/next queries.
 *  @internal only exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT EfaJourneyQueryContext
{
public:
    QString sessionId;
    QString requestId;

    bool isEmpty();
};

/** Base class for parsers for responses from EFA services.
 *  @internal just exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT EfaParser
{
public:
    virtual ~EfaParser();

    void setLocationIdentifierType(const  QString &locationIdentifierType);

    Reply::Error error() const;
    QString errorMessage() const;

    virtual std::vector<Location> parseStopFinderResponse(const QByteArray &data) = 0;
    virtual std::vector<Stopover> parseDmResponse(const QByteArray &data) = 0;
    virtual std::vector<Journey> parseTripResponse(const QByteArray &data) = 0;

    EfaJourneyQueryContext journeyQueryContext() const;

protected:
    /** convert "means of transport" type id to Line::Mode
     * so far this seems to be identical in all installations, if that eventually changes
     * this needs a similar configuration as Hafas uses.
     */
    static Line::Mode motTypeToLineMode(int mot);

    /** Parse path encoded as a space separated string of coordinate pairs. */
    static QPolygonF parsePathCoordinatesElement(ScopedXmlStreamReader &reader);
    /** Turn a polygon into a section path. */
    static Path polygonToPath(const QPolygonF &poly);

    /** Returns @c true if the given stop id is a dummy value used for non-stops. */
    static bool isDummyStopId(QStringView id);

    /** Parses a key/value list structure. */
    static QHash<QString, QString> parseKeyValueList(ScopedXmlStreamReader &&reader, QLatin1String elemName, QLatin1String keyName, QLatin1String valueName);

    QString m_locationIdentifierType;
    QString m_errorMsg;
    Reply::Error m_error = Reply::NoError;
    EfaJourneyQueryContext m_journeyContext;
};

}

#endif // KPUBLICTRANSPORT_EFAPARSER_H

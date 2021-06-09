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

namespace KPublicTransport {

class Journey;
class JourneySection;
class Location;
class Path;
class ScopedXmlStreamReader;
class Stopover;

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

    virtual std::vector<Location> parseStopFinderResponse(const QByteArray &data) const = 0;
    virtual std::vector<Stopover> parseDmResponse(const QByteArray &data) const = 0;
    virtual std::vector<Journey> parseTripResponse(const QByteArray &data) const = 0;

protected:
    /** convert "means of transport" type id to Line::Mode
     * so far this seems to be identical in all installations, if that eventually changes
     * this needs a similar configuration as Hafas uses.
     */
    static Line::Mode motTypeToLineMode(int mot);

    /** Parse path encoded as a space separated string of coordinate pairs. */
    static Path parsePathCoordinatesElement(ScopedXmlStreamReader &reader);

    /** Returns @c true if the given stop id is a dummy value used for non-stops. */
    static bool isDummyStopId(QStringView id);

    QString m_locationIdentifierType;
    mutable QString m_errorMsg;
    mutable Reply::Error m_error = Reply::NoError;
};

}

#endif // KPUBLICTRANSPORT_EFAPARSER_H

/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_EFAPARSER_H
#define KPUBLICTRANSPORT_EFAPARSER_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Reply>

#include <QHash>
#include <QString>

#include <vector>

class QByteArray;
class QXmlStreamReader;

namespace KPublicTransport {

class Departure;
class Journey;
class JourneySection;
class Location;

/** Base class for parsers for responses from EFA services.
 *  @internal just exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT EfaParser
{
public:
    void setLocationIdentifierType(const  QString &locationIdentifierType);

    Reply::Error error() const;
    QString errorMessage() const;

protected:
    QString m_locationIdentifierType;
    mutable QString m_errorMsg;
    mutable Reply::Error m_error = Reply::NoError;
};

}

#endif // KPUBLICTRANSPORT_EFAPARSER_H

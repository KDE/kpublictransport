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

#ifndef KPUBLICTRANSPORT_HAFASBACKEND_H
#define KPUBLICTRANSPORT_HAFASBACKEND_H

#include "abstractbackend.h"

#include <KPublicTransport/Line>

#include <unordered_map>

namespace KPublicTransport {

/** Base class for Hafas-based backends. */
class HafasBackend : public AbstractBackend
{
    Q_GADGET
    Q_PROPERTY(QString endpoint MEMBER m_endpoint)
    Q_PROPERTY(QJsonObject lineModeMap WRITE setLineModeMap)
    /** Identifier type used for stations. Default is backendId(). */
    Q_PROPERTY(QString locationIdentifierType MEMBER m_locationIdentifierType)
    /** Standard location Identifier type ("ibnr" or "uic"), if supported by the backend. */
    Q_PROPERTY(QString standardLocationIdentifierType MEMBER m_standardLocationIdentifierType)

protected:
    QString locationIdentifierType() const;
    QString standardLocationIdentifierType() const;
    QString locationIdentifier(const Location &loc) const;

    QString m_endpoint;
    std::unordered_map<int, Line::Mode> m_lineModeMap;

private:
    void setLineModeMap(const QJsonObject &obj);
    QString m_locationIdentifierType;
    QString m_standardLocationIdentifierType;
};

}

#endif // KPUBLICTRANSPORT_HAFASBACKEND_H

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

#include "efaparser.h"

#include <KPublicTransport/Location>

#include <QDebug>
#include <QXmlStreamReader>

using namespace KPublicTransport;

void EfaParser::setLocationIdentifierType(const QString& locationIdentifierType)
{
    m_locationIdentifierType = locationIdentifierType;
}

std::vector<Location> EfaParser::parseStopFinderResponse(const QByteArray &data) const
{
    //qDebug().noquote() << data;
    std::vector<Location> res;
    QXmlStreamReader reader(data);
    while (!reader.atEnd()) {
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            reader.readNext();
            continue;
        }

        if (reader.name() == QLatin1String("odvNameElem") && reader.attributes().hasAttribute(QLatin1String("stateless"))) {
            Location loc;
            loc.setLatitude(reader.attributes().value(QLatin1String("y")).toDouble());
            loc.setLongitude(reader.attributes().value(QLatin1String("x")).toDouble());
            loc.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("stateless")).toString());
            loc.setName(reader.readElementText(QXmlStreamReader::SkipChildElements));
            res.push_back(loc);
            // TODO anything to be done with itdOdvAssignedStops?
        } else {
            reader.readNext();
        }
    }
    return res;
}

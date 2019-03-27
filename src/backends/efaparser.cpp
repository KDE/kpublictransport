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

#include <KPublicTransport/Departure>
#include <KPublicTransport/Location>

#include <QDateTime>
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

static QDateTime parseDmDateTime(QXmlStreamReader &reader)
{
    QDateTime dt;
    while (!reader.atEnd()) {
        reader.readNext();
        const auto token = reader.tokenType();
        if (token == QXmlStreamReader::EndElement) {
            break;
        }
        if (token != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("itdDate")) {
            QDate d(
                reader.attributes().value(QLatin1String("year")).toInt(),
                reader.attributes().value(QLatin1String("month")).toInt(),
                reader.attributes().value(QLatin1String("day")).toInt());
            dt.setDate(d);
            reader.skipCurrentElement();
        } else if (reader.name() == QLatin1String("itdTime")) {
            QTime t(
                reader.attributes().value(QLatin1String("hour")).toInt(),
                reader.attributes().value(QLatin1String("minute")).toInt(), 0);
            dt.setTime(t);
            reader.skipCurrentElement();
        } else {
            reader.skipCurrentElement();
        }
    }

    return dt;
}

static Departure parseDmDeparture(QXmlStreamReader &reader)
{
    Departure dep;
    dep.setScheduledPlatform(reader.attributes().value(QLatin1String("platformName")).toString());

    while (!reader.atEnd()) {
        reader.readNext();
        const auto token = reader.tokenType();
        if (token == QXmlStreamReader::EndElement) {
            break;
        }
        if (token != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("itdServingLine")) {
            Line line;
            line.setName(reader.attributes().value(QLatin1String("number")).toString());
            Route route;
            route.setDirection(reader.attributes().value(QLatin1String("direction")).toString());
            route.setLine(line);
            dep.setRoute(route);
            reader.skipCurrentElement();
        } else if (reader.name() == QLatin1String("itdDateTime")) {
            dep.setScheduledDepartureTime(parseDmDateTime(reader));
        } else {
            reader.skipCurrentElement();
        }
    }

    return dep;
}

std::vector<Departure> EfaParser::parseDmResponse(const QByteArray &data) const
{
    //qDebug().noquote() << data;
    std::vector<Departure> res;
    QXmlStreamReader reader(data);
    while (!reader.atEnd()) {
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            reader.readNext();
            continue;
        }

        if (reader.name() == QLatin1String("itdDeparture")) {
            res.push_back(parseDmDeparture(reader));
        } else {
            reader.readNext();
        }
    }

    return res;
}

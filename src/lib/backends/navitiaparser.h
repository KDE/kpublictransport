/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_NAVITIAPARSER_H
#define KPUBLICTRANSPORT_NAVITIAPARSER_H

#include "kpublictransport_export.h"

#include <QJsonArray>
#include <QUrl>

#include <vector>

class QByteArray;
class QString;

namespace KPublicTransport {

class Attribution;
class Departure;
class Journey;
class JourneySection;
class Location;

/** Navitia REST response parser.
 *  @internal exported for unit tests only
 */
class KPUBLICTRANSPORT_EXPORT NavitiaParser
{
public:
    explicit NavitiaParser();
    ~NavitiaParser();

    std::vector<Journey> parseJourneys(const QByteArray &data);
    std::vector<Departure> parseDepartures(const QByteArray &data);
    std::vector<Location> parsePlacesNearby(const QByteArray &data);
    std::vector<Location> parsePlaces(const QByteArray &data);

    static QString parseErrorMessage(const QByteArray &data);

    QUrl nextLink;
    QUrl prevLink;

    std::vector<Attribution> attributions;

private:
    void parseLinks(const QJsonArray &links);
    void parseAttributions(const QJsonArray &feeds);
    QJsonObject findDisruption(const QString &id) const;
    JourneySection parseJourneySection(const QJsonObject &obj) const;
    Journey parseJourney(const QJsonObject &obj) const;

    QJsonArray m_disruptions;
};

}

#endif // KPUBLICTRANSPORT_NAVITIAPARSER_H

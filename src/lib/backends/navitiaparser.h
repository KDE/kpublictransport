/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
class Journey;
class JourneySection;
class Location;
class Stopover;

/** Navitia REST response parser.
 *  @internal exported for unit tests only
 */
class KPUBLICTRANSPORT_EXPORT NavitiaParser
{
public:
    explicit NavitiaParser();
    ~NavitiaParser();

    std::vector<Journey> parseJourneys(const QByteArray &data);
    std::vector<Stopover> parseDepartures(const QByteArray &data);
    std::vector<Location> parsePlacesNearby(const QByteArray &data);
    std::vector<Location> parsePlaces(const QByteArray &data);

    static QString parseErrorMessage(const QByteArray &data);

    QUrl nextLink;
    QUrl prevLink;

    std::vector<Attribution> attributions;

private:
    void parseLinks(const QJsonArray &links);
    void parseAttributions(const QJsonArray &feeds);
    template <typename T> void parseDisruptionLink(T &element, const QJsonObject &link) const;
    QJsonObject findDisruption(const QString &id) const;
    JourneySection parseJourneySection(const QJsonObject &obj) const;
    Journey parseJourney(const QJsonObject &obj) const;
    Stopover parseDeparture(const QJsonObject &obj) const;

    QJsonArray m_disruptions;
};

}

#endif // KPUBLICTRANSPORT_NAVITIAPARSER_H

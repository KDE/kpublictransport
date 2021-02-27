/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_IVVASSPARSER_H
#define KPUBLICTRANSPORT_IVVASSPARSER_H

#include <QString>

#include <vector>

class QByteArray;
class QJsonObject;

namespace KPublicTransport {

class Location;
class Journey;
class Stopover;

/** Parser for IVV ASS responses. */
class IvvAssParser
{
public:
    std::vector<Location> parseLocations(const QByteArray &data);
    std::vector<Stopover> parseStopovers(const QByteArray &data);
    std::vector<Journey> parseJourneys(const QByteArray &data);

    QString errorMessage;

private:
    bool parseError(const QJsonObject &top);
};

}

#endif // KPUBLICTRANSPORT_IVVASSPARSER_H

/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_IVVASSPARSER_H
#define KPUBLICTRANSPORT_IVVASSPARSER_H

#include <vector>

class QByteArray;

namespace KPublicTransport {

class Location;
class Journey;
class Stopover;

/** Parser for IVV ASS responses. */
class IvvAssParser
{
public:
    static std::vector<Location> parseLocations(const QByteArray &data);
    static std::vector<Stopover> parseStopovers(const QByteArray &data);
    static std::vector<Journey> parseJourneys(const QByteArray &data);
};

}

#endif // KPUBLICTRANSPORT_IVVASSPARSER_H

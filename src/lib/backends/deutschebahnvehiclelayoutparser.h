/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DEUTSCHEBAHNVEHICLELAYOUTPARSER_H
#define KPUBLICTRANSPORT_DEUTSCHEBAHNVEHICLELAYOUTPARSER_H

#include <KPublicTransport/Platform>
#include <KPublicTransport/Vehicle>
#include <KPublicTransport/Reply>
#include <KPublicTransport/Stopover>

class QByteArray;

namespace KPublicTransport {

/** Parser for vehicle layout responses from Deutsche Bahn. */
class DeutscheBahnVehicleLayoutParser
{
public:
    bool parse(const QByteArray &data);

    Stopover stopover;
    Reply::Error error = Reply::NoError;
    QString errorMessage;

private:
    void parseVehicleSection(Vehicle &vehicle, const QJsonObject &obj);
    void parsePlatformSection(Platform &platform, const QJsonObject &obj);
    void fillMissingPositions(Vehicle &vehicle, Platform &platform);
};

}

#endif // KPUBLICTRANSPORT_DEUTSCHEBAHNVEHICLELAYOUTPARSER_H

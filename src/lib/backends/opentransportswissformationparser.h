/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_OPENTRANSPORTSWISSFORMATIONPARSER_H
#define KPUBLICTRANSPORT_OPENTRANSPORTSWISSFORMATIONPARSER_H

#include <KPublicTransport/Platform>
#include <KPublicTransport/Vehicle>
#include <KPublicTransport/Stopover>

class QByteArray;

namespace KPublicTransport {

/** Parser for vehicle layout responses from opentransportdata.swiss. */
class OpenTransportSwissFormationParser
{
public:
    [[nodiscard]] bool parse(const QByteArray &data, const QString &identifierType);

    Stopover stopover;
    QString errorMsg;
};

}

#endif

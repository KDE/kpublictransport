/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_EFACOMPACTPARSER_H
#define KPUBLICTRANSPORT_EFACOMPACTPARSER_H

#include "efaparser.h"

namespace KPublicTransport {

class ScopedXmlStreamReader;

/** Parser for compact XML responses from EFA services.
 * @internal just exported for unit tests
 */
class KPUBLICTRANSPORT_EXPORT EfaCompactParser : public EfaParser
{
public:
    std::vector<Location> parseStopFinderResponse(const QByteArray &data) const override;
    std::vector<Stopover> parseDmResponse(const QByteArray &data) const override;
    std::vector<Journey> parseTripResponse(const QByteArray &data) const override;

private:
    Location parseCompactSf(ScopedXmlStreamReader &&reader) const;
    Stopover parseCompactDp(ScopedXmlStreamReader &&reader) const;
    Journey parseCompactTp(ScopedXmlStreamReader &&reader) const;
    JourneySection parseTripSection(ScopedXmlStreamReader &&reader) const;
    void parseTripSectionHalf(ScopedXmlStreamReader &&reader, JourneySection &section) const;
    QStringList parseNotes(ScopedXmlStreamReader &&reader) const;
};

}

#endif // KPUBLICTRANSPORT_EFACOMPACTPARSER_H

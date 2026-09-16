/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JOURNEY_P_H
#define KPUBLICTRANSPORT_JOURNEY_P_H

#include "journey.h"

#include "identifier_p.h"

#include <KPublicTransport/RentalVehicle>
#include <KPublicTransport/Stopover>

#include <QUrl>

namespace KPublicTransport {

class JourneySectionPrivate : public QSharedData
{
public:
    [[nodiscard]] bool isValidIndex(qsizetype idx) const;

    JourneySection::Mode mode = JourneySection::Invalid;
    Stopover departure;
    Stopover arrival;
    int distance = 0;
    Disruption::Effect disruptionEffect = Disruption::NormalService;
    QStringList notes;
    std::vector<Stopover> intermediateStops;
    int co2Emission = -1;
    RentalVehicle rentalVehicle;
    Path path;
    IndividualTransport individualTransport;
    IdentifierSet ids;
    QUrl bookingUrl;
};

class JourneyPrivate : public QSharedData
{
public:
    [[nodiscard]] static const JourneyPrivate* get(const Journey &q) { return q.d.constData(); }

    std::vector<JourneySection> sections;
    QUrl bookingUrl;
    IdentifierSet ids;
};

}

#endif

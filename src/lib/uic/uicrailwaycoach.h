/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_UICRAILWAYCOACH_H
#define KPUBLICTRANSPORT_UICRAILWAYCOACH_H

#include <KPublicTransport/Vehicle>

namespace KPublicTransport {

/** Methods for parsing UIC railway coach numbers and classification codes.
 *  @see https://en.wikipedia.org/wiki/UIC_classification_of_railway_coaches
 *  @see https://en.wikipedia.org/wiki/UIC_wagon_numbers
 */
namespace UicRailwayCoach
{

/** Returns the UIC country code from @p coachNumber. */
QStringView countryCode(QStringView coachNumber);

/** Determine the coach class(es) from a UIC @p coachNumber and/or @p coachClassification.
 *  Either one of the arguments can be empty, but the most reliable result is returned with both present.
 */
VehicleSection::Classes coachClass(QStringView coachNumber, QStringView coachClassification);

/** Determine the number of decks from a UIC @p coachNumber and/or @p coachClassification.
 *  Either one of the arguments can be empty, but the most reliable result is returned with both present.
 */
int deckCount(QStringView coachNumber, QStringView coachClassification);

/** Determine coach features from a UIC @p coachNumber and/or @p coachClassification.
 *  Either one of the arguments can be empty, but the most reliable result is returned with both present.
 */
VehicleSection::Features features(QStringView coachNumber, QStringView coachClassification);

/** Determine the vehicle type from a UIC @p coachNumber and/or @p coachClassification.
 *  Either one of the arguments can be empty, but the most reliable result is returned with both present.
 */
VehicleSection::Type type(QStringView coachNumber, QStringView coachClassification);

}

}

#endif // KPUBLICTRANSPORT_UICRAILWAYCOACH_H

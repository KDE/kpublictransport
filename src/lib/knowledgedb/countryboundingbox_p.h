/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_COUNTRYBOUNDINGBOX_P_H
#define KPUBLICTRANSPORT_COUNTRYBOUNDINGBOX_P_H

#include <cstdint>

class QRectF;
class QStringView;

namespace KPublicTransport {

struct CountryBoundingBoxData {
    const char code[2];
    int16_t minLon;
    int16_t minLat;
    int16_t maxLon;
    int16_t maxLat;
};

/** Look up bounding box for country with the given ISO 3166-1 alpha 2 code. */
[[nodiscard]] QRectF boundingBoxForCountry(QStringView countryCode);

}

#endif

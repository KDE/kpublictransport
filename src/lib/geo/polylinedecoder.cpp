/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "polylinedecoder_p.h"

using namespace KPublicTransport;

int32_t PolylineDecoderBase::readNextIntNonDifferential()
{
    int32_t result = 0;
    int shift = 0;
    char c = 0;
    do {
        if (canReadMore()) {
            c = *m_it;
            ++m_it;
            c -= 63;
            result |= (c & 0b11111) << shift;
            shift += 5;
        } else {
            return std::numeric_limits<int32_t>::max();
        }
    } while (c >= 0x20);

    if (result & 1) {
        result = ~result;
    }
    result >>= 1;
    return result;
}

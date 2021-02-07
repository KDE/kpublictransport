/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_POLYLINEDECODER_P_H
#define KPUBLICTRANSPORT_POLYLINEDECODER_P_H

#include "kpublictransport_export.h"

#include <QPolygonF>

#include <array>
#include <cstdint>
#include <limits>

namespace KPublicTransport {

///@cond internal
class PolylineDecoderBase {
protected:
    explicit inline PolylineDecoderBase(const char *const begin, const char *const end)
        : m_it(begin)
        , m_end(end)
    {}

    inline bool canReadMore() const
    {
        return m_it != m_end && *m_it;
    }

    KPUBLICTRANSPORT_EXPORT int32_t readNextIntNonDifferential();

    const char *m_it = nullptr;
    const char *m_end = nullptr;
};
///@endcond

/**
 * Decoder for Google's Polyline format.
 * @see https://developers.google.com/maps/documentation/utilities/polylinealgorithm
 */
template <int Dim = 2, bool Differential = true>
class PolylineDecoder : PolylineDecoderBase
{
public:
    explicit inline PolylineDecoder(const char *const begin, const char *const end)
        : PolylineDecoderBase(begin, end)
    {
        m_accu.fill(0);
    }

    template <std::size_t N>
    explicit inline PolylineDecoder(const char (&data)[N])
        : PolylineDecoder(std::begin(data), std::end(data)) {}

    ~PolylineDecoder() = default;

    constexpr inline int dimensions() const { return Dim; }

    using PolylineDecoderBase::canReadMore;

    inline int32_t readNextInt()
    {
        auto n = readNextIntNonDifferential();
        if constexpr(Differential) {
            n += m_accu[m_nextDim];
            m_accu[m_nextDim++] = n;
            m_nextDim %= Dim;
        }
        return n;
    }

    inline double readNextDouble()
    {
        return readNextInt() / 100000.0;
    }

    inline QPolygonF readPolygon()
    {
        static_assert(Dim == 2, "Polygons require a two-dimensional polyline");
        QPolygonF p;
        while (canReadMore()) {
            const auto lat = readNextDouble();
            const auto lon = readNextDouble();
            p.push_back({lon, lat});
        }
        return p;
    }

private:
    int m_nextDim = 0;
    std::array<int32_t, Dim> m_accu;
};

}

#endif // KPUBLICTRANSPORT_POLYLINEDECODER_P_H

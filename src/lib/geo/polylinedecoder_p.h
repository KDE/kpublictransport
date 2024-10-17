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
#include <cstring>

namespace KPublicTransport {

///@cond internal
class PolylineDecoderBase {
protected:
    explicit inline PolylineDecoderBase(const char *const begin, const char *const end)
        : m_it(begin)
        , m_end(end)
    {}

    [[nodiscard]] inline bool canReadMore() const
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
template <int Dim = 2, int Precision = 5, bool Differential = true>
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

    explicit inline PolylineDecoder(const char *data)
        : PolylineDecoder(data, data + std::strlen(data)) {}

    ~PolylineDecoder() = default;

    [[nodiscard]] constexpr inline int dimensions() const { return Dim; }
    [[nodiscard]] constexpr inline int precision() const { return Precision; }

    using PolylineDecoderBase::canReadMore;

    [[nodiscard]] inline int32_t readNextInt()
    {
        auto n = readNextIntNonDifferential();
        if constexpr(Differential) {
            n += m_accu[m_nextDim];
            m_accu[m_nextDim++] = n;
            m_nextDim %= Dim;
        }
        return n;
    }

    [[nodiscard]] inline double readNextDouble()
    {
        return readNextInt() / scaleFactor();
    }

    inline void readPolygon(QPolygonF &polygon, int maxEntries = -1)
    {
        static_assert(Dim == 2, "Polygons require a two-dimensional polyline");
        if (maxEntries > 0) {
            polygon.reserve(polygon.size() + maxEntries);
        }
        while (canReadMore() && maxEntries != 0) {
            const auto lat = readNextDouble();
            const auto lon = readNextDouble();
            polygon.push_back({lon, lat});
            --maxEntries;
        }
    }

private:
    // TODO constexpr in C++26
    [[nodiscard]] inline double scaleFactor() const { return std::pow(10.0, precision()); };

    int m_nextDim = 0;
    std::array<int32_t, Dim> m_accu;
};

}

#endif // KPUBLICTRANSPORT_POLYLINEDECODER_P_H

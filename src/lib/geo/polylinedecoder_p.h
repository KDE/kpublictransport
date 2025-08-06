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
    explicit PolylineDecoderBase(const char *const begin, const char *const end, int precision)
        : m_it(begin)
        , m_end(end)
        , m_precision(precision)
    {}

    [[nodiscard]] bool canReadMore() const
    {
        return m_it != m_end && *m_it;
    }

    [[nodiscard]] int precision() const { return m_precision; }

    KPUBLICTRANSPORT_EXPORT int32_t readNextIntNonDifferential();

    const char *m_it = nullptr;
    const char *m_end = nullptr;
    int m_precision = 5;
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
    explicit PolylineDecoder(const char *const begin, const char *const end, int precision = 5)
        : PolylineDecoderBase(begin, end, precision)
    {
        m_accu.fill(0);
    }

    template <std::size_t N>
    explicit PolylineDecoder(const char (&data)[N], int precision = 5)
        : PolylineDecoder(std::begin(data), std::end(data), precision) {}

    explicit PolylineDecoder(const char *data, int precision = 5)
        : PolylineDecoder(data, data + std::strlen(data), precision) {}

    ~PolylineDecoder() = default;

    [[nodiscard]] constexpr int dimensions() const { return Dim; }

    using PolylineDecoderBase::canReadMore;

    [[nodiscard]] int32_t readNextInt()
    {
        auto n = readNextIntNonDifferential();
        if constexpr(Differential) {
            n += m_accu[m_nextDim];
            m_accu[m_nextDim++] = n;
            m_nextDim %= Dim;
        }
        return n;
    }

    [[nodiscard]] double readNextDouble()
    {
        return readNextInt() / scaleFactor();
    }

    void readPolygon(QPolygonF &polygon, int maxEntries = -1)
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
    [[nodiscard]] double scaleFactor() const { return std::pow(10.0, precision()); };

    int m_nextDim = 0;
    std::array<int32_t, Dim> m_accu;
};

}

#endif // KPUBLICTRANSPORT_POLYLINEDECODER_P_H

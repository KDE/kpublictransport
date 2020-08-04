/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_INTERNAL_H
#define OSM_INTERNAL_H

#include <cstdint>

namespace OSM {

namespace Internal {
/** Pointer with the lower bits used for compact flag storage. */
template <typename T> class TaggedPointer
{
public:
    explicit inline constexpr TaggedPointer() = default;
    explicit inline constexpr TaggedPointer(T *ptr, uint8_t tag)
        : m_data(reinterpret_cast<std::uintptr_t>(ptr) | (tag & TagMask))
    {}

    constexpr inline T* get() const { return reinterpret_cast<T*>(m_data & ~TagMask); }
    constexpr inline void set(T *data) { m_data = (m_data & TagMask) | (reinterpret_cast<std::uintptr_t>(data) & ~TagMask); }
    constexpr inline uint8_t tag() const { return m_data & TagMask; }
    constexpr inline void setTag(uint8_t tag) { m_data = (tag & TagMask) | (m_data & ~TagMask); }
    constexpr inline operator bool() const { return (m_data & ~TagMask); }
    constexpr inline bool operator==(TaggedPointer<T> other) const { return m_data == other.m_data; }

private:
    enum { TagMask = 0x3 };
    std::uintptr_t m_data = 0;
};

}
}

#endif

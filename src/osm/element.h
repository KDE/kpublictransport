/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef OSM_ELEMENT_H
#define OSM_ELEMENT_H

#include "datatypes.h"

#include <cstdint>

namespace OSM {

namespace Internal {
template <typename T> class TaggedPointer
{
public:
    explicit inline TaggedPointer(T *ptr, uint8_t tag)
        : m_data(reinterpret_cast<std::uintptr_t>(ptr) | (tag & TagMask))
    {}

    inline T* get() const { return reinterpret_cast<T*>(m_data & ~TagMask); }
    inline uint8_t tag() const { return m_data & TagMask; }
    inline operator bool() const { return (m_data & ~TagMask); }

private:
    enum { TagMask = 0x3 };
    std::uintptr_t m_data;
};
}

/** A reference to any of OSM::Node/OSM::Way/OSM::Relation.
 *  Lifetime of the referenced object needs to extend beyond the lifetime of this.
 */
class Element
{
public:
    inline Element(const Node *node) : m_elem(node, static_cast<uint8_t>(Type::Node)) {}
    inline Element(const Way *way) : m_elem(way, static_cast<uint8_t>(Type::Way)) {}
    inline Element(const Relation *relation) : m_elem(relation, static_cast<uint8_t>(Type::Relation)) {}

    inline Type type() const { return static_cast<Type>(m_elem.tag()); }
    inline const Node* node() const { return static_cast<const Node*>(m_elem.get()); }
    inline const Way* way() const { return static_cast<const Way*>(m_elem.get()); }
    inline const Relation* relation() const { return static_cast<const Relation*>(m_elem.get()); }

    Coordinate center() const;
    BoundingBox boundingBox() const;
    QString tagValue(const QLatin1String &key) const;
    QString url() const;

    /** Returns all nodes belonging to the outer path of this element.
     *  In the simplest case that's a single closed polygon, but it can also be a sequence of multiple
     *  closed loop polygons, or a polyline.
     */
    std::vector<const Node*> outerPath(const DataSet &dataSet) const;

private:
    Internal::TaggedPointer<const void> m_elem;
};

template <typename Func>
inline void for_each(const DataSet &dataSet, Func func)
{
    for (const auto &rel : dataSet.relations) {
        func(Element(&rel));
    }
    for (const auto &way : dataSet.ways) {
        func(Element(&way));
    }
    for (const auto &node : dataSet.nodes) {
        func(Element(&node));
    }
}

}

#endif // OSM_ELEMENT_H

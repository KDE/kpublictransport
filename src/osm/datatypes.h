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

#ifndef OSM_DATATYPES_H
#define OSM_DATATYPES_H

#include <QString>

#include <cstdint>
#include <vector>

namespace OSM {

/** OSM element identifier. */
typedef int64_t Id;

/** Coordinate, stored as 1e7 * degree to avoid floating point precision issues. */
class Coordinate {
public:
    Coordinate() = default;
    explicit constexpr Coordinate(double lat, double lon)
        : latitude(lat * 10'000'000)
        , longitude(lon * 10'000'000)
    {}

    int32_t latitude = 0;
    int32_t longitude = 0;
};

/** Bounding box, ie. a pair of coordinates. */
class BoundingBox {
public:
    Coordinate min;
    Coordinate max;
};

/** An OSM element tag. */
class Tag {
public:
    QString key;
    QString value;
};

/** An OSM node. */
class Node {
public:
    constexpr inline bool operator<(const Node &other) const { return id < other.id; }

    Id id;
    Coordinate coordinate;
    std::vector<Tag> tags;
};

/** An OSM way. */
class Way {
public:
    constexpr inline bool operator<(const Way &other) const { return id < other.id; }

    Id id;
    std::vector<Id> nodes;
    std::vector<Tag> tags;
};

/** A member in a relation. */
// TODO this has 7 byte padding, can we make this more efficient?
class Member {
public:
    Id id;
    QString role;
    enum class Type : uint8_t {
        Node,
        Way,
        Relation
    } type;
};

/** An OSM relation. */
class Relation {
public:
    constexpr inline bool operator<(const Relation &other) const { return id < other.id; }

    Id id;
    BoundingBox bbox;
    std::vector<Member> members;
    std::vector<Tag> tags;
};

/** A set of nodes, ways and relations. */
class DataSet {
public:
    void addNode(Node &&node);
    void addRelation(Relation &&rel);

    std::vector<Node> nodes;
    std::vector<Way> ways;
    std::vector<Relation> relations;
};

/** Returns the tag value for @p key of @p elem. */
template <typename Elem>
inline QString tagValue(const Elem& elem, const QLatin1String &key)
{
    // TODO sort tag list?
    const auto it = std::find_if(elem.tags.begin(), elem.tags.end(), [key](const auto &t) { return t.key == key; });
    if (it != elem.tags.end()) {
        return (*it).value;
    }
    return {};
}

template <typename Elem>
inline bool operator<(const Elem &elem, Id id)
{
    return elem.id < id;
}

}

#endif // OSM_DATATYPES_H

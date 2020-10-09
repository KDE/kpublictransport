/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_ELEMENT_H
#define OSM_ELEMENT_H

#include "datatypes.h"
#include "internal.h"

#include <cstdint>

namespace OSM {

/** A reference to any of OSM::Node/OSM::Way/OSM::Relation.
 *  Lifetime of the referenced object needs to extend beyond the lifetime of this.
 */
class Element
{
public:
    inline constexpr Element() : m_elem(nullptr, static_cast<uint8_t>(Type::Null)) {}
    inline Element(const Node *node) : m_elem(node, static_cast<uint8_t>(Type::Node)) {}
    inline Element(const Way *way) : m_elem(way, static_cast<uint8_t>(Type::Way)) {}
    inline Element(const Relation *relation) : m_elem(relation, static_cast<uint8_t>(Type::Relation)) {}

    inline bool operator==(Element other) const { return m_elem == other.m_elem; }
    inline bool operator!=(Element other) const { return m_elem != other.m_elem; }
    inline bool operator<(Element other) const { return m_elem < other.m_elem; }
    explicit inline operator bool() const { return type() != OSM::Type::Null; }

    inline Type type() const { return static_cast<Type>(m_elem.tag()); }
    inline const Node* node() const { return static_cast<const Node*>(m_elem.get()); }
    inline const Way* way() const { return static_cast<const Way*>(m_elem.get()); }
    inline const Relation* relation() const { return static_cast<const Relation*>(m_elem.get()); }
    Id id() const;

    Coordinate center() const;
    BoundingBox boundingBox() const;
    QByteArray tagValue(TagKey key) const;
    QByteArray tagValue(const char *keyName) const;
    QByteArray tagValue(const char *keyName, const QLocale &locale) const;
    /** Returns the value of the first non-empty tag. */
    template <typename ...Args> QByteArray tagValue(const char *keyName, Args... args) const;
    template <typename ...Args> QByteArray tagValue(const char *keyName, Args... args, const QLocale &locale) const;
    /** Returns whether or not this element has any tags set. */
    inline bool hasTags() const { return std::distance(tagsBegin(), tagsEnd()) > 0; }

    std::vector<Tag>::const_iterator tagsBegin() const;
    std::vector<Tag>::const_iterator tagsEnd() const;
    QString url() const;

    /** Returns all nodes belonging to the outer path of this element.
     *  In the simplest case that's a single closed polygon, but it can also be a sequence of multiple
     *  closed loop polygons, or a polyline.
     */
    std::vector<const Node*> outerPath(const DataSet &dataSet) const;

    /** Recompute the bounding box of this element.
     *  We usually assume those to be provided by Overpass/osmconvert, but there seem to be cases where those
     *  aren't reliable.
     */
    void recomputeBoundingBox(const DataSet &dataSet);

private:
    Internal::TaggedPointer<const void> m_elem;
};

template <typename ...Args>
QByteArray Element::tagValue(const char *keyName, Args... args) const
{
    const auto v = tagValue(keyName);
    if (!v.isEmpty()) {
        return v;
    }
    return tagValue(args...);
}

template <typename ...Args>
QByteArray Element::tagValue(const char *keyName, Args... args, const QLocale &locale) const
{
    const auto v = tagValue(keyName, locale);
    if (!v.isEmpty()) {
        return v;
    }
    return tagValue(args..., locale);
}


/** A std::unique_ptr-like object for OSM element types. */
class UniqueElement
{
public:
    explicit inline UniqueElement() = default;
    explicit inline UniqueElement(Node *node) : m_element(node) {}
    explicit inline UniqueElement(Way *way) : m_element(way) {}
    explicit inline UniqueElement(Relation *rel) : m_element(rel) {}

    UniqueElement(const UniqueElement&) = delete;
    inline UniqueElement(UniqueElement &&other) {
        m_element = other.m_element;
        other.m_element = {};
    }

    ~UniqueElement();

    UniqueElement& operator=(const UniqueElement&) = delete;
    UniqueElement& operator=(UniqueElement &&other) {
        m_element = other.m_element;
        other.m_element = {};
        return *this;
    }

    constexpr inline Element element() const { return m_element; }
    constexpr inline operator Element() const { return m_element; }

    void setTagValue(TagKey key, const QByteArray &value);

private:
    Element m_element;
};


/** Utility function similar to SQL COALESCE for OSM::Element, ie. this returns the first non-null element passed as argument. */
constexpr Element coalesce(Element e) { return e; }
template <typename ...Args>
constexpr Element coalesce(Element e, Args... args) { return e ? e : coalesce(args...); }

enum ForeachFlag : uint8_t {
    IncludeRelations = 1,
    IncludeWays = 2,
    IncludeNodes = 4,
    IterateAll = IncludeRelations | IncludeWays | IncludeNodes,
};

template <typename Func>
inline void for_each(const DataSet &dataSet, Func func, uint8_t flags = IterateAll)
{
    if (flags & IncludeRelations) {
        for (const auto &rel : dataSet.relations) {
            func(Element(&rel));
        }
    }
    if (flags & IncludeWays) {
        for (const auto &way : dataSet.ways) {
            func(Element(&way));
        }
    }
    if (flags & IncludeNodes) {
        for (const auto &node : dataSet.nodes) {
            func(Element(&node));
        }
    }
}

template <typename Func>
inline void for_each_node(const DataSet &dataSet, const Way &way, Func func)
{
    for (auto nodeId : way.nodes) {
        if (auto node = dataSet.node(nodeId)) {
            func(*node);
        }
    }
}

template <typename Func>
inline void for_each_member(const DataSet &dataSet, const Relation &rel, Func func)
{
    for (const auto &mem : rel.members) {
        switch (mem.type()) {
            case Type::Null:
                break;
            case Type::Node:
                if (auto node = dataSet.node(mem.id)) {
                    func(Element(node));
                }
                break;
            case Type::Way:
                if (auto way = dataSet.way(mem.id)) {
                    func(Element(way));
                }
                break;
            case Type::Relation:
                if (auto rel = dataSet.relation(mem.id)) {
                    func(Element(rel));
                }
                break;
        }
    }
}

}

Q_DECLARE_METATYPE(OSM::Element)

#endif // OSM_ELEMENT_H

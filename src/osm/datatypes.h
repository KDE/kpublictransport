/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_DATATYPES_H
#define OSM_DATATYPES_H

#include "internal.h"

#include <QByteArray>
#include <QDebug>
#include <QLocale>
#include <QString>

#include <cstdint>
#include <cstring>
#include <vector>

/** Low-level types and functions to work with raw OSM data as efficiently as possible. */
namespace OSM {

class DataSet;
class Member;

/** OSM element identifier. */
using Id = int64_t;

/** Coordinate, stored as 1e7 * degree to avoid floating point precision issues,
 *  and offset to unsigned values to make the z-order curve work.
 *  Can be in an invalid state with coordinates out of range, see isValid().
 *  @see https://en.wikipedia.org/wiki/Z-order_curve for the z-order curve stuff
 */
class Coordinate {
public:
    Coordinate() = default;
    explicit constexpr Coordinate(double lat, double lon)
        : latitude((lat + 90.0) * 10'000'000)
        , longitude((lon + 180.0) * 10'000'000)
    {}
    explicit constexpr Coordinate(uint32_t lat, uint32_t lon)
        : latitude(lat)
        , longitude(lon)
    {}

    /** Create a coordinate from a z-order curve index. */
    explicit constexpr Coordinate(uint64_t z)
        : latitude(0)
        , longitude(0)
    {
        for (int i = 0; i < 32; ++i) {
            latitude += (z & (1ull << (i * 2))) >> i;
            longitude += (z & (1ull << (1 + i * 2))) >> (i + 1);
        }
    }

    [[nodiscard]] constexpr inline bool isValid() const
    {
        return latitude != std::numeric_limits<uint32_t>::max() && longitude != std::numeric_limits<uint32_t>::max();
    }
    [[nodiscard]] constexpr inline bool operator==(Coordinate other) const
    {
        return latitude == other.latitude && longitude == other.longitude;
    }

    /** Z-order curve value for this coordinate. */
    [[nodiscard]] constexpr inline uint64_t z() const
    {
        uint64_t z = 0;
        for (int i = 0; i < 32; ++i) {
            z += ((uint64_t)latitude & (1 << i)) << i;
            z += ((uint64_t)longitude & (1 << i)) << (i + 1);
        }
        return z;
    }

    [[nodiscard]] constexpr inline double latF() const
    {
        return (latitude / 10'000'000.0) - 90.0;
    }
    [[nodiscard]] constexpr inline double lonF() const
    {
        return (longitude / 10'000'000.0) - 180.0;
    }

    uint32_t latitude = std::numeric_limits<uint32_t>::max();
    uint32_t longitude = std::numeric_limits<uint32_t>::max();
};


/** Bounding box, ie. a pair of coordinates. */
class BoundingBox {
public:
    constexpr BoundingBox() = default;
    constexpr inline BoundingBox(Coordinate c1, Coordinate c2)
        : min(c1)
        , max(c2)
    {}
    [[nodiscard]] constexpr inline bool isValid() const
    {
        return min.isValid() && max.isValid();
    }
    [[nodiscard]] constexpr inline bool operator==(BoundingBox other) const
    {
        return min == other.min && max == other.max;
    }

    [[nodiscard]] constexpr inline uint32_t width() const
    {
        return max.longitude - min.longitude;
    }
    [[nodiscard]] constexpr inline uint32_t height() const
    {
        return max.latitude - min.latitude;
    }

    [[nodiscard]] constexpr inline double widthF() const
    {
        return width() / 10'000'000.0;
    }
    [[nodiscard]] constexpr inline double heightF() const
    {
        return height() / 10'000'000.0;
    }

    [[nodiscard]] constexpr inline Coordinate center() const
    {
        return Coordinate(min.latitude + height() / 2, min.longitude + width() / 2);
    }

    Coordinate min;
    Coordinate max;
};

[[nodiscard]] constexpr inline BoundingBox unite(BoundingBox bbox1, BoundingBox bbox2)
{
    if (!bbox1.isValid()) {
        return bbox2;
    }
    if (!bbox2.isValid()) {
        return bbox1;
    }
    BoundingBox ret;
    ret.min.latitude = std::min(bbox1.min.latitude, bbox2.min.latitude);
    ret.min.longitude = std::min(bbox1.min.longitude, bbox2.min.longitude);
    ret.max.latitude = std::max(bbox1.max.latitude, bbox2.max.latitude);
    ret.max.longitude = std::max(bbox1.max.longitude, bbox2.max.longitude);
    return ret;
}

[[nodiscard]] constexpr inline bool intersects(BoundingBox bbox1, BoundingBox bbox2)
{
    return !(bbox2.min.latitude > bbox1.max.latitude || bbox2.max.latitude < bbox1.min.latitude
        || bbox2.min.longitude > bbox1.max.longitude || bbox2.max.longitude < bbox1.min.longitude);
}

[[nodiscard]] constexpr inline bool contains(BoundingBox bbox, Coordinate coord)
{
    return bbox.min.latitude <= coord.latitude && bbox.max.latitude >= coord.latitude
        && bbox.min.longitude <= coord.longitude && bbox.max.longitude >= coord.longitude;
}

[[nodiscard]] constexpr inline uint32_t latitudeDistance(BoundingBox bbox1, BoundingBox bbox2)
{
    return bbox1.max.latitude < bbox2.min.latitude ? bbox2.min.latitude - bbox1.max.latitude : bbox1.min.latitude - bbox2.max.latitude;
}

[[nodiscard]] constexpr inline uint32_t longitudeDifference(BoundingBox bbox1, BoundingBox bbox2)
{
    return bbox1.max.longitude < bbox2.min.longitude ? bbox2.min.longitude - bbox1.max.longitude : bbox1.min.longitude - bbox2.max.longitude;
}

/** Base class for unique string keys. */
class StringKey
{
public:
    constexpr inline const char* name() const { return key; }
    constexpr inline bool isNull() const { return !key; }

    // yes, pointer compare is enough here
    inline constexpr bool operator<(StringKey other) const { return key < other.key; }
    inline constexpr bool operator==(StringKey other) const { return key == other.key; }
    inline constexpr bool operator!=(StringKey other) const { return key != other.key; }

protected:
    constexpr inline StringKey() = default;
    explicit constexpr inline StringKey(const char *keyData) : key(keyData) {}

private:
    const char* key = nullptr;
};

/** A key of an OSM tag.
 *  See DataSet::tagKey().
 */
class TagKey : public StringKey
{
public:
    constexpr inline TagKey() = default;
private:
    explicit constexpr inline TagKey(const char *keyData) : StringKey(keyData) {}
    friend class DataSet;
};

/** An OSM element tag. */
class Tag {
public:
    Tag() = default;
    inline Tag(TagKey _key, QByteArray &&_value)
        : key(_key)
        , value(std::move(_value))
    {}
    Tag(const Tag&) = default;
    Tag(Tag &&Tag) noexcept = default;
    Tag& operator=(const Tag &other) = default;
    Tag& operator=(Tag &&other) noexcept = default;

    [[nodiscard]] inline constexpr bool operator<(const Tag &other) const { return key < other.key; }

    TagKey key;
    QByteArray value;
};

[[nodiscard]] inline constexpr bool operator<(const Tag &lhs, TagKey rhs) { return lhs.key < rhs; }
[[nodiscard]] inline constexpr bool operator<(TagKey lhs, const Tag &rhs) { return lhs < rhs.key; }

/** An OSM node. */
class Node {
public:
    explicit Node() = default;
    Node(const Node&) = default;
    Node(Node &&other) noexcept
    {
        *this = std::move(other);
    }
    Node& operator=(const Node &other) = default;
    Node& operator=(Node &&other) noexcept
    {
        id = other.id;
        coordinate = other.coordinate;
        std::swap(tags, other.tags);
        return *this;
    }

    [[nodiscard]] constexpr inline bool operator<(const Node &other) const { return id < other.id; }
    [[nodiscard]] constexpr inline bool operator<(Id other) const { return id < other; };

    [[nodiscard]] QString url() const;

    Id id;
    Coordinate coordinate;
    std::vector<Tag> tags;
};

/** An OSM way. */
class Way {
public:
    explicit Way() = default;
    Way(const Way&) = default;
    Way(Way &&other) noexcept
    {
        *this = std::move(other);
    }
    Way& operator=(const Way &other) = default;
    Way& operator=(Way &&other) noexcept
    {
        id = other.id;
        bbox = other.bbox;
        std::swap(nodes, other.nodes);
        std::swap(tags, other.tags);
        return *this;
    }

    [[nodiscard]] constexpr inline bool operator<(const Way &other) const { return id < other.id; }
    [[nodiscard]] constexpr inline bool operator<(Id other) const { return id < other; };

    [[nodiscard]] bool isClosed() const;

    [[nodiscard]] QString url() const;

    Id id;
    mutable BoundingBox bbox;
    std::vector<Id> nodes;
    std::vector<Tag> tags;
};

/** Element type. */
enum class Type : uint8_t {
    Null,
    Node,
    Way,
    Relation
};

/** A relation role name key.
 *  See DataSet::role().
 */
class Role : public StringKey
{
public:
    constexpr inline Role() = default;
private:
    friend class DataSet;
    friend class Member;
    explicit constexpr inline Role(const char *keyData) : StringKey(keyData) {}
};

/** A member in a relation. */
class Member {
public:
    [[nodiscard]] inline bool operator==(const Member &other) const { return id == other.id && m_roleAndType == other.m_roleAndType; }

    Id id;

    [[nodiscard]] constexpr inline Role role() const
    {
        return Role(m_roleAndType.get());
    }
    constexpr inline void setRole(Role role)
    {
        m_roleAndType.set(role.name());
    }

    [[nodiscard]] constexpr inline Type type() const
    {
        return static_cast<Type>(m_roleAndType.tag());
    }
    constexpr inline void setType(Type type)
    {
        m_roleAndType.setTag(static_cast<uint8_t>(type));
    }

private:
    Internal::TaggedPointer<const char> m_roleAndType;
};

/** An OSM relation. */
class Relation {
public:
    explicit Relation() = default;
    Relation(const Relation&) = default;
    Relation(Relation &&other) noexcept
    {
        *this = std::move(other);
    }
    Relation& operator=(const Relation &other) = default;
    Relation& operator=(Relation &&other) noexcept
    {
        id = other.id;
        bbox = other.bbox;
        std::swap(members, other.members);
        std::swap(tags, other.tags);
        return *this;
    }

    [[nodiscard]] constexpr inline bool operator<(const Relation &other) const { return id < other.id; }
    [[nodiscard]] constexpr inline bool operator<(Id other) const { return id < other; };

    [[nodiscard]] QString url() const;

    Id id;
    mutable BoundingBox bbox;
    std::vector<Member> members;
    std::vector<Tag> tags;
};

/** A set of nodes, ways and relations. */
class DataSet {
public:
    explicit DataSet();
    DataSet(const DataSet&) = delete;
    DataSet(DataSet &&other) noexcept;
    ~DataSet();

    DataSet& operator=(const DataSet&) = delete;
    DataSet& operator=(DataSet &&) noexcept;

    /** Find a node by its id.
     *  @returns @c nullptr if the node doesn't exist.
     */
    [[nodiscard]] const Node* node(Id id) const;

    /** Find a way by its id.
     *  @returns @c nullptr if the way doesn't exist.
     */
    [[nodiscard]] const Way* way(Id id) const;
    [[nodiscard]] Way* way(Id id);

    /** Find a relation by its id.
     *  @returns @c nullptr if the relation doesn't exist.
     */
    [[nodiscard]] const Relation* relation(Id id) const;

    void addNode(Node &&node);
    void addWay(Way &&way);
    void addRelation(Relation &&rel);

    /** Look up a tag key for the given tag name, if it exists.
     *  If no key exists, an empty/invalid/null key is returned.
     *  Use this for tag lookup, not for creating/adding tags.
     */
    [[nodiscard]] TagKey tagKey(const char *keyName) const;

    enum StringMemory { StringIsPersistent, StringIsTransient };
    /** Create a tag key for the given tag name. If none exist yet a new one is created.
     *  Use this for creating tags, not for lookup, prefer tagKey() for that.
     *  @param keyMemOpt specifies whether @p keyName is persisent for the lifetime of this
     *  instance and thus can be used without requiring a copy. If the memory is transient
     *  the string is copied if needed, and released in the DataSet destructor.
     */
    [[nodiscard]] TagKey makeTagKey(const char *keyName, StringMemory keyMemOpt = StringIsTransient);

    /** Looks up a role name key.
     *  @see tagKey()
     */
    [[nodiscard]] Role role(const char *roleName) const;
    /** Creates a role name key.
     *  @see makeTagKey()
     */
    [[nodiscard]] Role makeRole(const char *roleName, StringMemory memOpt = StringIsTransient);

    /** Create a unique id for internal use (ie. one that will not clash with official OSM ids). */
    [[nodiscard]] Id nextInternalId() const;

    std::vector<Node> nodes;
    std::vector<Way> ways;
    std::vector<Relation> relations;

private:
    template <typename T> T stringKey(const char *name, const std::vector<T> &registry) const;
    template <typename T> T makeStringKey(const char *name, StringMemory memOpt, std::vector<T> &registry);

    std::vector<TagKey> m_tagKeyRegistry;
    std::vector<Role> m_roleRegistry;
    std::vector<char*> m_stringPool;
};

/** Returns the tag value for @p key of @p elem. */
template <typename Elem>
[[nodiscard]] inline QByteArray tagValue(const Elem& elem, TagKey key)
{
    const auto it = std::lower_bound(elem.tags.begin(), elem.tags.end(), key);
    if (it != elem.tags.end() && (*it).key == key) {
        return (*it).value;
    }
    return {};
}

/** Returns the tag value for key name @p keyName of @p elem.
 *  @warning This is slow due to doing a linear search and string comparissons.
 *  Where possible avoid this in favor of tagValue().
 */
template <typename Elem>
[[nodiscard]] inline QByteArray tagValue(const Elem& elem, const char *keyName)
{
    const auto it = std::find_if(elem.tags.begin(), elem.tags.end(), [keyName](const auto &tag) { return std::strcmp(tag.key.name(), keyName) == 0; });
    if (it != elem.tags.end()) {
        return (*it).value;
    }
    return {};
}

/** Returns the localized version of the tag value for key name @p keyName of @p elem.
 *  @warning This is slow due to doing a linear search and string comparissons.
 */
template <typename Elem>
inline QByteArray tagValue(const Elem& elem, const char *keyName, const QLocale &locale)
{
    QByteArray key(keyName);
    key.push_back(':');
    const auto baseLen = key.size();
    for (const auto &lang : locale.uiLanguages()) {
        key.resize(baseLen);
        key.append(lang.toUtf8());
        const auto it = std::find_if(elem.tags.begin(), elem.tags.end(), [key](const auto &tag) { return std::strcmp(tag.key.name(), key.constData()) == 0; });
        if (it != elem.tags.end()) {
            return (*it).value;
        }

        const auto idx = lang.indexOf(QLatin1Char('-'));
        if (idx > 0) {
            key.resize(baseLen);
            key.append(QStringView(lang).left(idx).toUtf8());
            const auto it = std::find_if(elem.tags.begin(), elem.tags.end(), [key](const auto &tag) { return std::strcmp(tag.key.name(), key.constData()) == 0; });
            if (it != elem.tags.end()) {
                return (*it).value;
            }
        }
    }

    // fall back to generic value, if present
    const auto v = tagValue(elem, keyName);
    if (!v.isEmpty()) {
        return v;
    }

    // check if there is at least one in any language we can use
    key.resize(baseLen);
    const auto it = std::find_if(elem.tags.begin(), elem.tags.end(), [key, baseLen](const auto &tag) { return std::strncmp(tag.key.name(), key.constData(), baseLen) == 0; });
    if (it != elem.tags.end()) {
        return (*it).value;
    }
    return {};
}

/** Inserts a new tag, or replaces an existing one with the same key. */
template <typename Elem>
inline void setTag(Elem &elem, Tag &&tag)
{
    const auto it = std::lower_bound(elem.tags.begin(), elem.tags.end(), tag);
    if (it == elem.tags.end() || (*it).key != tag.key) {
        elem.tags.insert(it, std::move(tag));
    } else {
        (*it) = std::move(tag);
    }
}

/** Inserts a new tag, or updates an existing one. */
template <typename Elem>
inline void setTagValue(Elem &elem, TagKey key, QByteArray &&value)
{
    setTag(elem, Tag(key, std::move(value)));
}

/** Removes a tag from the given element. */
template <typename Elem>
inline void removeTag(Elem &elem, TagKey key)
{
    const auto it = std::lower_bound(elem.tags.begin(), elem.tags.end(), key);
    if (it != elem.tags.end() && (*it).key == key) {
        elem.tags.erase(it);
    }
}

}

QDebug operator<<(QDebug debug, OSM::Coordinate coord);
QDebug operator<<(QDebug debug, OSM::BoundingBox bbox);

#endif // OSM_DATATYPES_H

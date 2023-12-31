/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef WIKIDATA_ITEM_H
#define WIKIDATA_ITEM_H

#include <QColor>
#include <QDebug>
#include <QJsonObject>
#include <QMetaType>
#include <QVariant>

#include <cstdint>
#include <vector>

namespace Wikidata {

template <typename T, char Prefix>
class Identifier
{
public:
    explicit inline constexpr Identifier() {}
    explicit inline constexpr Identifier(T id) : m_id(id) {}
    explicit inline Identifier(const QString &id) : m_id(fromString(id).m_id) {}
    explicit inline Identifier(const QByteArray &id) : m_id(fromString(id).m_id) {}

    inline constexpr bool isValid() const
    {
        return m_id > 0;
    }

    inline constexpr bool operator<(Identifier other) const
    {
        return m_id < other.m_id;
    }
    inline constexpr bool operator==(Identifier other) const
    {
        return m_id == other.m_id;
    }
    inline constexpr bool operator!=(Identifier other) const
    {
        return m_id != other.m_id;
    }

    inline QString toString() const
    {
        return QLatin1Char(Prefix) + QString::number(m_id);
    }

protected:
    T m_id = 0;

private:
    static inline Identifier fromString(const QString &id)
    {
        if (!id.startsWith(QLatin1Char(Prefix))) {
            return Identifier();
        }
        return Identifier(QStringView(id).mid(1).toULongLong());
    }
    static inline Identifier fromString(const QByteArray &id)
    {
        if (!id.startsWith(Prefix)) {
            return Identifier();
        }
        return Identifier(id.mid(1).toULongLong());
    }
};

/** Wikidata item identifier. */
class Q : public Identifier<uint64_t, 'Q'>
{
public:
    explicit inline constexpr Q() = default;
    explicit inline constexpr Q(uint64_t id) : Identifier(id) {}
    explicit inline Q(const QString &id) : Identifier(id) {}
    explicit inline Q(const QByteArray &id) : Identifier(id) {}
};

/** Wikidata property identifier. */
class P : public Identifier<uint32_t, 'P'>
{
public:
    enum Property : uint32_t {
        instanceOf = 31,
        logoImage = 154,
        partOf = 361,
    };

    explicit inline constexpr P() = default;
    /* implicit */ inline constexpr P(Property id) : Identifier(id) {}
    explicit inline constexpr P(uint32_t id) : Identifier(id) {}
    explicit inline P(const QString &id) : Identifier(id) {}
};

/** Wikidata item. */
class Item
{
public:
    explicit Item();
    explicit Item(Q id, const QJsonObject &data);
    ~Item();

    inline constexpr bool isValid() const { return m_id.isValid(); }
    inline constexpr Q id() const { return m_id; }

    template <typename T>
    inline T value(P property) const
    {
        return convertValue<T>(value(property));
    }

    template <typename T>
    inline std::vector<T> values(P property) const
    {
        const auto vals = values(property);
        std::vector<T> v;
        v.reserve(vals.size());
        std::transform(vals.begin(), vals.end(), std::back_inserter(v), [](const QVariant &value) { return convertValue<T>(value); });
        return v;
    }

private:
    std::vector<QVariant> values(P property) const;
    QVariant value(P property) const;

    template <typename T>
    static inline T convertValue(const QVariant &v)
    {
        return v.value<T>();
    }

    Q m_id;
    QJsonObject m_data;
};

template <>
inline QColor Item::convertValue<QColor>(const QVariant &v)
{
    const auto s = v.toString();
    if (s.size() == 6) {
        return QColor(QLatin1Char('#') + s);
    }
    return QColor(s);
}

/** Commons image metadata. */
class Image
{
public:
    explicit Image();
    explicit Image(const QJsonObject &obj);
    ~Image();

    QString name() const;
    uint64_t fileSize() const;
    uint32_t width() const;
    uint32_t height() const;
    QString mimeType() const;
    QString license() const;

private:
    QJsonObject imageInfo() const;
    QJsonObject m_data;
};

}

Q_DECLARE_METATYPE(Wikidata::Q)
Q_DECLARE_METATYPE(Wikidata::P)

template <typename T, char Prefix>
inline QDebug operator<<(QDebug debug, Wikidata::Identifier<T, Prefix> id)
{
    QDebugStateSaver saver(debug);
    if (id.isValid()) {
        debug.noquote().nospace() << QStringLiteral("https://www.wikidata.org/wiki/") + id.toString();
    }
    return debug;
}

#endif // WIKIDATA_ITEM_H

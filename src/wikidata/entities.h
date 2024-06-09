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
    explicit inline constexpr Identifier() = default;
    explicit inline constexpr Identifier(T id) : m_id(id) {}
    explicit inline Identifier(QStringView id) : m_id(fromString(id).m_id) {}
    explicit inline Identifier(QByteArrayView id) : m_id(fromString(id).m_id) {}

    [[nodiscard]] inline constexpr bool isValid() const
    {
        return m_id > 0;
    }

    [[nodiscard]] inline constexpr bool operator<(Identifier other) const
    {
        return m_id < other.m_id;
    }
    [[nodiscard]] inline constexpr bool operator==(Identifier other) const
    {
        return m_id == other.m_id;
    }
    [[nodiscard]] inline constexpr bool operator!=(Identifier other) const
    {
        return m_id != other.m_id;
    }

    [[nodiscard]] inline QString toString() const
    {
        return QLatin1Char(Prefix) + QString::number(m_id);
    }

protected:
    T m_id = 0;

private:
    [[nodiscard]] static inline Identifier fromString(QStringView id)
    {
        if (!id.startsWith(QLatin1Char(Prefix))) {
            return Identifier();
        }
        return Identifier(id.mid(1).toULongLong());
    }
    [[nodiscard]] static inline Identifier fromString(QByteArrayView id)
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
    explicit inline Q(QStringView id) : Identifier(id) {}
    explicit inline Q(QByteArrayView id) : Identifier(id) {}
};

/** Wikidata property identifier. */
class P : public Identifier<uint32_t, 'P'>
{
public:
    enum Property : uint32_t {
        image = 18,
        instanceOf = 31,
        logoImage = 154,
        partOf = 361,
        nighttimeView = 3451,
        winterView = 5252,
        view = 8517,
        aerialView = 8592,
        modelImage = 11101,
    };

    explicit inline constexpr P() = default;
    /* implicit */ inline constexpr P(Property id) : Identifier(id) {}
    explicit inline constexpr P(uint32_t id) : Identifier(id) {}
    explicit inline P(QStringView id) : Identifier(id) {}
};

/** Wikidata item. */
class Item
{
public:
    explicit Item();
    explicit Item(Q id, const QJsonObject &data);
    ~Item();

    [[nodiscard]] inline constexpr bool isValid() const { return m_id.isValid(); }
    [[nodiscard]] inline constexpr Q id() const { return m_id; }

    template <typename T>
    [[nodiscard]] inline T value(P property) const
    {
        return convertValue<T>(value(property));
    }

    template <typename T>
    [[nodiscard]] inline std::vector<T> values(P property) const
    {
        const auto vals = values(property);
        std::vector<T> v;
        v.reserve(vals.size());
        std::transform(vals.begin(), vals.end(), std::back_inserter(v), [](const QVariant &value) { return convertValue<T>(value); });
        return v;
    }

private:
    [[nodiscard]] std::vector<QVariant> values(P property) const;
    [[nodiscard]] QVariant value(P property) const;

    template <typename T>
    [[nodiscard]] static inline T convertValue(const QVariant &v)
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

    [[nodiscard]] QString name() const;
    [[nodiscard]] uint64_t fileSize() const;
    [[nodiscard]] uint32_t width() const;
    [[nodiscard]] uint32_t height() const;
    [[nodiscard]] QString mimeType() const;
    [[nodiscard]] QString license() const;

private:
    [[nodiscard]] QJsonObject imageInfo() const;
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
        debug.noquote().nospace() << QLatin1StringView("https://www.wikidata.org/wiki/") + id.toString();
    }
    return debug;
}

#endif // WIKIDATA_ITEM_H

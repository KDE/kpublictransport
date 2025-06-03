/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JSON_P_H
#define KPUBLICTRANSPORT_JSON_P_H

#include <QJsonArray>
#include <QJsonObject>
#include <QMetaEnum>
#include <QStringList>

#include <vector>

struct QMetaObject;

namespace KPublicTransport {

/** De/serialization helper methods. */
namespace Json
{
    /** Looks for a translated value in @p obj with @p key. */
    [[nodiscard]] QString translatedValue(const QJsonObject &obj, QLatin1StringView key);
    /** Convert a QJsonValue to a QStringList, assuming it contains an array of strings. */
    QStringList toStringList(const QJsonValue &v);

    QJsonObject toJson(const QMetaObject *mo, const void *elem);

    /** Serialize from QMetaObject. */
    template <typename T> inline QJsonObject toJson(const T &elem)
    {
        return toJson(&T::staticMetaObject, &elem);
    }

    /** Serialize an array of elements. */
    template <typename T> inline QJsonArray toJson(const std::vector<T> &elems)
    {
        QJsonArray a;
        //a.reserve(elems.size());
        std::transform(elems.begin(), elems.end(), std::back_inserter(a), QOverload<const T&>::of(&T::toJson));
        return a;
    }

    void fromJson(const QMetaObject *mo, const QJsonObject &obj, void *elem);

    /** Deserialize via QMetaObject. */
    template <typename T> inline T fromJson(const QJsonObject &obj)
    {
        T elem;
        fromJson(&T::staticMetaObject, obj, &elem);
        return elem;
    }

    /** Deserialize an array of elements. */
    template <typename T> inline std::vector<T> fromJson(const QJsonArray &a)
    {
        std::vector<T> res;
        res.reserve(a.size());
        std::transform(a.begin(), a.end(), std::back_inserter(res), [](const auto &v) { return T::fromJson(v.toObject()); });
        return res;
    }

    /** Deserialize an enum string. */
    template <typename Flags> inline Flags flagsFromJson(const QJsonValue &s)
    {
        const auto me = QMetaEnum::fromType<Flags>();
        return static_cast<Flags>(me.keysToValue(s.toString().toUtf8().constData()));
    }
}

}

#endif // KPUBLICTRANSPORT_JSON_P_H

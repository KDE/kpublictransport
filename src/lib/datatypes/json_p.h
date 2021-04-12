/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JSON_P_H
#define KPUBLICTRANSPORT_JSON_P_H

#include <QJsonArray>
#include <QJsonObject>

#include <vector>

struct QMetaObject;

namespace KPublicTransport {

/** De/serialization helper methods. */
namespace Json
{
    /** Looks for a translated value in @p obj with @p key. */
    QString translatedValue(const QJsonObject &obj, const QString &key);

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
}

}

#endif // KPUBLICTRANSPORT_JSON_P_H

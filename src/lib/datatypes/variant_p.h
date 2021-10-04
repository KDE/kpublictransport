/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_VARIANT_H
#define KPUBLICTRANSPORT_VARIANT_H

#include <QVariant>

#include <vector>

class QMetaObject;

namespace KPublicTransport {

/** Deserialization from variant maps, for QML bindings. */
namespace Variant
{
    void fromVariantMap(const QMetaObject *mo, const QVariantMap &v, void *obj);

    /** Deserialize variant map into an actual object based on meta-type information. */
    template <typename T>
    inline T fromVariant(const QVariant &v)
    {
        if (qMetaTypeId<T>() == v.userType()) {
            return v.value<T>();
        }
        if (v.canConvert<QVariantMap>()) {
            T obj;
            fromVariantMap(&T::staticMetaObject, v.toMap(), &obj);
            return obj;
        }
        return {};
    }

    /** Deserialize a list of variants. */
    template <typename T>
    inline std::vector<T> fromVariantList(const QVariantList &l)
    {
        std::vector<T> out;
        out.reserve(l.size());
        std::transform(l.begin(), l.end(), std::back_inserter(out), &Variant::fromVariant<T>);
        return out;
    }
}

}

#endif // KPUBLICTRANSPORT_VARIANT_H

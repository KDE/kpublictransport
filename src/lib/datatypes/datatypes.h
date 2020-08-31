/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DATATYPES_H
#define KPUBLICTRANSPORT_DATATYPES_H

#include "kpublictransport_export.h"

#include <QMetaType>
#include <QSharedDataPointer>

#include <type_traits>

namespace KPublicTransport {
namespace Internal {
template <typename T>
struct parameter_type
{
    using type = typename std::conditional<std::is_fundamental<T>::value || std::is_enum<T>::value, T, const T&>::type;
};
}
}

#define KPUBLICTRANSPORT_GADGET(Class) \
    Q_GADGET \
public: \
    Class(); \
    Class(Class&&) noexcept; \
    Class(const Class&); \
    ~Class(); \
    Class& operator=(Class&&) noexcept; \
    Class& operator=(const Class&); \
private: \
    QExplicitlySharedDataPointer<Class ## Private> d;

#define KPUBLICTRANSPORT_PROPERTY(Type, Getter, Setter) \
public: \
    Q_PROPERTY(Type Getter READ Getter WRITE Setter) \
    Type Getter() const; \
    void Setter(KPublicTransport::Internal::parameter_type<Type>::type value); \


#endif

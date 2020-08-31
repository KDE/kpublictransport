/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_DATATYPES_P_H
#define KPUBLICTRANSPORT_DATATYPES_P_H

#include "datatypes.h"

#include <QSharedData>

#define KPUBLICTRANSPORT_MAKE_GADGET(Class) \
Class::Class() : d(new Class ## Private) {} \
Class::Class(const Class&) = default; \
Class::Class(Class&&) noexcept = default; \
Class::~Class() = default; \
Class& Class::operator=(const Class&) = default; \
Class& Class::operator=(Class&&) noexcept = default;

// TODO this could be improved by checking for equality before detaching
// but this requires similar equality workarounds than KItinerary uses
#define KPUBLICTRANSPORT_MAKE_PROPERTY(Class, Type, Getter, Setter) \
Type Class::Getter() const { return d->Getter; } \
void Class::Setter(KPublicTransport::Internal::parameter_type<Type>::type value) \
{ \
    d.detach(); \
    d->Getter = value; \
}

#endif

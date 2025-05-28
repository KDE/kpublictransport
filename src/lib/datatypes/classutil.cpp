/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "classutil.h"

#include <KLocalizedString>

using namespace Qt::Literals;
using namespace KPublicTransport;

VehicleSection::Classes ClassUtil::fromString(const QString &className)
{
    VehicleSection::Classes c = VehicleSection::UnknownClass;
    if (className.contains('1'_L1)) {
        c |= VehicleSection::FirstClass;
    }
    if (className.contains('2'_L1)) {
        c |= VehicleSection::SecondClass;
    }

    return c;
}

QString ClassUtil::displayName(VehicleSection::Classes classes)
{
    if (classes == VehicleSection::FirstClass) {
        return i18nc("train seating class", "First class");
    }
    if (classes == VehicleSection::SecondClass) {
        return i18nc("train seating class", "Second class");
    }
    if (classes == (VehicleSection::FirstClass | VehicleSection::SecondClass)) {
        return i18nc("train seating class", "First/second class");
    }

    return {};
}

#include "moc_classutil.cpp"

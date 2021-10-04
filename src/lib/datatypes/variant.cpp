/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "variant_p.h"

#include <QMetaObject>
#include <QMetaProperty>

using namespace KPublicTransport;

void Variant::fromVariantMap(const QMetaObject *mo, const QVariantMap &v, void *obj)
{
    for (auto it = v.begin(); it != v.end(); ++it) {
        const auto idx = mo->indexOfProperty(it.key().toUtf8().constData());
        if (idx < 0) {
            continue;
        }

        const auto prop = mo->property(idx);
        if (!prop.isStored()) {
            continue;
        }

        prop.writeOnGadget(obj, it.value());
    }
}

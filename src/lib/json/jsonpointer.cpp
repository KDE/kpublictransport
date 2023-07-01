/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "jsonpointer_p.h"

#include <QDebug>
#include <QJsonObject>

using namespace KPublicTransport;

QJsonValue JsonPointer::evaluate(const QJsonValue &obj, QStringView jsonPointer)
{
    if (jsonPointer.startsWith(QLatin1Char('/'))) {
        jsonPointer = jsonPointer.mid(1);
    }
    if (jsonPointer.isEmpty()) {
        return obj;
    }

    const auto idx = jsonPointer.indexOf(QLatin1Char('/'));
    const auto key = idx >= 0 ? jsonPointer.left(idx) : jsonPointer;

    if (obj.isObject()) {
        const auto value = obj.toObject().value(key);
        if (idx >= 0) {
            return JsonPointer::evaluate(value, jsonPointer.mid(idx + 1));
        }
        return value;
    }
    if (obj.isArray()) {
        qWarning() << "JSON Pointer array indexing not implemented yet!";
        return {};
    }

    qWarning() << "JSON Pointer expression applied to primitive value!" << jsonPointer;
    return {};
}

/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "jsonp_p.h"

#include <QByteArray>

using namespace KPublicTransport;

QByteArray JsonP::decode(const QByteArray &data)
{
    const auto firstBrace = data.indexOf('{');
    const auto firstBracket = data.indexOf('[');

    if (firstBrace == 0 || firstBracket == 0 || (firstBrace < 0 && firstBracket < 0)) {
        return data;
    }

    if (firstBrace > 0 && (firstBrace < firstBracket || firstBracket < 0)) {
        const auto lastBrace = data.lastIndexOf('}');
        return lastBrace > firstBrace ? data.mid(firstBrace, lastBrace - firstBrace + 1) : data;
    }

    if (firstBracket > 0 && (firstBracket < firstBrace || firstBrace < 0)) {
        const auto lastBracket = data.lastIndexOf(']');
        return lastBracket > firstBracket ? data.mid(firstBracket, lastBracket - firstBracket +1) : data;
    }

    return data;
}

/*
    SPDX-FileCopyrightText: 2023 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

#include <unordered_map>

#include "localbackendutils.h"
#include "journeyrequest.h"


using namespace KPublicTransport::LocalBackendUtils;

QString KPublicTransport::LocalBackendUtils::makeSearchableName(QString name)
{
    // Remove spaces
    return normalizeName(
        name.replace(QStringLiteral(" "), QString())
            // Remove parts in parantheses, the DB API likes to add the country in parantheses
            .replace(QRegularExpression(QStringLiteral(R"(\([^)]*\))")), QString()));
}

QString KPublicTransport::LocalBackendUtils::normalizeName(QString name)
{
    return name
        // Split accents into their own charcters
        .normalized(QString::NormalizationForm_D)
        // filter those characters out
        .replace(QRegularExpression(QStringLiteral("[\\p{Mn}\\p{Mc}\\p{Me}]")), QString())
        .toLower()
        .trimmed();
}

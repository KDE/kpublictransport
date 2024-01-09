/*
    SPDX-FileCopyrightText: 2023 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>

#include "localbackendutils.h"
#include "journeyrequest.h"


using namespace KPublicTransport::LocalBackendUtils;

QString KPublicTransport::LocalBackendUtils::makeSearchableName(QString name)
{
    return name
        // Remove parts in parantheses, the DB API likes to add the country in parantheses
        .replace(QRegularExpression(QStringLiteral(R"(\([^)]*\))")), QString())
        // Split accents into their own charcters
        .normalized(QString::NormalizationForm_D)
        // filter those characters out
        .replace(QRegularExpression(QStringLiteral("[^a-zA-Z0-9\\s]")), QString())
        .toLower();
}

bool KPublicTransport::LocalBackendUtils::isInSelectedTimeframe(const QDateTime &departure, const QDateTime &arrival, const JourneyRequest &req)
{
    // Filter for requested arrival / departure time frame
    if (req.dateTimeMode() == JourneyRequest::Departure) {
        if (departure < req.dateTime()) {
            return false;
        }
    } else {
        if (arrival > req.dateTime()) {
            return false;
        }
    }

    return true;
}

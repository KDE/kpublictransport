/*
    SPDX-FileCopyrightText: 2023 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QString>
#include <QRegularExpression>
#include <QNetworkReply>

#include "journeyrequest.h"

namespace KPublicTransport {

namespace LocalBackendUtils {

QString makeSearchableName(const QString &name);

bool isInSelectedTimeframe(const QDateTime &departure, const QDateTime &arrival, const JourneyRequest &req);

}

}

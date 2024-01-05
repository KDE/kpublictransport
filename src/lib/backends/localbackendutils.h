/*
    SPDX-FileCopyrightText: 2023 Jonah Brüchert <jbb@kaidan.im>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include "journeyrequest.h"
#include <QString>
#include <QRegularExpression>

namespace KPublicTransport {

namespace LocalBackendUtils {

QString makeSearchableName(QString name);

bool isInSelectedTimeframe(const QDateTime &departure, const QDateTime &arrival, const JourneyRequest &req);

}

}

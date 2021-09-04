/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsreader.h"

#include <QJsonObject>

#include <cmath>

using namespace KPublicTransport;

static double readDouble(const QJsonValue &v)
{
    if (v.isDouble()) {
        return v.toDouble(NAN);
    }
    if (v.isString()) {
        bool valid = false;
        const auto d = v.toString().toDouble(&valid);
        return valid ? d : NAN;
    }
    return NAN;
}

double GBFSReader::readLatitude(const QJsonObject &obj)
{
    return readDouble(obj.value(QLatin1String("lat")));
}

double GBFSReader::readLongitude(const QJsonObject &obj)
{
    return readDouble(obj.value(QLatin1String("lon")));
}

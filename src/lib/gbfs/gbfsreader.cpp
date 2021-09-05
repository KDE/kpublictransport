/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsreader.h"

#include <QJsonDocument>
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

QJsonObject GBFSReader::dataObject(const QJsonDocument &doc)
{
    const auto obj = doc.object();
    const auto it = obj.find(QLatin1String("data"));
    if (it == obj.end() || !(*it).isObject()) {
        return obj;
    }
    return (*it).toObject();
}

QJsonValue GBFSReader::dataValue(const QJsonDocument &doc, QLatin1String name)
{
    return dataObject(doc).value(name);
}

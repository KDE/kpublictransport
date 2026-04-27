/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsreader.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLocale>

#include <cmath>

using namespace Qt::Literals;
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
    return readDouble(obj.value("lat"_L1));
}

double GBFSReader::readLongitude(const QJsonObject &obj)
{
    return readDouble(obj.value("lon"_L1));
}

QJsonObject GBFSReader::dataObject(const QJsonDocument &doc)
{
    auto obj = doc.object();
    const auto it = obj.find("data"_L1);
    if (it == obj.end() || !(*it).isObject()) {
        return obj;
    }
    return (*it).toObject();
}

QJsonValue GBFSReader::dataValue(const QJsonDocument &doc, QLatin1String name)
{
    return dataObject(doc).value(name);
}

QString GBFSReader::readLocalizedString(const QJsonObject &obj, QLatin1String key)
{
    const auto v = obj.value(key);
    if (!v.isArray()) {
        return v.toString();
    }
    const auto texts = v.toArray();
    if (texts.isEmpty()) {
        return {};
    }

    const auto findLang = [texts](QStringView lang) {
        for (const auto &textV : texts) {
            const auto textObj = textV.toObject();
            if (textObj.value("language"_L1).toString() == lang) {
                return textObj.value("text"_L1).toString();
            }
        }
        return QString();
    };

    const auto langs = QLocale().uiLanguages();
    for (const auto &lang : langs) {
        auto res = findLang(lang);
        if (!res.isEmpty()) {
            return res;
        }
        const auto idx = lang.indexOf('-'_L1);
        if (idx > 0) {
            res = findLang(lang.left(idx));
            if (!res.isEmpty()) {
                return res;
            }
        }
    }

    auto res = findLang(u"en");
    return res.isEmpty() ? texts.at(0).toObject().value("text"_L1).toString() : res;
}

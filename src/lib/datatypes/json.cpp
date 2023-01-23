/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "json_p.h"
#include "logging.h"

#include <QColor>
#include <QDateTime>
#include <QDebug>
#include <QLocale>
#include <QMetaObject>
#include <QMetaProperty>
#include <QRectF>
#include <QTimeZone>
#include <QUrl>
#include <QVariant>

#include <cmath>

using namespace KPublicTransport;

QString Json::translatedValue(const QJsonObject &obj, const QString &key)
{
    auto languageWithCountry = QLocale().name();
    auto it = obj.constFind(key + QLatin1Char('[') + languageWithCountry + QLatin1Char(']'));
    if (it != obj.constEnd()) {
        return it.value().toString();
    }
    const auto language = QStringView(languageWithCountry).mid(0, languageWithCountry.indexOf(QLatin1Char('_')));
    it = obj.constFind(key + QLatin1Char('[') + language + QLatin1Char(']'));
    if (it != obj.constEnd()) {
        return it.value().toString();
    }
    return obj.value(key).toString();
}

QStringList Json::toStringList(const QJsonValue &v)
{
    const auto a = v.toArray();
    QStringList l;
    l.reserve(a.size());
    for (const auto &av : a) {
        l.push_back(av.toString());
    }
    return l;
}

static QJsonValue variantToJson(const QVariant &v)
{
    switch (v.userType()) {
        case QMetaType::QString:
        {
            const auto s = v.toString();
            return s.isNull() ? QJsonValue() : v.toString();
        }
        case QMetaType::Double:
        case QMetaType::Float:
        {
            auto d = v.toDouble();
            if (std::isnan(d)) {
                return QJsonValue::Null;
            }
            return d;
        }
        case QMetaType::Int:
            return v.toInt();
        case QMetaType::QDateTime:
        {
            const auto dt = v.toDateTime();
            if (!dt.isValid()) {
                return {};
            }
            if (dt.timeSpec() == Qt::TimeZone) {
                QJsonObject dtObj;
                dtObj.insert(QStringLiteral("value"), dt.toString(Qt::ISODate));
                dtObj.insert(QStringLiteral("timezone"), QString::fromUtf8(dt.timeZone().id()));
                return dtObj;
            }
            return v.toDateTime().toString(Qt::ISODate);
        }
        case QMetaType::QUrl:
        {
            const auto url = v.toUrl();
            return url.isValid() ? url.toString() : QJsonValue();
        }
        case QMetaType::QRectF:
        {
            const auto r = v.toRectF();
            QJsonObject obj;
            obj.insert(QStringLiteral("x1"), r.topLeft().x());
            obj.insert(QStringLiteral("y1"), r.topLeft().y());
            obj.insert(QStringLiteral("x2"), r.bottomRight().x());
            obj.insert(QStringLiteral("y2"), r.bottomRight().y());
            return obj;
        }
        case QMetaType::QColor:
        {
            const auto c = v.value<QColor>();
            return c.isValid() ? v.value<QColor>().name() : QJsonValue();;
        }
    }

    if (v.canConvert<QVariantList>()) {
        const auto l = v.toList();
        if (l.isEmpty()) {
            return {};
        }

        QJsonArray a;
        std::transform(l.begin(), l.end(), std::back_inserter(a), variantToJson);
        return a;
    }

    return {};
}

QJsonObject Json::toJson(const QMetaObject *mo, const void *elem)
{
    QJsonObject obj;

    for (int i = 0; i < mo->propertyCount(); ++i) {
        const auto prop = mo->property(i);
        if (!prop.isStored()) {
            continue;
        }

        if (prop.isFlagType()) { // flag has to come first, as prop.isEnumType() is also true for this
            const auto key = prop.readOnGadget(elem).toInt();
            const auto value = prop.enumerator().valueToKeys(key);
            obj.insert(QString::fromUtf8(prop.name()), QString::fromUtf8(value));
            continue;
        }
        if (prop.isEnumType()) { // enums defined in this QMO
            const auto key = prop.readOnGadget(elem).toInt();
            const auto value = prop.enumerator().valueToKey(key);
            obj.insert(QString::fromUtf8(prop.name()), QString::fromUtf8(value));
            continue;
        } else if (QMetaType(prop.userType()).flags() & QMetaType::IsEnumeration) { // external enums
            obj.insert(QString::fromUtf8(prop.name()), prop.readOnGadget(elem).toString());
            continue;
        }

        const auto v = variantToJson(prop.readOnGadget(elem));
        if (!v.isNull()) {
            obj.insert(QString::fromUtf8(prop.name()), v);
        }
    }

    return obj;
}

static QVariant variantFromJson(const QJsonValue &v, int mt)
{
    switch (mt) {
        case QMetaType::QString:
            return v.toString();
        case QMetaType::Double:
        case QMetaType::Float:
            return v.toDouble();
        case QMetaType::Int:
            return v.toInt();
        case QMetaType::QDateTime:
        {
            if (v.isObject()) {
                const auto dtObj = v.toObject();
                auto dt = QDateTime::fromString(dtObj.value(QLatin1String("value")).toString(), Qt::ISODate);
                dt.setTimeZone(QTimeZone(dtObj.value(QLatin1String("timezone")).toString().toUtf8()));
                return dt;
            }
            return QDateTime::fromString(v.toString(), Qt::ISODate);
        }
        case QMetaType::QUrl:
            return QUrl(v.toString());
        case QMetaType::QStringList:
            return Json::toStringList(v);
        case QMetaType::QRectF:
        {
            const auto obj = v.toObject();
            QRectF r;
            r.setTopLeft(QPointF(obj.value(QLatin1String("x1")).toDouble(), obj.value(QLatin1String("y1")).toDouble()));
            r.setBottomRight(QPointF(obj.value(QLatin1String("x2")).toDouble(), obj.value(QLatin1String("y2")).toDouble()));
            return r;
        }
        case QMetaType::QColor:
            return QColor(v.toString());
    }

    return {};
}

void Json::fromJson(const QMetaObject *mo, const QJsonObject &obj, void *elem)
{
    for (auto it = obj.begin(); it != obj.end(); ++it) {
        const auto idx = mo->indexOfProperty(it.key().toUtf8().constData());
        if (idx < 0) {
            continue;
        }

        const auto prop = mo->property(idx);
        if (!prop.isStored()) {
            continue;
        }

        if (prop.isFlagType() && it.value().isString()) {
            const auto key = prop.enumerator().keysToValue(it.value().toString().toUtf8().constData());
            prop.writeOnGadget(elem, key);
            continue;
        }
        if (prop.isEnumType() && it.value().isString()) { // internal enums in this QMO
            const auto key = prop.enumerator().keyToValue(it.value().toString().toUtf8().constData());
            prop.writeOnGadget(elem, key);
            continue;
        }
        if ((QMetaType(prop.userType()).flags() & QMetaType::IsEnumeration) && it.value().isString()) { // external enums
            const QMetaType mt(prop.userType());
            const auto mo = mt.metaObject();
            if (!mo) {
                qCWarning(Log) << "No meta object found for enum type:" << prop.typeName();
                continue;
            }
            const auto enumIdx = mo->indexOfEnumerator(prop.typeName() + strlen(mo->className()) + 2);
            if (enumIdx < 0) {
                qCWarning(Log) << "Could not find QMetaEnum for" << prop.typeName();
                continue;
            }
            const auto me = mo->enumerator(enumIdx);
            bool success = false;
            const auto numValue = me.keyToValue(it.value().toString().toUtf8().constData(), &success);
            if (!success) {
                qCWarning(Log) << "Unknown enum value" << it.value().toString() << "for" << prop.typeName();
                continue;
            }
            auto valueData = mt.create();
            *reinterpret_cast<int*>(valueData) = numValue;
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
            QVariant value(prop.userType(), valueData);
#else
            QVariant value(prop.metaType(), valueData);
#endif
            prop.writeOnGadget(elem, value);
            continue;
        }

        const auto v = variantFromJson(it.value(), prop.userType());
        prop.writeOnGadget(elem, v);
    }
}

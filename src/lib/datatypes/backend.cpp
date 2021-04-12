/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backend.h"
#include "backend_p.h"
#include "datatypes_p.h"
#include "json_p.h"

#include <QJsonObject>

using namespace KPublicTransport;

KPUBLICTRANSPORT_MAKE_GADGET(Backend)
KPUBLICTRANSPORT_MAKE_PROPERTY(Backend, QString, identifier, setIdentifier)
KPUBLICTRANSPORT_MAKE_PROPERTY(Backend, QString, name, setName)
KPUBLICTRANSPORT_MAKE_PROPERTY(Backend, QString, description, setDescription)
KPUBLICTRANSPORT_MAKE_PROPERTY(Backend, bool, isSecure, setIsSecure)

QString Backend::primaryCountryCode() const
{
    if (identifier().size() > 3 && identifier().at(2) == QLatin1Char('_')) {
        return identifier().left(2).toUpper();
    }
    return {};
}

Backend BackendPrivate::fromJson(const QJsonObject &obj, const QString &backendId)
{
    Backend b;
    b.d->identifier = backendId;
    const auto jsonMetaData = obj.value(QLatin1String("KPlugin")).toObject();
    b.d->name = Json::translatedValue(jsonMetaData, QStringLiteral("Name"));
    b.d->description = Json::translatedValue(jsonMetaData, QStringLiteral("Description"));
    return b;
}

#include "moc_backend.cpp"

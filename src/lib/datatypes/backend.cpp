/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backend.h"
#include "backend_p.h"
#include "backends/abstractbackend.h"
#include "datatypes_p.h"
#include "json_p.h"

#include <QJsonObject>

using namespace KPublicTransport;

KPUBLICTRANSPORT_MAKE_GADGET(Backend)

QString Backend::identifier() const
{
    return d->m_backendImpl ? d->m_backendImpl->backendId() : QString();
}

QString Backend::name() const
{
    return d->name;
}

QString Backend::description() const
{
    return d->description;
}

bool Backend::isSecure() const
{
    return d->m_backendImpl && d->m_backendImpl->capabilities() & AbstractBackend::Secure;
}

QString Backend::primaryCountryCode() const
{
    if (identifier().size() > 3 && identifier().at(2) == QLatin1Char('_')) {
        return identifier().left(2).toUpper();
    }
    return {};
}

const AbstractBackend* BackendPrivate::impl(const Backend &b)
{
    return b.d->m_backendImpl.get();
}

void BackendPrivate::setImpl(Backend &b, std::unique_ptr<AbstractBackend> &&impl)
{
    b.d->m_backendImpl = std::move(impl);
}

Backend BackendPrivate::fromJson(const QJsonObject &obj)
{
    Backend b;
    const auto jsonMetaData = obj.value(QLatin1String("KPlugin")).toObject();
    b.d->name = Json::translatedValue(jsonMetaData, QStringLiteral("Name"));
    b.d->description = Json::translatedValue(jsonMetaData, QStringLiteral("Description"));
    return b;
}

#include "moc_backend.cpp"

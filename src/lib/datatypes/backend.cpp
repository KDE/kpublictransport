/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backend.h"
#include "backend_p.h"
#include "backends/abstractbackend.h"
#include "coveragearea.h"
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
    return d->m_backendImpl && d->m_backendImpl->hasCapability(AbstractBackend::Secure);
}

CoverageArea Backend::coverageArea(CoverageArea::Type coverageType) const
{
    return d->coverage[coverageType];
}

const AbstractBackend* BackendPrivate::impl(const Backend &b)
{
    return b.d->m_backendImpl.get();
}

void BackendPrivate::setImpl(Backend &b, std::unique_ptr<AbstractBackend> &&impl)
{
    b.d->m_backendImpl = std::move(impl);
}

struct {
    const char *name;
    CoverageArea::Type type;
} static constexpr const coverage_area_map[] = {
    { "realtimeCoverage", CoverageArea::Realtime },
    { "regularCoverage", CoverageArea::Regular },
    { "anyCoverage", CoverageArea::Any },
};

Backend BackendPrivate::fromJson(const QJsonObject &obj)
{
    Backend b;
    const auto jsonMetaData = obj.value(QLatin1String("KPlugin")).toObject();
    b.d->name = Json::translatedValue(jsonMetaData, QStringLiteral("Name"));
    b.d->description = Json::translatedValue(jsonMetaData, QStringLiteral("Description"));

    const auto coverage = obj.value(QLatin1String("coverage")).toObject();
    for (const auto &c : coverage_area_map) {
        const auto covObj = coverage.value(QLatin1String(c.name)).toObject();
        if (covObj.empty()) {
            continue;
        }
        b.d->coverage[c.type] = CoverageArea::fromJson(covObj);
        b.d->coverage[c.type].setType(c.type);
    }

    return b;
}

#include "moc_backend.cpp"

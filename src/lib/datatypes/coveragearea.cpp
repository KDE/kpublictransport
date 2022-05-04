/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "coveragearea.h"
#include "datatypes_p.h"
#include "json_p.h"
#include "location.h"
#include "geo/geojson_p.h"

#include <QJsonObject>
#include <QPolygonF>

using namespace KPublicTransport;

namespace KPublicTransport {
class CoverageAreaPrivate : public QSharedData {
public:
    CoverageArea::Type type = CoverageArea::Any;
    QStringList regions;
    QStringList uicCompanyCodes;
    QStringList vdvOrganizationIds;
    std::vector<QPolygonF> areas;
    QRectF boundingBox;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(CoverageArea)
KPUBLICTRANSPORT_MAKE_PROPERTY(CoverageArea, CoverageArea::Type, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(CoverageArea, QStringList, regions, setRegions)
KPUBLICTRANSPORT_MAKE_PROPERTY(CoverageArea, QStringList, uicCompanyCodes, setUicCompanyCodes)
KPUBLICTRANSPORT_MAKE_PROPERTY(CoverageArea, QStringList, vdvOrganizationIds, setVdvOrganizationIds)

bool CoverageArea::isEmpty() const
{
    return d->regions.isEmpty() && d->areas.empty();
}

bool CoverageArea::isGlobal() const
{
    if (d->regions.size() == 1 && d->regions.at(0) == QLatin1String("UN")) {
        return true;
    }

    return d->boundingBox.topLeft() == QPointF(-180.0, -90.0) && d->boundingBox.bottomRight() == QPointF(180.0, 90.0);
}

static QStringView countryCode(QStringView isoCode)
{
    return isoCode.size() < 2 ? QStringView() : isoCode.left(2);
}

bool CoverageArea::coversLocation(const Location &loc) const
{
    if (loc.hasCoordinate() && !d->areas.empty()) {
        if (d->boundingBox.contains({loc.longitude(), loc.latitude()})) {
            return std::any_of(d->areas.begin(), d->areas.end(), [&loc](const auto &area) {
                return area.containsPoint({loc.longitude(), loc.latitude()}, Qt::WindingFill);
            });
        }
        return false;
    }

    // TODO we could do a more precise check for ISO 3166-2 subdivision codes when available

    if (loc.country().size() == 2 && !d->regions.empty()) {
        if (d->regions.size() == 1 && d->regions.at(0) == QLatin1String("UN")) { // global coverage
            return true;
        }
        return std::binary_search(d->regions.begin(), d->regions.end(), loc.country(), [](const auto &lhs, const auto &rhs) {
            return countryCode(lhs) < countryCode(rhs);
        });
    }

    // if we have nothing to check against, assume the backend can help (otherwise none would trigger)
    return true;
}

bool CoverageArea::hasNationWideCoverage(const QString &country) const
{
    return std::binary_search(d->regions.begin(), d->regions.end(), country);
}

CoverageArea CoverageArea::fromJson(const QJsonObject &obj)
{
    CoverageArea ca;
    ca.setRegions(Json::toStringList(obj.value(QLatin1String("region"))));
    ca.setUicCompanyCodes(Json::toStringList(obj.value(QLatin1String("uicCompanyCodes"))));
    std::sort(ca.d->regions.begin(), ca.d->regions.end());
    ca.d->areas = GeoJson::readOuterPolygons(obj.value(QLatin1String("area")).toObject());
    for (const auto &area : ca.d->areas) {
        ca.d->boundingBox |= area.boundingRect();
    }
    return ca;
}

#include "moc_coveragearea.cpp"

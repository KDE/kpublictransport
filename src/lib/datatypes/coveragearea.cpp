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
#include <QStringList>

using namespace KPublicTransport;

namespace KPublicTransport {
class CoverageAreaPrivate : public QSharedData {
public:
    CoverageArea::Type type = CoverageArea::Any;
    QStringList regions;
    QPolygonF area;
    QRectF boundingBox;
};
}

KPUBLICTRANSPORT_MAKE_GADGET(CoverageArea)
KPUBLICTRANSPORT_MAKE_PROPERTY(CoverageArea, CoverageArea::Type, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(CoverageArea, QStringList, regions, setRegions)

bool CoverageArea::isEmpty() const
{
    return d->regions.isEmpty() && d->area.isEmpty();
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
    if (loc.hasCoordinate() && !d->area.isEmpty()) {
        return d->boundingBox.contains({loc.longitude(), loc.latitude()})
            && d->area.containsPoint({loc.longitude(), loc.latitude()}, Qt::WindingFill);
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

CoverageArea CoverageArea::fromJson(const QJsonObject &obj)
{
    CoverageArea ca;
    ca.setRegions(Json::toStringList(obj.value(QLatin1String("region"))));
    std::sort(ca.d->regions.begin(), ca.d->regions.end());
    ca.d->area = GeoJson::readOuterPolygon(obj.value(QLatin1String("area")).toObject());
    ca.d->boundingBox = ca.d->area.boundingRect();
    return ca;
}

#include "moc_coveragearea.cpp"

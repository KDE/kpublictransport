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
};
}

KPUBLICTRANSPORT_MAKE_GADGET(CoverageArea)
KPUBLICTRANSPORT_MAKE_PROPERTY(CoverageArea, CoverageArea::Type, type, setType)
KPUBLICTRANSPORT_MAKE_PROPERTY(CoverageArea, QStringList, regions, setRegions)

bool CoverageArea::isEmpty() const
{
    return d->regions.isEmpty() && d->area.isEmpty();
}

static QStringView countryCode(QStringView isoCode)
{
    return isoCode.size() < 2 ? QStringView() : isoCode.left(2);
}

bool CoverageArea::coveresLocation(const Location &loc) const
{
    if (loc.hasCoordinate() && !d->area.isEmpty()) {
        return d->area.containsPoint({loc.longitude(), loc.latitude()}, Qt::WindingFill);
    }

    // TODO we could do a more precise check for ISO 3166-2 subdivision codes when available

    if (loc.country().size() == 2 && !d->regions.empty()) {
        return std::binary_search(d->regions.begin(), d->regions.end(), loc.country(), [](const auto &lhs, const auto &rhs) {
            return countryCode(lhs) < countryCode(rhs);
        });
    }

    return false;
}

CoverageArea CoverageArea::fromJson(const QJsonObject &obj)
{
    CoverageArea ca;
    ca.setRegions(Json::toStringList(obj.value(QLatin1String("region"))));
    std::sort(ca.d->regions.begin(), ca.d->regions.end());
    ca.d->area = GeoJson::readOuterPolygon(obj.value(QLatin1String("area")).toObject());
    return ca;
}

#include "moc_coveragearea.cpp"

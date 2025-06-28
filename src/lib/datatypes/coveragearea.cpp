/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "coveragearea.h"
#include "datatypes_p.h"
#include "json_p.h"
#include "location.h"
#include "logging.h"
#include "geo/geojson_p.h"
#include "standardpaths_p.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPolygonF>

using namespace Qt::Literals;
using namespace KPublicTransport;

namespace KPublicTransport {
class CoverageAreaPrivate : public QSharedData {
public:
    void loadGeometry();
    void recomputeBoundingBox();

    CoverageArea::Type type = CoverageArea::Any;
    QStringList regions;
    QStringList uicCompanyCodes;
    QStringList vdvOrganizationIds;
    QString areaFile;
    std::vector<QPolygonF> areas;
    QRectF boundingBox;
};
}

void CoverageAreaPrivate::loadGeometry()
{
    if (areaFile.isEmpty() || !areas.empty()) {
        return;
    }

    QFile f(StandardPaths::locateFile("networks/geometry/"_L1 + areaFile));
    if (!f.open(QFile::ReadOnly)) {
        qCWarning(Log) << "reading coverage area file failed:" << f.fileName() << f.errorString();
        return;
    }

    const auto doc = QJsonDocument::fromJson(f.readAll());
    areas = GeoJson::readOuterPolygons(doc.object());
    recomputeBoundingBox();
}

void CoverageAreaPrivate::recomputeBoundingBox()
{
    for (const auto &area : areas) {
        boundingBox |= area.boundingRect();
    }
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
    if (d->regions.size() == 1 && d->regions.at(0) == "UN"_L1) {
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
    if (loc.hasCoordinate()) {
        d->loadGeometry();
        if (!d->areas.empty()) {
            if (d->boundingBox.contains({loc.longitude(), loc.latitude()})) {
                return std::any_of(d->areas.begin(), d->areas.end(), [&loc](const auto &area) {
                    return area.containsPoint({loc.longitude(), loc.latitude()}, Qt::WindingFill);
                });
            }
            return false;
        }
    }

    // TODO we could do a more precise check for ISO 3166-2 subdivision codes when available

    if (loc.country().size() == 2 && !d->regions.empty()) {
        if (d->regions.size() == 1 && d->regions.at(0) == "UN"_L1) { // global coverage
            return true;
        }
        return std::binary_search(d->regions.begin(), d->regions.end(), loc.country(), [](const auto &lhs, const auto &rhs) {
            return countryCode(lhs) < countryCode(rhs);
        });
    }

    // if we have nothing to check against, assume the backend can help (otherwise none would trigger)
    return true;
}

bool CoverageArea::coversArea(const QRectF &rect) const
{
    // no information to the contrary means yes, as above
    if (!rect.isValid()) {
        return true;
    }

    d->loadGeometry();
    if (!d->areas.empty()) {
        if (d->boundingBox.intersects(rect)) {
            return std::any_of(d->areas.begin(), d->areas.end(), [rect](const auto &area) {
                return area.intersects(rect);
            });
        }
        return false;
    }

    return true;
}

bool CoverageArea::hasNationWideCoverage(const QString &country) const
{
    return std::binary_search(d->regions.begin(), d->regions.end(), country);
}

CoverageArea CoverageArea::fromJson(const QJsonObject &obj)
{
    CoverageArea ca;
    ca.setRegions(Json::toStringList(obj.value("region"_L1)));
    ca.setUicCompanyCodes(Json::toStringList(obj.value("uicCompanyCodes"_L1)));
    std::sort(ca.d->regions.begin(), ca.d->regions.end());

    ca.d->areaFile = obj.value("areaFile"_L1).toString();
    if (ca.d->areaFile.isEmpty()) {
        ca.d->areas = GeoJson::readOuterPolygons(obj.value("area"_L1).toObject());
        ca.d->recomputeBoundingBox();
    }
    return ca;
}

#include "moc_coveragearea.cpp"

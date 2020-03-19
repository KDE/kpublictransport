/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "indexeddatatable.h"

#include <overpassquery.h>
#include <overpassquerymanager.h>
#include <xmlparser.h>
#include <wikidataquery.h>
#include <wikidataquerymanager.h>

#include <QColor>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>

enum {
    MaxLogoFileSize = 10000, // bytes
    MinBoundingBoxDistance = 1'048'576, // minimum bounding box distance, in 1/1e7-th degree, lines with smaller distances will be discarded, set to yield a 26 bit hash/40 bit shift
};

static constexpr const auto MaxLogoAspectRatio = 2.75;
static constexpr const auto MinLogoAspectRatio = 0.45; // Shanghai Metro is the extreme still valid case with 0.5

enum LineMode { // ordered by accuracy in OSM data, ie. higher value -> higher probability of being the correctly detected mode
    Unknown,
    RapidTransit,
    Tram,
    Subway,
};

struct RouteInfo {
    OSM::Id relId;
    OSM::BoundingBox bbox;
    QString name;
    QColor color;
    LineMode mode = Unknown;
    QString logoName;
    QString wdId;
};

class Generator {
public:
    void processOSMData(OSM::DataSet &&dataSet);
    void augmentFromWikidata();
    void applyWikidataResults(const QJsonObject &entities);
    void verifyImages();
    void verifyImageMetaData(const QJsonObject &images);
    void generateIndex();
    void generateCode(std::map<uint64_t, std::vector<std::size_t>> &&zIndex, uint32_t zShift);

    QIODevice *out = nullptr;
    std::vector<RouteInfo> routes;
    WikidataQueryManager *m_wdMgr = new WikidataQueryManager(QCoreApplication::instance());
};

static LineMode lineModeStringToMode(const QString &s)
{
   if (s == QLatin1String("subway")) {
        return Subway;
    }
    if (s == QLatin1String("tram")) {
        return Tram;
    }
    if (s == QLatin1String("light_rail") || s == QLatin1String("commuter")) {
        return RapidTransit;
    }
    return Unknown;
}

static LineMode determineLineMode(const OSM::Relation &rel)
{
    auto m = lineModeStringToMode(OSM::tagValue(rel, QLatin1String("route_master")));
    if (m != Unknown) return m;

    m = lineModeStringToMode(OSM::tagValue(rel, QLatin1String("route")));
    if (m != Unknown) return m;

    m = lineModeStringToMode(OSM::tagValue(rel, QLatin1String("line")));
    if (m != Unknown) return m;

    m = lineModeStringToMode(OSM::tagValue(rel, QLatin1String("commuter")));
    if (m != Unknown) return m;

    return lineModeStringToMode(OSM::tagValue(rel, QLatin1String("passenger")));
}

static RouteInfo routeInfoFromRelation(const OSM::Relation &rel)
{
    RouteInfo info;
    info.relId = rel.id;
    info.bbox = rel.bbox;
    info.name = OSM::tagValue(rel, QLatin1String("ref"));
    const auto colStr = OSM::tagValue(rel, QLatin1String("colour"));
    if (!colStr.isEmpty()) {
        info.color = QColor(colStr);
    }
    info.wdId = OSM::tagValue(rel, QLatin1String("wikidata"));
    info.mode = determineLineMode(rel);
    return info;
}

static void mergeRouteInfo(RouteInfo &lhs, const RouteInfo &rhs)
{
    if (lhs.color.isValid() && rhs.color.isValid() && lhs.color != rhs.color) {
        qWarning() << "OSM color conflict:" << lhs.relId << rhs.relId << lhs.name << lhs.color.name() << rhs.color.name();
    } else if (rhs.color.isValid()) {
        lhs.color = rhs.color;
    }
    if (!lhs.wdId.isEmpty() && !rhs.wdId.isEmpty() && lhs.wdId != rhs.wdId) {
        qWarning() << "wikidata id conflict:" << lhs.relId << rhs.relId << lhs.name << lhs.wdId << rhs.wdId;
    } else if (!rhs.wdId.isEmpty()) {
        lhs.wdId = rhs.wdId;
    }
    lhs.bbox = OSM::unite(lhs.bbox, rhs.bbox);
    if (lhs.mode != Unknown && rhs.mode != Unknown && lhs.mode != rhs.mode) {
        qWarning() << "OSM mode conflict:" << lhs.relId << lhs.mode << rhs.relId << rhs.mode << lhs.name;
    }
    lhs.mode = std::max(lhs.mode, rhs.mode);
}

void Generator::processOSMData(OSM::DataSet &&dataSet)
{
    qDebug() << "got" << dataSet.relations.size() << "relations from OSM";

    // split relations into route_master elements and route elements
    auto splitIt = std::partition(dataSet.relations.begin(), dataSet.relations.end(), [](const auto &rel) {
        return OSM::tagValue(rel, QLatin1String("type")) == QLatin1String("route_master");
    });
    sort(splitIt, dataSet.relations.end());
    const auto routeMasterCount = std::distance(dataSet.relations.begin(), splitIt);
    qDebug() << "  containing" << routeMasterCount << "route masters and" << (dataSet.relations.size() - routeMasterCount) << "routes";

    // resolve route masters first, and then consider the remaining routes that have no route_master
    for (auto i = 0; i < routeMasterCount; ++i) {
        auto &rel = dataSet.relations[i];
        auto info = routeInfoFromRelation(rel);

        const auto members = std::move(rel.members); // reference will become invalid once we start to modify below
        for (const auto &mem : members) {
            auto memIt = std::lower_bound(dataSet.relations.begin() + routeMasterCount, dataSet.relations.end(), mem.id);
            if (memIt == dataSet.relations.end() || (*memIt).id != mem.id) {
                continue;
            }
            mergeRouteInfo(info, routeInfoFromRelation(*memIt));
            dataSet.relations.erase(memIt);
        }
        routes.push_back(std::move(info));
    }

    // deal with routes without a route master
    qDebug() << "  " << (dataSet.relations.size() - routeMasterCount) << "dangling routes remaining";
    for (auto it = dataSet.relations.begin() + routeMasterCount; it != dataSet.relations.end(); ++it) {
        auto info = routeInfoFromRelation(*it);
        routes.push_back(std::move(info));
    }
    qDebug() << "merged routes:" << routes.size();

    // filter useless routes
    routes.erase(std::remove_if(routes.begin(), routes.end(), [](const auto &info) {
        return info.name.isEmpty() || !info.bbox.isValid() || (!info.color.isValid() && info.wdId.isEmpty()) || info.mode == Unknown;
    }), routes.end());
    qDebug() << "routes after filtering:" << routes.size();

    // check for uniqueness of (bbox, name) - would break indexing and can happen for lines without a route_master relation
    // we assume those to belong together as well and thus merge them to a single line
    for (auto lit = routes.begin(); lit != routes.end(); ++lit) {
        // a merge pass can increase the bbox to include more elements that we previously missed
        // so do this as long as we find things
        while (true) {
            auto dupIt = std::remove_if(lit + 1, routes.end(), [lit](const auto &rhs) {
                return (*lit).name == rhs.name && OSM::intersects((*lit).bbox, rhs.bbox);
            });
            if (dupIt == routes.end()) {
                break;
            }

            for (auto it = dupIt; it != routes.end(); ++it) {
                mergeRouteInfo(*lit, *it);
            }
            routes.erase(dupIt, routes.end());
        }
    }
    qDebug() << "routes after bbox merge:" << routes.size();

    // remove all lines that are too close together, as this blows up the z index too much
    std::sort(routes.begin(), routes.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.name < rhs.name;
    });
    for (auto it = routes.begin(); it != routes.end() && it + 1 != routes.end();) {
        bool removed = false;
        for (auto it2 = it + 1; it2 != routes.end() && (*it).name == (*it2).name; ++it2) {
            const auto dist = std::max(OSM::latitudeDistance((*it).bbox, (*it2).bbox), OSM::longitudeDifference((*it).bbox, (*it2).bbox));
            if (dist < MinBoundingBoxDistance) {
                qDebug() << "Removing close lines:" << (*it).relId << (*it2).relId << (*it).name << dist;
                it2 = routes.erase(it2);
                it = routes.erase(it);
                removed = true;
                break;
            }
        }
        if (!removed) {
            ++it;
        }
    }
    qDebug() << "routes after bbox distance filtering:" << routes.size();

    augmentFromWikidata();
}

void Generator::augmentFromWikidata()
{
    // sort to maximize cache hits of the batches wikidata queries
    std::sort(routes.begin(), routes.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.wdId < rhs.wdId;
    });
    std::vector<QString> wdIds;
    for (const auto &r: routes) {
        if (!r.wdId.isEmpty()) {
            wdIds.push_back(r.wdId);
        }
    }
    qDebug() << "Retrieving" << wdIds.size() << "items from Wikidata";

    auto query = new WikidataEntitiesQuery(m_wdMgr);
    query->setItems(std::move(wdIds));
    QObject::connect(query, &WikidataEntitiesQuery::partialResult, [this](const auto &entities) { applyWikidataResults(entities); });
    QObject::connect(query, &WikidataQuery::finished, [this, query]() mutable {
        if (query->error() != WikidataQuery::NoError) {
            qCritical() << "Wikidata query failed";
            QCoreApplication::exit(1);
            return;
        }
        verifyImages();
    });
    m_wdMgr->execute(query);
}

static std::vector<QVariant> propertyValues(const QJsonObject &entity, const QLatin1String &propName)
{
    std::vector<QVariant> values;

    const auto propA = entity.value(QLatin1String("claims")).toObject().value(propName).toArray();
    for (const auto & propV : propA) {
        const auto valueObj = propV.toObject().value(QLatin1String("mainsnak")).toObject().value(QLatin1String("datavalue")).toObject();
        const auto type = valueObj.value(QLatin1String("type")).toString();
        if (type == QLatin1String("string")) {
            values.push_back(valueObj.value(QLatin1String("value")).toString());
        } else if (type == QLatin1String("wikibase-entityid")) {
            values.push_back(valueObj.value(QLatin1String("value")).toObject().value(QLatin1String("id")).toString());
        }

        // TODO other types
    }

    return values;
}

static QVariant propertyValue(const QJsonObject &entity, const QLatin1String &propName)
{
    const auto values = propertyValues(entity, propName);
    return values.empty() ? QVariant() : values[0];
}

void Generator::applyWikidataResults(const QJsonObject &entities)
{
    const QStringList suspicious_types({
        QStringLiteral("Q43229"), // organization
        QStringLiteral("Q740752"), // transport company
    });

    for (auto it = entities.begin(); it != entities.end(); ++it) {
        const auto rit = std::lower_bound(routes.begin(), routes.end(), it.key(), [](const RouteInfo &lhs, const QString &rhs) {
            return lhs.wdId < rhs;
        });
        if (rit == routes.end() || (*rit).wdId != it.key()) {
            continue; // shouldn't happen...
        }

        // check if this is a plausible type
        const auto instancesOf = propertyValues(it.value().toObject(), QLatin1String("P31"));
        bool found = false;
        for (const auto &instanceOf : instancesOf) {
            if (suspicious_types.contains(instanceOf.toString())) {
                qWarning() << "Suspicious WD types:" << (*rit).name << (*rit).wdId << (*rit).relId << instancesOf;
                found = true;
            }
        }
        if (found) {
            continue;
        }

        // merge information
        const auto color = QColor(QLatin1Char('#') + propertyValue(it.value().toObject(), QLatin1String("P465")).toString());
        if ((*rit).color.isValid() && color.isValid() && (*rit).color != color) {
            qWarning() << "OSM/WD color conflict:" << (*rit).relId << (*rit).wdId << (*rit).name << (*rit).color.name() << color.name();
        } else if (color.isValid()) {
            (*rit).color = color;
        }
        (*rit).logoName = propertyValue(it.value().toObject(), QLatin1String("P154")).toString();
    }
}

void Generator::verifyImages()
{
    std::sort(routes.begin(), routes.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.logoName < rhs.logoName;
    });
    std::vector<QString> imageIds;
    for (const auto &r: routes) {
        if (!r.logoName.isEmpty()) {
            imageIds.push_back(r.logoName);
        }
    }
    qDebug() << "Verifying" << imageIds.size() << "images";

    auto query = new WikidataImageMetadataQuery(m_wdMgr);
    query->setImages(std::move(imageIds));
    QObject::connect(query, &WikidataImageMetadataQuery::partialResult, [this](const auto &metaData) { verifyImageMetaData(metaData); });
    QObject::connect(query, &WikidataQuery::finished, [this, query]() mutable {
        if (query->error() != WikidataQuery::NoError) {
            qCritical() << "Wikidata image metadata query failed";
            QCoreApplication::exit(1);
            return;
        }
        generateIndex();
    });
    m_wdMgr->execute(query);
}

static void clearLogo(std::vector<RouteInfo> &routes, const QString &name)
{
    // we cannot rely on sort order once we have done the first call to this method!
    for (auto &info : routes) {
        if (info.logoName == name) {
            info.logoName.clear();
        }
    }
}

void Generator::verifyImageMetaData(const QJsonObject &images)
{
    const QStringList valid_licenses({
        QStringLiteral("cc0"),
        QStringLiteral("public domain"),
    });

    for (auto it = images.begin(); it != images.end(); ++it) {
        const auto name = it.value().toObject().value(QLatin1String("title")).toString().mid(5);

        const auto imageinfo = it.value().toObject().value(QLatin1String("imageinfo")).toArray();
        if (imageinfo.isEmpty()) {
            continue;
        }

        const auto fileSize = imageinfo.at(0).toObject().value(QLatin1String("size")).toInt();
        if (fileSize > MaxLogoFileSize) {
            qWarning() << "not using logo" << name << "due to file size:" << fileSize;
            clearLogo(routes, name);
            continue;
        }

        const auto width = imageinfo.at(0).toObject().value(QLatin1String("width")).toDouble();
        const auto height = imageinfo.at(0).toObject().value(QLatin1String("height")).toDouble();
        const auto aspectRatio = width / height;
        if (aspectRatio > MaxLogoAspectRatio || aspectRatio < MinLogoAspectRatio) {
            qWarning() << "not using logo" << name << "due to aspect ratio:" << aspectRatio;
            clearLogo(routes, name);
            continue;
        }

        const auto mt = imageinfo.at(0).toObject().value(QLatin1String("mime")).toString();
        if (mt != QLatin1String("image/svg+xml") && mt != QLatin1String("image/png")) {
            qWarning() << "not using logo" << name << "due to mimetype:" << mt;
            clearLogo(routes, name);
            continue;
        }

        const auto extmeta = imageinfo.at(0).toObject().value(QLatin1String("extmetadata")).toObject();
        const auto lic = extmeta.value(QLatin1String("LicenseShortName")).toObject().value(QLatin1String("value")).toString();
        if (!valid_licenses.contains(lic, Qt::CaseInsensitive)) {
            qWarning() << "not using logo" << name << "due to license:" << lic;
            clearLogo(routes, name);
            continue;
        }
    }
}

void Generator::generateIndex()
{
    // find the smallest distance between two bboxes with a name collision
    std::sort(routes.begin(), routes.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.name < rhs.name;
    });
    auto minDist = std::numeric_limits<uint32_t>::max();
    OSM::Id lmin = 0, rmin = 0;
    for (auto lit = routes.begin(); lit != routes.end(); ++lit) { // for each name
        auto rit = std::upper_bound(lit, routes.end(), (*lit).name, [](const auto &lhs, const auto &rhs) { return lhs < rhs.name; });
        if (lit + 1 == rit || rit == routes.end()) { // only a single route with that name
            continue;
        }
        --rit;

        for (; lit != rit; ++lit) {  // for each pair with equal name
            for (auto it = lit + 1; it != rit; ++it) {
                const auto dist = std::max(OSM::latitudeDistance((*lit).bbox, (*it).bbox), OSM::longitudeDifference((*lit).bbox, (*it).bbox));
                if (dist < minDist) {
                    minDist = dist;
                    lmin = (*lit).relId;
                    rmin = (*it).relId;
                }
            }
        }
    }
    qDebug() << "minimum bbox distance is" << minDist << lmin << rmin;
    qDebug() << "z hash size is" << __builtin_clz(minDist) + 1;
    const uint32_t zShift = 32 - (__builtin_clz(minDist) + 1);
    const uint32_t zInc = 1 << zShift;
    const uint32_t zMask = ~(zInc - 1);

    // order routes by OSM id, to increase output stability
    std::sort(routes.begin(), routes.end(), [](const auto &lhs, const auto &rhs) { return lhs.relId < rhs.relId; });
    std::map<uint64_t, std::vector<std::size_t>> zIndex;

    // tile bboxes at the z-level derived from the above minimum distance
    for (auto routeIt = routes.begin(); routeIt != routes.end(); ++routeIt) {
        const uint32_t xMin = (*routeIt).bbox.min.latitude & zMask;
        const uint32_t xMax = ((*routeIt).bbox.max.latitude & zMask) + zInc;
        const uint32_t yMin = (*routeIt).bbox.min.longitude & zMask;
        const uint32_t yMax = ((*routeIt).bbox.max.longitude & zMask) + zInc;
        for (uint32_t x = xMin; x < xMax; x += zInc) {
            for (uint32_t y = yMin; y < yMax; y += zInc) {
                OSM::Coordinate tile(x, y);
                zIndex[tile.z() >> (zShift * 2)].push_back(std::distance(routes.begin(), routeIt));
            }
        }
    }
    qDebug() << "hash buckets:" << zIndex.size();

    // sort route index vectors by name
    for (auto it = zIndex.begin(); it != zIndex.end(); ++it) {
        std::sort((*it).second.begin(), (*it).second.end(), [this](const auto lhs, const auto rhs) {
            return routes[lhs].name < routes[rhs].name;
        });
    }

    generateCode(std::move(zIndex), zShift);
}

void Generator::generateCode(std::map<uint64_t, std::vector<std::size_t>> &&zIndex, uint32_t zShift)
{
    // write header
    out->write(R"(/*
    SPDX-License-Identifier: ODbL-1.0

    Generated code based on data from OpenStreetMap (ODbL) and Wikidata (CC0), do not edit!
*/

#include "linemetadata_p.h"

namespace KPublicTransport {

)");

    // create and write string table
    StringTable strTab;
    for (const auto &route : routes) {
        strTab.addString(route.name);
        strTab.addString(route.logoName);
    }
    strTab.writeCode("line_data_stringtab", out);

    // write route table
    out->write("static const LineMetaDataContent line_data[] = {\n");
    for (const auto &route : routes) {
        out->write("    { ");
        out->write(QByteArray::number((int)strTab.stringOffset(route.name)));
        out->write(", ");
        out->write(QByteArray::number((int)strTab.stringOffset(route.logoName)));
        out->write(", 0x");
        out->write(QByteArray::number(route.color.rgb(), 16));
        out->write(" }, // ");
        out->write(route.name.toUtf8()),
        out->write(" OSM: ");
        out->write(QByteArray::number((long long)route.relId));
        if (!route.wdId.isEmpty()) {
            out->write(" WD: ");
            out->write(route.wdId.toUtf8());
        }
        out->write("\n");
    }
    out->write("};\n\n");

    // write bucket table
    IndexedDataTable<std::vector<std::size_t>> bucketTable;
    for (const auto &zi : zIndex) {
        bucketTable.addEntry(zi.second);
    }
    bucketTable.writeCode("int32_t", "line_data_bucketTable", out, [](const std::vector<std::size_t> &bucket, QIODevice *out) {
        for (const auto i : bucket) {
            out->write(QByteArray::number((int)i));
            out->write(", ");
        }
        out->write("-1,");
    });

    // write z index
    out->write("static constexpr const uint32_t line_data_zShift = ");
    out->write(QByteArray::number(2* zShift));
    out->write(";\n\n");
    out->write("static const LineMetaDataZIndex line_data_zindex[] = {\n");
    for (const auto &zi : zIndex) {
        out->write("    { ");
        out->write(QByteArray::number((qulonglong)zi.first));
        out->write(", ");
        out->write(QByteArray::number((qulonglong)bucketTable.entryOffset(zi.second)));
        out->write(" }, // ");
        OSM::Coordinate coord(zi.first << (zShift * 2));
        out->write(QByteArray::number(coord.latF(), 'g', 4));
        out->write(" x ");
        out->write(QByteArray::number(coord.lonF(), 'g', 4));
        out->write("\n");
    }
    out->write("};\n}\n");

    QCoreApplication::quit();
}

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QCommandLineParser parser;
    parser.addHelpOption();
    QCommandLineOption outFileOption({ QStringLiteral("o") }, QStringLiteral("Output file name"), QStringLiteral("out"));
    parser.addOption(outFileOption);
    QCommandLineOption osmInputOption({ QStringLiteral("i") }, QStringLiteral("OSM input file"),  QStringLiteral("osm-in"));
    parser.addOption(osmInputOption);
    parser.process(app);

    QFile out(parser.value(outFileOption));
    if (!out.open(QFile::WriteOnly)) {
        qCritical() << "Failed to open output file:" << out.errorString();
        return 1;
    }

    Generator generator;
    generator.out = &out;

    OSM::OverpassQueryManager osmMgr;
    OSM::OverpassQuery osmQuery;
    QFile f(QStringLiteral(":/routes.overpassql"));
    if (!f.open(QFile::ReadOnly)) {
        qCritical() << f.errorString();
        return 1;
    }
    osmQuery.setQuery(QString::fromUtf8(f.readAll()));

    // TODO subset for testing only
    osmQuery.setBoundingBox({0.0, 45.0, 15.0, 10.0});
    osmQuery.setTileSize({2.5, 2.5});
    osmQuery.setMinimumTileSize({1.0, 1.0});

    QObject::connect(&osmQuery, &OSM::OverpassQuery::finished, [&osmQuery, &generator]() {
        if (osmQuery.error() != OSM::OverpassQuery::NoError) {
            qCritical() << "Overpass query failed.";
            QCoreApplication::exit(1);
        } else {
            generator.processOSMData(osmQuery.takeResult());
        }
    });

    if (!parser.isSet(osmInputOption)) {
        osmMgr.execute(&osmQuery);
    } else {
        QFile f(parser.value(osmInputOption));
        if (!f.open(QFile::ReadOnly)) {
            qCritical() << "Failed to open OSM input file!" << f.errorString() << f.fileName();
            QCoreApplication::exit(1);
        }
        OSM::DataSet dataSet;
        OSM::XmlParser p(&dataSet);
        p.parse(&f);
        generator.processOSMData(std::move(dataSet));
    }

    return QCoreApplication::exec();
}

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
#include "lineinfo.h"

#include "../lib/datatypes/linecompare_p.h"

#include <osm/xmlparser.h>
#include <osm/ztile.h>

#include <wikidataquery.h>
#include <wikidataquerymanager.h>

#include <QColor>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonObject>

#include <set>

enum {
    MaxLogoFileSize = 10000, // bytes
};

static constexpr const auto MaxLogoAspectRatio = 2.75;
static constexpr const auto MinLogoAspectRatio = 0.45; // Shanghai Metro is the extreme still valid case with 0.5

static bool isSameLine(const LineInfo &lhs, const LineInfo &rhs)
{
    return lhs.mode == rhs.mode && KPublicTransport::Internal::isSameLineName(lhs.name, rhs.name);
}

class Generator {
public:
    void processOSMData(OSM::DataSet &&dataSet);
    void augmentFromWikidata();
    void applyWikidataResults(const QJsonObject &entities);
    void augmentProductsFromWikidata();
    void applyWikidataProductResults(const QJsonObject &entities);
    void verifyImages();
    void verifyImageMetaData(const QJsonObject &images);

    void generateQuadTree();
    bool resolveOneBottomUpConflict();
    void writeCode();

    void insertToBucket(OSM::ZTile tile, std::size_t lineIdx);

    QIODevice *out = nullptr;
    std::vector<LineInfo> lines;
    WikidataQueryManager *m_wdMgr = new WikidataQueryManager(QCoreApplication::instance());
    std::set<QString> wdPartOfIds;

    std::map<OSM::ZTile, std::vector<size_t>> zQuadTree;
};

void Generator::insertToBucket(OSM::ZTile tile, std::size_t lineIdx)
{
    auto &bucket = zQuadTree[tile];
    if (std::find(bucket.begin(), bucket.end(), lineIdx) == bucket.end()) {
        bucket.push_back(lineIdx);
    } else {
        // all tree transforms below should not create duplicates
        assert(false);
    }
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
        auto info = LineInfo::fromRelation(rel);
        if (info.name.isEmpty()) {
            continue;
        }

        const auto members = std::move(rel.members); // reference will become invalid once we start to modify below
        for (const auto &mem : members) {
            auto memIt = std::lower_bound(dataSet.relations.begin() + routeMasterCount, dataSet.relations.end(), mem.id);
            if (memIt == dataSet.relations.end() || (*memIt).id != mem.id) {
                continue;
            }
            LineInfo::merge(info, LineInfo::fromRelation(*memIt));
            dataSet.relations.erase(memIt);
        }
        lines.push_back(std::move(info));
    }

    // deal with routes without a route master
    qDebug() << "  " << (dataSet.relations.size() - routeMasterCount) << "dangling routes remaining";
    for (auto it = dataSet.relations.begin() + routeMasterCount; it != dataSet.relations.end(); ++it) {
        auto info = LineInfo::fromRelation(*it);
        if (info.name.isEmpty()) {
            continue;
        }
        lines.push_back(std::move(info));
    }
    qDebug() << "merged lines:" << lines.size();

    // filter useless lines - ie. those that don't contain useful information and have no wikidata id to fill the missing gaps
    lines.erase(std::remove_if(lines.begin(), lines.end(), [](const auto &info) {
        return !LineInfo::isUseful(info) && info.wdId.isEmpty();
    }), lines.end());
    qDebug() << "lines after filtering OSM data:" << lines.size();

    // check for uniqueness of (bbox, name) - would break indexing and can happen for lines without a route_master relation
    // we assume those to belong together as well and thus merge them to a single line
    for (auto lit = lines.begin(); lit != lines.end(); ++lit) {
        // a merge pass can increase the bbox to include more elements that we previously missed
        // so do this as long as we find things
        while (true) {
            auto dupIt = std::partition(lit + 1, lines.end(), [lit](const auto &rhs) {
                return !isSameLine(*lit, rhs) || !OSM::intersects((*lit).bbox, rhs.bbox);
            });
            if (dupIt == lines.end()) {
                break;
            }

            for (auto it = dupIt; it != lines.end(); ++it) {
                LineInfo::merge(*lit, *it);
            }
            lines.erase(dupIt, lines.end());
        }
    }
    qDebug() << "lines after bbox merge:" << lines.size();

    augmentFromWikidata();
}

void Generator::augmentFromWikidata()
{
    // sort to maximize cache hits of the batches wikidata queries
    std::sort(lines.begin(), lines.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.wdId < rhs.wdId;
    });
    std::vector<QString> wdIds;
    for (const auto &r: lines) {
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

        augmentProductsFromWikidata();
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

static struct {
    const char *entity;
    LineInfo::Mode mode;
} const wd_type_to_mode_map[] = {
    { "Q1412403", LineInfo::RapidTransit }, // commuter rail
    { "Q1192191", LineInfo::RapidTransit }, // airport rail link
    { "Q50331459", LineInfo::RapidTransit }, // S-Bahn line
    { "Q95723", LineInfo::RapidTransit }, // S-Bahn
    { "Q129172", LineInfo::LongDistance }, // ICE
    { "Q15145593", LineInfo::Tram }, // tram line
// TODO enable once we enforce a minimum quad tree depth, otherwise this breaks the Randa unit test
//     { "Q2572054", LineInfo::RapidTransit }, // Transilien (multiple variants)
//     { "Q732778", LineInfo::RapidTransit }, // Transilien
//     { "Q2571458", LineInfo::RapidTransit }, // Transilien
//     { "Q2571977", LineInfo::RapidTransit }, // Transilien
//     { "/Q373725", LineInfo::RapidTransit }, // Transilien
};

static LineInfo::Mode modeFromWikidataType(const QString &type)
{
    LineInfo::Mode mode = LineInfo::Unknown;
    for (const auto &modeMap : wd_type_to_mode_map) {
        if (type == QLatin1String(modeMap.entity)) {
            mode = std::max(modeMap.mode, mode);
        }
    }
    return mode;
}

static const char* wd_excluded_types[] {
    "Q43229", // organization
    "Q740752", // transport company
    "Q928830", // metro station
    "Q4830453", // business
    "Q7835189", // transit district
    "Q249556", // railway company
    "Q17377208", // train operating company
};

static bool isExcludedWikidataType(const QString &type)
{
    return std::find_if(std::begin(wd_excluded_types), std::end(wd_excluded_types), [type](const char *t) {
        return QLatin1String(t) == type;
    }) != std::end(wd_excluded_types);
}

static const char* wd_product_types[] {
    "Q5503", // rapid transit
    "Q95723", // S-Bahn
    "Q15640053", // tram system
    "Q1412403", // commuter rail
    "Q2140646", // Stadtbahn
    "Q1268865", // light rail
};

static bool isWikidataProductType(const QString &type)
{
    return std::find_if(std::begin(wd_product_types), std::end(wd_product_types), [type](const char *t) {
        return QLatin1String(t) == type;
    }) != std::end(wd_product_types);
}

void Generator::applyWikidataResults(const QJsonObject &entities)
{
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        auto rit = std::lower_bound(lines.begin(), lines.end(), it.key(), [](const LineInfo &lhs, const QString &rhs) {
            return lhs.wdId < rhs;
        });
        // wikidata line elements shouldn't occur for multiple lines, but in some cases
        // OSM points to product or network elements instead, and those can occur once per line
        for (; rit != lines.end() && (*rit).wdId == it.key(); ++rit) {
            // check if this is a plausible type
            const auto instancesOf = propertyValues(it.value().toObject(), QLatin1String("P31"));
            bool found = false;
            LineInfo::Mode mode = LineInfo::Unknown;
            for (const auto &instanceOf : instancesOf) {
                const auto type = instanceOf.toString();
                if (isExcludedWikidataType(type)) {
                    qWarning() << "Suspicious WD types:" << (*rit) << instancesOf;
                    found = true;
                }
                mode = std::max(mode, modeFromWikidataType(type));

                if (isWikidataProductType(type)) { // wikidata link in OSM is pointing to the product, not the line it seems
                    wdPartOfIds.insert(it.key());
                    (*rit).wdProducts.push_back(it.key());
                }
            }
            if (found) {
                break;
            }

            // collect possible product types
            const auto partOfIds = propertyValues(it.value().toObject(), QLatin1String("P361"));
            for (const auto &id : partOfIds) {
                wdPartOfIds.insert(id.toString());
                (*rit).wdProducts.push_back(id.toString());

                mode = std::max(mode, modeFromWikidataType(id.toString()));
            }

            // merge information
            const auto color = QColor(QLatin1Char('#') + propertyValue(it.value().toObject(), QLatin1String("P465")).toString());
            if ((*rit).color.isValid() && color.isValid() && (*rit).color != color) {
                qWarning() << "OSM/WD color conflict:" << (*rit) << color.name();
            } else if (color.isValid()) {
                (*rit).color = color;
            }
            (*rit).logoName = propertyValue(it.value().toObject(), QLatin1String("P154")).toString();
            if ((*rit).mode != LineInfo::Unknown && mode != LineInfo::Unknown && (*rit).mode != mode) {
                qWarning() << "OSM/WD mode conflict:" << (*rit) << mode;
            } else {
                (*rit).mode = std::max((*rit).mode, mode);
            }
        }
    }
}

void Generator::augmentProductsFromWikidata()
{
    std::vector<QString> wdIds;
    for (const auto &id: wdPartOfIds) {
        if (!id.isEmpty()) {
            wdIds.push_back(id);
        }
    }
    qDebug() << "Retrieving" << wdIds.size() << "product items from Wikidata";

    auto query = new WikidataEntitiesQuery(m_wdMgr);
    query->setItems(std::move(wdIds));
    QObject::connect(query, &WikidataEntitiesQuery::partialResult, [this](const auto &entities) { applyWikidataProductResults(entities); });
    QObject::connect(query, &WikidataQuery::finished, [this, query]() mutable {
        if (query->error() != WikidataQuery::NoError) {
            qCritical() << "Wikidata product query failed";
            QCoreApplication::exit(1);
            return;
        }

        verifyImages();
    });
    m_wdMgr->execute(query);
}

void Generator::applyWikidataProductResults(const QJsonObject &entities)
{
    for (auto it = entities.begin(); it != entities.end(); ++it) {
        // check if this is a plausible type
        const auto instancesOf = propertyValues(it.value().toObject(), QLatin1String("P31"));
        LineInfo::Mode mode = LineInfo::Unknown;
        bool found = false;
        for (const auto &instanceOf : instancesOf) {
            const auto type = instanceOf.toString();
            if (isWikidataProductType(type)) {
                found = true;
            }
            mode = std::max(mode, modeFromWikidataType(type));
        }
        if (!found && !std::all_of(instancesOf.begin(), instancesOf.end(), [](const auto &v) { return isExcludedWikidataType(v.toString()); })) {
            qDebug().nospace().noquote() << "Product https://www.wikidata.org/wiki/" << it.key() << " is of unknown type " << instancesOf;
        }
        if (!found) {
            continue;
        }


        // retrieve logo and find the lines this is for
        const auto logoName = propertyValue(it.value().toObject(), QLatin1String("P154")).toString();
        if (logoName.isEmpty() && mode == LineInfo::Unknown) {
            continue;
        }
        for (auto &line : lines) {
            if (!line.wdProducts.contains(it.key())) {
                continue;
            }

            if (line.mode == LineInfo::Unknown) {
                line.mode = mode;
            }

            if (line.productLogoName.isEmpty() || (line.logoName == line.productLogoName)) {
                line.productLogoName = logoName;
            } else if (line.productLogoName != logoName) {
                qWarning() << "Product logo name conflict:" << line << line.productLogoName << logoName;
            }
        }
    }
}

void Generator::verifyImages()
{
    std::sort(lines.begin(), lines.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.logoName < rhs.logoName;
    });
    std::vector<QString> imageIds;
    for (const auto &r: lines) {
        if (!r.logoName.isEmpty() && LineInfo::isUseful(r)) {
            imageIds.push_back(r.logoName);
        }
        if (!r.productLogoName.isEmpty() && LineInfo::isUseful(r)) {
            imageIds.push_back(r.productLogoName);
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

        // filter lines still missing data
        lines.erase(std::remove_if(lines.begin(), lines.end(), [](const auto &info) {
            if (!LineInfo::isUseful(info)) {
                qDebug() << "dropping" << info;
            }
            return !LineInfo::isUseful(info);
        }), lines.end());
        qDebug() << "lines after Wikidata filtering:" << lines.size();

        generateQuadTree();
    });
    m_wdMgr->execute(query);
}

static void clearLogo(std::vector<LineInfo> &lines, const QString &name)
{
    // we cannot rely on sort order once we have done the first call to this method!
    for (auto &info : lines) {
        if (info.logoName == name) {
            info.logoName.clear();
        }
        if (info.productLogoName == name) {
            info.productLogoName.clear();
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
            clearLogo(lines, name);
            continue;
        }

        const auto width = imageinfo.at(0).toObject().value(QLatin1String("width")).toDouble();
        const auto height = imageinfo.at(0).toObject().value(QLatin1String("height")).toDouble();
        const auto aspectRatio = width / height;
        if (aspectRatio > MaxLogoAspectRatio || aspectRatio < MinLogoAspectRatio) {
            qWarning() << "not using logo" << name << "due to aspect ratio:" << aspectRatio;
            clearLogo(lines, name);
            continue;
        }

        const auto mt = imageinfo.at(0).toObject().value(QLatin1String("mime")).toString();
        if (mt != QLatin1String("image/svg+xml") && mt != QLatin1String("image/png")) {
            qWarning() << "not using logo" << name << "due to mimetype:" << mt;
            clearLogo(lines, name);
            continue;
        }

        const auto extmeta = imageinfo.at(0).toObject().value(QLatin1String("extmetadata")).toObject();
        const auto lic = extmeta.value(QLatin1String("LicenseShortName")).toObject().value(QLatin1String("value")).toString();
        if (!valid_licenses.contains(lic, Qt::CaseInsensitive)) {
            qWarning() << "not using logo" << name << "due to license:" << lic;
            clearLogo(lines, name);
            continue;
        }
    }
}

void Generator::generateQuadTree()
{
    // order lines by OSM id, to increase output stability
    std::sort(lines.begin(), lines.end(), [](const auto &lhs, const auto &rhs) { return lhs.relId < rhs.relId; });

    // initialize quad tree by smallest single tile containing the entire line bbox
    for (auto lineIt = lines.begin(); lineIt != lines.end(); ++lineIt) {
        insertToBucket(OSM::ztileFromBoundingBox((*lineIt).bbox), std::distance(lines.begin(), lineIt));
    }
    qDebug() << "initial tiles:" << zQuadTree.size();

    // collision resolution
    // this is done in two steps: bottom-up and top-down
    // bottom-up means that for each tile/line we check if there is a parent tile with a conflicting line, and if so, we
    // propagate that line down to the same level
    // this is done in a rather crude brute-force way, but it gets the job done
    while(resolveOneBottomUpConflict()) {}
    qDebug() << "tiles after bottom-up conflict resolution:" << zQuadTree.size();

    // top-down means we look at conflicts inside a given tile, and propagate the conflicting lines down
    for (auto tileIt = zQuadTree.begin(); tileIt != zQuadTree.end(); ++tileIt) {
        if ((*tileIt).second.size() <= 1) {
            continue;
        }
        // check for name collisions
        for (auto lit = (*tileIt).second.end(); lit != (*tileIt).second.begin();) {
            const auto lend = lit;
            const auto firstIdx = (*tileIt).second.front();
            lit = std::partition((*tileIt).second.begin(), lend, [this, firstIdx](const auto &lineIdx) {
                return !isSameLine(lines[firstIdx], lines[lineIdx]);
            });

            // must not happen if isSameLineName(x, x) == true holds
            assert(lit != lend);

            if (lit + 1 == lend) { // only a single line with that name
                continue;
            }

            // insert subtiles, if they actually contain the line bbox
            qDebug() << "subdividing" << lines[*lit].name << lines[*lit].bbox << lines[*lit].relId << std::distance(lit, lend) << (*lit) << (*tileIt).first.depth << (*tileIt).first.z;
            for (auto it = lit; it != lend; ++it) {
                for (auto subtile : (*tileIt).first.quadSplit()) {
                    if (subtile.intersects(lines[*it].bbox)) {
                        insertToBucket(subtile, *it);
                    }
                }
            }

            // remove current entries
            lit = (*tileIt).second.erase(lit, lend);
        }
    }
    qDebug() << "tiles after top-down conflict resolution:" << zQuadTree.size();

    // remove empty buckets, and sort the non-empty ones for output stability
    for (auto tileIt = zQuadTree.begin(); tileIt != zQuadTree.end();) {
        if ((*tileIt).second.empty()) {
            tileIt = zQuadTree.erase(tileIt);
        } else {
            std::sort((*tileIt).second.begin(), (*tileIt).second.end(), [this](const auto lhs, const auto rhs) {
                return lines[lhs].name < lines[rhs].name;
            });

            ++tileIt;
        }
    }
    qDebug() << "tiles remaining after cleanup:" << zQuadTree.size();

    writeCode();
}

bool Generator::resolveOneBottomUpConflict()
{
    for (auto tileIt = zQuadTree.rbegin(); tileIt != zQuadTree.rend(); ++tileIt) {
        for (auto lineIt = (*tileIt).second.begin(); lineIt != (*tileIt).second.end(); ++lineIt) {
            auto parentTile = (*tileIt).first.parent();
            while (parentTile.depth < 32) {
                const auto parentTileIt = zQuadTree.find(parentTile);
                if (parentTileIt != zQuadTree.end()) {
                    auto conflictIt = std::find_if((*parentTileIt).second.begin(), (*parentTileIt).second.end(), [this, lineIt](const auto lhs) {
                        return isSameLine(lines[lhs], lines[*lineIt]);
                    });
                    if (conflictIt != (*parentTileIt).second.end()) {
                        qDebug() << "propagating down:" << lines[*conflictIt].name << parentTile.z << parentTile.depth;
                        auto splitTile = parentTile;
                        while (splitTile.depth > (*tileIt).first.depth) {
                            for (auto subtile : splitTile.quadSplit()) {
                                if (subtile.intersects((*tileIt).first)) {
                                    splitTile = subtile;
                                } else if (subtile.intersects(lines[*conflictIt].bbox)) {
                                    insertToBucket(subtile, *conflictIt);
                                }
                            }
                        }
                        if (splitTile.intersects(lines[*conflictIt].bbox)) {
                            insertToBucket(splitTile, *conflictIt);
                        }
                        (*parentTileIt).second.erase(conflictIt);
                        return true;
                    }
                }
                parentTile = parentTile.parent();
            }
        }
    }
    return false;
}

static QByteArray modeToString(LineInfo::Mode mode)
{
    switch (mode) {
        case LineInfo::Tram:
            return "LineMetaDataContent::Tramway";
        case LineInfo::Subway:
            return "LineMetaDataContent::Subway";
        case LineInfo::RapidTransit:
            return "LineMetaDataContent::RapidTransit";
        default:
            assert(false);
    }
}

void Generator::writeCode()
{
    // write header
    out->write(R"(/*
    SPDX-License-Identifier: ODbL-1.0

    Generated code based on data from OpenStreetMap (ODbL) and Wikidata (CC0), do not edit!
*/

#include "linemetadata_p.h"

namespace KPublicTransport {

)");

    // create and write string tables
    // name and logo are separated to achieve smaller index values (and thus need less bits for storage)
    // this can be done as due to file extensions on the logos we will never be able to apply suffix compression here
    StringTable nameStrTab;
    StringTable logoStrTab;
    for (const auto &line : lines) {
        nameStrTab.addString(line.name);
        logoStrTab.addString(line.logoName);
        logoStrTab.addString(line.productLogoName);
    }
    nameStrTab.writeCode("line_name_stringtab", out);
    logoStrTab.writeCode("line_logo_stringtab", out);
    // create a symbolic name for the common no logo case (reduces diff on changes)
    out->write("static const constexpr auto NoLogo = ");
    out->write(QByteArray::number((int)logoStrTab.stringOffset(QString())));
    out->write(";\n\n");

    // write line table
    out->write("static const constexpr LineMetaDataContent line_data[] = {\n");
    for (const auto &line : lines) {
        out->write("    { ");
        out->write(QByteArray::number((int)nameStrTab.stringOffset(line.name)));
        out->write(", ");
        if (!line.logoName.isEmpty()) {
            out->write(QByteArray::number((int)logoStrTab.stringOffset(line.logoName)));
        } else {
            out->write("NoLogo");
        }
        out->write(", ");
        if (!line.productLogoName.isEmpty()) {
            out->write(QByteArray::number((int)logoStrTab.stringOffset(line.productLogoName)));
        } else {
            out->write("NoLogo");
        }
        out->write(", ");
        out->write(modeToString(line.mode));
        out->write(", Color{");
        if (line.color.isValid()) {
            out->write("0x");
            const auto col = QByteArray::number(line.color.rgb() & 0xffffff, 16);
            out->write(QByteArray(6 - col.size(), '0'));
            out->write(col);
        }
        out->write("} }, // ");
        out->write(line.name.toUtf8()),
        out->write(" OSM: ");
        out->write(QByteArray::number((long long)line.relId));
        if (!line.wdId.isEmpty()) {
            out->write(" WD: ");
            out->write(line.wdId.toUtf8());
        }
        out->write(" ");
        out->write(QByteArray::number(line.bbox.min.latF(), 'g', 4));
        out->write(", ");
        out->write(QByteArray::number(line.bbox.min.lonF(), 'g', 4));
        out->write(" x ");
        out->write(QByteArray::number(line.bbox.max.latF(), 'g', 4));
        out->write(", ");
        out->write(QByteArray::number(line.bbox.max.lonF(), 'g', 4));
        out->write("\n");
    }
    out->write(R"(};

static constexpr const auto line_data_count = sizeof(line_data) / sizeof(LineMetaDataContent);

static inline constexpr uint16_t Bucket(uint16_t index) { return line_data_count + index; }

)");

    // write bucket table
    IndexedDataTable<std::vector<std::size_t>> bucketTable;
    for (const auto &zi : zQuadTree) {
        if (zi.second.size() > 1) {
            bucketTable.addEntry(zi.second);
        }
    }
    bucketTable.writeCode("int16_t", "line_data_bucketTable", out, [](const std::vector<std::size_t> &bucket, QIODevice *out) {
        for (const auto i : bucket) {
            out->write(QByteArray::number((int)i));
            out->write(", ");
        }
        out->write("-1,");
    });

    // write quad tree depth offsets
    out->write("static const constexpr LineMetaDataQuadTreeDepthIndex line_data_depthOffsets[] = {\n");
    int offset = -1;
    uint8_t lastDepth = 0;
    for (const auto &zi : zQuadTree) {
        ++offset;
        if (lastDepth == zi.first.depth) {
            continue;
        }
        lastDepth = zi.first.depth;
        out->write("    { ");
        out->write(QByteArray::number(lastDepth));
        out->write(", ");
        out->write(QByteArray::number((qulonglong)offset));
        out->write(" },\n");
    }
    out->write("};\n\n");

    // write quad tree
    out->write("static const constexpr LineMetaDataZIndex line_data_zquadtree[] = {\n");
    for (const auto &zi : zQuadTree) {
        out->write("    { ");
        out->write(QByteArray::number((qulonglong)zi.first.z));
        out->write(", ");
        if (zi.second.size() == 1) {
            out->write(QByteArray::number((qulonglong)zi.second[0]));
        } else {
            out->write("Bucket(");
            out->write(QByteArray::number((qulonglong)bucketTable.entryOffset(zi.second)));
            out->write(")");
        }
        out->write(" }, // ");
        out->write(QByteArray::number(zi.first.boundingBox().min.latF(), 'g', 4));
        out->write(", ");
        out->write(QByteArray::number(zi.first.boundingBox().min.lonF(), 'g', 4));
        out->write(" x ");
        out->write(QByteArray::number(zi.first.boundingBox().max.latF(), 'g', 4));
        out->write(", ");
        out->write(QByteArray::number(zi.first.boundingBox().max.lonF(), 'g', 4));
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

    QFile f(parser.value(osmInputOption));
    if (!f.open(QFile::ReadOnly)) {
        qCritical() << "Failed to open OSM input file!" << f.errorString() << f.fileName();
        QCoreApplication::exit(1);
    }
    OSM::DataSet dataSet;
    OSM::XmlParser p(&dataSet);
    p.parse(&f);

    Generator generator;
    generator.out = &out;
    generator.processOSMData(std::move(dataSet));

    return QCoreApplication::exec();
}

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

#include <osm/overpassquery.h>
#include <osm/overpassquerymanager.h>
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

enum {
    MaxLogoFileSize = 10000, // bytes
};

static constexpr const auto MaxLogoAspectRatio = 2.75;
static constexpr const auto MinLogoAspectRatio = 0.45; // Shanghai Metro is the extreme still valid case with 0.5

class Generator {
public:
    void processOSMData(OSM::DataSet &&dataSet);
    void augmentFromWikidata();
    void applyWikidataResults(const QJsonObject &entities);
    void verifyImages();
    void verifyImageMetaData(const QJsonObject &images);

    void generateQuadTree();
    bool resolveOneBottomUpConflict();
    void writeCode();

    QIODevice *out = nullptr;
    std::vector<LineInfo> lines;
    WikidataQueryManager *m_wdMgr = new WikidataQueryManager(QCoreApplication::instance());

    std::map<OSM::ZTile, std::vector<size_t>> zQuadTree;
};

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
                return (*lit).name != rhs.name || !OSM::intersects((*lit).bbox, rhs.bbox);
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

static struct {
    const char *entity;
    LineInfo::Mode mode;
} const wd_type_to_mode_map[] = {
    { "Q1412403", LineInfo::RapidTransit }, // commuter rail
    { "Q1192191", LineInfo::RapidTransit }, // airport rail link
    { "Q50331459", LineInfo::RapidTransit }, // S-Bahn line
    { "Q129172", LineInfo::LongDistance }, // ICE
    { "Q15145593", LineInfo::Tram }, // tram line
};

void Generator::applyWikidataResults(const QJsonObject &entities)
{
    const QStringList suspicious_types({
        QStringLiteral("Q43229"), // organization
        QStringLiteral("Q740752"), // transport company
        QStringLiteral("Q928830"), // metro station
        QStringLiteral("Q4830453"), // business
    });

    for (auto it = entities.begin(); it != entities.end(); ++it) {
        const auto rit = std::lower_bound(lines.begin(), lines.end(), it.key(), [](const LineInfo &lhs, const QString &rhs) {
            return lhs.wdId < rhs;
        });
        if (rit == lines.end() || (*rit).wdId != it.key()) {
            continue; // shouldn't happen...
        }

        // check if this is a plausible type
        const auto instancesOf = propertyValues(it.value().toObject(), QLatin1String("P31"));
        bool found = false;
        LineInfo::Mode mode = LineInfo::Unknown;
        for (const auto &instanceOf : instancesOf) {
            const auto type = instanceOf.toString();
            if (suspicious_types.contains(type)) {
                qWarning() << "Suspicious WD types:" << (*rit).name << (*rit).wdId << (*rit).relId << instancesOf;
                found = true;
            }
            for (const auto &modeMap : wd_type_to_mode_map) {
                if (type == QLatin1String(modeMap.entity)) {
                    mode = std::max(modeMap.mode, mode);
                    break;
                }
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
        if ((*rit).mode != LineInfo::Unknown && mode != LineInfo::Unknown && (*rit).mode != mode) {
            qWarning() << "OSM/WD mode conflict:" << (*rit).relId << (*rit).wdId << (*rit).name << (*rit).mode << mode;
        } else {
            (*rit).mode = std::max((*rit).mode, mode);
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
        zQuadTree[OSM::ztileFromBoundingBox((*lineIt).bbox)].push_back(std::distance(lines.begin(), lineIt));
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
        // check for name collisions
        for (auto lit = (*tileIt).second.end(); lit != (*tileIt).second.begin();) {
            const auto lend = lit;
            lit = std::partition((*tileIt).second.begin(), lend, [this, tileIt](const auto &lineIdx) {
                return !KPublicTransport::Internal::isSameLineName(lines[*((*tileIt).second.begin())].name, lines[lineIdx].name);
            });

            if (lit + 1 == lend) { // only a single line with that name
                continue;
            }

            // insert subtiles, if they actually contain the line bbox
            qDebug() << "subdividing" << lines[*lit].name << lines[*lit].bbox << lines[*lit].relId << std::distance(lit, lend) << (*lit) << (*tileIt).first.depth << (*tileIt).first.z;
            for (auto it = lit; it != lend; ++it) {
                for (auto subtile : (*tileIt).first.quadSplit()) {
                    if (subtile.intersects(lines[*it].bbox)) {
                        zQuadTree[subtile].push_back(*it);
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
                        return KPublicTransport::Internal::isSameLineName(lines[lhs].name, lines[*lineIt].name);
                    });
                    if (conflictIt != (*parentTileIt).second.end()) {
                        qDebug() << "propagating down:" << lines[*conflictIt].name << parentTile.z << parentTile.depth;
                        auto splitTile = parentTile;
                        while (splitTile.depth > (*tileIt).first.depth) {
                            for (auto subtile : splitTile.quadSplit()) {
                                if (subtile.intersects((*tileIt).first)) {
                                    splitTile = subtile;
                                } else if (subtile.intersects(lines[*lineIt].bbox)) {
                                    zQuadTree[subtile].push_back(*lineIt);
                                }
                            }
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

    // create and write string table
    StringTable strTab;
    for (const auto &line : lines) {
        strTab.addString(line.name);
        strTab.addString(line.logoName);
    }
    strTab.writeCode("line_data_stringtab", out);

    // write line table
    out->write("static const constexpr LineMetaDataContent line_data[] = {\n");
    for (const auto &line : lines) {
        out->write("    { ");
        out->write(QByteArray::number((int)strTab.stringOffset(line.name)));
        out->write(", ");
        out->write(QByteArray::number((int)strTab.stringOffset(line.logoName)));
        out->write(", 0x");
        out->write(QByteArray::number(line.color.rgb(), 16));
        out->write(" }, // ");
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
    out->write("};\n\n");

    // write bucket table
    IndexedDataTable<std::vector<std::size_t>> bucketTable;
    for (const auto &zi : zQuadTree) {
        bucketTable.addEntry(zi.second);
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
        out->write(QByteArray::number((qulonglong)bucketTable.entryOffset(zi.second)));
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

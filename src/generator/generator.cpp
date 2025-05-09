/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "indexeddatatable.h"
#include "lineinfo.h"

#include "../lib/datatypes/linecompare_p.h"

#include <osm/io.h>
#include <osm/ztile.h>

#include <wikidataquery.h>
#include <wikidataquerymanager.h>

#include <QColor>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>

#include <set>

using namespace Qt::Literals::StringLiterals;

namespace wd = Wikidata;

enum {
    MaxLogoFileSize = 25000, // bytes
    QuadTreeDepthLimit = 16, // we don't want to use more than 32 bit
};

static constexpr const auto MaxLogoAspectRatio = 2.75;
static constexpr const auto MinLogoAspectRatio = 0.45; // Shanghai Metro is the extreme still valid case with 0.5

static constexpr const auto MinTileCoverage = 0.1;

static bool isCompatibleMode(LineInfo::Mode lhs, LineInfo::Mode rhs)
{
    if (lhs == rhs || lhs == LineInfo::Unknown || rhs == LineInfo::Unknown) {
        return true;
    }
    if ((lhs == LineInfo::LocalTrain && rhs == LineInfo::RapidTransit) || (lhs == LineInfo::RapidTransit && rhs == LineInfo::LocalTrain)) {
        return true;
    }
    if (lhs == LineInfo::Train) {
        return rhs == LineInfo::LocalTrain
            || rhs == LineInfo::LongDistance
            || rhs == LineInfo::RapidTransit;
    }
    if (rhs == LineInfo::Train) {
        return lhs == LineInfo::LocalTrain
            || lhs == LineInfo::LongDistance
            || lhs == LineInfo::RapidTransit;
    }

    return false;
}

static bool isSameLine(const LineInfo &lhs, const LineInfo &rhs)
{
    return isCompatibleMode(lhs.mode, rhs.mode)
        && KPublicTransport::Internal::isSameLineName(lhs.name, rhs.name, KPublicTransport::Internal::StrictCompare);
}

class Generator {
public:
    void processOSMData(OSM::DataSet &&dataSet);
    void augmentFromWikidata();
    void applyWikidataResults(std::vector<wd::Item> &&entities);
    void augmentProductsFromWikidata();
    void applyWikidataProductResults(std::vector<wd::Item> &&entities);
    void applyWikidataProductResults();
    void verifyImages();
    void verifyImageMetaData(std::vector<wd::Image> &&images);
    void verifyImageMetaData(QStringList &logos);
    void verifyImageMetaData();

    void generateQuadTree();
    bool resolveOneBottomUpConflict();
    void writeCode();

    void insertToBucket(OSM::ZTile tile, std::size_t lineIdx);

    QIODevice *out = nullptr;
    std::vector<LineInfo> lines;
    Wikidata::QueryManager *m_wdMgr = new Wikidata::QueryManager(QCoreApplication::instance());
    std::set<wd::Q> wdPartOfIds;
    std::map<wd::Q, wd::Item> wdItems;
    std::map<QString, wd::Image> wdImages;

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
    // expand multi-line relations
    for (auto it = dataSet.relations.begin(); it != dataSet.relations.end();) {
        auto ref = OSM::tagValue(*it, "ref");
        ref.replace(',', ';'); // wrong ref separator syntax, occurs rarely
        if (!ref.contains(';')) {
            ++it;
            continue;
        }

        const auto refs = ref.split(';');
        for (const auto &ref : refs) {
            if (ref.isEmpty()) {
                continue;
            }
            auto rel = *it;
            const auto tagKey = dataSet.makeTagKey("ref", OSM::DataSet::StringIsPersistent);
            OSM::setTagValue(rel, tagKey, QByteArray(ref));
            dataSet.relations.push_back(rel);
        }
        it = dataSet.relations.erase(it);
    }
    qDebug() << "OSM relations after ref split:" << dataSet.relations.size();

    // split relations into route_master elements and route elements
    auto splitIt = std::partition(dataSet.relations.begin(), dataSet.relations.end(), [](const auto &rel) {
        return OSM::tagValue(rel, "type") == "route_master";
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
        if (!LineInfo::isUseful(info) && !info.wdId.isValid() && info.mode != LineInfo::LongDistance) {
            qDebug() << "dropping" << info;
        }
        return !LineInfo::isUseful(info) && !info.wdId.isValid();
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
                qDebug() << "  merging:" << *lit << "with" << *it;
                LineInfo::merge(*lit, *it);
            }
            lines.erase(dupIt, lines.end());
        }
    }
    qDebug() << "lines after bbox merge:" << lines.size();

    // check for uniqueness of Wikidata reference, even with non-intersecting bboxes
    // can help to fix broken/split routes
    for (auto lit = lines.begin(); lit != lines.end(); ++lit) {
        if (!(*lit).wdId.isValid()) {
            continue;
        }
        auto dupIt = std::partition(std::next(lit), lines.end(), [lit](const auto &rhs) {
            return !isSameLine(*lit, rhs) || (*lit).wdId != rhs.wdId;
        });
        if (dupIt == lines.end()) {
            continue;
        }

        for (auto it = dupIt; it != lines.end(); ++it) {
            qDebug() << "  merging:" << *lit << "with" << *it;
            LineInfo::merge(*lit, *it);
        }
        lines.erase(dupIt, lines.end());
    }
    qDebug() << "lines after WD reference merge:" << lines.size();

    augmentFromWikidata();
}

void Generator::augmentFromWikidata()
{
    // sort to maximize cache hits of the batches wikidata queries
    std::sort(lines.begin(), lines.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.wdId < rhs.wdId;
    });
    std::vector<wd::Q> wdIds;
    for (const auto &r: lines) {
        if (r.wdId.isValid()) {
            wdIds.push_back(r.wdId);
        }
    }
    wdIds.erase(std::unique(wdIds.begin(), wdIds.end()), wdIds.end());
    qDebug() << "Retrieving" << wdIds.size() << "items from Wikidata";

    auto query = new Wikidata::EntitiesQuery(m_wdMgr);
    query->setItems(std::move(wdIds));
    QObject::connect(query, &Wikidata::EntitiesQuery::partialResult, [this](auto query) { applyWikidataResults(std::move(query->takeResult())); });
    QObject::connect(query, &Wikidata::Query::finished, [this, query]() mutable {
        if (query->error() != Wikidata::Query::NoError) {
            qCritical() << "Wikidata query failed";
            QCoreApplication::exit(1);
            return;
        }

        augmentProductsFromWikidata();
    });
    m_wdMgr->execute(query);
}

static struct {
    wd::Q id;
    LineInfo::Mode mode;
} const wd_type_to_mode_map[] = {
    { wd::Q(1412403), LineInfo::RapidTransit }, // commuter rail
    { wd::Q(1192191), LineInfo::Train }, // airport rail link
    { wd::Q(50331459), LineInfo::RapidTransit }, // S-Bahn line
    { wd::Q(95723), LineInfo::RapidTransit }, // S-Bahn
    { wd::Q(129172), LineInfo::LongDistance }, // ICE
    { wd::Q(15145593), LineInfo::Tram }, // tram line
    { wd::Q(2572054), LineInfo::RapidTransit }, // Transilien (multiple variants)
    { wd::Q(732778), LineInfo::RapidTransit }, // Transilien
    { wd::Q(2571458), LineInfo::RapidTransit }, // Transilien
    { wd::Q(2571977), LineInfo::RapidTransit }, // Transilien
    { wd::Q(373725), LineInfo::RapidTransit }, // Transilien
    { wd::Q(858485), LineInfo::LongDistance }, // high speed railway line
    { wd::Q(2138247), LineInfo::LocalTrain }, // Regional-Express
    { wd::Q(515449), LineInfo::LocalTrain }, // Regionalbahn
    { wd::Q(1116067), LineInfo::RapidTransit }, // RER
};

static LineInfo::Mode modeFromWikidataType(wd::Q type)
{
    LineInfo::Mode mode = LineInfo::Unknown;
    for (const auto &modeMap : wd_type_to_mode_map) {
        if (type == modeMap.id) {
            mode = std::max(modeMap.mode, mode);
        }
    }
    return mode;
}

static const wd::Q wd_excluded_types[] {
    wd::Q(43229), // organization
    wd::Q(740752), // transport company
    wd::Q(928830), // metro station
    wd::Q(4830453), // business
    wd::Q(7835189), // transit district
    wd::Q(249556), // railway company
    wd::Q(17377208), // train operating company
    wd::Q(138825), // children's railway (yes, really...)
    wd::Q(1144661), // amusement ride
    wd::Q(420962), // heritage railway
};

static bool isExcludedWikidataType(wd::Q type)
{
    return std::find(std::begin(wd_excluded_types), std::end(wd_excluded_types), type) != std::end(wd_excluded_types);
}

static const wd::Q wd_product_types[] {
    wd::Q(5503), // rapid transit
    wd::Q(95723), // S-Bahn
    wd::Q(15640053), // tram system
    wd::Q(1412403), // commuter rail
    wd::Q(2140646), // Stadtbahn
    wd::Q(1268865), // light rail
    wd::Q(113455515), // automated rapid transit
    wd::Q(124130081), // commuter rail network
};

static bool isWikidataProductType(wd::Q type)
{
    return std::find(std::begin(wd_product_types), std::end(wd_product_types), type) != std::end(wd_product_types);
}

static const wd::Q wd_recursive_product_types[] = {
    wd::Q(95723), // S-Bahn
    wd::Q(1054782), // Cercanías
};

void Generator::applyWikidataResults(std::vector<wd::Item> &&items)
{
    for (auto &item : items) {
        auto rit = std::lower_bound(lines.begin(), lines.end(), item.id(), [](const LineInfo &lhs, wd::Q rhs) {
            return lhs.wdId < rhs;
        });
        // wikidata line elements shouldn't occur for multiple lines, but in some cases
        // OSM points to product or network elements instead, and those can occur once per line
        for (; rit != lines.end() && (*rit).wdId == item.id(); ++rit) {
            // check if this is a plausible type
            const auto instancesOf = item.values<wd::Q>(wd::P::instanceOf);
            bool found = false;
            LineInfo::Mode mode = LineInfo::Unknown;
            for (const auto &instanceOf : instancesOf) {
                if (isExcludedWikidataType(instanceOf)) {
                    qWarning() << "Suspicious WD types:" << (*rit) << instancesOf;
                    found = true;
                }
                mode = std::max(mode, modeFromWikidataType(instanceOf));

                if (isWikidataProductType(instanceOf)) { // wikidata link in OSM is pointing to the product, not the line it seems
                    wdPartOfIds.insert(item.id());
                    (*rit).wdProducts.push_back(item.id());
                }
            }
            if (found) {
                break;
            }

            // collect possible product types
            for (const wd::P p : {wd::P(wd::P::partOf), wd::P(16)}) {
                for (const auto &id : item.values<wd::Q>(p)) {
                    wdPartOfIds.insert(id);
                    (*rit).wdProducts.push_back(id);

                    mode = std::max(mode, modeFromWikidataType(id));
                }
            }

            // merge information
            const auto color = item.value<QColor>(wd::P(465));
            if ((*rit).color.isValid() && color.isValid() && (*rit).color != color) {
                //qWarning() << "OSM/WD color conflict:" << (*rit) << color.name();
            } else if (color.isValid()) {
                (*rit).color = color;
            }
            for (const auto p : { wd::P::logoImage, wd::P::icon, wd::P::smallLogoOrIcon }) {
                const auto logos = item.values<QString>(p);
                for (const auto &logo : logos) {
                    if (!logo.isEmpty() && !(*rit).lineLogos.contains(logo)) {
                        (*rit).lineLogos.push_back(logo);
                    }
                }
            }
            if (!isCompatibleMode((*rit).mode, mode)) {
                qWarning() << "OSM/WD mode conflict:" << (*rit) << mode;
            }
            (*rit).mode = std::max((*rit).mode, mode);
        }

        wdItems[item.id()] = std::move(item);
    }
}

void Generator::augmentProductsFromWikidata()
{
    for (const auto &t : wd_recursive_product_types) { // should all be already in there, but let's make sure so we don't have to check again below
        wdPartOfIds.insert(t);
    }
    std::vector<wd::Q> wdIds;
    for (const auto &id: wdPartOfIds) {
        if (id.isValid() && wdItems.find(id) == wdItems.end()) {
            wdIds.push_back(id);
        }
    }
    qDebug() << "Retrieving" << wdIds.size() << "product items from Wikidata";

    auto query = new Wikidata::EntitiesQuery(m_wdMgr);
    query->setItems(std::move(wdIds));
    QObject::connect(query, &Wikidata::EntitiesQuery::partialResult, [this](auto query) { applyWikidataProductResults(std::move(query->takeResult())); });
    QObject::connect(query, &Wikidata::Query::finished, [this, query]() mutable {
        if (query->error() != Wikidata::Query::NoError) {
            qCritical() << "Wikidata product query failed";
            QCoreApplication::exit(1);
            return;
        }

        applyWikidataProductResults();
        verifyImages();
    });
    m_wdMgr->execute(query);
}

void Generator::applyWikidataProductResults(std::vector<wd::Item> &&items)
{
    for (auto &item : items) {
        wdItems[item.id()] = std::move(item);
    }
}

void Generator::applyWikidataProductResults()
{
    for (const auto &id : wdPartOfIds) {
        const auto item = wdItems[id];
        // check if this is a plausible type
        const auto instancesOf = item.values<wd::Q>(wd::P::instanceOf);
        LineInfo::Mode mode = LineInfo::Unknown;
        bool found = false;
        for (const auto &instanceOf : instancesOf) {
            if (isWikidataProductType(instanceOf)) {
                found = true;
            }
            mode = std::max(mode, modeFromWikidataType(instanceOf));
        }
        if (!found && !std::all_of(instancesOf.begin(), instancesOf.end(), isExcludedWikidataType)) {
            qDebug() << "Product" << item.id() << "is of unknown type " << instancesOf;
        }
        if (!found) {
            continue;
        }

        // retrieve logo and find the lines this is for
        auto logoNames = item.values<QString>(wd::P::logoImage);
        // check if this is a type we should recurse on for more logo candidates
        for (const auto &instanceOf : instancesOf) {
            if (std::find(std::begin(wd_recursive_product_types), std::end(wd_recursive_product_types), instanceOf) == std::end(wd_recursive_product_types)) {
                continue;
            }
            const auto logos = wdItems[instanceOf].values<QString>(wd::P::logoImage);
            std::copy(logos.begin(), logos.end(), std::back_inserter(logoNames));
        }

        if (logoNames.empty() && mode == LineInfo::Unknown) {
            continue;
        }
        for (auto &line : lines) {
            if (std::find(line.wdProducts.begin(), line.wdProducts.end(), item.id()) == line.wdProducts.end()) {
                continue;
            }

            if (line.mode == LineInfo::Unknown) {
                line.mode = mode;
            }

            std::copy(logoNames.begin(), logoNames.end(), std::back_inserter(line.productLogos));
        }
    }
}

void Generator::verifyImages()
{
    std::vector<QString> imageIds;
    for (const auto &r: lines) {
        if (!LineInfo::isUseful(r)) {
            continue;
        }
        std::copy(r.lineLogos.begin(), r.lineLogos.end(), std::back_inserter(imageIds));
        std::copy(r.productLogos.begin(), r.productLogos.end(), std::back_inserter(imageIds));
    }
    std::sort(imageIds.begin(), imageIds.end());
    imageIds.erase(std::unique(imageIds.begin(), imageIds.end()), imageIds.end());
    imageIds.erase(std::remove(imageIds.begin(), imageIds.end(), QString()), imageIds.end());
    qDebug() << "Verifying" << imageIds.size() << "images" << imageIds;

    auto query = new Wikidata::ImageMetadataQuery(m_wdMgr);
    query->setImages(std::move(imageIds));
    QObject::connect(query, &Wikidata::ImageMetadataQuery::partialResult, [this](auto query) { verifyImageMetaData(std::move(query->takeResult())); });
    QObject::connect(query, &Wikidata::Query::finished, [this, query]() mutable {
        if (query->error() != Wikidata::Query::NoError) {
            qCritical() << "Wikidata image metadata query failed";
            QCoreApplication::exit(1);
            return;
        }
        verifyImageMetaData();

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

void Generator::verifyImageMetaData(std::vector<wd::Image> &&images)
{
    const QStringList valid_licenses({
        QStringLiteral("cc0"),
        QStringLiteral("copyrighted free use"),
        QStringLiteral("public domain"),
        QStringLiteral("cc by 3.0"),
        QStringLiteral("cc by 3.0 it"),
        QStringLiteral("cc by-sa 3.0"),
        QStringLiteral("cc by-sa 3.0 de"),
        QStringLiteral("cc-by-sa-3.0"),
        QStringLiteral("cc by-sa 4.0"),
    });

    // things that for whatever reason managed to bypass all generic checks but that we don't want still
    const QStringList excluded_names({
        QStringLiteral("S-Bahn München Logo ohne DB (2022).svg"), // cheats around the aspect ratio check, fallback gives us the standard S-Bahn logo
    });

    for (auto &image : images) {
        const auto name = image.name();
        const auto fileSize = image.fileSize();
        if (fileSize > MaxLogoFileSize) {
            qWarning() << "not using logo" << name << "due to file size:" << fileSize;
            continue;
        }

        const auto aspectRatio = (double)image.width() / (double)image.height();
        if (aspectRatio > MaxLogoAspectRatio || aspectRatio < MinLogoAspectRatio) {
            qWarning() << "not using logo" << name << "due to aspect ratio:" << aspectRatio;
            continue;
        }

        const auto mt = image.mimeType();
        if (mt != QLatin1String("image/svg+xml") && mt != QLatin1String("image/png")) {
            qWarning() << "not using logo" << name << "due to mimetype:" << mt;
            continue;
        }

        const auto lic = image.license();
        if (!valid_licenses.contains(lic, Qt::CaseInsensitive)) {
            qWarning() << "not using logo" << name << "due to license:" << lic;
            continue;
        }

        if (excluded_names.contains(name)) {
            qWarning() << "dropping logo" << name;
            continue;
        }

        wdImages[name] = std::move(image);
   }
   images.clear();
}

void Generator::verifyImageMetaData(QStringList &logos)
{
    logos.erase(std::remove_if(logos.begin(), logos.end(), [this](const auto &logo) {
        return wdImages.find(logo) == wdImages.end();
    }), logos.end());

    if (logos.size() <= 1) {
        return;
    }

    // TODO sort by best aspect ratio/size
    qDebug() << "multiple logos available:" << logos;
}

void Generator::verifyImageMetaData()
{
    for (auto &line : lines) {
        verifyImageMetaData(line.lineLogos);
        if (!line.lineLogos.empty() && line.productLogos.size() > 1) {
            line.productLogos.erase(std::remove(line.productLogos.begin(), line.productLogos.end(), line.lineLogos[0]), line.productLogos.end());
        }
        verifyImageMetaData(line.productLogos);
    }
}

void Generator::generateQuadTree()
{
    // order lines by OSM id, to increase output stability
    std::sort(lines.begin(), lines.end(), [](const auto &lhs, const auto &rhs) { return lhs.relId < rhs.relId; });

    // initialize quad tree by smallest single tile containing the entire line bbox
    for (auto lineIt = lines.begin(); lineIt != lines.end(); ++lineIt) {
        auto z = OSM::ztileFromBoundingBox((*lineIt).bbox);
        while (z.depth < QuadTreeDepthLimit) { // don't go deeper than what we can represent in 32bit
            z = z.parent();
        }
        insertToBucket(z, std::distance(lines.begin(), lineIt));
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
            //qDebug() << "subdividing" << lines[*lit].name << lines[*lit].bbox << lines[*lit].relId << std::distance(lit, lend) << (*lit) << (*tileIt).first.depth << (*tileIt).first.z;
            for (auto it = lit; it != lend; ++it) {
                //qDebug() << "  " << lines[*it];
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

    // split oversized tiles for what they contain, depsite the name being unique in the dataset we have here
    for (auto tileIt = zQuadTree.begin(); tileIt != zQuadTree.end(); ++tileIt) {
        if ((*tileIt).first.depth == QuadTreeDepthLimit) { // below that we need more than 32 bit for z in the quad tree storage
            break;
        }
        for (auto lineIt = (*tileIt).second.begin(); lineIt != (*tileIt).second.end();) {
            // push down elements that actually only occupy a sub-tile
            // this can happen as part of conflict resolution above as well as the splitting below
            int coveredSubTiles = 0;
            for (auto subtile : (*tileIt).first.quadSplit()) {
                if (subtile.intersects(lines[*lineIt].bbox)) {
                    ++coveredSubTiles;
                }
            }

            // check if the line is too small for the current tile, and if so, split it
            const auto coverage = std::max((double)lines[*lineIt].bbox.width() / (double)(*tileIt).first.boundingBox().width(),
                                           (double)lines[*lineIt].bbox.height() / (double)(*tileIt).first.boundingBox().height());

            if (coverage < MinTileCoverage || coveredSubTiles == 1) {
                //qDebug() << "splitting due to small coverage:" << lines[*lineIt] << (*tileIt).first.depth << coverage << coveredSubTiles;
                for (auto subtile : (*tileIt).first.quadSplit()) {
                    if (subtile.intersects(lines[*lineIt].bbox)) {
                        insertToBucket(subtile, *lineIt);
                    }
                }
                lineIt = (*tileIt).second.erase(lineIt);
                continue;
            }

            ++lineIt;
        }
    }
    qDebug() << "tiles after coverage cleanup:" << zQuadTree.size();

    // remove empty buckets, and sort the non-empty ones for output stability
    for (auto tileIt = zQuadTree.begin(); tileIt != zQuadTree.end();) {
        if ((*tileIt).second.empty()) {
            tileIt = zQuadTree.erase(tileIt);
        } else if ((*tileIt).first.depth < QuadTreeDepthLimit) {
            qWarning() << "  found tile below depth limit!";
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
                        //qDebug() << "propagating down:" << lines[*conflictIt].name << lines[*conflictIt].relId << parentTile.z << parentTile.depth << *conflictIt;
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
        case LineInfo::Train:
        case LineInfo::LocalTrain:
            return "LineMetaDataContent::LocalTrain";
        case LineInfo::LongDistance:
            return "LineMetaDataContent::LongDistanceTrain";
        default:
            assert(false);
    }

    return {};
}

void Generator::writeCode()
{
    // write header
    out->write(R"(/*
    SPDX-FileCopyrightText: OpenStreetMap contributors
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
        logoStrTab.addString(line.lineLogos.value(0));
        logoStrTab.addString(line.productLogos.value(0));
    }
    nameStrTab.writeCode("line_name_stringtab", out);
    logoStrTab.writeCode("line_logo_stringtab", out);
    // create a symbolic name for the common no logo case (reduces diff on changes)
    out->write("static const constexpr uint16_t NoLogo = ");
    out->write(QByteArray::number((int)logoStrTab.stringOffset(QString())));
    out->write(";\n\n");

    // write line table
    out->write("static const constexpr LineMetaDataContent line_data[] = {\n");
    for (const auto &line : lines) {
        out->write("    { ");
        out->write(QByteArray::number((int)nameStrTab.stringOffset(line.name)));
        out->write(", ");
        if (!line.lineLogos.isEmpty()) {
            out->write(QByteArray::number((int)logoStrTab.stringOffset(line.lineLogos.at(0))));
        } else {
            out->write("NoLogo");
        }
        out->write(", ");
        if (!line.productLogos.isEmpty()) {
            out->write(QByteArray::number((int)logoStrTab.stringOffset(line.productLogos.at(0))));
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
        if (line.wdId.isValid()) {
            out->write(" WD: ");
            out->write(line.wdId.toString().toUtf8());
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
    QCoreApplication::setApplicationName(u"KPublicTransport/KnowledgeDBGenerator"_s);
    QCommandLineParser parser;
    parser.addHelpOption();
    QCommandLineOption outFileOption({ QStringLiteral("o") }, QStringLiteral("Output file name"), QStringLiteral("out"));
    parser.addOption(outFileOption);
    QCommandLineOption osmInputOption({ QStringLiteral("i") }, QStringLiteral("O5M input file"),  QStringLiteral("o5m-in"));
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
    auto reader = OSM::IO::readerForMimeType(u"application/vnd.openstreetmap.data+o5m", &dataSet);
    assert(reader);
    reader->read(f.map(0, f.size()), f.size());

    Generator generator;
    generator.m_wdMgr->setUserAgentEmailAddress(u"kde-pim@kde.org"_s);
    generator.out = &out;
    generator.processOSMData(std::move(dataSet));

    return QCoreApplication::exec();
}

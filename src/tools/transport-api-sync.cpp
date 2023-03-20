/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "polygonsimplifier.h"
#include "../lib/geo/geojson_p.h"

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QDirIterator>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QPolygonF>
#include <QProcess>
#include <QRegularExpression>

#include <iostream>

// excluded provider ids, mainly for simple disambiguation
static constexpr const char* const excluded_transport_apis[] = {
    "db-hafas-query",
    "db-busradar-nrw-hafas-mgate",
    "db-sbahn-muenchen-hafas-mgate",
};

// manual config file name mappings, used when our mapping heuristics fail
static constexpr struct {
    const char* fromCountry;
    const char* fromId;
    const char* to;
} transport_api_mapping[] = {
    { "au", "transportnsw", "au_nsw" },
    { "be", "nmbs-sncb", "be_sncb" },
    { "ch", "sbb-cff-ffs", "ch_sbb" },
    { "de", "bayernfahrplan", "de_by_bayern" },
    { "de", "nahsh", "de_sh_sh" },
    { "de", "nasa", "de_st_insa" },
    { "de", "saarfahrplan", "de_sl_saarvv" },
    { "dk", "rejseplanen", "dk_dsb" },
};

static bool updateTransportApisRepo(const QString &path)
{
    if (!QDir().exists(path)) {
        QProcess proc;
        proc.setProcessChannelMode(QProcess::ForwardedChannels);
        proc.start(QStringLiteral("git"), {QStringLiteral("clone"), QStringLiteral("https://github.com/public-transport/transport-apis.git"), path});
        if (!proc.waitForFinished() || proc.exitCode() != 0) {
            return false;
        }
    }

    QProcess proc;
    proc.setWorkingDirectory(path);
    proc.setProcessChannelMode(QProcess::ForwardedChannels);
    proc.start(QStringLiteral("git"), {QStringLiteral("pull")});
    return proc.waitForFinished() && proc.exitCode() == 0;
}

static bool isArrayOfObjects(const QJsonValue &v)
{
    const auto a = v.toArray();
    return !a.isEmpty() && a.at(0).isObject();
}

static void mergeJsonObject(QJsonObject &destObj, const QJsonObject &srcObj)
{
    for (auto it = srcObj.begin(); it != srcObj.end(); ++it) {
        if (it.value().isObject()) {
            const auto srcChild = it.value().toObject();
            auto destChild = destObj.value(it.key()).toObject();
            mergeJsonObject(destChild, srcChild);
            destObj.insert(it.key(), destChild);
        } else if (isArrayOfObjects(it.value())) {
            const auto srcArray = it.value().toArray();
            const auto destArray = destObj.value(it.key()).toArray();
            QJsonArray outArray;
            int i = 0;
            for (; i < destArray.size() && i < srcArray.size(); ++i) {
                auto obj = destArray.at(i).toObject();
                mergeJsonObject(obj, srcArray.at(i).toObject());
                outArray.push_back(obj);
            }
            for (; i < destArray.size(); ++i) {
                outArray.push_back(destArray.at(i));
            }
            for (; i < srcArray.size(); ++i) {
                outArray.push_back(srcArray.at(i));
            }
            destObj.insert(it.key(), outArray);
        } else {
            destObj.insert(it.key(), it.value());
        }
    }
}

static void sortJsonArray(QJsonArray &array)
{
    QStringList l;
    l.reserve(array.size());
    std::transform(array.begin(), array.end(), std::back_inserter(l), [](const auto &jval) { return jval.toString(); });
    std::sort(l.begin(), l.end());
    array = {};
    std::transform(l.begin(), l.end(), std::back_inserter(array), [](const auto &s) { return QJsonValue(s); });
}

static void preProcessCoverage(QJsonObject &obj)
{
    // sort country codes
    auto regions = obj.take(QLatin1String("region")).toArray();
    sortJsonArray(regions);
    if (!regions.empty()) {
        obj.insert(QLatin1String("region"), regions);
    }

    // reduce resolution of the area geometry
    using namespace KPublicTransport;
    auto polys = GeoJson::readOuterPolygons(obj.take(QLatin1String("area")).toObject());
    for (auto &poly : polys) {
        const auto originalPolySize = poly.size();
        poly = PolygonSimplifier::douglasPeucker(poly, 10'000.0);
        if (originalPolySize > poly.size()) {
            // only apply offsetting if we actually simplified the polygon
            poly = PolygonSimplifier::offset(poly, 10'000.0);
        }
    }

    // remove polygons fully contained inside another one already (e.g. small enclaves/islands included by the above offset operation now)
    for (auto it = polys.begin(); it != polys.end();) {
        auto it2 = polys.begin();
        for (; it2 != polys.end(); ++it2) {
            if (it == it2) {
                continue;
            }
            if ((*it).subtracted(*it2).isEmpty()) {
                break;
            }
        }
        if (it2 != polys.end()) {
            qDebug() << "dropping fully enclosed polygon" << (*it).size();
            it = polys.erase(it);
        } else {
            ++it;
        }
    }

    if (!polys.empty()) {
        obj.insert(QLatin1String("area"), GeoJson::writePolygons(polys));
    }
}

static void preProcessConfig(QJsonObject &top)
{
    // move translated keys to the location ki18n expects them
    QJsonObject translatedObj;
    for (const auto &key : { "name", "description" }) {
        auto v = top.take(QLatin1String(key));

        auto normalizedKey = QString::fromLatin1(key);
        normalizedKey[0] = normalizedKey[0].toUpper();
        translatedObj.insert(normalizedKey, std::move(v));
    }
    top.insert(QLatin1String("KPlugin"), std::move(translatedObj));

    // remove excessive Hafas client properties
    auto options = top.take(QLatin1String("options")).toObject();
    auto client = options.value(QLatin1String("client")).toObject();
    client.remove(QLatin1String("os"));
    client.remove(QLatin1String("v"));
    client.remove(QLatin1String("name"));
    if (!client.isEmpty()) {
        options.insert(QLatin1String("client"), std::move(client));
    }
    if (!options.isEmpty()) {
        top.insert(QLatin1String("options"), std::move(options));
    }

    // coverage data
    auto coverage = top.take(QLatin1String("coverage")).toObject();
    for (auto it = coverage.begin(); it != coverage.end(); ++it) {
        auto cov = it.value().toObject();
        preProcessCoverage(cov);
        it.value() = cov;
    }
    top.insert(QLatin1String("coverage"), coverage);
}

static void postProcessConfig(QJsonObject &top)
{
    // sort languages alphabetically to create stable diffs, the order doesn't matter for us
    auto langs = top.take(QLatin1String("supportedLanguages")).toArray();
    sortJsonArray(langs);
    if (!langs.empty()) {
        top.insert(QLatin1String("supportedLanguages"), langs);
    }
}

static bool applyUpstreamConfig(const QString &kptConfigFile, const QString &apiConfigFile)
{
    qDebug() << "merging" << apiConfigFile << kptConfigFile;
    QFile inFile(apiConfigFile);
    if (!inFile.open(QFile::ReadOnly)) {
        std::cerr << qPrintable(inFile.errorString()) << std::endl;
        return false;
    }
    QJsonParseError error;
    auto inObj = QJsonDocument::fromJson(inFile.readAll(), &error).object();
    if (error.error != QJsonParseError::NoError) {
        std::cerr << "JSON parsing error: " << qPrintable(error.errorString()) << ": " << qPrintable(apiConfigFile) << std::endl;
        return false;
    }
    preProcessConfig(inObj);

    QFile outFile(kptConfigFile);
    if (!outFile.open(QFile::ReadOnly)) {
        std::cerr << qPrintable(outFile.errorString());
        return false;
    }
    auto outObj = QJsonDocument::fromJson(outFile.readAll()).object();
    outFile.close();

    mergeJsonObject(outObj, inObj);
    postProcessConfig(outObj);

    if (!outFile.open(QFile::WriteOnly | QFile::Truncate)) {
        std::cerr << qPrintable(outFile.errorString()) << std::endl;
        return false;
    }
    outFile.write(QJsonDocument(outObj).toJson());
    return true;
}

/** Sync network configurations with upstream transport API repository. */
int main(int argc, char **argv)
{
    QCoreApplication::setApplicationName(QStringLiteral("transport-api-snyc"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("kde.org"));
    QCoreApplication::setOrganizationName(QStringLiteral("KDE"));
    QCoreApplication app(argc, argv);

    QCommandLineParser parser;
    auto configPathOpt = QCommandLineOption({QStringLiteral("config-path")}, QStringLiteral("location of the network config files"), QStringLiteral("config-path"));
    parser.addOption(configPathOpt);
    auto transportApiPathOpt = QCommandLineOption({QStringLiteral("transport-apis")}, QStringLiteral("path to the transport-apis repo checkout"), QStringLiteral("transport-apis-repo"));
    parser.addOption(transportApiPathOpt);
    parser.addHelpOption();
    parser.process(app);

    if (!updateTransportApisRepo(parser.value(transportApiPathOpt))) {
        return -1;
    }

    // ### temporary to migrate our format closer to the standard format
#if 0
    for (QDirIterator it(parser.value(configPathOpt), QDir::Files); it.hasNext();) {
        const auto fileName = it.next();
        QFile f(fileName);
        if (!f.fileName().endsWith(QLatin1String(".json"))) {
            continue;
        }
        if (!f.open(QFile::ReadOnly)) {
            qWarning() << "Failed to open" << f.fileName() << f.errorString();
            continue;
        }

        const auto doc = QJsonDocument::fromJson(f.readAll());
        auto topObj = doc.object();

        qDebug() << "Updating" << fileName;
        auto options = topObj.value(QLatin1String("options")).toObject();
        auto lineModeMap = options.take(QLatin1String("lineModeMap")).toObject();
        if (lineModeMap.isEmpty()) {
            continue;
        }

        std::vector<QJsonObject> products;
        for (auto it = lineModeMap.begin(); it != lineModeMap.end(); it++) {
            QJsonArray bitmasks({ it.key().toInt() });
            QJsonObject product;
            product.insert(QLatin1String("bitmasks"), bitmasks);
            product.insert(QLatin1String("mode"), it.value());
            products.push_back(std::move(product));
        }
        std::sort(products.begin(), products.end(), [](const auto &lhs, const auto &rhs) {
            return lhs.value(QLatin1String("bitmasks")).toArray().at(0).toInt() < rhs.value(QLatin1String("bitmasks")).toArray().at(0).toInt();
        });

        QJsonArray productsA;
        std::copy(products.begin(), products.end(), std::back_inserter(productsA));

        options.insert(QLatin1String("products"), std::move(productsA));
        topObj.insert(QLatin1String("options"), options);

        f.close();
        f.open(QFile::WriteOnly | QFile::Truncate);
        f.write(QJsonDocument(topObj).toJson());
    }
#endif
    // ### end temporary migration code

    // match our files and the transport api ones
    struct MatchedConfig {
        QString config;
        std::vector<QString> apiConfigs;
    };
    std::vector<MatchedConfig> configs;
    for (QDirIterator it(parser.value(configPathOpt), QDir::Files); it.hasNext();) {
        const auto fileName = it.next();
        QFile f(fileName);
        if (!fileName.endsWith(QLatin1String(".json"))) {
            continue;
        }
        MatchedConfig c;
        c.config = it.fileInfo().baseName();
        configs.push_back(std::move(c));
    }
    for (QDirIterator it(parser.value(transportApiPathOpt) + QLatin1String("/data"), QDir::Files, QDirIterator::Subdirectories); it.hasNext();) {
        const auto fileName = it.next();
        const auto baseName = it.fileInfo().baseName();
        if (!fileName.endsWith(QLatin1String(".json"))
         || std::any_of(std::begin(excluded_transport_apis), std::end(excluded_transport_apis), [&baseName](const char* excl) {
                return QLatin1String(excl) == baseName;
            })
        ) {
            continue;
        }

        QRegularExpression rx(QStringLiteral("/([a-z]{2})/([a-z-]+?)-(hafas-mgate|hafas-query|[^-]+)\\.json"));
        const auto match = rx.match(fileName);
        if (!match.hasMatch()) {
            return -1;
        }

        bool found = false;
        for (auto cit = configs.begin(); cit != configs.end(); ++cit) {
            if (!(*cit).config.startsWith(match.captured(1) + QLatin1Char('_')) || !(*cit).config.endsWith(QLatin1Char('_') + match.captured(2))) {
                continue;
            }
            (*cit).apiConfigs.push_back(fileName);
            found = true;
        }
        if (found) {
            continue;
        }
        for (const auto &map : transport_api_mapping) {
            if (QLatin1String(map.fromCountry) == match.captured(1) && QLatin1String(map.fromId) == match.captured(2)) {
                auto cit = std::find_if(configs.begin(), configs.end(), [map](const auto &config) {
                    return QLatin1String(map.to) == config.config;
                });
                if (cit != configs.end()) {
                    (*cit).apiConfigs.push_back(fileName);
                }
                found = true;
                break;
            }
        }
        if (!found) {
            qDebug() << "  no match found for" << fileName;
        }
    }

    // for better readability of the output
    std::sort(configs.begin(), configs.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.config < rhs.config;
    });

    for (const auto &c : configs) {
        if (c.apiConfigs.empty()) {
            qDebug() << "  " << c.config << "is missing upstream";
            continue;
        }
        if (c.apiConfigs.size() > 1) {
            qDebug() << "  " << c.config << "has multiple matches:" << c.apiConfigs;
            // TODO pick the best protocol and use that one
            continue;
        }

        if (!applyUpstreamConfig(parser.value(configPathOpt) + QLatin1Char('/') + c.config + QLatin1String(".json"), c.apiConfigs[0])) {
            return -1;
        }
    }
}

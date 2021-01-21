/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDebug>
#include <QDirIterator>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QProcess>

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
    { "be", "nmbs-sncb", "be_sncb" },
    { "ch", "sbb-cff-ffs", "ch_sbb" },
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

static void mergeJsonObject(QJsonObject &destObj, const QJsonObject &srcObj)
{
    for (auto it = srcObj.begin(); it != srcObj.end(); ++it) {
        if (it.value().isObject()) {
            const auto srcChild = it.value().toObject();
            auto destChild = destObj.value(it.key()).toObject();
            mergeJsonObject(destChild, srcChild);
            destObj.insert(it.key(), destChild);
        } else {
            destObj.insert(it.key(), it.value());
        }
    }
}

// product name patterns to create our line mode mapping
static constexpr struct {
    const char *productName;
    const char *modeName;
} const hafas_line_modes[] = {
    { "s-", "RapidTransit" },
    { "u-", "Metro" },
    { "tram", "Tramway" },
    { "straßenbahn", "Tramway" },
    { "fernbus", "Coach" },
    { "bus", "Bus" },
    { "taxi", "Taxi" },
    { "fähre", "Ferry" },
    { "schiff", "Ferry" },
    { "intercity", "LongDistanceTrain" },
    { "ic", "LongDistanceTrain" },
    { "regio", "LocalTrain" },
    { "rb", "LocalTrain" },
    { "seil", "Tramway" }, // TODO cable car/aerial lift
    { "cable", "Tramway" },
    { "anruf", "Taxi" },
    { "call", "Taxi" },
    { "nah", "LocalTrain" },
    { "local", "LocalTrain" },
    { "fern", "LongDistanceTrain" },
    { "long", "LongDistanceTrain" },
    { "bedarf", "Taxi" },
    { "bart", "RapidTransit" },
    { "fun", "Funicular" },
    { "train", "Train" },
    { "euro", "LongDistanceTrain" },
    { "ir", "Train" },
    { "re", "LocalTrain" },
    { "zug", "Train" },
};

static void postProcessConfig(QJsonObject &top)
{
    // TODO we probably should put this into a separate key and not override the upstream data?
    auto options = top.value(QLatin1String("options")).toObject();
    auto lineModeMap = options.value(QLatin1String("lineModeMap")).toObject();
    for (auto it = lineModeMap.begin(); it != lineModeMap.end(); ++it) {
        for (const auto &mode : hafas_line_modes) {
            if (it.value().toString().contains(QString::fromUtf8(mode.productName), Qt::CaseInsensitive)) {
                it.value() = QLatin1String(mode.modeName);
                break;
            }
        }
    }
    if (!lineModeMap.empty()) {
        options.insert(QLatin1String("lineModeMap"), lineModeMap);
    }
    top.insert(QLatin1String("options"), options);
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

    // move translated keys to the location ki18n expects them
    QJsonObject translatedObj;
    for (const auto &key : { "name", "description" }) {
        auto v = inObj.take(QLatin1String(key));

        auto normalizedKey = QString::fromLatin1(key);
        normalizedKey[0] = normalizedKey[0].toUpper();
        translatedObj.insert(normalizedKey, std::move(v));
    }
    inObj.insert(QLatin1String("KPlugin"), translatedObj);

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
        auto protocolType = topObj.value(QLatin1String("type")).toString();
        if (protocolType.isEmpty()) { continue; }
        if (protocolType == QLatin1String("hafas_mgate")) { protocolType = QStringLiteral("hafasMgate"); }
        if (protocolType == QLatin1String("hafas_query")) { protocolType = QStringLiteral("hafasQuery"); }
        if (protocolType == QLatin1String("otp_graphql")) { protocolType = QStringLiteral("otpGraphQl"); }
        if (protocolType == QLatin1String("otp_rest")) { protocolType = QStringLiteral("otpRest"); }
        QJsonObject type;
        type.insert(protocolType, true);
        topObj.insert(QLatin1String("type"), type);

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

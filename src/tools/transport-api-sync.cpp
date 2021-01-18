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

static bool applyUpstreamConfig(const QString &kptConfigFile, const QString &apiConfigFile)
{
    qDebug() << "merging" << apiConfigFile << kptConfigFile;
    QFile inFile(apiConfigFile);
    if (!inFile.open(QFile::ReadOnly)) {
        std::cerr << qPrintable(inFile.errorString());
        return false;
    }
    const auto inObj = QJsonDocument::fromJson(inFile.readAll()).object();

    QFile outFile(kptConfigFile);
    if (!outFile.open(QFile::ReadOnly)) {
        std::cerr << qPrintable(outFile.errorString());
        return false;
    }
    auto outObj = QJsonDocument::fromJson(outFile.readAll()).object();
    outFile.close();

    // TODO convert fields we need to translate
    mergeJsonObject(outObj, inObj);
    if (!outFile.open(QFile::WriteOnly | QFile::Truncate)) {
        std::cerr << qPrintable(outFile.errorString());
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
        auto poly = topObj.value(QLatin1String("filter")).toObject().value(QLatin1String("geo")).toArray();
        if (poly.empty()) {
            continue;
        }
        poly.push_back(poly.at(0)); // close the polygon, required by GeoJSON

        QJsonObject area;
        area.insert(QLatin1String("type"), QLatin1String("Polygon"));
        area.insert(QLatin1String("coordinates"), QJsonArray({poly}));
        QJsonObject anyCoverage;
        anyCoverage.insert(QLatin1String("area"), area);
        QJsonObject coverage;
        coverage.insert(QLatin1String("anyCoverage"), anyCoverage);
        topObj.insert(QLatin1String("coverage"), coverage);
        topObj.remove(QLatin1String("filter"));

        f.close();
        f.open(QFile::WriteOnly | QFile::Truncate);
        f.write(QJsonDocument(topObj).toJson());
    }
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
        if (!f.fileName().endsWith(QLatin1String(".json"))) {
            continue;
        }
        MatchedConfig c;
        c.config = it.fileInfo().baseName();
        configs.push_back(std::move(c));
    }
    for (QDirIterator it(parser.value(transportApiPathOpt) + QLatin1String("/data"), QDir::Files, QDirIterator::Subdirectories); it.hasNext();) {
        const auto fileName = it.next();
        QRegularExpression rx(QStringLiteral("/([a-z]{2})/([a-z]+)-"));
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

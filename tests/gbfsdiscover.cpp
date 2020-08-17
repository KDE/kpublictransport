/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <gbfs/gbfsjob.h>

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QUrl>

#include <iostream>

using namespace KPublicTransport;

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    QCommandLineParser parser;
    parser.addHelpOption();
    QCommandLineOption listOpt(QStringLiteral("list"), QStringLiteral("list all known services"));
    parser.addOption(listOpt);
    QCommandLineOption discoverOpt(QStringLiteral("discover"), QStringLiteral("perform discovery on the given GBFS feed"), QStringLiteral("url"));
    parser.addOption(discoverOpt);
    parser.process(app);

    const auto& services = GBFSServiceRepository::services();
    if (parser.isSet(listOpt)) {
        for (const auto &s : services) {
            std::cout << qPrintable(s.systemId) << " (" << qPrintable(s.discoveryUrl.toString()) << ") - ["
                << s.boundingBox.topLeft().x() << "," << s.boundingBox.topLeft().y() << "|"
                << s.boundingBox.bottomRight().x() << "," << s.boundingBox.bottomRight().y() << "]" << std::endl;
        }
        return 0;
    }

    QNetworkAccessManager nam;
    nam.setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);

    GBFSJob job(&nam);
    int exitCode = -1;
    QObject::connect(&job, &GBFSJob::finished, &app, [&]() {
        if (job.error() != GBFSJob::NoError) {
            qWarning() << job.error() << job.errorMessage();
            app.exit(exitCode = 1);
        } else {
            app.exit(exitCode = 0);
        }
    });

    GBFSService service;
    service.discoveryUrl = QUrl(parser.value(discoverOpt));

    for (const auto &s : services) {
        if (s.discoveryUrl == service.discoveryUrl) {
            service = s;
            break;
        }
    }
    job.discoverAndUpdate(service);

    return exitCode < 0 ? app.exec() : exitCode;
}

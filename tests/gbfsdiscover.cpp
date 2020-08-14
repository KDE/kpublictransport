/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <gbfs/gbfsjob.h>

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QStandardPaths>
#include <QUrl>

using namespace KPublicTransport;

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    QNetworkAccessManager nam;
    nam.setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);

    QStandardPaths::setTestModeEnabled(true);

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
    job.discoverAndUpdate(QUrl(app.arguments().at(1)));

    return exitCode < 0 ? app.exec() : exitCode;
}

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
    job.discover(QUrl(app.arguments().at(1)));

    return app.exec();
}

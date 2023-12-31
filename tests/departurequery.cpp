/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "exampleutil.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QApplication>

using namespace KPublicTransport;

int main(int argc, char **argv)
{
    QCoreApplication::setApplicationName(QStringLiteral("departurequery"));
    QCoreApplication::setOrganizationName(QStringLiteral("KDE"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("kde.org"));

    QApplication app(argc, argv);

    qmlRegisterSingletonType<ExampleUtil>("org.kde.example", 1, 0, "ExampleUtil", [](QQmlEngine*, QJSEngine*) -> QObject*{
        return new ExampleUtil;
    });

    QQmlApplicationEngine engine;
    engine.load(QStringLiteral("qrc:/departurequery.qml"));
    return app.exec();
}

#include "moc_exampleutil.cpp"

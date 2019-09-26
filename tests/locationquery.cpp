/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#include "exampleutil.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QApplication>

using namespace KPublicTransport;

int main(int argc, char **argv)
{
    QCoreApplication::setApplicationName(QStringLiteral("locationquery"));
    QCoreApplication::setOrganizationName(QStringLiteral("KDE"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("kde.org"));

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);

    qmlRegisterSingletonType<ExampleUtil>("org.kde.example", 1, 0, "ExampleUtil", [](QQmlEngine*, QJSEngine*) -> QObject*{
        return new ExampleUtil;
    });

    QQmlApplicationEngine engine;
    engine.load(QStringLiteral("qrc:/locationquery.qml"));
    return app.exec();
}

#include "moc_exampleutil.cpp"

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

#include <KPublicTransport/Location>

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QApplication>
#include <QDateTime>
#include <QDebug>
#include <QUrl>

using namespace KPublicTransport;

class QueryManager : public QObject
{
    Q_OBJECT
public:
    QueryManager(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE QString locationIds(const QVariant &v)
    {
        const auto loc = v.value<Location>();
        const auto ids = loc.identifiers();
        QStringList l;
        l.reserve(ids.size());
        for (auto it = ids.begin(); it != ids.end(); ++it) {
            l.push_back(it.key() + QLatin1String(": ") + it.value());
        }
        return l.join(QLatin1String(", "));
    }
};

int main(int argc, char **argv)
{
    QCoreApplication::setApplicationName(QStringLiteral("locationquery"));
    QCoreApplication::setOrganizationName(QStringLiteral("KDE"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("kde.org"));

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);

    QueryManager mgr;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("_queryMgr"), &mgr);
    engine.load(QStringLiteral("qrc:/locationquery.qml"));
    return app.exec();
}

#include "locationquery.moc"

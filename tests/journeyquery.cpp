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
#include <QDateTime>
#include <QIdentityProxyModel>
#include <QLocale>

using namespace KPublicTransport;

class JourneyQueryProxyModel : public QIdentityProxyModel
{
    Q_OBJECT
public:
    JourneyQueryProxyModel(QObject *parent = nullptr) : QIdentityProxyModel(parent) {}
    QVariant data(const QModelIndex &index, int role) const override
    {
        if (role == Qt::DisplayRole) {
            const auto j = index.data(JourneyQueryModel::JourneyRole).value<Journey>();
            return QString(QLocale().toString(j.scheduledDepartureTime(), QLocale::ShortFormat) + QLatin1String(" (") +
                QString::number(j.duration()/60) + QLatin1String("min) - ") + QString::number(j.numberOfChanges()) + QLatin1String(" change(s)"));
        }
        return QIdentityProxyModel::data(index, role);
    }
};

int main(int argc, char **argv)
{
    QCoreApplication::setApplicationName(QStringLiteral("journeyquery"));
    QCoreApplication::setOrganizationName(QStringLiteral("KDE"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("kde.org"));

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);

    qmlRegisterType<JourneyQueryProxyModel>("org.kde.example", 1, 0, "JourneyTitleModel");
    qmlRegisterSingletonType<ExampleUtil>("org.kde.example", 1, 0, "ExampleUtil", [](QQmlEngine*, QJSEngine*) -> QObject*{
        return new ExampleUtil;
    });

    QQmlApplicationEngine engine;
    engine.load(QStringLiteral("qrc:/journeyquery.qml"));
    return app.exec();
}

#include "journeyquery.moc"
#include "moc_exampleutil.cpp"

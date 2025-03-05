/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "exampleutil.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QApplication>
#include <QDateTime>
#include <QIdentityProxyModel>
#include <QLocale>

#include <KLocalizedQmlContext>

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

    QApplication app(argc, argv);

    qmlRegisterType<JourneyQueryProxyModel>("org.kde.example", 1, 0, "JourneyTitleModel");
    qmlRegisterSingletonType<ExampleUtil>("org.kde.example", 1, 0, "ExampleUtil", [](QQmlEngine*, QJSEngine*) -> QObject*{
        return new ExampleUtil;
    });

    QQmlApplicationEngine engine;
    KLocalization::setupLocalizedContext(&engine);
    engine.load(QStringLiteral("qrc:/journeyquery.qml"));
    return app.exec();
}

#include "journeyquery.moc"
#include "moc_exampleutil.cpp"

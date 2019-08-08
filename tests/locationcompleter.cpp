/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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
#include <KPublicTransport/LocationQueryModel>
#include <KPublicTransport/Manager>

#include <QApplication>
#include <QCompleter>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

using namespace KPublicTransport;

int main(int argc, char **argv)
{
    QCoreApplication::setApplicationName(QStringLiteral("locationcompleter"));
    QCoreApplication::setOrganizationName(QStringLiteral("KDE"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("kde.org"));

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    QApplication app(argc, argv);

    Manager ptMgr;

    QWidget window;
    auto topLayout = new QVBoxLayout;
    window.setLayout(topLayout);
    auto lineEdit = new QLineEdit;
    topLayout->addWidget(lineEdit);
    auto label = new QLabel;
    topLayout->addWidget(label);

    auto completer = new QCompleter;
    auto model = new LocationQueryModel(completer);
    model->setManager(&ptMgr);
    completer->setModel(model);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    completer->setCompletionRole(Qt::DisplayRole);
    lineEdit->setCompleter(completer);
    // TODO compress queries with a short timer
    QObject::connect(lineEdit, &QLineEdit::textEdited, model, [completer, model](const auto &text) {
        LocationRequest req;
        req.setName(text);
        model->setRequest(req);
    });
    // TODO this seems very wrong...
    QObject::connect(model, &QAbstractItemModel::rowsInserted, completer, [completer]() { completer->complete(); });
    QObject::connect(completer, QOverload<const QModelIndex&>::of(&QCompleter::activated), label, [label](const QModelIndex &idx) {
        const auto loc = idx.data(LocationQueryModel::LocationRole).value<Location>();
        QString s = QLatin1String("Name: ") + loc.name()
            + QLatin1String("\nLat: ") + QString::number(loc.latitude()) + QLatin1String(" Lon: ") + QString::number(loc.longitude());
        label->setText(s);
    });

    window.show();
    return app.exec();
}

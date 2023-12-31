/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
    model->setQueryDelay(250);
    completer->setModel(model);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setFilterMode(Qt::MatchContains);
    completer->setCompletionRole(Qt::DisplayRole);
    lineEdit->setCompleter(completer);
    QObject::connect(lineEdit, &QLineEdit::textEdited, model, [model](const auto &text) {
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

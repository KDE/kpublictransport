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

#ifndef KPUBLICTRANSPORT_BACKENDMODEL_H
#define KPUBLICTRANSPORT_BACKENDMODEL_H

#include "kpublictransport_export.h"

#include <QAbstractListModel>

#include <memory>

namespace KPublicTransport {

class BackendModelPrivate;
class Manager;

/** Model listing backends and allowing to configure which ones are active. */
class KPUBLICTRANSPORT_EXPORT BackendModel : public QAbstractListModel
{
    Q_OBJECT

    /** Sets the KPublicTransport::Manager instance. Necessary for this to work at all. */
    Q_PROPERTY(KPublicTransport::Manager* manager READ manager WRITE setManager NOTIFY managerChanged)

public:
    explicit BackendModel(QObject *parent = nullptr);
    ~BackendModel();

    enum Roles {
        NameRole = Qt::DisplayRole,
        DescriptionRole = Qt::UserRole,
        IdentifierRole,
        SecureRole,
        ItemEnabledRole,
        BackendEnabledRole
    };

    Manager* manager() const;
    void setManager(Manager *mgr);

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QHash<int, QByteArray> roleNames() const override;

Q_SIGNALS:
    void managerChanged();

private:
    const std::unique_ptr<BackendModelPrivate> d;
};

}

#endif // KPUBLICTRANSPORT_BACKENDMODEL_H

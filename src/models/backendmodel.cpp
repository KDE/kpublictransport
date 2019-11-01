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

#include "backendmodel.h"

#include <KPublicTransport/Backend>
#include <KPublicTransport/Manager>

using namespace KPublicTransport;

namespace KPublicTransport {
class BackendModelPrivate
{
public:
    Manager *mgr = nullptr;
};
}

BackendModel::BackendModel(QObject *parent)
    : QAbstractListModel(parent)
    , d(new BackendModelPrivate)
{
}

BackendModel::~BackendModel() = default;

Manager* BackendModel::manager() const
{
    return d->mgr;
}

void BackendModel::setManager(Manager *mgr)
{
    if (d->mgr == mgr) {
        return;
    }

    beginResetModel();
    d->mgr = mgr;
    connect(mgr, &Manager::configurationChanged, this, [this]() {
        emit dataChanged(index(0, 0), index(rowCount() - 1, 0));
    });
    endResetModel();
    emit managerChanged();
}

int BackendModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !d->mgr) {
        return 0;
    }
    return d->mgr->backends().size();
}

QVariant BackendModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !d->mgr) {
        return {};
    }

    const auto &backend = d->mgr->backends()[index.row()];
    switch (role) {
        case NameRole:
            return backend.name();
        case DescriptionRole:
            return backend.description();
        case IdentifierRole:
            return backend.identifier();
        case SecureRole:
            return backend.isSecure();
        case ItemEnabledRole:
            return backend.isSecure() || d->mgr->allowInsecureBackends();
        case BackendEnabledRole:
            if (!backend.isSecure() && !d->mgr->allowInsecureBackends()) {
                return false;
            }
            return true; // TODO
    }

    return {};
}

Qt::ItemFlags BackendModel::flags(const QModelIndex &index) const
{
    auto f = QAbstractListModel::flags(index);
    if (!d->mgr || !index.isValid()) {
        return f;
    }

    const auto &backend = d->mgr->backends()[index.row()];
    if (!d->mgr->allowInsecureBackends() && !backend.isSecure()) {
        return f & ~Qt::ItemIsEnabled;
    }

    return f;
}

QHash<int, QByteArray> BackendModel::roleNames() const
{
    auto names = QAbstractListModel::roleNames();
    names.insert(NameRole, "name");
    names.insert(DescriptionRole, "description");
    names.insert(IdentifierRole, "identifier");
    names.insert(SecureRole, "isSecure");
    names.insert(ItemEnabledRole, "itemEnabled");
    names.insert(BackendEnabledRole, "backendEnabled");
    return names;
}

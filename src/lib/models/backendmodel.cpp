/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backendmodel.h"

#include <KPublicTransport/Backend>
#include <KPublicTransport/Manager>

#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
struct BackendInfo
{
    Backend backend;
    QString country;
};

class BackendModelPrivate
{
public:
    void repopulateModel(BackendModel *q);
    void repopulateFlat();
    void repopulateGrouped();

    Manager *mgr = nullptr;
    std::vector<BackendInfo> rows;
    BackendModel::Mode mode = BackendModel::Flat;
};
}

void BackendModelPrivate::repopulateModel(BackendModel *q)
{
    if (!mgr) {
        return;
    }

    q->beginResetModel();
    rows.clear();
    switch (mode) {
        case BackendModel::Flat:
            repopulateFlat();
            break;
        case BackendModel::GroupByCountry:
            repopulateGrouped();
            break;
    }

    std::sort(rows.begin(), rows.end(), [](const auto &lhs, const auto &rhs) {
        if (lhs.country == rhs.country) {
            return lhs.backend.name() < rhs.backend.name();
        }
        return lhs.country < rhs.country;
    });
    q->endResetModel();
}

void BackendModelPrivate::repopulateFlat()
{
    rows.reserve(mgr->backends().size());
    for (const auto &b : mgr->backends()) {
        rows.push_back({ b, b.primaryCountryCode() });
    }
}

void BackendModelPrivate::repopulateGrouped()
{
    for (const auto &b : mgr->backends()) {
        for (const auto type : { CoverageArea::Realtime, CoverageArea::Regular, CoverageArea::Any }) {
            const auto c = b.coverageArea(type);
            if (c.isEmpty()) {
                continue;
            }

            for (const auto &country : c.regions()) {
                rows.push_back({ b, country.left(2) });
            }
            break;
        }
    }
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

    d->mgr = mgr;
    connect(mgr, &Manager::configurationChanged, this, [this]() {
        emit dataChanged(index(0, 0), index(rowCount() - 1, 0));
    });
    d->repopulateModel(this);
    emit managerChanged();
}

BackendModel::Mode BackendModel::mode() const
{
    return d->mode;
}

void BackendModel::setMode(BackendModel::Mode mode)
{
    if (d->mode == mode) {
        return;
    }

    d->mode = mode;
    emit modeChanged();
    d->repopulateModel(this);
}

int BackendModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return d->rows.size();
}

QVariant BackendModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !d->mgr) {
        return {};
    }

    const auto &row = d->rows[index.row()];
    switch (role) {
        case NameRole:
            return row.backend.name();
        case DescriptionRole:
            return row.backend.description();
        case IdentifierRole:
            return row.backend.identifier();
        case SecureRole:
            return row.backend.isSecure();
        case ItemEnabledRole:
            return row.backend.isSecure() || d->mgr->allowInsecureBackends();
        case BackendEnabledRole:
            if (!row.backend.isSecure() && !d->mgr->allowInsecureBackends()) {
                return false;
            }
            return d->mgr->isBackendEnabled(row.backend.identifier());
        case Qt::CheckStateRole:
            if (!row.backend.isSecure() && !d->mgr->allowInsecureBackends()) {
                return Qt::Unchecked;
            }
            return d->mgr->isBackendEnabled(row.backend.identifier()) ? Qt::Checked : Qt::Unchecked;
        case PrimaryCountryCodeRole:
            return row.country;
    }

    return {};
}

bool BackendModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    const auto &row = d->rows[index.row()];
    switch (role) {
        case BackendModel::BackendEnabledRole:
            d->mgr->setBackendEnabled(row.backend.identifier(), value.toBool());
            return true;
        case Qt::CheckStateRole:
            d->mgr->setBackendEnabled(row.backend.identifier(), value.toInt() == Qt::Checked);
            return true;
    }
    return false;
}

Qt::ItemFlags BackendModel::flags(const QModelIndex &index) const
{
    auto f = QAbstractListModel::flags(index);
    if (!d->mgr || !index.isValid()) {
        return f;
    }
    f |= Qt::ItemIsUserCheckable;

    const auto &row = d->rows[index.row()];
    if (!d->mgr->allowInsecureBackends() && !row.backend.isSecure()) {
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
    names.insert(PrimaryCountryCodeRole, "primaryCountryCode");
    return names;
}

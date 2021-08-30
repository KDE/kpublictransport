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
    bool isNationWide;
    CoverageArea::Type coverageType;
};

class BackendModelPrivate
{
public:
    void repopulateModel(BackendModel *q);
    void repopulateFlat();
    void repopulateGrouped();
    void sortModel();

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

    sortModel();
    q->endResetModel();
}

void BackendModelPrivate::repopulateFlat()
{
    rows.reserve(mgr->backends().size());
    for (const auto &b : mgr->backends()) {
        if (b.identifier().size() > 3 && b.identifier().at(2) == QLatin1Char('_')) {
            rows.push_back({ b, b.identifier().left(2).toUpper(), true, CoverageArea::Any });
        }
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

            for (const auto &region: c.regions()) {
                const auto country = region.left(2);
                if (!rows.empty() && rows.back().backend.identifier() == b.identifier() && rows.back().country == country) {
                    continue; // deduplicate backends covering multiple regions in the same country
                }
                rows.push_back({ b, country, region.size() == 2, type });
            }
        }
    }
}

void BackendModelPrivate::sortModel()
{
    // group by country
    const auto orderByCountry = [](const auto &lhs, const auto &rhs) {
        return lhs.country < rhs.country;
    };
    std::sort(rows.begin(), rows.end(), orderByCountry);

    // process each country individually
    for (auto next = rows.begin(); next != rows.end();) {
        const auto [begin, end] = std::equal_range(next, rows.end(), *next, orderByCountry);
        next = end;

        // find best coverage quality for nation-wide services
        CoverageArea::Type bestCoverageType = CoverageArea::Any;
        for (auto it = begin; it != end; ++it) {
            if ((*it).isNationWide) {
                bestCoverageType = std::min(bestCoverageType, (*it).coverageType);
            }
        }

        // sort within one country: nation wide with best quality first, then regional, then nation-wide with subpar coverage
        std::sort(begin, end, [bestCoverageType](const auto &lhs, const auto &rhs) {
            if (lhs.isNationWide && rhs.isNationWide) {
                if ((lhs.coverageType > bestCoverageType && rhs.coverageType > bestCoverageType)
                  || (lhs.coverageType <= bestCoverageType && rhs.coverageType <= bestCoverageType)) {
                    return lhs.backend.name() < rhs.backend.name();
                }
                return lhs.coverageType < rhs.coverageType;
            }
            if (lhs.isNationWide && !rhs.isNationWide) {
                return lhs.coverageType <= bestCoverageType;
            }
            if (!lhs.isNationWide && rhs.isNationWide) {
                return rhs.coverageType > bestCoverageType;
            }
            assert(!lhs.isNationWide && !rhs.isNationWide);
            return lhs.backend.name() < rhs.backend.name();
        });

        // drop entries for nationwide providers that are only the second best coverage quality for a country
        // and that have better coverage elsewhere
        // since removing entries here immediately would mess with the active iterators, we just clear the country
        // and do the actual deletion below
        if (mode == BackendModel::GroupByCountry) {
            for (auto it = begin; it != end; ++it) {
                if (!(*it).isNationWide || (*it).coverageType <= bestCoverageType) {
                    continue;
                }

                for (auto type : { CoverageArea::Realtime, CoverageArea::Regular }) {
                    if (type >= (*it).coverageType) {
                        break;
                    }
                    if (!(*it).backend.coverageArea(type).isEmpty()) {
                        (*it).country.clear();
                        break;
                    }
                }
            }
        }
    }

    // clean up entries marked for deletion above
    rows.erase(std::remove_if(rows.begin(), rows.end(), [](const auto &r) { return r.country.isEmpty(); }), rows.end());
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
        Q_EMIT dataChanged(index(0, 0), index(rowCount() - 1, 0));
    });
    d->repopulateModel(this);
    Q_EMIT managerChanged();
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
    Q_EMIT modeChanged();
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
        case CountryCodeRole:
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
    names.insert(CountryCodeRole, "countryCode");
    return names;
}

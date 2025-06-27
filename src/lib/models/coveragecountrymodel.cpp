/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "coveragecountrymodel.h"

#include <KPublicTransport/Backend>
#include <KPublicTransport/CoverageArea>
#include <KPublicTransport/Manager>

#include <KCountry>

using namespace Qt::Literals;
using namespace KPublicTransport;

namespace KPublicTransport {
class CoverageCountryModelPrivate {
public:
    Manager *m_mgr = nullptr;
    std::vector<QString> m_countryCodes;
};
}

CoverageCountryModel::CoverageCountryModel(QObject *parent)
    : QAbstractListModel(parent)
    , d(std::make_unique<CoverageCountryModelPrivate>())
{
}

CoverageCountryModel::~CoverageCountryModel() = default;

Manager* CoverageCountryModel::manager() const
{
    return d->m_mgr;
}

void CoverageCountryModel::setManager(Manager *mgr)
{
    if (d->m_mgr == mgr) {
        return;
    }

    if (d->m_mgr) {
        disconnect(d->m_mgr, nullptr, this, nullptr);
    }

    d->m_mgr = mgr;
    connect(mgr, &Manager::backendsChanged, this, &CoverageCountryModel::repopulate);
    connect(mgr, &Manager::configurationChanged, this, &CoverageCountryModel::repopulate);
    Q_EMIT managerChanged();
    repopulate();
}

int CoverageCountryModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return (int)d->m_countryCodes.size();
}

QVariant CoverageCountryModel::data(const QModelIndex &index, int role) const
{
    if (!checkIndex(index)) {
        return {};
    }

    switch (role) {
        case CountryCodeRole:
            return d->m_countryCodes[index.row()];
    }

    return {};
}

QHash<int, QByteArray> CoverageCountryModel::roleNames() const
{
    auto names = QAbstractListModel::roleNames();
    names.insert(CountryCodeRole, "code");
    return names;
}

void CoverageCountryModel::repopulate()
{

    std::vector<QString> newCountryCodes;
    for (const auto &backend : d->m_mgr->backends()) {
        if (!d->m_mgr->isBackendEnabled(backend.identifier())) {
            continue;
        }
        for (const auto cov : {CoverageArea::Realtime, CoverageArea::Regular, CoverageArea::Any}) {
            const auto regions = backend.coverageArea(cov).regions();
            for (const auto &region : regions) {
                // TODO XK should be enabled here eventualy, but iso-codes doesn't have that
                // so neither our sorting nor our display code will work correctly for that
                if (region == "UN"_L1 || region == "EU"_L1 || region == "XK"_L1) {
                    continue;
                }
                const auto code = region.left(2);
                auto it = std::ranges::lower_bound(newCountryCodes, code);
                if (it == newCountryCodes.end() || (*it) != code) {
                    newCountryCodes.insert(it, code);
                }
            }
        }
    }

    std::ranges::sort(newCountryCodes, [](const auto &lhs, const auto &rhs) {
        return KCountry::fromAlpha2(lhs).name().localeAwareCompare(KCountry::fromAlpha2(rhs).name()) < 0;
    });

    // incrementally update to keep the selection in the UI
    // which unfortunately is entirely pointless as QML's combo box can't deal with that yet :(
    // ### also, there's the case of a locale change (which also emits Manager::backendsChanged()),
    // in which breaks the sorting assumptions here
#if 0
    if (d->m_countryCodes.empty() || newCountryCodes.empty()) {
        beginResetModel();
        std::swap(d->m_countryCodes, newCountryCodes);
        endResetModel();
        return;
    }

    auto itNew = newCountryCodes.begin();
    auto itCur = d->m_countryCodes.begin();
    for (;itNew != newCountryCodes.end() && itCur != d->m_countryCodes.end();) {
        if ((*itNew) == (*itCur)) {
            ++itCur;
            ++itNew;
            continue;
        }
        const auto row = (int)std::distance(d->m_countryCodes.begin(), itCur);
        if (KCountry::fromAlpha2(*itCur).name().localeAwareCompare(KCountry::fromAlpha2(*itNew).name()) < 0) {
            beginRemoveRows({}, row, row);
            itCur = d->m_countryCodes.erase(itCur);
            endRemoveRows();
        } else {
            beginInsertRows({}, row, row);
            itCur = d->m_countryCodes.insert(itCur, (*itNew++));
            ++itCur;
            endInsertRows();
        }
    }

    if (itNew != newCountryCodes.end()) {
        beginInsertRows({}, (int)d->m_countryCodes.size(), (int)d->m_countryCodes.size() + (int)std::distance(itNew, newCountryCodes.end() - 1));
        std::copy(itNew, newCountryCodes.end(), std::back_inserter(d->m_countryCodes));
        endInsertRows();
    } else if (itCur != d->m_countryCodes.end()) {
        beginRemoveRows({}, (int)std::distance(d->m_countryCodes.begin(), itCur), (int)d->m_countryCodes.size());
        d->m_countryCodes.erase(itCur, d->m_countryCodes.end());
        endRemoveRows();
    }
#endif

    beginResetModel();
    std::swap(d->m_countryCodes, newCountryCodes);
    endResetModel();
}

#include "moc_coveragecountrymodel.cpp"

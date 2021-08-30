/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "locationquerymodel.h"
#include "abstractquerymodel_p.h"
#include "logging.h"
#include "../datatypes/locationutil_p.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/Manager>

#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class LocationQueryModelPrivate : public AbstractQueryModelPrivate
{
public:
    void doQuery() override;
    void doClearResults() override;
    void mergeResults(const std::vector<Location> &newLocations);
    bool isFiltered(const Location &loc) const;

    std::vector<Location> m_locations;

    LocationRequest m_request;

    Q_DECLARE_PUBLIC(LocationQueryModel)
};
}

void LocationQueryModelPrivate::doQuery()
{
    Q_Q(LocationQueryModel);
    if (!m_manager || !m_request.isValid()) {
        return;
    }

    setLoading(true);
    auto reply = m_manager->queryLocation(m_request);
    monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::LocationReply::updated, q, [reply, this]() {
        mergeResults(reply->takeResult());
    });
}

void LocationQueryModelPrivate::doClearResults()
{
    m_locations.clear();
}

bool LocationQueryModelPrivate::isFiltered(const Location &loc) const
{
    if (m_request.types() != Location::Place && loc.type() != Location::Place && (loc.type() & m_request.types()) == 0) {
        return true;
    }

    if (m_request.hasCoordinate() && m_request.maximumDistance() > 0) {
        return Location::distance(m_request.latitude(), m_request.longitude(), loc.latitude(), loc.longitude()) > m_request.maximumDistance();
    }

    return false;
}

void LocationQueryModelPrivate::mergeResults(const std::vector<Location> &newLocations)
{
    Q_Q(LocationQueryModel);

    for (const auto &loc : newLocations) {
        if (isFiltered(loc)) {
            continue;
        }

        // lacking an actual useful ordering, we need to do a full search for merging
        // LocationUtil::sortLessThan provides an order, but proximity there does not imply
        // always all merge candidates are nearby unfortunately (e.g. in cases of native
        // language vs. English spelling in case of name searches).
        bool found = false;
        for (auto it = m_locations.begin(); it != m_locations.end(); ++it) {
            if (Location::isSame(*it, loc)) {
                *it = Location::merge(loc, *it);
                found = true;
                const auto row = std::distance(m_locations.begin(), it);
                const auto idx = q->index(row, 0);
                Q_EMIT q->dataChanged(idx, idx);
                break;
            }
        }
        if (found) {
            continue;
        }

        auto it = std::lower_bound(m_locations.begin(), m_locations.end(), loc, [this](const auto &lhs, const auto &rhs) {
            return LocationUtil::sortLessThan(m_request, lhs, rhs);
        });

        const auto row = std::distance(m_locations.begin(), it);
        q->beginInsertRows({}, row, row);
        m_locations.insert(it, loc);
        q->endInsertRows();
    }
}


LocationQueryModel::LocationQueryModel(QObject* parent)
    : AbstractQueryModel(new LocationQueryModelPrivate, parent)
{
}

LocationQueryModel::~LocationQueryModel() = default;

LocationRequest LocationQueryModel::request() const
{
    Q_D(const LocationQueryModel);
    return d->m_request;
}

void LocationQueryModel::setRequest(const LocationRequest &req)
{
    Q_D(LocationQueryModel);
    d->m_request = req;
    Q_EMIT requestChanged();
    d->query();
}

int LocationQueryModel::rowCount(const QModelIndex &parent) const
{
    Q_D(const LocationQueryModel);
    if (parent.isValid()) {
        return 0;
    }
    return d->m_locations.size();
}

QVariant LocationQueryModel::data(const QModelIndex &index, int role) const
{
    Q_D(const LocationQueryModel);
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case Qt::DisplayRole:
            return d->m_locations[index.row()].name();
        case LocationRole:
            return QVariant::fromValue(d->m_locations[index.row()]);
    }

    return {};
}

QHash<int, QByteArray> LocationQueryModel::roleNames() const
{
    auto r = QAbstractListModel::roleNames();
    r.insert(LocationRole, "location");
    return r;
}

const std::vector<Location>& LocationQueryModel::locations() const
{
    Q_D(const LocationQueryModel);
    return d->m_locations;
}

#include "moc_locationquerymodel.moc"

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

#include "locationquerymodel.h"
#include "abstractquerymodel_p.h"
#include "logging.h"

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
    void queryLocations();
    void mergeResults(const std::vector<Location> &newLocations);

    std::vector<Location> m_locations;

    LocationRequest m_request;

    Q_DECLARE_PUBLIC(LocationQueryModel)
};
}

void LocationQueryModelPrivate::queryLocations()
{
    Q_Q(LocationQueryModel);
    if (!m_manager || m_request.isEmpty()) {
        return;
    }

    resetForNewRequest();
    if (!m_locations.empty()) {
        q->beginResetModel();
        m_locations.clear();
        q->endResetModel();
    }

    auto reply = m_manager->queryLocation(m_request);
    monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::LocationReply::finished, reply, &QObject::deleteLater);
    QObject::connect(reply, &KPublicTransport::LocationReply::updated, q, [reply, this]() {
        mergeResults(reply->takeResult());
    });
}

void LocationQueryModelPrivate::mergeResults(const std::vector<Location> &newLocations)
{
    Q_Q(LocationQueryModel);
    // TODO for coordinate-based searches we can use a distance-based order here, for name-based we need some form of order too
    for (const auto &loc : newLocations) {
        bool found = false;
        for (auto it = m_locations.begin(); it != m_locations.end(); ++it) {
            if (Location::isSame(*it, loc)) {
                *it = Location::merge(loc, *it);
                found = true;
                const auto row = std::distance(m_locations.begin(), it);
                const auto idx = q->index(row, 0);
                emit q->dataChanged(idx, idx);
                break;
            }
        }
        if (found) {
            continue;
        }

        const auto row = m_locations.size();
        q->beginInsertRows({}, row, row);
        m_locations.push_back(loc);
        q->endInsertRows();
    }
}


LocationQueryModel::LocationQueryModel(QObject* parent)
    : AbstractQueryModel(new LocationQueryModelPrivate, parent)
{
    Q_D(LocationQueryModel);
    connect(this, &AbstractQueryModel::managerChanged, this, [d]() { d->queryLocations(); });
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
    emit requestChanged();
    d->queryLocations();
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

#include "moc_locationquerymodel.moc"

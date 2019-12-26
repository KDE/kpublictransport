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

#include "vehiclelayoutquerymodel.h"
#include "abstractquerymodel_p.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Vehicle>
#include <KPublicTransport/VehicleLayoutReply>
#include <KPublicTransport/Manager>

#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class VehicleLayoutQueryModelPrivate : public AbstractQueryModelPrivate
{
public:
    void doQuery() override;

    Vehicle m_vehicle;
    VehicleLayoutRequest m_request;
    Platform m_platform;
    Departure m_departure;

    Q_DECLARE_PUBLIC(VehicleLayoutQueryModel)
};
}

void VehicleLayoutQueryModelPrivate::doQuery()
{
    Q_Q(VehicleLayoutQueryModel);
    if (!m_manager || !m_request.isValid()) {
        return;
    }

    resetForNewRequest();
    // TODO
//     if (!m_locations.empty()) {
//         q->beginResetModel();
//         m_locations.clear();
//         q->endResetModel();
//     }

    auto reply = m_manager->queryVehicleLayout(m_request);
    monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::VehicleLayoutReply::finished, q, [reply, this]() {
        Q_Q(VehicleLayoutQueryModel);
        q->beginResetModel();
        m_vehicle = reply->vehicle();
        m_platform = reply->platform();
        m_departure = reply->departure();
        q->endResetModel();
        emit q->contentChanged();
        reply->deleteLater();
    });
}

VehicleLayoutQueryModel::VehicleLayoutQueryModel(QObject* parent)
    : AbstractQueryModel(new VehicleLayoutQueryModelPrivate, parent)
{
}

VehicleLayoutQueryModel::~VehicleLayoutQueryModel() = default;

VehicleLayoutRequest VehicleLayoutQueryModel::request() const
{
    Q_D(const VehicleLayoutQueryModel);
    return d->m_request;
}

void VehicleLayoutQueryModel::setRequest(const VehicleLayoutRequest &req)
{
    Q_D(VehicleLayoutQueryModel);
    d->m_request = req;
    emit requestChanged();
    d->query();
}

Platform VehicleLayoutQueryModel::platform() const
{
    Q_D(const VehicleLayoutQueryModel);
    return d->m_platform;
}

Departure VehicleLayoutQueryModel::departure() const
{
    Q_D(const VehicleLayoutQueryModel);
    return d->m_departure;
}

int VehicleLayoutQueryModel::rowCount(const QModelIndex &parent) const
{
    Q_D(const VehicleLayoutQueryModel);
    if (parent.isValid()) {
        return 0;
    }
    return d->m_vehicle.sections().size();
}

QVariant VehicleLayoutQueryModel::data(const QModelIndex &index, int role) const
{
    Q_D(const VehicleLayoutQueryModel);
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case VehicleSectionRole:
            return QVariant::fromValue(d->m_vehicle.sections()[index.row()]);
    }

    return {};
}

QHash<int, QByteArray> VehicleLayoutQueryModel::roleNames() const
{
    auto r = QAbstractListModel::roleNames();
    r.insert(VehicleSectionRole, "vehicleSection");
    return r;
}

#include "moc_vehiclelayoutquerymodel.moc"

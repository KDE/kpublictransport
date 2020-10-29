/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
    void doClearResults() override;

    Vehicle m_vehicle;
    VehicleLayoutRequest m_request;
    Platform m_platform;
    Stopover m_departure;

    Q_DECLARE_PUBLIC(VehicleLayoutQueryModel)
};
}

void VehicleLayoutQueryModelPrivate::doQuery()
{
    Q_Q(VehicleLayoutQueryModel);
    if (!m_manager || !m_request.isValid()) {
        return;
    }

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
    });
}

void VehicleLayoutQueryModelPrivate::doClearResults()
{
    m_vehicle = {};
    m_platform = {};
    m_departure = {};
    Q_Q(VehicleLayoutQueryModel);
    emit q->contentChanged();
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

Vehicle VehicleLayoutQueryModel::vehicle() const
{
    Q_D(const VehicleLayoutQueryModel);
    return d->m_vehicle;
}

Platform VehicleLayoutQueryModel::platform() const
{
    Q_D(const VehicleLayoutQueryModel);
    return d->m_platform;
}

Stopover VehicleLayoutQueryModel::departure() const
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

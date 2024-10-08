/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "vehiclelayoutquerymodel.h"
#include "abstractquerymodel_p.h"

#include <KPublicTransport/Attribution>
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

    void interpolatePlatformPositionsFromSectionName();
    template <typename Iter>
    void interpolatePlatformPositionsFromSectionName(Iter begin, Iter end);

    VehicleLayoutRequest m_request;
    Stopover m_stopover;

    Q_DECLARE_PUBLIC(VehicleLayoutQueryModel)
};
}

void VehicleLayoutQueryModelPrivate::doQuery()
{
    Q_Q(VehicleLayoutQueryModel);
    if (!m_manager || !m_request.isValid()) {
        return;
    }

    // if the request already contains useful information, let's use those already
    q->beginResetModel();
    m_stopover = m_request.stopover();
    q->endResetModel();
    Q_EMIT q->contentChanged();

    setLoading(true);
    auto reply = m_manager->queryVehicleLayout(m_request);
    monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::VehicleLayoutReply::finished, q, [reply, this]() {
        Q_Q(VehicleLayoutQueryModel);
        q->beginResetModel();
        m_stopover = reply->stopover();
        if (!m_stopover.platformLayout().isEmpty() && !m_stopover.vehicleLayout().isEmpty()
         && !m_stopover.vehicleLayout().hasPlatformPositions() && m_stopover.vehicleLayout().hasPlatformSectionNames()) {
            interpolatePlatformPositionsFromSectionName();
        }
        q->endResetModel();
        Q_EMIT q->contentChanged();
    });
}

void VehicleLayoutQueryModelPrivate::doClearResults()
{
    m_stopover = {};
    Q_Q(VehicleLayoutQueryModel);
    Q_EMIT q->contentChanged();
}

void VehicleLayoutQueryModelPrivate::interpolatePlatformPositionsFromSectionName()
{
    auto vehicle = m_stopover.vehicleLayout();
    auto vehicleSections = vehicle.takeSections();
    const auto startSection = vehicleSections.front().platformSectionName();
    const auto endSection = vehicleSections.back().platformSectionName();

    const auto platform = m_stopover.platformLayout();
    for (const auto &sec : platform.sections()) {
        if (sec.name() == startSection) {
            interpolatePlatformPositionsFromSectionName(vehicleSections.begin(), vehicleSections.end());
            break;
        } else if (sec.name() == endSection) {
            interpolatePlatformPositionsFromSectionName(vehicleSections.rbegin(), vehicleSections.rend());
            break;
        }
    }

    vehicle.setSections(std::move(vehicleSections));
    m_stopover.setVehicleLayout(std::move(vehicle));
}

template<typename Iter>
void VehicleLayoutQueryModelPrivate::interpolatePlatformPositionsFromSectionName(Iter begin, Iter end)
{
    auto rangeBegin = begin, rangeEnd = begin;
    float minLength = 1.0;
    while (rangeBegin != end) {
        while (rangeEnd != end && (*rangeBegin).platformSectionName() == (*rangeEnd).platformSectionName()) {
            ++rangeEnd;
        }

        const auto platformIt = std::find_if(m_stopover.platformLayout().sections().begin(), m_stopover.platformLayout().sections().end(), [&rangeBegin](const auto &p) {
            return p.name() == (*rangeBegin).platformSectionName();
        });
        if (platformIt == m_stopover.platformLayout().sections().end()) {
            qWarning() << "Failed to find platform section" << (*rangeBegin).platformSectionName();
            return;
        }

        auto l = ((*platformIt).end() - (*platformIt).begin()) / std::distance(rangeBegin, rangeEnd);
        minLength = std::min(minLength, l);

        if (rangeEnd == end) { // trailing coaches, don't scale them to the full section
            l = minLength;
        }

        auto pos = (*platformIt).begin();
        for (auto it = rangeBegin; it != rangeEnd; ++it) {
            (*it).setPlatformPositionBegin(pos);
            (*it).setPlatformPositionEnd(pos + l);
            pos += l;
        }

        rangeBegin = rangeEnd;
    }

    // fix-up leading coaches to not fill up the entire platform section
    rangeEnd = std::find_if(begin, end, [&begin](const auto &p) {
        return p.platformSectionName() != (*begin).platformSectionName();
    });
    auto pos = (*std::prev(rangeEnd)).platformPositionEnd() - std::distance(begin, rangeEnd) * minLength;
    for (auto it = begin; it != rangeEnd; ++it) {
        (*it).setPlatformPositionBegin(pos);
        (*it).setPlatformPositionEnd(pos + minLength);
        pos += minLength;
    }
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
    Q_EMIT requestChanged();
    d->query();
}

Vehicle VehicleLayoutQueryModel::vehicle() const
{
    return stopover().vehicleLayout();
}

Platform VehicleLayoutQueryModel::platform() const
{
    return stopover().platformLayout();
}

Stopover VehicleLayoutQueryModel::stopover() const
{
    Q_D(const VehicleLayoutQueryModel);
    return d->m_stopover;
}

int VehicleLayoutQueryModel::rowCount(const QModelIndex &parent) const
{
    Q_D(const VehicleLayoutQueryModel);
    if (parent.isValid()) {
        return 0;
    }
    return d->m_stopover.vehicleLayout().sections().size();
}

QVariant VehicleLayoutQueryModel::data(const QModelIndex &index, int role) const
{
    Q_D(const VehicleLayoutQueryModel);
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case VehicleSectionRole:
            return QVariant::fromValue(d->m_stopover.vehicleLayout().sections()[index.row()]);
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

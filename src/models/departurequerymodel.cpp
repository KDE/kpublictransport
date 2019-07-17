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

#include "departurequerymodel.h"
#include "abstractquerymodel_p.h"
#include "logging.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Departure>
#include <KPublicTransport/DepartureReply>
#include <KPublicTransport/Manager>

#include <QDateTime>
#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class DepartureQueryModelPrivate : public AbstractQueryModelPrivate
{
public:
    void queryDeparture();
    void mergeResults(std::vector<Departure> &&res);

    std::vector<Departure> m_departures;

    DepartureRequest m_request;
    DepartureRequest m_nextRequest;
    DepartureRequest m_prevRequest;

    Q_DECLARE_PUBLIC(DepartureQueryModel)
};
}

void DepartureQueryModelPrivate::queryDeparture()
{
    Q_Q(DepartureQueryModel);
    if (!m_manager || m_request.isEmpty()) {
        return;
    }

    resetForNewRequest();
    if (!m_departures.empty()) {
        q->beginResetModel();
        m_departures.clear();
        q->endResetModel();
    }
    m_nextRequest = {};
    m_prevRequest = {};
    emit q->canQueryPrevNextChanged();

    auto reply = m_manager->queryDeparture(m_request);
    monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::DepartureReply::finished, q, [reply, q, this]{
        if (reply->error() == KPublicTransport::DepartureReply::NoError) {
            q->beginResetModel();
            m_departures = reply->takeResult();
            m_nextRequest = reply->nextRequest();
            m_prevRequest = reply->previousRequest();
            q->endResetModel();
        }
        reply->deleteLater();
        emit q->canQueryPrevNextChanged();
    });
}

void DepartureQueryModelPrivate::mergeResults(std::vector<Departure> &&res)
{
    Q_Q(DepartureQueryModel);
    Q_ASSERT(!m_departures.empty());
    auto result = std::move(res);
    if (result.empty()) {
        return;
    }

    // sort and merge results, aligned by first transport departure
    // TODO this is actually wrong for arrivals!
    std::sort(result.begin(), result.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.scheduledDepartureTime() < rhs.scheduledDepartureTime();
    });

    auto depIt = m_departures.begin();
    auto resIt = result.begin();

    while (true) {
        if (resIt == result.end()) {
            break;
        }

        if (depIt == m_departures.end()) {
            const auto row = std::distance(m_departures.begin(), depIt);
            q->beginInsertRows({}, row, row + std::distance(resIt, result.end()) - 1);
            m_departures.insert(depIt, resIt, result.end());
            q->endInsertRows();
            break;
        }

        if ((*resIt).scheduledDepartureTime() < (*depIt).scheduledDepartureTime()) {
            const auto row = std::distance(m_departures.begin(), depIt);
            q->beginInsertRows({}, row, row);
            depIt = m_departures.insert(depIt, *resIt);
            ++resIt;
            q->endInsertRows();
            continue;
        }

        if ((*depIt).scheduledDepartureTime() < (*resIt).scheduledDepartureTime()) {
            ++depIt;
            continue;
        }

        if (Departure::isSame(*depIt, *resIt)) {
            *depIt = Departure::merge(*depIt, *resIt);
            ++resIt;
            const auto row = std::distance(m_departures.begin(), depIt);
            const auto idx = q->index(row, 0);
            emit q->dataChanged(idx, idx);
        } else {
            ++depIt;
        }
    }
}


DepartureQueryModel::DepartureQueryModel(QObject *parent)
    : AbstractQueryModel(new DepartureQueryModelPrivate, parent)
{
    Q_D(DepartureQueryModel);
    connect(this, &AbstractQueryModel::managerChanged, this, [d]() { d->queryDeparture(); });
    connect(this, &AbstractQueryModel::loadingChanged, this, &DepartureQueryModel::canQueryPrevNextChanged);
}

DepartureQueryModel::~DepartureQueryModel() = default;

DepartureRequest DepartureQueryModel::request() const
{
    Q_D(const DepartureQueryModel);
    return d->m_request;
}

void DepartureQueryModel::setRequest(const DepartureRequest &req)
{
    Q_D(DepartureQueryModel);
    d->m_request = req;
    emit requestChanged();
    d->queryDeparture();
}

bool DepartureQueryModel::canQueryNext() const
{
    Q_D(const DepartureQueryModel);
    return !d->m_loading && !d->m_departures.empty() && !d->m_nextRequest.isEmpty();
}

void DepartureQueryModel::queryNext()
{
    Q_D(DepartureQueryModel);
    if (!canQueryNext()) {
        qCWarning(Log) << "Cannot query next journeys";
        return;
    }

    d->setLoading(true);
    auto reply = d->m_manager->queryDeparture(d->m_nextRequest);
    d->monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::DepartureReply::finished, this, [reply, this] {
        Q_D(DepartureQueryModel);
        if (reply->error() == KPublicTransport::DepartureReply::NoError) {
            d->mergeResults(std::move(reply->takeResult()));
            d->m_nextRequest = reply->nextRequest();
        } else {
            d->m_nextRequest = {};
        }
        emit canQueryPrevNextChanged();
        reply->deleteLater();
    });
}

bool DepartureQueryModel::canQueryPrevious() const
{
    Q_D(const DepartureQueryModel);
    return !d->m_loading && !d->m_departures.empty() && !d->m_prevRequest.isEmpty();
}

void DepartureQueryModel::queryPrevious()
{
    Q_D(DepartureQueryModel);
    if (!canQueryPrevious()) {
        qCWarning(Log) << "Cannot query previous journeys";
        return;
    }

    d->setLoading(true);
    auto reply = d->m_manager->queryDeparture(d->m_prevRequest);
    d->monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::DepartureReply::finished, this, [reply, this] {
        Q_D(DepartureQueryModel);
        if (reply->error() == KPublicTransport::DepartureReply::NoError) {
            d->mergeResults(std::move(reply->takeResult()));
            d->m_prevRequest = reply->previousRequest();
        } else {
            d->m_prevRequest = {};
        }
        emit canQueryPrevNextChanged();
        reply->deleteLater();
    });
}

int DepartureQueryModel::rowCount(const QModelIndex& parent) const
{
    Q_D(const DepartureQueryModel);
    if (parent.isValid()) {
        return 0;
    }
    return d->m_departures.size();
}

QVariant DepartureQueryModel::data(const QModelIndex& index, int role) const
{
    Q_D(const DepartureQueryModel);
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case DepartureRole:
            return QVariant::fromValue(d->m_departures[index.row()]);
    }

    return {};
}

QHash<int, QByteArray> DepartureQueryModel::roleNames() const
{
    auto r = QAbstractListModel::roleNames();
    r.insert(DepartureRole, "departure");
    return r;
}

const std::vector<Departure>& DepartureQueryModel::departures() const
{
    Q_D(const DepartureQueryModel);
    return d->m_departures;
}

#include "moc_departurequerymodel.moc"

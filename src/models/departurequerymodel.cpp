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
#include "logging.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Departure>
#include <KPublicTransport/DepartureReply>
#include <KPublicTransport/Manager>

#include <QDateTime>
#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class DepartureQueryModelPrivate
{
public:
    Manager *mgr = nullptr;

    void queryDeparture(DepartureQueryModel *q);
    void mergeResults(DepartureQueryModel *q, std::vector<Departure> &&res);

    std::vector<Departure> m_departures;

    DepartureRequest m_request;
    DepartureRequest m_nextRequest;
    DepartureRequest m_prevRequest;

    std::vector<Attribution> m_attributions;
    QString m_errorMessage;
    bool m_loading = false;
};
}

void DepartureQueryModelPrivate::queryDeparture(DepartureQueryModel *q)
{
    m_errorMessage.clear();
    emit q->errorMessageChanged();
    m_loading = true;
    emit q->loadingChanged();
    emit q->canQueryPrevNextChanged();
    if (!m_departures.empty()) {
        q->beginResetModel();
        m_departures.clear();
        q->endResetModel();
    }
    m_nextRequest = {};
    m_prevRequest = {};
    m_attributions.clear();
    emit q->attributionsChanged();

    auto reply = mgr->queryDeparture(m_request);
    QObject::connect(reply, &KPublicTransport::DepartureReply::finished, q, [reply, q, this]{
        m_loading = false;
        emit q->loadingChanged();
        if (reply->error() == KPublicTransport::DepartureReply::NoError) {
            q->beginResetModel();
            m_departures = reply->takeResult();
            m_nextRequest = reply->nextRequest();
            m_prevRequest = reply->previousRequest();
            m_attributions = std::move(reply->takeAttributions());
            emit q->attributionsChanged();
            q->endResetModel();
        } else {
            m_errorMessage = reply->errorString();
            emit q->errorMessageChanged();
        }
        reply->deleteLater();
        emit q->canQueryPrevNextChanged();
    });
}

void DepartureQueryModelPrivate::mergeResults(DepartureQueryModel *q, std::vector<Departure> &&res)
{
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
    : QAbstractListModel(parent)
    , d(new DepartureQueryModelPrivate)
{
}

DepartureQueryModel::~DepartureQueryModel() = default;

Manager* DepartureQueryModel::manager() const
{
    return d->mgr;
}

void DepartureQueryModel::setManager(Manager *mgr)
{
    if (d->mgr == mgr) {
        return;
    }

    d->mgr = mgr;
    emit managerChanged();
    if (d->mgr && !d->m_request.isEmpty()) {
        d->queryDeparture(this);
    }
}

DepartureRequest DepartureQueryModel::request() const
{
    return d->m_request;
}

void DepartureQueryModel::setRequest(const DepartureRequest &req)
{
    d->m_request = req;
    emit requestChanged();
    if (d->mgr && !req.isEmpty()) {
        d->queryDeparture(this);
    }
}

bool DepartureQueryModel::isLoading() const
{
    return d->m_loading;
}

QString DepartureQueryModel::errorMessage() const
{
    return d->m_errorMessage;
}

bool DepartureQueryModel::canQueryNext() const
{
    return !d->m_loading && !d->m_departures.empty() && !d->m_nextRequest.isEmpty();
}

void DepartureQueryModel::queryNext()
{
    if (!canQueryNext()) {
        qCWarning(Log) << "Cannot query next journeys";
        return;
    }

    d->m_loading = true;
    emit loadingChanged();
    emit canQueryPrevNextChanged();

    auto reply = d->mgr->queryDeparture(d->m_nextRequest);
    QObject::connect(reply, &KPublicTransport::DepartureReply::finished, this, [reply, this]{
        d->m_loading = false;
        emit loadingChanged();
        if (reply->error() == KPublicTransport::DepartureReply::NoError) {
            d->mergeResults(this, std::move(reply->takeResult()));
            d->m_nextRequest = reply->nextRequest();
            // TODO check if there are new attributions
        } else {
            d->m_errorMessage = reply->errorString();
            d->m_nextRequest = {};
            emit errorMessageChanged();
        }
        reply->deleteLater();
        emit canQueryPrevNextChanged();
    });
}

bool DepartureQueryModel::canQueryPrevious() const
{
    return !d->m_loading && !d->m_departures.empty() && !d->m_prevRequest.isEmpty();
}

void DepartureQueryModel::queryPrevious()
{
    if (!canQueryPrevious()) {
        qCWarning(Log) << "Cannot query previous journeys";
        return;
    }

    d->m_loading = true;
    emit loadingChanged();
    emit canQueryPrevNextChanged();

    auto reply = d->mgr->queryDeparture(d->m_prevRequest);
    QObject::connect(reply, &KPublicTransport::DepartureReply::finished, this, [reply, this]{
        d->m_loading = false;
        emit loadingChanged();
        if (reply->error() == KPublicTransport::DepartureReply::NoError) {
            d->mergeResults(this, std::move(reply->takeResult()));
            d->m_prevRequest = reply->previousRequest();
            // TODO check if there are new attributions
        } else {
            d->m_errorMessage = reply->errorString();
            d->m_prevRequest = {};
            emit errorMessageChanged();
        }
        reply->deleteLater();
        emit canQueryPrevNextChanged();
    });
}

int DepartureQueryModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return d->m_departures.size();
}

QVariant DepartureQueryModel::data(const QModelIndex& index, int role) const
{
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
    return d->m_departures;
}

const std::vector<Attribution>& DepartureQueryModel::attributions() const
{
    return d->m_attributions;
}

QVariantList DepartureQueryModel::attributionsVariant() const
{
    QVariantList l;
    l.reserve(d->m_attributions.size());
    std::transform(d->m_attributions.begin(), d->m_attributions.end(), std::back_inserter(l), [](const auto &attr) { return QVariant::fromValue(attr); });
    return l;
}

#include "moc_departurequerymodel.moc"

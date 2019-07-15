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
#include <KPublicTransport/DepartureRequest>
#include <KPublicTransport/Manager>

#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class DepartureQueryModelPrivate
{
public:
    Manager *mgr = nullptr;

    void mergeResults(DepartureQueryModel *q, std::vector<Departure> &&res);

    std::vector<Departure> m_departures;

    DepartureRequest m_nextRequest;
    DepartureRequest m_prevRequest;

    std::vector<Attribution> m_attributions;
    QString m_errorMessage;
    bool m_loading = false;
};
}

void DepartureQueryModelPrivate::mergeResults(DepartureQueryModel *q, std::vector<Departure> &&res)
{
    // TODO
}


DepartureQueryModel::DepartureQueryModel(QObject *parent)
    : QAbstractListModel(parent)
    , d(new DepartureQueryModelPrivate)
{
}

DepartureQueryModel::~DepartureQueryModel() = default;

void DepartureQueryModel::setManager(Manager *mgr)
{
    d->mgr = mgr;
}

void DepartureQueryModel::setRequest(const DepartureRequest &req)
{
    if (!d->mgr) {
        qCWarning(Log) << "No KPublicTransport::Manager set!";
        return;
    }

    d->m_errorMessage.clear();
    emit errorMessageChanged();
    d->m_loading = true;
    emit loadingChanged();
    emit canQueryPrevNextChanged();
    if (!d->m_departures.empty()) {
        beginResetModel();
        d->m_departures.clear();
        endResetModel();
    }
    d->m_nextRequest = {};
    d->m_prevRequest = {};
    d->m_attributions.clear();
    emit attributionsChanged();

    auto reply = d->mgr->queryDeparture(req);
    QObject::connect(reply, &KPublicTransport::DepartureReply::finished, this, [reply, this]{
        d->m_loading = false;
        emit loadingChanged();
        if (reply->error() == KPublicTransport::DepartureReply::NoError) {
            beginResetModel();
            d->m_departures = reply->takeResult();
            d->m_nextRequest = reply->nextRequest();
            d->m_prevRequest = reply->previousRequest();
            d->m_attributions = std::move(reply->takeAttributions());
            emit attributionsChanged();
            endResetModel();
        } else {
            d->m_errorMessage = reply->errorString();
            emit errorMessageChanged();
        }
        reply->deleteLater();
        emit canQueryPrevNextChanged();
    });
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

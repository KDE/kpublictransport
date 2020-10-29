/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "stopoverquerymodel.h"
#include "abstractquerymodel_p.h"
#include "logging.h"
#include "datatypes/stopoverutil_p.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Manager>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/StopoverReply>

#include <QDateTime>
#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class StopoverQueryModelPrivate : public AbstractQueryModelPrivate
{
public:
    void doQuery() override;
    void doClearResults() override;
    void mergeResults(const std::vector<Stopover> &newDepartures);

    std::vector<Stopover> m_departures;

    StopoverRequest m_request;
    StopoverRequest m_nextRequest;
    StopoverRequest m_prevRequest;

    Q_DECLARE_PUBLIC(StopoverQueryModel)
};
}

void StopoverQueryModelPrivate::doQuery()
{
    Q_Q(StopoverQueryModel);
    if (!m_manager || !m_request.isValid()) {
        return;
    }

    setLoading(true);
    m_nextRequest = {};
    m_prevRequest = {};
    emit q->canQueryPrevNextChanged();

    auto reply = m_manager->queryStopover(m_request);
    monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::StopoverReply::finished, q, [reply, q, this]{
        if (reply->error() == KPublicTransport::StopoverReply::NoError) {
            m_nextRequest = reply->nextRequest();
            m_prevRequest = reply->previousRequest();
            emit q->canQueryPrevNextChanged();
        }
    });
    QObject::connect(reply, &KPublicTransport::StopoverReply::updated,q, [reply, this]() {
        mergeResults(reply->takeResult());
    });
}

void StopoverQueryModelPrivate::doClearResults()
{
    m_departures.clear();
}

void StopoverQueryModelPrivate::mergeResults(const std::vector<Stopover> &newDepartures)
{
    Q_Q(StopoverQueryModel);
    for (const auto &dep : newDepartures) {
        auto it = std::lower_bound(m_departures.begin(), m_departures.end(), dep, [this](const auto &lhs, const auto &rhs) {
            return StopoverUtil::timeLessThan(m_request, lhs, rhs);
        });

        bool found = false;
        while (it != m_departures.end() && StopoverUtil::timeEqual(m_request, dep, *it)) {
            if (Stopover::isSame(dep, *it)) {
                *it = Stopover::merge(*it, dep);
                found = true;
                const auto row = std::distance(m_departures.begin(), it);
                const auto idx = q->index(row, 0);
                emit q->dataChanged(idx, idx);
                break;
            } else {
                ++it;
            }
        }
        if (found) {
            continue;
        }

        const auto row = std::distance(m_departures.begin(), it);
        q->beginInsertRows({}, row, row);
        m_departures.insert(it, dep);
        q->endInsertRows();
    }
}


StopoverQueryModel::StopoverQueryModel(QObject *parent)
    : AbstractQueryModel(new StopoverQueryModelPrivate, parent)
{
    connect(this, &AbstractQueryModel::loadingChanged, this, &StopoverQueryModel::canQueryPrevNextChanged);
}

StopoverQueryModel::~StopoverQueryModel() = default;

StopoverRequest StopoverQueryModel::request() const
{
    Q_D(const StopoverQueryModel);
    return d->m_request;
}

void StopoverQueryModel::setRequest(const StopoverRequest &req)
{
    Q_D(StopoverQueryModel);
    d->m_request = req;
    emit requestChanged();
    d->query();
}

bool StopoverQueryModel::canQueryNext() const
{
    Q_D(const StopoverQueryModel);
    return !d->m_loading && !d->m_departures.empty() && d->m_nextRequest.isValid();
}

void StopoverQueryModel::queryNext()
{
    Q_D(StopoverQueryModel);
    if (!canQueryNext()) {
        qCWarning(Log) << "Cannot query next journeys";
        return;
    }

    d->setLoading(true);
    auto reply = d->m_manager->queryStopover(d->m_nextRequest);
    d->monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::StopoverReply::finished, this, [reply, this] {
        Q_D(StopoverQueryModel);
        if (reply->error() == KPublicTransport::StopoverReply::NoError) {
            d->m_nextRequest = reply->nextRequest();
        } else {
            d->m_nextRequest = {};
        }
        emit canQueryPrevNextChanged();
    });
    QObject::connect(reply, &KPublicTransport::StopoverReply::updated, this, [reply, this]() {
        Q_D(StopoverQueryModel);
        d->mergeResults(reply->takeResult());
    });
}

bool StopoverQueryModel::canQueryPrevious() const
{
    Q_D(const StopoverQueryModel);
    return !d->m_loading && !d->m_departures.empty() && d->m_prevRequest.isValid();
}

void StopoverQueryModel::queryPrevious()
{
    Q_D(StopoverQueryModel);
    if (!canQueryPrevious()) {
        qCWarning(Log) << "Cannot query previous journeys";
        return;
    }

    d->setLoading(true);
    auto reply = d->m_manager->queryStopover(d->m_prevRequest);
    d->monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::StopoverReply::finished, this, [reply, this] {
        Q_D(StopoverQueryModel);
        if (reply->error() == KPublicTransport::StopoverReply::NoError) {
            d->m_prevRequest = reply->previousRequest();
        } else {
            d->m_prevRequest = {};
        }
        emit canQueryPrevNextChanged();
    });
    QObject::connect(reply, &KPublicTransport::StopoverReply::updated, this, [reply, this]() {
        Q_D(StopoverQueryModel);
        d->mergeResults(reply->takeResult());
    });
}

int StopoverQueryModel::rowCount(const QModelIndex& parent) const
{
    Q_D(const StopoverQueryModel);
    if (parent.isValid()) {
        return 0;
    }
    return d->m_departures.size();
}

QVariant StopoverQueryModel::data(const QModelIndex& index, int role) const
{
    Q_D(const StopoverQueryModel);
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case DepartureRole:
            return QVariant::fromValue(d->m_departures[index.row()]);
    }

    return {};
}

QHash<int, QByteArray> StopoverQueryModel::roleNames() const
{
    auto r = QAbstractListModel::roleNames();
    r.insert(DepartureRole, "departure");
    return r;
}

const std::vector<Stopover>& StopoverQueryModel::departures() const
{
    Q_D(const StopoverQueryModel);
    return d->m_departures;
}

#include "moc_stopoverquerymodel.moc"

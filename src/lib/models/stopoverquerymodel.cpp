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
struct StopoverModelEntry {
    Stopover current;
    Stopover next;
};

class StopoverQueryModelPrivate : public AbstractQueryModelPrivate
{
public:
    void doQuery() override;
    void doClearResults() override;
    void mergeResults(const std::vector<Stopover> &newDepartures);
    void applyUpdates();

    std::vector<StopoverModelEntry> m_stopovers;

    StopoverRequest m_request;
    StopoverRequest m_nextRequest;
    StopoverRequest m_prevRequest;

    bool m_autoUpdate = false;
    bool m_isLoadingUpdate = false;
    QTimer m_autoUpdateTimer;

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
    Q_EMIT q->canQueryPrevNextChanged();

    auto reply = m_manager->queryStopover(m_request);
    monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::StopoverReply::finished, q, [reply, q, this]{
        if (reply->error() == KPublicTransport::StopoverReply::NoError) {
            m_nextRequest = reply->nextRequest();
            m_prevRequest = reply->previousRequest();
            Q_EMIT q->canQueryPrevNextChanged();
        }
        if (m_isLoadingUpdate) {
            applyUpdates();
            m_isLoadingUpdate = false;
        }
    });
    QObject::connect(reply, &KPublicTransport::StopoverReply::updated,q, [reply, this]() {
        mergeResults(reply->takeResult());
    });
}

void StopoverQueryModelPrivate::doClearResults()
{
    m_stopovers.clear();
}

void StopoverQueryModelPrivate::mergeResults(const std::vector<Stopover> &newDepartures)
{
    Q_Q(StopoverQueryModel);
    for (const auto &dep : newDepartures) {
        auto it = std::lower_bound(m_stopovers.begin(), m_stopovers.end(), dep, [this](const auto &lhs, const auto &rhs) {
            return StopoverUtil::timeLessThan(m_request, lhs.current, rhs);
        });

        bool found = false;
        while (it != m_stopovers.end() && StopoverUtil::timeEqual(m_request, dep, (*it).current)) {
            if (Stopover::isSame(dep, (*it).current)) {
                found = true;
                if (m_isLoadingUpdate) {
                    (*it).next = Stopover::merge((*it).current, dep);
                } else {
                    (*it).current = Stopover::merge((*it).current, dep);
                    const auto row = (int)std::distance(m_stopovers.begin(), it);
                    const auto idx = q->index(row, 0);
                    Q_EMIT q->dataChanged(idx, idx);
                }
                break;
            } else {
                ++it;
            }
        }
        if (found) {
            continue;
        }

        const auto row = (int)std::distance(m_stopovers.begin(), it);
        q->beginInsertRows({}, row, row);
        m_stopovers.insert(it, { .current = dep, .next = m_isLoadingUpdate ? dep : Stopover() });
        q->endInsertRows();
    }
}

void StopoverQueryModelPrivate::applyUpdates()
{
    Q_Q(StopoverQueryModel);

    for (auto it = m_stopovers.begin(); it != m_stopovers.end();) {
        const auto row = (int)std::distance(m_stopovers.begin(), it);
        if ((*it).next.scheduledDepartureTime().isValid() || (*it).next.scheduledArrivalTime().isValid()) {
            (*it).current = (*it).next;
            (*it).next = {};
            Q_EMIT q->dataChanged(q->index(row, 0), q->index(row, 0));
            ++it;
        } else {
            q->beginRemoveRows({}, row, row);
            it = m_stopovers.erase(it);
            q->endRemoveRows();
        }
    }
}


StopoverQueryModel::StopoverQueryModel(QObject *parent)
    : AbstractQueryModel(new StopoverQueryModelPrivate, parent)
{
    connect(this, &AbstractQueryModel::loadingChanged, this, &StopoverQueryModel::canQueryPrevNextChanged);

    Q_D(StopoverQueryModel);
    d->m_autoUpdateTimer.setTimerType(Qt::VeryCoarseTimer);
    d->m_autoUpdateTimer.setSingleShot(true);
    connect(&d->m_autoUpdateTimer, &QTimer::timeout, this, [this]() {
        Q_D(StopoverQueryModel);

        // trigger QML binding re-evaluation for relative durection displays (e.g. "in N mins")
        Q_EMIT dataChanged(index(0, 0), index(rowCount() - 1, 0));
        d->m_autoUpdateTimer.start(std::chrono::seconds(60) - std::chrono::seconds(QDateTime::currentDateTimeUtc().time().second()));

        // trigger another query if we are tracking the current time
        if (isLoading() || std::abs(d->m_request.dateTime().secsTo(QDateTime::currentDateTimeUtc())) > 600) {
            return;
        }
        d->m_request.setDateTime(QDateTime::currentDateTime());
        d->m_isLoadingUpdate = true;
        d->doQuery();
    });
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
    Q_EMIT requestChanged();
    d->query();
}

bool StopoverQueryModel::canQueryNext() const
{
    Q_D(const StopoverQueryModel);
    return !d->m_loading && !d->m_stopovers.empty() && d->m_nextRequest.isValid();
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
        Q_EMIT canQueryPrevNextChanged();
    });
    QObject::connect(reply, &KPublicTransport::StopoverReply::updated, this, [reply, this]() {
        Q_D(StopoverQueryModel);
        d->mergeResults(reply->takeResult());
    });
}

bool StopoverQueryModel::canQueryPrevious() const
{
    Q_D(const StopoverQueryModel);
    return !d->m_loading && !d->m_stopovers.empty() && d->m_prevRequest.isValid();
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
        Q_EMIT canQueryPrevNextChanged();
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
    return (int)d->m_stopovers.size();
}

QVariant StopoverQueryModel::data(const QModelIndex& index, int role) const
{
    Q_D(const StopoverQueryModel);
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case DepartureRole:
        case StopoverRole:
            return QVariant::fromValue(d->m_stopovers[index.row()].current);
    }

    return {};
}

QHash<int, QByteArray> StopoverQueryModel::roleNames() const
{
    auto r = QAbstractListModel::roleNames();
    r.insert(DepartureRole, "departure");
    r.insert(StopoverRole, "stopover");
    return r;
}

std::vector<Stopover> StopoverQueryModel::departures() const
{
    Q_D(const StopoverQueryModel);
    std::vector<Stopover> deps;
    deps.reserve(d->m_stopovers.size());
    std::ranges::transform(d->m_stopovers, std::back_inserter(deps), [](const auto &s) { return s.current; });
    return deps;;
}

bool StopoverQueryModel::autoUpdate() const
{
    Q_D(const StopoverQueryModel);
    return d->m_autoUpdate;
}

void StopoverQueryModel::setAutoUpdate(bool enable)
{
    Q_D(StopoverQueryModel);
    if (d->m_autoUpdate == enable) {
        return;
    }

    d->m_autoUpdate = enable;
    if (!enable) {
        d->m_autoUpdateTimer.stop();
    } else {
        d->m_autoUpdateTimer.start(std::chrono::seconds(60) - std::chrono::seconds(QDateTime::currentDateTimeUtc().time().second()));
    }

    Q_EMIT autoUpdateChanged();
}

#include "moc_stopoverquerymodel.moc"

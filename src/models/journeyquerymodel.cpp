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

#include "journeyquerymodel.h"
#include "abstractquerymodel_p.h"
#include "logging.h"
#include "../datatypes/journeyutil_p.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Manager>

#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class JourneyQueryModelPrivate : public AbstractQueryModelPrivate
{
public:
    void doQuery() override;
    void mergeResults(const std::vector<Journey> &newJourneys);

    std::vector<Journey> m_journeys;

    JourneyRequest m_request;
    JourneyRequest m_nextRequest;
    JourneyRequest m_prevRequest;

    Q_DECLARE_PUBLIC(JourneyQueryModel)
};
}

void JourneyQueryModelPrivate::doQuery()
{
    Q_Q(JourneyQueryModel);
    if (!m_manager || m_request.isEmpty()) {
        return;
    }

    resetForNewRequest();
    if (!m_journeys.empty()) {
        q->beginResetModel();
        m_journeys.clear();
        q->endResetModel();
    }
    m_nextRequest = {};
    m_prevRequest = {};

    auto reply = m_manager->queryJourney(m_request);
    monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::JourneyReply::finished, q, [reply, this] {
        Q_Q(JourneyQueryModel);
        if (reply->error() == KPublicTransport::JourneyReply::NoError) {
            m_nextRequest = reply->nextRequest();
            m_prevRequest = reply->previousRequest();
            emit q->canQueryPrevNextChanged();
        }
        reply->deleteLater();
    });
    QObject::connect(reply, &KPublicTransport::JourneyReply::updated, q, [reply, this]() {
        mergeResults(reply->takeResult());
    });
}

void JourneyQueryModelPrivate::mergeResults(const std::vector<Journey> &newJourneys)
{
    Q_Q(JourneyQueryModel);
    for (const auto &jny : newJourneys) {
        auto it = std::lower_bound(m_journeys.begin(), m_journeys.end(), jny, JourneyUtil::firstTransportDepartureLessThan);

        bool found = false;
        while (it != m_journeys.end() && JourneyUtil::firstTransportDepartureEqual(jny, *it)) {
            if (Journey::isSame(jny, *it)) {
                *it = Journey::merge(*it, jny);
                found = true;
                const auto row = std::distance(m_journeys.begin(), it);
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

        const auto row = std::distance(m_journeys.begin(), it);
        q->beginInsertRows({}, row, row);
        m_journeys.insert(it, jny);
        q->endInsertRows();
    }
}


JourneyQueryModel::JourneyQueryModel(QObject *parent)
    : AbstractQueryModel(new JourneyQueryModelPrivate, parent)
{
    Q_D(JourneyQueryModel);
    connect(this, &AbstractQueryModel::loadingChanged, this, &JourneyQueryModel::canQueryPrevNextChanged);
}

JourneyQueryModel::~JourneyQueryModel() = default;

JourneyRequest JourneyQueryModel::request() const
{
    Q_D(const JourneyQueryModel);
    return d->m_request;
}

void JourneyQueryModel::setRequest(const JourneyRequest &req)
{
    Q_D(JourneyQueryModel);
    d->m_request = req;
    emit requestChanged();
    d->query();
}

bool JourneyQueryModel::canQueryNext() const
{
    Q_D(const JourneyQueryModel);
    return !d->m_loading && !d->m_journeys.empty() && !d->m_nextRequest.isEmpty();
}

void JourneyQueryModel::queryNext()
{
    Q_D(JourneyQueryModel);
    if (!canQueryNext()) {
        qCWarning(Log) << "Cannot query next journeys";
        return;
    }

    d->setLoading(true);
    auto reply = d->m_manager->queryJourney(d->m_nextRequest);
    d->monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::JourneyReply::finished, this, [reply, this] {
        Q_D(JourneyQueryModel);
        if (reply->error() == KPublicTransport::JourneyReply::NoError) {
            d->m_nextRequest = reply->nextRequest();
        } else {
            d->m_nextRequest = {};
        }
        emit canQueryPrevNextChanged();
        reply->deleteLater();
    });
    QObject::connect(reply, &KPublicTransport::JourneyReply::updated, this, [reply, this]() {
        Q_D(JourneyQueryModel);
        d->mergeResults(reply->takeResult());
    });
}

bool JourneyQueryModel::canQueryPrevious() const
{
    Q_D(const JourneyQueryModel);
    return !d->m_loading && !d->m_journeys.empty() && !d->m_prevRequest.isEmpty();
}

void JourneyQueryModel::queryPrevious()
{
    Q_D(JourneyQueryModel);
    if (!canQueryPrevious()) {
        qCWarning(Log) << "Cannot query previous journeys";
        return;
    }

    d->setLoading(true);
    auto reply = d->m_manager->queryJourney(d->m_prevRequest);
    d->monitorReply(reply);
    QObject::connect(reply, &KPublicTransport::JourneyReply::finished, this, [reply, this] {
        Q_D(JourneyQueryModel);
        if (reply->error() == KPublicTransport::JourneyReply::NoError) {
            d->m_prevRequest = reply->previousRequest();
        } else {
            d->m_prevRequest = {};
        }
        emit canQueryPrevNextChanged();
        reply->deleteLater();
    });
    QObject::connect(reply, &KPublicTransport::JourneyReply::updated, this, [reply, this]() {
        Q_D(JourneyQueryModel);
        d->mergeResults(reply->takeResult());
    });
}

int JourneyQueryModel::rowCount(const QModelIndex& parent) const
{
    Q_D(const JourneyQueryModel);
    if (parent.isValid()) {
        return 0;
    }
    return d->m_journeys.size();
}

QVariant JourneyQueryModel::data(const QModelIndex& index, int role) const
{
    Q_D(const JourneyQueryModel);
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case JourneyRole:
            return QVariant::fromValue(d->m_journeys[index.row()]);
    }

    return {};
}

QHash<int, QByteArray> JourneyQueryModel::roleNames() const
{
    auto r = QAbstractListModel::roleNames();
    r.insert(JourneyRole, "journey");
    return r;
}

const std::vector<Journey>& JourneyQueryModel::journeys() const
{
    Q_D(const JourneyQueryModel);
    return d->m_journeys;
}

#include "moc_journeyquerymodel.cpp"

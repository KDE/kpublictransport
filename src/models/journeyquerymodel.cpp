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
    void queryJourney();
    void mergeResults(std::vector<Journey> &&res);

    std::vector<Journey> m_journeys;

    JourneyRequest m_request;
    JourneyRequest m_nextRequest;
    JourneyRequest m_prevRequest;

    Q_DECLARE_PUBLIC(JourneyQueryModel)
};
}

void JourneyQueryModelPrivate::queryJourney()
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
            q->beginResetModel();
            m_journeys = reply->takeResult();
            m_nextRequest = reply->nextRequest();
            m_prevRequest = reply->previousRequest();
            q->endResetModel();
        }
        emit q->canQueryPrevNextChanged();
        reply->deleteLater();
    });
}

void JourneyQueryModelPrivate::mergeResults(std::vector<Journey> &&res)
{
    Q_Q(JourneyQueryModel);
    Q_ASSERT(!m_journeys.empty());
    auto result = std::move(res);
    if (result.empty()) {
        return;
    }

    // sort and merge results, aligned by first transport departure
    std::sort(result.begin(), result.end(), JourneyUtil::firstTransportDepartureLessThan);
    auto jnyIt = m_journeys.begin();
    auto resIt = result.begin();

    while (true) {
        if (resIt == result.end()) {
            break;
        }

        if (jnyIt == m_journeys.end()) {
            const auto row = std::distance(m_journeys.begin(), jnyIt);
            q->beginInsertRows({}, row, row + std::distance(resIt, result.end()) - 1);
            m_journeys.insert(jnyIt, resIt, result.end());
            q->endInsertRows();
            break;
        }

        if (JourneyUtil::firstTransportDepartureLessThan(*resIt, *jnyIt)) {
            const auto row = std::distance(m_journeys.begin(), jnyIt);
            q->beginInsertRows({}, row, row);
            jnyIt = m_journeys.insert(jnyIt, *resIt);
            ++resIt;
            q->endInsertRows();
            continue;
        }

        if (JourneyUtil::firstTransportDepartureLessThan(*jnyIt, *resIt)) {
            ++jnyIt;
            continue;
        }

        if (Journey::isSame(*jnyIt, *resIt)) {
            *jnyIt = Journey::merge(*jnyIt, *resIt);
            ++resIt;
            const auto row = std::distance(m_journeys.begin(), jnyIt);
            const auto idx = q->index(row, 0);
            emit q->dataChanged(idx, idx);
        } else {
            ++jnyIt;
        }
    }
}


JourneyQueryModel::JourneyQueryModel(QObject *parent)
    : AbstractQueryModel(new JourneyQueryModelPrivate, parent)
{
    Q_D(JourneyQueryModel);
    connect(this, &AbstractQueryModel::managerChanged, this, [d]() { d->queryJourney(); });
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
    d->queryJourney();
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
            d->mergeResults(std::move(reply->takeResult()));
            d->m_nextRequest = reply->nextRequest();
        } else {
            d->m_nextRequest = {};
        }
        emit canQueryPrevNextChanged();
        reply->deleteLater();
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
            d->mergeResults(std::move(reply->takeResult()));
            d->m_prevRequest = reply->previousRequest();
        } else {
            d->m_prevRequest = {};
        }
        emit canQueryPrevNextChanged();
        reply->deleteLater();
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

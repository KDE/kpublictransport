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
#include "logging.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyReply>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Manager>

#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class JourneyQueryModelPrivate
{
public:
    Manager *mgr = nullptr;

    void mergeResults(JourneyQueryModel *q, std::vector<Journey> &&res);

    std::vector<Journey> m_journeys;

    JourneyRequest m_nextRequest;
    JourneyRequest m_prevRequest;

    QString m_errorMessage;
    bool m_loading = false;
};
}

// TODO share with JourneyReply
static QDateTime firstTransportDeparture(const Journey &jny)
{
    for (const auto &section : jny.sections()) {
        if (section.mode() == JourneySection::PublicTransport) {
            return section.scheduledDepartureTime();
        }
    }

    return jny.scheduledDepartureTime();
}

void JourneyQueryModelPrivate::mergeResults(JourneyQueryModel *q, std::vector<Journey> &&res)
{
    Q_ASSERT(!m_journeys.empty());
    auto result = std::move(res);
    if (result.empty()) {
        return;
    }

    // sort and merge results, aligned by first transport departure
    std::sort(result.begin(), result.end(), [](const auto &lhs, const auto &rhs) {
        return firstTransportDeparture(lhs) < firstTransportDeparture(rhs);
    });

    auto jnyIt = m_journeys.begin();
    auto resIt = result.begin();

    q->beginResetModel(); // TODO
    while (true) {
        if (resIt == result.end()) {
            break;
        }

        if (jnyIt == m_journeys.end()) {
            m_journeys.insert(jnyIt, resIt, result.end());
            break;
        }

        if (firstTransportDeparture(*resIt) < firstTransportDeparture(*jnyIt)) {
//             q->beginInsertRows();
            jnyIt = m_journeys.insert(jnyIt, *resIt);
            ++resIt;
//             q->endInsertRows();
            continue;
        }

        if (firstTransportDeparture(*jnyIt) < firstTransportDeparture(*resIt)) {
            ++jnyIt;
            continue;
        }

        if (Journey::isSame(*jnyIt, *resIt)) {
            *jnyIt = Journey::merge(*jnyIt, *resIt);
            ++resIt;
//             emit q->dataChanged();
        } else {
            ++jnyIt;
        }
    }

    q->endResetModel();
}


JourneyQueryModel::JourneyQueryModel(QObject *parent)
    : QAbstractListModel(parent)
    , d(new JourneyQueryModelPrivate)
{
}

JourneyQueryModel::~JourneyQueryModel() = default;

void JourneyQueryModel::setManager(Manager *mgr)
{
    d->mgr = mgr;
}

void JourneyQueryModel::setJourneyRequest(const JourneyRequest &req)
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
    if (!d->m_journeys.empty()) {
        beginResetModel();
        d->m_journeys.clear();
        endResetModel();
    }
    d->m_nextRequest = {};
    d->m_prevRequest = {};

    auto reply = d->mgr->queryJourney(req);
    QObject::connect(reply, &KPublicTransport::JourneyReply::finished, this, [reply, this]{
        d->m_loading = false;
        emit loadingChanged();
        if (reply->error() == KPublicTransport::JourneyReply::NoError) {
            beginResetModel();
            d->m_journeys = reply->takeResult();
            d->m_nextRequest = reply->nextRequest();
            d->m_prevRequest = reply->previousRequest();
            endResetModel();
        } else {
            d->m_errorMessage = reply->errorString();
            emit errorMessageChanged();
        }
        reply->deleteLater();
        emit canQueryPrevNextChanged();
    });
}

bool JourneyQueryModel::isLoading() const
{
    return d->m_loading;
}

QString JourneyQueryModel::errorMessage() const
{
    return d->m_errorMessage;
}

bool JourneyQueryModel::canQueryNext() const
{
    return !d->m_loading && !d->m_journeys.empty() && !d->m_nextRequest.isEmpty();
}

void JourneyQueryModel::queryNext()
{
    if (!canQueryNext()) {
        qCWarning(Log) << "Cannot query next journeys";
        return;
    }

    d->m_loading = true;
    emit loadingChanged();
    emit canQueryPrevNextChanged();

    auto reply = d->mgr->queryJourney(d->m_nextRequest);
    QObject::connect(reply, &KPublicTransport::JourneyReply::finished, this, [reply, this]{
        d->m_loading = false;
        emit loadingChanged();
        if (reply->error() == KPublicTransport::JourneyReply::NoError) {
            beginResetModel();
            d->mergeResults(this, std::move(reply->takeResult()));
            d->m_nextRequest = reply->nextRequest();
            endResetModel();
        } else {
            d->m_errorMessage = reply->errorString();
            d->m_nextRequest = {};
            emit errorMessageChanged();
        }
        reply->deleteLater();
        emit canQueryPrevNextChanged();
    });
}

bool JourneyQueryModel::canQueryPrevious() const
{
    return !d->m_loading && !d->m_journeys.empty() && !d->m_prevRequest.isEmpty();
}

void JourneyQueryModel::queryPrevious()
{
    if (!canQueryPrevious()) {
        qCWarning(Log) << "Cannot query previous journeys";
        return;
    }

    // TODO
}

int JourneyQueryModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return d->m_journeys.size();
}

QVariant JourneyQueryModel::data(const QModelIndex& index, int role) const
{
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
    return d->m_journeys;
}

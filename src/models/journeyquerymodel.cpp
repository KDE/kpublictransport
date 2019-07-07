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

    std::vector<Journey> journeys;

    JourneyRequest nextRequest;
    JourneyRequest prevRequest;

    QString errorMessage;
    bool loading = false;
};
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

    d->errorMessage.clear();
    emit errorMessageChanged();
    d->loading = true;
    emit loadingChanged();
    emit canQueryPrevNextChanged();
    if (!d->journeys.empty()) {
        beginResetModel();
        d->journeys.clear();
        endResetModel();
    }
    d->nextRequest = {};
    d->prevRequest = {};

    auto reply = d->mgr->queryJourney(req);
    QObject::connect(reply, &KPublicTransport::JourneyReply::finished, this, [reply, this]{
        d->loading = false;
        emit loadingChanged();
        if (reply->error() == KPublicTransport::JourneyReply::NoError) {
            beginResetModel();
            d->journeys = reply->takeResult();
            d->nextRequest = reply->nextRequest();
            d->prevRequest = reply->previousRequest();
            endResetModel();
        } else {
            d->errorMessage = reply->errorString();
            emit errorMessageChanged();
        }
        reply->deleteLater();
        emit canQueryPrevNextChanged();
    });
}

bool JourneyQueryModel::isLoading() const
{
    return d->loading;
}

QString JourneyQueryModel::errorMessage() const
{
    return d->errorMessage;
}

bool JourneyQueryModel::canQueryNext() const
{
    return !d->loading && !d->journeys.empty() && !d->nextRequest.isEmpty();
}

void JourneyQueryModel::queryNext()
{
    // TODO
}

bool JourneyQueryModel::canQueryPrevious() const
{
    return !d->loading && !d->journeys.empty() && !d->prevRequest.isEmpty();
}

void JourneyQueryModel::queryPrevious()
{
    // TODO
}

int JourneyQueryModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return d->journeys.size();
}

QVariant JourneyQueryModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case JourneyRole:
            return QVariant::fromValue(d->journeys[index.row()]);
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
    return d->journeys;
}

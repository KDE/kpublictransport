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

#include "abstractquerymodel.h"
#include "abstractquerymodel_p.h"
#include "datatypes/attributionutil_p.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Manager>
#include <KPublicTransport/Reply>

#include <QDebug>

using namespace KPublicTransport;

void AbstractQueryModelPrivate::setLoading(bool l)
{
    if (m_loading == l) {
        return;
    }
    m_loading = l;
    emit q_ptr->loadingChanged();
}

void AbstractQueryModelPrivate::setErrorMessage(const QString &msg)
{
    if (m_errorMessage == msg) {
        return;
    }
    m_errorMessage = msg;
    emit q_ptr->errorMessageChanged();
}

void AbstractQueryModelPrivate::monitorReply(Reply *reply)
{
    QObject::connect(reply, &Reply::finished, q_ptr, [this, reply]() {
        setLoading(false);
        if (reply->error() == KPublicTransport::Reply::NoError) {
            AttributionUtil::merge(m_attributions, std::move(reply->takeAttributions()));
            emit q_ptr->attributionsChanged();
        } else {
            setErrorMessage(reply->errorString());
        }
    });
}

void AbstractQueryModelPrivate::resetForNewRequest()
{
    setLoading(true);
    setErrorMessage({});
    m_attributions.clear();
    emit q_ptr->attributionsChanged();
}


AbstractQueryModel::AbstractQueryModel(AbstractQueryModelPrivate* dd, QObject* parent)
    : QAbstractListModel(parent)
    , d_ptr(dd)
{
    d_ptr->q_ptr = this;
}

AbstractQueryModel::~AbstractQueryModel() = default;

Manager* AbstractQueryModel::manager() const
{
    return d_ptr->m_manager;
}

void AbstractQueryModel::setManager(Manager *mgr)
{
    if (d_ptr->m_manager == mgr) {
        return;
    }

    d_ptr->m_manager = mgr;
    emit managerChanged();
}

bool AbstractQueryModel::isLoading() const
{
    return d_ptr->m_loading;
}

QString AbstractQueryModel::errorMessage() const
{
    return d_ptr->m_errorMessage;
}

const std::vector<Attribution>& AbstractQueryModel::attributions() const
{
    return d_ptr->m_attributions;
}

QVariantList AbstractQueryModel::attributionsVariant() const
{
    QVariantList l;
    l.reserve(d_ptr->m_attributions.size());
    std::transform(d_ptr->m_attributions.begin(), d_ptr->m_attributions.end(), std::back_inserter(l), [](const auto &attr) { return QVariant::fromValue(attr); });
    return l;
}

#include "moc_abstractquerymodel.moc"

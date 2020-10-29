/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "abstractquerymodel.h"
#include "abstractquerymodel_p.h"
#include "assetrepository_p.h"
#include "datatypes/attributionutil_p.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Manager>
#include <KPublicTransport/Reply>

#include <QDebug>
#include <QTimer>

using namespace KPublicTransport;

AbstractQueryModelPrivate::~AbstractQueryModelPrivate() = default;

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
    m_reply = reply;
    QObject::connect(reply, &Reply::finished, q_ptr, [this, reply]() {
        setLoading(false);
        reply->deleteLater();
        m_reply = nullptr;
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

void AbstractQueryModelPrivate::query()
{
    if (m_pendingQuery || !m_manager) {
        return;
    }

    m_pendingQuery = true;
    QTimer::singleShot(0, q_ptr, [this]() {
        m_pendingQuery = false;
        doQuery();
    });
}


AbstractQueryModel::AbstractQueryModel(AbstractQueryModelPrivate* dd, QObject* parent)
    : QAbstractListModel(parent)
    , d_ptr(dd)
{
    d_ptr->q_ptr = this;

    connect(AssetRepository::instance(), &AssetRepository::downloadFinished, this, [this]() {
        const auto rows = rowCount();
        if (rows > 0) {
            emit dataChanged(index(0, 0), index(rows - 1, 0));
        }
    });
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
    d_ptr->query();
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

void AbstractQueryModel::cancel()
{
    d_ptr->setLoading(false);
    delete d_ptr->m_reply;
    d_ptr->m_reply = nullptr;
}

#include "moc_abstractquerymodel.moc"

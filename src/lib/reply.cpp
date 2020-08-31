/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "reply.h"
#include "reply_p.h"
#include "assetrepository_p.h"
#include "datatypes/attributionutil_p.h"

#include <QDebug>
#include <QUrl>

using namespace KPublicTransport;

void ReplyPrivate::emitFinishedIfDone(Reply *q)
{
    if (pendingOps == 0 && (!needToWaitForAssets() || AssetRepository::instance()->isQueueEmpty())) {
        finalizeResult();
        // delayed, as this is trigged from the backend settings results on us, which can be a multi-step process
        QMetaObject::invokeMethod(q, &Reply::finished, Qt::QueuedConnection);
    }
}

void ReplyPrivate::emitUpdated(Reply *q)
{
    shouldClearError = true;
    // delayed, as this is trigged from immediate cache lookup in Manager, when signals are not yet connected
    QMetaObject::invokeMethod(q, &Reply::updated, Qt::QueuedConnection);
}

bool ReplyPrivate::needToWaitForAssets() const
{
    return false;
}

Reply::Reply(ReplyPrivate *dd, QObject *parent)
    : QObject(parent)
    , d_ptr(dd)
{
}

Reply::~Reply() = default;

Reply::Error Reply::error() const
{
    if (d_ptr->shouldClearError) {
        return Reply::NoError;
    }
    return d_ptr->error;
}

QString Reply::errorString() const
{
    if (d_ptr->shouldClearError) {
        return {};
    }
    return d_ptr->errorMsg;
}

void Reply::addError(Reply::Error error, const QString &errorMsg)
{
    d_ptr->error = error;
    d_ptr->errorMsg = errorMsg;
    d_ptr->pendingOps--;
    d_ptr->emitFinishedIfDone(this);
}

void Reply::setPendingOps(int ops)
{
    Q_ASSERT(d_ptr->pendingOps <= -1);
    Q_ASSERT(ops >= 0);
    d_ptr->pendingOps = ops;
    if (ops == 0) {
        QMetaObject::invokeMethod(this, &Reply::finished, Qt::QueuedConnection);
    }

    if (d_ptr->needToWaitForAssets()) {
        connect(AssetRepository::instance(), &AssetRepository::downloadFinished, this, [this]() { d_ptr->emitFinishedIfDone(this); });
    }
}

const std::vector<Attribution>& Reply::attributions() const
{
    return d_ptr->attributions;
}

std::vector<Attribution>&& Reply::takeAttributions()
{
    return std::move(d_ptr->attributions);
}

void Reply::addAttributions(std::vector<Attribution>&& attributions)
{
    AttributionUtil::merge(d_ptr->attributions, std::move(attributions));
}

void Reply::addAttribution(const Attribution &attr)
{
    AttributionUtil::merge(d_ptr->attributions, attr);
}

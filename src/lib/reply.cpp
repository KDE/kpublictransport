/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#include "reply.h"
#include "reply_p.h"
#include "datatypes/attributionutil_p.h"

#include <QUrl>

using namespace KPublicTransport;

void ReplyPrivate::emitFinishedIfDone(Reply *q)
{
    if (pendingOps == 0) {
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

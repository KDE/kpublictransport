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

#include <QUrl>

using namespace KPublicTransport;

void ReplyPrivate::emitFinishedIfDone(Reply *q)
{
    if (pendingOps <= 0) {
        finalizeResult();
        // delayed, as this is trigged from the backend settings results on us, which can be a multi-step process
        QMetaObject::invokeMethod(q, &Reply::finished, Qt::QueuedConnection);
    }
}

Reply::Reply(ReplyPrivate *dd, QObject *parent)
    : QObject(parent)
    , d_ptr(dd)
{
}

Reply::~Reply() = default;

Reply::Error Reply::error() const
{
    return d_ptr->error;
}

QString Reply::errorString() const
{
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

bool multiLessThan() { return false; }
template<typename T, typename... Args>
bool multiLessThan(const T &first, const T &second, Args... next)
{
    if (first != second) {
        return first < second;
    } else {
        return multiLessThan(next...);
    }
}

void Reply::addAttributions(std::vector<Attribution>&& attributions)
{
    if (d_ptr->attributions.empty()) {
        d_ptr->attributions = std::move(attributions);
    } else {
        d_ptr->attributions.insert(d_ptr->attributions.end(), attributions.begin(), attributions.end());
    }

    // remove duplicates
    std::sort(d_ptr->attributions.begin(), d_ptr->attributions.end(), [](const auto &lhs, const auto &rhs) {
        return multiLessThan(lhs.name(), rhs.name(), lhs.license(), rhs.license(), lhs.url(), rhs.url(), lhs.licenseUrl(), rhs.licenseUrl());
    });
    d_ptr->attributions.erase(std::unique(d_ptr->attributions.begin(), d_ptr->attributions.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.name() == rhs.name() && lhs.url() == rhs.url() && lhs.license() == rhs.license() && lhs.licenseUrl() == rhs.licenseUrl();
    }), d_ptr->attributions.end());
}

void Reply::addAttribution(const Attribution &attr)
{
    if (attr.isEmpty()) {
        return;
    }
    // TODO technically we need to de-duplicate here, but practically this is only used for static attributions which are unique
    d_ptr->attributions.push_back(attr);
}

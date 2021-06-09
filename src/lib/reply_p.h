/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_REPLY_P_H
#define KPUBLICTRANSPORT_REPLY_P_H

#include "reply.h"

#include <KPublicTransport/Attribution>

#include <QString>

#include <vector>

namespace KPublicTransport {

class ReplyPrivate
{
public:
    ReplyPrivate() = default;
    ReplyPrivate(const ReplyPrivate&) = delete;
    virtual ~ReplyPrivate() = default;
    ReplyPrivate& operator=(const ReplyPrivate&) = delete;

    virtual void finalizeResult() = 0;
    virtual bool needToWaitForAssets() const;

    void emitUpdated(Reply *q);
    void emitFinishedIfDone(Reply *q);

    std::vector<Attribution> attributions;
    QString errorMsg;
    Reply::Error error = Reply::NoError;
    int pendingOps = -1;
    bool shouldClearError = false; // if we got valid results from one backend, we ignore errors from others
};

}

#endif // KPUBLICTRANSPORT_REPLY_P_H


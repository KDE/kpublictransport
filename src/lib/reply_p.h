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

#ifndef KPUBLICTRANSPORT_REPLY_P_H
#define KPUBLICTRANSPORT_REPLY_P_H

#include "reply.h"
#include "pointer_helper_p.h"

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


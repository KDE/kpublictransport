/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_REQUESTCONTEXT_P_H
#define KPUBLICTRANSPORT_REQUESTCONTEXT_P_H

#include <QDateTime>
#include <QVariant>

namespace KPublicTransport {

class AbstractBackend;

/** Backend-specific request information. */
class RequestContext
{
public:
    explicit RequestContext();
    ~RequestContext();
    bool operator==(const RequestContext &other) const;
    bool operator<(const AbstractBackend *other) const;

    /** Removes all contexts from @p contexts that already exist in @p baseContexts.
     *  Both vectors are assumed to be sorted by backend pointer.
     */
    static void purgeLoops(std::vector<RequestContext> &contexts, const std::vector<RequestContext> &baseContexts);

    const AbstractBackend *backend = nullptr;

    enum RequestType {
        Normal,
        Next,
        Previous
    };
    RequestType type = Normal;
    // for departure/next this is the time of the last previously found departure time
    // for departure/previous this is the first previously found departure time
    // for arrival/next this is the last previously found arrival time
    // for arrival/previous this is the first previously found arrival time
    QDateTime dateTime;
    QVariant backendData;
};

}

#endif // KPUBLICTRANSPORT_REQUESTCONTEXT_P_H

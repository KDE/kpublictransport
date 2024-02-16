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

/** Backend-specific request information.
 *  This holds information a backend can use for follow-up requests
 *  to a previous query, ie. paging to following/preceeding results.
 */
class RequestContext
{
public:
    explicit RequestContext();
    ~RequestContext();
    bool operator==(const RequestContext &other) const;
    bool operator<(const AbstractBackend *other) const;

    /** Removes all contexts from @p contexts that already exist in @p baseContexts.
     *  Both vectors are assumed to be sorted by backend pointer.
     *  @internal
     */
    static void purgeLoops(std::vector<RequestContext> &contexts, const std::vector<RequestContext> &baseContexts);

    const AbstractBackend *backend = nullptr;

    enum RequestType {
        Normal, ///< this is the first request of its kind, ie. there is no context
        Next, ///< this request is for results following those of the previous request
        Previous, ///< this request is for results preceeding those of the previous request
    };
    RequestType type = Normal;
    // for departure/next this is the time of the last previously found departure time
    // for departure/previous this is the first previously found departure time
    // for arrival/next this is the last previously found arrival time
    // for arrival/previous this is the first previously found arrival time
    QDateTime dateTime;
    /** Backend-provided custom context data. */
    QVariant backendData;
};

}

#endif // KPUBLICTRANSPORT_REQUESTCONTEXT_P_H

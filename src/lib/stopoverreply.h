/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_STOPOVERREPLY_H
#define KPUBLICTRANSPORT_STOPOVERREPLY_H

#include "reply.h"

#include <vector>

namespace KPublicTransport {

class AbstractBackend;
class Stopover;
class StopoverReplyPrivate;
class StopoverRequest;

/** Departure or arrival query reply. */
class KPUBLICTRANSPORT_EXPORT StopoverReply : public Reply
{
    Q_OBJECT
public:
    ~StopoverReply() override;

    /** The request this is the reply for. */
    StopoverRequest request() const;

    /** Returns the found arrival or departure information. */
    const std::vector<Stopover>& result() const;
    /** Returns the found arrival or departure information for moving elsewhere. */
    std::vector<Stopover>&& takeResult();

    /** Returns a request object for querying departures following the ones returned by this reply.
     *  The returned request is empty if querying later departures is not possible/supported.
     */
    StopoverRequest nextRequest() const;
    /** Returns a request object for querying departures preceding the ones returned by this reply.
     *  The returned request is empty if querying earlier departures is not possible/supported.
     */
    StopoverRequest previousRequest() const;

private:
    friend class Manager;
    friend class ManagerPrivate;
    explicit StopoverReply(const StopoverRequest &req, QObject *parent = nullptr);

    friend class AbstractBackend;
    Q_DECL_HIDDEN void addResult(const AbstractBackend *backend, std::vector<Stopover> &&res);
    using Reply::addError;
    Q_DECL_HIDDEN void addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg);

    Q_DECL_HIDDEN void setNextContext(const AbstractBackend *backend, const QVariant &data);
    Q_DECL_HIDDEN void setPreviousContext(const AbstractBackend *backend, const QVariant &data);

    Q_DECLARE_PRIVATE(StopoverReply)
};

}

#endif // KPUBLICTRANSPORT_STOPOVERREPLY_H

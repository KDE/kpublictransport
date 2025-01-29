/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_TRIPREPLY_H
#define KPUBLICTRANSPORT_TRIPREPLY_H

#include "reply.h"

namespace KPublicTransport {

class AbstractBackend;
class JourneySection;
class TripReplyPrivate;
class TripReplyTest;
class TripRequest;

/** Reply to a trip query.
 *  @since 25.04
 */
class KPUBLICTRANSPORT_EXPORT TripReply : public Reply
{
    Q_OBJECT
    Q_PROPERTY(KPublicTransport::JourneySection trip READ trip NOTIFY finished)

public:
    ~TripReply() override;

    /** The request this is the reply for. */
    [[nodiscard]] TripRequest request() const;

    /** The full trip, ie the entire vehicle run.
     *  This can be incomplete if no backend supports trip queries and this
     *  is emulated internally by journey queries.
     */
    [[nodiscard]] JourneySection trip() const;

    /** The sub-trip matching the JourneySection used in the request.
     *  This can be identical to trip() if the entire vehicle run happened
     *  to be requested, or when no backend supports trip queries.
     */
    [[nodiscard]] JourneySection journeySection() const;

private:
    friend class Manager;
    friend class ManagerPrivate;
    explicit TripReply(const TripRequest &req, QObject *parent = nullptr);

    friend class AbstractBackend;
    void addResult(const AbstractBackend *backend, JourneySection &&journeySection); // exported for unit tests
    using Reply::addError;
    Q_DECL_HIDDEN void addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg);

    friend class TripReplyTest;
    Q_DECLARE_PRIVATE(TripReply)
};

}

#endif

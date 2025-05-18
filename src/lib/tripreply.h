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
class Stopover;
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
    Q_PROPERTY(KPublicTransport::JourneySection journeySection READ journeySection NOTIFY finished)
    Q_PROPERTY(qsizetype journeySectionBegin READ journeySectionBegin NOTIFY finished)
    Q_PROPERTY(qsizetype journeySectionEnd READ journeySectionEnd NOTIFY finished)
    Q_PROPERTY(KPublicTransport::Stopover stopover READ stopover NOTIFY finished)
    Q_PROPERTY(qsizetype stopoverIndex READ stopoverIndex NOTIFY finished)

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

    /** Index at which journeySection() begins in trip(). */
    [[nodiscard]] qsizetype journeySectionBegin() const;
    /** Index at which journeySection() ends in trip(). */
    [[nodiscard]] qsizetype journeySectionEnd() const;

    /** An updated version of the Stopover instance used in the request.
     *  This is only meaningful for TripRequests created from a Stopover.
     *  @since 25.08
     */
    [[nodiscard]] Stopover stopover() const;

    /** Index at which stopover() is placed inside trip().
     *  @since 25.08
     */
    [[nodiscard]] qsizetype stopoverIndex() const;

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

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
class TripRequest;

/** Reply to a trip query. */
class KPUBLICTRANSPORT_EXPORT TripReply : public Reply
{
    Q_OBJECT
    Q_PROPERTY(KPublicTransport::JourneySection trip READ trip NOTIFY finished)

public:
    ~TripReply() override;

    /** The request this is the reply for. */
    [[nodiscard]] TripRequest request() const;

    /** The requested Stopover information, including the vehicle and platform layout. */
    [[nodiscard]] JourneySection trip() const;

private:
    friend class Manager;
    friend class ManagerPrivate;
    explicit TripReply(const TripRequest &req, QObject *parent = nullptr);

    friend class AbstractBackend;
    Q_DECL_HIDDEN void addResult(const AbstractBackend *backend, JourneySection &&journeySection);
    using Reply::addError;
    Q_DECL_HIDDEN void addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg);

    Q_DECLARE_PRIVATE(TripReply)
};

}

#endif

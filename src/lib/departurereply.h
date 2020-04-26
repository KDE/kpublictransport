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

#ifndef KPUBLICTRANSPORT_DEPARTUREREPLY_H
#define KPUBLICTRANSPORT_DEPARTUREREPLY_H

#include "reply.h"

#include <vector>

namespace KPublicTransport {

class AbstractBackend;
class DepartureReplyPrivate;
class Stopover;
class StopoverRequest;

/** Departure or arrival query reply. */
class KPUBLICTRANSPORT_EXPORT DepartureReply : public Reply
{
    Q_OBJECT
public:
    ~DepartureReply();

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
    explicit DepartureReply(const StopoverRequest &req, QObject *parent = nullptr);

    friend class AbstractBackend;
    Q_DECL_HIDDEN void addResult(const AbstractBackend *backend, std::vector<Stopover> &&res);
    using Reply::addError;
    Q_DECL_HIDDEN void addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg);

    Q_DECL_HIDDEN void setNextContext(const AbstractBackend *backend, const QVariant &data);
    Q_DECL_HIDDEN void setPreviousContext(const AbstractBackend *backend, const QVariant &data);

    Q_DECLARE_PRIVATE(DepartureReply)
};

}

#endif // KPUBLICTRANSPORT_DEPARTUREREPLY_H

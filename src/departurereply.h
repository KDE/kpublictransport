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
class Departure;
class DepartureRequest;
class DepartureReplyPrivate;

/** Departure or arrival query reply. */
class KPUBLICTRANSPORT_EXPORT DepartureReply : public Reply
{
    Q_OBJECT
public:
    ~DepartureReply();

    /** The request this is the reply for. */
    DepartureRequest request() const;

    /** Returns the found arrival or departure information. */
    const std::vector<Departure>& result() const;
    /** Returns the found arrival or departure information for moving elsewhere. */
    std::vector<Departure>&& takeResult();

    /** Returns a request object for querying departures following the ones returned by this reply.
     *  The returned request is empty if querying later departures is not possible/supported.
     */
    DepartureRequest nextRequest() const;
    /** Returns a request object for querying departures preceeding the ones returned by this reply.
     *  The returned request is empty if querying earlier departures is not possible/supported.
     */
    DepartureRequest previousRequest() const;

private:
    friend class ManagerPrivate;
    explicit DepartureReply(const DepartureRequest &req, QObject *parent = nullptr);

    friend class AbstractBackend;
    void addResult(std::vector<Departure> &&res);

    Q_DECL_HIDDEN void setNextContext(const AbstractBackend *backend, const QVariant &data);
    Q_DECL_HIDDEN void setPreviousContext(const AbstractBackend *backend, const QVariant &data);

    Q_DECLARE_PRIVATE(DepartureReply)
};

}

#endif // KPUBLICTRANSPORT_DEPARTUREREPLY_H

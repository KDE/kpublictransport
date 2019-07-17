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

#ifndef KPUBLICTRANSPORT_REPLY_H
#define KPUBLICTRANSPORT_REPLY_H

#include "kpublictransport_export.h"
#include "internal_impl.h"

#include <QObject>

namespace KPublicTransport {

class AbstractBackend;
class Attribution;
class Manager;
class ReplyPrivate;

/** Query response base class. */
class KPUBLICTRANSPORT_EXPORT Reply : public QObject
{
    Q_OBJECT
public:
    ~Reply();

    /** Error types. */
    enum Error {
        NoError, ///< Nothing went wrong.
        NetworkError, ///< Error during network operations.
        NotFoundError, ///< The requested journey/departure/place could not be found.
        UnknownError ///< Anything else.
    };

    /** Error code. */
    Error error() const;
    /** Textual error message. */
    QString errorString() const;

    /** Returns the attributions for the provided data. */
    const std::vector<Attribution>& attributions() const;
    /** Returns the attributions for the provided data for moving them elsewhere. */
    std::vector<Attribution>&& takeAttributions();

Q_SIGNALS:
    /** Emitted whenever the journey search has been completed. */
    void finished();

protected:
    Q_DECL_HIDDEN explicit Reply(ReplyPrivate *dd, QObject *parent);
    std::unique_ptr<ReplyPrivate> d_ptr;

    friend class AbstractBackend;
    Q_DECL_HIDDEN void addError(Error error, const QString &errorMsg);
    Q_DECL_HIDDEN void addAttributions(std::vector<Attribution> &&attributions);

    friend class Manager;
    friend class ManagerPrivate;
    Q_DECL_HIDDEN void setPendingOps(int ops);
    Q_DECL_HIDDEN void addAttribution(const Attribution &attr);
};

}

#endif // KPUBLICTRANSPORT_JOURNEYREPLY_H

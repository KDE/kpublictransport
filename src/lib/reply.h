/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_REPLY_H
#define KPUBLICTRANSPORT_REPLY_H

#include "kpublictransport_export.h"

#include <QObject>

#include <memory>

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
        InvalidRequest, ///< Incomplete or otherwise invalid request.
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
    /** Emitted whenever the corresponding search has been completed. */
    void finished();
    /** Emitted whenever new results are available, even before the search has been completed.
     *  @note At this point no guarantees about the result apply, sorting/merging/etc might not have been applied yet
     *  and not all properties of the reply might be valid. Avoid the usage of this in general, unless you write
     *  dynamically updating models that need very quick results at the expensive of incompleteness.
     */
    void updated();

protected:
    ///@cond internal
    Q_DECL_HIDDEN explicit Reply(ReplyPrivate *dd, QObject *parent);
    std::unique_ptr<ReplyPrivate> d_ptr;

    friend class AbstractBackend;
    /** Used for a backend to report it finished it's job with an error.
     *  Prefer to use the variants of this provided by the type-specific sub-classes
     *  which also add the corresponding negative cache entries if appropriate.
     */
    Q_DECL_HIDDEN void addError(Error error, const QString &errorMsg);
    Q_DECL_HIDDEN void addAttributions(std::vector<Attribution> &&attributions);
    Q_DECL_HIDDEN void addAttributions(const std::vector<Attribution> &attributions);

    friend class Manager;
    friend class ManagerPrivate;
    Q_DECL_HIDDEN void setPendingOps(int ops);
    Q_DECL_HIDDEN void addAttribution(const Attribution &attr);
    ///@endcond
};

}

#endif // KPUBLICTRANSPORT_JOURNEYREPLY_H

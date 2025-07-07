/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_STOPOVERQUERYMODEL_H
#define KPUBLICTRANSPORT_STOPOVERQUERYMODEL_H

#include "kpublictransport_export.h"
#include "abstractquerymodel.h"

#include <KPublicTransport/StopoverRequest>

namespace KPublicTransport {

class Stopover;
class StopoverQueryModelPrivate;

/**
 * Model representing arrival or departure query results.
 * This takes care of dynamically updating as results arrive from different
 * backends, including merging them, as well as providing a way to search
 * for earlier/later arrivals/departures for the initial request.
 */
class KPUBLICTRANSPORT_EXPORT StopoverQueryModel : public AbstractQueryModel
{
    Q_OBJECT

    /** Specify the actual departure query. */
    Q_PROPERTY(KPublicTransport::StopoverRequest request READ request WRITE setRequest NOTIFY requestChanged)

    /** Whether querying for later departures is possible. */
    Q_PROPERTY(bool canQueryNext READ canQueryNext NOTIFY canQueryPrevNextChanged)
    /** Whether querying for earlier journey is possible. */
    Q_PROPERTY(bool canQueryPrevious READ canQueryPrevious NOTIFY canQueryPrevNextChanged)

    /** Enable automatic update of the model content every minute. */
    Q_PROPERTY(bool autoUpdate READ autoUpdate WRITE setAutoUpdate NOTIFY autoUpdateChanged)

public:
    explicit StopoverQueryModel(QObject *parent = nullptr);
    ~StopoverQueryModel() override;

    [[nodiscard]] StopoverRequest request() const;
    void setRequest(const StopoverRequest &req);

    [[nodiscard]] bool canQueryNext() const;
    /** Search for later journeys.
     *  Has no effect if canQueryNext() returns @c false.
     */
    Q_INVOKABLE void queryNext();

    [[nodiscard]] bool canQueryPrevious() const;
    /** Search for earlier journeys.
     *  Has no effect if canQueryPrevious() returns @c false.
     */
    Q_INVOKABLE void queryPrevious();

    enum Roles {
        DepartureRole [[deprecated("Use StopoverRole instead")]] = Qt::UserRole,
        StopoverRole,
    };
    Q_ENUM(Roles)

    [[nodiscard]] int rowCount(const QModelIndex &parent = {}) const override;
    [[nodiscard]] QVariant data(const QModelIndex &index, int role) const override;
    [[nodiscard]] QHash<int, QByteArray> roleNames() const override;

    /** The current model content. */
    [[nodiscard]] std::vector<Stopover> departures() const;

    [[nodiscard]] bool autoUpdate() const;
    void setAutoUpdate(bool enabled);

Q_SIGNALS:
    void requestChanged();
    void canQueryPrevNextChanged();
    void autoUpdateChanged();

private:
    friend class StopoverQueryModelPrivate;
    Q_DECLARE_PRIVATE(StopoverQueryModel)
};

}

#endif // KPUBLICTRANSPORT_STOPOVERQUERYMODEL_H

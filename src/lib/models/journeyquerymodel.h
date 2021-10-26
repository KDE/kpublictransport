/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JOURNEYQUERYMODEL_H
#define KPUBLICTRANSPORT_JOURNEYQUERYMODEL_H

#include "kpublictransport_export.h"
#include "abstractquerymodel.h"

#include <KPublicTransport/JourneyRequest>

namespace KPublicTransport {

class Journey;
class JourneyQueryModelPrivate;

/**
 * Model representing journey query results.
 * This takes care of dynamically updating as results arrive from different
 * backends, including merging them, as well as providing a way to search
 * for earlier/later journeys for the initial request.
 */
class KPUBLICTRANSPORT_EXPORT JourneyQueryModel : public AbstractQueryModel
{
    Q_OBJECT

    /** Specify the requested journey. */
    Q_PROPERTY(KPublicTransport::JourneyRequest request READ request WRITE setRequest NOTIFY requestChanged)

    /** Whether querying for later journeys is possible. */
    Q_PROPERTY(bool canQueryNext READ canQueryNext NOTIFY canQueryPrevNextChanged)
    /** Whether querying for earlier journey is possible. */
    Q_PROPERTY(bool canQueryPrevious READ canQueryPrevious NOTIFY canQueryPrevNextChanged)

public:
    explicit JourneyQueryModel(QObject *parent = nullptr);
    ~JourneyQueryModel() override;

    JourneyRequest request() const;
    /** Specify the actual journey query. */
    void setRequest(const JourneyRequest &req);

    bool canQueryNext() const;
    /** Search for later journeys.
     *  Has no effect if canQueryNext() returns @c false.
     */
    Q_INVOKABLE void queryNext();

    bool canQueryPrevious() const;
    /** Search for earlier journeys.
     *  Has no effect if canQueryPrevious() returns @c false.
     */
    Q_INVOKABLE void queryPrevious();

    enum Roles {
        JourneyRole = Qt::UserRole,
        ScheduledDepartureTime,
        ScheduledArrivalTime
    };
    Q_ENUM(Roles)

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    /** The current model content. */
    const std::vector<Journey>& journeys() const;

Q_SIGNALS:
    void requestChanged();
    void canQueryPrevNextChanged();

private:
    friend class JourneyQueryModelPrivate;
    Q_DECLARE_PRIVATE(JourneyQueryModel)
};

}

#endif // KPUBLICTRANSPORT_JOURNEYQUERYMODEL_H

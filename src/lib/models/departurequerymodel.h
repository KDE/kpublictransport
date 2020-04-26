/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_DEPARTUREQUERYMODEL_H
#define KPUBLICTRANSPORT_DEPARTUREQUERYMODEL_H

#include "kpublictransport_export.h"
#include "abstractquerymodel.h"

#include <KPublicTransport/StopoverRequest>

namespace KPublicTransport {

class DepartureQueryModelPrivate;
class Stopover;

/**
 * Model representing arrival or departure query results.
 * This takes care of dynamically updating as results arrive from different
 * backends, including merging them, as well as providing a way to search
 * for earlier/later arrivals/departures for the initial request.
 */
class KPUBLICTRANSPORT_EXPORT DepartureQueryModel : public AbstractQueryModel
{
    Q_OBJECT

    /** Specify the actual departure query. */
    Q_PROPERTY(KPublicTransport::StopoverRequest request READ request WRITE setRequest NOTIFY requestChanged)

    /** Whether querying for later departures is possible. */
    Q_PROPERTY(bool canQueryNext READ canQueryNext NOTIFY canQueryPrevNextChanged)
    /** Whether querying for earlier journey is possible. */
    Q_PROPERTY(bool canQueryPrevious READ canQueryPrevious NOTIFY canQueryPrevNextChanged)

public:
    explicit DepartureQueryModel(QObject *parent = nullptr);
    ~DepartureQueryModel();

    StopoverRequest request() const;
    void setRequest(const StopoverRequest &req);

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
        DepartureRole = Qt::UserRole
    };

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    /** The current model content. */
    const std::vector<Stopover>& departures() const;

Q_SIGNALS:
    void requestChanged();
    void canQueryPrevNextChanged();

private:
    friend class DepartureQueryModelPrivate;
    Q_DECLARE_PRIVATE(DepartureQueryModel)
};

}

#endif // KPUBLICTRANSPORT_DEPARTUREQUERYMODEL_H

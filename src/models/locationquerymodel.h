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

#ifndef KPUBLICTRANSPORT_LOCATIONQUERYMODEL_H
#define KPUBLICTRANSPORT_LOCATIONQUERYMODEL_H

#include "kpublictransport_export.h"
#include "abstractquerymodel.h"

#include <KPublicTransport/LocationRequest>

namespace KPublicTransport {

class Location;
class LocationQueryModelPrivate;

/**
 * Model representing location query results.
 * Intented as a basis for as-you-type completers for location searches.
 */
class KPUBLICTRANSPORT_EXPORT LocationQueryModel : public AbstractQueryModel
{
    Q_OBJECT
    /** Specify the actual location query. */
    Q_PROPERTY(KPublicTransport::LocationRequest request READ request WRITE setRequest NOTIFY requestChanged)

public:
    explicit LocationQueryModel(QObject *parent = nullptr);
    ~LocationQueryModel();

    LocationRequest request() const;
    void setRequest(const LocationRequest &req);

    enum Roles {
        LocationRole = Qt::UserRole
    };

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

Q_SIGNALS:
    void requestChanged();

private:
    friend class LocationQueryModelPrivate;
    Q_DECLARE_PRIVATE(LocationQueryModel)
};

}

#endif // KPUBLICTRANSPORT_LOCATIONQUERYMODEL_H

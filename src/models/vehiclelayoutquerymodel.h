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

#ifndef KPUBLICTRANSPORT_VEHICLELAYOUTQUERYMODEL_H
#define KPUBLICTRANSPORT_VEHICLELAYOUTQUERYMODEL_H

#include "kpublictransport_export.h"
#include "abstractquerymodel.h"

#include <KPublicTransport/Platform>
#include <KPublicTransport/VehicleLayoutRequest>

namespace KPublicTransport {

class VehicleLayoutQueryModelPrivate;

/** Model for retrieving vehicle and platform layout query results. */
class KPUBLICTRANSPORT_EXPORT VehicleLayoutQueryModel : public AbstractQueryModel
{
    Q_OBJECT
    Q_PROPERTY(KPublicTransport::VehicleLayoutRequest request READ request WRITE setRequest NOTIFY requestChanged)

    /** The platform this vehicle is departing from. */
    Q_PROPERTY(KPublicTransport::Platform platform READ platform NOTIFY contentChanged)

public:
    explicit VehicleLayoutQueryModel(QObject *parent = nullptr);
    ~VehicleLayoutQueryModel();

    VehicleLayoutRequest request() const;
    void setRequest(const VehicleLayoutRequest &req);

    Platform platform() const;

    enum Roles {
        VehicleSectionRole = Qt::UserRole
    };

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
Q_SIGNALS:
    void requestChanged();
    void contentChanged();

private:
    friend class VehicleLayoutQueryModelPrivate;
    Q_DECLARE_PRIVATE(VehicleLayoutQueryModel)
};

}

#endif // KPUBLICTRANSPORT_VEHICLELAYOUTQUERYMODEL_H

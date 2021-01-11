/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_VEHICLELAYOUTQUERYMODEL_H
#define KPUBLICTRANSPORT_VEHICLELAYOUTQUERYMODEL_H

#include "kpublictransport_export.h"
#include "abstractquerymodel.h"

#include <KPublicTransport/Platform>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/Vehicle>
#include <KPublicTransport/VehicleLayoutRequest>

namespace KPublicTransport {

class VehicleLayoutQueryModelPrivate;

/** Model for retrieving vehicle and platform layout query results. */
class KPUBLICTRANSPORT_EXPORT VehicleLayoutQueryModel : public AbstractQueryModel
{
    Q_OBJECT
    Q_PROPERTY(KPublicTransport::VehicleLayoutRequest request READ request WRITE setRequest NOTIFY requestChanged)

    /** The vehicle for which this model shows its sections. */
    Q_PROPERTY(KPublicTransport::Vehicle vehicle READ vehicle NOTIFY contentChanged)
    /** The platform this vehicle is departing from. */
    Q_PROPERTY(KPublicTransport::Platform platform READ platform NOTIFY contentChanged)
    /** The departure this vehicle layout belongs to. */
    Q_PROPERTY(KPublicTransport::Stopover departure READ departure NOTIFY contentChanged)

public:
    explicit VehicleLayoutQueryModel(QObject *parent = nullptr);
    ~VehicleLayoutQueryModel();

    VehicleLayoutRequest request() const;
    void setRequest(const VehicleLayoutRequest &req);

    Vehicle vehicle() const;
    Platform platform() const;
    Stopover departure() const;

    enum Roles {
        VehicleSectionRole = Qt::UserRole
    };
    Q_ENUM(Roles)

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

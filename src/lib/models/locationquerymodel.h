/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
    Q_ENUM(Roles)

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    /** The current model content. */
    const std::vector<Location>& locations() const;

Q_SIGNALS:
    void requestChanged();

private:
    friend class LocationQueryModelPrivate;
    Q_DECLARE_PRIVATE(LocationQueryModel)
};

}

#endif // KPUBLICTRANSPORT_LOCATIONQUERYMODEL_H

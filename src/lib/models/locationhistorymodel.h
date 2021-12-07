/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LOCATIONHISTORYMODEL_H
#define KPUBLICTRANSPORT_LOCATIONHISTORYMODEL_H

#include "kpublictransport_export.h"

#include <KPublicTransport/Location>

#include <QAbstractTableModel>
#include <QDateTime>

namespace KPublicTransport {

/** Model of frequently/recently used locations.
 *  Content is persisted globally, ie. all applications sharing this see
 *  the same data.
 */
class KPUBLICTRANSPORT_EXPORT LocationHistoryModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit LocationHistoryModel(QObject *parent = nullptr);
    ~LocationHistoryModel();

    enum Role {
        LocationRole = Qt::UserRole,
        LocationNameRole,
        LastUsedRole,
        UseCountRole,
    };
    Q_ENUM(Role)

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;
    Q_INVOKABLE bool removeRow(int row, const QModelIndex &parent = QModelIndex()); // not exported to QML by default...
    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex &parent = {}) override;

public Q_SLOTS:
    /** Add a location to the history.
     *  If already present, just the usage data will be updated.
     */
    void addLocation(const KPublicTransport::Location &loc);

    /** Delete the entire history content. */
    void clear();

private:
    struct Data {
        QString id;
        Location loc;
        QDateTime lastUse;
        int useCount = 0;
    };

    void rescan();
    void store(const Data &data) const;

    std::vector<Data> m_locations;
};

}

#endif // KPUBLICTRANSPORT_LOCATIONHISTORYMODEL_H

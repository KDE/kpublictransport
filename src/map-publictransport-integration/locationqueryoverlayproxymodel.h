/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_LOCATIONQUERYOVERLAYPROXYMODEL_H
#define KOSMINDOORMAP_LOCATIONQUERYOVERLAYPROXYMODEL_H

#include <QAbstractItemModel>

#include <KOSMIndoorMap/MapData>

namespace OSM {
class Element;
class Node;
}

namespace KOSMIndoorMap {

/** Adapts a KPublicTransport::LocationQueryModel to be compatible with a KOSMIndoorMap::OverlaySource.
 */
class LocationQueryOverlayProxyModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(KOSMIndoorMap::MapData* mapData READ mapData WRITE setMapData NOTIFY mapDataChanged)
    Q_PROPERTY(QAbstractItemModel* sourceModel READ sourceModel WRITE setSourceModel NOTIFY sourceModelChanged)

public:
    explicit LocationQueryOverlayProxyModel(QObject *parent = nullptr);
    ~LocationQueryOverlayProxyModel();

    MapData* mapData() const;
    void setMapData(MapData *data);

    QAbstractItemModel *sourceModel() const;
    void setSourceModel(QAbstractItemModel *sourceModel);

    enum Role {
        ElementRole = Qt::UserRole,
        LevelRole,
    };
    Q_ENUM(Role)

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex & index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

Q_SIGNALS:
    void mapDataChanged();
    void sourceModelChanged();

private:
    void initialize();

    std::vector<OSM::Node> m_nodes;
    MapData *m_data = nullptr;
    QAbstractItemModel *m_sourceModel = nullptr;
};

}

#endif // KOSMINDOORMAP_LOCATIONQUERYOVERLAYPROXYMODEL_H

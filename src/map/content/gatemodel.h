/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_GATEMODEL_H
#define KOSMINDOORMAP_GATEMODEL_H

#include <KOSMIndoorMap/MapData>

#include <osm/element.h>

#include <QAbstractListModel>

namespace KOSMIndoorMap {

/** An airport gate. */
struct Gate {
    OSM::Element element;
    QString name;
    int level = 0;
};


/** Lists all airport gates found in current map. */
class GateModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(const KOSMIndoorMap::MapData* mapData READ mapData WRITE setMapData NOTIFY mapDataChanged)

public:
    explicit GateModel(QObject *parent = nullptr);
    ~GateModel();

    const MapData* mapData() const;
    void setMapData(const MapData *data);

    enum Role {
        CoordinateRole = Qt::UserRole,
        LevelRole,
    };

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex & index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

Q_SIGNALS:
    void mapDataChanged();

private:
    void populateModel();

    std::vector<Gate> m_gates;
    const MapData *m_data = nullptr;
    bool m_searchDone = false;
};

}

#endif // KOSMINDOORMAP_GATEMODEL_H

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


/** Lists all airport gates found in the current map.
 *  This also contains the concept of (optional) arrival/departure gates,
 *  for matching gate names from other sources and highlighting those in the output.
 */
class GateModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(KOSMIndoorMap::MapData* mapData READ mapData WRITE setMapData NOTIFY mapDataChanged)
    Q_PROPERTY(bool isEmpty READ isEmpty NOTIFY mapDataChanged)

    /** Row indexes of the matched arrival/departure gates, if found and/or set, otherwise @c -1. */
    Q_PROPERTY(int arrivalGateRow READ arrivalGateRow NOTIFY gateIndexChanged)
    Q_PROPERTY(int departureGateRow READ departureGateRow NOTIFY gateIndexChanged)
public:
    explicit GateModel(QObject *parent = nullptr);
    ~GateModel();

    MapData* mapData() const;
    void setMapData(MapData *data);

    bool isEmpty() const;

    enum Role {
        CoordinateRole = Qt::UserRole,
        ElementRole,
        LevelRole,
        ArrivalGateRole,
        DepartureGateRole,
    };
    Q_ENUM(Role)

    int rowCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex & index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    /** Match arrival/departure gates against what we found in the map data. */
    Q_INVOKABLE void setArrivalGate(const QString &name);
    Q_INVOKABLE void setDepartureGate(const QString &name);

    int arrivalGateRow() const;
    int departureGateRow() const;

Q_SIGNALS:
    void mapDataChanged();
    void gateIndexChanged();

private:
    void populateModel();
    void matchGates();
    int matchGate(const QString &name) const;

    std::vector<Gate> m_gates;
    MapData *m_data = nullptr;

    QString m_arrivalGate;
    QString m_departureGate;
    int m_arrivalGateRow = -1;
    int m_departureGateRow = -1;
};

}

#endif // KOSMINDOORMAP_GATEMODEL_H

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gatemodel.h"

#include <QCollator>
#include <QDebug>
#include <QPointF>

using namespace KOSMIndoorMap;

GateModel::GateModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

GateModel::~GateModel() = default;

MapData* GateModel::mapData() const
{
    return m_data;
}

void GateModel::setMapData(MapData* data)
{
    // ### do not check for m_data != data, this does not actually change!
    beginResetModel();
    m_gates.clear();
    m_data = data;
    if (m_data) {
        m_tagKeys.mxArrival = m_data->dataSet().makeTagKey("mx:arrival");
        m_tagKeys.mxDeparture = m_data->dataSet().makeTagKey("mx:departure");
        populateModel();
    }
    endResetModel();
    emit mapDataChanged();
    matchGates();
}

bool GateModel::isEmpty() const
{
    return rowCount() == 0;
}

int GateModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }

    return m_gates.size();
}

QVariant GateModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    const auto &gate = m_gates[index.row()];
    switch (role) {
        case Qt::DisplayRole:
            return gate.name;
        case CoordinateRole:
            return QPointF(gate.node.coordinate.lonF(), gate.node.coordinate.latF());
        case ElementRole:
            return QVariant::fromValue(OSM::Element(&gate.node));
        case LevelRole:
            return gate.level;
        case ArrivalGateRole:
            return index.row() == m_arrivalGateRow;
        case DepartureGateRole:
            return index.row() == m_departureGateRow;
        case HiddenElementRole:
            return QVariant::fromValue(gate.sourceElement);
    }

    return {};
}

QHash<int, QByteArray> GateModel::roleNames() const
{
    auto n = QAbstractListModel::roleNames();
    n.insert(CoordinateRole, "coordinate");
    n.insert(ElementRole, "osmElement");
    n.insert(LevelRole, "level");
    n.insert(ArrivalGateRole, "isArrivalGate");
    n.insert(DepartureGateRole, "isDepartureGate");
    n.insert(HiddenElementRole, "hiddenElement");
    return n;
}

void GateModel::populateModel()
{
    if (!m_data) {
        return;
    }

    const auto aerowayKey = m_data->dataSet().tagKey("aeroway");
    if (aerowayKey.isNull()) { // not looking at an airport at all here
        return;
    }

    for (auto it = m_data->m_levelMap.begin(); it != m_data->m_levelMap.end(); ++it) {
        for (const auto &e : (*it).second) {
            if (e.type() != OSM::Type::Node || e.tagValue(aerowayKey) != "gate") {
                continue;
            }

            const auto l = e.tagValue("ref").split(';');
            for (const auto &n : l) {
                if (n.isEmpty()) {
                    continue;
                }

                Gate gate;
                gate.name = QString::fromUtf8(n);
                gate.sourceElement = e;
                gate.node = *e.node();
                gate.node.id = m_data->dataSet().nextInternalId();
                OSM::setTagValue(gate.node, m_data->dataSet().tagKey("name"), "TODO");
                gate.level = (*it).first.numericLevel();
                m_gates.push_back(gate);
            }
        }
    }

    QCollator c{QLocale()};
    c.setNumericMode(true);
    c.setIgnorePunctuation(true);
    c.setCaseSensitivity(Qt::CaseInsensitive);
    std::sort(m_gates.begin(), m_gates.end(), [&c](const auto &lhs, const auto &rhs) {
        return c.compare(lhs.name, rhs.name) < 0;
    });

    qDebug() << m_gates.size() << "gates found";
}

void GateModel::setArrivalGate(const QString &name)
{
    m_arrivalGate = name;
    matchGates();
}

void GateModel::setDepartureGate(const QString &name)
{
    m_departureGate = name;
    matchGates();
}

int GateModel::arrivalGateRow() const
{
    return m_arrivalGateRow;
}

int GateModel::departureGateRow() const
{
    return m_departureGateRow;
}

void GateModel::matchGates()
{
    setGateTag(m_arrivalGateRow, m_tagKeys.mxArrival, false);
    m_arrivalGateRow = matchGate(m_arrivalGate);
    setGateTag(m_arrivalGateRow, m_tagKeys.mxArrival, true);

    setGateTag(m_departureGateRow, m_tagKeys.mxDeparture, false);
    m_departureGateRow = matchGate(m_departureGate);
    setGateTag(m_departureGateRow, m_tagKeys.mxDeparture, true);

    emit gateIndexChanged();
    if (m_arrivalGateRow >= 0) {
        emit dataChanged(index(m_arrivalGateRow, 0), index(m_arrivalGateRow, 0));
    }
    if (m_departureGateRow >= 0) {
        emit dataChanged(index(m_departureGateRow, 0), index(m_departureGateRow, 0));
    }
}

int GateModel::matchGate(const QString &name) const
{
    if (name.isEmpty()) {
        return -1;
    }

    int i = 0;
    for (const auto &g : m_gates) {
        if (g.name == name) {
            return i;
        }
        ++i;
    }

    return -1;
}

void GateModel::setGateTag(int idx, OSM::TagKey key, bool enabled)
{
    if (idx < 0) {
        return;
    }

    OSM::setTagValue(m_gates[idx].node, key, enabled ? "1" : "0");
}

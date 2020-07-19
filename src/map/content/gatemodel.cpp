/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gatemodel.h"

#include <QDebug>
#include <QPointF>

using namespace KOSMIndoorMap;

QString Gate::name() const
{
    return QString::fromUtf8(element.tagValue("ref", QLocale()));
}


GateModel::GateModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

GateModel::~GateModel() = default;

const MapData* GateModel::mapData() const
{
    return m_data;
}

void GateModel::setMapData(const MapData* data)
{
    // ### do not check for m_data != data, this does not actually change!
    beginResetModel();
    m_gates.clear();
    m_data = data;
    m_searchDone = false;
    endResetModel();
    emit mapDataChanged();
}

int GateModel::rowCount(const QModelIndex &parent) const
{
    const_cast<GateModel*>(this)->populateModel();
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
            return gate.name();
        case CoordinateRole:
            return QPointF(gate.element.center().lonF(), gate.element.center().latF());
        case LevelRole:
            return gate.level;
    }

    return {};
}

QHash<int, QByteArray> GateModel::roleNames() const
{
    auto n = QAbstractListModel::roleNames();
    n.insert(CoordinateRole, "coordinate");
    n.insert(LevelRole, "level");
    return n;
}

void GateModel::populateModel()
{
    if (m_searchDone || !m_data) {
        return;
    }
    m_searchDone = true;

    const auto aerowayKey = m_data->dataSet().tagKey("aeroway");
    if (aerowayKey.isNull()) { // not looking at an airport at all here
        return;
    }

    for (auto it = m_data->m_levelMap.begin(); it != m_data->m_levelMap.end(); ++it) {
        for (const auto &e : (*it).second) {
            if (e.type() != OSM::Type::Node || e.tagValue(aerowayKey) != "gate") {
                continue;
            }

            Gate gate;
            gate.element = e;
            gate.level = (*it).first.numericLevel();
            m_gates.push_back(gate);
        }
    }

    std::sort(m_gates.begin(), m_gates.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.name() < rhs.name();
    });

    qDebug() << m_gates.size() << "gates found";
}

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "locationqueryoverlayproxymodel.h"

#include <KPublicTransport/Location>
#include <KPublicTransport/LocationQueryModel>

#include <osm/element.h>

using namespace KOSMIndoorMap;
using namespace KPublicTransport;

LocationQueryOverlayProxyModel::LocationQueryOverlayProxyModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

LocationQueryOverlayProxyModel::~LocationQueryOverlayProxyModel() = default;

MapData* LocationQueryOverlayProxyModel::mapData() const
{
    return m_data;
}

void LocationQueryOverlayProxyModel::setMapData(MapData* data)
{
    // ### do not check for m_data != data, this does not actually change!
    beginResetModel();
    m_data = data;
    initialize();
    endResetModel();
    emit mapDataChanged();
}

QAbstractItemModel* LocationQueryOverlayProxyModel::sourceModel() const
{
    return m_sourceModel;
}

void LocationQueryOverlayProxyModel::setSourceModel(QAbstractItemModel *sourceModel)
{
    if (m_sourceModel == sourceModel) {
        return;
    }
    beginResetModel();
    m_sourceModel = sourceModel;
    initialize();
    // TODO watch for changes
    endResetModel();
}

int LocationQueryOverlayProxyModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return m_nodes.size();
}

QVariant LocationQueryOverlayProxyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    switch (role) {
        case ElementRole:
            return QVariant::fromValue(OSM::Element(&m_nodes[index.row()]));
        case LevelRole:
            return 0;
    }

    return {};
}

QHash<int, QByteArray> LocationQueryOverlayProxyModel::roleNames() const
{
    auto n = QAbstractListModel::roleNames();
    n.insert(ElementRole, "osmElement");
    n.insert(LevelRole, "level");
    return n;
}

void LocationQueryOverlayProxyModel::initialize()
{
    static OSM::Id nextId = -1;
    if (!m_data || !m_sourceModel) {
        return;
    }

    const auto overlayTag = m_data->dataSet().makeTagKey("mx:overlay");
    const auto capacityTag = m_data->dataSet().makeTagKey("capacity");
    const auto availableTag = m_data->dataSet().makeTagKey("available");

    m_nodes.clear();
    const auto rows = m_sourceModel->rowCount();
    m_nodes.reserve(rows);
    for (int i = 0; i < rows; ++i) {
        const auto idx = m_sourceModel->index(i, 0);
        const auto loc = idx.data(LocationQueryModel::LocationRole).value<Location>();

        OSM::Node node;
        node.id = --nextId;
        node.coordinate = OSM::Coordinate(loc.latitude(), loc.longitude());
        OSM::setTagValue(node, overlayTag, "bike_rental");
        OSM::setTagValue(node, capacityTag, QByteArray::number(loc.rentalVehicleStation().capacity()));
        OSM::setTagValue(node, availableTag, QByteArray::number(loc.rentalVehicleStation().availableVehicles()));

        m_nodes.push_back(std::move(node));
    }
}

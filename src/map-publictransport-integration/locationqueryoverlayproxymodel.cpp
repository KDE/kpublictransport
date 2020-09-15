/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "locationqueryoverlayproxymodel.h"

#include <KPublicTransport/Location>
#include <KPublicTransport/LocationQueryModel>

#include <osm/element.h>
#include <osm/geomath.h>

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

    if (m_data) {
        m_tagKeys.amenity = m_data->dataSet().makeTagKey("amenity");
        m_tagKeys.capacity = m_data->dataSet().makeTagKey("capacity");
        m_tagKeys.realtimeAvailable = m_data->dataSet().makeTagKey("mx:realtime_available");
        m_tagKeys.network = m_data->dataSet().makeTagKey("network");
        m_tagKeys.mxoid = m_data->dataSet().makeTagKey("mx:oid");
    }

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
    endResetModel();

    connect(m_sourceModel, &QAbstractItemModel::modelReset, this, [this]() {
        beginResetModel();
        initialize();
        endResetModel();
    });
    connect(m_sourceModel, &QAbstractItemModel::rowsInserted, this, [this](const QModelIndex &parent, int first, int last) {
        if (parent.isValid() || !m_data) {
            return;
        }
        beginInsertRows({}, first, last);
        for (int i = first; i <= last; ++i) {
            m_nodes.insert(m_nodes.begin() + i, nodeForRow(i));
        }
        endInsertRows();
    });
    connect(m_sourceModel, &QAbstractItemModel::rowsRemoved, this, [this](const QModelIndex &parent, int first, int last) {
        if (parent.isValid() || !m_data) {
            return;
        }
        beginRemoveRows({}, first, last);
        m_nodes.erase(m_nodes.begin() + first, m_nodes.begin() + last);
        endRemoveRows();
    });
    connect(m_sourceModel, &QAbstractItemModel::dataChanged, this, [this](const QModelIndex &first, const QModelIndex &last) {
        if (first.parent().isValid() || last.parent().isValid() || !m_data) {
            return;
        }
        for (int i = first.row(); i <= last.row(); ++i) {
            m_nodes[i] = nodeForRow(i);
        }
        emit dataChanged(index(first.row(), 0), index(last.row(), 0));
    });
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
            return QVariant::fromValue(OSM::Element(&m_nodes[index.row()].overlayNode));
        case LevelRole:
            return 0;
        case HiddenElementRole:
            return QVariant::fromValue(m_nodes[index.row()].sourceElement);
    }

    return {};
}

QHash<int, QByteArray> LocationQueryOverlayProxyModel::roleNames() const
{
    auto n = QAbstractListModel::roleNames();
    n.insert(ElementRole, "osmElement");
    n.insert(LevelRole, "level");
    n.insert(HiddenElementRole, "hiddenElement");
    return n;
}

void LocationQueryOverlayProxyModel::initialize()
{
    if (!m_data || !m_sourceModel) {
        return;
    }

    m_nodes.clear();
    const auto rows = m_sourceModel->rowCount();
    m_nodes.reserve(rows);
    for (int i = 0; i < rows; ++i) {
        m_nodes.push_back(nodeForRow(i));
    }
}

LocationQueryOverlayProxyModel::Info LocationQueryOverlayProxyModel::nodeForRow(int row) const
{
    const auto idx = m_sourceModel->index(row, 0);
    const auto loc = idx.data(LocationQueryModel::LocationRole).value<Location>();

    Info info;
    info.overlayNode.coordinate = OSM::Coordinate(loc.latitude(), loc.longitude());

    // try to find a matching node in the base OSM data
    for (const auto &n : m_data->dataSet().nodes) {
        if (OSM::distance(n.coordinate, info.overlayNode.coordinate) < 10 && OSM::tagValue(n, m_tagKeys.amenity) == "bicycle_rental") {
            qDebug() << "found matching node, cloning that!" << n.url();
            info.sourceElement = OSM::Element(&n);
            info.overlayNode = n;
            OSM::setTagValue(info.overlayNode, m_tagKeys.mxoid, QByteArray::number(qlonglong(n.id)));
            break;
        }
    }

    info.overlayNode.id = m_data->dataSet().nextInternalId();
    OSM::setTagValue(info.overlayNode, m_tagKeys.amenity, "bicycle_rental");
    if (loc.rentalVehicleStation().capacity() >= 0) {
        OSM::setTagValue(info.overlayNode, m_tagKeys.capacity, QByteArray::number(loc.rentalVehicleStation().capacity()));
    }
    OSM::setTagValue(info.overlayNode, m_tagKeys.realtimeAvailable, QByteArray::number(loc.rentalVehicleStation().availableVehicles()));
    if (OSM::tagValue(info.overlayNode, m_tagKeys.network).isEmpty()) {
        OSM::setTagValue(info.overlayNode, m_tagKeys.network, loc.rentalVehicleStation().network().name().toUtf8());
    }
    return info;
}

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "platformmodel.h"
#include "platformfinder.h"

#include <KOSMIndoorMap/MapData>

#include <QPointF>

#include <limits>

using namespace KOSMIndoorMap;

static constexpr auto TOP_PARENT = std::numeric_limits<quintptr>::max();

PlatformModel::PlatformModel(QObject* parent) :
    QAbstractItemModel(parent)
{
}

PlatformModel::~PlatformModel() = default;

MapData* PlatformModel::mapData() const
{
    return m_data;
}

void PlatformModel::setMapData(MapData* data)
{
    // ### do not check for m_data != data, this does not actually change!
    beginResetModel();
    m_platforms.clear();
    m_data = data;
    if (m_data) {
        PlatformFinder finder;
        m_platforms = finder.find(m_data);
    }
    endResetModel();
    emit mapDataChanged();
    matchPlatforms();
}

bool PlatformModel::isEmpty() const
{
    return rowCount() == 0;
}

int PlatformModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 1;
}

int PlatformModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return parent.internalId() == TOP_PARENT ? m_platforms[parent.row()].sections().size() : 0;
    }

    return m_platforms.size();
}

QVariant PlatformModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    if (index.internalId() == TOP_PARENT) {
        const auto &platform = m_platforms[index.row()];
        switch (role) {
            case Qt::DisplayRole:
                return platform.name();
            case CoordinateRole:
                return QPointF(platform.position().lonF(), platform.position().latF());
            case ElementRole:
                return QVariant::fromValue(platform.stopPoint());
            case LevelRole:
                return platform.level();
            case TransportModeRole:
                return platform.mode();
            case LinesRole:
                return platform.lines;
            case ArrivalPlatformRole:
                return index.row() == m_arrivalPlatformRow;
            case DeparturePlatformRole:
                return index.row() == m_departurePlatformRow;
        }
    } else {
        const auto &platform = m_platforms[index.internalId()];
        const auto &section = platform.sections()[index.row()];
        switch (role) {
            case Qt::DisplayRole:
                return section.name;
            case CoordinateRole:
                return QPointF(section.position.center().lonF(), section.position.center().latF());
            case ElementRole:
                return QVariant::fromValue(section.position);
            case LevelRole:
                return platform.level();
        }
    }

    return {};
}

QModelIndex PlatformModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        return createIndex(row, column, TOP_PARENT);
    }
    return createIndex(row, column, parent.row());
}

QModelIndex PlatformModel::parent(const QModelIndex &child) const
{
    if (!child.isValid() || child.internalId() == TOP_PARENT) {
        return {};
    }
    return createIndex(child.internalId(), 0, TOP_PARENT);
}

QHash<int, QByteArray> PlatformModel::roleNames() const
{
    auto n = QAbstractItemModel::roleNames();
    n.insert(CoordinateRole, "coordinate");
    n.insert(ElementRole, "osmElement");
    n.insert(LevelRole, "level");
    n.insert(TransportModeRole, "mode");
    n.insert(LinesRole, "lines");
    n.insert(ArrivalPlatformRole, "isArrivalPlatform");
    n.insert(DeparturePlatformRole, "isDeparturePlatform");
    return n;
}

void PlatformModel::setArrivalPlatform(const QString &name, Platform::Mode mode)
{
    m_arrivalPlatform.setName(name);
    m_arrivalPlatform.setMode(mode);
    matchPlatforms();
}

void PlatformModel::setDeparturePlatform(const QString &name, Platform::Mode mode)
{
    m_departurePlatform.setName(name);
    m_departurePlatform.setMode(mode);
    matchPlatforms();
}

int PlatformModel::arrivalPlatformRow() const
{
    return m_arrivalPlatformRow;
}

int PlatformModel::departurePlatformRow() const
{
    return m_departurePlatformRow;
}

void PlatformModel::matchPlatforms()
{
    m_arrivalPlatformRow = matchPlatform(m_arrivalPlatform);
    m_departurePlatformRow = matchPlatform(m_departurePlatform);
    emit platformIndexChanged();
    if (m_arrivalPlatformRow >= 0) {
        emit dataChanged(index(m_arrivalPlatformRow, 0), index(m_arrivalPlatformRow, 0));
    }
    if (m_departurePlatformRow >= 0) {
        emit dataChanged(index(m_departurePlatformRow, 0), index(m_departurePlatformRow, 0));
    }
}

int PlatformModel::matchPlatform(const Platform &platform) const
{
    if (platform.name().isEmpty()) {
        return -1;
    }

    int i = 0;
    for (const auto &p : m_platforms) {
        if (p.name() == platform.name() && p.mode() == platform.mode()) { // TODO this needs to be a bit more complex to also handle platform section
            return i;
        }
        ++i;
    }
    return -1;
}

#include "moc_platformmodel.cpp"

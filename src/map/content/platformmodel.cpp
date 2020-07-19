/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "platformmodel.h"

#include <KOSMIndoorMap/MapData>

#include <QCollator>
#include <QPointF>

using namespace KOSMIndoorMap;

QCollator PlatformModel::m_collator;

PlatformModel::PlatformModel(QObject* parent) :
    QAbstractListModel(parent)
{
    m_collator.setLocale(QLocale());
    m_collator.setNumericMode(true);
    m_collator.setIgnorePunctuation(true);
    m_collator.setCaseSensitivity(Qt::CaseInsensitive);
}

PlatformModel::~PlatformModel() = default;

const MapData* PlatformModel::mapData() const
{
    return m_data;
}

void PlatformModel::setMapData(const MapData* data)
{
    // ### do not check for m_data != data, this does not actually change!
    beginResetModel();
    m_platforms.clear();
    m_data = data;
    m_searchDone = false;
    endResetModel();
    emit mapDataChanged();
}

int PlatformModel::rowCount(const QModelIndex &parent) const
{
    const_cast<PlatformModel*>(this)->populateModel();
    if (parent.isValid()) {
        return 0;
    }

    return m_platforms.size();
}

QVariant PlatformModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return {};
    }

    const auto &platform = m_platforms[index.row()];
    switch (role) {
        case Qt::DisplayRole:
            return platform.name;
        case CoordinateRole:
            return QPointF(platform.element.center().lonF(), platform.element.center().latF());
        case LevelRole:
            return platform.level;
    }

    return {};
}

QHash<int, QByteArray> PlatformModel::roleNames() const
{
    auto n = QAbstractListModel::roleNames();
    n.insert(CoordinateRole, "coordinate");
    n.insert(LevelRole, "level");
    return n;
}

void PlatformModel::populateModel()
{
    if (m_searchDone || !m_data) {
        return;
    }
    m_searchDone = true;

    const auto railwayKey = m_data->dataSet().tagKey("railway");
    const auto ptKey = m_data->dataSet().tagKey("public_transport");
    if (ptKey.isNull() && railwayKey.isNull()) {
        return;
    }

    for (auto it = m_data->m_levelMap.begin(); it != m_data->m_levelMap.end(); ++it) {
        for (const auto &e : (*it).second) {
            if (e.type() == OSM::Type::Node || e.type() == OSM::Type::Relation) {
                continue;
            }
            const auto railway = e.tagValue(railwayKey);
            if (railway == "rail" || railway == "light_rail") {
                OSM::for_each_node(m_data->dataSet(), *e.way(), [this, ptKey, &it](const auto &node) {
                    const auto pt = OSM::tagValue(node, ptKey);
                    if (pt == "stop_point" || pt == "stop_position") {
                        Platform platform;
                        platform.element = OSM::Element(&node);
                        platform.level = (*it).first.numericLevel();
                        platform.name = QString::fromUtf8(platform.element.tagValue("local_ref", "ref", QLocale()));
                        addPlatform(std::move(platform));
                    }
                });
            }
        }
    }

    qDebug() << m_platforms.size() << "platforms found";
}

void PlatformModel::addPlatform(Platform &&platform)
{
    if (platform.name.isEmpty()) {
        return;
    }

    auto it = std::lower_bound(m_platforms.begin(), m_platforms.end(), platform, comparePlatform);
    if (it != m_platforms.end() && (*it).element.id() == platform.element.id()) {
        return;
    }
    m_platforms.insert(it, std::move(platform));
}

bool PlatformModel::comparePlatform(const Platform &lhs, const Platform &rhs)
{
    if (lhs.name == rhs.name) {
        return lhs.element.id() < rhs.element.id();
    }
    return m_collator.compare(lhs.name, rhs.name) < 0;
}

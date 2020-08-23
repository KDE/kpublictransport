/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "overlaysource.h"

#include <QAbstractItemModel>
#include <QDebug>

using namespace KOSMIndoorMap;

OverlaySource::OverlaySource(QAbstractItemModel *model)
{
    const auto roles = model->roleNames();
    for (auto it = roles.begin(); it != roles.end(); ++it) {
        if (it.value() == "osmElement") {
            m_elementRole = it.key();
        } else if (it.value() == "level") {
            m_floorRole = it.key();
        }
    }
    if (m_elementRole < 0 || m_floorRole < 0) {
        qWarning() << model << " - model does not provide the required roles!";
        return;
    }
    m_model = model;
}

OverlaySource::~OverlaySource() = default;

void OverlaySource::setUpdateCallback(QObject *context, const std::function<void()> &updateFunc) const
{
    if (!m_model) {
        return;
    }
    QObject::connect(m_model, &QAbstractItemModel::modelReset, context, updateFunc);
    QObject::connect(m_model, &QAbstractItemModel::rowsInserted, context, updateFunc);
    QObject::connect(m_model, &QAbstractItemModel::rowsRemoved, context, updateFunc);
    QObject::connect(m_model, &QAbstractItemModel::dataChanged, context, updateFunc);
}

void OverlaySource::forEach(int floorLevel, const std::function<void (OSM::Element, int)> &func) const
{
    if (!m_model) {
        return;
    }

    const auto rows = m_model->rowCount();
    for (int i = 0; i < rows; ++i) {
        const auto idx = m_model->index(i, 0);
        const auto floor = idx.data(m_floorRole).toInt();
        if (floor != floorLevel) {
            continue;
        }
        const auto elem = idx.data(m_elementRole).value<OSM::Element>();
        func(elem, floor);
    }
}

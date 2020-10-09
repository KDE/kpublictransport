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
        } else if (it.value() == "hiddenElement") {
            m_hiddenElementRole = it.key();
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

void OverlaySource::setResetCallback(QObject *context, const std::function<void()> &resetFunc) const
{
    if (!m_model) {
        return;
    }
    QObject::connect(m_model, &QAbstractItemModel::modelReset, context, resetFunc);
}

void OverlaySource::forEach(int floorLevel, const std::function<void (OSM::Element, int)> &func) const
{
    if (!m_model) {
        return;
    }

    recursiveForEach({}, floorLevel, func);
}

void OverlaySource::recursiveForEach(const QModelIndex &rootIdx, int floorLevel, const std::function<void (OSM::Element, int)> &func) const
{
    const auto rows = m_model->rowCount(rootIdx);
    for (int i = 0; i < rows; ++i) {
        const auto idx = m_model->index(i, 0, rootIdx);
        const auto floor = idx.data(m_floorRole).toInt();
        if (floor != floorLevel) {
            continue;
        }

        recursiveForEach(idx, floorLevel, func);

        const auto elem = idx.data(m_elementRole).value<OSM::Element>();
        func(elem, floor);
    }
}

void OverlaySource::hiddenElements(std::vector<OSM::Element> &elems) const
{
    if (!m_model || m_hiddenElementRole < 0) {
        return;
    }

    const auto rows = m_model->rowCount();
    for (int i = 0; i < rows; ++i) {
        const auto idx = m_model->index(i, 0);
        const auto elem = idx.data(m_hiddenElementRole).value<OSM::Element>();
        if (elem.type() != OSM::Type::Null) {
            elems.push_back(elem);
        }
    }
}

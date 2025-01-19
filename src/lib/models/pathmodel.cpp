/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "pathmodel.h"

using namespace KPublicTransport;

PathModel::PathModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

PathModel::~PathModel() = default;

Path PathModel::path() const
{
    return m_path;
}

void PathModel::setPath(const Path &path)
{
    beginResetModel();
    m_path = path;
    endResetModel();
}

int PathModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return m_path.sections().size();
}

QVariant PathModel::data(const QModelIndex &index, int role) const
{
    switch (role) {
        case PathSectionRole:
            return m_path.sections()[index.row()];
        case TurnDirectionRole:
        {
            const auto curDir = m_path.sections()[index.row()].direction();
            if (index.row() == 0) {
                return curDir;
            }
            const auto prevDir = m_path.sections()[index.row() - 1].direction();
            if (prevDir >= 0 && curDir >= 0) {
                return (360 + curDir - prevDir) % 360;
            }
            return curDir;
        }
    }

    return {};
}

QHash<int, QByteArray> PathModel::roleNames() const
{
    auto r = QAbstractListModel::roleNames();
    r.insert(PathSectionRole, "section");
    r.insert(TurnDirectionRole, "turnDirection");
    return r;
}

#include "moc_pathmodel.cpp"

/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "locationhistorymodel.h"
#include "logging.h"

#include <QDirIterator>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>

using namespace KPublicTransport;
using namespace Qt::Literals;

static QString basePath()
{
#ifdef Q_OS_ANDROID
    constexpr auto dataLoc = QStandardPaths::AppDataLocation;
#else
    constexpr auto dataLoc = QStandardPaths::GenericDataLocation;
#endif
    return QStandardPaths::writableLocation(dataLoc) + "/org.kde.kpublictransport/location-history/"_L1;
}

LocationHistoryModel::LocationHistoryModel(QObject *parent)
    : QAbstractListModel(parent)
{
    rescan();
}

LocationHistoryModel::~LocationHistoryModel() = default;

int LocationHistoryModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return (int)m_locations.size();
}

QVariant LocationHistoryModel::data(const QModelIndex &index, int role) const
{
    if (!checkIndex(index)) {
        return {};
    }

    switch (role) {
        case LocationRole: return m_locations[index.row()].loc;
        case LocationNameRole: return m_locations[index.row()].loc.name();
        case LastUsedRole: return m_locations[index.row()].lastUse;
        case UseCountRole: return m_locations[index.row()].useCount;
        case IsRemovableRole: return m_locations[index.row()].removable;
    }

    return {};
}

QHash<int, QByteArray> LocationHistoryModel::roleNames() const
{
    auto r = QAbstractListModel::roleNames();
    r.insert(LocationRole, "location");
    r.insert(LocationNameRole, "locationName");
    r.insert(LastUsedRole, "lastUsed");
    r.insert(UseCountRole, "useCount");
    r.insert(IsRemovableRole, "removable");
    return r;
}

bool LocationHistoryModel::removeRow(int row, const QModelIndex& parent)
{
    return QAbstractListModel::removeRow(row, parent);
}

bool LocationHistoryModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (parent.isValid()) {
        return false;
    }

    const auto path = basePath();
    beginRemoveRows({}, row, row + count - 1);
    for (int i = row; i < row + count; ++i) {
        QFile::remove(path + m_locations[i].id);
    }
    m_locations.erase(m_locations.begin() + row, m_locations.begin() + row + count);
    endRemoveRows();
    return true;
}

void LocationHistoryModel::addLocation(const Location &loc)
{
    for (auto it = m_locations.begin(); it != m_locations.end(); ++it) {
        if (Location::isSame((*it).loc, loc)) {
            (*it).loc = Location::merge((*it).loc, loc);
            (*it).lastUse = QDateTime::currentDateTime();
            (*it).useCount++;
            store(*it);
            const auto idx = index((int)std::distance(m_locations.begin(), it));
            Q_EMIT dataChanged(idx, idx);
            return;
        }
    }

    Data data;
    data.id = QUuid::createUuid().toString(QUuid::WithoutBraces);
    data.loc = loc;
    data.lastUse = QDateTime::currentDateTime();
    data.useCount = 1;
    store(data);

    beginInsertRows({}, (int)m_locations.size(), (int)m_locations.size());
    m_locations.push_back(std::move(data));
    endInsertRows();
}

void LocationHistoryModel::addPresetLocation(const Location &loc, const QDateTime &lastUse, int useCount)
{
    for (auto it = m_locations.begin(); it != m_locations.end(); ++it) {
        if (Location::isSame((*it).loc, loc)) {
            (*it).loc = Location::merge((*it).loc, loc);
            (*it).lastUse = std::max((*it).lastUse, lastUse);
            (*it).useCount += useCount;
            (*it).removable = false;
            const auto idx = index((int)std::distance(m_locations.begin(), it));
            Q_EMIT dataChanged(idx, idx);
            return;
        }
    }

    Data data;
    data.loc = loc;
    data.lastUse = lastUse;
    data.useCount = useCount;
    data.removable = false;
    store(data);

    beginInsertRows({}, (int)m_locations.size(), (int)m_locations.size());
    m_locations.push_back(std::move(data));
    endInsertRows();
}

void LocationHistoryModel::clearPresetLocations()
{
    beginResetModel();
    m_locations.clear();
    endResetModel();
    rescan();
}

void LocationHistoryModel::clear()
{
    beginResetModel();
    const auto path = basePath();
    for (const auto &data : m_locations) {
        QFile::remove(path + data.id);
    }
    m_locations.clear();
    endResetModel();
}

void LocationHistoryModel::rescan()
{
    beginResetModel();
    for(QDirIterator it(basePath(), QDir::Files); it.hasNext();) {
        QFile f(it.next());
        if (!f.open(QFile::ReadOnly)) {
            qCWarning(Log) << "Unable to read history entry:" << f.fileName() << f.errorString();
            continue;
        }

        const auto doc = QJsonDocument::fromJson(f.readAll());
        const auto obj = doc.object();
        Data data;
        data.id = it.fileInfo().baseName();
        data.loc = Location::fromJson(obj.value("location"_L1).toObject());
        data.lastUse = QDateTime::fromString(obj.value("lastUse"_L1).toString(), Qt::ISODate);
        data.useCount = obj.value("useCount"_L1).toInt();
        m_locations.push_back(std::move(data));
    }
    endResetModel();
}

void LocationHistoryModel::store(const LocationHistoryModel::Data &data)
{
    if (data.id.isEmpty()) {
        return;
    }

    const auto path = basePath();
    QDir().mkpath(path);

    QFile f(path + data.id);
    if (!f.open(QFile::WriteOnly)) {
        qCWarning(Log) << "Unable to write history entry:" << f.fileName() << f.errorString();
        return;
    }

    QJsonObject obj;
    obj.insert("location"_L1, Location::toJson(data.loc));
    obj.insert("lastUse"_L1, data.lastUse.toString(Qt::ISODate));
    obj.insert("useCount"_L1, data.useCount);
    f.write(QJsonDocument(obj).toJson(QJsonDocument::Compact));
}

#include "moc_locationhistorymodel.cpp"

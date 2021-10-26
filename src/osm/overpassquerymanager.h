/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_OVERPASSQUERYMANAGER_H
#define OSM_OVERPASSQUERYMANAGER_H

#include <QObject>

#include <memory>

namespace OSM {

class OverpassQuery;
class OverpassQueryManagerPrivate;

/** Executes OverpassQuery jobs. */
class OverpassQueryManager : public QObject
{
    Q_OBJECT
public:
    explicit OverpassQueryManager(QObject *parent = nullptr);
    ~OverpassQueryManager() override;

    /** Executes @p query.
     *  Once done, OverpassQuery::finished will be emitted.
     */
    void execute(OverpassQuery *query);

private:
    std::unique_ptr<OverpassQueryManagerPrivate> d;
};

}

#endif // OSM_OVERPASSQUERYMANAGER_H

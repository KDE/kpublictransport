/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
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
    ~OverpassQueryManager();

    /** Executes @p query.
     *  Once done, OverpassQuery::finished will be emitted.
     */
    void execute(OverpassQuery *query);

private:
    std::unique_ptr<OverpassQueryManagerPrivate> d;
};

}

#endif // OSM_OVERPASSQUERYMANAGER_H

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

#ifndef LINEINFO_H
#define LINEINFO_H

#include <osm/datatypes.h>

#include <QColor>
#include <QString>

struct LineInfo
{
    Q_GADGET
public:

    LineInfo();
    ~LineInfo();

    enum Mode { // ordered by accuracy in OSM data, ie. higher value -> higher probability of being the correctly detected mode
        Unknown,
        LongDistance,
        RapidTransit,
        Tram,
        Subway,
    };
    Q_ENUM(Mode)

    static bool isUseful(const LineInfo &info);
    static Mode determineMode(const OSM::Relation &rel);
    static LineInfo fromRelation(const OSM::Relation &rel);
    static void merge(LineInfo &lhs, const LineInfo &rhs);

    OSM::Id relId;
    OSM::BoundingBox bbox;
    QString name;
    QColor color;
    Mode mode = Unknown;
    QString logoName;
    QString wdId;
};

QDebug operator<<(QDebug debug, LineInfo info);

#endif // LINEINFO_H

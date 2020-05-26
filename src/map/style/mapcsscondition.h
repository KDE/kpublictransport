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

#ifndef KOSMINDOORMAP_MAPCSSCONDITION_H
#define KOSMINDOORMAP_MAPCSSCONDITION_H

#include <osm/datatypes.h>

#include <QByteArray>
#include <QString>

#include <cmath>
#include <memory>
#include <vector>

class QIODevice;

namespace KOSMIndoorMap {

class MapCSSState;

/** Selector condition. */
class MapCSSCondition
{
public:
    explicit MapCSSCondition();
    MapCSSCondition(const MapCSSCondition&) = delete;
    MapCSSCondition(MapCSSCondition&&);
    ~MapCSSCondition();
    MapCSSCondition& operator=(const MapCSSCondition&) = delete;

    /** Resolve tag keys. */
    void compile(const OSM::DataSet &dataSet);
    /** Condition matches the given evaluation state. */
    bool matches(const MapCSSState &state) const;

    enum Operator {
        None,
        Equal,
        NotEqual,
        LessThan,
        GreaterThan,
        LessOrEqual,
        GreaterOrEqual
    };

    void setKey(const char *key, int len);
    void setOperation(Operator op);
    void setValue(const char *value, int len);
    void setValue(double val);

    void write(QIODevice *out) const;

private:
    OSM::TagKey m_tagKey;
    QByteArray m_key;
    QString m_value;
    double m_numericValue = NAN;
    Operator m_op = None;
};

/** @internal intermediate AST node used during parsing */
class MapCSSConditionHolder
{
public:
    void addCondition(MapCSSCondition *condition);
    std::vector<std::unique_ptr<MapCSSCondition>> conditions;
};

}

#endif // KOSMINDOORMAP_MAPCSSSELECTORCONDITION_H

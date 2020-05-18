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

#include <memory>
#include <vector>

#include <QByteArray>
#include <QString>

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

    /** Condition matches the given evaluation state. */
    bool matches(const MapCSSState &state) const;

    QByteArray m_key;

    enum Operator {
        None,
        Equal,
        NotEqual,
    };
    Operator op = None;

    QString m_value;

    void setKey(const char *key, int len);
    void setValue(const char *value, int len);

    void write(QIODevice *out) const;
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

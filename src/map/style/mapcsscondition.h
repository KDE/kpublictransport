/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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
    QByteArray m_value;
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

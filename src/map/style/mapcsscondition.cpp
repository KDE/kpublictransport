/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mapcsscondition.h"
#include "mapcssstate.h"

#include <QDebug>
#include <QIODevice>

using namespace KOSMIndoorMap;

MapCSSCondition::MapCSSCondition() = default;
MapCSSCondition::MapCSSCondition(MapCSSCondition &&) = default;
MapCSSCondition::~MapCSSCondition() = default;

static double toNumber(const QByteArray &val)
{
    bool res = false;
    const auto n = val.toDouble(&res);
    return res ? n : NAN;
}

void MapCSSCondition::compile(const OSM::DataSet &dataSet)
{
    m_tagKey = dataSet.tagKey(m_key.constData());
}

bool MapCSSCondition::matches(const MapCSSState &state) const
{
    if (m_tagKey.isNull()) {
        return false;
    }

    const auto v = state.element.tagValue(m_tagKey);
    switch (m_op) {
        case KeySet: return !v.isEmpty();
        case KeyNotSet: return v.isEmpty();
        case Equal: return std::isnan(m_numericValue) ? v == m_value : toNumber(v) == m_numericValue;
        case NotEqual: return std::isnan(m_numericValue) ? v != m_value : toNumber(v) != m_numericValue;
        case LessThan: return toNumber(v) < m_numericValue;
        case GreaterThan: return toNumber(v) > m_numericValue;
        case LessOrEqual: return toNumber(v) <= m_numericValue;
        case GreaterOrEqual: return toNumber(v) >= m_numericValue;
    }
    return false;
}

bool MapCSSCondition::matchesCanvas(const MapCSSState &state) const
{
    if (m_key != "level") {
        return false;
    }

    switch (m_op) {
        case KeySet:
        case KeyNotSet:
            return false;
        case Equal: return (state.floorLevel/10) == m_numericValue;
        case NotEqual: return (state.floorLevel/10) != m_numericValue;
        case LessThan: return (state.floorLevel/10) < m_numericValue;
        case GreaterThan: return (state.floorLevel/10) > m_numericValue;
        case LessOrEqual: return (state.floorLevel/10) <= m_numericValue;
        case GreaterOrEqual: return (state.floorLevel/10) >= m_numericValue;
    }

    return false;
}

void MapCSSCondition::setKey(const char *key, int len)
{
    m_key = QByteArray(key, len);
}

void MapCSSCondition::setOperation(MapCSSCondition::Operator op)
{
    m_op = op;
}

void MapCSSCondition::setValue(const char *value, int len)
{
    m_value = QByteArray(value, len);
}

void MapCSSCondition::setValue(double val)
{
    m_numericValue = val;
}

void MapCSSCondition::write(QIODevice *out) const
{
    out->write("[");
    if (m_op == KeyNotSet) { out->write("!"); }
    out->write(m_key);

    switch (m_op) {
        case KeySet:
        case KeyNotSet:
            out->write("]"); return;
        case Equal: out->write("="); break;
        case NotEqual: out->write("!="); break;
        case LessThan: out->write("<"); break;
        case GreaterThan: out->write(">"); break;
        case LessOrEqual: out->write("<="); break;
        case GreaterOrEqual: out->write(">="); break;
    }

    if (m_numericValue != NAN && m_value.isEmpty()) {
        out->write(QByteArray::number(m_numericValue));
    } else {
        out->write(m_value);
    }

    out->write("]");
}


void MapCSSConditionHolder::addCondition(MapCSSCondition *condition)
{
    conditions.push_back(std::unique_ptr<MapCSSCondition>(condition));
}

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
        case None: return !v.isEmpty();
        case Equal: return v == m_value;
        case NotEqual: return v != m_value;
        case LessThan: return toNumber(v) < m_numericValue;
        case GreaterThan: return toNumber(v) > m_numericValue;
        case LessOrEqual: return toNumber(v) <= m_numericValue;
        case GreaterOrEqual: return toNumber(v) >= m_numericValue;
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
    out->write(m_key);

    switch (m_op) {
        case None: out->write("]"); return;
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

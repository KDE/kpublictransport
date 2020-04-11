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

#include "entities.h"

#include <QJsonArray>
#include <QVariant>

using namespace Wikidata;

Item::Item() = default;
Item::Item(Wikidata::Q id, const QJsonObject& data)
    : m_id(id)
    , m_data(data)
{
}

Item::~Item() = default;

std::vector<QVariant> Item::values(P property) const
{
    std::vector<QVariant> values;

    const auto propA = m_data.value(QLatin1String("claims")).toObject().value(property.toString()).toArray();
    for (const auto & propV : propA) {
        const auto valueObj = propV.toObject().value(QLatin1String("mainsnak")).toObject().value(QLatin1String("datavalue")).toObject();
        const auto type = valueObj.value(QLatin1String("type")).toString();
        if (type == QLatin1String("string")) {
            values.push_back(valueObj.value(QLatin1String("value")).toString());
        } else if (type == QLatin1String("wikibase-entityid")) {
            values.push_back(QVariant::fromValue(Wikidata::Q(valueObj.value(QLatin1String("value")).toObject().value(QLatin1String("id")).toString())));
        }

        // TODO other types
    }

    return values;
}

QVariant Item::value(Wikidata::P property) const
{
    const auto vals = values(property);
    return vals.empty() ? QVariant() : vals[0];
}

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

#include "datatypes.h"

using namespace OSM;

DataSet::DataSet() = default;
DataSet::DataSet(DataSet &&) = default;
DataSet::~DataSet()
{
    std::for_each(m_stringPool.begin(), m_stringPool.end(), free);
}

DataSet& DataSet::operator=(DataSet &&) = default;

TagKey DataSet::makeTagKey(const char *keyName, DataSet::TagKeyMemory keyMemOpt)
{
    const auto it = std::lower_bound(m_tagKeyRegistry.begin(), m_tagKeyRegistry.end(), keyName, [](TagKey lhs, const char *rhs) {
        return std::strcmp(lhs.key, rhs) < 0;
    });
    if (it == m_tagKeyRegistry.end() || std::strcmp((*it).key, keyName) != 0) {
        if (keyMemOpt == TagKeyIsTransient) {
            auto s = strdup(keyName);
            m_stringPool.push_back(s);
            keyName = s;
        }
        TagKey k(keyName);
        m_tagKeyRegistry.insert(it, k);
        return k;
    }
    return (*it);
}

TagKey DataSet::tagKey(const char *keyName) const
{
    const auto it = std::lower_bound(m_tagKeyRegistry.begin(), m_tagKeyRegistry.end(), keyName, [](TagKey lhs, const char *rhs) {
        return std::strcmp(lhs.key, rhs) < 0;
    });
    if (it == m_tagKeyRegistry.end() || std::strcmp((*it).key, keyName) != 0) {
        return {};
    }
    return (*it);
}

void DataSet::addNode(Node &&node)
{
    const auto it = std::lower_bound(nodes.begin(), nodes.end(), node);
    if (it != nodes.end() && (*it).id == node.id) {
        // do we need to merge something here?
        return;
    }
    nodes.insert(it, std::move(node));
}

void DataSet::addWay(Way &&way)
{
    const auto it = std::lower_bound(ways.begin(), ways.end(), way);
    if (it != ways.end() && (*it).id == way.id) {
        // already there?
        return;
    }
    ways.insert(it, std::move(way));
}

void DataSet::addRelation(Relation &&rel)
{
    const auto it = std::lower_bound(relations.begin(), relations.end(), rel);
    if (it != relations.end() && (*it).id == rel.id) {
        // do we need to merge something here?
        return;
    }
    relations.insert(it, std::move(rel));
}

// resolve ids for elements split in Marble vector tiles
template <typename T>
static QString actualIdString(const T &elem)
{
    const auto mxoid = OSM::tagValue(elem, "mx:oid");
    return mxoid.isEmpty() ? QString::number(elem.id) : mxoid;
}

QString OSM::Node::url() const
{
    return QStringLiteral("https://openstreetmap.org/node/") + actualIdString(*this);
}

bool OSM::Way::isClosed() const
{
    return nodes.size() >= 2 && nodes.front() == nodes.back();
}

QString OSM::Way::url() const
{
    return QStringLiteral("https://openstreetmap.org/way/") + actualIdString(*this);
}

QString OSM::Relation::url() const
{
    return QStringLiteral("https://openstreetmap.org/relation/") + actualIdString(*this);
}

QDebug operator<<(QDebug debug, OSM::Coordinate coord)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << '(' << coord.latF() << ',' << coord.lonF() << ')';
    return debug;
}

QDebug operator<<(QDebug debug, OSM::BoundingBox bbox)
{
    QDebugStateSaver saver(debug);
    debug.nospace() << '[' << bbox.min.latF() << ',' << bbox.min.lonF() << '|' << bbox.max.latF() << ',' << bbox.max.lonF() << ']';
    return debug;
}

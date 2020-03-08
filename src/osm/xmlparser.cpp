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

#include "xmlparser_p.h"
#include "datatypes.h"

#include <QIODevice>
#include <QXmlStreamReader>

using namespace OSM;

XmlParser::XmlParser(DataSet* dataSet)
    : m_dataSet(dataSet)
{
    assert(dataSet);
}

void XmlParser::parse(QIODevice *io)
{
    QXmlStreamReader reader(io);
    while (!reader.atEnd()) {
        const auto token = reader.readNext();
        if (token != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("node")) {
            parseNode(reader);
        }
        else if (reader.name() == QLatin1String("way")) {
            parseWay(reader);
        }
        else if (reader.name() == QLatin1String("relation")) {
            parseRelation(reader);
        }
    }
}

void XmlParser::parseNode(QXmlStreamReader &reader)
{
    Node node;
    node.id = reader.attributes().value(QLatin1String("id")).toLongLong();
    node.coordinate = Coordinate(reader.attributes().value(QLatin1String("lat")).toDouble(), reader.attributes().value(QLatin1String("lon")).toDouble());

    while (!reader.atEnd() && reader.readNext() != QXmlStreamReader::EndElement) {
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            continue;
        }
        if (reader.name() == QLatin1String("tag")) {
            parseTag(reader, node);
        } else {
            reader.skipCurrentElement();
        }
    }

    m_dataSet->addNode(std::move(node));
}

void XmlParser::parseWay(QXmlStreamReader &reader)
{
    // TODO
    reader.skipCurrentElement();
}

void XmlParser::parseRelation(QXmlStreamReader &reader)
{
    // TODO
    reader.skipCurrentElement();
}

template<typename T>
void XmlParser::parseTag(QXmlStreamReader& reader, T& elem)
{
    // TODO shared value pool for the key, sorting by key
    Tag t;
    t.key = reader.attributes().value(QLatin1String("k")).toString();
    t.value = reader.attributes().value(QLatin1String("v")).toString();
    elem.tags.push_back(t);
    reader.skipCurrentElement();
}

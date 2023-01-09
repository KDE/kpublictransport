/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "xmlparser.h"
#include "datatypes.h"

#include <QDebug>
#include <QIODevice>
#include <QXmlStreamReader>

#include <cmath>

using namespace OSM;

XmlParser::XmlParser(DataSet* dataSet)
    : AbstractReader(dataSet)
{
}

void XmlParser::readFromIODevice(QIODevice *io)
{
    QXmlStreamReader reader(io);
    while (!reader.atEnd() && !reader.hasError()) {
        const auto token = reader.readNext();
        if (token != QXmlStreamReader::StartElement) {
            continue;
        }

        if (reader.name() == QLatin1String("node")) {
            parseNode(reader);
        } else if (reader.name() == QLatin1String("way")) {
            parseWay(reader);
        } else if (reader.name() == QLatin1String("relation")) {
            parseRelation(reader);
        } else if (reader.name() == QLatin1String("remark")) {
            m_error = reader.readElementText();
            return;
        }
    }

    if (reader.hasError()) {
        m_error = reader.errorString();
    }
}

// parse double coordinate value without actually doing floating point computations
// this avoids any loss in precision we can other get heret
uint32_t parseCoordinateValue(QStringView s, int offset)
{
    const auto idx = s.indexOf(QLatin1Char('.'));
    if (idx < 0) {
        return s.toUInt() * 10'000'000;
    }
    uint32_t result = (uint32_t)(s.left(idx).toInt() + offset) * 10'000'000;
    const auto decimals = s.mid(idx + 1);
    if (decimals.size() >= 7) {
        result += decimals.left(7).toUInt();
    } else {
        result += decimals.toUInt() * std::pow(10, 7 - decimals.size());
    }
    return result;
}

void XmlParser::parseNode(QXmlStreamReader &reader)
{
    Node node;
    node.id = reader.attributes().value(QLatin1String("id")).toLongLong();
    node.coordinate = Coordinate(parseCoordinateValue(reader.attributes().value(QLatin1String("lat")), 90), parseCoordinateValue(reader.attributes().value(QLatin1String("lon")), 180));

    while (!reader.atEnd() && reader.readNext() != QXmlStreamReader::EndElement) {
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            continue;
        }
        if (reader.name() == QLatin1String("tag")) {
            parseTag(reader, node);
        }
        reader.skipCurrentElement();
    }

    addNode(std::move(node));
}

void XmlParser::parseWay(QXmlStreamReader &reader)
{
    Way way;
    way.id = reader.attributes().value(QLatin1String("id")).toLongLong();

    while (!reader.atEnd() && reader.readNext() != QXmlStreamReader::EndElement) {
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            continue;
        }
        if (reader.name() == QLatin1String("nd")) {
            OSM::Id node;
            node = reader.attributes().value(QLatin1String("ref")).toLongLong();
            way.nodes.push_back(node);
        } else if (reader.name() == QLatin1String("tag")) {
            parseTagOrBounds(reader, way);
        } else if (reader.name() == QLatin1String("bounds")) {
            parseBounds(reader, way);
        }
        reader.skipCurrentElement();
    }

    addWay(std::move(way));
}

void XmlParser::parseRelation(QXmlStreamReader &reader)
{
    Relation rel;
    rel.id = reader.attributes().value(QLatin1String("id")).toLongLong();

    while (!reader.atEnd() && reader.readNext() != QXmlStreamReader::EndElement) {
        if (reader.tokenType() != QXmlStreamReader::StartElement) {
            continue;
        }
        if (reader.name() == QLatin1String("tag")) {
            parseTagOrBounds(reader, rel);
        } else if (reader.name() == QLatin1String("bounds")) { // Overpass style bounding box
            parseBounds(reader, rel);
        } else if (reader.name() == QLatin1String("member")) {
            Member member;
            member.id = reader.attributes().value(QLatin1String("ref")).toLongLong();
            const auto type = reader.attributes().value(QLatin1String("type"));
            if (type == QLatin1String("node")) {
                member.setType(Type::Node);
            } else if (type == QLatin1String("way")) {
                member.setType(Type::Way);
            } else {
                member.setType(Type::Relation);
            }
            member.setRole(m_dataSet->makeRole(reader.attributes().value(QLatin1String("role")).toUtf8().constData(), DataSet::StringIsTransient));
            rel.members.push_back(std::move(member));
        }
        reader.skipCurrentElement();
    }

    addRelation(std::move(rel));
}

template <typename T>
void XmlParser::parseTag(QXmlStreamReader &reader, T &elem)
{
    const auto key = m_dataSet->makeTagKey(reader.attributes().value(QLatin1String("k")).toString().toUtf8().constData(), OSM::DataSet::StringIsTransient);
    OSM::setTagValue(elem, key, reader.attributes().value(QLatin1String("v")).toUtf8());
}

template <typename T>
void XmlParser::parseTagOrBounds(QXmlStreamReader &reader, T &elem)
{
    if (reader.attributes().value(QLatin1String("k")) == QLatin1String("bBox")) { // osmconvert style bounding box
        const auto v = reader.attributes().value(QLatin1String("v")).split(QLatin1Char(','));
        if (v.size() == 4) {
            elem.bbox.min = Coordinate(v[1].toDouble(), v[0].toDouble());
            elem.bbox.max = Coordinate(v[3].toDouble(), v[2].toDouble());
        }
    } else {
        parseTag(reader, elem);
    }
}

template<typename T>
void XmlParser::parseBounds(QXmlStreamReader &reader, T &elem)
{
    // overpass style bounding box
    elem.bbox.min = Coordinate(reader.attributes().value(QLatin1String("minlat")).toDouble(), reader.attributes().value(QLatin1String("minlon")).toDouble());
    elem.bbox.max = Coordinate(reader.attributes().value(QLatin1String("maxlat")).toDouble(), reader.attributes().value(QLatin1String("maxlon")).toDouble());
}

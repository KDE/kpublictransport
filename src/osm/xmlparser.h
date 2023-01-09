/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_XMLPARSER_H
#define OSM_XMLPARSER_H

#include "abstractreader.h"

#include <QString>

class QIODevice;
class QXmlStreamReader;

namespace OSM {

class DataSet;

class XmlParser : public AbstractReader
{
public:
    explicit XmlParser(DataSet *dataSet);

private:
    void readFromIODevice(QIODevice *io) override;

    void parseNode(QXmlStreamReader &reader);
    void parseWay(QXmlStreamReader &reader);
    void parseRelation(QXmlStreamReader &reader);
    template <typename T>
    void parseTag(QXmlStreamReader &reader, T &elem);
    template <typename T>
    void parseTagOrBounds(QXmlStreamReader &reader, T&elem);
    template <typename T>
    void parseBounds(QXmlStreamReader &reader, T &elem);
};

}

#endif // OSM_XMLPARSER_P_H

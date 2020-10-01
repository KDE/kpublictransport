/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_XMLWRITER_H
#define OSM_XMLWRITER_H

class QIODevice;

namespace OSM {
class DataSet;

/** Serialite a OSM::DataSet into OSM XML. */
namespace XmlWriter
{
    void write(const OSM::DataSet &dataSet, QIODevice *out);
}

}

#endif // OSM_XMLWRITER_H

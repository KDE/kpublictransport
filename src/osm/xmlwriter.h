/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_XMLWRITER_H
#define OSM_XMLWRITER_H

#include "abstractwriter.h"

namespace OSM {

/** Serialize a OSM::DataSet into OSM XML. */
class XmlWriter : public AbstractWriter
{
private:
    void writeToIODevice(const OSM::DataSet &dataSet, QIODevice *io) override;
};

}

#endif // OSM_XMLWRITER_H

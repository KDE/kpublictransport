/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_ABSTRACTWRITER_H
#define OSM_ABSTRACTWRITER_H

#include "kosm_export.h"

class QIODevice;

namespace OSM {

class DataSet;

/** Abstract base class for OSM file format writers. */
class KOSM_EXPORT AbstractWriter
{
public:
    virtual ~AbstractWriter();

    /** Write the given data set into @p io.
     *  @param io has to be open.
     */
    void write(const OSM::DataSet &dataSet, QIODevice *io);

protected:
    virtual void writeToIODevice(const OSM::DataSet &dataSet, QIODevice *io) = 0;
};

}

#endif // OSM_ABSTRACTWRITER_H

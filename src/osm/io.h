/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef OSM_IO_H
#define OSM_IO_H

#include "kosm_export.h"
#include "abstractreader.h"
#include "abstractwriter.h"

class QStringView;

#include <memory>

namespace OSM {

class DataSet;

/** Access to OSM file/data readers. */
namespace IO
{

/** Returns a suitable reader for the given file name. */
KOSM_EXPORT std::unique_ptr<AbstractReader> readerForFileName(QStringView fileName, OSM::DataSet *dataSet);
/** Returns a suitable reader for the given MIME type. */
KOSM_EXPORT std::unique_ptr<AbstractReader> readerForMimeType(QStringView mimeType, OSM::DataSet *dataSet);

/** Returns a suitable writer for the given file name. */
KOSM_EXPORT std::unique_ptr<AbstractWriter> writerForFileName(QStringView fileName);
/** Returns a suitable writer for the given MIME type. */
KOSM_EXPORT std::unique_ptr<AbstractWriter> writerForMimeType(QStringView mimeType);

}

}

#endif // OSM_IO_H

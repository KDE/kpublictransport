/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "abstractwriter.h"

#include <QIODevice>

#include <cassert>

using namespace OSM;

AbstractWriter::~AbstractWriter() = default;

void AbstractWriter::write(const OSM::DataSet &dataSet, QIODevice *io)
{
    assert(io);
    assert(io->isOpen());
    writeToIODevice(dataSet, io);
}

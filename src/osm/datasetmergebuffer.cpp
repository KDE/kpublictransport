/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "datasetmergebuffer.h"

using namespace OSM;

void OSM::DataSetMergeBuffer::clear()
{
    nodes.clear();
    ways.clear();
    relations.clear();
}

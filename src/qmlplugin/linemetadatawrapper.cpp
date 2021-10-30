/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "linemetadatawrapper.h"

#include "assetrepository_p.h"
#include "datatypes/lineutil_p.h"
#include "knowledgedb/linemetadata.h"

#include <QDebug>

using namespace KPublicTransport;

Line LineMetaDataWrapper::lookup(const QString &name, double latitude, double longitude, int mode, bool download)
{
    Line line;
    line.setName(name);
    line.setMode(static_cast<Line::Mode>(mode));
    Location loc;
    loc.setCoordinate(latitude, longitude);
    line.applyMetaData(loc, download);
    return line;
}

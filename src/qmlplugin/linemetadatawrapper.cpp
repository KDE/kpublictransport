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
    auto md = LineMetaData::find(latitude, longitude, name, static_cast<Line::Mode>(mode));
    if (md.isNull()) {
        return {};
    }

    Line line;
    LineUtil::setMetaData(line, md);

    if (download && AssetRepository::instance()) {
        AssetRepository::instance()->download(md.logoUrl());
        AssetRepository::instance()->download(md.modeLogoUrl());
    }

    return line;
}

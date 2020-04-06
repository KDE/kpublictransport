/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "lineutil_p.h"
#include "linecompare_p.h"
#include "assetrepository_p.h"

#include <knowledgedb/linemetadata.h>

#include <KPublicTransport/Line>
#include <KPublicTransport/Location>

#include <QColor>
#include <QDebug>
#include <QString>
#include <QUrl>

using namespace KPublicTransport;

bool LineUtil::isSameLineName(const QString &lhs, const QString &rhs)
{
    return Internal::isSameLineName(lhs, rhs);
}

void LineUtil::applyMetaData(Line &line, const Location &loc, bool download)
{
    if (line.name().isEmpty() || !loc.hasCoordinate()) {
        return;
    }

    if (line.mode() == Line::Bus) { // not covered yet, so avoid accidental hits
        return;
    }

    auto metaData = LineMetaData::find(loc.latitude(), loc.longitude(), line.name());
    setMetaData(line, metaData);

    if (download && AssetRepository::instance()) {
        AssetRepository::instance()->download(metaData.logoUrl());
        AssetRepository::instance()->download(metaData.modeLogoUrl());
    }
}

void LineUtil::setMetaData(Line& line, LineMetaData metaData)
{
    line.setMetaData(metaData);
}

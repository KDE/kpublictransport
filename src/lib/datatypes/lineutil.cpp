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

bool LineUtil::isCompatibleMode(Line::Mode lhs, Line::Mode rhs)
{
    if (lhs == rhs || lhs == Line::Unknown || rhs == Line::Unknown) {
        return true;
    }

    if (lhs == Line::Train) {
        return rhs == Line::LocalTrain || rhs == Line::LongDistanceTrain || rhs == Line::RapidTransit;
    }
    if (rhs == Line::Train) {
        return lhs == Line::LocalTrain || lhs == Line::LongDistanceTrain || lhs == Line::RapidTransit;
    }

    return false;
}

void LineUtil::applyMetaData(Line &line, const Location &loc, bool download)
{
    if (line.name().isEmpty() || !loc.hasCoordinate()) {
        return;
    }

    auto metaData = LineMetaData::find(loc.latitude(), loc.longitude(), line.name(), line.mode());
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

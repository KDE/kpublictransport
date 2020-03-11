/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#include "linemetadata.h"
#include "linemetadata_data.cpp"
#include "datatypes/lineutil_p.h"

#include <osm/datatypes.h>

#include <QColor>
#include <QDebug>
#include <QString>
#include <QUrl>

using namespace KPublicTransport;

static QString lookup(uint16_t index)
{
    return QString::fromUtf8(line_data_stringtab + index);
}

LineMetaData::LineMetaData() = default;
LineMetaData::LineMetaData(const LineMetaDataContent *dd)
    : d(dd)
{
}

LineMetaData::~LineMetaData() = default;

bool LineMetaData::isNull() const
{
    return d == nullptr;
}

QString LineMetaData::name() const
{
    return lookup(d->nameIdx);
}

QColor LineMetaData::color() const
{
    return QColor(d->color);
}

QUrl LineMetaData::logoUrl() const
{
    const auto logoName = lookup(d->logoIdx);
    return logoName.isEmpty() ? QUrl() : QUrl(QLatin1String("https://commons.wikimedia.org/wiki/Special:Redirect/file/") + logoName);
}

LineMetaData LineMetaData::find(double latitude, double longitude, const QString &name)
{
    OSM::Coordinate coord(latitude, longitude);
    const auto zIndex = coord.z() >> line_data_zShift;
    const auto zIt = std::lower_bound(std::begin(line_data_zindex), std::end(line_data_zindex), zIndex);
    if (zIt == std::end(line_data_zindex) || (*zIt).z != zIndex) {
        return {};
    }

    auto bucketIt = line_data_bucketTable + (*zIt).lineIdx;
    while ((*bucketIt) != -1) {
        const auto d = line_data + (*bucketIt);
        if (LineUtil::isSameLineName(lookup(d->nameIdx), name)) {
            return LineMetaData(d);
        }
        ++bucketIt;
    }
    return {};
}

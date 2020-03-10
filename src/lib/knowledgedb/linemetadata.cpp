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

#include <osm/datatypes.h>

#include <QColor>
#include <QString>

using namespace KPublicTransport;

static QString lookup(uint16_t index)
{
    return QString::fromUtf8(line_data_stringtab + index);
}

LineMetaData::LineMetaData() = default;
LineMetaData::LineMetaData(LineMetaDataContent *dd)
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

LineMetaData LineMetaData::find(float latitude, float longitude, const QString &name)
{
    // TODO
    return {};
}

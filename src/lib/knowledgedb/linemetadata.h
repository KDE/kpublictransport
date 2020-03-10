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

#ifndef KPUBLICTRANSPORT_LINEMETADATA_H
#define KPUBLICTRANSPORT_LINEMETADATA_H

class QColor;
class QString;

namespace KPublicTransport {

class LineMetaDataContent;

/** Static information about a public transport line. */
class LineMetaData
{
public:
    LineMetaData();
    ~LineMetaData();

    bool isNull() const;
    QString name() const;
    QColor color() const;

    /** Attempts to find information about a line with the given name and a stop at the given coordinates. */
    static LineMetaData find(float latitude, float longitude, const QString &name);

private:
    LineMetaData(LineMetaDataContent *dd);
    LineMetaDataContent *d = nullptr;
};

}

#endif // KPUBLICTRANSPORT_LINEMETADATA_H

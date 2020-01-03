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

#ifndef KPUBLICTRANSPORT_STYLEDSVGIMAGEPROVIDER_H
#define KPUBLICTRANSPORT_STYLEDSVGIMAGEPROVIDER_H

#include <QQuickImageProvider>

namespace KPublicTransport {

/** Image provider injecting a CSS style sheet into an SVG, based on URI parameters. */
class StyledSvgImageProvider : public QQuickImageProvider
{
public:
    explicit StyledSvgImageProvider();
    ~StyledSvgImageProvider();
    QImage requestImage(const QString &id, QSize *size, const QSize &requestedSize) override;
};

}

#endif // KPUBLICTRANSPORT_STYLEDSVGIMAGEPROVIDER_H

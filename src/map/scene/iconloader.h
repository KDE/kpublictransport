/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_ICONLOADER_H
#define KOSMINDOORMAP_ICONLOADER_H

#include <QColor>
#include <QSizeF>
#include <QString>

class QIcon;
class QIODevice;

namespace KOSMIndoorMap {

/** Information determining the icon to load. */
class IconData {
public:
    QString name;
    QSizeF size;
    QColor color;
};

/** Load (colorized) icons for display on the map from various sources. */
class IconLoader
{
public:
    QIcon loadIcon(const IconData &iconData) const;

private:
    QIcon loadSvgAsset(QIODevice *svgFile, const IconData &iconData) const;
};

}

#endif // KOSMINDOORMAP_ICONLOADER_H

/*
    SPDX-FileCopyrightText: 2006 Zack Rusin <zack@kde.org>
    SPDX-FileCopyrightText: 2006-2007, 2008 Fredrik Höglund <fredrik@kde.org>

    The stack blur algorithm was invented by Mario Klingemann <mario@quasimondo.com>

    This implementation is based on the version in Anti-Grain Geometry Version 2.4,
    SPDX-FileCopyrightText: 2002-2005 Maxim Shemanarev (http://www.antigrain.com)

    SPDX-License-Identifier: BSD-2-Clause
*/

#ifndef KOSMINDOORMAP_STACKBLUR_H
#define KOSMINDOORMAP_STACKBLUR_H

class QImage;

namespace KOSMIndoorMap {

/** Stack blur algorithm, taken from KIO. */
namespace StackBlur
{
    void blur(QImage &image, float radius);
}

}

#endif // KOSMINDOORMAP_STACKBLUR_H

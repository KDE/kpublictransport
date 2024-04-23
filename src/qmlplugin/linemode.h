/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_LINEMODE_H
#define KPUBLICTRANSPORT_LinEMODE_H

#include <KPublicTransport/Line>

namespace KPublicTransport {

/** QML API for static methods in Line. */
class LineMode
{
    Q_GADGET
public:
    Q_INVOKABLE [[nodiscard]] static QString iconName(KPublicTransport::Line::Mode mode);
};

}

#endif

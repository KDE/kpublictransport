/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "linemode.h"

using namespace KPublicTransport;

QString LineMode::iconName(Line::Mode mode)
{
    return Line::modeIconName(mode);
}

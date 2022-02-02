/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kpublictransportquickplugin.h"
#include "styledframesvgitem.h"

using namespace KPublicTransport;

void KPublicTransportQuickPlugin::registerTypes(const char* uri)
{
    qmlRegisterType<StyledFrameSvgItem>(uri, 1, 0, "StyledFrameSvgItem");
}

#include "kpublictransportquickplugin.moc"

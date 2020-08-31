/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kpublictransportquickplugin.h"
#include "styledsvgimageprovider.h"

using namespace KPublicTransport;

class Dummy {
    Q_GADGET
};

void KPublicTransportQuickPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    Q_UNUSED(uri);
    engine->addImageProvider(QStringLiteral("org.kde.kpublictransport.styledsvg"), new StyledSvgImageProvider);
}

void KPublicTransportQuickPlugin::registerTypes(const char* uri)
{
    Q_UNUSED(uri);
    // we need to register at least one thing with our module name, otherwise the QML engine chokes on this plugin
    // we however only want to inject our image provider here...
    qmlRegisterUncreatableType<Dummy>("org.kde.kpublictransport.ui", 1, 0, "DummyType", {});
}

#include "kpublictransportquickplugin.moc"

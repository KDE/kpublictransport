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

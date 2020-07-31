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

#include "kosmindoormapquickplugin.h"
#include "mapitem.h"
#include "osmaddress.h"
#include "osmelement.h"
#include "osmelementinformationmodel.h"

#include <KOSMIndoorMap/GateModel>
#include <KOSMIndoorMap/PlatformModel>

using namespace KOSMIndoorMap;

void KOSMIndoorMapQuickPlugin::registerTypes(const char *uri)
{
    Q_UNUSED(uri);
    qRegisterMetaType<OSMAddress>();
    qRegisterMetaType<OSMElement>();
    qRegisterMetaType<const MapData*>();
    qRegisterMetaType<Platform::Mode>();

    qmlRegisterUncreatableType<OSMAddress>("org.kde.kosmindoormap", 1, 0, "OSMAddress", {});
    qmlRegisterUncreatableType<OSMElement>("org.kde.kosmindoormap", 1, 0, "OSMElement", {});
    qmlRegisterUncreatableType<Platform>("org.kde.kosmindoormap", 1, 0, "Platform", {});

    qmlRegisterType<MapItem>("org.kde.kosmindoormap", 1, 0, "MapItemImpl");
    qmlRegisterType<OSMElementInformationModel>("org.kde.kosmindoormap", 1, 0, "OSMElementInformationModel");
    qmlRegisterType<GateModel>("org.kde.kosmindoormap", 1, 0, "GateModel");
    qmlRegisterType<PlatformModel>("org.kde.kosmindoormap", 1, 0, "PlatformModel");
}

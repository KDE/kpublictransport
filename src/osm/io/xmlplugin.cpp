/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "../ioplugin.h"
#include "../xmlparser.h"
#include "../xmlwriter.h"

class OSM_XmlIOPlugin : public QObject, public OSM::IOPlugin<OSM::XmlParser, OSM::XmlWriter>
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID OSMIOPluginInteraface_iid FILE "xmlplugin.json")
    Q_INTERFACES(OSM::IOPluginInterface)
};

#include "xmlplugin.moc"

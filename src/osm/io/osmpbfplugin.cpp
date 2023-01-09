/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#define QT_STATICPLUGIN 1

#include "../ioplugin.h"
#include "../osmpbfparser.h"

class OSM_PbfIOPlugin : public QObject, public OSM::IOPlugin<OSM::OsmPbfParser>
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID OSMIOPluginInteraface_iid FILE "osmpbfplugin.json")
    Q_INTERFACES(OSM::IOPluginInterface)
};

#include "osmpbfplugin.moc"

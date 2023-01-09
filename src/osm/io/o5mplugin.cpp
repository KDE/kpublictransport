/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#define QT_STATICPLUGIN 1

#include "../ioplugin.h"
#include "../o5mparser.h"

class OSM_O5mIOPlugin : public QObject, public OSM::IOPlugin<OSM::O5mParser>
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID OSMIOPluginInteraface_iid FILE "o5mplugin.json")
    Q_INTERFACES(OSM::IOPluginInterface)
};

#include "o5mplugin.moc"

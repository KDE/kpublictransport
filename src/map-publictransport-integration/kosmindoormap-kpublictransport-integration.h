/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAP_KPUBLICTRANSPORT_PLUGIN_H
#define KOSMINDOORMAP_KPUBLICTRANSPORT_PLUGIN_H

#include <QQmlExtensionPlugin>

/** Plugin for KPublicTransport <-> KOSMIndoorMap integration. */
class KOSMIndoorMapQuickPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri) override;
};

#endif // KOSMINDOORMAP_KPUBLICTRANSPORT_PLUGIN_H

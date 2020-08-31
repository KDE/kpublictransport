/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KOSMINDOORMAPQUICKPLUGIN_H
#define KOSMINDOORMAPQUICKPLUGIN_H

#include <QQmlExtensionPlugin>

/** Qt Quick integration plugin for KOSMIndoorMap. */
class KOSMIndoorMapQuickPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri) override;
};

#endif // KOSMINDOORMAPQUICKPLUGIN_H

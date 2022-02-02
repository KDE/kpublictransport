/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORTQUICKPLUGIN_H
#define KPUBLICTRANSPORTQUICKPLUGIN_H

#include <QQmlExtensionPlugin>

/** QML plugin for KPublicTransport UI elements. */
class KPublicTransportQuickPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
public:
    void registerTypes(const char *uri) override;
};

#endif // KPUBLICTRANSPORTQUICKPLUGIN_H

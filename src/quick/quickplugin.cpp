/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "maputils.h"

#include <QQmlEngine>
#include <QQmlExtensionPlugin>

#include "localizer_p.h"

class KPublicTransportUiQuickPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

    void registerTypes(const char* uri) override;
};


void KPublicTransportUiQuickPlugin::registerTypes(const char*)
{
    qmlRegisterSingletonType("org.kde.kpublictransport.ui", 1, 0, "Localizer", [](QQmlEngine *, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(Localizer());
    });

    qmlRegisterSingletonType("org.kde.kpublictransport.ui", 1, 0, "MapUtils", [](QQmlEngine *qmlEngine, QJSEngine *engine) -> QJSValue {
        KPublicTransport::MapUtils v;
        v.m_engine = qmlEngine;
        return engine->toScriptValue(v);
    });
}

#include "quickplugin.moc"

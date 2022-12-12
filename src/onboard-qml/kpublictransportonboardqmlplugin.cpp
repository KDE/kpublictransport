/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include <KPublicTransport/OnboardStatus>

#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlExtensionPlugin>

class KPublicTransportOnboardQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")
    void registerTypes(const char* uri) override;
};

void KPublicTransportOnboardQmlPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<KPublicTransport::OnboardStatus>(uri, 1, 0, "OnboardStatus");
}

#include "kpublictransportonboardqmlplugin.moc"

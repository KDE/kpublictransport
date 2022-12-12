# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

ecm_add_qml_module(kpublictransportonboardqmlplugin URI "org.kde.kpublictransport.onboard" VERSION 1.0)

target_sources(kpublictransportonboardqmlplugin PRIVATE kpublictransportonboardqmlplugin.cpp)
target_link_libraries(kpublictransportonboardqmlplugin PRIVATE Qt::Qml KPublicTransportOnboard)

ecm_finalize_qml_module(kpublictransportonboardqmlplugin DESTINATION ${KDE_INSTALL_QMLDIR})

# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

ecm_add_qml_module(kpublictransportqmlplugin URI "org.kde.kpublictransport" VERSION 1.0 DEPENDENCIES "QtCore" "QtQml")

target_sources(kpublictransportqmlplugin PRIVATE
    kpublictransportqmlplugin.cpp
    linemetadatawrapper.cpp
)
target_link_libraries(kpublictransportqmlplugin PRIVATE Qt::Quick KPublicTransport)

ecm_finalize_qml_module(kpublictransportqmlplugin DESTINATION ${KDE_INSTALL_QMLDIR})

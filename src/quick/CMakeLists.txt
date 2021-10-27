# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

ecm_add_qml_module(kpublictransportquickplugin URI "org.kde.kpublictransport.ui" VERSION 1.0)

target_sources(kpublictransportquickplugin PRIVATE
    kpublictransportquickplugin.cpp
    styledframesvgitem.cpp
    kpublictransportquickplugin.h
    assets/assets.qrc
)

ecm_target_qml_sources(kpublictransportquickplugin SOURCES VehicleSectionItem.qml VERSION 1.0)

target_link_libraries(kpublictransportquickplugin PRIVATE Qt::Quick)

ecm_finalize_qml_module(kpublictransportquickplugin DESTINATION ${KDE_INSTALL_QMLDIR})

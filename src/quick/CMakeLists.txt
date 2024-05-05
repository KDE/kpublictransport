# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

ecm_add_qml_module(kpublictransportquickplugin
    URI "org.kde.kpublictransport.ui"
    VERSION 1.0
    GENERATE_PLUGIN_SOURCE
    IMPORTS "org.kde.kpublictransport"
    DEPENDENCIES "QtQuick" "QtQuick.Controls" "org.kde.kirigami"
)

target_sources(kpublictransportquickplugin PRIVATE
    styledframesvgitem.cpp
    assets/assets.qrc
)

ecm_target_qml_sources(kpublictransportquickplugin SOURCES
    FeatureIcon.qml
    OccupancyIndicator.qml
    VehicleSectionItem.qml
)

target_link_libraries(kpublictransportquickplugin PRIVATE Qt::Quick)

ecm_finalize_qml_module(kpublictransportquickplugin DESTINATION ${KDE_INSTALL_QMLDIR})

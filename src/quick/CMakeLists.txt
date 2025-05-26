# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

ecm_add_qml_module(kpublictransportquickplugin
    URI "org.kde.kpublictransport.ui"
    VERSION 1.0
    NO_GENERATE_PLUGIN_SOURCE
    CLASS_NAME "KPublicTransportUiQuickPlugin"
    IMPORTS "org.kde.kpublictransport"
    DEPENDENCIES
        "QtQuick"
        "QtQuick.Controls"
        "org.kde.kirigami"
        "org.kde.kirigamiaddons.delegates"
        "org.kde.i18n.localeData"
        "org.kde.kitemmodels"
)

target_sources(kpublictransportquickplugin PRIVATE
    maputils.cpp
    quickplugin.cpp
    styledframesvgitem.cpp
    assets/assets.qrc
)

ecm_target_qml_sources(kpublictransportquickplugin SOURCES
    BackendPage.qml
    ExpectedTimeLabel.qml
    FeatureDelegate.qml
    FeatureIcon.qml
    JourneyHorizontalBar.qml
    OccupancyIndicator.qml
    StopPickerPage.qml
    TransportIcon.qml
    TransportNameControl.qml
    VehicleLayoutView.qml
    VehicleSectionDelegate.qml
    VehicleSectionItem.qml
)

ecm_target_qml_sources(kpublictransportquickplugin
    PRIVATE
    PATH private
    SOURCES
        private/CountryComboBox.qml
)

target_link_libraries(kpublictransportquickplugin
    PRIVATE
        KPublicTransport
        Qt::Quick
        KF6::I18nLocaleData
)

ecm_finalize_qml_module(kpublictransportquickplugin DESTINATION ${KDE_INSTALL_QMLDIR})

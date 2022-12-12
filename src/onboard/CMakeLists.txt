# SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

if (TARGET KF5::NetworkManagerQt)
    set(HAVE_NM TRUE)
endif()

add_library(KPublicTransportOnboard)
target_sources(KPublicTransportOnboard PRIVATE
    onboardstatus.cpp
    onboardstatusmanager.cpp
    positiondata.cpp
    wifimonitor.cpp

    backend/abstractonboardbackend.cpp
    backend/restonboardbackend.cpp
    backend/scriptedrestonboardbackend.cpp

    data/data.qrc
)

if (ANDROID)
    target_sources(KPublicTransportOnboard PRIVATE wifimonitor_android.cpp)
    add_subdirectory(android)
elseif (HAVE_NM)
    target_sources(KPublicTransportOnboard PRIVATE wifimonitor_nm.cpp)
else()
    message("WARNING: No Wifi monitoring implementation available on this platform!")
    target_sources(KPublicTransportOnboard PRIVATE wifimonitor_dummy.cpp)
endif()

ecm_qt_declare_logging_category(KPublicTransportOnboard
    HEADER logging.h
    IDENTIFIER KPublicTransport::Log
    CATEGORY_NAME org.kde.kpublictransport.onboard
    DESCRIPTION "KPublicTransport Onboard API"
    EXPORT KPUBLICTRANSPORTONBOARD
)

generate_export_header(KPublicTransportOnboard BASE_NAME KPublicTransportOnboard)
set_target_properties(KPublicTransportOnboard PROPERTIES
    VERSION ${KPUBLICTRANSPORT_VERSION}
    SOVERSION ${KPUBLICTRANSPORT_SOVERSION}
)
target_include_directories(KPublicTransportOnboard PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")
target_include_directories(KPublicTransportOnboard INTERFACE "$<INSTALL_INTERFACE:${KPUBLICTRANSPORT_INSTALL_INCLUDEDIR}>")
target_link_libraries(KPublicTransportOnboard
    PUBLIC
        KPublicTransport
    PRIVATE
        Qt::Network
        Qt::Qml
)
if (HAVE_NM)
    target_link_libraries(KPublicTransportOnboard PRIVATE KF5::NetworkManagerQt)
endif()
if (ANDROID AND QT_MAJOR_VERSION EQUAL "5")
    target_link_libraries(KPublicTransportOnboard PRIVATE Qt5::AndroidExtras)
endif()

ecm_generate_headers(KPublicTransportOnboard_FORWARDING_HEADERS
    HEADER_NAMES
        OnboardStatus
    PREFIX KPublicTransport
    REQUIRED_HEADERS KPublicTransportOnbard_HEADERS
)
install(TARGETS KPublicTransportOnboard EXPORT KPublicTransportTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
ecm_qt_install_logging_categories(
    EXPORT KPUBLICTRANSPORTONBOARD
    FILE org_kde_kpublictransport_onboard.categories
    DESTINATION ${KDE_INSTALL_LOGGINGCATEGORIESDIR}
)
install(FILES
    ${KPublicTransportOnboard_FORWARDING_HEADERS}
    DESTINATION ${KPUBLICTRANSPORT_INSTALL_INCLUDEDIR}/KPublicTransport
)
install(FILES
    ${KPublicTransportOnboard_HEADERS}
    ${CMAKE_CURRENT_BINARY_DIR}/kpublictransportonboard_export.h
    DESTINATION ${KPUBLICTRANSPORT_INSTALL_INCLUDEDIR}/kpublictransport
)

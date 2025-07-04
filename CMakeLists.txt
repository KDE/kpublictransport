# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)

# KDE Application Version, managed by release script
set (RELEASE_SERVICE_VERSION_MAJOR "25")
set (RELEASE_SERVICE_VERSION_MINOR "11")
set (RELEASE_SERVICE_VERSION_MICRO "70")
set (RELEASE_SERVICE_VERSION "${RELEASE_SERVICE_VERSION_MAJOR}.${RELEASE_SERVICE_VERSION_MINOR}.${RELEASE_SERVICE_VERSION_MICRO}")
project(KPublicTransport VERSION ${RELEASE_SERVICE_VERSION})

find_package(ECM 6.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${ECM_MODULE_PATH})

include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMAddTests)
include(ECMGenerateHeaders)
include(ECMQtDeclareLoggingCategory)
include(ECMDeprecationSettings)
include(ECMSetupVersion)
include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(GenerateExportHeader)
include(ECMAddQch)
include(ECMQmlModule)
include(ECMFindQmlModule)

set(CMAKE_CXX_STANDARD 23)

option(BUILD_QCH "Build API documentation in QCH format (for e.g. Qt Assistant, Qt Creator & KDevelop)" OFF)
add_feature_info(QCH ${BUILD_QCH} "API documentation in QCH format (for e.g. Qt Assistant, Qt Creator & KDevelop)")

ecm_setup_version(PROJECT VARIABLE_PREFIX KPUBLICTRANSPORT
    VERSION_HEADER kpublictransport_version.h
    PACKAGE_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/KPublicTransportConfigVersion.cmake"
    SOVERSION 1
)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

if (BUILD_TESTING)
    find_package(Qt6 6.5 REQUIRED COMPONENTS Test Widgets)
endif()

find_package(ZLIB REQUIRED)
find_package(OsmTools)
set_package_properties(OsmTools PROPERTIES TYPE OPTIONAL PURPOSE "Needed only for regenereating line metadata tables (you don't need this for distribution)")
if (NOT CMAKE_CROSSCOMPILING)
    find_package(PolyClipping)
    set_package_properties(PolyClipping PROPERTIES TYPE OPTIONAL PURPOSE "Needed only for processing coverage area data from the Transport API Repository (you don't need this for distribution)")
endif()

if (NOT WIN32)
    find_package(Protobuf)
    set_package_properties(Protobuf PROPERTIES TYPE OPTIONAL PURPOSE "Parsing of OSM PBF files.")
endif()

if (UNIX AND NOT ANDROID)
    find_package(KF6NetworkManagerQt)
    set_package_properties(KF6NetworkManagerQt PROPERTIES TYPE OPTIONAL PURPOSE "Onboard status detection.")
endif()
if (ANDROID)
    find_package(Gradle)
endif()

find_package(KF6 6.11 REQUIRED COMPONENTS I18n)
find_package(KF6KirigamiAddons 1.6.0 REQUIRED)

set(KPUBLICTRANSPORT_INSTALL_INCLUDEDIR ${KDE_INSTALL_INCLUDEDIR}/KPublicTransport)

ecm_set_disabled_deprecation_versions(QT 6.7 KF 6.11.0)

add_subdirectory(src)

if (BUILD_TESTING)
    add_subdirectory(autotests)
    add_subdirectory(tests)
endif()


ecm_find_qmlmodule(org.kde.kitemmodels ${KF_MIN_VERSION})

set(CMAKECONFIG_INSTALL_DIR "${KDE_INSTALL_CMAKEPACKAGEDIR}/KPublicTransport")

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/kpublictransport_version.h DESTINATION ${KPUBLICTRANSPORT_INSTALL_INCLUDEDIR} COMPONENT Devel)

install(EXPORT KPublicTransportTargets DESTINATION "${CMAKECONFIG_INSTALL_DIR}" FILE KPublicTransportTargets.cmake)

if (BUILD_QCH)
    ecm_install_qch_export(
        TARGETS KPublicTransport_QCH
        FILE KPublicTransportQchTargets.cmake
        DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
        COMPONENT Devel
    )
    set(PACKAGE_INCLUDE_QCHTARGETS "include(\"\${CMAKE_CURRENT_LIST_DIR}/KPublicTransportQchTargets.cmake\")")
endif()

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/KPublicTransportConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/KPublicTransportConfig.cmake"
    INSTALL_DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
)

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/KPublicTransportConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/KPublicTransportConfigVersion.cmake"
    DESTINATION "${CMAKECONFIG_INSTALL_DIR}"
    COMPONENT Devel
)
ki18n_install(po)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)

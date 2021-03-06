# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)

# KDE Application Version, managed by release script
set (RELEASE_SERVICE_VERSION_MAJOR "21")
set (RELEASE_SERVICE_VERSION_MINOR "11")
set (RELEASE_SERVICE_VERSION_MICRO "70")
set (RELEASE_SERVICE_VERSION "${RELEASE_SERVICE_VERSION_MAJOR}.${RELEASE_SERVICE_VERSION_MINOR}.${RELEASE_SERVICE_VERSION_MICRO}")
project(KPublicTransport VERSION ${RELEASE_SERVICE_VERSION})

find_package(ECM 5.59 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR})

include(KDEFrameworkCompilerSettings NO_POLICY_SCOPE)
include(ECMAddTests)
include(ECMGenerateHeaders)
include(ECMQtDeclareLoggingCategory)
include(ECMSetupVersion)
include(FeatureSummary)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(GenerateExportHeader)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
ecm_setup_version(PROJECT VARIABLE_PREFIX KPUBLICTRANSPORT
    VERSION_HEADER kpublictransport_version.h
    PACKAGE_VERSION_FILE "${CMAKE_CURRENT_BINARY_DIR}/KPublicTransportConfigVersion.cmake"
    SOVERSION 1
)

find_package(Qt5 5.15 REQUIRED COMPONENTS Quick)

if (BUILD_TESTING)
    find_package(Qt5 5.15 REQUIRED COMPONENTS Test Widgets)
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

add_definitions(-DQT_DISABLE_DEPRECATED_BEFORE=0x050f00)
add_definitions(-DKF_DISABLE_DEPRECATED_BEFORE_AND_AT=0x055100)
add_definitions(-DQT_NO_FOREACH)
add_subdirectory(src)

if (BUILD_TESTING)
    add_subdirectory(autotests)
    add_subdirectory(tests)
endif()

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

set(CMAKECONFIG_INSTALL_DIR "${CMAKECONFIG_INSTALL_PREFIX}/KPublicTransport")
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
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/kpublictransport_version.h DESTINATION ${KDE_INSTALL_INCLUDEDIR} COMPONENT Devel)

install(EXPORT KPublicTransportTargets DESTINATION "${CMAKECONFIG_INSTALL_DIR}" FILE KPublicTransportTargets.cmake)

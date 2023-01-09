# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_library(KOSM STATIC
    abstractreader.cpp
    abstractwriter.cpp
    datatypes.cpp
    datasetmergebuffer.cpp
    element.cpp
    geomath.cpp
    io.cpp
    o5mparser.cpp
    overpassquery.cpp
    overpassquerymanager.cpp
    pathutil.cpp
    ztile.cpp

    io/o5mplugin.cpp
)
generate_export_header(KOSM BASE_NAME KOSM)
set_target_properties(KOSM PROPERTIES
    VERSION ${KOSMINDOORMAP_VERSION}
    SOVERSION ${KOSMINDOORMAP_SOVERSION}
    EXPORT_NAME KOSM
)

target_include_directories(KOSM PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
target_compile_definitions(KOSM PUBLIC "-DKOSM_STATIC_DEFINE=1")
target_link_libraries(KOSM PUBLIC Qt::Core PRIVATE Qt::Network)
set_target_properties(KOSM PROPERTIES POSITION_INDEPENDENT_CODE ON)

if (NOT BUILD_SHARED_LIBS)
    install(TARGETS KOSM EXPORT KPublicTransportTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
endif()

add_subdirectory(io)

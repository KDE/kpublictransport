# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

if (Protobuf_FOUND AND Protobuf_PROTOC_EXECUTABLE)
    set(HAVE_PROTOBUF TRUE)
    PROTOBUF_GENERATE_CPP(pbf_srcs pbf_hdrs
        pbf/fileformat.proto
        pbf/osmformat.proto
    )
    set(EXTRA_LIBS ${Protobuf_LIBRARIES} ZLIB::ZLIB)
    set_source_files_properties(${pbf_srcs} ${pbf_hdrs} PROPERTIES SKIP_AUTOMOC ON)
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config-kosm.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config-kosm.h)

add_library(KOSM STATIC
    datatypes.cpp
    datasetmergebuffer.cpp
    element.cpp
    geomath.cpp
    o5mparser.cpp
    osmpbfparser.cpp
    overpassquery.cpp
    overpassquerymanager.cpp
    pathutil.cpp
    xmlparser.cpp
    xmlwriter.cpp
    ztile.cpp
    ${pbf_srcs}
)

target_include_directories(KOSM PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
target_include_directories(KOSM PRIVATE ${Protobuf_INCLUDE_DIRS})
target_link_libraries(KOSM PUBLIC Qt::Core PRIVATE Qt::Network ${EXTRA_LIBS})

if (NOT BUILD_SHARED_LIBS)
    install(TARGETS KOSM EXPORT KPublicTransportTargets ${INSTALL_TARGETS_DEFAULT_ARGS})
endif()

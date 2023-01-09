# SPDX-FileCopyrightText: 2020-2022 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-2-Clause

if (Protobuf_FOUND AND Protobuf_PROTOC_EXECUTABLE)
    PROTOBUF_GENERATE_CPP(pbf_srcs pbf_hdrs
        ../pbf/fileformat.proto
        ../pbf/osmformat.proto
    )
    set_source_files_properties(${pbf_srcs} ${pbf_hdrs} PROPERTIES SKIP_AUTOMOC ON)

    add_library(KOSM_pbfioplugin STATIC)
    target_sources(KOSM_pbfioplugin PRIVATE
        ${pbf_srcs}
        osmpbfplugin.cpp
        ../osmpbfparser.cpp
    )
    target_include_directories(KOSM_pbfioplugin PRIVATE ${Protobuf_INCLUDE_DIRS})
    target_compile_definitions(KOSM_pbfioplugin PRIVATE -DQT_STATICPLUGIN=1)
    set_target_properties(KOSM_pbfioplugin PROPERTIES POSITION_INDEPENDENT_CODE ON)
    target_link_libraries(KOSM_pbfioplugin
        PUBLIC KOSM
        PRIVATE ${Protobuf_LIBRARIES} ZLIB::ZLIB
    )
endif()

add_library(KOSM_xmlioplugin STATIC)
target_sources(KOSM_xmlioplugin PRIVATE
    xmlplugin.cpp
    ../xmlparser.cpp
    ../xmlwriter.cpp
)
set_target_properties(KOSM_xmlioplugin PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_compile_definitions(KOSM_xmlioplugin PRIVATE -DQT_STATICPLUGIN=1)
target_link_libraries(KOSM_xmlioplugin PUBLIC KOSM)

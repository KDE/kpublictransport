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

    # workaroud for https://github.com/protocolbuffers/protobuf/issues/10108
    if (Protobuf_VERSION VERSION_LESS 3.22)
        target_compile_definitions(KOSM_pbfioplugin PRIVATE -DGOOGLE_PROTOBUF_INTERNAL_DONATE_STEAL_INLINE=0)
    endif()
    # workaround for a similar still unresolved issue with using undefined defines...
    target_compile_definitions(KOSM_pbfioplugin PRIVATE -DPROTOBUF_ENABLE_DEBUG_LOGGING_MAY_LEAK_PII=0)
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

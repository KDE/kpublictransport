if (Protobuf_FOUND)
    set(HAVE_PROTOBUF TRUE)
    PROTOBUF_GENERATE_CPP(pbf_srcs pbf_hdrs
        pbf/fileformat.proto
        pbf/osmformat.proto
    )
    set(EXTRA_LIBS ${Protobuf_LIBRARIES} ZLIB::ZLIB)
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
    xmlparser.cpp
    ztile.cpp
    ${pbf_srcs}
)

target_include_directories(KOSM PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
target_include_directories(KOSM PRIVATE ${Protobuf_INCLUDE_DIRS})
target_link_libraries(KOSM PUBLIC Qt5::Core PRIVATE Qt5::Network ${EXTRA_LIBS})

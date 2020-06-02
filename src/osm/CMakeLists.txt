add_library(KOSM STATIC
    datatypes.cpp
    datasetmergebuffer.cpp
    element.cpp
    geomath.cpp
    o5mparser.cpp
    overpassquery.cpp
    overpassquerymanager.cpp
    xmlparser.cpp
    ztile.cpp
)

target_include_directories(KOSM PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
target_link_libraries(KOSM PUBLIC Qt5::Core PRIVATE Qt5::Network)

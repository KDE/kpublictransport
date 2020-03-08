add_library(KOSM STATIC
    datatypes.cpp
    overpassquery.cpp
    overpassquerymanager.cpp
    xmlparser.cpp
)

target_link_libraries(KOSM PUBLIC Qt5::Core PRIVATE Qt5::Network)

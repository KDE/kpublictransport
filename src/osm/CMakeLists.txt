add_library(KOSM STATIC
    overpassquery.cpp
    overpassquerymanager.cpp
)

target_link_libraries(KOSM PUBLIC Qt5::Core PRIVATE Qt5::Network)

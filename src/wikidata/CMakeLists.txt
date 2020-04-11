add_library(KWikidata STATIC
    entities.cpp
    wikidataquerymanager.cpp
    wikidataquery.cpp
)

target_include_directories(KOSM PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>")
target_link_libraries(KWikidata
    PUBLIC Qt5::Gui
    PRIVATE Qt5::Network
)

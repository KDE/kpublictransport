add_library(KWikidata STATIC
    wikidataquerymanager.cpp
    wikidataquery.cpp
)
target_link_libraries(KWikidata
    PUBLIC Qt5::Core
    PRIVATE Qt5::Network
)

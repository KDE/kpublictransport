add_executable(line-data-generator
    generator.cpp
    indexeddatatable.cpp
    lineinfo.cpp
)
target_link_libraries(line-data-generator KOSM KWikidata Qt5::Gui)

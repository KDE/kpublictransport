add_executable(line-data-generator
    generator.cpp
    generator.qrc
)
target_link_libraries(line-data-generator KOSM Qt5::Gui)

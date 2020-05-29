set(kosmindoormapquickplugin_SRC
    kosmindoormapquickplugin.cpp
    mapitem.cpp
)
set(kosmindoormapquickplugin_qml
    qmldir
    IndoorMap.qml
)

add_library(kosmindoormapquickplugin ${kosmindoormapquickplugin_SRC})
target_link_libraries(kosmindoormapquickplugin
    Qt5::Quick
    KOSMIndoorMap
)

# make examples work without installation
set_property(TARGET kosmindoormapquickplugin PROPERTY LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kosmindoormap)
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kosmindoormap/)
foreach(f IN LISTS kosmindoormapquickplugin_qml)
    file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/${f} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kosmindoormap/${f} SYMBOLIC)
endforeach()

# install(TARGETS kosmindoormapquickplugin DESTINATION ${QML_INSTALL_DIR}/org/kde/kosmindoormap)
# install(FILES ${kosmindoormapquickplugin_qml} ${quick_SRC} DESTINATION ${QML_INSTALL_DIR}/org/kde/kosmindoormap)

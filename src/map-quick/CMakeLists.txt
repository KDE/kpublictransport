add_library(KOSMIndoorMapQuick STATIC
    floorlevelmodel.cpp
    mapitem.cpp
    osmaddress.cpp
    osmelement.cpp
    osmelementinformationmodel.cpp
)
target_link_libraries(KOSMIndoorMapQuick PUBLIC
    Qt5::Quick
    KOSMIndoorMap
)

set(kosmindoormapquickplugin_qml
    qmldir
    IndoorMap.qml
    IndoorMapAttributionLabel.qml
    IndoorMapScale.qml
)

add_library(kosmindoormapquickplugin kosmindoormapquickplugin.cpp)
target_link_libraries(kosmindoormapquickplugin
    KOSMIndoorMapQuick
)

# make examples work without installation
if (NOT CMAKE_VERSION VERSION_LESS 3.14)
    set_property(TARGET kosmindoormapquickplugin PROPERTY LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kosmindoormap)
    file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kosmindoormap/)
    foreach(f IN LISTS kosmindoormapquickplugin_qml)
        file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/${f} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kosmindoormap/${f} SYMBOLIC)
    endforeach()
else()
    message(WARNING "CMake is too old, cannot setup examples to work without installation")
endif()

install(TARGETS kosmindoormapquickplugin DESTINATION ${QML_INSTALL_DIR}/org/kde/kosmindoormap)
install(FILES ${kosmindoormapquickplugin_qml} ${quick_SRC} DESTINATION ${QML_INSTALL_DIR}/org/kde/kosmindoormap)

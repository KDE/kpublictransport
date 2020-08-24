set(kosmindoormap_kpublictransport_integration_qml
    qmldir
)

add_library(kosmindoormap_kpublictransport_integration_plugin
    kosmindoormap-kpublictransport-integration.cpp
    locationqueryoverlayproxymodel.cpp
)
target_link_libraries(kosmindoormap_kpublictransport_integration_plugin
    Qt5::Qml
    KOSMIndoorMap
    KPublicTransport
)

# make examples work without installation
if (NOT CMAKE_VERSION VERSION_LESS 3.14)
    set_property(TARGET kosmindoormap_kpublictransport_integration_plugin PROPERTY LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kosmindoormap/kpublictransport)
    file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kosmindoormap/kpublictransport/)
    foreach(f IN LISTS kosmindoormap_kpublictransport_integration_qml)
        file(CREATE_LINK ${CMAKE_CURRENT_SOURCE_DIR}/${f} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kosmindoormap/kpublictransport/${f} SYMBOLIC)
    endforeach()
else()
    message(WARNING "CMake is too old, cannot setup examples to work without installation")
endif()

install(TARGETS kosmindoormap_kpublictransport_integration_plugin DESTINATION ${QML_INSTALL_DIR}/org/kde/kosmindoormap/kpublictransport)
install(FILES ${kosmindoormap_kpublictransport_integration_qml} DESTINATION ${QML_INSTALL_DIR}/org/kde/kosmindoormap/kpublictransport)


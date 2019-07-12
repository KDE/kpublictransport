set(kpublictransportqmlplugin_SRC
    kpublictransportqmlplugin.cpp
)

add_library(kpublictransportqmlplugin ${kpublictransportqmlplugin_SRC})
target_link_libraries(kpublictransportqmlplugin
    Qt5::Qml
    KPublicTransport
)
install(TARGETS kpublictransportqmlplugin DESTINATION ${QML_INSTALL_DIR}/org/kde/kpublictransport)
install(FILES qmldir ${qml_SRC} DESTINATION ${QML_INSTALL_DIR}/org/kde/kpublictransport)


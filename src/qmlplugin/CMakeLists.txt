# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_library(kpublictransportqmlplugin)
target_sources(kpublictransportqmlplugin PRIVATE
    kpublictransportqmlplugin.cpp
    linemetadatawrapper.cpp
)

if(NOT BUILD_SHARED_LIBS)
    target_compile_definitions(kpublictransportqmlplugin PRIVATE -DQT_PLUGIN -DQT_STATICPLUGIN=1)
    set_target_properties(kpublictransportqmlplugin PROPERTIES AUTOMOC_MOC_OPTIONS -Muri=org.kde.kpublictransport)
    target_sources(kpublictransportqmlplugin PRIVATE kpublictransportqml.qrc)
endif()

target_link_libraries(kpublictransportqmlplugin
    Qt5::Qml
    KPublicTransport
)

# make examples work without installation
set_property(TARGET kpublictransportqmlplugin PROPERTY LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kpublictransport)
file(COPY qmldir DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kpublictransport)

install(TARGETS kpublictransportqmlplugin DESTINATION ${QML_INSTALL_DIR}/org/kde/kpublictransport)
install(FILES qmldir ${qml_SRC} DESTINATION ${QML_INSTALL_DIR}/org/kde/kpublictransport)


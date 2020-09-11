# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

set(kpublictransportqmlplugin_SRC
    kpublictransportqmlplugin.cpp
    linemetadatawrapper.cpp
)

add_library(kpublictransportqmlplugin ${kpublictransportqmlplugin_SRC})
target_link_libraries(kpublictransportqmlplugin
    Qt5::Qml
    KPublicTransport
)

# make examples work without installation
set_property(TARGET kpublictransportqmlplugin PROPERTY LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kpublictransport)
file(COPY qmldir DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kpublictransport)

install(TARGETS kpublictransportqmlplugin DESTINATION ${QML_INSTALL_DIR}/org/kde/kpublictransport)
install(FILES qmldir ${qml_SRC} DESTINATION ${QML_INSTALL_DIR}/org/kde/kpublictransport)


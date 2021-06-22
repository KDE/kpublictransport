# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_library(kpublictransportquickplugin)
target_sources(kpublictransportquickplugin PRIVATE
    kpublictransportquickplugin.cpp
    styledsvgimageprovider.cpp
    assets/assets.qrc
)
set(kpublictransportquickplugin_qml
    qmldir
    VehicleSectionItem.qml
)

target_link_libraries(kpublictransportquickplugin
    Qt5::Quick
)

# make examples work without installation
set_property(TARGET kpublictransportquickplugin PROPERTY LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kpublictransport/ui)
file(COPY ${kpublictransportquickplugin_qml} DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/org/kde/kpublictransport/ui)

install(TARGETS kpublictransportquickplugin DESTINATION ${QML_INSTALL_DIR}/org/kde/kpublictransport/ui)
install(FILES ${kpublictransportquickplugin_qml} ${quick_SRC} DESTINATION ${QML_INSTALL_DIR}/org/kde/kpublictransport/ui)

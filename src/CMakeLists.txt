# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_definitions(-DTRANSLATION_DOMAIN=\"kpublictransport\")

add_subdirectory(graphql)
add_subdirectory(osm)
add_subdirectory(wikidata)
if (NOT CMAKE_CROSSCOMPILING)
    add_subdirectory(generator)
endif()
add_subdirectory(lib)
add_subdirectory(qmlplugin)
if (TARGET Qt::Quick)
    add_subdirectory(quick)
endif()
if (NOT CMAKE_CROSSCOMPILING)
    add_subdirectory(tools)
endif()
add_subdirectory(onboard)
add_subdirectory(onboard-qml)

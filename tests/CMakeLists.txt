# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_executable(departurequery departurequery.cpp departurequery.qrc)
target_link_libraries(departurequery KPublicTransport Qt5::Quick Qt5::Widgets)

add_executable(journeyquery journeyquery.cpp journeyquery.qrc)
target_link_libraries(journeyquery KPublicTransport Qt5::Quick Qt5::Widgets)

add_executable(locationquery locationquery.cpp locationquery.qrc)
target_link_libraries(locationquery KPublicTransport Qt5::Quick Qt5::Widgets)

add_executable(locationcompleter locationcompleter.cpp)
target_link_libraries(locationcompleter KPublicTransport Qt5::Widgets)

add_executable(gbfsdiscover gbfsdiscover.cpp)
target_link_libraries(gbfsdiscover KPublicTransport Qt5::Network)

add_executable(graphql-cli graphql-cli.cpp)
target_link_libraries(graphql-cli KGraphQL)

add_executable(overpassql-cli overpassql-cli.cpp)
target_link_libraries(overpassql-cli KOSM)

if (TARGET KOSMIndoorMap)
    add_executable(indoormap indoormap.cpp ../src/map/assets/assets.qrc)
    target_compile_definitions(indoormap PRIVATE -DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
    target_link_libraries(indoormap KOSMIndoorMap Qt5::Widgets)
endif()

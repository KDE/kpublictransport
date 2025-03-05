# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_executable(querytest querytest.cpp)
target_link_libraries(querytest Qt::Test KPublicTransport)
add_custom_target(run-querytest COMMAND querytest)

add_executable(departurequery departurequery.cpp departurequery.qrc)
target_link_libraries(departurequery KPublicTransport Qt::Quick Qt::Widgets KF6::I18nQml)

add_executable(journeyquery journeyquery.cpp journeyquery.qrc)
target_link_libraries(journeyquery KPublicTransport Qt::Quick Qt::Widgets KF6::I18nQml)

add_executable(locationquery locationquery.cpp locationquery.qrc)
target_link_libraries(locationquery KPublicTransport Qt::Quick Qt::Widgets)

add_executable(locationcompleter locationcompleter.cpp)
target_link_libraries(locationcompleter KPublicTransport Qt::Widgets)

add_executable(gbfsdiscover gbfsdiscover.cpp)
target_link_libraries(gbfsdiscover KPublicTransport Qt::Network)

add_executable(graphql-cli graphql-cli.cpp)
target_link_libraries(graphql-cli KGraphQL)

add_executable(overpassql-cli overpassql-cli.cpp)
target_link_libraries(overpassql-cli KOSM)

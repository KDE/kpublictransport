# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

if (CMAKE_CROSSCOMPILING OR NOT OSM_PLANET_DIR OR NOT OsmTools_FOUND)
    return()
endif()

# Extract route_master and route relation of relevant transport modes from a full planet-osm data file.
# The output of this acts as input for the code generator for the line meta data tables.

# extract all route and route_master relations with types we are interested in
# this can take ~15min and produces about 100MB of output
osm_filter(OUTPUT routes.o5m FILTER --keep=\"route_master=train or route_master=subway or route_master=tram or route=train or route=subway or route=tram or route_master=light_rail\")

# augment bounding box information
osm_convert(INPUT routes.o5m OUTPUT routes-bbox.o5m ADD_BBOX ON)

# drop all depending nodes/ways/relations we wont need
# this is merely to speed up the code generator, by reducing the resulting XML output to manageable sizes
osm_filter(INPUT routes-bbox.o5m OUTPUT routes-only.o5m FILTER --keep=\"route_master=train or route_master=subway or route_master=tram or route=train or route=subway or route=tram or route_master=light_rail\" --ignore-dependencies)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/linemetadata_data.cpp
    COMMAND
        line-data-generator -o ${CMAKE_CURRENT_SOURCE_DIR}/linemetadata_data.cpp -i ${OSM_PLANET_DIR}/routes-only.o5m
    DEPENDS
        line-data-generator ${OSM_PLANET_DIR}/routes-only.o5m
)
add_custom_target(rebuild-knowledgedb DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/linemetadata_data.cpp)

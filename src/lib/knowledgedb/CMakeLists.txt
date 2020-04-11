if (CMAKE_CROSSCOMPILING OR NOT OSM_PLANET_DIR OR NOT OsmTools_FOUND)
    return()
endif()

# Extract route_master and route relation of relevant transport modes from a full planet-osm data file.
# The output of this acts as input for the code generator for the line meta data tables.

# reduce data set to a smaller area for testing, as x1,y1,x2,y2
set(BBOX "-180.0,-90.0,180.0,90.0")
# set(BBOX "-5.0,45.0,15.0,55.0")

# extract all route and route_master relations with types we are interested in
# this can take ~15min and produces about 100MB of output
add_custom_command(
    OUTPUT ${OSM_PLANET_DIR}/routes.o5m
    COMMAND OSM::filter ${OSM_PLANET_DIR}/planet-latest.o5m --keep=\"route_master=train or route_master=subway or route_master=tram or route=train or route=subway or route=tram\" --out-o5m -o=${OSM_PLANET_DIR}/routes.o5m
    WORKING_DIRECTORY ${OSM_PLANET_DIR}
    COMMENT "Extracting all route and route_master relations"
    DEPENDS ${OSM_PLANET_DIR}/planet-latest.o5m
)

# augment bounding box information
add_custom_command(
    OUTPUT ${OSM_PLANET_DIR}/routes-bbox.o5m
    COMMAND OSM::convert ${OSM_PLANET_DIR}/routes.o5m --out-o5m --add-bbox-tags -b=${BBOX} -o=${OSM_PLANET_DIR}/routes-bbox.o5m
    WORKING_DIRECTORY ${OSM_PLANET_DIR}
    COMMENT "Adding bounding boxes"
    DEPENDS ${OSM_PLANET_DIR}/routes.o5m
)

# drop all depending nodes/ways/relations we wont need
# this is merely to speed up the code generator, by reducing the resulting XML output to manageable sizes
add_custom_command(
    OUTPUT ${OSM_PLANET_DIR}/routes-only.o5m
    COMMAND OSM::filter ${OSM_PLANET_DIR}/routes-bbox.o5m --drop-nodes --drop-ways --keep=\"route_master=train or route_master=subway or route_master=tram or route=train or route=subway or route=tram\" --ignore-dependencies --out-o5m -o=${OSM_PLANET_DIR}/routes-only.o5m
    WORKING_DIRECTORY ${OSM_PLANET_DIR}
    COMMENT "Purging unnecessary elements"
    DEPENDS ${OSM_PLANET_DIR}/routes-bbox.o5m
)

# convert the output to OSM XML format, so the code generator can consume it
add_custom_command(
    OUTPUT ${OSM_PLANET_DIR}/routes-only.osm
    COMMAND OSM::convert ${OSM_PLANET_DIR}/routes-only.o5m --out-osm -o=${OSM_PLANET_DIR}/routes-only.osm
    WORKING_DIRECTORY ${OSM_PLANET_DIR}
    COMMENT "Converting to OSM XML format"
    DEPENDS ${OSM_PLANET_DIR}/routes-only.o5m
)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/linemetadata_data.cpp
    COMMAND
        line-data-generator -o ${CMAKE_CURRENT_SOURCE_DIR}/linemetadata_data.cpp -i ${OSM_PLANET_DIR}/routes-only.osm
    DEPENDS
        line-data-generator ${OSM_PLANET_DIR}/routes-only.osm
)
add_custom_target(rebuild-knowledgedb DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/linemetadata_data.cpp)

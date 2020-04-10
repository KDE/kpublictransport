# Copyright (c) 2018 Volker Krause <vkrause@kde.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


find_program(OSMCONVERT_EXECUTABLE osmconvert)
find_program(OSMFILTER_EXECUTABLE osmfilter)
find_program(OSMUPDATE_EXECUTABLE osmupdate)

find_program(WGET_EXECUTABLE wget) # needed by osmupdate
find_program(RSYNC_EXECUTABLE rsync) # needed for the initial download


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(OsmTools
    FOUND_VAR OsmTools_FOUND
    REQUIRED_VARS OSMCONVERT_EXECUTABLE OSMFILTER_EXECUTABLE OSMUPDATE_EXECUTABLE WGET_EXECUTABLE RSYNC_EXECUTABLE
)

if (OSMCONVERT_EXECUTABLE AND NOT TARGET OSM::convert)
    add_executable(OSM::convert IMPORTED)
    set_target_properties(OSM::convert PROPERTIES IMPORTED_LOCATION ${OSMCONVERT_EXECUTABLE})
endif()
if (OSMFILTER_EXECUTABLE AND NOT TARGET OSM::filter)
    add_executable(OSM::filter IMPORTED)
    set_target_properties(OSM::filter PROPERTIES IMPORTED_LOCATION ${OSMFILTER_EXECUTABLE})
endif()
if (OSMUPDATE_EXECUTABLE AND NOT TARGET OSM::update)
    add_executable(OSM::update IMPORTED)
    set_target_properties(OSM::update PROPERTIES IMPORTED_LOCATION ${OSMUPDATE_EXECUTABLE})
endif()

set_package_properties(OsmTools PROPERTIES
    URL "https://gitlab.com/osm-c-tools/osmctools"
    DESCRIPTION "Tols to convert, filter and update OpenStreetMap data files"
)

mark_as_advanced(OSMCONVERT_EXECUTABLE OSMFILTER_EXECUTABLE OSMCONVERT_EXECUTABLE WGET_EXECUTABLE)

set(OSM_PLANET_DIR "" CACHE PATH "Directory containing the planet-latest.o5m file, and enough space to store processing results in.")
set(OSM_MIRROR "ftp5.gwdg.de/pub/misc/openstreetmap/planet.openstreetmap.org" CACHE STRING "Base URL of the preferred OSM download mirror.")

# create initial download and incremental update targets for the OSM planet file
if (OSM_PLANET_DIR)
    set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM ON) # avoid cleaning the expensive full planet files
    add_custom_command(
        OUTPUT ${OSM_PLANET_DIR}/planet-latest.osm.pbf
        COMMAND ${RSYNC_EXECUTABLE} -Lvz --partial --progress rsync://${OSM_MIRROR}/pbf/planet-latest.osm.pbf ${OSM_PLANET_DIR}/planet-latest.osm.pbf
        WORKING_DIRECTORY ${OSM_PLANET_DIR}
        COMMENT "Downloading full OSM plant file (~60GB)"
    )
    add_custom_command(
        OUTPUT ${OSM_PLANET_DIR}/planet-latest.o5m
        COMMAND OSM::convert ${OSM_PLANET_DIR}/planet-latest.osm.pbf --drop-author --drop-version --out-o5m -o=${OSM_PLANET_DIR}/planet-latest.o5m
        WORKING_DIRECTORY ${OSM_PLANET_DIR}
        COMMENT "Converting full OSM planet file to o5m format (takes ~30min and needs ~80GB of extra disk space)"
    )

    add_custom_target(osm-update-planet
        COMMAND OSM::update --base-url=https://${OSM_MIRROR}/replication --day --verbose ${OSM_PLANET_DIR}/planet-latest.o5m ${OSM_PLANET_DIR}/new-planet-latest.o5m
        COMMAND ${CMAKE_COMMAND} -E rename ${OSM_PLANET_DIR}/new-planet-latest.o5m ${OSM_PLANET_DIR}/planet-test.o5m
        WORKING_DIRECTORY ${OSM_PLANET_DIR}
        DEPENDS ${OSM_PLANET_DIR}/planet-latest.o5m
        COMMENT "Updating OSM planet file"
    )
endif()

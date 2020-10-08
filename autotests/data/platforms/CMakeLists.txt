# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

if (NOT TARGET OSM::filter)
    return()
endif()

add_custom_target(fetch-platform-data)
function(fetch_osm_data _name _bbox)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${_name}.raw.osm
        COMMAND osm-download-data --bbox ${_bbox} --out ${CMAKE_CURRENT_BINARY_DIR}/${_name}.raw.osm
        COMMENT "Downloading ${_name}"
    )
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${_name}.osm
        COMMAND OSM::filter ${CMAKE_CURRENT_BINARY_DIR}/${_name}.raw.osm --drop-author --drop-version --out-osm --keep=route=train --keep=route=light_rail --keep=route=tram --keep=railway=* --keep=public_transport=* --keep=platform*=* --drop-relations=public_transport=station --drop-tags=\\"addr*= building*= contact*= covered= crossing*= cutting= description= ele= embankment= electrified= entrance*= frequency= gauge= HVV:*= heritage*= highspeed= image= indoor*= interval*= maxspeed*= mx:*= name:*= network= note*= layer= lit= operator*= rack= railway:ballastless= railway:bidirectional= railway:etcs= railway:gnt= railway:lzb= railway:milestone*= railway:local_operated= railway:position*= railway:preferred_direction= railway:pzb= railway:radio= railway:radius= railway=signal railway:signal*= railway=switch railway:switch*= railway:tilting= railway:track_class= shelter= source*= TMC*= tactile_paving= toilets*= tunnel*= voltage= via= VRS:*= website= wheelchair*= wiki*= workrules= \\" -o=${CMAKE_CURRENT_SOURCE_DIR}/${_name}.osm
        COMMAND sed -i -e \"s,\\?>,?>\\n<!--\\n    SPDX-FileCopyrightText: OpenStreetMap contributors\\n    SPDX-License-Identifier: ODbL-1.0\\n-->,\" ${CMAKE_CURRENT_SOURCE_DIR}/${_name}.osm
        COMMENT "Filtering ${_name}"
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${_name}.raw.osm
    )
    add_custom_target(fetch-platform-${_name} DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${_name}.osm)
    add_dependencies(fetch-platform-data fetch-platform-${_name})
endfunction()

fetch_osm_data(hamburg-altona 53.55031,9.93353,53.55768,9.93623)
fetch_osm_data(cologne-central 50.94143,6.95608,50.94528,6.96129)
fetch_osm_data(paris-gare-de-lyon 48.84151,2.37250,48.8467,2.38113)
fetch_osm_data(berlin-central 52.52315,13.36642,52.52721,13.37167)
fetch_osm_data(leipzig-central 51.34354,12.37857,51.34835,12.38722)
fetch_osm_data(hamburg-central 53.55027,10.00478,53.55427,10.00992)

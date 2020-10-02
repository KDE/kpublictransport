# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_custom_target(fetch-platform-data)
function(fetch_osm_data _name _bbox)
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${_name}.osm
        COMMAND osm-download-data --bbox ${_bbox} --out ${CMAKE_CURRENT_BINARY_DIR}/${_name}.osm
        COMMENT "Downloading ${_name}"
    )
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${_name}.osm
        COMMAND OSM::filter ${CMAKE_CURRENT_BINARY_DIR}/${_name}.osm --drop-author --drop-version --out-osm --keep=route=train --keep=route=light_rail --keep=route=tram --keep=railway=* --keep=public_transport=* --drop-tags=\\"addr*= covered= description= cutting= embankment= electrified= entrance*= frequency= gauge= HVV:*= heritage*= highspeed= image= interval*= maxspeed= mx:*= network= note*= layer= lit= operator*= rack= railway:ballastless= railway:etcs= railway:gnt= railway:lzb= railway:milestone*= railway:local_operated= railway:position*= railway:pzb= railway:radius= railway=signal railway:signal*= railway=switch railway:switch*= railway:tilting= shelter= source*= TMC*= tunnel= voltage= VRS:*= wheelchair*= wiki*= workrules= \\" -o=${CMAKE_CURRENT_SOURCE_DIR}/${_name}.osm
        COMMAND sed -i -e \"s,\\?>,?>\\n<!--\\n    SPDX-FileCopyrightText: OpenStreetMap contributors\\n    SPDX-License-Identifier: ODbL-1.0\\n-->,\" ${CMAKE_CURRENT_SOURCE_DIR}/${_name}.osm
        COMMENT "Filtering ${_name}"
        DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${_name}.osm
    )
    add_custom_target(fetch-platform-${_name} DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${_name}.osm)
    add_dependencies(fetch-platform-data fetch-platform-${_name})
endfunction()

fetch_osm_data(hamburg-altona 53.55031,9.93353,53.55768,9.93623)
fetch_osm_data(cologne-central 50.94143,6.95608,50.94528,6.96129)

# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_executable(endpointprobe endpointprobe.cpp)
target_link_libraries(endpointprobe Qt5::Network)
add_custom_target(run-endpoint-probe COMMAND endpointprobe ${CMAKE_SOURCE_DIR}/src/lib/networks)

add_executable(otpprobe otpprobe.cpp)
target_link_libraries(otpprobe Qt5::Network)
add_custom_target(run-otp-probe COMMAND otpprobe ${CMAKE_SOURCE_DIR}/src/lib/networks)

add_executable(gbfsprobe gbfsprobe.cpp)
target_link_libraries(gbfsprobe Qt5::Network KPublicTransport)
add_custom_target(run-gbfs-probe COMMAND gbfsprobe ${CMAKE_SOURCE_DIR}/src/lib/gbfs/gbfs-feeds.json)

if (TARGET KOSMIndoorMap)
    add_executable(osm-download-data osm-download-data.cpp)
    target_link_libraries(osm-download-data KOSMIndoorMap)
endif()

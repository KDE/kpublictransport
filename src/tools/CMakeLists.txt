# SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_executable(endpointprobe endpointprobe.cpp)
target_link_libraries(endpointprobe Qt5::Network)
add_custom_target(run-endpoint-probe COMMAND endpointprobe ${CMAKE_SOURCE_DIR}/src/lib/networks)

add_executable(otpprobe
    otpprobe.cpp
    ../lib/geo/geojson.cpp
)
target_link_libraries(otpprobe Qt5::Gui Qt5::Network)
add_custom_target(run-otp-probe COMMAND otpprobe ${CMAKE_SOURCE_DIR}/src/lib/networks)

add_executable(gbfsprobe gbfsprobe.cpp)
target_link_libraries(gbfsprobe Qt5::Network KPublicTransport)
add_custom_target(run-gbfs-probe COMMAND gbfsprobe ${CMAKE_SOURCE_DIR}/src/lib/gbfs/gbfs-feeds.json)

if (TARGET PolyClipping::PolyClipping)
    add_executable(transport-api-sync
        transport-api-sync.cpp
        polygonsimplifier.cpp
        ../lib/geo/geojson.cpp
    )
    target_link_libraries(transport-api-sync Qt5::Gui KOSM PolyClipping::PolyClipping)
    add_custom_target(run-transport-api-sync COMMAND transport-api-sync --config-path ${CMAKE_SOURCE_DIR}/src/lib/networks --transport-apis ${CMAKE_CURRENT_BINARY_DIR}/transport-apis)
endif()

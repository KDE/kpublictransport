add_executable(otpprobe otpprobe.cpp)
target_link_libraries(otpprobe Qt5::Network)

add_custom_target(run-otp-probe COMMAND otpprobe ${CMAKE_SOURCE_DIR}/src/lib/networks)

add_executable(gbfsprobe gbfsprobe.cpp)
target_link_libraries(gbfsprobe Qt5::Network KPublicTransport)

add_custom_target(run-gbfs-probe COMMAND gbfsprobe ${CMAKE_SOURCE_DIR}/src/lib/gbfs/gbfs-feeds.json)

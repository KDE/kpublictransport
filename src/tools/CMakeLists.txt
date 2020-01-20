add_executable(otpprobe otpprobe.cpp)
target_link_libraries(otpprobe Qt5::Network)

add_custom_target(run-otp-probe COMMAND otpprobe ${CMAKE_SOURCE_DIR}/src/lib/networks)

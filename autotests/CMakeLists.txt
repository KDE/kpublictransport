add_definitions(-DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

ecm_add_test(navitiaparsertest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)

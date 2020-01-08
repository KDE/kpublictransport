add_library(KGraphQL STATIC kgraphql.cpp)
target_link_libraries(KGraphQL PUBLIC Qt5::Network)

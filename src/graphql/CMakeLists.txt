add_library(KGraphQL STATIC
    kgraphql.cpp
    kgraphqlminimizer.cpp
)
target_link_libraries(KGraphQL PUBLIC Qt5::Network)

if (NOT BUILD_SHARED_LIBS)
    install(TARGETS KGraphQL EXPORT KPublicTransportTargets ${INSTALL_TARGETS_DEFAULT_ARGS})
endif()

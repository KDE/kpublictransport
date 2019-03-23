set(kpublictransport_srcs
    departurereply.cpp
    departurerequest.cpp
    journeyreply.cpp
    journeyrequest.cpp
    locationreply.cpp
    locationrequest.cpp
    manager.cpp
    reply.cpp

    backends/abstractbackend.cpp
    backends/cache.cpp
    backends/hafasbackend.cpp
    backends/hafasparser.cpp
    backends/hafasmgatebackend.cpp
    backends/hafasmgateparser.cpp
    backends/hafasquerybackend.cpp
    backends/hafasqueryparser.cpp
    backends/navitiabackend.cpp
    backends/navitiaparser.cpp

    datatypes/departure.cpp
    datatypes/journey.cpp
    datatypes/json.cpp
    datatypes/line.cpp
    datatypes/location.cpp
    datatypes/mergeutil.cpp

    networks/networks.qrc
)
ecm_qt_declare_logging_category(kpublictransport_srcs HEADER logging.h IDENTIFIER KPublicTransport::Log CATEGORY_NAME org.kde.kpublictransport)

add_library(KPublicTransport ${kpublictransport_srcs})
generate_export_header(KPublicTransport BASE_NAME KPublicTransport)
set_target_properties(KPublicTransport PROPERTIES
    VERSION ${KPUBLICTRANSPORT_VERSION_STRING}
    SOVERSION ${KPUBLICTRANSPORT_SOVERSION}
    EXPORT_NAME KPublicTransport
)
target_include_directories(KPublicTransport PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>")
target_link_libraries(KPublicTransport
    PUBLIC
        Qt5::Gui
    PRIVATE
        Qt5::Network
        ZLIB::ZLIB
)

ecm_generate_headers(KPublicTransport_FORWARDING_HEADERS
    HEADER_NAMES
        DepartureReply
        DepartureRequest
        JourneyReply
        JourneyRequest
        LocationReply
        LocationRequest
        Manager
        Reply
    PREFIX KPublicTransport
    REQUIRED_HEADERS KPublicTransport_HEADERS
)
# # ### for testing only
ecm_generate_headers(KPublicTransport_Backends_FORWARDING_HEADERS
    HEADER_NAMES
        Cache
        HafasMgateParser
        NavitiaParser
    PREFIX KPublicTransport
    REQUIRED_HEADERS KPublicTransport_Backends_HEADERS
    RELATIVE backends
)
ecm_generate_headers(KPublicTransport_Datatypes_FORWARDING_HEADERS
    HEADER_NAMES
        Datatypes
        Departure
        Journey
        Line
        Location
    PREFIX KPublicTransport
    REQUIRED_HEADERS KPublicTransport_Datatypes_HEADERS
    RELATIVE datatypes
)

install(TARGETS KPublicTransport EXPORT KPublicTransportTargets ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES org_kde_kpublictransport.categories DESTINATION ${KDE_INSTALL_CONFDIR})
install(FILES
    ${KPublicTransport_FORWARDING_HEADERS}
    ${KPublicTransport_Datatypes_FORWARDING_HEADERS}
    DESTINATION ${KDE_INSTALL_INCLUDEDIR}/KPublicTransport
)
install(FILES
    ${KPublicTransport_HEADERS}
    ${KPublicTransport_Datatypes_HEADERS}
    ${CMAKE_CURRENT_BINARY_DIR}/kpublictransport_export.h
    DESTINATION ${KDE_INSTALL_INCLUDEDIR}/kpublictransport
)

# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(knowledgedb)

set(kpublictransport_srcs
    assetrepository.cpp
    journeyreply.cpp
    journeyrequest.cpp
    locationreply.cpp
    locationrequest.cpp
    manager.cpp
    reply.cpp
    requestcontext.cpp
    stopoverreply.cpp
    stopoverrequest.cpp
    vehiclelayoutreply.cpp
    vehiclelayoutrequest.cpp

    backends/abstractbackend.cpp
    backends/accessibilitycloudbackend.cpp
    backends/accessibilitycloudparser.cpp
    backends/cache.cpp
    backends/deutschebahnbackend.cpp
    backends/deutschebahnvehiclelayoutparser.cpp
    backends/efabackend.cpp
    backends/efaparser.cpp
    backends/efacompactparser.cpp
    backends/efaxmlparser.cpp
    backends/hafasbackend.cpp
    backends/hafasparser.cpp
    backends/hafasmgatebackend.cpp
    backends/hafasmgateparser.cpp
    backends/hafasquerybackend.cpp
    backends/hafasqueryparser.cpp
    backends/hafasvehiclelayoutparser.cpp
    backends/navitiabackend.cpp
    backends/navitiaparser.cpp
    backends/oebbbackend.cpp
    backends/oebbvehiclelayoutparser.cpp
    backends/opentripplannergraphqlbackend.cpp
    backends/opentripplannerparser.cpp
    backends/opentripplannerrestbackend.cpp
    backends/otp/otp.qrc
    backends/scopedxmlstreamreader.cpp

    datatypes/attribution.cpp
    datatypes/attributionutil.cpp
    datatypes/backend.cpp
    datatypes/disruption.cpp
    datatypes/equipment.cpp
    datatypes/equipmentutil.cpp
    datatypes/journey.cpp
    datatypes/journeyutil.cpp
    datatypes/json.cpp
    datatypes/line.cpp
    datatypes/lineutil.cpp
    datatypes/load.cpp
    datatypes/loadutil.cpp
    datatypes/location.cpp
    datatypes/locationutil.cpp
    datatypes/mergeutil.cpp
    datatypes/notesutil.cpp
    datatypes/path.cpp
    datatypes/platform.cpp
    datatypes/platformutils.cpp
    datatypes/rentalvehicle.cpp
    datatypes/rentalvehicleutil.cpp
    datatypes/stopover.cpp
    datatypes/stopoverutil.cpp
    datatypes/vehicle.cpp
    datatypes/vehiclelayoutresult.cpp

    gbfs/gbfs.cpp
    gbfs/gbfs.qrc
    gbfs/gbfsbackend.cpp
    gbfs/gbfsjob.cpp
    gbfs/gbfsservice.cpp
    gbfs/gbfsstore.cpp

    geo/geojson.cpp
    geo/polylinedecoder.cpp

    gtfs/hvt.cpp

    knowledgedb/linemetadata.cpp

    models/abstractquerymodel.cpp
    models/backendmodel.cpp
    models/journeyquerymodel.cpp
    models/locationquerymodel.cpp
    models/stopoverquerymodel.cpp
    models/vehiclelayoutquerymodel.cpp

    networks/networks.qrc
    networks/certs/network_certs.qrc
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
        KGraphQL
        KOSM
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
        StopoverReply
        StopoverRequest
        VehicleLayoutReply
        VehicleLayoutRequest
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
        Attribution
        Backend
        Datatypes
        Departure
        Disruption
        Equipment
        Journey
        Line
        Load
        Location
        RentalVehicle
        Path
        Platform
        Stopover
        Vehicle
    PREFIX KPublicTransport
    REQUIRED_HEADERS KPublicTransport_Datatypes_HEADERS
    RELATIVE datatypes
)
ecm_generate_headers(KPublicTransport_Models_FORWARDING_HEADERS
    HEADER_NAMES
        AbstractQueryModel
        BackendModel
        DepartureQueryModel
        JourneyQueryModel
        LocationQueryModel
        StopoverQueryModel
        VehicleLayoutQueryModel
    PREFIX KPublicTransport
    REQUIRED_HEADERS KPublicTransport_Models_HEADERS
    RELATIVE models
)

install(TARGETS KPublicTransport EXPORT KPublicTransportTargets ${INSTALL_TARGETS_DEFAULT_ARGS})
install(FILES org_kde_kpublictransport.categories DESTINATION ${KDE_INSTALL_LOGGINGCATEGORIESDIR})
install(FILES
    ${KPublicTransport_FORWARDING_HEADERS}
    ${KPublicTransport_Datatypes_FORWARDING_HEADERS}
    ${KPublicTransport_Models_FORWARDING_HEADERS}
    DESTINATION ${KDE_INSTALL_INCLUDEDIR}/KPublicTransport
)
install(FILES
    ${KPublicTransport_HEADERS}
    ${KPublicTransport_Datatypes_HEADERS}
    ${KPublicTransport_Models_HEADERS}
    ${CMAKE_CURRENT_BINARY_DIR}/kpublictransport_export.h
    DESTINATION ${KDE_INSTALL_INCLUDEDIR}/kpublictransport
)

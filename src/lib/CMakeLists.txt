# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_subdirectory(knowledgedb)

add_library(KPublicTransport)
qt_extract_metatypes(KPublicTransport)

target_sources(KPublicTransport PRIVATE
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
    backends/efamodeoftransport.cpp
    backends/efaxmlparser.cpp
    backends/hafasbackend.cpp
    backends/hafasparser.cpp
    backends/hafasmgatebackend.cpp
    backends/hafasmgateparser.cpp
    backends/hafasquerybackend.cpp
    backends/hafasqueryparser.cpp
    backends/hafasvehiclelayoutparser.cpp
    backends/ivvassbackend.cpp
    backends/ivvassparser.cpp
    backends/ivvassproductmap.cpp
    backends/localbackendutils.cpp
    backends/ltglinkbackend.cpp
    backends/motisbackend.cpp
    backends/motisparser.cpp
    backends/navitiabackend.cpp
    backends/navitiaparser.cpp
    backends/navitiaphysicalmode.cpp
    backends/networkreplycollection.cpp
    backends/oebbbackend.cpp
    backends/oebbvehiclelayoutparser.cpp
    backends/openjourneyplannerbackend.cpp
    backends/openjourneyplannerparser.cpp
    backends/openjourneyplannerrequestbuilder.cpp
    backends/opentripplannergraphqlbackend.cpp
    backends/opentripplannerparser.cpp
    backends/opentripplannerrestbackend.cpp
    backends/otp/otp.qrc
    backends/scopedxmlstreamreader.cpp
    backends/srbijavozbackend.cpp
    backends/zpcgbackend.cpp

    datatypes/attribution.cpp
    datatypes/attributionutil.cpp
    datatypes/backend.cpp
    datatypes/coveragearea.cpp
    datatypes/disruption.cpp
    datatypes/equipment.cpp
    datatypes/equipmentutil.cpp
    datatypes/feature.cpp
    datatypes/featureutil.cpp
    datatypes/individualtransport.cpp
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
    datatypes/timeutil.cpp
    datatypes/variant.cpp
    datatypes/vehicle.cpp

    gbfs/gbfs.cpp
    gbfs/gbfs.qrc
    gbfs/gbfsbackend.cpp
    gbfs/gbfsjob.cpp
    gbfs/gbfsreader.cpp
    gbfs/gbfsservice.cpp
    gbfs/gbfsstore.cpp
    gbfs/gbfsvehicletypes.cpp

    geo/convexhull.cpp
    geo/geojson.cpp
    geo/polylinedecoder.cpp

    gtfs/hvt.cpp

    ifopt/ifoptutil.cpp

    images/images.qrc

    json/jsonp.cpp
    json/jsonpointer.cpp

    knowledgedb/asset-attributions.qrc
    knowledgedb/linemetadata.cpp

    layout/platformlayout.cpp

    models/abstractquerymodel.cpp
    models/backendmodel.cpp
    models/journeyquerymodel.cpp
    models/locationhistorymodel.cpp
    models/locationquerymodel.cpp
    models/pathmodel.cpp
    models/stopoverquerymodel.cpp
    models/vehiclelayoutquerymodel.cpp

    networks/networks.qrc
    networks/certs/network_certs.qrc
    networks/geometry/geometry.qrc
    networks/stations/stations.qrc

    uic/uicrailwaycoach.cpp
    uic/uicstationcode.cpp
)
ecm_qt_declare_logging_category(KPublicTransport
    HEADER logging.h
    IDENTIFIER KPublicTransport::Log
    CATEGORY_NAME org.kde.kpublictransport
    DESCRIPTION "KPublicTransport"
    EXPORT KPUBLICTRANSPORT
)

generate_export_header(KPublicTransport BASE_NAME KPublicTransport)
set_target_properties(KPublicTransport PROPERTIES
    VERSION ${KPUBLICTRANSPORT_VERSION}
    SOVERSION ${KPUBLICTRANSPORT_SOVERSION}
    EXPORT_NAME KPublicTransport
)
target_include_directories(KPublicTransport PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR};${CMAKE_BINARY_DIR}>")
target_include_directories(KPublicTransport INTERFACE "$<INSTALL_INTERFACE:${KPUBLICTRANSPORT_INSTALL_INCLUDEDIR}>")
target_link_libraries(KPublicTransport
    PUBLIC
        Qt::Gui
    PRIVATE
        KGraphQL
        KOSM
        Qt::Network
        ZLIB::ZLIB
)

ecm_generate_headers(KPublicTransport_FORWARDING_HEADERS
    HEADER_NAMES
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
        CoverageArea
        Datatypes
        Disruption
        Equipment
        Feature
        IndividualTransport
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
ecm_generate_headers(KPublicTransport_Layout_FORWARDING_HEADERS
    HEADER_NAMES
        PlatformLayout
    PREFIX KPublicTransport
    REQUIRED_HEADERS KPublicTransport_Layout_HEADERS
    RELATIVE layout
)
ecm_generate_headers(KPublicTransport_Models_FORWARDING_HEADERS
    HEADER_NAMES
        AbstractQueryModel
        BackendModel
        JourneyQueryModel
        LocationHistoryModel
        LocationQueryModel
        PathModel
        StopoverQueryModel
        VehicleLayoutQueryModel
    PREFIX KPublicTransport
    REQUIRED_HEADERS KPublicTransport_Models_HEADERS
    RELATIVE models
)

install(TARGETS KPublicTransport EXPORT KPublicTransportTargets ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
ecm_qt_install_logging_categories(
    EXPORT KPUBLICTRANSPORT
    FILE org_kde_kpublictransport.categories
    DESTINATION ${KDE_INSTALL_LOGGINGCATEGORIESDIR}
)
install(FILES
    ${KPublicTransport_FORWARDING_HEADERS}
    ${KPublicTransport_Datatypes_FORWARDING_HEADERS}
    ${KPublicTransport_Layout_FORWARDING_HEADERS}
    ${KPublicTransport_Models_FORWARDING_HEADERS}
    DESTINATION ${KPUBLICTRANSPORT_INSTALL_INCLUDEDIR}/KPublicTransport
)
install(FILES
    ${KPublicTransport_HEADERS}
    ${KPublicTransport_Datatypes_HEADERS}
    ${KPublicTransport_Layout_HEADERS}
    ${KPublicTransport_Models_HEADERS}
    ${CMAKE_CURRENT_BINARY_DIR}/kpublictransport_export.h
    DESTINATION ${KPUBLICTRANSPORT_INSTALL_INCLUDEDIR}/kpublictransport
)


if (BUILD_QCH)
    ecm_add_qch(
        KPublicTransport_QCH
        NAME KPublicTransport
        BASE_NAME KPublicTransport
        VERSION ${RELEASE_SERVICE_VERSION}
        ORG_DOMAIN org.kde
        SOURCES # using only public headers, to cover only public API
        ${KPublicTransport_HEADERS}
        ${KPublicTransport_Datatypes_HEADERS}
        ${KPublicTransport_Models_HEADERS}
        MD_MAINPAGE "${CMAKE_SOURCE_DIR}/README.md"
        #IMAGE_DIRS "${CMAKE_SOURCE_DIR}/docs/pics"
        LINK_QCHS
            Qt6Core_QCH
        INCLUDE_DIRS
            ${CMAKE_CURRENT_BINARY_DIR}
        BLANK_MACROS
            KPUBLICTRANSPORT_EXPORT
        TAGFILE_INSTALL_DESTINATION ${KDE_INSTALL_QTQCHDIR}
        QCH_INSTALL_DESTINATION ${KDE_INSTALL_QTQCHDIR}
        COMPONENT Devel
    )
endif()

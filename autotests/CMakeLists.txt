# SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_definitions(-DSOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

ecm_add_test(osmtypetest.cpp LINK_LIBRARIES Qt5::Test KOSM)
ecm_add_test(o5mparsertest.cpp LINK_LIBRARIES Qt5::Test KOSM)

ecm_add_test(kgraphqlminimizertest.cpp LINK_LIBRARIES Qt5::Test KGraphQL)

ecm_add_test(indexeddatatabletest LINK_LIBRARIES Qt5::Test)

ecm_add_test(mergeutiltest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(locationtest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(linetest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(departuretest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(journeytest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(platformtest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(notestest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(backendtest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(linemetadatatest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(networkconfigtest.cpp LINK_LIBRARIES Qt5::Test)

ecm_add_test(navitiaparsertest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(hafasmgateparsertest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(hafasqueryparsertest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(efaparsertest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(deutschebahntest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(otpparsertest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(publictransportmanagertest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(cachetest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)
ecm_add_test(gbfstest.cpp LINK_LIBRARIES Qt5::Test KPublicTransport)

if (TARGET KOSMIndoorMap)
    add_subdirectory(data/platforms)
    ecm_add_test(mapviewtest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMap)
    ecm_add_test(mapcssparsertest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMap)
    ecm_add_test(scenegeometrytest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMap)
    ecm_add_test(tilecachetest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMap)
    ecm_add_test(marblegeometryassemblertest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMap)
    ecm_add_test(mapleveltest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMap)
    ecm_add_test(levelparsertest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMap)
    ecm_add_test(penwidthutiltest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMap)
    ecm_add_test(platformfindertest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMap)
    ecm_add_test(platformmodeltest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMap)
    ecm_add_test(osmelementinfomodeltest.cpp LINK_LIBRARIES Qt5::Test KOSMIndoorMapQuick)
endif()

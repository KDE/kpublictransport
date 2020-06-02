flex_target(mapcssscanner
    style/mapcsslexer.l
    ${CMAKE_CURRENT_BINARY_DIR}/mapcsslexer.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/mapcssscanner.h
    COMPILE_FLAGS "--nounistd"
)
bison_target(mapcssparser
    style/mapcssparser.y
    ${CMAKE_CURRENT_BINARY_DIR}/mapcssparser_p.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/mapcssparser_p.h
)
add_flex_bison_dependency(mapcssscanner mapcssparser)

add_library(KOSMIndoorMap STATIC
    assets/assets.qrc

    loader/boundarysearch.cpp
    loader/mapdata.cpp
    loader/maploader.cpp
    loader/marblegeometryassembler.cpp
    loader/tilecache.cpp

    renderer/hitdetector.cpp
    renderer/painterrenderer.cpp
    renderer/view.cpp

    scene/scenecontroller.cpp
    scene/scenegeometry.cpp
    scene/scenegraph.cpp
    scene/scenegraphitem.cpp

    style/mapcsscondition.cpp
    style/mapcssdeclaration.cpp
    style/mapcssparser.cpp
    style/mapcssresult.cpp
    style/mapcssrule.cpp
    style/mapcssselector.cpp
    style/mapcssstate.cpp
    style/mapcssstyle.cpp
    ${BISON_mapcssparser_OUTPUTS}
    ${FLEX_mapcssscanner_OUTPUTS}
)

target_include_directories(KOSMIndoorMap PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)
target_include_directories(KOSMIndoorMap PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>)
target_link_libraries(KOSMIndoorMap
    PUBLIC Qt5::Gui KOSM
    PRIVATE Qt5::Network
)

ecm_generate_headers(KOSMIndoorMap_Loader_FORWARDING_HEADERS
    HEADER_NAMES
        MapLoader
        MapData
    PREFIX KOSMIndoorMap
    REQUIRED_HEADERS KOSMIndoorMap_Loader_HEADERS
    RELATIVE loader
)
ecm_generate_headers(KOSMIndoorMap_Renderer_FORWARDING_HEADERS
    HEADER_NAMES
        HitDetector
        PainterRenderer
        View
    PREFIX KOSMIndoorMap
    REQUIRED_HEADERS KOSMIndoorMap_Renderer_HEADERS
    RELATIVE renderer
)
ecm_generate_headers(KOSMIndoorMap_Scene_FORWARDING_HEADERS
    HEADER_NAMES
        SceneController
        SceneGraph
    PREFIX KOSMIndoorMap
    REQUIRED_HEADERS KOSMIndoorMap_Scene_HEADERS
    RELATIVE scene
)
ecm_generate_headers(KOSMIndoorMap_Style_FORWARDING_HEADERS
    HEADER_NAMES
        MapCSSParser
        MapCSSStyle
    PREFIX KOSMIndoorMap
    REQUIRED_HEADERS KOSMIndoorMap_Style_HEADERS
    RELATIVE style
)

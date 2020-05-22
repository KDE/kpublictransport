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

    loader/mapdata.cpp
    loader/maploader.cpp

    renderer/painterrenderer.cpp
    renderer/view.cpp

    scene/scenecontroller.cpp
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
)

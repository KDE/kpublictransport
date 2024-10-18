/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import QtLocation as QtLocation
import QtPositioning as QtPositioning
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport


Kirigami.Page {
    id: root

    property KPublicTransport.journey journey

    function pathForSection(section)
    {
        // if (section.path.sectionCount > 0) {
        //     let poly = [];
        //     for (const pathSec of section.path.sections) {
        //         for (const p of pathSec.path)
        //             poly.push({latitude: p.y, longitude: p.x});
        //     }
        //     return poly;
        // }
        let poly = [{latitude: section.from.latitude, longitude: section.from.longitude}];
        for (const stop of section.intermediateStops)
            poly.push({latitude: stop.stopPoint.latitude, longitude: stop.stopPoint.longitude});
        poly.push({latitude: section.to.latitude, longitude: section.to.longitude});
        return poly;
    }

    QtLocation.Map {
        id: map
        plugin: QtLocation.Plugin {
            name: "osm"
            QtLocation.PluginParameter { name: "osm.useragent"; value: "org.kde.kpublictransport/JourneyQueryDemo" }
            QtLocation.PluginParameter { name: "osm.mapping.providersrepository.address"; value: "https://autoconfig.kde.org/qtlocation/" }
        }

        onCopyrightLinkActivated: (link) => Qt.openUrlExternally(link)

        property QtPositioning.geoCoordinate startCentroid
        PinchHandler {
            id: pinch
            target: null
            onActiveChanged: if (active) {
                map.startCentroid = map.toCoordinate(pinch.centroid.position, false)
            }
            onScaleChanged: (delta) => {
                map.zoomLevel += Math.log2(delta)
                map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position)
            }
            xAxis.enabled: false
            yAxis.enabled: false
            minimumRotation: 0.0
            maximumRotation: 0.0
        }
        WheelHandler {
            id: wheel
            rotationScale: 1/120
            orientation: Qt.Vertical
            acceptedDevices: PointerDevice.Mouse | PointerDevice.TouchPad
            onWheel: (event) => {
                map.startCentroid = map.toCoordinate(wheel.point.position, false)
                map.zoomLevel += event.angleDelta.y * rotationScale
                map.alignCoordinateToPoint(map.startCentroid, wheel.point.position)
            }
        }
        DragHandler {
            id: drag
            target: null
            onTranslationChanged: (delta) => map.pan(-delta.x, -delta.y)
        }
        Shortcut {
            enabled: map.zoomLevel < map.maximumZoomLevel
            sequence: StandardKey.ZoomIn
            onActivated: map.zoomLevel = Math.round(map.zoomLevel + 1)
        }
        Shortcut {
            enabled: map.zoomLevel > map.minimumZoomLevel
            sequence: StandardKey.ZoomOut
            onActivated: map.zoomLevel = Math.round(map.zoomLevel - 1)
        }

        anchors.fill: parent
        Repeater {
            model: root.journey.sections
            QtLocation.MapPolyline {
                line.width: 10
                line.color: modelData.route.line.hasColor ? modelData.route.line.color : Kirigami.Theme.textColor
                path: pathForSection(modelData)
            }
        }
        Repeater {
            model: root.journey.sections
            QtLocation.MapQuickItem {
                coordinate {
                    latitude: modelData.departure.stopPoint.latitude
                    longitude: modelData.departure.stopPoint.longitude
                }
                anchorPoint.x: sourceItem.width/2
                anchorPoint.y: sourceItem.height/2
                sourceItem: Rectangle {
                    width:15
                    height:15
                    radius: height/2
                    border.width: 2
                    border.color: line.line.color
                    MouseArea {
                        anchors.fill: parent
                        scale: 2
                        onClicked: console.log(modelData.departure);
                    }
                }
            }
        }
        Repeater {
            model: root.journey.sections
            Repeater {
                model: modelData.intermediateStops
                QtLocation.MapQuickItem {
                    coordinate {
                        latitude: modelData.stopPoint.latitude
                        longitude: modelData.stopPoint.longitude
                    }
                    anchorPoint.x: sourceItem.width/2
                    anchorPoint.y: sourceItem.height/2
                    sourceItem: Rectangle {
                        width: 6
                        height: 6
                        radius: height/2
                        opacity: 0.5
                        MouseArea {
                            anchors.fill: parent
                            scale: 3
                            onClicked: console.log(modelData)
                        }
                    }
                }
            }
        }
        Repeater {
            model: root.journey.sections
            QtLocation.MapQuickItem {
                coordinate {
                    latitude: modelData.arrival.stopPoint.latitude
                    longitude: modelData.arrival.stopPoint.longitude
                }
                anchorPoint.x: sourceItem.width/2
                anchorPoint.y: sourceItem.height/2
                sourceItem: Rectangle {
                    width:15
                    height:15
                    radius: height/2
                    border.width: 2
                    border.color: line.line.color
                    MouseArea {
                        anchors.fill: parent
                        scale: 2
                        onClicked: console.log(modelData.arrival);
                    }
                }
            }
        }
    }
}

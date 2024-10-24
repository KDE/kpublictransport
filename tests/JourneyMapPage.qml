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
import org.kde.kpublictransport.ui as KPublicTransport

Kirigami.Page {
    id: root

    property KPublicTransport.journey journey

    topPadding: 0
    bottomPadding: 0
    leftPadding: 0
    rightPadding: 0

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

        // transport paths
        Repeater {
            model: root.journey.sections.filter((sec) => { return sec.mode != KPublicTransport.JourneySection.Walking || sec.path.sectionCount == 0})
            QtLocation.MapPolyline {
                line.width: switch (modelData.mode) {
                    case KPublicTransport.JourneySection.Walking:
                        return 4;
                    case KPublicTransport.JourneySection.PublicTransport:
                        return  modelData.route.line.mode == KPublicTransport.Line.Air ? 2 : 10;
                    default:
                        return 6;
                }
                line.color: modelData.route.line.hasColor ? modelData.route.line.color : "black"
                referenceSurface: modelData.route.line.mode == KPublicTransport.Line.Air ? QtLocation.QtLocation.ReferenceSurface.Globe : QtLocation.QtLocation.ReferenceSurface.Map
                path: KPublicTransport.MapUtils.polyline(modelData);
            }
        }
        // walking paths
        Repeater {
            model: root.journey.sections.filter((sec) => { return sec.mode == KPublicTransport.JourneySection.Walking && sec.path.sectionCount > 0})
            Repeater {
                model: modelData.path.sections
                QtLocation.MapPolyline {
                    line.width: 4
                    line.color: "black"
                    opacity: (modelData.hasStartFloorLevel && modelData.startFloorLevel < 0 && (modelData.startFloorLevel + modelData.floorLevelChange) < 0) ? 0.5 : 1.0
                    path: KPublicTransport.MapUtils.polyline(modelData);
                }
            }
        }
        // departure dots
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
                    border.color: modelData.route.line.hasColor ? modelData.route.line.color : "black"
                    MouseArea {
                        anchors.fill: parent
                        scale: 2
                        onClicked: console.log(modelData.departure);
                    }
                }
            }
        }
        // intermediate stops
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
        // path maneuvers
        Repeater {
            model: root.journey.sections.filter((sec) => { return sec.mode == KPublicTransport.JourneySection.Walking && sec.path.sectionCount > 0})
            Repeater {
                model: modelData.path.sections
                QtLocation.MapQuickItem {
                    coordinate {
                        latitude: modelData.startPoint.y
                        longitude: modelData.startPoint.x
                    }
                    anchorPoint.x: sourceItem.width/2
                    anchorPoint.y: sourceItem.height/2
                    sourceItem: Rectangle {
                        width: 16
                        height: 16
                        radius: height/2

                        Kirigami.Icon {
                            anchors.fill: parent
                            source: modelData.maneuver == KPublicTransport.PathSection.Move ? "go-up" : modelData.iconName
                            isMask: true
                            color: "black"
                            rotation: modelData.maneuver == KPublicTransport.PathSection.Move ? modelData.direction : 0
                        }
                    }
                }
            }
        }
        // arrival dots
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
                    border.color: modelData.route.line.hasColor ? modelData.route.line.color : "black"
                    MouseArea {
                        anchors.fill: parent
                        scale: 2
                        onClicked: console.log(modelData.arrival);
                    }
                }
            }
        }

        function centerOnJourney() {
            const bbox = KPublicTransport.MapUtils.boundingBox(root.journey);
            map.center = KPublicTransport.MapUtils.center(bbox);
            map.zoomLevel = KPublicTransport.MapUtils.zoomLevel(bbox, map.width, map.height);
        }

        onWidthChanged: centerOnJourney();
        onHeightChanged: centerOnJourney();
        Component.onCompleted: centerOnJourney();
    }
}

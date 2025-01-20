/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtLocation as QtLocation
import QtPositioning as QtPositioning
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport

Kirigami.Page {
    id: root

    property KPublicTransport.journeySection journey

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
        QtLocation.MapPolyline {
            line.width: 6
            line.color: root.journey.route.line.hasColor ? root.journey.route.line.color : "black"
            path: KPublicTransport.MapUtils.polyline(root.journey);
        }
        // departure dots
        QtLocation.MapQuickItem {
            coordinate {
                latitude: root.journey.departure.stopPoint.latitude
                longitude: root.journey.departure.stopPoint.longitude
            }
            anchorPoint.x: sourceItem.width/2
            anchorPoint.y: sourceItem.height/2
            sourceItem: Rectangle {
                width:15
                height:15
                radius: height/2
                border.width: 2
                border.color: root.journey.route.line.hasColor ? root.journey.route.line.color : "black"
            }
        }
        // intermediate stops
        Repeater {
            model: root.journey.intermediateStops
            QtLocation.MapQuickItem {
                required property KPublicTransport.stopover modelData
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
                }
            }
        }
        // arrival dots
        QtLocation.MapQuickItem {
            coordinate {
                latitude: root.journey.arrival.stopPoint.latitude
                longitude: root.journey.arrival.stopPoint.longitude
            }
            anchorPoint.x: sourceItem.width/2
            anchorPoint.y: sourceItem.height/2
            sourceItem: Rectangle {
                width:15
                height:15
                radius: height/2
                border.width: 2
                border.color: root.journey.route.line.hasColor ? root.journey.route.line.color : "black"
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

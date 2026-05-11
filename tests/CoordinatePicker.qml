/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
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
    property QtPositioning.geoCoordinate coordinate
    padding: 0

    QtLocation.Map {
        id: map
        anchors.fill: parent

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

        TapHandler {
            onTapped: (ev) => {
                root.coordinate = map.toCoordinate(ev.position, true);
                applicationWindow().pageStack.pop();
            }
        }
    }
}

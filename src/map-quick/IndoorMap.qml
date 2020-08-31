/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.12
import QtQuick.Layouts 1.12
import org.kde.kosmindoormap 1.0
import QtQuick.Controls 2.12 as QQC2

/** QML item for displaying a train station or airport map. */
Item {
    id: mapRoot

    /** Access to map loading status and progress. */
    property alias mapLoader: map.loader
    /** Path to a MapCSS style sheet used for rendering the map. */
    property alias styleSheet: map.styleSheet
    /** Floor level model. */
    property alias floorLevels: map.floorLevels
    /** Access to the view transformation and floor level selection. */
    property alias view: map.view
    /** There is something preventing displaying a map. */
    property alias hasError: map.hasError
    /** Access to the map data, for feeding into content-specific models. */
    property alias mapData: map.mapData
    /** Access to overlay sources. */
    property alias overlaySources: map.overlaySources

    /** Emitted when a map element has been picked by clicking/tapping on it. */
    signal elementPicked(var element);

    MapItemImpl {
        id: map
        anchors.fill: parent

    }

    Flickable {
        id: flickable
        boundsBehavior: Flickable.StopAtBounds
        clip: true
        contentX: map.view.panX
        contentY: map.view.panY
        contentWidth: map.view.panWidth
        contentHeight: map.view.panHeight
        anchors.fill: parent

        onContentXChanged: {
            if (moving) {
                map.view.panTopLeft(flickable.contentX, flickable.contentY);
                map.update();
            }
        }
        onContentYChanged: {
            if (moving) {
                map.view.panTopLeft(flickable.contentX, flickable.contentY);
                map.update();
            }
        }

        QQC2.ScrollBar.vertical: QQC2.ScrollBar {}
        QQC2.ScrollBar.horizontal: QQC2.ScrollBar {}

        TapHandler {
            acceptedButtons: Qt.LeftButton
            onTapped: {
                var root = parent;
                while (root.parent) { root = root.parent; }
                var localPos = map.mapFromItem(root, eventPoint.scenePosition.x, eventPoint.scenePosition.y);
                var element = map.elementAt(localPos.x, localPos.y);
                if (!element.isNull) {
                    elementPicked(element);
                }
            }
        }
        PinchHandler {
            id: pinchHandler
            target: null
            property double initialZoom
            onActiveChanged: {
                initialZoom = map.view.zoomLevel
            }
            onActiveScaleChanged: {
                map.view.setZoomLevel(pinchHandler.initialZoom + Math.log2(pinchHandler.activeScale), pinchHandler.centroid.pressPosition);
            }
            xAxis.enabled: false
            yAxis.enabled: false
            minimumRotation: 0.0
            maximumRotation: 0.0
        }
    }

    Connections {
        target: map.view
        onTransformationChanged: {
            flickable.contentX = map.view.panX;
            flickable.contentY = map.view.panY;
        }
    }

    MouseArea {
        acceptedButtons: Qt.NoButton
        anchors.fill: parent
        onWheel: {
            if (wheel.angleDelta.y > 0) {
                map.view.zoomIn(Qt.point(wheel.x, wheel.y));
            } else {
                map.view.zoomOut(Qt.point(wheel.x, wheel.y));
            }
            wheel.accepted = true;
        }
    }

    QQC2.BusyIndicator {
        anchors.centerIn: parent
        running: map.loader.isLoading
    }

    QQC2.Label {
        anchors.fill: parent
        text: map.errorMessage
        visible: map.hasError
        wrapMode: Text.WordWrap
        horizontalAlignment: Qt.AlignHCenter
        verticalAlignment: Qt.AlignVCenter
    }
}

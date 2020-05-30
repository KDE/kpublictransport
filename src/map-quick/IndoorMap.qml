/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
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

    MapItemImpl {
        id: map
        anchors.fill: parent
    }

    Flickable {
        id: flickable
        boundsBehavior: Flickable.StopAtBounds
        contentX: map.view.panX
        contentY: map.view.panY
        contentWidth: map.view.panWidth
        contentHeight: map.view.panHeight
        anchors.fill: parent

        Rectangle { color: "red"; width: 100; height: 100 }
        Rectangle { color: "green"; width: 100; height: 100; x: flickable.contentWidth - width; y: flickable.contentHeight - height; }

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
    }

    Connections {
        target: map.view
        onTransformationChanged: {
            console.log(map.view.panY, flickable.contentY);
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
            map.update();
        }
    }

    PinchArea {
        anchors.fill: parent
    }

    QQC2.BusyIndicator {
        anchors.centerIn: parent
        running: map.loader.isLoading
    }
}

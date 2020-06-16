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
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import org.kde.kirigami 2.7 as Kirigami
import org.kde.kosmindoormap 1.0

Kirigami.Page {
    title: "Indoor Map View"
    property point coordinate
    property alias map: map

    topPadding: 0
    bottomPadding: 0
    leftPadding: 0
    rightPadding: 0

    // prevent swipe to the right changing pages, we want to pan the map instead
    // TODO in theory we could make this conditional to having panned the map all the way to the right
    Kirigami.ColumnView.preventStealing: true

    actions {
        left: Kirigami.Action {
            iconName: "go-down-symbolic"
            enabled: map.floorLevels.hasFloorLevelBelow(map.view.floorLevel)
            onTriggered: map.view.floorLevel = map.floorLevels.floorLevelBelow(map.view.floorLevel)
        }
        right: Kirigami.Action {
            iconName: "go-up-symbolic"
            enabled: map.floorLevels.hasFloorLevelAbove(map.view.floorLevel)
            onTriggered: map.view.floorLevel = map.floorLevels.floorLevelAbove(map.view.floorLevel)
        }
    }

    Kirigami.OverlaySheet {
        id: elementDetailsSheet
        property var element

        header: Kirigami.Heading {
            text: elementDetailsSheet.element.name
        }

        ColumnLayout {
            QQC2.Label {
                visible: text != ""
                text: elementDetailsSheet.element.tagValue("description");
            }
            QQC2.Label {
                visible: text != ""
                text: elementDetailsSheet.element.tagValue("amenity") + elementDetailsSheet.element.tagValue("shop") + elementDetailsSheet.element.tagValue("tourism") + elementDetailsSheet.element.tagValue("office")
            }
            QQC2.Label {
                visible: text != ""
                text: elementDetailsSheet.element.tagValue("opening_hours");
            }
            QQC2.Label {
                visible: elementDetailsSheet.element.tagValue("website") != ""
                text: "<a href=\"" + elementDetailsSheet.element.tagValue("website") + "\">" + elementDetailsSheet.element.tagValue("website") + "</a>"
                onLinkActivated: Qt.openUrlExternally(link)
            }
            QQC2.Label {
                visible: elementDetailsSheet.element.wikipediaUrl != ""
                text: "<a href=\"" + elementDetailsSheet.element.wikipediaUrl + "\">Wikipedia</a>"
                onLinkActivated: Qt.openUrlExternally(link)
            }
            QQC2.Label {
                text: elementDetailsSheet.element.tagValue("addr:street") + " " + elementDetailsSheet.element.tagValue("addr:housenumber") +
                    "\n" + elementDetailsSheet.element.tagValue("addr:postcode") + " " + elementDetailsSheet.element.tagValue("addr:city") +
                    "\n" + elementDetailsSheet.element.tagValue("addr:country");
            }
        }
    }

    IndoorMap {
        id: map
        anchors.fill: parent

        IndoorMapScale {
            map: map
            anchors.left: map.left
            anchors.bottom: map.bottom
            width: 0.3 * map.width
        }

        IndoorMapAttributionLabel {
            anchors.right: map.right
            anchors.bottom: map.bottom
        }

        onElementPicked: {
            elementDetailsSheet.element = element;
            elementDetailsSheet.sheetOpen = true;
        }
    }

    onCoordinateChanged: map.mapLoader.loadForCoordinate(coordinate.y, coordinate.x);
}

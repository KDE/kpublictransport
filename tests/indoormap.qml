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
import org.kde.kirigami 2.0 as Kirigami
import org.kde.kosmindoormap 1.0

Kirigami.ApplicationWindow {
    title: "OSM Indoor Map QML Test"

    pageStack.initialPage: Kirigami.Page {
        title: "Indoor Map View"

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
            contextualActions: [
                Kirigami.Action {
                    text: "Light Style"
                    onTriggered: map.styleSheet = ":/org.kde.kosmindoormap/assets/css/breeze-light.mapcss"
                },
                Kirigami.Action {
                    text: "Dark Style"
                    onTriggered: map.styleSheet = ":/org.kde.kosmindoormap/assets/css/breeze-dark.mapcss"
                },
                Kirigami.Action {
                    text: "Diagnostic View"
                    onTriggered: map.styleSheet = ":/org.kde.kosmindoormap/assets/css/diagnostic.mapcss"
                }
            ]
        }

        header: RowLayout {
            QQC2.Label { text: "Floor Level:" }
            QQC2.ComboBox {
                id: floorLevelCombo
                model: map.floorLevels
                textRole: "display"
                Component.onCompleted: currentIndex = map.floorLevels.rowForLevel(map.view.floorLevel);
                onCurrentIndexChanged: if (currentIndex >= 0) { map.view.floorLevel = map.floorLevels.levelForRow(currentIndex); }
            }
            Connections {
                target: map.view
                onFloorLevelChanged: floorLevelCombo.currentIndex = map.floorLevels.rowForLevel(map.view.floorLevel);
            }

            QQC2.Label { text: "Coordinate:" }
            QQC2.TextField {
                id: coordInput
                placeholderText: "map coordinates"
                text: "49.44572, 11.08196"
            }
            QQC2.Button {
                text: "x"
                onClicked: coordInput.text = ""
            }
            QQC2.Button {
                text: ">"
                onClicked: {
                    var c = coordInput.text.match(/(.*)[,;/ ]+(.*)/);
                    var lat = c[1];
                    var lon = c[2];
                    map.mapLoader.loadForCoordinate(lat, lon);
                }
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
            styleSheet: ":/org.kde.kosmindoormap/assets/css/breeze-light.mapcss"

            Component.onCompleted: {
                map.mapLoader.loadForCoordinate(49.44572, 11.08196);
            }

            onElementPicked: {
                elementDetailsSheet.element = element;
                elementDetailsSheet.sheetOpen = true;
            }
        }
    }
}

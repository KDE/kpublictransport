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

    pageStack.initialPage: IndoorMapPage {
        id: page

        actions {
            contextualActions: [
                Kirigami.Action {
                    text: "Light Style"
                    onTriggered: page.map.styleSheet = ":/org.kde.kosmindoormap/assets/css/breeze-light.mapcss"
                },
                Kirigami.Action {
                    text: "Dark Style"
                    onTriggered: page.map.styleSheet = ":/org.kde.kosmindoormap/assets/css/breeze-dark.mapcss"
                },
                Kirigami.Action {
                    text: "Diagnostic View"
                    onTriggered: page.map.styleSheet = ":/org.kde.kosmindoormap/assets/css/diagnostic.mapcss"
                }
            ]
        }

        header: RowLayout {
            QQC2.Label { text: "Floor Level:" }
            QQC2.ComboBox {
                id: floorLevelCombo
                model: page.map.floorLevels
                textRole: "display"
                currentIndex: page.map.floorLevels.rowForLevel(page.map.view.floorLevel);
                onCurrentIndexChanged: if (currentIndex >= 0) { page.map.view.floorLevel = page.map.floorLevels.levelForRow(currentIndex); }
            }
            Connections {
                target: page.map.view
                onFloorLevelChanged: floorLevelCombo.currentIndex = page.map.floorLevels.rowForLevel(page.map.view.floorLevel);
            }

            QQC2.Slider {
                id: zoomSlider
                from: 14.0
                to: 21.0
                live: true
                Layout.preferredWidth: 200

                onValueChanged: {
                    page.map.view.setZoomLevel(value, Qt.point(page.map.width / 2.0, page.map.height/ 2.0));
                }
            }
            Connections {
                target: page.map.view
                onZoomLevelChanged: zoomSlider.value = page.map.view.zoomLevel
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
                    var c = coordInput.text.match(/([\d\.-]+)[,;/ ]+([\d\.-]*)/);
                    var lat = c[1];
                    var lon = c[2];
                    page.map.mapLoader.loadForCoordinate(lat, lon);
                }
            }
        }

        coordinate: Qt.point(11.08196, 49.44572);
    }
}

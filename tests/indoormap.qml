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
import Qt.labs.platform 1.0 as QPlatform
import org.kde.kirigami 2.0 as Kirigami
import org.kde.kosmindoormap 1.0

Kirigami.ApplicationWindow {
    title: "OSM Indoor Map QML Test"

    globalDrawer: Kirigami.GlobalDrawer {
        title: i18n("Indoor Map")
        titleIcon: "map-symbolic"
        isMenu: true
        actions: [
            Kirigami.Action {
                text: "Open O5M File"
                onTriggered: fileDialog.open()
            },
            Kirigami.Action {
                text: "Open MapCSS Stylesheet"
                onTriggered: mapcssDialog.open()
            },
            Kirigami.Action {
                text: "Reload Stylesheet"
                onTriggered: {
                    var s = page.map.styleSheet;
                    page.map.styleSheet = "";
                    page.map.styleSheet = s;
                }
            }
        ]
    }

    QPlatform.FileDialog {
        id: fileDialog
        title: "Open O5M File"
        fileMode: QPlatform.FileDialog.OpenFile
        nameFilters: ["o5m file (*.o5m)"]
        onAccepted: page.map.mapLoader.loadFromO5m(fileDialog.file);
    }
    QPlatform.FileDialog {
        id: mapcssDialog
        title: "Open MapCSS Stylesheet"
        fileMode: QPlatform.FileDialog.OpenFile
        nameFilters: ["MapCSS stylesheet (*.mapcss)"]
        onAccepted: page.map.styleSheet = mapcssDialog.file
    }

    pageStack.initialPage: IndoorMapPage {
        id: page
        debug: debugAction.checked

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
                },
                Kirigami.Action {
                    id: debugAction
                    text: "Debug Info Model"
                    checkable: true
                    checked: false
                },
                Kirigami.Action {
                    id: platformAction
                    text: "Find Platform"
                    onTriggered: platformSheet.sheetOpen = true
                },
                Kirigami.Action {
                    id: gateAction
                    text: "Find Gate"
                    onTriggered: gateSheet.sheetOpen = true
                }
            ]
        }

        PlatformModel {
            id: platformModel
            mapData: page.map.mapData
        }

        Kirigami.OverlaySheet {
            id: platformSheet

            header: Kirigami.Heading {
                text: "Find Platform"
            }

            ListView {
                model: platformModel

                delegate: Kirigami.BasicListItem {
                    text: model.display
                    highlighted: false
                    onClicked: {
                        page.map.view.floorLevel = model.level
                        page.map.view.centerOnGeoCoordinate(model.coordinate);
                        page.map.view.setZoomLevel(19, Qt.point(page.map.width / 2.0, page.map.height/ 2.0));
                        platformSheet.sheetOpen = false
                    }
                }
            }
        }

        GateModel {
            id: gateModel
            mapData: page.map.mapData
        }

        Kirigami.OverlaySheet {
            id: gateSheet

            header: Kirigami.Heading {
                text: "Find Gate"
            }

            ListView {
                model: gateModel

                delegate: Kirigami.BasicListItem {
                    text: model.display
                    highlighted: false
                    onClicked: {
                        page.map.view.floorLevel = model.level
                        page.map.view.centerOnGeoCoordinate(model.coordinate);
                        page.map.view.setZoomLevel(18, Qt.point(page.map.width / 2.0, page.map.height/ 2.0));
                        gateSheet.sheetOpen = false
                    }
                }
            }
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

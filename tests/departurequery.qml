/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import Qt.labs.platform 1.0 as Platform
import org.kde.kirigami 2.0 as Kirigami
import org.kde.kpublictransport 1.0

Kirigami.ApplicationWindow {
    title: "Departure Query"
    reachableModeEnabled: false

    width: 540
    height: 800

    pageStack.initialPage: departureQueryPage

    globalDrawer: Kirigami.GlobalDrawer {
        actions: [
            Kirigami.Action {
                text: i18n("Save...")
                iconName: "document-save"
                onTriggered: fileDialog.open();
            },
            Kirigami.Action {
                iconName: "help-about-symbolic"
                text: i18n("Data Sources")
                enabled: _attributions.length > 0
                onTriggered: aboutSheet.sheetOpen = true;
            }
        ]
    }

    Platform.FileDialog {
        id: fileDialog
        title: i18n("Save Departure Data")
        fileMode: Platform.FileDialog.SaveFile
        nameFilters: ["JSON files (*.json)"]
        onAccepted: _queryMgr.saveTo(fileDialog.file);
    }

    TestLocationsModel { id: exampleModel }
    AttributionSheet {
        id: aboutSheet
        attributions: _attributions
    }
    LocationDetailsSheet { id: locationDetailsSheet }

    Component {
        id: departureDelegate
        Kirigami.AbstractListItem {
            RowLayout {
                id: delegateLayout

                Rectangle {
                    id: colorBar
                    width: Kirigami.Units.largeSpacing
                    color: modelData.route.line.hasColor ? modelData.route.line.color : "transparent"
                    Layout.fillHeight: true
                }

                QQC2.Label {
                    text: {
                        switch (modelData.route.line.mode) {
                            case Line.Air: return "✈️";
                            case Line.Boat: return "🛥️";
                            case Line.Bus: return "🚍";
                            case Line.BusRapidTransit: return "🚌";
                            case Line.Coach: return "🚌";
                            case Line.Ferry: return "⛴️";
                            case Line.Funicular: return "🚞";
                            case Line.LocalTrain: return "🚆";
                            case Line.LongDistanceTrain: return "🚄";
                            case Line.Metro: return "🚇";
                            case Line.RailShuttle: return "🚅";
                            case Line.RapidTransit: return "🚊";
                            case Line.Shuttle: return "🚐";
                            case Line.Taxi: return "🚕";
                            case Line.Train: return "🚆";
                            case Line.Tramway: return "🚈";
                            default: return "?";
                        }
                    }
                    font.pointSize: Kirigami.Theme.defaultFont.pointSize * 2
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    QQC2.Label {
                        Layout.fillWidth: true
                        text: modelData.route.line.modeString + " " + modelData.route.line.name + " to " + modelData.route.direction
                    }
                    RowLayout {
                        QQC2.Label {
                            text: "Arrival: " + modelData.scheduledArrivalTime.toTimeString()
                        }
                        QQC2.Label {
                            text: (modelData.arrivalDelay >= 0 ? "+" : "") + modelData.arrivalDelay
                            color: modelData.arrivalDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                            visible: modelData.hasExpectedArrivalTime
                        }
                        QQC2.Label {
                            text: "Departure: " + modelData.scheduledDepartureTime.toTimeString()
                        }
                        QQC2.Label {
                            text: (modelData.departureDelay >= 0 ? "+" : "") + modelData.departureDelay
                            color: modelData.departureDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                            visible: modelData.hasExpectedDepartureTime
                        }
                    }
                    RowLayout {
                        QQC2.Label {
                            text: "From: <a href=\"#from\">" + modelData.stopPoint.name + "</a>"
                            onLinkActivated: {
                                locationDetailsSheet.location = modelData.stopPoint;
                                locationDetailsSheet.sheetOpen = true;
                            }
                        }
                        QQC2.Label {
                            visible: modelData.scheduledPlatform != ""
                            text: "Platform: " + modelData.scheduledPlatform + (platformChange.visible ? " -> " : "")
                            color: (!platformChange.visible && modelData.hasExpectedPlatform) ? Kirigami.Theme.positiveTextColor : Kirigami.Theme.textColor
                        }
                        QQC2.Label {
                            id: platformChange
                            text: modelData.expectedPlatform
                            visible: modelData.hasExpectedPlatform && modelData.scheduledPlatform != modelData.expectedPlatform
                            color: Kirigami.Theme.negativeTextColor
                        }
                    }
                }
            }
        }
    }

    Component {
        id: departureQueryPage
        Kirigami.Page {
            ColumnLayout {
                anchors.fill: parent

                QQC2.CheckBox {
                    id: arrivalBox
                    text: checked ? "Arrival" : "Departure"
                }

                QQC2.CheckBox {
                    text: "Allow insecure backends"
                    onToggled: _queryMgr.setAllowInsecure(checked)
                }

                QQC2.ComboBox {
                    id: exampleSelector
                    Layout.fillWidth: true
                    model: exampleModel
                    textRole: "label"
                    onCurrentIndexChanged: {
                        var obj = exampleModel.get(currentIndex);
                        nameQuery.text = obj.name == undefined ? obj.label : obj.name;
                        lonQuery.text = obj.lon;
                        latQuery.text = obj.lat;
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    QQC2.TextField {
                        Layout.fillWidth: true
                        id: nameQuery
                    }
                    QQC2.TextField {
                        id: lonQuery
                        Layout.preferredWidth: 100
                    }
                    QQC2.TextField {
                        id: latQuery
                        Layout.preferredWidth: 100
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    QQC2.Button {
                        text: "Query"
                        onClicked: _queryMgr.queryDeparture(nameQuery.text, latQuery.text, lonQuery.text, arrivalBox.checked);
                    }
                    QQC2.Button {
                        text: "Query Name"
                        onClicked: _queryMgr.queryDeparture(nameQuery.text, NaN, NaN, arrivalBox.checked);
                    }
                    QQC2.Button {
                        text: "Query Coord"
                        onClicked: _queryMgr.queryDeparture("", latQuery.text, lonQuery.text, arrivalBox.checked);

                    }
                }

                ListView {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: _departures
                    clip: true
                    delegate: departureDelegate

                    QQC2.BusyIndicator {
                        anchors.centerIn: parent
                        running: _queryMgr.loading
                    }

                    QQC2.Label {
                        anchors.centerIn: parent
                        width: parent.width
                        text: _queryMgr.errorMessage
                        color: Kirigami.Theme.negativeTextColor
                        wrapMode: Text.Wrap
                    }
                }

            }
        }
    }
}

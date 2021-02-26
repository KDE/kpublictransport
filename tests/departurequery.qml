/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import Qt.labs.platform 1.0 as Platform
import Qt.labs.settings 1.0
import org.kde.kirigami 2.0 as Kirigami
import org.kde.kpublictransport 1.0
import org.kde.example 1.0

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
                enabled: departureModel.attributions.length > 0
                onTriggered: aboutSheet.sheetOpen = true;
            },
            Kirigami.Action {
                iconName: "settings-configure"
                text: "Backends"
                onTriggered: pageStack.push(backendPage)
            }
        ]
    }

    Platform.FileDialog {
        id: fileDialog
        title: i18n("Save Departure Data")
        fileMode: Platform.FileDialog.SaveFile
        nameFilters: ["JSON files (*.json)"]
        onAccepted: ExampleUtil.saveTo(departureModel, fileDialog.file);
    }

    TestLocationsModel { id: exampleModel }
    AttributionSheet {
        id: aboutSheet
        attributions: departureModel.attributions
    }
    LocationDetailsSheet { id: locationDetailsSheet }

    Manager {
        id: ptMgr;
    }

    Settings {
        id: settings
        property alias allowInsecureBackends: ptMgr.allowInsecureBackends
        property alias enabledBackends: ptMgr.enabledBackends
        property alias disabledBackends: ptMgr.disabledBackends
    }

    StopoverQueryModel {
        id: departureModel
        manager: ptMgr
    }

    Component {
        id: vehicleLayoutPage
        VehicleLayoutPage {
            publicTransportManager: ptMgr
        }
    }

    Component {
        id: indoorMapPage
        IndoorMapPage {}
    }

    Component {
        id: departureDelegate
        Kirigami.AbstractListItem {
            enabled: departure.disruptionEffect != Disruption.NoService
            highlighted: false
            RowLayout {
                id: delegateLayout

                Kirigami.Icon {
                    id: icon
                    source: departure.route.line.hasLogo ? departure.route.line.logo : departure.route.line.modeLogo
                    width: height
                    height: Kirigami.Units.iconSizes.large
                    visible: source != ""
                }

                Rectangle {
                    id: colorBar
                    width: Kirigami.Units.largeSpacing
                    color: departure.route.line.hasColor ? departure.route.line.color : "transparent"
                    Layout.fillHeight: true
                    visible: icon.source == ""
                }

                QQC2.Label {
                    text: {
                        switch (departure.route.line.mode) {
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
                            case Line.RideShare: return "🚗";
                            default: return "?";
                        }
                    }
                    font.pointSize: Kirigami.Theme.defaultFont.pointSize * 2
                    visible: icon.source == ""
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    QQC2.Label {
                        Layout.fillWidth: true
                        text: departure.route.line.modeString + " " + departure.route.line.name + " to <a href=\"#dest\">" + departure.route.direction + "</a>"
                        onLinkActivated: {
                            locationDetailsSheet.location = departure.route.destination;
                            locationDetailsSheet.sheetOpen = true;
                        }
                    }
                    RowLayout {
                        QQC2.Label {
                            text: "Arrival: " + departure.scheduledArrivalTime.toTimeString()
                        }
                        QQC2.Label {
                            text: (departure.arrivalDelay >= 0 ? "+" : "") + departure.arrivalDelay
                            color: departure.arrivalDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                            visible: departure.hasExpectedArrivalTime
                        }
                        QQC2.Label {
                            text: "Departure: " + departure.scheduledDepartureTime.toTimeString()
                        }
                        QQC2.Label {
                            text: (departure.departureDelay >= 0 ? "+" : "") + departure.departureDelay
                            color: departure.departureDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                            visible: departure.hasExpectedDepartureTime
                        }
                        QQC2.Label {
                            text: "<a href=\"#layout\">vehicle</a>"
                            visible: departure.route.line.mode == Line.LongDistanceTrain
                            onLinkActivated: applicationWindow().pageStack.push(vehicleLayoutPage, {"departure": departure });
                            Layout.fillWidth: true
                            horizontalAlignment: Text.Right
                        }
                    }
                    RowLayout {
                        QQC2.Label {
                            text: "From: <a href=\"#from\">" + departure.stopPoint.name + "</a>"
                            onLinkActivated: {
                                locationDetailsSheet.location = departure.stopPoint;
                                locationDetailsSheet.sheetOpen = true;
                            }
                        }
                        QQC2.Label {
                            visible: departure.scheduledPlatform != ""
                            text: "Platform: " + departure.scheduledPlatform + (platformChange.visible ? " -> " : "")
                            color: (!platformChange.visible && departure.hasExpectedPlatform) ? Kirigami.Theme.positiveTextColor : Kirigami.Theme.textColor
                        }
                        QQC2.Label {
                            id: platformChange
                            text: departure.expectedPlatform
                            visible: departure.hasExpectedPlatform && departure.scheduledPlatform != departure.expectedPlatform
                            color: Kirigami.Theme.negativeTextColor
                        }
                    }
                    QQC2.Label {
                        text: departure.notes.join("<br/>")
                        visible: departure.notes.length > 0
                        font.italic: true
                        textFormat: Text.RichText
                    }
                }
            }
        }
    }

    Component {
        id: backendPage
        BackendPage {
            publicTransportManager: ptMgr
        }
    }

    Component {
        id: departureQueryPage
        Kirigami.Page {
            Settings {
                id: settings
                property alias queryArrivals: arrivalBox.checked
                property alias singleBackend: backendBox.checked
                property alias backend: backendSelector.currentIndex
            }

            ColumnLayout {
                anchors.fill: parent

                QQC2.CheckBox {
                    id: arrivalBox
                    text: checked ? "Arrival" : "Departure"
                }

                QQC2.CheckBox {
                    text: "Allow insecure backends"
                    checked: ptMgr.allowInsecureBackends
                    onToggled: ptMgr.allowInsecureBackends = checked
                }

                RowLayout {
                    QQC2.CheckBox {
                        id: backendBox
                        text: "Select Backend:"
                    }
                    QQC2.ComboBox {
                        id: backendSelector
                        Layout.fillWidth: true
                        textRole: "identifier"
                        model: BackendModel {
                            manager: ptMgr
                        }
                        enabled: backendBox.checked
                    }
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
                        onClicked: {
                            var stop = departureModel.request.stop;
                            stop.latitude = latQuery.text;
                            stop.longitude = lonQuery.text;
                            stop.name = nameQuery.text;
                            departureModel.request.stop = stop;
                            departureModel.request.mode = arrivalBox.checked ? StopoverRequest.QueryArrival : StopoverRequest.QueryDeparture;
                            departureModel.request.backends = backendBox.checked ? [ backendSelector.currentText ] : [];
                            departureModel.request.downloadAssets = true
                        }
                    }
                    QQC2.Button {
                        text: "Query Name"
                        onClicked: {
                            var stop = departureModel.request.stop;
                            stop.latitude = NaN;
                            stop.longitude = NaN;
                            stop.name = nameQuery.text;
                            departureModel.request.stop = stop;
                            departureModel.request.mode = arrivalBox.checked ? StopoverRequest.QueryArrival : StopoverRequest.QueryDeparture;
                            departureModel.request.backends = backendBox.checked ? [ backendSelector.currentText ] : [];
                            departureModel.request.downloadAssets = true
                        }
                    }
                    QQC2.Button {
                        text: "Query Coord"
                        onClicked: {
                            var stop = departureModel.request.stop;
                            stop.latitude = latQuery.text;
                            stop.longitude = lonQuery.text;
                            stop.name = "";
                            departureModel.request.stop = stop;
                            departureModel.request.mode = arrivalBox.checked ? StopoverRequest.QueryArrival : StopoverRequest.QueryDeparture;
                            departureModel.request.backends = backendBox.checked ? [ backendSelector.currentText ] : [];
                            departureModel.request.downloadAssets = true
                        }
                    }
                    QQC2.Button {
                        text: "Earlier"
                        enabled: departureModel.canQueryPrevious
                        onClicked: departureModel.queryPrevious()
                    }
                    QQC2.Button {
                        text: "Later"
                        enabled: departureModel.canQueryNext
                        onClicked: departureModel.queryNext()
                    }
                }

                ListView {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: departureModel
                    clip: true
                    delegate: departureDelegate

                    QQC2.BusyIndicator {
                        anchors.centerIn: parent
                        running: departureModel.loading
                    }

                    QQC2.Label {
                        anchors.centerIn: parent
                        width: parent.width
                        text: departureModel.errorMessage
                        color: Kirigami.Theme.negativeTextColor
                        wrapMode: Text.Wrap
                    }
                }

            }
        }
    }
}

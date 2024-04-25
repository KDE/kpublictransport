/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtCore
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import QtQuick.Dialogs as Dialogs
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport
import org.kde.example

Kirigami.ApplicationWindow {
    title: "Departure Query"

    width: 540
    height: 800

    pageStack.initialPage: departureQueryPage

    globalDrawer: Kirigami.GlobalDrawer {
        actions: [
            Kirigami.Action {
                text: "Save..."
                icon.name: "document-save"
                onTriggered: fileDialog.open();
            },
            Kirigami.Action {
                icon.name: "help-about-symbolic"
                text: "Data Sources"
                enabled: departureModel.attributions.length > 0
                onTriggered: aboutSheet.open();
            },
            Kirigami.Action {
                icon.name: "settings-configure"
                text: "Backends"
                onTriggered: pageStack.push(backendPage)
            }
        ]
    }

    Dialogs.FileDialog {
        id: fileDialog
        title: "Save Departure Data"
        fileMode: Dialog.FileDialog.SaveFile
        nameFilters: ["JSON files (*.json)"]
        onAccepted: ExampleUtil.saveTo(departureModel, fileDialog.selectedFile);
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
        QQC2.ItemDelegate {
            enabled: departure.disruptionEffect != Disruption.NoService
            highlighted: false
            width: ListView.view.width
            contentItem: RowLayout {
                id: delegateLayout

                Rectangle {
                    id: colorBar
                    width: Kirigami.Units.largeSpacing
                    color: departure.route.line.hasColor ? departure.route.line.color : "transparent"
                    Layout.fillHeight: true
                }

                Kirigami.Icon {
                    id: icon
                    source: departure.route.line.iconName
                    width: height
                    height: Kirigami.Units.iconSizes.large
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    QQC2.Label {
                        Layout.fillWidth: true
                        text: {
                            if (departure.route.name !== "") {
                                return departure.route.line.modeString + " " + departure.route.line.name + " (" + departure.route.name
                                    + ") to <a href=\"#dest\">" + departure.route.direction + "</a>"
                            }
                            return departure.route.line.modeString + " " + departure.route.line.name
                                + " to <a href=\"#dest\">" + departure.route.direction + "</a>";
                        }
                        onLinkActivated: {
                            locationDetailsSheet.location = departure.route.destination;
                            locationDetailsSheet.open();
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
                            visible: departure.route.line.mode == Line.LongDistanceTrain || departure.route.line.mode == Line.Train || departure.route.name !== ""
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
                                locationDetailsSheet.open();
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
                        text: departure.route.line.operatorName
                        visible: text !== ""
                    }
                    RowLayout {
                        Repeater {
                            model: departure.features
                                delegate: FeatureDelegate {
                                feature: modelData
                            }
                        }
                    }
                    RowLayout {
                        visible: departure.loadInformation.length > 0
                        QQC2.Label {
                            text: "Load: ";
                        }
                        Repeater {
                            model: departure.loadInformation
                            RowLayout {
                                QQC2.Label {
                                    text: {
                                        switch (modelData.load) {
                                            case Load.Low: return "Low";
                                            case Load.Medium: return "Medium";
                                            case Load.High: return "High";
                                            case Load.Full: return "Full";
                                            default: return "?"
                                        }
                                    }
                                    color: {
                                        switch (modelData.load) {
                                            case Load.Low: return Kirigami.Theme.positiveTextColor;
                                            case Load.Medium: return Kirigami.Theme.neutralTextColor;
                                            case Load.High:
                                            case Load.Full:
                                                return Kirigami.Theme.negativeTextColor;
                                            default:
                                                return Kirigami.Theme.textColor;
                                        }
                                    }
                                }
                                QQC2.Label {
                                    text: "(class " + modelData.seatingClass + ")"
                                    visible: modelData.seatingClass != ""
                                }
                            }
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
                property alias maxResults: maxResults.text
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
                RowLayout {
                    QQC2.Label { text: "Results:" }
                    QQC2.TextField {
                        id: maxResults
                        text: "10"
                    }
                }

                QQC2.ComboBox {
                    id: exampleSelector
                    Layout.fillWidth: true
                    model: exampleModel
                    textRole: "label"
                    onCurrentIndexChanged: {
                        var obj = exampleModel.get(currentIndex);
                        nameQuery.text = obj.name == "" ? obj.label : obj.name;
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

                QQC2.ComboBox {
                    id: lineModeSelector
                    Layout.fillWidth: true
                    model: [ "All", "Only long distance", "Local public transport", "Local trains only", "Rapit transit/metro/tram", "Bus" ]
                    property var currentMode: {
                        switch (currentIndex) {
                            case 1: return [Line.LongDistanceTrain, Line.Train];
                            case 2: return [Line.LocalTrain, Line.RapidTransit, Line.Metro, Line.Tramway, Line.Funicular, Line.Bus];
                            case 3: return [Line.LocalTrain];
                            case 4: return [Line.RapidTransit, Line.Metro, Line.Tramway, Line.Funicular];
                            case 5: return [Line.Bus];
                        }
                        return [];
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
                            departureModel.request.downloadAssets = true;
                            departureModel.request.maximumResults = maxResults.text;
                            departureModel.request.lineModes = lineModeSelector.currentMode
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
                            departureModel.request.downloadAssets = true;
                            departureModel.request.lineModes = lineModeSelector.currentMode
                            departureModel.request.maximumResults = maxResults.text;
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
                            departureModel.request.downloadAssets = true;
                            departureModel.request.maximumResults = maxResults.text;
                            departureModel.request.lineModes = lineModeSelector.currentMode
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

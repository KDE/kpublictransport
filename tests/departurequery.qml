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
import org.kde.coreaddons as KCoreAddons
import org.kde.kpublictransport
import org.kde.kpublictransport.ui
import org.kde.example

Kirigami.ApplicationWindow {

    width: 540
    height: 800

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
        fileMode: Dialogs.FileDialog.SaveFile
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
        property alias allowInsecureBackends: ptMgr.allowInsecureBackends
        property alias enabledBackends: ptMgr.enabledBackends
        property alias disabledBackends: ptMgr.disabledBackends
    }

    StopoverQueryModel {
        id: departureModel
        manager: ptMgr
        autoUpdate: autoUpdateBox.checked
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

                TransportIcon {
                    id: icon
                    source: departure.route.line.iconName
                    iconHeight: Kirigami.Units.iconSizes.smallMedium
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
                            text: "Arrival:"
                            visible: arrivalTimeLabel.scheduledTime !== ""
                        }
                        ExpectedTimeLabel {
                            id: arrivalTimeLabel
                            stopover: departure
                            scheduledTime: KCoreAddons.Format.formatTime(departure, "scheduledArrivalTime", Locale.ShortFormat, KCoreAddons.FormatTypes.AddTimezoneAbbreviationIfNeeded)
                            delay: departure.arrivalDelay
                            hasExpectedTime: departure.hasExpectedArrivalTime
                        }
                        QQC2.Label {
                            text: "Departure:"
                            visible: departureTimeLabel.scheduledTime !== ""
                        }
                        ExpectedTimeLabel {
                            id: departureTimeLabel
                            stopover: departure
                            scheduledTime: KCoreAddons.Format.formatTime(departure, "scheduledDepartureTime", Locale.ShortFormat, KCoreAddons.FormatTypes.AddTimezoneAbbreviationIfNeeded)
                            delay: departure.departureDelay
                            hasExpectedTime: departure.hasExpectedDepartureTime
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
                    RowLayout {
                        Repeater {
                            model: departure.features
                            delegate: FeatureIcon {
                                feature: modelData
                                Layout.preferredHeight: Kirigami.Units.iconSizes.small
                                Layout.preferredWidth: Kirigami.Units.iconSizes.small
                            }
                        }
                    }
                    RowLayout {
                        visible: departure.loadInformation.length > 0
                        Repeater {
                            model: departure.loadInformation
                            RowLayout {
                                id: loadDelegateRoot
                                required property loadInfo modelData
                                OccupancyIndicator {
                                    occupancy: loadDelegateRoot.modelData.load
                                    Layout.preferredHeight: Kirigami.Units.iconSizes.small
                                    Layout.preferredWidth: Kirigami.Units.iconSizes.small
                                }
                                QQC2.Label {
                                    text: "(class " + loadDelegateRoot.modelData.seatingClass + ")"
                                    visible: loadDelegateRoot.modelData.seatingClass != ""
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

            onClicked: {
                if (stopover.stopPoint.hasCoordinate || stopover.hasTripIdentifiers)
                    applicationWindow().pageStack.push(detailsPage, {
                        stopover: departure,
                        backendIds: backendBox.checked ? [ backendSelector.currentText ] : [],
                        isArrival: arrivalBox.checked,
                        ptMgr: ptMgr
                    });
            }
        }
    }

    Component {
        id: backendPage
        BackendPage {
            publicTransportManager: ptMgr
            actions: [ onlineUpdateAction ]
        }
    }
    Component {
        id: detailsPage
        StopoverDetailsPage {}
    }

    pageStack.initialPage: Kirigami.Page {
        title: "Departure Query"

        Settings {
            id: settings
            property alias queryArrivals: arrivalBox.checked
            property alias singleBackend: backendBox.checked
            property alias backend: backendSelector.currentIndex
            property alias maxResults: maxResults.text
            property alias autoUpdate: autoUpdateBox.checked
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

            QQC2.CheckBox {
                id: autoUpdateBox
                text: "Update continuously"
            }

            RowLayout {
                Layout.fillWidth: true
                QQC2.Button {
                    text: "Query"
                    onClicked: {
                        departureModel.request = {
                            stop: {
                                latitude: latQuery.text,
                                longitude: lonQuery.text,
                                name: nameQuery.text
                            },
                            mode: arrivalBox.checked ? StopoverRequest.QueryArrival : StopoverRequest.QueryDeparture,
                            backends: backendBox.checked ? [ backendSelector.currentText ] : [],
                            downloadAssets: true,
                            maximumResults: maxResults.text,
                            lineModes: lineModeSelector.currentMode
                        }
                    }
                }
                QQC2.Button {
                    text: "Query Name"
                    onClicked: {
                        departureModel.request = {
                            stop: {
                                name: nameQuery.text
                            },
                            mode: arrivalBox.checked ? StopoverRequest.QueryArrival : StopoverRequest.QueryDeparture,
                            backends: backendBox.checked ? [ backendSelector.currentText ] : [],
                            downloadAssets: true,
                            maximumResults: maxResults.text,
                            lineModes: lineModeSelector.currentMode
                        }
                    }
                }
                QQC2.Button {
                    text: "Query Coord"
                    onClicked: {
                        departureModel.request = {
                            stop: {
                                latitude: latQuery.text,
                                longitude: lonQuery.text
                            },
                            mode: arrivalBox.checked ? StopoverRequest.QueryArrival : StopoverRequest.QueryDeparture,
                            backends: backendBox.checked ? [ backendSelector.currentText ] : [],
                            downloadAssets: true,
                            maximumResults: maxResults.text,
                            lineModes: lineModeSelector.currentMode
                        }
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

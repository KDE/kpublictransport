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
import org.kde.kpublictransport.ui
import org.kde.example

Kirigami.ApplicationWindow {
    title: "Location Query"

    width: 540
    height: 720

    pageStack.initialPage: locationQueryPage

    Manager {
        id: ptMgr
    }
    Settings {
        id: settings
        property alias allowInsecureBackends: ptMgr.allowInsecureBackends
        property alias enabledBackends: ptMgr.enabledBackends
        property alias disabledBackends: ptMgr.disabledBackends
    }

    LocationQueryModel {
        id: locationModel
        manager: ptMgr
    }

    TestLocationsModel { id: exampleModel }
    AttributionSheet {
        id: aboutSheet
        attributions: locationModel.attributions
    }

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
                enabled: locationModel.attributions.length > 0
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
        onAccepted: ExampleUtil.saveTo(locationModel, fileDialog.selectedFile);
    }

    Component {
        id: locationDelegate
        Kirigami.SwipeListItem {
            id: delegateRoot
            required property location location
            actions: [
                Kirigami.Action {
                    icon.name: "map-globe"
                    text: "View on OSM"
                    onTriggered: Qt.openUrlExternally("https://www.openstreetmap.org/#map=18/" + delegateRoot.location.latitude + "/" + delegateRoot.location.longitude)
                },
                Kirigami.Action {
                    icon.name: "map-symbolic"
                    text: "Indoor Map"
                    onTriggered: pageStack.push(indoorMapPage, {coordinate: Qt.point(delegateRoot.location.longitude, delegateRoot.location.latitude)})
                }
            ]
            contentItem: RowLayout {
                Kirigami.Icon {
                    source: delegateRoot.location.iconName
                    Layout.preferredHeight: Kirigami.Units.iconSizes.medium
                    Layout.preferredWidth: Kirigami.Units.iconSizes.medium
                    Layout.alignment: Qt.AlignCenter
                }
                ColumnLayout {
                    id: delegateLayout
                    Layout.fillWidth: true
                    QQC2.Label {
                        text: delegateRoot.location.name
                        color: {
                            if (delegateRoot.location && delegateRoot.location.type == Location.Equipment) {
                                switch (delegateRoot.location.equipment.disruptionEffect) {
                                    case Disruption.NormalService:
                                        return Kirigami.Theme.positiveTextColor;
                                    case Disruption.NoService:
                                        return Kirigami.Theme.negativeTextColor;
                                }
                            }
                            return Kirigami.Theme.textColor;
                        }
                    }
                    QQC2.Label {
                        text: delegateRoot.location.streetAddress
                        visible: delegateRoot.location.streetAddress.length > 0
                    }
                    QQC2.Label {
                        text: "ZIP: " + delegateRoot.location.postalCode + " City: " + delegateRoot.location.locality
                        visible: delegateRoot.location.postalCode.length > 0 || delegateRoot.location.locality.length > 0
                    }
                    QQC2.Label {
                        text: "Region: " + delegateRoot.location.region + " Country: " + delegateRoot.location.country
                        visible: delegateRoot.location.region.length > 0 || delegateRoot.location.country.length > 0
                    }
                    QQC2.Label {
                        text: "Lat: " + delegateRoot.location.latitude + " Lon: " + delegateRoot.location.longitude
                    }
                    QQC2.Label {
                        text: "<a href=\"" + delegateRoot.location.rentalVehicleStation.network.url + "\">" + delegateRoot.location.rentalVehicleStation.network.name + "</a> (" + delegateRoot.location.rentalVehicleStation.availableVehicles
                            + "/" + delegateRoot.location.rentalVehicleStation.capacity + ")"
                        visible: delegateRoot.location.rentalVehicleStation.isValid
                        onLinkActivated: (link) => { Qt.openUrlExternally(link); }
                    }
                    QQC2.Label {
                        text: delegateRoot.location.equipment ? delegateRoot.location.equipment.notes.join("<br/>") : ''
                        visible: text != ''
                        font.italic: true
                        textFormat: Text.RichText
                    }
                    Flow {
                        Layout.fillWidth: true
                        spacing: Kirigami.Units.smallSpacing
                        Repeater {
                            model: delegateRoot.location.stopInformation.lines
                            TransportNameControl {
                                required property line modelData
                                line: modelData
                            }
                        }
                    }
                    QQC2.Label {
                        text: {
                            let s = "Identifiers:";
                            for (const type of delegateRoot.location.identifierTypes)
                                s += " " + type + ":" + delegateRoot.location.identifier(type);
                            return s;
                        }
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
        id: indoorMapPage
        IndoorMapPage {}
    }

    Component {
        id: locationQueryPage
        Kirigami.Page {
            Settings {
                id: settings
                property alias singleBackend: backendBox.checked
                property alias backend: backendSelector.currentIndex
                property alias maxResults: maxResults.text
                property alias maxDistance: maxDist.text
                property alias includeStops: includeStops.checked
                property alias includeRentals: includeRentals.checked
                property alias includeEquipment: includeEquipment.checked
                property alias includeAddresses: includeAddresses.checked

                property alias biasEnabled: biasBox.checked
                property alias biasLon1: biasX1.text
                property alias biasLat1: biasY1.text
                property alias biasLon2: biasX2.text
                property alias biasLat2: biasY2.text
            }

            ColumnLayout {
                anchors.fill: parent

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
                    QQC2.Label { text: "Distance:" }
                    QQC2.TextField {
                        id: maxDist
                        text: "1000"
                    }
                }

                RowLayout {
                    QQC2.CheckBox {
                        id: includeStops
                        checked: true
                        text: "Public Transport Stops"
                    }
                    QQC2.CheckBox {
                        id: includeRentals
                        checked: true
                        text: "Rental Vehicles"
                    }
                    QQC2.CheckBox {
                        id: includeEquipment
                        checked: true
                        text: "Elevators"
                    }
                    QQC2.CheckBox {
                        id: includeAddresses
                        checked: true
                        text: "Addresses"
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    QQC2.CheckBox {
                        id: biasBox
                        checked: false
                        text: "Bias"
                    }
                    QQC2.TextField {
                        id: biasX1
                        text: "5.93"
                        validator: DoubleValidator { bottom: -180; top: 180; decimals: 2 }
                        maximumLength: 6
                        Layout.maximumWidth: maximumLength * Kirigami.Units.gridUnit
                    }
                    QQC2.TextField {
                        id: biasY1
                        text: "45.8"
                        validator: DoubleValidator { bottom: -90; top: 90; decimals: 2 }
                        maximumLength: 5
                        Layout.maximumWidth: maximumLength * Kirigami.Units.gridUnit
                    }
                    QQC2.TextField {
                        id: biasX2
                        text: "10.5"
                        validator: DoubleValidator { bottom: -180; top: 180; decimals: 2 }
                        maximumLength: 6
                        Layout.maximumWidth: maximumLength * Kirigami.Units.gridUnit
                    }
                    QQC2.TextField {
                        id: biasY2
                        text: "47.83"
                        validator: DoubleValidator { bottom: -90; top: 90; decimals: 2 }
                        maximumLength: 5
                        Layout.maximumWidth: maximumLength * Kirigami.Units.gridUnit
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
                        latQuery.text = obj.lat;
                        lonQuery.text = obj.lon;
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    QQC2.TextField {
                        Layout.fillWidth: true
                        id: nameQuery
                    }
                    QQC2.Button {
                        text: "Query"
                        onClicked: {
                            locationModel.request = {
                                name: nameQuery.text,
                                backends: backendBox.checked ? [ backendSelector.currentText ] : [],
                                maximumResults: maxResults.text,
                                maximumDistance: maxDist.text,
                                types: (includeStops.checked ?  Location.Stop : Location.Place)
                                | (includeRentals.checked ? (Location.RentedVehicleStation | Location.RentedVehicle) : Location.Place)
                                | (includeEquipment.checked ? Location.Equipment : Location.Place)
                                | (includeAddresses.checked ? Location.Address: Location.Place),
                                viewbox: biasBox.checked ? Qt.rect(biasX1.text, biasY1.text, biasX2.text - biasX1.text, biasY2.text - biasY1.text) : null,
                                downloadAssets: true
                            }
                        }
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    QQC2.TextField {
                        id: latQuery
                    }
                    QQC2.TextField {
                        id: lonQuery
                    }
                    QQC2.Button {
                        text: "Query"
                        onClicked: {
                            locationModel.request = {
                                latitude: latQuery.text,
                                longitude: lonQuery.text,
                                backends: backendBox.checked ? [ backendSelector.currentText ] : [],
                                maximumResults: maxResults.text,
                                maximumDistance: maxDist.text,
                                types: (includeStops.checked ?  Location.Stop : Location.Place)
                                | (includeRentals.checked ? (Location.RentedVehicleStation | Location.RentedVehicle) : Location.Place)
                                | (includeEquipment.checked ? Location.Equipment : Location.Place)
                                | (includeAddresses.checked ? Location.Address: Location.Place)
                            }
                        }
                    }
                }

                ListView {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: locationModel
                    clip: true
                    delegate: locationDelegate

                    QQC2.BusyIndicator {
                        anchors.centerIn: parent
                        running: locationModel.loading
                    }

                    QQC2.Label {
                        anchors.centerIn: parent
                        width: parent.width
                        text: locationModel.errorMessage
                        color: Kirigami.Theme.negativeTextColor
                        wrapMode: Text.Wrap
                    }
                }

            }
        }
    }
}

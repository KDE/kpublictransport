/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import Qt.labs.platform 1.0 as Platform
import Qt.labs.settings 1.0
import org.kde.kirigami 2.12 as Kirigami
import org.kde.kpublictransport 1.0
import org.kde.example 1.0

Kirigami.ApplicationWindow {
    title: "Location Query"
    reachableModeEnabled: false

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
                iconName: "document-save"
                onTriggered: fileDialog.open();
            },
            Kirigami.Action {
                iconName: "help-about-symbolic"
                text: "Data Sources"
                enabled: locationModel.attributions.length > 0
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
        title: "Save Departure Data"
        fileMode: Platform.FileDialog.SaveFile
        nameFilters: ["JSON files (*.json)"]
        onAccepted: ExampleUtil.saveTo(locationModel, fileDialog.file);
    }

    function vehicleTypeIcon(type)
    {
        switch (type) {
            case RentalVehicle.ElectricKickScooter: return "🛴";
            case RentalVehicle.ElectricMoped: return "🛵";
            case RentalVehicle.Car: return "🚗";
            case RentalVehicle.Pedelec: return "⚡🚲";
        }
        return "🚲";
    }

    Component {
        id: locationDelegate
        Kirigami.SwipeListItem {
            actions: [
                Kirigami.Action {
                    iconName: "map-globe"
                    text: "View on OSM"
                    onTriggered: Qt.openUrlExternally("https://www.openstreetmap.org/#map=18/" + location.latitude + "/" + location.longitude)
                },
                Kirigami.Action {
                    iconName: "map-symbolic"
                    text: "Indoor Map"
                    onTriggered: pageStack.push(indoorMapPage, {coordinate: Qt.point(location.longitude, location.latitude)})
                }
            ]
            contentItem: ColumnLayout {
                id: delegateLayout
                Layout.fillWidth: true
                QQC2.Label {
                    text: {
                        switch (location.type) {
                            case Location.Stop: return "🚏 " + location.name;
                            case Location.RentedVehicleStation:
                                return '🚏' + vehicleTypeIcon(location.rentalVehicleStation.network.vehicleTypes) + ' ' + location.name;
                            case Location.RentedVehicle:
                                return vehicleTypeIcon(location.rentalVehicle.type) + ' ' + location.name;
                            case Location.Equipment:
                                switch (location.equipment.type) {
                                    case Equipment.Elevator:
                                        return '🛗 ' + location.name;
                                    case Equipment.Escalator:
                                        return '↗ ' + location.name;
                                    default:
                                        return '? ' + location.name;
                                }
                            case Location.CarpoolPickupDropoff:
                                return '🚘 ' + location.name;
                            case Location.Place: return location.name;
                        }
                    }
                    color: {
                        if (location.type == Location.Equipment) {
                            switch (location.equipment.disruptionEffect) {
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
                    text: location.streetAddress
                    visible: location.streetAddress.length > 0
                }
                QQC2.Label {
                    text: "ZIP: " + location.postalCode + " City: " + location.locality
                    visible: location.postalCode.length > 0 || location.locality.length > 0
                }
                QQC2.Label {
                    text: "Region: " + location.region + " Country: " + location.country
                    visible: location.region.length > 0 || location.country.length > 0
                }
                QQC2.Label {
                    text: "Lat: " + location.latitude + " Lon: " + location.longitude
                }
                QQC2.Label {
                    text: location.rentalVehicleStation.network.name + " (" + location.rentalVehicleStation.availableVehicles
                        + "/" + location.rentalVehicleStation.capacity + ")"
                    visible: location.rentalVehicleStation.isValid
                }
                QQC2.Label {
                    text: location.equipment ? location.equipment.notes.join("<br/>") : ''
                    visible: text != ''
                    font.italic: true
                    textFormat: Text.RichText
                }
                QQC2.Label {
                    text: "Identifiers: " + ExampleUtil.locationIds(location)
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
                }

                QQC2.ComboBox {
                    id: exampleSelector
                    Layout.fillWidth: true
                    model: exampleModel
                    textRole: "label"
                    onCurrentIndexChanged: {
                        var obj = exampleModel.get(currentIndex);
                        nameQuery.text = obj.name == undefined ? obj.label : obj.name;
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
                            locationModel.request.latitude = NaN;
                            locationModel.request.longitude = NaN;
                            locationModel.request.name = nameQuery.text;
                            locationModel.request.backends = backendBox.checked ? [ backendSelector.currentText ] : [];
                            locationModel.request.maximumResults = maxResults.text;
                            locationModel.request.maximumDistance = maxDist.text;
                            locationModel.request.types = (includeStops.checked ?  Location.Stop : Location.Place)
                                | (includeRentals.checked ? (Location.RentedVehicleStation | Location.RentedVehicle) : Location.Place)
                                | (includeEquipment.checked ? Location.Equipment : Location.Place);
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
                            locationModel.request.latitude = latQuery.text;
                            locationModel.request.longitude = lonQuery.text;
                            locationModel.request.name = "";
                            locationModel.request.backends = backendBox.checked ? [ backendSelector.currentText ] : [];
                            locationModel.request.maximumResults = maxResults.text;
                            locationModel.request.maximumDistance = maxDist.text;
                            locationModel.request.types = (includeStops.checked ?  Location.Stop : Location.Place)
                                | (includeRentals.checked ? (Location.RentedVehicleStation | Location.RentedVehicle) : Location.Place)
                                | (includeEquipment.checked ? Location.Equipment : Location.Place);
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

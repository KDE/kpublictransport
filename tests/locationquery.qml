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
import Qt.labs.settings 1.0
import org.kde.kirigami 2.0 as Kirigami
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
                iconName: "help-about-symbolic"
                text: i18n("Data Sources")
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
                    text: location.name
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

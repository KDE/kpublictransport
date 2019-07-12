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
    title: "Journey Query"
    reachableModeEnabled: false
    width: 640
    height: 800

    pageStack.initialPage: journyQueryPage

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
                enabled: _queryMgr.model.attributions.length > 0
                onTriggered: aboutSheet.sheetOpen = true;
            }
        ]
    }

    Platform.FileDialog {
        id: fileDialog
        title: i18n("Save Journey Data")
        fileMode: Platform.FileDialog.SaveFile
        nameFilters: ["JSON files (*.json)"]
        onAccepted: _queryMgr.saveTo(fileDialog.file);
    }

    TestLocationsModel { id: exampleModel }
    AttributionSheet { id: aboutSheet }

    Kirigami.OverlaySheet {
        id: locationDetailsSheet
        property var location

        header: Kirigami.Heading {
            text: "Location Details"
        }

        ColumnLayout {
            QQC2.Label {
                text: "Name: " + locationDetailsSheet.location.name
            }
            QQC2.Label {
                text: "Street:" + locationDetailsSheet.location.streetAddress
            }
            QQC2.Label {
                text: "ZIP: " + locationDetailsSheet.location.postalCode
            }
            QQC2.Label {
                text: "City: " + locationDetailsSheet.location.locality
            }
            QQC2.Label {
                text: "Region: " + locationDetailsSheet.location.region
            }
            QQC2.Label {
                text: "Country: " + locationDetailsSheet.location.country
            }
            QQC2.Label {
                text: "Lat: " + locationDetailsSheet.location.latitude
            }
            QQC2.Label {
                text: "Lon: " + locationDetailsSheet.location.longitude
            }
            QQC2.Label {
                text: "Identifiers: " + _queryMgr.locationIds(locationDetailsSheet.location)
            }
            QQC2.ToolButton {
                icon.name: "map-symbolic"
                text: "View on map"
                onClicked: Qt.openUrlExternally("https://www.openstreetmap.org/#map=18/" + locationDetailsSheet.location.latitude + "/" + locationDetailsSheet.location.longitude)
            }
        }
    }


    function displayDuration(dur)
    {
        if (dur < 60)
            return "<1min";
        if (dur < 3600)
            return Math.floor(dur/60) + "min";
        return Math.floor(dur/3600) + ":" + Math.floor((dur % 3600)/60)
    }

    Component {
        id: journeyDelegate
        Kirigami.AbstractListItem {
            RowLayout {
                id: topLayout

                Rectangle {
                    id: colorBar
                    width: Kirigami.Units.largeSpacing
                    color: modelData.route.line.hasColor ? modelData.route.line.color : "transparent"
                    Layout.fillHeight: true
                }

                QQC2.Label {
                    text: {
                        switch (modelData.mode) {
                            case JourneySection.PublicTransport:
                            {
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
                                break;
                            }
                            case JourneySection.Walking: return "🚶";
                            case JourneySection.Waiting: return "⌛";
                            case JourneySection.Transfer: return "⇄";
                            default: return "?";
                        }
                    }
                    font.pointSize: Kirigami.Theme.defaultFont.pointSize * 2
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    RowLayout {
                        QQC2.Label {
                            text: "From: <a href=\"#from\">" + modelData.from.name + "</a> Platform: " + modelData.scheduledDeparturePlatform
                            onLinkActivated: {
                                locationDetailsSheet.location = modelData.from;
                                locationDetailsSheet.sheetOpen = true;
                            }
                        }
                        QQC2.Label {
                            text: modelData.expectedDeparturePlatform
                            color: modelData.departurePlatformChanged ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                            visible: modelData.hasExpectedDeparturePlatform
                        }
                    }
                    RowLayout {
                        QQC2.Label {
                            text: "Departure: " + modelData.scheduledDepartureTime.toTimeString()
                        }
                        QQC2.Label {
                            text: (modelData.departureDelay >= 0 ? "+" : "") + modelData.departureDelay
                            color: modelData.departureDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                            visible: modelData.hasExpectedDepartureTime
                        }
                    }
                    QQC2.Label {
                        Layout.fillWidth: true
                        text: {
                            switch (modelData.mode) {
                            case JourneySection.PublicTransport:
                                return modelData.route.line.modeString + " " + modelData.route.line.name + " " + displayDuration(modelData.duration);
                            case JourneySection.Walking:
                                return "Walk " + displayDuration(modelData.duration)
                            case JourneySection.Transfer:
                                return "Transfer " + displayDuration(modelData.duration)
                            case JourneySection.Waiting:
                                return "Wait " + displayDuration(modelData.duration)
                            return "???";
                        }}
                    }
                    RowLayout {
                        QQC2.Label {
                            text: "To: <a href=\"#to\">" + modelData.to.name + "</a> Platform: " + modelData.scheduledArrivalPlatform
                            onLinkActivated: {
                                locationDetailsSheet.location = modelData.to;
                                locationDetailsSheet.sheetOpen = true;
                            }
                        }
                        QQC2.Label {
                            text: modelData.expectedArrivalPlatform
                            color: modelData.arrivalPlatformChanged ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                            visible: modelData.hasExpectedArrivalPlatform
                        }
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
                    }
                }
            }
        }
    }

    Component {
        id: journyQueryPage
        Kirigami.Page {
            ColumnLayout {
                anchors.fill: parent
                QQC2.CheckBox {
                    text: "Allow insecure backends"
                    onToggled: _queryMgr.setAllowInsecure(checked)
                }
                QQC2.CheckBox {
                    id: searchDirection
                    text: checked ? "Time is arrival" : "Time is departure"
                }
                QQC2.ComboBox {
                    id: fromSelector
                    Layout.fillWidth: true
                    model: exampleModel
                    textRole: "label"
                    onCurrentIndexChanged: {
                        var obj = exampleModel.get(currentIndex);
                        fromName.text = obj.name == undefined ? obj.label : obj.name;
                        fromLon.text = obj.lon;
                        fromLat.text = obj.lat;
                        if (toSelector.currentIndex == currentIndex) {
                            toSelector.currentIndex = (currentIndex + 1) % count;
                        }
                    }
                }
                RowLayout {
                    QQC2.TextField {
                        id: fromName
                    }
                    QQC2.TextField {
                        id: fromLon
                    }
                    QQC2.TextField {
                        id: fromLat
                    }
                }

                QQC2.ComboBox {
                    id: toSelector
                    Layout.fillWidth: true
                    model: exampleModel
                    textRole: "label"
                    onCurrentIndexChanged: {
                        var obj = exampleModel.get(currentIndex);
                        toName.text = obj.name == undefined ? obj.label : obj.name;
                        toLon.text = obj.lon;
                        toLat.text = obj.lat;
                        if (fromSelector.currentIndex == currentIndex) {
                            fromSelector.currentIndex = (currentIndex - 1 + count) % count;
                        }
                    }
                }
                RowLayout {
                    QQC2.TextField {
                        id: toName
                    }
                    QQC2.TextField {
                        id: toLon
                    }
                    QQC2.TextField {
                        id: toLat
                    }
                }
                RowLayout {
                    QQC2.Button {
                        text: "Query"
                        onClicked: _queryMgr.findJourney(fromName.text, fromLat.text, fromLon.text, toName.text, toLat.text, toLon.text, searchDirection.checked);
                    }
                    QQC2.Button {
                        text: "Query Name"
                        onClicked: _queryMgr.findJourney(fromName.text, NaN, NaN, toName.text, NaN, NaN, searchDirection.checked);
                    }
                    QQC2.Button {
                        text: "Query Coord"
                        onClicked: _queryMgr.findJourney("", fromLat.text, fromLon.text, "", toLat.text, toLon.text, searchDirection.checked);
                    }
                    QQC2.Button {
                        text: "Clear"
                        onClicked: {
                            fromName.text = "";
                            fromLon.text = "";
                            fromLat.text = "";
                            toName.text = "";
                            toLon.text = "";
                            toLat.text = "";
                        }
                    }
                }

                RowLayout {
                    QQC2.ToolButton {
                        id: prevQueryButton
                        icon.name: "go-previous"
                        enabled: _queryMgr.model.canQueryPrevious
                        onClicked: _queryMgr.model.queryPrevious()
                    }
                    QQC2.ComboBox {
                        id: journeySelector
                        Layout.fillWidth: true
                        model: _queryMgr.titleModel
                        textRole: "display"
                    }
                    QQC2.ToolButton {
                        id: nextQueryButton
                        icon.name: "go-next"
                        enabled: _queryMgr.model.canQueryNext
                        onClicked: _queryMgr.model.queryNext()
                    }
                }

                ListView {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: _queryMgr.model.data(_queryMgr.model.index(journeySelector.currentIndex, 0), 256).sections
                    clip: true
                    delegate: journeyDelegate

                    QQC2.BusyIndicator {
                        anchors.centerIn: parent
                        running: _queryMgr.model.loading
                    }

                    QQC2.Label {
                        anchors.centerIn: parent
                        width: parent.width
                        text: _queryMgr.model.errorMessage
                        color: Kirigami.Theme.negativeTextColor
                        wrapMode: Text.Wrap
                    }
                }

            }
        }
    }
}

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
    title: "Journey Query"
    reachableModeEnabled: false
    width: 640
    height: 800

    pageStack.initialPage: journyQueryPage

    Manager {
        id: ptMgr;
    }
    Settings {
        id: settings
        property alias allowInsecureBackends: ptMgr.allowInsecureBackends
        property alias enabledBackends: ptMgr.enabledBackends
        property alias disabledBackends: ptMgr.disabledBackends
    }

    JourneyQueryModel {
        id: journeyModel
        manager: ptMgr
    }

    JourneyTitleModel {
        id: titleModel
        sourceModel: journeyModel
    }

    globalDrawer: Kirigami.GlobalDrawer {
        actions: [
            Kirigami.Action {
                text: i18n("Save...")
                iconName: "document-save"
                onTriggered: fileDialog.open();
            },
            Kirigami.Action {
                iconName: "help-about-symbolic"
                text: i18n("Current Data Sources")
                enabled: journeyModel.attributions.length > 0
                onTriggered: {
                    aboutSheet.attributions = Qt.binding(function() { return journeyModel.attributions; });
                    aboutSheet.sheetOpen = true;
                }
            },
            Kirigami.Action {
                iconName: "help-about-symbolic"
                text: i18n("All Data Sources")
                onTriggered: {
                    aboutSheet.attributions = Qt.binding(function() { return ptMgr.attributions; });
                    aboutSheet.sheetOpen = true;
                }
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
        title: i18n("Save Journey Data")
        fileMode: Platform.FileDialog.SaveFile
        nameFilters: ["JSON files (*.json)"]
        onAccepted: ExampleUtil.saveTo(journeyModel, fileDialog.file);
    }

    TestLocationsModel { id: exampleModel }
    AttributionSheet { id: aboutSheet }
    LocationDetailsSheet { id:locationDetailsSheet }

    function displayDuration(dur)
    {
        if (dur < 60)
            return "<1min";
        if (dur < 3600)
            return Math.floor(dur/60) + "min";
        return Math.floor(dur/3600) + ":" + Math.floor((dur % 3600)/60)
    }

    function displayDistance(dist)
    {
        if (dist == 0)
            return "";
        if (dist < 1000)
            return dist + "m";
        return Math.floor(dist/1000) + "km";
    }

    function locationName(loc)
    {
        switch(loc.type) {
            case Location.Stop: return "🚏 " + loc.name;
            case Location.RentedVehicleStation: return "🚲 " + loc.name;
            case Location.Place: return loc.name;
        }
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
        id: journeyDelegate
        Kirigami.AbstractListItem {
            enabled: modelData.disruptionEffect != Disruption.NoService
            highlighted: false
            RowLayout {
                id: topLayout

                Kirigami.Icon {
                    id: icon
                    source: modelData.route.line.hasLogo ? modelData.route.line.logo : modelData.route.line.modeLogo
                    width: height
                    height: Kirigami.Units.iconSizes.large
                    visible: source != ""
                }

                Rectangle {
                    id: colorBar
                    width: Kirigami.Units.largeSpacing
                    color: modelData.route.line.hasColor ? modelData.route.line.color : "transparent"
                    Layout.fillHeight: true
                    visible: icon.source == ""
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
                                    case Line.RideShare: return "🚗";
                                    default: return "?";
                                }
                                break;
                            }
                            case JourneySection.Walking: return "🚶";
                            case JourneySection.Waiting: return "⌛";
                            case JourneySection.Transfer: return "⇄";
                            case JourneySection.RentedVehicle:
                            {
                                switch (modelData.rentalVehicle.type) {
                                    case RentalVehicle.Bicycle: return "🚲";
                                    case RentalVehicle.Pedelec: return "🚲";
                                    case RentalVehicle.ElectricKickScooter: return "🛴";
                                    case RentalVehicle.ElectricMoped: return "🛵";
                                    case RentalVehicle.Car: return "🚗";
                                    default: return "?";
                                }
                            }
                            default: return "?";
                        }
                    }
                    font.pointSize: Kirigami.Theme.defaultFont.pointSize * 2
                    visible: icon.source == ""
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    RowLayout {
                        QQC2.Label {
                            text: "From: <a href=\"#from\">" + locationName(modelData.from) + "</a> Platform: " + modelData.scheduledDeparturePlatform
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
                        QQC2.Label {
                            text: "<a href=\"#layout\">vehicle</a>"
                            visible: modelData.route.line.mode == Line.LongDistanceTrain
                            onLinkActivated: applicationWindow().pageStack.push(vehicleLayoutPage, {"departure": modelData.departure });
                            Layout.fillWidth: true
                            horizontalAlignment: Text.Right
                        }
                    }
                    QQC2.Label {
                        Layout.fillWidth: true
                        text: {
                            switch (modelData.mode) {
                            case JourneySection.PublicTransport:
                                return modelData.route.line.modeString + " " + modelData.route.line.name + " " + displayDuration(modelData.duration) + " / " + displayDistance(modelData.distance)
                            case JourneySection.Walking:
                                return "Walk " + displayDuration(modelData.duration) + " / " + displayDistance(modelData.distance)
                            case JourneySection.Transfer:
                                return "Transfer " + displayDuration(modelData.duration)  + " / " + displayDistance(modelData.distance)
                            case JourneySection.Waiting:
                                return "Wait " + displayDuration(modelData.duration)
                            case JourneySection.RentedVehicle:
                                return modelData.rentalVehicle.network.name;
                            return "???";
                        }}
                    }
                    RowLayout {
                        QQC2.Label {
                            text: "To: <a href=\"#to\">" + locationName(modelData.to) + "</a> Platform: " + modelData.scheduledArrivalPlatform
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
                        QQC2.Label {
                            text: "<a href=\"#layout\">vehicle</a>"
                            visible: modelData.route.line.mode == Line.LongDistanceTrain
                            onLinkActivated: applicationWindow().pageStack.push(vehicleLayoutPage, {"departure": modelData.arrival });
                            Layout.fillWidth: true
                            horizontalAlignment: Text.Right
                        }
                    }
                    RowLayout {
                        visible: modelData.loadInformation.length > 0
                        QQC2.Label {
                            text: "Load: ";
                        }
                        Repeater {
                            model: modelData.loadInformation
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
                        text: modelData.notes.join("<br/>")
                        textFormat: Text.RichText
                        visible: modelData.notes.length > 0
                        font.italic: true
                    }
                }
            }
            onClicked: {
                if (modelData.mode == JourneySection.PublicTransport) {
                    applicationWindow().pageStack.push(journeySectionPathPage, {"journeySection": modelData});
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
        id: journeySectionPathPage
        JourneySectionPage {}
    }

    Component {
        id: journyQueryPage
        Kirigami.Page {
            Settings {
                id: settings
                property alias singleBackend: backendBox.checked
                property alias backend: backendSelector.currentIndex
                property alias maxResults: maxResults.text
                property alias includeIntermediateStops: intermediateStops.checked
                property alias includePaths: includePaths.checked
            }

            ColumnLayout {
                anchors.fill: parent
                QQC2.CheckBox {
                    id: searchDirection
                    text: checked ? "Time is arrival" : "Time is departure"
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
                    QQC2.CheckBox {
                        id: ptMode
                        checked: true
                        text: "Public Transport"
                    }
                    QQC2.CheckBox {
                        id: rentalMode
                        checked: true
                        text: "Retal Vehicles"
                    }
                }
                RowLayout {
                    QQC2.Label { text: "Results:" }
                    QQC2.TextField {
                        id: maxResults
                        text: "10"
                    }
                    QQC2.CheckBox {
                        id: intermediateStops
                        checked: true
                        text: "Intermediate stops"
                    }
                    QQC2.CheckBox {
                        id: includePaths
                        text: "Paths"
                    }
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
                        onClicked: {
                            var from = journeyModel.request.from;
                            from.name = fromName.text;
                            from.latitude = fromLat.text;
                            from.longitude = fromLon.text;
                            journeyModel.request.from = from;
                            var to = journeyModel.request.to;
                            to.name = toName.text;
                            to.latitude = toLat.text;
                            to.longitude = toLon.text;
                            journeyModel.request.to = to;
                            journeyModel.request.dateTimeMode = searchDirection.checked ? JourneyRequest.Arrival : JourneyRequest.Departure;
                            journeyModel.request.dateTime = new Date(new Date().getTime() + (searchDirection.checked ? 7200000 : 0));
                            journeyModel.request.backends = backendBox.checked ? [ backendSelector.currentText ] : [];
                            journeyModel.request.downloadAssets = true
                            journeyModel.request.modes = (ptMode.checked ?  JourneySection.PublicTransport : JourneySection.Invalid)
                                | (rentalMode.checked ? JourneySection.RentedVehicle : JourneySection.Invalid);
                            journeyModel.request.maximumResults = maxResults.text;
                            journeyModel.request.includeIntermediateStops = intermediateStops.checked;
                            journeyModel.request.includePaths = includePaths.checked;
                        }
                    }
                    QQC2.Button {
                        text: "Query Name"
                        onClicked: {
                            var from = journeyModel.request.from;
                            from.name = fromName.text;
                            from.latitude = NaN;
                            from.longitude = NaN;
                            journeyModel.request.from = from;
                            var to = journeyModel.request.to;
                            to.name = toName.text;
                            to.latitude = NaN;
                            to.longitude = NaN;
                            journeyModel.request.to = to;
                            journeyModel.request.dateTimeMode = searchDirection.checked ? JourneyRequest.Arrival : JourneyRequest.Departure;
                            journeyModel.request.dateTime = new Date(new Date().getTime() + (searchDirection.checked ? 7200000 : 0));
                            journeyModel.request.backends = backendBox.checked ? [ backendSelector.currentText ] : [];
                            journeyModel.request.downloadAssets = true
                            journeyModel.request.modes = (ptMode.checked ?  JourneySection.PublicTransport : JourneySection.Invalid)
                                | (rentalMode.checked ? JourneySection.RentedVehicle : JourneySection.Invalid);
                            journeyModel.request.maximumResults = maxResults.text;
                            journeyModel.request.includeIntermediateStops = intermediateStops.checked;
                            journeyModel.request.includePaths = includePaths.checked;
                        }
                    }
                    QQC2.Button {
                        text: "Query Coord"
                        onClicked: {
                            var from = journeyModel.request.from;
                            from.name = "";
                            from.latitude = fromLat.text;
                            from.longitude = fromLon.text;
                            journeyModel.request.from = from;
                            var to = journeyModel.request.to;
                            to.name = "";
                            to.latitude = toLat.text;
                            to.longitude = toLon.text;
                            journeyModel.request.to = to;
                            journeyModel.request.dateTimeMode = searchDirection.checked ? JourneyRequest.Arrival : JourneyRequest.Departure;
                            journeyModel.request.dateTime = new Date(new Date().getTime() + (searchDirection.checked ? 7200000 : 0));
                            journeyModel.request.backends = backendBox.checked ? [ backendSelector.currentText ] : [];
                            journeyModel.request.downloadAssets = true
                            journeyModel.request.modes = (ptMode.checked ?  JourneySection.PublicTransport : JourneySection.Invalid)
                                | (rentalMode.checked ? JourneySection.RentedVehicle : JourneySection.Invalid);
                            journeyModel.request.maximumResults = maxResults.text;
                            journeyModel.request.includeIntermediateStops = intermediateStops.checked;
                            journeyModel.request.includePaths = includePaths.checked;
                        }
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
                        enabled: journeyModel.canQueryPrevious
                        onClicked: journeyModel.queryPrevious()
                    }
                    QQC2.ComboBox {
                        id: journeySelector
                        Layout.fillWidth: true
                        model: titleModel
                        textRole: "display"
                    }
                    QQC2.ToolButton {
                        id: nextQueryButton
                        icon.name: "go-next"
                        enabled: journeyModel.canQueryNext
                        onClicked: journeyModel.queryNext()
                    }
                }

                ListView {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: journeyModel.data(journeyModel.index(journeySelector.currentIndex, 0), 256).sections
                    clip: true
                    delegate: journeyDelegate

                    QQC2.BusyIndicator {
                        anchors.centerIn: parent
                        running: journeyModel.loading
                    }

                    QQC2.Label {
                        anchors.centerIn: parent
                        width: parent.width
                        text: journeyModel.errorMessage
                        color: Kirigami.Theme.negativeTextColor
                        wrapMode: Text.Wrap
                    }
                }

            }
        }
    }
}

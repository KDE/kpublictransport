/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtCore
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import QtQuick.Dialogs as Dialogs
import org.kde.coreaddons as KCoreAddons
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport
import org.kde.kpublictransport.ui
import org.kde.example

Kirigami.ApplicationWindow {
    title: "Journey Query"
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
                text: "Save..."
                icon.name: "document-save"
                onTriggered: fileDialog.open();
            },
            Kirigami.Action {
                icon.name: "help-about-symbolic"
                text: "Current Data Sources"
                enabled: journeyModel.attributions.length > 0
                onTriggered: {
                    aboutSheet.attributions = Qt.binding(function() { return journeyModel.attributions; });
                    aboutSheet.open();
                }
            },
            Kirigami.Action {
                icon.name: "help-about-symbolic"
                text: "All Data Sources"
                onTriggered: {
                    aboutSheet.attributions = Qt.binding(function() { return ptMgr.attributions; });
                    aboutSheet.open();
                }
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
        title: "Save Journey Data"
        fileMode: Dialogs.FileDialog.SaveFile
        nameFilters: ["JSON files (*.json)"]
        onAccepted: ExampleUtil.saveTo(journeyModel, fileDialog.selectedFile);
    }

    TestLocationsModel { id: exampleModel }
    AttributionSheet { id: aboutSheet }
    LocationDetailsSheet { id:locationDetailsSheet }

    function locationName(loc)
    {
        switch(loc.type) {
            case Location.Stop: return "🚏 " + loc.name;
            case Location.RentedVehicleStation: return "🚏🚲 " + loc.name;
            case Location.RentedVehicle: return "🚲 " + loc.name;
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
        id: journeyMapPage
        JourneyMapPage {}
    }
    Component {
        id: tripPage
        TripPage {}
    }

    Component {
        id: journeyDelegate
        QQC2.ItemDelegate {
            id: delegateRoot
            required property journeySection modelData

            enabled: modelData.disruptionEffect != Disruption.NoService
            highlighted: false
            width: ListView.view.width
            contentItem: RowLayout {
                id: topLayout

                Rectangle {
                    id: colorBar
                    width: Kirigami.Units.largeSpacing
                    color: delegateRoot.modelData.route.line.hasColor ? delegateRoot.modelData.route.line.color :
                        delegateRoot.modelData.rentalVehicle.network.hasBrandColor ? delegateRoot.modelData.rentalVehicle.network.brandColor : "transparent"
                    Layout.fillHeight: true
                }

                TransportIcon {
                    id: icon
                    source: modelData.iconName
                    iconHeight: Kirigami.Units.iconSizes.smallMedium
                    visible: source != ""
                }

                ColumnLayout {
                    Layout.fillWidth: true
                    RowLayout {
                        QQC2.Label {
                            text: "From: <a href=\"#from\">" + locationName(modelData.from) + "</a> Platform: " + modelData.scheduledDeparturePlatform
                            onLinkActivated: {
                                locationDetailsSheet.location = modelData.from;
                                locationDetailsSheet.open();
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
                            text: "Departure:"
                        }
                        ExpectedTimeLabel {
                            stopover: modelData.departure
                            scheduledTime: KCoreAddons.Format.formatTime(modelData, "scheduledDepartureTime", Locale.ShortFormat, KCoreAddons.FormatTypes.AddTimezoneAbbreviationIfNeeded)
                            delay: modelData.departureDelay
                            hasExpectedTime: modelData.hasExpectedDepartureTime
                        }
                        QQC2.Label {
                            text: "<a href=\"#layout\">vehicle</a>"
                            visible: modelData.route.line.mode == Line.LongDistanceTrain || modelData.route.line.mode == Line.Train || modelData.route.name !== ""
                            onLinkActivated: applicationWindow().pageStack.push(vehicleLayoutPage, {"departure": modelData.departure });
                            Layout.fillWidth: true
                            horizontalAlignment: Text.Right
                        }
                    }
                    QQC2.Label {
                        Layout.fillWidth: true
                        text: {
                            let bookingLink = "";
                            if (delegateRoot.modelData.bookingUrl != "") {
                                bookingLink = " <a href=\"" + delegateRoot.modelData.bookingUrl + "\">Book section</a>";
                            }
                            switch (delegateRoot.modelData.mode) {
                            case JourneySection.PublicTransport:
                            {
                                if (delegateRoot.modelData.route.name !== "") {
                                    return delegateRoot.modelData.route.line.modeString + " " + delegateRoot.modelData.route.line.name + " (" + delegateRoot.modelData.route.name
                                        + ") " + KCoreAddons.Format.formatDuration(delegateRoot.modelData.duration * 1000, KCoreAddons.FormatTypes.HideSeconds) + " / " + KCoreAddons.Format.formatDistance(delegateRoot.modelData.distance) + " <a href=\"#trip\">trip</a>" + bookingLink;
                                }
                                return delegateRoot.modelData.route.line.modeString + " " + delegateRoot.modelData.route.line.name + " " + KCoreAddons.Format.formatDuration(delegateRoot.modelData.duration * 1000, KCoreAddons.FormatTypes.HideSeconds) + " / " + KCoreAddons.Format.formatDistance(delegateRoot.modelData.distance) + " <a href=\"#trip\">trip</a>" + bookingLink;
                            }
                            case JourneySection.Walking:
                                return "Walk " + KCoreAddons.Format.formatDuration(delegateRoot.modelData.duration * 1000, KCoreAddons.FormatTypes.HideSeconds) + " / " + KCoreAddons.Format.formatDistance(delegateRoot.modelData.distance)
                            case JourneySection.Transfer:
                                return "Transfer " + KCoreAddons.Format.formatDuration(delegateRoot.modelData.duration * 1000, KCoreAddons.FormatTypes.HideSeconds)  + " / " + KCoreAddons.Format.formatDistance(delegateRoot.modelData.distance)
                            case JourneySection.Waiting:
                                return "Wait " + KCoreAddons.Format.formatDuration(delegateRoot.modelData.duration * 1000, KCoreAddons.FormatTypes.HideSeconds)
                            case JourneySection.RentedVehicle:
                                return "Drive (<a href=\""+ delegateRoot.modelData.rentalVehicle.network.url + "\">" + delegateRoot.modelData.rentalVehicle.network.name + "</a>) " + KCoreAddons.Format.formatDuration(delegateRoot.modelData.duration * 1000, KCoreAddons.FormatTypes.HideSeconds) + " / " + KCoreAddons.Format.formatDistance(delegateRoot.modelData.distance) + bookingLink;
                            case JourneySection.IndividualTransport:
                                return "Drive " + KCoreAddons.Format.formatDuration(delegateRoot.modelData.duration * 1000, KCoreAddons.FormatTypes.HideSeconds) + " / " + KCoreAddons.Format.formatDistance(delegateRoot.modelData.distance) + bookingLink;
                            }
                            return "???";
                        }
                        onLinkActivated: (link) => { link.startsWith("#") ? delegateRoot.ListView.view.showTrip(delegateRoot.modelData) : Qt.openUrlExternally(link); }
                    }
                    RowLayout {
                        QQC2.Label {
                            text: "To: <a href=\"#to\">" + locationName(modelData.to) + "</a> Platform: " + modelData.scheduledArrivalPlatform
                            onLinkActivated: {
                                locationDetailsSheet.location = modelData.to;
                                locationDetailsSheet.open();
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
                            text: "Arrival:"
                        }
                        ExpectedTimeLabel {
                            stopover: modelData.departure
                            scheduledTime: KCoreAddons.Format.formatTime(modelData, "scheduledArrivalTime", Locale.ShortFormat, KCoreAddons.FormatTypes.AddTimezoneAbbreviationIfNeeded)
                            delay: modelData.arrivalDelay
                            hasExpectedTime: modelData.hasExpectedArrivalTime
                        }
                        QQC2.Label {
                            text: "<a href=\"#layout\">vehicle</a>"
                            visible: modelData.route.line.mode == Line.LongDistanceTrain
                            onLinkActivated: applicationWindow().pageStack.push(vehicleLayoutPage, {"departure": modelData.arrival });
                            Layout.fillWidth: true
                            horizontalAlignment: Text.Right
                        }
                    }
                    QQC2.Label {
                        text: delegateRoot.modelData.route.line.operatorName + " <a href=\"" + delegateRoot.modelData.route.line.operatorUrl + "\">" + delegateRoot.modelData.route.line.operatorUrl + "</a>"
                        visible: text !== ""
                        onLinkActivated: (link) => { Qt.openUrlExternally(link); }
                    }
                    RowLayout {
                        Repeater {
                            model: modelData.features
                            delegate: FeatureIcon {
                                feature: modelData
                                Layout.preferredHeight: Kirigami.Units.iconSizes.small
                                Layout.preferredWidth: Kirigami.Units.iconSizes.small
                            }
                        }
                    }
                    RowLayout {
                        visible: modelData.loadInformation.length > 0
                        Repeater {
                            model: modelData.loadInformation
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
                        text: modelData.notes.join("<br/>")
                        textFormat: Text.RichText
                        visible: modelData.notes.length > 0
                        font.italic: true
                    }
                }
            }
            onClicked: {
                if (modelData.mode == JourneySection.PublicTransport) {
                    applicationWindow().pageStack.push(journeySectionPage, {"journeySection": modelData});
                } else if (modelData.path.sectionCount > 1) {
                    applicationWindow().pageStack.push(pathPage, {"path": modelData.path});
                }
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
        id: journeySectionPage
        JourneySectionPage {}
    }

    Component {
        id: pathPage
        PathPage {}
    }

    readonly property var individualTransportModes: [
        [{ mode: IndividualTransport.Walk }],
        [{ mode: IndividualTransport.Bike }],
        [{ mode: IndividualTransport.Bike, qualifier: IndividualTransport.Park }],
        [{ mode: IndividualTransport.Bike, qualifier: IndividualTransport.Rent }],
        [{ mode: IndividualTransport.Car, qualifier: IndividualTransport.Park }],
        [{ mode: IndividualTransport.Car, qualifier: IndividualTransport.Rent }],
        [{ mode: IndividualTransport.Car, qualifier: IndividualTransport.Pickup }],
        [{ mode: IndividualTransport.Car, qualifier: IndividualTransport.Dropoff }],
    ]
    ListModel {
        id: individualTransportModesModel
        ListElement { name: "Walk" }
        ListElement { name: "Take Bike" }
        ListElement { name: "Park Bike" }
        ListElement { name: "Rent Bike" }
        ListElement { name: "Park Car" }
        ListElement { name: "Rent Car" }
        ListElement { name: "Pickup by car" }
        ListElement { name: "Drop-off by car" }
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
                property alias accessMode: accessMode.currentIndex
                property alias egressMode: egressMode.currentIndex
                property alias walkMode: walkMode.checked
                property alias ptMode: ptMode.checked
                property alias rentalMode: rentalMode.checked
                property alias bikeMode: bikeMode.checked
                property alias carMode: carMode.checked
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
                        id: walkMode
                        checked: true
                        text: "Walk"
                    }
                    QQC2.CheckBox {
                        id: ptMode
                        checked: true
                        text: "Public Transport"
                    }
                    QQC2.CheckBox {
                        id: rentalMode
                        checked: true
                        text: "Rental Vehicles"
                    }
                    QQC2.CheckBox {
                        id: bikeMode
                        checked: false
                        text: "Bike (direct)"
                    }
                    QQC2.CheckBox {
                        id: carMode
                        checked: false
                        text: "Car (direct)"
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
                    id: accessMode
                    Layout.fillWidth: true
                    model: individualTransportModesModel
                    textRole: "name"
                }
                QQC2.ComboBox {
                    id: fromSelector
                    Layout.fillWidth: true
                    model: exampleModel
                    textRole: "label"
                    onCurrentIndexChanged: {
                        var obj = exampleModel.get(currentIndex);
                        fromName.text = obj.name == "" ? obj.label : obj.name;
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
                        toName.text = obj.name == "" ? obj.label : obj.name;
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
                QQC2.ComboBox {
                    id: egressMode
                    Layout.fillWidth: true
                    model: individualTransportModesModel
                    textRole: "name"
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
                            case 5: return [Line.Bus, Line.Coach];
                        }
                        return [];
                    }
                }

                RowLayout {
                    function setupRequestCommon()
                    {
                        return {
                            dateTimeMode: searchDirection.checked ? JourneyRequest.Arrival : JourneyRequest.Departure,
                            dateTime: new Date(new Date().getTime() + (searchDirection.checked ? 7200000 : 0)),
                            backends: backendBox.checked ? [ backendSelector.currentText ] : [],
                            downloadAssets: true,
                            modes: (ptMode.checked ?  JourneySection.PublicTransport : JourneySection.Invalid)
                            | (rentalMode.checked ? JourneySection.RentedVehicle : JourneySection.Invalid)
                            | (walkMode.checked ? JourneySection.Walking : JourneySection.Invalid)
                            | ((bikeMode.checked || carMode.checked) ? JourneySection.IndividualTransport : JourneySection.Invalid),
                            maximumResults: maxResults.text,
                            includeIntermediateStops: intermediateStops.checked,
                            includePaths: includePaths.checked,
                            accessModes: individualTransportModes[accessMode.currentIndex],
                            egressModes: individualTransportModes[egressMode.currentIndex],
                            lineModes: lineModeSelector.currentMode,
                            individualTransportModes: (() => {
                                let modes = [];
                                if (walkMode.checked)
                                    modes.push({mode: IndividualTransport.Walk})
                                if (bikeMode.checked)
                                    modes.push({mode: IndividualTransport.Bike});
                                if (carMode.checked)
                                    modes.push({mode: IndividualTransport.Car});
                                return modes;
                            })()
                        };
                    }

                    QQC2.Button {
                        text: "Query"
                        onClicked: {
                            let r = parent.setupRequestCommon();
                            r.from = {
                                name: fromName.text,
                                latitude: fromLat.text,
                                longitude: fromLon.text,
                            };
                            r.to = {
                                name: toName.text,
                                latitude: toLat.text,
                                longitude: toLon.text,
                            };
                            journeyModel.request = r;
                        }
                    }
                    QQC2.Button {
                        text: "Query Name"
                        onClicked: {
                            let r = parent.setupRequestCommon();
                            r.from = {
                                name: fromName.text,
                            };
                            r.to = {
                                name: toName.text,
                            };
                            journeyModel.request = r;
                        }
                    }
                    QQC2.Button {
                        text: "Query Coord"
                        onClicked: {
                            let r = parent.setupRequestCommon();
                            r.from = {
                                latitude: fromLat.text,
                                longitude: fromLon.text,
                            };
                            r.to = {
                                latitude: toLat.text,
                                longitude: toLon.text,
                            };
                            journeyModel.request = r;
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

                    function showTrip(jnySec: journeySection) {
                        applicationWindow().pageStack.push(tripPage, {
                            requestedJourneySection: jnySec,
                            backendIds: backendBox.checked ? [ backendSelector.currentText ] : [],
                            ptMgr: ptMgr
                        });
                    }

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

                    footer: RowLayout {
                        QQC2.Button {
                            text: "Map view"
                            visible: journeySelector.currentIndex >= 0
                            onClicked: applicationWindow().pageStack.push(journeyMapPage, {journey: journeyModel.data(journeyModel.index(journeySelector.currentIndex, 0), 256)});
                        }
                        QQC2.Button {
                            text: "Book journey"
                            visible: {
                                const jny = journeyModel.data(journeyModel.index(journeySelector.currentIndex, 0), 256);
                                return jny != undefined && jny.bookingUrl != ""
                            }
                            onClicked: Qt.openUrlExternally(journeyModel.data(journeyModel.index(journeySelector.currentIndex, 0), 256).bookingUrl)
                        }
                    }
                }

            }
        }
    }
}

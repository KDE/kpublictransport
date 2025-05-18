/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kirigami.delegates as KirigamiDelegates
import org.kde.kirigamiaddons.components as KirigamiComponents
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport
import org.kde.kosmindoormap as KOSM

Kirigami.Page {
    id: root
    title: "Stopover Details"

    required property KPublicTransport.Manager ptMgr
    required property KPublicTransport.stopover stopover
    required property var backendIds

    KPublicTransport.VehicleLayoutQueryModel {
        id: vehicleModel
        manager: root.ptMgr
        // TODO move flickable offset
        onContentChanged: {
            root.stopover = vehicleModel.stopover;
        }
    }

    ColumnLayout {
        anchors.fill: parent

        GridLayout {
            columns: 3
            rows: 3

            KPublicTransport.TransportNameControl {
                Layout.rowSpan: 3
                line: root.stopover.route.line
            }

            QQC2.Label {
                Layout.row: 0
                Layout.column: 1
                Layout.fillWidth: true
                text: "<b>" + root.stopover.route.line.modeString + " " + root.stopover.route.line.name + "</b> at " + root.stopover.stopPoint.name + " · Platform: " + (root.stopover.hasExpectedPlatform ? root.stopover.expectedPlatform : root.stopover.scheduledPlatform)
            }

            QQC2.Label {
                Layout.row: 1
                Layout.column: 1
                text: "Direction: " + root.stopover.route.direction
            }

            // TODO arrival support
            KPublicTransport.ExpectedTimeLabel {
                Layout.row: 2
                Layout.column: 1
                stopover: root.stopover
                scheduledTime: root.stopover.scheduledDepartureTime.toTimeString()
                delay: root.stopover.departureDelay
                hasExpectedTime: root.stopover.hasExpectedDepartureTime
            }

            QQC2.Label {
                Layout.row: 1
                Layout.column: 2
                Layout.rowSpan: 2
                text: root.stopover.expectedDepartureTime.toTimeString()
            }
        }

        QQC2.TabBar {
            id: tabBar
            Layout.fillWidth: true
            QQC2.TabButton { text: "Information" }
            QQC2.TabButton { text: "Trip" }
            QQC2.TabButton { text: "Trip Map" }
            QQC2.TabButton { text: "Vehicle" }
            QQC2.TabButton { text: "Stop Map" }
        }

        StackLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            currentIndex: tabBar.currentIndex
            QQC2.ScrollView {
                id: infoPage
                contentWidth: width - effectiveScrollBarWidth
                ColumnLayout {
                    width: infoPage.width - infoPage.effectiveScrollBarWidth

                    Kirigami.Heading {
                        text: "Information"
                        level: 4
                    }
                    QQC2.Label {
                        text: root.stopover.notes.join("<br/>")
                        textFormat: Text.RichText
                        font.italic: true
                        wrapMode: Text.WordWrap
                        Layout.fillWidth: true
                        // TODO handle links
                    }

                    Kirigami.Heading {
                        text: "Occupancy"
                        level: 4
                    }
                    Repeater {
                        model: root.stopover.loadInformation
                        RowLayout {
                            id: loadDelegateRoot
                            required property KPublicTransport.loadInfo modelData
                            KPublicTransport.OccupancyIndicator {
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

                    Kirigami.Heading {
                        text: "Amenities"
                        level: 4
                    }
                    // TODO copied from Itinerary's PublicTransportFeatureList, should be an upstream component?
                    Repeater {
                        model: root.stopover.vehicleLayout.combinedFeatures
                        delegate: RowLayout {
                            Layout.leftMargin: Kirigami.Units.largeSpacing
                            KPublicTransport.FeatureIcon {
                                id: featureIcon
                                feature: modelData
                                Layout.preferredHeight: Kirigami.Units.iconSizes.smallMedium
                                Layout.preferredWidth: Kirigami.Units.iconSizes.smallMedium
                            }
                            KirigamiDelegates.TitleSubtitle {
                                Layout.fillWidth: true
                                enabled: modelData.availability !== KPublicTransport.Feature.Unavailable
                                title: modelData.displayName
                                subtitle: {
                                    if (modelData.description !== "")
                                        return modelData.description;
                                    if (modelData.availability === KPublicTransport.Feature.Unknown)
                                        return i18n("Availability unknown")
                                    if (modelData.availability === KPublicTransport.Feature.Unavailable)
                                        return i18n("Not available")
                                    if (modelData.disruptionEffect === KPublicTransport.Disruption.NoService)
                                        return i18n("Currently not available")
                                    if (modelData.quantity > 0)
                                        return i18np("One space", "%1 spaces", modelData.quantity);
                                    return "";
                                }
                            }
                        }
                    }

                    Kirigami.Heading {
                        text: "Operator"
                        level: 4
                    }
                    QQC2.Label {
                        text: root.stopover.route.line.operatorName
                    }
                }
            }
            ListView {
                id: tripView
                clip: true
                property KPublicTransport.journeySection journeySection
                header: JourneySectionStopDelegate {
                    stop: tripView.journeySection.departure
                }

                delegate: JourneySectionStopDelegate {
                    stop: modelData
                }

                footer: JourneySectionStopDelegate {
                    stop: tripView.journeySection.arrival
                }

                model: journeySection.intermediateStops

                QQC2.Label {
                    id: errorMessage
                    anchors.centerIn: parent
                    width: parent.width
                    color: Kirigami.Theme.negativeTextColor
                    wrapMode: Text.Wrap
                }
            }
            JourneySectionMap {
                // TODO intermediate stops missing??
                id: tripMapView
                journey: tripView.journeySection
            }
            QQC2.ScrollView {
                id: vehicleLayout
                KPublicTransport.VehicleLayoutView {
                    model: vehicleModel
                    width: vehicleLayout.width - vehicleLayout.effectiveScrollBarWidth
                    onVehicleSectionTapped: (section) => { console.log(section.name); }
                }
            }
            KOSM.IndoorMap {
                id: stopMapView
                overlaySources: [ platformModel ]

                KOSM.IndoorMapScale {
                    map: stopMapView
                    anchors.left: map.left
                    anchors.bottom: map.bottom
                    width: 0.3 * map.width
                }
                KOSM.IndoorMapAttributionLabel {
                    anchors.right: stopMapView.right
                    anchors.bottom: stopMapView.bottom
                }

                KOSM.OSMElementInformationModel {
                    id: infoModel
                    debug: true
                    allowOnlineContent: true
                }
                KOSM.FloorLevelChangeModel {
                    id: floorLevelChangeModel
                    currentFloorLevel: stopMapView.view.floorLevel
                    floorLevelModel: stopMapView.floorLevels
                }

                KOSM.OSMElementInformationDialog {
                    id: elementDetailsSheet
                    model: infoModel
                    regionCode: stopMapView.mapData.regionCode
                    timeZone: stopMapView.mapData.timeZone
                }
                KOSM.FloorLevelSelector {
                    id: elevatorSheet
                    model: floorLevelChangeModel
                    onFloorLevelSelected: (level) => { stopMapView.view.floorLevel = level; }
                }

                KOSM.PlatformModel {
                    id: platformModel
                    mapData: stopMapView.mapData

                    onPlatformIndexChanged: {
                        if (platformModel.departurePlatformRow >= 0) {
                            const idx = platformModel.index(platformModel.departurePlatformRow, 0);
                            stopMapView.view.floorLevel = platformModel.data(idx, KOSM.PlatformModel.LevelRole)
                            stopMapView.view.setZoomLevel(19, Qt.point(stopMapView.width / 2.0, stopMapView.height / 2.0));
                            stopMapView.view.centerOnGeoCoordinate(platformModel.data(idx, KOSM.PlatformModel.CoordinateRole));
                        }
                    }
                }

                onElementPicked: (element) => {
                    floorLevelChangeModel.element = element;
                    if (floorLevelChangeModel.hasSingleLevelChange) {
                        showPassiveNotification("Switched to floor " + floorLevelChangeModel.destinationLevelName, "short");
                        stopMapView.view.floorLevel = floorLevelChangeModel.destinationLevel;
                        return;
                    } else if (floorLevelChangeModel.hasMultipleLevelChanges) {
                        elevatorSheet.open();
                        return;
                    }

                    infoModel.element = element;
                    if (infoModel.name != "" || infoModel.debug) {
                        elementDetailsSheet.open();
                    }
                }

                KirigamiComponents.DoubleFloatingButton {
                    anchors {
                        right: parent.right
                        rightMargin: Kirigami.Units.largeSpacing
                        bottom: parent.bottom
                        bottomMargin: Kirigami.Units.largeSpacing + Kirigami.Units.smallSpacing // to not hide the copyright information
                    }

                    leadingAction: Kirigami.Action {
                        icon.name: "go-down-symbolic"
                        text: "Floor down"
                        enabled: stopMapView.floorLevels.hasFloorLevelBelow(stopMapView.view.floorLevel)
                        onTriggered: stopMapView.view.floorLevel = stopMapView.floorLevels.floorLevelBelow(stopMapView.view.floorLevel)
                        visible: stopMapView.floorLevels.hasFloorLevels
                        tooltip: text
                    }

                    trailingAction: Kirigami.Action {
                        icon.name: "go-up-symbolic"
                        text: "Floor up"
                        enabled: stopMapView.floorLevels.hasFloorLevelAbove(stopMapView.view.floorLevel)
                        onTriggered: stopMapView.view.floorLevel = stopMapView.floorLevels.floorLevelAbove(stopMapView.view.floorLevel)
                        visible: stopMapView.floorLevels.hasFloorLevels
                        tooltip: text
                    }
                }
            }
        }
    }

    // TODO trigger this only when opening the trip tab for the first time?
    Component.onCompleted: {
        errorMessage.text = "Loading..."
        let reply = ptMgr.queryTrip({ stopover: root.stopover, backendIds: root.backendIds, downloadAssets: true })
        reply.finished.connect(() => {
            if (reply.error === KPublicTransport.Reply.NoError) {
                errorMessage.text = ""
                tripView.journeySection = reply.trip;
                root.stopover = reply.stopover;
                tripMapView.centerOnJourney();
                vehicleModel.request.stopover = reply.stopover;
                // TODO platform, times, platform sections
                stopMapView.mapLoader.loadForCoordinate(root.stopover.stopPoint.latitude, root.stopover.stopPoint.longitude);
                platformModel.departurePlatform.name = root.stopover.hasExpectedPlatform ? root.stopover.expectedPlatform : root.stopover.scheduledPlatform
                // platformModel.departurePlatform.mode
                platformModel.departurePlatform.ifopt = root.stopover.stoppoint.identifier("ifopt")

            } else {
                errorMessage.text = reply.errorString;
            }
            reply.destroy();
        });
    }
}

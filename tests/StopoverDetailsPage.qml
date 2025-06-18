/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport
import org.kde.kosmindoormap as KOSM

Kirigami.Page {
    id: root
    title: "Stopover Details"

    required property KPublicTransport.Manager ptMgr
    required property KPublicTransport.stopover stopover
    required property var backendIds // ### should be list<string> but that gives us an empty list here no matter what's passed in

    property bool isArrival: false

    KPublicTransport.VehicleLayoutQueryModel {
        id: vehicleModel
        manager: root.ptMgr
        onContentChanged: {
            root.stopover = vehicleModel.stopover;
            tabBar.selectFirstEnabledTab();
        }
    }

    ColumnLayout {
        anchors.fill: parent

        GridLayout {
            columns: 3
            rows: 3

            KPublicTransport.TransportNameControl {
                id: lineLabel
                Layout.rowSpan: 3
                line: root.stopover.route.line
                opacity: loadingSpinner.running ? 0.75 : 1.0

                QQC2.BusyIndicator {
                    id: loadingSpinner
                    anchors.centerIn: lineLabel
                    running: vehicleModel.loading && root.stopover.hasTripIdentifiers
                }
            }

            QQC2.Label {
                Layout.row: 0
                Layout.column: 1
                Layout.fillWidth: true
                text: {
                    let s = "<b>" + root.stopover.route.line.modeString + " " + root.stopover.route.line.name;
                    if (root.stopover.route.name !== "")
                        s+= " (" + root.stopover.route.name + ")";
                    s += "</b> at " + root.stopover.stopPoint.name + " · Platform: " + (root.stopover.hasExpectedPlatform ? root.stopover.expectedPlatform : root.stopover.scheduledPlatform)
                    return s;
                }
            }

            QQC2.Label {
                Layout.row: 1
                Layout.column: 1
                text: (root.isArrival ? "From: " : "Direction: ") + root.stopover.route.direction
            }

            KPublicTransport.ExpectedTimeLabel {
                Layout.row: 2
                Layout.column: 1
                stopover: root.stopover
                scheduledTime: root.isArrival ? root.stopover.scheduledArrivalTime.toTimeString() : root.stopover.scheduledDepartureTime.toTimeString()
                delay: root.isArrival ? root.stopover.arrivalDelay : root.stopover.departureDelay
                hasExpectedTime: root.isArrival ? root.stopover.hasExpectedArrivalTime : root.stopover.hasExpectedDepartureTime
            }

            QQC2.Label {
                Layout.row: 1
                Layout.column: 2
                Layout.rowSpan: 2
                text: root.isArrival ?  root.stopover.expectedArrivalTime.toTimeString() : root.stopover.expectedDepartureTime.toTimeString()
            }
        }

        QQC2.TabBar {
            id: tabBar
            Layout.fillWidth: true
            QQC2.TabButton {
                text: "Information"
                enabled: infoView.hasContent
            }
            QQC2.TabButton {
                text: "Trip"
                enabled: tripView.journeySection.mode !== KPublicTransport.JourneySection.Invalid
            }
            QQC2.TabButton {
                text: "Trip Map"
                enabled: tripView.journeySection.mode !== KPublicTransport.JourneySection.Invalid
            }
            QQC2.TabButton {
                text: "Vehicle"
                enabled: root.stopover.vehicleLayout.sections.length > 0
            }
            QQC2.TabButton {
                text: "Stop Map"
                enabled: root.stopover.stopPoint.hasCoordinate
            }

            function selectFirstEnabledTab() {
                if (tabBar.itemAt(tabBar.currentIndex).enabled)
                    return;
                for (let i = 0; i < tabBar.count; ++i) {
                    if (tabBar.itemAt(i).enabled) {
                        tabBar.currentIndex = i;
                        break;
                    }
                }
            }

            onCurrentIndexChanged: {
                // trip map view on-demand loading
                if (tabBar.currentIndex === 2 && tripView.journeySection.mode !== KPublicTransport.JourneySection.Invalid && tripMapView.journey.mode === KPublicTransport.JourneySection.Invalid) {
                    tripMapView.journey = tripView.journeySection;
                    tripMapView.centerOnJourney();
                }
                // position vehicle layout at the start of the train if not modified yet
                if (tabBar.currentIndex === 3 && vehicleLayout.contentItem.contentY === 0) {
                    let offset = vehicleView.fullLength * vehicleModel.vehicle.platformPositionBegin;
                    offset -= Kirigami.Units.iconSizes.small + Kirigami.Units.largeSpacing; // direction indicator
                    vehicleLayout.contentItem.contentY = offset;
                }
                // indoor map view on-demand loading
                if (tabBar.currentIndex === 4 && stopMapView.mapData.isEmpty && !stopMapView.mapLoader.isLoading && root.stopover.stopPoint.hasCoordinate) {
                    stopMapView.mapLoader.loadForCoordinate(root.stopover.stopPoint.latitude, root.stopover.stopPoint.longitude);
                    root.updateStopMap();
                }
            }
        }

        StackLayout {
            Layout.fillHeight: true
            Layout.fillWidth: true
            currentIndex: tabBar.currentIndex

            QQC2.ScrollView {
                id: infoPage
                contentWidth: width - effectiveScrollBarWidth
                QQC2.ScrollBar.horizontal.policy: QQC2.ScrollBar.AlwaysOff

                KPublicTransport.StopoverInformationView {
                    id: infoView
                    width: infoPage.width - infoPage.effectiveScrollBarWidth
                    stopover: root.stopover
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
            }
            JourneySectionMap {
                id: tripMapView
            }
            QQC2.ScrollView {
                id: vehicleLayout
                QQC2.ScrollBar.horizontal.policy: QQC2.ScrollBar.AlwaysOff
                KPublicTransport.VehicleLayoutView {
                    id: vehicleView
                    model: vehicleModel
                    width: vehicleLayout.width - vehicleLayout.effectiveScrollBarWidth
                    onVehicleSectionTapped: (section) => { console.log(section.name); }
                }
            }
            KOSM.IndoorMapView {
                id: stopMapView
                overlaySources: [ platformModel, stopMapView.equipmentModel ]

                KOSM.PlatformModel {
                    id: platformModel
                    mapData: stopMapView.mapData

                    onPlatformIndexChanged: {
                        if (platformModel.departurePlatformRow >= 0) {
                            const idx = platformModel.index(platformModel.departurePlatformRow, 0);
                            stopMapView.view.centerOn(platformModel.data(idx, KOSM.PlatformModel.CoordinateRole), platformModel.data(idx, KOSM.PlatformModel.LevelRole), 19);
                        }
                    }
                }
            }
        }
    }

    function updateStopMap() {
        // TODO platform, times, platform sections
        platformModel.departurePlatform.name = root.stopover.hasExpectedPlatform ? root.stopover.expectedPlatform : root.stopover.scheduledPlatform
        switch (root.stopover.route.line.mode) {
            case KPublicTransport.Line.Metro:
                platformModel.departurePlatform.mode = KOSM.Platform.Subway;
                break;
            case KPublicTransport.Line.Tramway:
                platformModel.departurePlatform.mode = KOSM.Platform.Tram;
                break;
            case KPublicTransport.Line.Bus:
            case KPublicTransport.Line.Coach:
            case KPublicTransport.Line.Shuttle:
                platformModel.departurePlatform.mode = KOSM.Platform.Bus;
                break;
        }
        platformModel.departurePlatform.ifopt = root.stopover.stopPoint.identifier("ifopt")
    }

    Component.onCompleted: {
        let reply = ptMgr.queryTrip({ stopover: root.stopover, backendIds: root.backendIds, downloadAssets: true })
        reply.finished.connect(() => {
            loadingSpinner.running = Qt.binding(() => { return vehicleModel.loading; });
            if (reply.error === KPublicTransport.Reply.NoError) {
                tripView.journeySection = reply.trip;
                root.stopover = reply.stopover;
                vehicleModel.request.stopover = reply.stopover;
                vehicleModel.request.backendIds = root.backendIds;
                tabBar.selectFirstEnabledTab();
                root.updateStopMap();
            } else {
                showPassiveNotification(reply.errorString);
            }
            reply.destroy();
        });

        tabBar.selectFirstEnabledTab();
    }
}

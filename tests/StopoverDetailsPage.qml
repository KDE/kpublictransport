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
    required property list<string> backendIds

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
                QQC2.ScrollBar.horizontal.policy: QQC2.ScrollBar.AlwaysOff
                KPublicTransport.VehicleLayoutView {
                    model: vehicleModel
                    width: vehicleLayout.width - vehicleLayout.effectiveScrollBarWidth
                    onVehicleSectionTapped: (section) => { console.log(section.name); }
                }
            }
            KOSM.IndoorMapView {
                id: stopMapView
                overlaySources: [ platformModel ]

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

    // TODO trigger this only when opening the trip tab for the first time?
    Component.onCompleted: {
        errorMessage.text = "Loading..."

        if (root.stopover.stopPoint.hasCoordinate) {
            stopMapView.mapLoader.loadForCoordinate(root.stopover.stopPoint.latitude, root.stopover.stopPoint.longitude);
            updateStopMap();
        }

        let reply = ptMgr.queryTrip({ stopover: root.stopover, backendIds: root.backendIds, downloadAssets: true })
        reply.finished.connect(() => {
            if (reply.error === KPublicTransport.Reply.NoError) {
                errorMessage.text = ""
                tripView.journeySection = reply.trip;
                if (!root.stopover.stopPoint.hasCoordinate && reply.stopover.stopPoint.hasCoordinate) {
                    stopMapView.mapLoader.loadForCoordinate(reply.stopover.stopPoint.latitude, reply.stopover.stopPoint.longitude);
                }
                root.stopover = reply.stopover;
                tripMapView.centerOnJourney();
                vehicleModel.request.stopover = reply.stopover;
                vehicleModel.request.backendIds = root.backendIds;
                root.updateStopMap();
            } else {
                errorMessage.text = reply.errorString;
            }
            reply.destroy();
        });
    }
}

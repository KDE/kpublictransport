/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport
import org.kde.kpublictransport.ui

Kirigami.Page {
    id: root
    property journeySection journeySection

    ColumnLayout {
        anchors.fill: parent
        spacing: Kirigami.Units.largeSpacing

        GridLayout {
            Layout.fillWidth: true
            Layout.margins: Kirigami.Units.largeSpacing
            columns: 3
            rows: 5

            TransportNameControl {
                Layout.rowSpan: 4
                id: icon
                journeySection: root.journeySection
            }

            QQC2.Label {
                Layout.row: 0
                Layout.column: 1
                Layout.fillWidth: true
                text: "<b>" + journeySection.route.line.modeString + " " + journeySection.route.line.name + "</b>"
            }

            QQC2.Label {
                Layout.row: 0
                Layout.column: 2
                text: "<a href=\"#layout\">vehicle</a>"
                visible: journeySection.route.line.mode == Line.LongDistanceTrain
                onLinkActivated: applicationWindow().pageStack.push(vehicleLayoutPage, {"departure": journeySection.departure});
            }

            QQC2.Label {
                Layout.row: 1
                Layout.column: 1
                Layout.columnSpan: 2
                text: "Direction: " + journeySection.route.direction
            }

            QQC2.Label {
                Layout.row: 2
                Layout.column: 1
                Layout.columnSpan: 2
                text: "Distance: " + journeySection.distance / 1000.0 + "km"
            }
            QQC2.Label {
                Layout.row: 3
                Layout.column: 1
                Layout.columnSpan: 2
                text: "CO₂: " + journeySection.co2Emission + "g"
                visible: journeySection.co2Emission >= 0
            }
            RowLayout {
                Layout.row: 4
                Layout.column: 1
                Layout.columnSpan: 2
                visible: journeySection.features.length > 0
                Repeater {
                    model: journeySection.features
                    delegate: FeatureIcon {
                        feature: modelData
                        Layout.preferredHeight: Kirigami.Units.iconSizes.small
                        Layout.preferredWidth: Kirigami.Units.iconSizes.small
                    }
                }
            }
        }

        ListView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            clip: true
            header: RowLayout {
                enabled: journeySection.departure.disruptionEffect != Disruption.NoService
                width: parent.width - 2 * Kirigami.Units.largeSpacing
                x: Kirigami.Units.largeSpacing
                Rectangle {
                    Layout.fillHeight: true
                    width: Kirigami.Units.largeSpacing
                    color: journeySection.route.line.hasColor ? journeySection.route.line.color : Kirigami.Theme.textColor
                }

                QQC2.Label {
                    text: journeySection.scheduledDepartureTime.toTimeString()
                }
                QQC2.Label {
                    text: (journeySection.departureDelay >= 0 ? "+" : "") + journeySection.departureDelay
                    color: journeySection.departureDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                    visible: journeySection.hasExpectedDepartureTime
                }

                QQC2.Label {
                    Layout.fillWidth: true
                    text: "<a href=\"#loc\">" + journeySection.from.name + "</a>"
                    onLinkActivated: {
                        locationDetailsSheet.location = journeySection.from;
                        locationDetailsSheet.open();
                    }
                }

                QQC2.Label {
                    text: journeySection.hasExpectedDeparturePlatform ? journeySection.expectedDeparturePlatform : journeySection.scheduledDeparturePlatform
                    color: JourneySection.hasExpectedDeparturePlatform ? (journeySection.departurePlatformChanged ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor) : Kirigami.Theme.textColor
                }
            }

            delegate: QQC2.ItemDelegate {
                property var stop: modelData
                enabled: stop.disruptionEffect != Disruption.NoService
                highlighted: false
                width: ListView.view.width
                contentItem: GridLayout {
                    columns: 5
                    rows: 4
                    Rectangle {
                        Layout.column: 0
                        Layout.row: 0
                        Layout.fillHeight: true
                        Layout.rowSpan: 4
                        width: Kirigami.Units.largeSpacing
                        color: stop.route.line.hasColor ? stop.route.line.color : Kirigami.Theme.textColor
                    }

                    QQC2.Label {
                        Layout.column: 1
                        Layout.row: 0
                        text: stop.scheduledArrivalTime.toTimeString()
                    }
                    QQC2.Label {
                        Layout.column: 2
                        Layout.row: 0
                        text: (stop.arrivalDelay >= 0 ? "+" : "") + stop.arrivalDelay
                        color: stop.arrivalDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                        visible: stop.hasExpectedArrivalTime
                    }

                    QQC2.Label {
                        Layout.column: 3
                        Layout.row: 0
                        Layout.rowSpan: loadData.visible ? 1 : 2
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                        text: "<a href=\"#loc\">" + stop.stopPoint.name + "</a>" + (stop.route.line.mode == Line.LongDistanceTrain ? " (<a href=\"#layout\">vehicle</a>)" : "")
                        verticalAlignment: Qt.AlignVCenter
                        onLinkActivated: {
                            if (link == "#loc") {
                                locationDetailsSheet.location = stop.stopPoint;
                                locationDetailsSheet.open();
                            } else if (link == "#layout") {
                                applicationWindow().pageStack.push(vehicleLayoutPage, {"departure": stop });
                            }
                        }
                    }

                    RowLayout {
                        id: loadData
                        Layout.column: 3
                        Layout.row: 1
                        Layout.fillWidth: true
                        visible: stop.loadInformation.length > 0
                        QQC2.Label {
                            text: "Load: ";
                        }
                        Repeater {
                            model: stop.loadInformation
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
                        Layout.column: 1
                        Layout.row: 1
                        text: stop.scheduledDepartureTime.toTimeString()
                    }
                    QQC2.Label {
                        Layout.column: 2
                        Layout.row: 1
                        text: (stop.departureDelay >= 0 ? "+" : "") + stop.departureDelay
                        color: stop.departureDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                        visible: stop.hasExpectedDepartureTime
                    }

                    QQC2.Label {
                        Layout.column: 4
                        Layout.row: 0
                        Layout.rowSpan: 2
                        Layout.fillHeight: true
                        verticalAlignment: Qt.AlignVCenter
                        text: stop.hasExpectedPlatform ? stop.expectedPlatform : stop.scheduledPlatform
                        color: stop.hasExpectedPlatform ? (stop.platformChanged ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor) : Kirigami.Theme.textColor
                    }

                    QQC2.Label {
                        Layout.column: 1
                        Layout.row: 2
                        Layout.columnSpan: 3
                        text: stop.notes.join("<br/>")
                        textFormat: Text.RichText
                        visible: stop.notes.length > 0
                        font.italic: true
                    }
                }
            }

            footer: RowLayout {
                enabled: journeySection.arrival.disruptionEffect != Disruption.NoService
                width: parent.width - 2 * Kirigami.Units.largeSpacing
                x: Kirigami.Units.largeSpacing
                Rectangle {
                    Layout.fillHeight: true
                    width: Kirigami.Units.largeSpacing
                    color: journeySection.route.line.hasColor ? journeySection.route.line.color : Kirigami.Theme.textColor
                }

                QQC2.Label {
                    text: journeySection.scheduledArrivalTime.toTimeString()
                }
                QQC2.Label {
                    text: (journeySection.arrivalDelay >= 0 ? "+" : "") + journeySection.arrivalDelay
                    color: journeySection.arrivalDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
                    visible: journeySection.hasExpectedArrivalTime
                }

                QQC2.Label {
                    Layout.fillWidth: true
                    text: "<a href=\"#loc\">" + journeySection.to.name + "</a>"
                    onLinkActivated: {
                        locationDetailsSheet.location = journeySection.to;
                        locationDetailsSheet.open();
                    }
                }

                QQC2.Label {
                    text: journeySection.hasExpectedArrivalPlatform ? journeySection.expectedArrivalPlatform : journeySection.scheduledArrivalPlatform
                    color: JourneySection.hasExpectedArrivalPlatform ? (journeySection.arrivalPlatformChanged ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor) : Kirigami.Theme.textColor
                }
            }

            model: journeySection.intermediateStops
        }
    }
}

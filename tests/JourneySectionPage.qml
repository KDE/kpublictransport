/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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
import org.kde.kirigami 2.0 as Kirigami
import org.kde.kpublictransport 1.0

Kirigami.Page {
    property var journeySection

    ColumnLayout {
        anchors.fill: parent
        spacing: Kirigami.Units.largeSpacing

        GridLayout {
            Layout.fillWidth: true
            Layout.margins: Kirigami.Units.largeSpacing
            columns: 3
            rows: 4

            Kirigami.Icon {
                Layout.rowSpan: 4
                id: icon
                source: journeySection.route.line.hasLogo ? journeySection.route.line.logo : journeySection.route.line.modeLogo
                width: height
                height: Kirigami.Units.iconSizes.large
                visible: source != ""
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
        }

        ListView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            clip: true
            header: RowLayout {
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
                        locationDetailsSheet.sheetOpen = true;
                    }
                }

                QQC2.Label {
                    text: journeySection.hasExpectedDeparturePlatform ? journeySection.expectedDeparturePlatform : journeySection.scheduledDeparturePlatform
                    color: JourneySection.hasExpectedDeparturePlatform ? (journeySection.departurePlatformChanged ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor) : Kirigami.Theme.textColor
                }
            }

            delegate: Kirigami.AbstractListItem {
                property var stop: modelData
                highlighted: false
                GridLayout {
                    columns: 5
                    rows: 2
                    Rectangle {
                        Layout.column: 0
                        Layout.row: 0
                        Layout.fillHeight: true
                        Layout.rowSpan: 2
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
                                locationDetailsSheet.sheetOpen = true;
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
                }
            }

            footer: RowLayout {
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
                        locationDetailsSheet.sheetOpen = true;
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

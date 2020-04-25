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
    ListView {
        anchors.fill: parent
        header: RowLayout {
            Rectangle {
                Layout.fillHeight: true
                width: Kirigami.Units.largeSpacing
                color: journeySection.route.line.color
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
                columns: 4
                rows: 2
                Rectangle {
                    Layout.column: 0
                    Layout.row: 0
                    Layout.fillHeight: true
                    Layout.rowSpan: 2
                    width: Kirigami.Units.largeSpacing
                    color: stop.route.line.color
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
                    Layout.fillWidth: true
                    text: "<a href=\"#loc\">" + stop.stopPoint.name + "</a>"
                    onLinkActivated: {
                        locationDetailsSheet.location = stop.stopPoint;
                        locationDetailsSheet.sheetOpen = true;
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
                    Layout.column: 3
                    Layout.row: 1
                    Layout.fillWidth: true
                    horizontalAlignment: Qt.AlignRight
                    text: stop.hasExpectedPlatform ? stop.expectedPlatform : stop.scheduledPlatform
                    color: stop.hasExpectedPlatform ? (stop.platformChanged ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor) : Kirigami.Theme.textColor
                }
            }
        }

        footer: RowLayout {
            Rectangle {
                Layout.fillHeight: true
                width: Kirigami.Units.largeSpacing
                color: journeySection.route.line.color
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
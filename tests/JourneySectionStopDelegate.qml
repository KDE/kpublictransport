/*
    SPDX-FileCopyrightText: ⓒ 2020 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.coreaddons as KCoreAddons
import org.kde.kpublictransport
import org.kde.kpublictransport.ui

QQC2.ItemDelegate {
    id: root
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

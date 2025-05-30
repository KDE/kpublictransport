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
    enabled: stop.disruptionEffect != Disruption.NoService || (stop.pickupType === PickupDropoff.NotAllowed && stop.dropoffType === PickupDropoff.NotAllowed)
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
            Layout.preferredWidth: Kirigami.Units.largeSpacing
            color: root.stop.route.line.hasColor ? stop.route.line.color : Kirigami.Theme.textColor
        }

        QQC2.Label {
            Layout.column: 1
            Layout.row: 0
            text: root.stop.scheduledArrivalTime.toTimeString()
            font.strikeout: root.stop.disruptionEffect === Disruption.NoService
            opacity: stop.dropoffType === PickupDropoff.NotAllowed ? 0.5 : 1.0
        }
        QQC2.Label {
            Layout.column: 2
            Layout.row: 0
            text: (root.stop.arrivalDelay >= 0 ? "+" : "") + stop.arrivalDelay
            color: root.stop.arrivalDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
            visible: root.stop.hasExpectedArrivalTime
            font.strikeout: root.stop.disruptionEffect === Disruption.NoService
        }

        QQC2.Label {
            Layout.column: 3
            Layout.row: 0
            Layout.rowSpan: loadData.visible ? 1 : 2
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "<a href=\"#loc\">" + root.stop.stopPoint.name + "</a>" + (root.stop.route.line.mode == Line.LongDistanceTrain ? " (<a href=\"#layout\">vehicle</a>)" : "")
            verticalAlignment: Qt.AlignVCenter
            font.strikeout: root.stop.disruptionEffect === Disruption.NoService
            onLinkActivated: (link) => {
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
            visible: root.stop.aggregatedOccupancy.length > 0
            QQC2.Label {
                text: "Load: ";
            }
            Repeater {
                model: root.stop.aggregatedOccupancy
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
            text: root.stop.scheduledDepartureTime.toTimeString()
            font.strikeout: root.stop.disruptionEffect === Disruption.NoService
            opacity: root.stop.pickupType === PickupDropoff.NotAllowed ? 0.5 : 1.0
        }
        QQC2.Label {
            Layout.column: 2
            Layout.row: 1
            text: (root.stop.departureDelay >= 0 ? "+" : "") + stop.departureDelay
            color: root.stop.departureDelay > 1 ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
            visible: root.stop.hasExpectedDepartureTime
            font.strikeout: root.stop.disruptionEffect === Disruption.NoService
        }

        QQC2.Label {
            Layout.column: 4
            Layout.row: 0
            Layout.rowSpan: 2
            Layout.fillHeight: true
            verticalAlignment: Qt.AlignVCenter
            text: root.stop.hasExpectedPlatform ? stop.expectedPlatform : stop.scheduledPlatform
            color: root.stop.hasExpectedPlatform ? (stop.platformChanged ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor) : Kirigami.Theme.textColor
        }

        QQC2.Label {
            Layout.column: 1
            Layout.row: 2
            Layout.columnSpan: 3
            text: root.stop.notes.join("<br/>")
            textFormat: Text.RichText
            visible: root.stop.notes.length > 0
            font.italic: true
        }
    }
}

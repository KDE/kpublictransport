/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.coreaddons as KCoreAddons
import org.kde.kpublictransport
import org.kde.kpublictransport.ui

Kirigami.Page {
    id: root
    property journeySection journeySection

    Component {
        id: sectionMapPage
        Kirigami.Page {
            property alias journey: map.journey
            topPadding: 0
            bottomPadding: 0
            leftPadding: 0
            rightPadding: 0
            JourneySectionMap {
                id: map
                anchors.fill: parent
            }
        }
    }

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
                text: "Direction: " + root.journeySection.route.direction + " <a href=\"#layout\">map</a>"
                onLinkActivated: (link) => { applicationWindow().pageStack.push(sectionMapPage, {journey: root.journeySection}); }
            }

            QQC2.Label {
                Layout.row: 2
                Layout.column: 1
                Layout.columnSpan: 2
                text: "Distance: " + KCoreAddons.Format.formatDistance(root.journeySection.distance)
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
            header: JourneySectionStopDelegate {
                stop: journeySection.departure
            }

            delegate: JourneySectionStopDelegate {
                stop: modelData
            }

            footer: JourneySectionStopDelegate {
                stop: journeySection.arrival
            }

            model: journeySection.intermediateStops
        }
    }
}

/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui

Kirigami.ScrollablePage {
    id: root
    title: "Vehicle Layout"

    property alias publicTransportManager: vehicleModel.manager
    property var departure

    onDepartureChanged: vehicleModel.request.stopover = root.departure;

    KPublicTransport.VehicleLayoutQueryModel {
        id: vehicleModel

        onContentChanged: {
            var offset = vehicleView.fullLength * vehicleModel.vehicle.platformPositionBegin;
            offset -= Kirigami.Units.iconSizes.small + Kirigami.Units.largeSpacing; // direction indicator
            root.flickable.contentY = offset;
        }
    }

    header: Column {
        QQC2.Label {
            text: vehicleModel.stopover.stopPoint.name + " - " + vehicleModel.stopover.route.line.name + " - "
                + (vehicleModel.stopover.scheduledDepartureTime > 0 ? vehicleModel.stopover.scheduledDepartureTime : vehicleModel.stopover.scheduledArrivalTime)
            leftPadding: Kirigami.Units.largeSpacing
            topPadding: Kirigami.Units.largeSpacing
        }
        QQC2.Label {
            text: "Platform: " + vehicleModel.platform.name
            leftPadding: Kirigami.Units.largeSpacing
        }
        RowLayout {
            x: Kirigami.Units.largeSpacing
            spacing: Kirigami.Units.largeSpacing
            Repeater {
                model: vehicleModel.vehicle.combinedFeatures
                delegate: FeatureIcon {
                    feature: modelData
                    Layout.preferredHeight: Kirigami.Units.iconSizes.small
                    Layout.preferredWidth: Kirigami.Units.iconSizes.small
                }
            }
        }
    }

    Item {
        width: parent.width
        height: childrenRect.height

        Column {
            id: contentLayout
            width: parent.width

            Repeater {
                id: vehicleView
                property real fullLength: 1600 // full length of the platform display
                property real sectionWidth: 48

                model: vehicleModel.platform.sections
                delegate: Item {
                    property var section: modelData
                    width: parent.width
                    height: (section.end - section.begin) * vehicleView.fullLength

                    Kirigami.Separator {
                        visible: index == 0
                        anchors { top: parent.top; left: parent.left; right: parent.right }
                    }
                    QQC2.Label {
                        anchors.centerIn: parent
                        text: section.name
                    }
                    Kirigami.Separator {
                        anchors { bottom: parent.bottom; left: parent.left; right: parent.right }
                    }
                }
            }
        }

        Kirigami.Icon {
            visible: vehicleModel.vehicle.direction != KPublicTransport.Vehicle.UnknownDirection
            source: {
                if (vehicleModel.vehicle.direction == KPublicTransport.Vehicle.Forward)
                    return "go-up";
                if (vehicleModel.vehicle.direction == KPublicTransport.Vehicle.Backward)
                    return "go-down"
                return "";
            }
            width: Kirigami.Units.iconSizes.small
            height: width
            x: vehicleView.sectionWidth / 2 - width / 2
            y: vehicleModel.vehicle.platformPositionBegin * vehicleView.fullLength - height - Kirigami.Units.largeSpacing
        }

        Repeater {
            id: vehicleRepeater
            Layout.fillWidth: true
            model: vehicleModel
            delegate: VehicleSectionItem {
                section: model.vehicleSection
                y: section.platformPositionBegin * vehicleView.fullLength
                height: section.platformPositionEnd * vehicleView.fullLength - y
                width: vehicleView.sectionWidth
                textColor: Kirigami.Theme.textColor
                firstClassBackground: Kirigami.Theme.positiveTextColor
                secondClassBackground: Kirigami.Theme.focusColor
                inaccessibleBackground: Kirigami.Theme.disabledTextColor
                restaurantBackground: Kirigami.Theme.neutralTextColor

                QQC2.Label {
                    anchors.centerIn: parent
                    text: section.name
                }

                ColumnLayout {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.right
                    anchors.leftMargin: Kirigami.Units.largeSpacing
                    spacing: Kirigami.Units.smallSpacing

                    RowLayout {
                        spacing: Kirigami.Units.largeSpacing
                        Repeater {
                            model: section.sectionFeatures
                            delegate: FeatureIcon {
                                feature: modelData
                                Layout.preferredHeight: Kirigami.Units.iconSizes.small
                                Layout.preferredWidth: Kirigami.Units.iconSizes.small
                            }
                        }
                    }
                    QQC2.Label {
                        visible: section.classes != KPublicTransport.VehicleSection.UnknownClass
                        text: {
                            if (section.classes == KPublicTransport.VehicleSection.FirstClass)
                                return "First class";
                            if (section.classes == KPublicTransport.VehicleSection.SecondClass)
                                return "Second class";
                            if (section.classes == (KPublicTransport.VehicleSection.FirstClass | KPublicTransport.VehicleSection.SecondClass))
                                return "First/second class";
                            return "Unknown class";
                        }
                    }
                    QQC2.Label {
                        visible: section.type == KPublicTransport.VehicleSection.SleepingCar || section.type == KPublicTransport.VehicleSection.CouchetteCar
                        text: section.type == KPublicTransport.VehicleSection.SleepingCar ? "Sleeping car" : "Couchette car"
                    }
                }
            }
        }

        Kirigami.Icon {
            visible: vehicleModel.vehicle.direction != KPublicTransport.Vehicle.UnknownDirection
            source: {
                if (vehicleModel.vehicle.direction == KPublicTransport.Vehicle.Forward)
                    return "go-up";
                if (vehicleModel.vehicle.direction == KPublicTransport.Vehicle.Backward)
                    return "go-down"
                return "";
            }
            width: Kirigami.Units.iconSizes.small
            height: width
            x: vehicleView.sectionWidth / 2 - width / 2
            y: vehicleModel.vehicle.platformPositionEnd * vehicleView.fullLength + Kirigami.Units.largeSpacing
        }

        QQC2.BusyIndicator {
            anchors.centerIn: contentLayout
            running: vehicleModel.loading
        }

        QQC2.Label {
            anchors.centerIn: contentLayout
            width: parent.width
            text: vehicleModel.errorMessage
            color: Kirigami.Theme.negativeTextColor
            wrapMode: Text.Wrap
            horizontalAlignment: Text.AlignHCenter
        }

        QQC2.Label {
            anchors.centerIn: contentLayout
            width: parent.width
            visible: vehicleModel.errorMessage === "" && !vehicleModel.loading && vehicleRepeater.count === 0
            wrapMode: Text.Wrap
            horizontalAlignment: Text.AlignHCenter
            text: "No vehicle layout information available."
        }
    }

    Component.onCompleted: contentItem.clip = true
}

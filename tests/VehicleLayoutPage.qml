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
    property KPublicTransport.stopover departure

    onDepartureChanged: vehicleModel.request = { stopover: root.departure }

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

    VehicleLayoutView {
        id: vehicleView
        model: vehicleModel
    }

    QQC2.BusyIndicator {
        anchors.centerIn: parent
        running: vehicleModel.loading
    }

    QQC2.Label {
        anchors.centerIn: parent
        width: parent.width
        text: vehicleModel.errorMessage
        color: Kirigami.Theme.negativeTextColor
        wrapMode: Text.Wrap
        horizontalAlignment: Text.AlignHCenter
    }

    QQC2.Label {
        anchors.centerIn: parent
        width: parent.width
        visible: vehicleModel.errorMessage === "" && !vehicleModel.loading && vehicleModel.vehicle.sections.length === 0
        wrapMode: Text.Wrap
        horizontalAlignment: Text.AlignHCenter
        text: "No vehicle layout information available."
    }

    Component.onCompleted: contentItem.clip = true
}

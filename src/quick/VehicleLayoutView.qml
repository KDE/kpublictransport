/*
    SPDX-FileCopyrightText: ⓒ 2019 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport

/** Top-down vehicle layout view of an entire train.
 *  @since 25.08
 */
Item {
    id: root

    /** Vehicle query model with the vehicle/platform/stop data to show. */
    property KPublicTransport.VehicleLayoutQueryModel model
    /** Width of the vehicle sections. */
    property real sectionWidth: 48

    /** Name of the vehicle section to highlight. */
    property string highlightedVehicleSection: ""
    /** Vehicle seating classes to highlight. */
    property int higlightedClassTypes: KPublicTransport.VehicleSection.UnknownClass

    /** Vehicle section tapped by the user. */
    signal vehicleSectionTapped(vehicleSection: KPublicTransport.vehicleSection)

    // internal
    readonly property real fullLength: model.platform.hasAbsoluteLength ? model.platform.length * 3.5 : 1600 // full length of the platform display
    readonly property real directionIndicatorSize: root.model.vehicle.direction === KPublicTransport.Vehicle.UnknownDirection ? 0 : (Kirigami.Units.iconSizes.small + Kirigami.Units.largeSpacing)
    height: fullLength + 2 * directionIndicatorSize
    implicitHeight: height

    Repeater {
        width: parent.width
        model: root.model.platform.sections
        delegate: Item {
            id: platformDelegateRoot
            required property KPublicTransport.platformSection modelData
            required property int index
            property alias section: platformDelegateRoot.modelData
            width: parent.width
            y: section.begin * root.fullLength + root.directionIndicatorSize
            height: section.end * root.fullLength - y

            Kirigami.Separator {
                visible: platformDelegateRoot.index === 0
                anchors { top: parent.top; left: parent.left; right: parent.right }
            }
            QQC2.Label {
                anchors.centerIn: parent
                text: platformDelegateRoot.section.name
            }
            Kirigami.Separator {
                anchors { bottom: parent.bottom; left: parent.left; right: parent.right }
            }
        }
    }

    Kirigami.Icon {
        visible: root.model.vehicle.direction != KPublicTransport.Vehicle.UnknownDirection
        source: {
            if (root.model.vehicle.direction == KPublicTransport.Vehicle.Forward)
                return "go-up";
            if (root.model.vehicle.direction == KPublicTransport.Vehicle.Backward)
                return "go-down"
            return "";
        }
        width: Kirigami.Units.iconSizes.small
        height: width
        x: root.sectionWidth / 2 - width / 2
        y: root.model.vehicle.platformPositionBegin * root.fullLength - height - Kirigami.Units.largeSpacing + root.directionIndicatorSize
    }
    Repeater {
        id: vehicleRepeater
        width: parent.width
        model: root.model
        delegate: KPublicTransport.VehicleSectionDelegate {
            id: delegateRoot

            highlighted: {
                if (root.highlightedVehicleSection === "") {
                    return root.higlightedClassTypes & section.classes;
                }
                return section.name === root.highlightedVehicleSection
            }

            y: delegateRoot.vehicleSection.platformPositionBegin * root.fullLength + root.directionIndicatorSize
            height: (delegateRoot.vehicleSection.platformPositionEnd - delegateRoot.vehicleSection.platformPositionBegin) * root.fullLength
            width: root.sectionWidth

            onTapped: root.vehicleSectionTapped(delegateRoot.vehicleSection)
        }
    }
    Kirigami.Icon {
        visible: root.model.vehicle.direction != KPublicTransport.Vehicle.UnknownDirection
        source: {
            if (root.model.vehicle.direction == KPublicTransport.Vehicle.Forward)
                return "go-up";
            if (root.model.vehicle.direction == KPublicTransport.Vehicle.Backward)
                return "go-down"
            return "";
        }
        width: Kirigami.Units.iconSizes.small
        height: width
        x: root.sectionWidth / 2 - width / 2
        y: root.model.vehicle.platformPositionEnd * root.fullLength + Kirigami.Units.largeSpacing + root.directionIndicatorSize
    }
}

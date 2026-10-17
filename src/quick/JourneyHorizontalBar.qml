/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>
    SPDX-FileCopyrightText: 2023 Carl Schwan <carl@carlschwan.eu>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport

/** Display a journey as a horizontal bar with elements for the individual journey sections.
 *  @since 25.04
 */
RowLayout {
    id: root

    /** The journey to display. */
    property KPublicTransport.journey journey

    /** Thresholds for warning about suspiciously long individual transport sections.
     *  Units are seconds or meters, respectively.
     */
    property int warnWalkTime: 20 * 60
    property int warnWalkDistance: 1000
    property int warnBikeTime: 60 * 60
    property int warnBikeDistance: 20000

    spacing: Kirigami.Units.smallSpacing
    Layout.fillWidth: true

    // suspiciously long individual transport sections
    function warnAboutSection(section : KPublicTransport.journeySection): bool {
        switch (section.mode) {
            case KPublicTransport.JourneySection.Walking:
            case KPublicTransport.JourneySection.Transfer:
                return section.duration > root.warnWalkTime || section.distance > root.warnWalkDistance;
            case KPublicTransport.JourneySection.Waiting:
                return section.duration > root.warnWalkTime;
            case KPublicTransport.JourneySection.RentedVehicle:
                switch (section.rentalVehicle.type) {
                    case KPublicTransport.RentalVehicle.Bicycle:
                        return section.duration > warnBikeTime || section.distance > root.warnBikeDistance;
                }
                break;
            case KPublicTransport.JourneySection.IndividualTransport:
                switch (section.individualTransport.mode) {
                    case KPublicTransport.IndividualTransport.Walk:
                        return section.duration > root.warnWalkTime || section.distance > root.warnWalkDistance;
                    case KPublicTransport.IndividualTransport.Bike:
                        return section.duration > warnBikeTime || section.distance > root.warnBikeDistance;
                }
                break;
        }
        return false;
    }


    Repeater {
        id: repeater
        model: root.journey.sections
        delegate: Loader {
            id: nameControlLoader
            active: modelData.mode != KPublicTransport.JourneySection.Walking || modelData.duration > 120 // seconds
            required property KPublicTransport.journeySection modelData
            Layout.fillWidth: nameControlLoader.modelData.mode === KPublicTransport.JourneySection.PublicTransport

            Component {
                id: transportLegComponent

                TransportNameControl {
                    id: delegateRoot
                    clip: false

                    journeySection: nameControlLoader.modelData

                    squashToFit: true

                    // ### enabled: false for cancelled sections? needs the below icon moved out of the hierarchy though

                    readonly property bool isFull: nameControlLoader.modelData.maximumOccupancy == KPublicTransport.Load.Full;

                    Loader {
                        id: iconLoader

                        readonly property string icon: {
                            if (nameControlLoader.modelData.disruptionEffect === KPublicTransport.Disruption.NoService)
                                return "emblem-error";
                            if (root.warnAboutSection(nameControlLoader.modelData))
                                return "emblem-warning";
                            if (delegateRoot.isFull)
                                return "qrc:///org.kde.kpublictransport/ui/assets/occupancy-full.svg";
                            return "";
                        }

                        active: icon != ""

                        anchors.right: delegateRoot.right
                        anchors.bottom: delegateRoot.bottom
                        anchors.bottomMargin: -Kirigami.Units.smallSpacing
                        anchors.rightMargin: -Kirigami.Units.smallSpacing
                        width: Kirigami.Units.iconSizes.small
                        height: width

                        Kirigami.Icon  {
                            width: iconLoader.width
                            height: width
                            source: iconLoader.icon
                            isMask: delegateRoot.isFull
                            color: delegateRoot.isFull ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.textColor
                            visible: source !== "" && delegateRoot.width > width
                        }
                    }
                }
            }

            Component {
                id: otherLegComponent

                TransportIcon {
                    color: Kirigami.Theme.textColor

                    isMask: true
                    iconHeight: Kirigami.Units.iconSizes.smallMedium
                    source: nameControlLoader.modelData.iconName
                    Accessible.name: nameControlLoader.modelData.label

                    width: Kirigami.Units.iconSizes.smallMedium
                    height: Kirigami.Units.iconSizes.smallMedium
                }
            }

            sourceComponent: modelData.mode === KPublicTransport.JourneySection.PublicTransport ? transportLegComponent : otherLegComponent
        }
    }
}

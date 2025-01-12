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

    spacing: Kirigami.Units.smallSpacing
    Layout.fillWidth: true

    // minimum width we need to show the journey without eliding/clipping/etc
    readonly property real __minimumWidth: {
        if (repeater.count != root.journey.sections.length || repeater.count === 0) // still being populated
            return 0.0;
        let s = 0.0;
        for (const v of root.children) {
            if (v as TransportNameControl)
                s += v.implicitWidth
        }
        s += (repeater.count - 1) * root.spacing;
        return s;
    }

    // suspiciously long individual transport sections
    function warnAboutSection(section : KPublicTransport.journeySection): bool {
        switch (section.mode) {
            case KPublicTransport.JourneySection.Walking:
            case KPublicTransport.JourneySection.Transfer:
                return section.duration > 20 * 60 || section.distance > 1000;
            case KPublicTransport.JourneySection.Waiting:
                return section.duration > 20 * 60;
            case KPublicTransport.JourneySection.PublicTransport:
                // TODO full occupancy
                return false;
            case KPublicTransport.JourneySection.RentedVehicle:
                switch (section.rentalVehicle.type) {
                    case KPublicTransport.RentalVehicle.Bicycle:
                        return section.duration > 60 * 60 || section.distance > 20000;
                }
                break;
            case KPublicTransport.JourneySection.IndividualTransport:
                switch (section.individualTransport.mode) {
                    case KPublicTransport.IndividualTransport.Walk:
                        return section.duration > 20 * 60 || section.distance > 1000;
                    case KPublicTransport.IndividualTransport.Bike:
                        return section.duration > 60 * 60 || section.distance > 20000;
                }
                break;
        }
        return false;
    }

    Repeater {
        id: repeater
        model: root.journey.sections
        delegate: TransportNameControl {
            id: delegateRoot
            clip: false

            required property KPublicTransport.journeySection modelData
            journeySection: modelData

            Layout.fillWidth: true
            Layout.maximumWidth: delegateRoot.modelData.mode === KPublicTransport.JourneySection.PublicTransport ? Number.POSITIVE_INFINITY : implicitWidth
            Layout.minimumWidth: root.__minimumWidth < root.width ? implicitWidth : 0

            // when we have the space, size public transport sections based on their duration
            Layout.preferredWidth: implicitWidth + (delegateRoot.modelData.mode === KPublicTransport.JourneySection.PublicTransport ? (delegateRoot.journeySection.duration / root.journey.duration) * (root.width - (root.journey.sections.length * root.spacing) - root.__minimumWidth) : 0)

            // ### enabled: false for cancelled sections? needs the below icon moved out of the hierarchy though

            Kirigami.Icon  {
                anchors.right: delegateRoot.right
                anchors.bottom: delegateRoot.bottom
                anchors.bottomMargin: -Kirigami.Units.smallSpacing
                anchors.rightMargin: -Kirigami.Units.smallSpacing
                width: Kirigami.Units.iconSizes.small
                height: width
                source: {
                    if (delegateRoot.journeySection.disruptionEffect === KPublicTransport.Disruption.NoService)
                        return "emblem-error";
                    if (root.warnAboutSection(delegateRoot.journeySection))
                        return "emblem-warning";
                    return "";
                }
                visible: source !== "" && delegateRoot.width > width
            }
        }
    }
}

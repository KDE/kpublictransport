/*
    SPDX-FileCopyrightText: 2020-2022 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport

/** Displays a single vehicle section. */
KPublicTransport.StyledFrameSvgItem {
    id: root

    /** The vehicle section to show. */
    property KPublicTransport.vehicleSection section

    /** Indicate whether this vehicle section should be visually highlighted. */
    property bool highlighted: false

    /** Color to use for the outline/text. */
    property color textColor: root.section.disruptionEffect === KPublicTransport.Disruption.NoService ?
        Kirigami.Theme.disabledTextColor : Kirigami.Theme.textColor
    /** Background color to use in first class sections. */
    property color firstClassBackground: _colorMix(Kirigami.Theme.backgroundColor, Kirigami.Theme.positiveTextColor, highlighted ? 1 : 0.25)
    /** Background color to use in second class sections. */
    property color secondClassBackground: _colorMix(Kirigami.Theme.backgroundColor, Kirigami.Theme.focusColor, highlighted ? 1 : 0.25)
    /** Background color for inaccessible sections (engines, power cars, etc). */
    property color inaccessibleBackground: _colorMix(Kirigami.Theme.backgroundColor, Kirigami.Theme.disabledTextColor, highlighted ? 1 : 0.25)
    /** Background color for restaurant cars. */
    property color restaurantBackground: _colorMix(Kirigami.Theme.backgroundColor, Kirigami.Theme.neutralTextColor, highlighted ? 1 : 0.25)

    width: 48

    // internal
    function _colorMix(bg: color, fg: color, alpha: real): color
    {
        return Qt.tint(bg, Qt.rgba(fg.r, fg.g, fg.b, alpha));
    }

    source: {
        var svgName = "passengercar";
        switch (section.type) {
            case KPublicTransport.VehicleSection.ControlCar:
            case KPublicTransport.VehicleSection.PowerCar:
                svgName = "controlcar";
                break;
            case KPublicTransport.VehicleSection.Engine:
                svgName = "engine";
                break;
        }

        switch (section.type) {
            case KPublicTransport.VehicleSection.PowerCar:
            case KPublicTransport.VehicleSection.ControlCar:
                if (section.connectedSides === KPublicTransport.VehicleSection.Front) {
                    svgName += "-back";
                } else {
                    svgName += "-front";
                }
                break;
        }

        if (section.deckCount > 1) {
            switch (section.type) {
                case KPublicTransport.VehicleSection.PassengerCar:
                case KPublicTransport.VehicleSection.RestaurantCar:
                case KPublicTransport.VehicleSection.ControlCar:
                case KPublicTransport.VehicleSection.SleepingCar:
                case KPublicTransport.VehicleSection.CouchetteCar:
                case KPublicTransport.VehicleSection.CarTransportCar:
                    svgName += "-double-deck";
                    break;
            }
        }
        return ":/org.kde.kpublictransport/ui/assets/" + svgName + ".svg";
    }

    backgroundColor: {
        if (root.section.disruptionEffect === KPublicTransport.Disruption.NoService)
            return root.inaccessibleBackground;

        switch (section.type) {
            case KPublicTransport.VehicleSection.Engine:
            case KPublicTransport.VehicleSection.PowerCar:
            case KPublicTransport.VehicleSection.CarTransportCar:
                return inaccessibleBackground;
            case KPublicTransport.VehicleSection.RestaurantCar:
                return restaurantBackground;
            case KPublicTransport.VehicleSection.PassengerCar:
            case KPublicTransport.VehicleSection.ControlCar:
            case KPublicTransport.VehicleSection.SleepingCar:
            case KPublicTransport.VehicleSection.CouchetteCar:
            default:
                if (section.classes == KPublicTransport.VehicleSection.FirstClass)
                    return firstClassBackground;
                else if (section.classes & KPublicTransport.VehicleSection.FirstClass)
                    return Qt.tint(secondClassBackground, Qt.rgba(firstClassBackground.r, firstClassBackground.g, firstClassBackground.b, 0.5));
        }
        return secondClassBackground;
    }
    lineColor: textColor

    borderTop: {
        switch (section.type) {
            case KPublicTransport.VehicleSection.PowerCar:
            case KPublicTransport.VehicleSection.ControlCar:
                return section.connectedSides == KPublicTransport.VehicleSection.Front ? 12 : 36
            case KPublicTransport.VehicleSection.Engine:
                return 22;
        }
        return 36;
    }
    borderBottom: 48 - borderTop - 2

    ColumnLayout {
        anchors.centerIn: root
        QQC2.Label {
            Layout.alignment: Qt.AlignCenter
            text: root.section.name
            visible: text !== ""
            color: root.textColor
        }
        Kirigami.Icon {
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: Kirigami.Units.iconSizes.small
            Layout.preferredHeight: visible ? Kirigami.Units.iconSizes.small : 0
            source: {
                if (root.section.disruptionEffect === KPublicTransport.Disruption.NoService)
                    return "dialog-cancel"
                root.section.type !== KPublicTransport.VehicleSection.ControlCar ? root.section.iconName : ""
            }
            color: root.section.disruptionEffect === KPublicTransport.Disruption.NoService ? Kirigami.Theme.negativeTextColor : root.textColor
            isMask: true
            visible: source ? true : false
        }
    }
}

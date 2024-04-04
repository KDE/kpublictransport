/*
    SPDX-FileCopyrightText: 2020-2022 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.5
import org.kde.kpublictransport 1.0
import org.kde.kpublictransport.ui 1.0

/** Displays a single vehicle section. */
StyledFrameSvgItem {
    id: root

    /** The vehicle section to show. */
    property var section

    /** Color to use for the outline/text. */
    property color textColor: "black"
    /** Background color to use in first class sections. */
    property color firstClassBackground: "green"
    /** Background color to use in second class sections. */
    property color secondClassBackground: "blue"
    /** Background color for inaccessible sections (engines, power cars, etc). */
    property color inaccessibleBackground: "gray"
    /** Background color for restaurant cars. */
    property color restaurantBackground: "orange"

    source: {
        var svgName = "passengercar";
        switch (section.type) {
            case VehicleSection.ControlCar:
            case VehicleSection.PowerCar:
                svgName = "controlcar";
                break;
            case VehicleSection.Engine:
                svgName = "engine";
                break;
        }

        switch (section.type) {
            case VehicleSection.PowerCar:
            case VehicleSection.ControlCar:
                if (section.connectedSides == VehicleSection.Front) {
                    svgName += "-back";
                } else {
                    svgName += "-front";
                }
                break;
        }

        if (section.deckCount > 1) {
            switch (section.type) {
                case VehicleSection.PassengerCar:
                case VehicleSection.RestaurantCar:
                case VehicleSection.ControlCar:
                case VehicleSection.SleepingCar:
                case VehicleSection.CouchetteCar:
                case VehicleSection.CarTransportCar:
                    svgName += "-double-deck";
                    break;
            }
        }
        return ":/org.kde.kpublictransport/ui/assets/" + svgName + ".svg";
    }

    backgroundColor: {
        if (root.section.disruptionEffect === Disruption.NoService)
            return root.inaccessibleBackground;

        switch (section.type) {
            case VehicleSection.Engine:
            case VehicleSection.PowerCar:
            case VehicleSection.CarTransportCar:
                return inaccessibleBackground;
            case VehicleSection.RestaurantCar:
                return restaurantBackground;
            case VehicleSection.PassengerCar:
            case VehicleSection.ControlCar:
            case VehicleSection.SleepingCar:
            case VehicleSection.CouchetteCar:
            default:
                if (section.classes == VehicleSection.FirstClass)
                    return firstClassBackground;
                else if (section.classes & VehicleSection.FirstClass)
                    return Qt.tint(secondClassBackground, Qt.rgba(firstClassBackground.r, firstClassBackground.g, firstClassBackground.b, 0.5));
        }
        return secondClassBackground;
    }
    lineColor: textColor

    borderTop: {
        switch (section.type) {
            case VehicleSection.PowerCar:
            case VehicleSection.ControlCar:
                return section.connectedSides == VehicleSection.Front ? 12 : 36
            case VehicleSection.Engine:
                return 22;
        }
        return 36;
    }
    borderBottom: 48 - borderTop - 2
}

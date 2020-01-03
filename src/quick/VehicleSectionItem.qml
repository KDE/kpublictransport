/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

import QtQuick 2.5
import org.kde.kpublictransport 1.0

/** Displays a single vehicle section. */
BorderImage {
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
                    svgName += "-double-deck";
                    break;
            }
        }

        var fillColor = secondClassBackground;
        switch (section.type) {
            case VehicleSection.Engine:
            case VehicleSection.PowerCar:
                fillColor = inaccessibleBackground;
                break;
            case VehicleSection.RestaurantCar:
                fillColor = restaurantBackground;
                break;
            case VehicleSection.PassengerCar:
            case VehicleSection.ControlCar:
                if (section.classes == VehicleSection.FirstClass)
                    fillColor = firstClassBackground;
                else if (section.classes & VehicleSection.FirstClass)
                    fillColor = Qt.tint(secondClassBackground, Qt.rgba(firstClassBackground.r, firstClassBackground.g, firstClassBackground.b, 0.5));
                break;
        }

        return "image://org.kde.kpublictransport.styledsvg/" + svgName + "?lineColor=" + textColor + "&fillColor=" + fillColor;
    }

    border.left: 20
    border.right: 20
    border.top: {
        switch (section.type) {
            case VehicleSection.PowerCar:
            case VehicleSection.ControlCar:
                return section.connectedSides == VehicleSection.Front ? 12 : 36
            case VehicleSection.Engine:
                return 22;
        }
        return 36;
    }
    border.bottom: 48 - border.top - 4
}

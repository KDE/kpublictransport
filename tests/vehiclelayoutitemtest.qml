/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import org.kde.kirigami 2.4 as Kirigami
import org.kde.kpublictransport 1.0
import org.kde.kpublictransport.ui 1.0

Item {
    width: 800
    height: 400

    RowLayout {
        anchors.fill: parent

        Image {
            source: "image://org.kde.kpublictransport.styledsvg/passengercar?lineColor=#00ff00&fillColor=#ff0000"
            width: 64
            height: 128
        }

        VehicleSectionItem {
            section: {
                var obj = new Object();
                obj.type = VehicleSection.PassengerCar;
                obj.classes = VehicleSection.FirstClass;
                return obj;
            }
            textColor: Kirigami.Theme.textColor
            firstClassBackground: Kirigami.Theme.positiveTextColor
            secondClassBackground: Kirigami.Theme.focusColor
            Layout.preferredHeight: 128
        }
        VehicleSectionItem {
            section: {
                var obj = new Object();
                obj.type = VehicleSection.ControlCar;
                obj.classes = VehicleSection.SecondClass;
                return obj;
            }
            textColor: Kirigami.Theme.textColor
            firstClassBackground: Kirigami.Theme.positiveTextColor
            secondClassBackground: Kirigami.Theme.focusColor
            Layout.preferredHeight: 128
        }
        VehicleSectionItem {
            section: {
                var obj = new Object();
                obj.type = VehicleSection.PassengerCar;
                obj.classes = VehicleSection.FirstClass | VehicleSection.SecondClass;
                obj.deckCount = 2;
                return obj;
            }
            textColor: Kirigami.Theme.textColor
            firstClassBackground: Kirigami.Theme.positiveTextColor
            secondClassBackground: Kirigami.Theme.focusColor
            Layout.preferredHeight: 128
        }
    }
}

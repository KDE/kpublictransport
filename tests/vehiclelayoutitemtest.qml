/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import org.kde.kirigami 2.12 as Kirigami
import org.kde.kpublictransport 1.0
import org.kde.kpublictransport.ui 1.0

Rectangle {
    width: 800
    height: 400
    color: Kirigami.Theme.backgroundColor

    RowLayout {
        anchors.fill: parent

        Image {
            source: "image://org.kde.kpublictransport.styledsvg/passengercar?lineColor=#00ff00&fillColor=#ff0000"
        }
        BorderImage {
            source: "image://org.kde.kpublictransport.styledsvg/passengercar?lineColor=#00ff00&fillColor=#ff0000"
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

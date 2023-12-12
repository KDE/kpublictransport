/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport
import org.kde.kpublictransport.ui

Rectangle {
    width: 800
    height: 400
    color: Kirigami.Theme.backgroundColor

    RowLayout {
        anchors.fill: parent

        Image {
            source: "qrc:///org.kde.kpublictransport/ui/assets/passengercar.svg"
        }
        BorderImage {
            source: "qrc:///org.kde.kpublictransport/ui/assets/passengercar.svg"
        }

        StyledFrameSvgItem {
            source: ":/org.kde.kpublictransport/ui/assets/passengercar.svg"
            backgroundColor: "red"
            lineColor: "#00ff00"
            borderTop: 35
            borderBottom: 12
            Layout.preferredHeight: 128
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

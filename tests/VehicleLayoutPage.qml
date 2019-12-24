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
import org.kde.kpublictransport 1.0 as KPublicTransport

Kirigami.ScrollablePage {
    id: root
    title: i18n("Vehicle Layout")

    property alias publicTransportManager: vehicleModel.manager
    property var departure

    onDepartureChanged: vehicleModel.request.departure = root.departure;

    KPublicTransport.VehicleLayoutQueryModel {
        id: vehicleModel
    }

    Item {
        Repeater {
            model: vehicleModel.platform.sections
            delegate: Item {
                property var section: modelData
                width: parent.width
                y: section.begin * 800
                height: section.end * 800 - y

                Rectangle {
                    visible: index == 0
                    anchors { top: parent.top; left: parent.left; right: parent.right }
                    color: "gray"
                    height: 1
                }
                QQC2.Label {
                    anchors.centerIn: parent
                    text: section.name
                }
                Rectangle {
                    anchors { bottom: parent.bottom; left: parent.left; right: parent.right }
                    color: "gray"
                    height: 1
                }
            }
        }

        Repeater {
            model: vehicleModel
            delegate: Rectangle {
                property var section: model.vehicleSection
                y: section.platformPositionBegin * 800
                height: section.platformPositionEnd * 800 - y
                width: 50
                color: {
                    if (section.type == KPublicTransport.VehicleSection.Engine || section.type == KPublicTransport.VehicleSection.PowerCar)
                        return "gray";
                    return "lightsteelblue";
                }
                border {
                    color: "black"
                    width: 1
                }
                radius: section.type == KPublicTransport.VehicleSection.ControlCar ? 2 : 0;
                QQC2.Label {
                    anchors.centerIn: parent
                    text: section.name
                }
            }
        }
    }
}

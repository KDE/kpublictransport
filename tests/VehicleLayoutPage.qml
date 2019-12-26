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

    ColumnLayout {
        QQC2.Label {
            text: vehicleModel.departure.stopPoint.name + " - " + vehicleModel.departure.route.line.name + " - " + vehicleModel.departure.scheduledDepartureTime
        }
        QQC2.Label {
            text: "Platform: " + vehicleModel.platform.name
        }

        Item {
            id: vehicleView
            property real fullLength: 1000 // full length of the platform display
            implicitHeight: childrenRect.height
            Layout.fillWidth: true
            Repeater {
                Layout.fillWidth: true;
                model: vehicleModel.platform.sections
                delegate: Item {
                    property var section: modelData
                    width: parent.width
                    y: section.begin * vehicleView.fullLength
                    height: section.end * vehicleView.fullLength - y

                    Kirigami.Separator {
                        visible: index == 0
                        anchors { top: parent.top; left: parent.left; right: parent.right }
                    }
                    QQC2.Label {
                        anchors.centerIn: parent
                        text: section.name
                    }
                    Kirigami.Separator {
                        anchors { bottom: parent.bottom; left: parent.left; right: parent.right }
                    }
                }
            }

            Repeater {
                Layout.fillWidth: true
                model: vehicleModel
                delegate: Rectangle {
                    property var section: model.vehicleSection
                    y: section.platformPositionBegin * vehicleView.fullLength
                    height: section.platformPositionEnd * vehicleView.fullLength - y
                    width: Kirigami.Units.gridUnit * 2
                    color: {
                        if (section.type == KPublicTransport.VehicleSection.Engine || section.type == KPublicTransport.VehicleSection.PowerCar)
                            return Kirigami.Theme.disabledTextColor
                        if (section.type == KPublicTransport.VehicleSection.RestaurantCar)
                            return Kirigami.Theme.neutralTextColor;
                        if (section.classes == KPublicTransport.VehicleSection.FirstClass)
                            return Kirigami.Theme.positiveTextColor;
                        if (section.classes == KPublicTransport.VehicleSection.SecondClass)
                            return Kirigami.Theme.highlightColor;
                        if (section.classes == (KPublicTransport.VehicleSection.FirstClass | KPublicTransport.VehicleSection.SecondClass))
                            return Qt.tint(Kirigami.Theme.highlightColor, Qt.rgba(Kirigami.Theme.positiveTextColor.r, Kirigami.Theme.positiveTextColor.g, Kirigami.Theme.positiveTextColor.b, 0.5));
                        return Kirigami.Theme.negativeTextColor;
                    }
                    border {
                        color: Kirigami.Theme.textColor
                        width: 1
                    }
                    radius: section.type == KPublicTransport.VehicleSection.ControlCar ? 0 : 10;
                    QQC2.Label {
                        anchors.centerIn: parent
                        text: section.name
                    }

                    ColumnLayout {
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.right
                        anchors.leftMargin: Kirigami.Units.largeSpacing
                        spacing: Kirigami.Units.smallSpacing

                        RowLayout {
                            spacing: Kirigami.Units.smallSpacing
                            Repeater {
                                model: section.featureList
                                QQC2.Label {
                                    text: {
                                        switch (modelData) {
                                            case KPublicTransport.VehicleSection.AirConditioning: return "❄️";
                                            case KPublicTransport.VehicleSection.Restaurant: return "🍴";
                                            case KPublicTransport.VehicleSection.ToddlerArea: return "👶";
                                            case KPublicTransport.VehicleSection.WheelchairAccessible: return "♿";
                                            case KPublicTransport.VehicleSection.SilentArea: return "🔇";
                                            case KPublicTransport.VehicleSection.BikeStorage: return "🚲";
                                        }
                                    }
                                }
                            }
                        }
                        QQC2.Label {
                            visible: section.classes != KPublicTransport.VehicleSection.UnknownClass
                            text: {
                                if (section.classes == KPublicTransport.VehicleSection.FirstClass)
                                    return "First class";
                                if (section.classes == KPublicTransport.VehicleSection.SecondClass)
                                    return "Second class";
                                if (section.classes == (KPublicTransport.VehicleSection.FirstClass | KPublicTransport.VehicleSection.SecondClass))
                                    return "First/second class";
                                return "Unknown class";
                            }
                        }
                    }
                }
            }

            QQC2.BusyIndicator {
                anchors.centerIn: root
                running: vehicleModel.loading
            }

            QQC2.Label {
                anchors.centerIn: root
                width: parent.width
                text: vehicleModel.errorMessage
                color: Kirigami.Theme.negativeTextColor
                wrapMode: Text.Wrap
            }
        }
    }
}

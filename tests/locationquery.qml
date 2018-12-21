/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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
import org.kde.kirigami 2.0 as Kirigami

Kirigami.ApplicationWindow {
    title: "Location Query"
    reachableModeEnabled: false

    width: 480
    height: 720

    pageStack.initialPage: locationQueryPage

    ListModel {
        id: exampleModel
        ListElement { name: "Charles de Gaulles"; lat: 2.57110; lon: 49.00406; }
        ListElement { name: "Paris Gare de Lyon"; lat: 2.37385; lon: 48.84467; }
        ListElement { name: "Zürich Flughafen"; lat: 8.56275; lon: 47.45050; }
        ListElement { name: "Randa"; lat: 7.78315; lon:  46.09901; }
        ListElement { name: "Brussels Gare de Midi"; lat: 4.33620; lon: 50.83588; }
        ListElement { name: "ULB"; lat: 4.38116; lon: 50.81360 }
        ListElement { name: "Wien Flughafen"; lat: 16.56312; lon: 48.12083; }
        ListElement { name: "Akademy 2018 Accomodation"; lat: 16.37859; lon: 48.18282 }
        ListElement { name: "Akademy 2018 BBQ"; lat: 16.43191; lon: 48.21612 }
        ListElement { name: "LEI"; lat: -2.37251; lon: 36.84774; }
        ListElement { name: "Akademy 2017 Accomodation"; lat: -2.44788; lon: 36.83731 }
        ListElement { name: "Akademy 2017 Venue"; lat: -2.40377; lon: 36.82784 }
        ListElement { name: "TXL"; lat: 13.29281; lon: 52.55420; }
        ListElement { name: "Alexanderplatz"; lat: 13.41644; lon: 52.52068 }
        ListElement { name: "SXF"; lat: 13.51870; lon: 52.38841; }
        ListElement { name: "Brno central station"; lat: 16.61287; lon: 49.19069 }
        ListElement { name: "Akademy 2014 venue"; lat: 16.57564; lon: 49.22462 }
        ListElement { name: "Copenhagen Central"; lat: 12.56489; lon: 55.67238; }
        ListElement { name: "Frankfurt (Main) Hauptbahnhof"; lat: 8.6625; lon: 50.106944; }
    }

    Component {
        id: locationDelegate
        Item {
            implicitHeight: delegateLayout.implicitHeight
            implicitWidth: delegateLayout.implicitWidth

             ColumnLayout {
                 id: delegateLayout
                Layout.fillWidth: true
                QQC2.Label {
                    text: modelData.name
                }
                QQC2.Label {
                    text: modelData.latitude + " " + modelData.longitude
                }

            }
        }
    }

    Component {
        id: locationQueryPage
        Kirigami.Page {
            ColumnLayout {
                anchors.fill: parent

                QQC2.CheckBox {
                    text: "Allow insecure backends"
                    onToggled: _queryMgr.setAllowInsecure(checked)
                }

                QQC2.ComboBox {
                    id: exampleSelector
                    Layout.fillWidth: true
                    model: exampleModel
                    textRole: "name"
                    onCurrentIndexChanged: {
                        var obj = exampleModel.get(currentIndex);
                        nameQuery.text = obj.name
                        latQuery.text = obj.lat
                        lonQuery.text = obj.lon
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    QQC2.TextField {
                        Layout.fillWidth: true
                        id: nameQuery
                    }
                    QQC2.Button {
                        text: "Query"
                        onClicked: _queryMgr.queryLocation(NaN, NaN, nameQuery.text);
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    QQC2.TextField {
                        id: latQuery
                    }
                    QQC2.TextField {
                        id: lonQuery
                    }
                    QQC2.Button {
                        text: "Query"
                        onClicked: _queryMgr.queryLocation(latQuery.text, lonQuery.text, null);
                    }
                }

                ListView {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: _locations
                    clip: true
                    spacing: Kirigami.Units.smallSpacing
                    delegate: locationDelegate

                    QQC2.BusyIndicator {
                        anchors.centerIn: parent
                        running: _queryMgr.loading
                    }

                    QQC2.Label {
                        anchors.centerIn: parent
                        width: parent.width
                        text: _queryMgr.errorMessage
                        color: Kirigami.Theme.negativeTextColor
                        wrapMode: Text.Wrap
                    }
                }

            }
        }
    }
}

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
import org.kde.kirigami 2.0 as Kirigami
import org.kde.kpublictransport 1.0

Kirigami.ApplicationWindow {
    title: "Pure QML Journey Query Example"
    reachableModeEnabled: false
    width: 640
    height: 800

    pageStack.initialPage: journyQueryPage

    Manager {
        id: ptMgr;
    }

    JourneyQueryModel {
        id: journeyModel
        manager: ptMgr
    }

    globalDrawer: Kirigami.GlobalDrawer {
        actions: [
            Kirigami.Action {
                iconName: "help-about-symbolic"
                text: i18n("Current Data Sources")
                enabled: journeyModel.attributions.length > 0
                onTriggered: {
                    aboutSheet.attributions = Qt.binding(function() { return journeyModel.attributions; });
                    aboutSheet.sheetOpen = true;
                }
            },
            Kirigami.Action {
                iconName: "help-about-symbolic"
                text: i18n("All Data Sources")
                onTriggered: {
                    aboutSheet.attributions = Qt.binding(function() { return ptMgr.attributions; });
                    aboutSheet.sheetOpen = true;
                }
            }
        ]
    }

    AttributionSheet { id: aboutSheet }

    Component {
        id: journyQueryPage
        Kirigami.Page {
            ColumnLayout {
                anchors.fill: parent
                QQC2.TextField {
                    id: fromName
                }
                QQC2.TextField {
                    id: toName
                }
                QQC2.Button {
                    text: qsTr("Query")
                    onClicked: {
                        var from = journeyModel.request.from;
                        from.name = fromName.text;
                        journeyModel.request.from = from;
                        var to = journeyModel.request.to;
                        to.name = toName.text;
                        journeyModel.request.to = to;
                    }
                }

                ListView {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    model: journeyModel
                    clip: true
                    delegate: Kirigami.AbstractListItem {
                        GridLayout {
                            rows: 2
                            columns: 2
                            QQC2.Label {
                                text: journey.scheduledDepartureTime
                            }
                            QQC2.Label {
                                Layout.fillWidth: true
                                text: journey.sections[0].from.name;
                            }
                            QQC2.Label {
                                text: journey.scheduledArrivalTime
                            }
                            QQC2.Label {
                                Layout.fillWidth: true
                                text: journey.sections[journey.sections.length - 1].to.name;
                            }
                        }
                    }

                    QQC2.BusyIndicator {
                        anchors.centerIn: parent
                        running: journeyModel.loading
                    }

                    QQC2.Label {
                        anchors.centerIn: parent
                        width: parent.width
                        text: journeyModel.errorMessage
                        color: Kirigami.Theme.negativeTextColor
                        wrapMode: Text.Wrap
                    }
                }
            }
        }
    }
}

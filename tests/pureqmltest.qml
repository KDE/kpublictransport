/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport

Kirigami.ApplicationWindow {
    title: "Pure QML Journey Query Example"
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
                icon.name: "help-about-symbolic"
                text: "Current Data Sources"
                enabled: journeyModel.attributions.length > 0
                onTriggered: {
                    aboutSheet.attributions = Qt.binding(function() { return journeyModel.attributions; });
                    aboutSheet.open();
                }
            },
            Kirigami.Action {
                icon.name: "help-about-symbolic"
                text: "All Data Sources"
                onTriggered: {
                    aboutSheet.attributions = Qt.binding(function() { return ptMgr.attributions; });
                    aboutSheet.open();
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
                    text: "Query"
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
                    delegate: QQC2.ItemDelegate {
                        width: ListView.view.width
                        contentItem: GridLayout {
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

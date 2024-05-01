/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport

Kirigami.ScrollablePage {
    property alias path: pathModel.path

    Component {
        id: pathDelegate
        QQC2.ItemDelegate {
            highlighted: false
            width: ListView.view.width
            property var section: model.section
            contentItem: GridLayout {
                rows: 2
                columns: 4

                Kirigami.Icon {
                    Layout.row: 0
                    Layout.column: 0
                    Layout.rowSpan: 2
                    source: section.iconName
                    width: 32
                    height: 32
                }

                QQC2.Label {
                    Layout.row: 0
                    Layout.column: 1
                    Layout.rowSpan: 2
                    visible: section.floorLevelChange != 0
                    text: section.floorLevelChange < 0 ? "⬇️" : "⬆️"
                    font.pixelSize: 32
                }

                QQC2.Label {
                    Layout.row: 0
                    Layout.column: 2
                    Layout.fillWidth: true
                    text: section.description
                }
                QQC2.Label {
                    Layout.row: 1
                    Layout.column: 2
                    visible: section.distance > 0
                    text: section.distance + "m"
                }

                QQC2.Label {
                    Layout.row: 0
                    Layout.column: 3
                    Layout.rowSpan: 2
                    text: "⬆️"
                    visible: model.turnDirection >= 0
                    font.pixelSize: 32
                    rotation: model.turnDirection
                }
            }
        }
    }

    PathModel {
        id: pathModel
    }

    ListView {
        model: pathModel
        delegate: pathDelegate
    }
}

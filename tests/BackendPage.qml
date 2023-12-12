/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport

Kirigami.ScrollablePage {
    id: root
    title: "Backends"

    property alias publicTransportManager: backendModel.manager

    KPublicTransport.BackendModel {
        id: backendModel
    }

    Component {
        id: backendDelegate
        QQC2.ItemDelegate {
            highlighted: false
            enabled: model.itemEnabled
            width: ListView.view.width

            contentItem: GridLayout {
                columns: 3
                rows: 2

                QQC2.Label {
                    text: model.name
                    Layout.fillWidth: true
                }
                Kirigami.Icon {
                    source: model.isSecure ? "channel-secure-symbolic" : "channel-insecure-symbolic"
                    color: model.isSecure ? Kirigami.Theme.positiveTextColor : Kirigami.Theme.negativeTextColor
                    width: height
                    height: Kirigami.Units.gridUnit
                }
                QQC2.Switch {
                    id: toggle
                    checked: model.backendEnabled
                    Layout.rowSpan: 2
                    onToggled: model.backendEnabled = checked;
                }
                QQC2.Label {
                    Layout.columnSpan: 2
                    Layout.fillWidth: true
                    text: model.description
                    font.italic: true
                }
            }

            onClicked: {
                toggle.toggle(); // does not trigger the signal handler for toggled...
                model.backendEnabled = toggle.checked;
            }
        }
    }

    ListView {
        model: backendModel
        delegate: backendDelegate
    }
}

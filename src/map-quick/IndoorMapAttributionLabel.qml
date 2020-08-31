/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.12
import QtQuick.Controls 2.12 as QQC2

Item {
    id: root

    implicitHeight: background.height
    implicitWidth: background.width

    property int __margin: 2

    Rectangle {
        id: background
        color: label.palette.base
        opacity: 0.5
        height: label.implicitHeight + 2 * __margin
        width: label.implicitWidth
    }

    QQC2.Label {
        text: qsTr("© <a href=\"https://www.openstreetmap.org/copyright\">OpenStreetMap contributors</a>");
        id: label
        font.pointSize: 7;
        anchors.centerIn: background

        onLinkActivated: Qt.openUrlExternally(link)
    }
}

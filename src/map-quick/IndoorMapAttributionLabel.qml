/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

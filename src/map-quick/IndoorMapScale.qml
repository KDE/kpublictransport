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
    property var view

    implicitHeight: background.height

    property int __margin: 2

    function updateScale() {
        var d = map.view.mapScreenToMeters(background.width - 2 * __margin);
        var s = d < 20 ? 5 : d < 100 ? 10 : 20;
        d /= s;
        d = Math.floor(d);
        d *= s;
        scaleLabel.text = d + "m"; // TODO i18n?
        scale.width = map.view.mapMetersToScreen(d);
    }

    Rectangle {
        id: background
        color: scaleLabel.palette.base
        opacity: 0.5
        height: scaleLabel.implicitHeight + scale.height + 2 * __margin
        width: root.width
    }

    QQC2.Label {
        id: scaleLabel
        anchors.bottom: scale.top
        anchors.horizontalCenter: scale.horizontalCenter
    }

    Rectangle {
        id: scale
        anchors.bottom: root.bottom
        anchors.left: root.left
        anchors.margins: __margin
        height: 4
        color: scaleLabel.color
    }

    Component.onCompleted: root.updateScale()

    Connections {
        target: root.view
        onTransformationChanged: root.updateScale();
    }
}

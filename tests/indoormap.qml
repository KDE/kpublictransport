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
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import org.kde.kirigami 2.0 as Kirigami
import org.kde.kosmindoormap 1.0

Kirigami.ApplicationWindow {
    title: "OSM Indoor Map QML Test"

    pageStack.initialPage: Kirigami.Page {
        title: "Indoor Map View"

        IndoorMap {
            id: map
            anchors.fill: parent

            Component.onCompleted: {
                map.mapLoader.loadForCoordinate(49.44572, 11.08196);
            }
        }
    }
}

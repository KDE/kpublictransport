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

Kirigami.OverlaySheet {
    id: aboutSheet
    property var attributions

    header: Kirigami.Heading {
        text: "Data Providers"
    }

    ListView {
        model: aboutSheet.attributions
        delegate: Kirigami.AbstractListItem {
            contentItem: ColumnLayout {
                QQC2.Label {
                    text: "<a href=\"" + modelData.url + "\">" + modelData.name + "</a>"
                    onLinkActivated: Qt.openUrlExternally(link)
                }
                QQC2.Label {
                    text: "License: <a href=\"" + modelData.licenseUrl + "\">" + modelData.license + "</a>"
                    onLinkActivated: Qt.openUrlExternally(link)
                    visible: modelData.hasLicense
                }
            }
        }
    }
}

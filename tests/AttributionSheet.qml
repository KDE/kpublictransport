/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import org.kde.kirigami 2.12 as Kirigami

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
                    text: "License: <a href=\"" + modelData.licenseUrl + "\">" + (modelData.license != "" ? modelData.license : modelData.licenseUrl) + "</a>"
                    onLinkActivated: Qt.openUrlExternally(link)
                    // FIXME this makes OverlaySheet go completely crazy when we have more entries than fit on the screen
                    //visible: modelData.hasLicense
                }
            }
        }
    }
}

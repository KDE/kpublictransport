/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import QtQuick.Dialogs as Dialogs
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.example

JourneySectionPage {
    id: root
    title: "Full Trip"

    required property KPublicTransport.Manager ptMgr
    required property KPublicTransport.journeySection requestedJourneySection
    required property var backendIds

    actions: [
        Kirigami.Action {
            text: "Save..."
            onTriggered: fileDialog.open()
        }
    ]

    Dialogs.FileDialog {
        id: fileDialog
        title: "Save Trip Data"
        fileMode: Dialogs.FileDialog.SaveFile
        nameFilters: ["JSON files (*.json)"]
        onAccepted: ExampleUtil.saveTo(root.journeySection, fileDialog.selectedFile);
    }

    QQC2.Label {
        id: errorMessage
        anchors.centerIn: parent
        width: parent.width
        color: Kirigami.Theme.negativeTextColor
        wrapMode: Text.Wrap
    }

    Component.onCompleted: {
        errorMessage.text = "Loading..."
        let reply = ptMgr.queryTrip({ journeySection: root.requestedJourneySection, backendIds: root.backendIds, downloadAssets: true })
        reply.finished.connect(() => {
            if (reply.error === KPublicTransport.Reply.NoError) {
                errorMessage.text = ""
                root.journeySection = reply.trip;
            } else {
                errorMessage.text = reply.errorString;
            }
            reply.destroy();
        });
    }

}

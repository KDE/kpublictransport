/*
    SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport

JourneySectionPage {
    id: root
    title: "Full Trip"

    required property KPublicTransport.Manager ptMgr
    required property KPublicTransport.journeySection requestedJourneySection
    required property var backendIds

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
            // TODO we'd need to delete reply here?
        });
    }

}

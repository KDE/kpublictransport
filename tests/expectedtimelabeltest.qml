// SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
// SPDX-License-Identifier: LGPL-2.0-or-later

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport

Kirigami.Page {
    width: 600
    height: 800

    contentItem: ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        KPublicTransport.ExpectedTimeLabel {
            scheduledTime: "12:34"
            delay: 0
            hasExpectedTime: false
            stopover: ({})
        }

        KPublicTransport.ExpectedTimeLabel {
            scheduledTime: "12:34"
            delay: 0
            hasExpectedTime: true
            stopover: ({})
        }

        KPublicTransport.ExpectedTimeLabel {
            scheduledTime: "12:34"
            delay: 1
            hasExpectedTime: true
            stopover: ({})
        }

        KPublicTransport.ExpectedTimeLabel {
            scheduledTime: "12:34"
            delay: 5
            hasExpectedTime: true
            stopover: ({})
        }

        KPublicTransport.ExpectedTimeLabel {
            scheduledTime: "12:34"
            delay: 120
            hasExpectedTime: true
            stopover: ({})
        }

        KPublicTransport.ExpectedTimeLabel {
            scheduledTime: "12:34"
            delay: 1
            hasExpectedTime: true
            stopover: ({ disruptionEffect: KPublicTransport.Disruption.NoService })
        }

        KPublicTransport.ExpectedTimeLabel {
            scheduledTime: "12:34"
            delay: -1
            hasExpectedTime: true
            stopover: ({})
        }

        KPublicTransport.ExpectedTimeLabel {
            scheduledTime: "12:34"
            delay: -10
            hasExpectedTime: true
            stopover: ({})
        }

        KPublicTransport.ExpectedTimeLabel {
            scheduledTime: ""
            delay: 30
            hasExpectedTime: true
            stopover: ({})
        }
    }
}

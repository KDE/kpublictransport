/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport

/** Icon representing a KPublicTransport::Feature. */
Kirigami.Icon {
    id: root

    /** The feature to display. */
    property KPublicTransport.feature feature

    source: root.feature.typeIconName

    Kirigami.Icon {
        id: emblem
        anchors {
            right: root.right
            bottom: root.bottom
        }
        width: root.width / 2
        height: root.height / 2

        visible: emblem.source !== ""
        source: {
            if (root.feature.disruptionEffect === KPublicTransport.Disruption.NoService)
                return "emblem-warning";

            switch (root.feature.availability) {
                case KPublicTransport.Feature.Unknown:
                    return "emblem-question";
                case KPublicTransport.Feature.Unavailable:
                    return "emblem-error";
                case KPublicTransport.Feature.Limited:
                    return "emblem-information";
                case KPublicTransport.Feature.Conditional:
                    return "emblem-important";
                case KPublicTransport.Feature.Available:
                default:
                    return "";
            }
        }
    }

    HoverHandler {
        id: hoverHandler
    }
    QQC2.ToolTip.visible: hoverHandler.hovered && QQC2.ToolTip.text !== ""
    QQC2.ToolTip.text: {
        let s = root.feature.displayName;

        if (root.feature.availability === KPublicTransport.Feature.Unknown) {
            s = i18nd("kpublictransport", "%1 (availability unknown)", s);
        } else if (root.feature.availability === KPublicTransport.Feature.Unavailable) {
            s = i18nd("kpublictransport", "%1 (not available)", s);
        } else if (root.feature.quantity > 0) {
            s = i18ndcp("kpublictransport", "bike/wheelchair spaces on a train/bus", "%2 (one space)", "%2 (%1 spaces)", root.feature.quantity, s);
        }

        if (root.feature.description !== "") {
            s += '\n' + root.feature.description;
            s = s.trimmed();
        }

        return s;
    }
    QQC2.ToolTip.delay: Kirigami.Units.toolTipDelay
    Accessible.name: QQC2.ToolTip.text
}

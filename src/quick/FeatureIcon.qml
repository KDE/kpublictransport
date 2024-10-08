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

    source: {
        switch (root.feature.type) {
            case KPublicTransport.Feature.AirConditioning:
                return "temperature-cold";
            case KPublicTransport.Feature.Restaurant:
                return "qrc:///org.kde.kpublictransport/assets/images/train-coach-restaurant.svg"
            case KPublicTransport.Feature.ToddlerArea:
                return "qrc:///org.kde.kpublictransport/ui/assets/vehicle-feature-toddlerarea.svg";
            case KPublicTransport.Feature.FamilyArea:
                return "qrc:///org.kde.kpublictransport/ui/assets/family.svg";
            case KPublicTransport.Feature.WheelchairAccessible:
                return "qrc:///org.kde.kpublictransport/ui/assets/wheelchair_accessible.svg";
            case KPublicTransport.Feature.SilentArea:
                return "qrc:///org.kde.kpublictransport/ui/assets/vehicle-feature-silentarea.svg";
            case KPublicTransport.Feature.BusinessArea:
                return "qrc:///org.kde.kpublictransport/ui/assets/vehicle-feature-businessarea.svg";
            case KPublicTransport.Feature.BikeStorage:
                return "qrc:///org.kde.kpublictransport/assets/images/transport-mode-bike.svg";
            case KPublicTransport.Feature.Toilet:
                return "qrc:///org.kde.kpublictransport/ui/assets/vehicle-feature-toilet.svg";
            case KPublicTransport.Feature.WheelchairAccessibleToilet:
                return "qrc:///org.kde.kpublictransport/ui/assets/vehicle-feature-wheelchair-toilet.svg";
            case KPublicTransport.Feature.InformationPoint:
                return "qrc:///org.kde.kpublictransport/ui/assets/vehicle-feature-information.svg";
            case KPublicTransport.Feature.WiFi:
                return "qrc:///org.kde.kpublictransport/ui/assets/vehicle-feature-wifi.svg";
            case KPublicTransport.Feature.PowerSockets:
                return "qrc:///org.kde.kpublictransport/ui/assets/vehicle-feature-powersocket.svg";
            case KPublicTransport.Feature.Other:
            default:
                return "documentinfo";
        }
    }

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
                return s + "emblem-warning";

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
                    break;
            }
        }
    }

    HoverHandler {
        id: hoverHandler
    }
    QQC2.ToolTip.visible: hoverHandler.hovered && QQC2.ToolTip.text !== ""
    QQC2.ToolTip.text: {
        let s = root.feature.displayName;

        if (root.feature.availability === KPublicTransport.Feature.Unavailable) {
            s = i18nd("kpublictransport", "%1 (not available)", s)
        }

        if (root.feature.quantity > 0) {
            s = i18ndp("kpublictransport", "%2 (one space)", "%2 (%1 spaces)", root.feature.quantity, s);
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

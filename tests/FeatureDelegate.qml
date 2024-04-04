/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Controls as QQC2
import org.kde.kpublictransport as KPublicTransport

QQC2.Label {
    id: root

    property var feature

    text: {
        let s = "";
        switch (feature.type) {
            case KPublicTransport.Feature.AirConditioning: s = "❄️"; break;
            case KPublicTransport.Feature.Restaurant: s = "🍴"; break;
            case KPublicTransport.Feature.ToddlerArea: s = "👶"; break;
            case KPublicTransport.Feature.FamilyArea: s = "👪"; break;
            case KPublicTransport.Feature.WheelchairAccessible: s = "♿"; break;
            case KPublicTransport.Feature.SilentArea: s = "🔇"; break;
            case KPublicTransport.Feature.BusinessArea: s = "📱"; break;
            case KPublicTransport.Feature.BikeStorage: s = "🚲"; break;
            case KPublicTransport.Feature.Toilet: s = "🚽"; break;
            case KPublicTransport.Feature.WheelchairAccessibleToilet: s = "♿🚽"; break;
            case KPublicTransport.Feature.InformationPoint: s = "ℹ️"; break;
            case KPublicTransport.Feature.WiFi: s = "💻"; break;
            case KPublicTransport.Feature.PowerSockets: s = "🔌"; break;
            case KPublicTransport.Feature.Other:
            default:
                s = "❔"; break;
        }
        if (feature.disruptionEffect === KPublicTransport.Disruption.NoService)
            return s + "⚠️";
        switch (feature.availability) {
            case KPublicTransport.Feature.Unknown: s += "(?)"; break;
            case KPublicTransport.Feature.Available: break;
            case KPublicTransport.Feature.Unavailable: s += "❌"; break;
            case KPublicTransport.Feature.Limited: s += "(limited)"; break;
            case KPublicTransport.Feature.Conditional: s += "(conditional)"; break;
        }
        if (feature.quatity > 0) {
            s += "(" + feature.quantity * ")"
        }
        return s;
    }

    HoverHandler {
        id: hoverHandler
    }
    QQC2.ToolTip.visible: hoverHandler.hovered
    QQC2.ToolTip.text: feature.name
    QQC2.ToolTip.delay: Qt.styleHints.mousePressAndHoldInterval
}

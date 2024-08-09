/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport

/** Train coach or vehicle occupancy indicator icon. */
Kirigami.Icon {
    id: root

    /** Occupancy level to display (KPublicTransport::Load::Category enum). */
    property int occupancy: KPublicTransport.Load.Unknown

    visible: root.occupancy !== KPublicTransport.Load.Unknown
    source: {
        switch (root.occupancy) {
            case KPublicTransport.Load.Low: return "qrc:///org.kde.kpublictransport/ui/assets/occupancy-low.svg";
            case KPublicTransport.Load.Medium: return "qrc:///org.kde.kpublictransport/ui/assets/occupancy-medium.svg";
            case KPublicTransport.Load.High: return "qrc:///org.kde.kpublictransport/ui/assets/occupancy-high.svg";
            case KPublicTransport.Load.Full: return "qrc:///org.kde.kpublictransport/ui/assets/occupancy-full.svg";
        }
    }
    isMask: true
    color: {
        switch (root.occupancy) {
            case KPublicTransport.Load.Low: return Kirigami.Theme.positiveTextColor;
            case KPublicTransport.Load.Medium: return "#fdbc4b";
            case KPublicTransport.Load.High: return Kirigami.Theme.neutralTextColor;
            case KPublicTransport.Load.Full: return Kirigami.Theme.negativeTextColor;
        }
        return Kirigami.Theme.textColor;
    }
    Accessible.name: {
        switch (root.occupancy) {
            case KPublicTransport.Load.Low: return i18ndc("kpublictransport", "vehicle occupancy", "Low occupancy");
            case KPublicTransport.Load.Medium: return i18ndc("kpublictransport", "vehicle occupancy", "Medium occupancy")
            case KPublicTransport.Load.High: return i18ndc("kpublictransport", "vehicle occupancy", "High occupancy")
            case KPublicTransport.Load.Full: return i18ndc("kpublictransport", "vehicle occupancy", "Full")
        }
        return "";
    }

    HoverHandler { id: hoverHandler }
    QQC2.ToolTip.visible: hoverHandler.hovered && Accessible.name !== ""
    QQC2.ToolTip.text: Accessible.name
    QQC2.ToolTip.delay: Kirigami.Units.toolTipDelay
}

/*
    SPDX-FileCopyrightText: ⓒ 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.kde.kirigami.delegates as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport

/** Combined icon and textual representation of a single vehicle feature.
 *  For use in e.g. a Repeater to show details about all available vehicle features
 *  and their availability/disruptions etc.
 *  @since 25.08
 */
RowLayout {
    id: delegateRoot
    /** The KPublicTransport::Feature to display. */
    required property KPublicTransport.feature feature

    spacing: Kirigami.Units.largeSpacing

    KPublicTransport.FeatureIcon {
        id: featureIcon
        feature: delegateRoot.feature
        Layout.preferredHeight: Kirigami.Units.iconSizes.smallMedium
        Layout.preferredWidth: Kirigami.Units.iconSizes.smallMedium
    }
    Kirigami.TitleSubtitle {
        Layout.fillWidth: true
        enabled: delegateRoot.feature.availability !== KPublicTransport.Feature.Unavailable
        title: delegateRoot.feature.displayName
        subtitle: {
            if (delegateRoot.feature.description !== "")
                return delegateRoot.feature.description;
            if (delegateRoot.feature.availability === KPublicTransport.Feature.Unknown)
                return i18nd("kpublictransport", "Availability unknown")
            if (delegateRoot.feature.availability === KPublicTransport.Feature.Unavailable)
                return i18nd("kpublictransport", "Not available")
            if (delegateRoot.feature.disruptionEffect === KPublicTransport.Disruption.NoService)
                return i18nd("kpublictransport", "Currently not available")
            if (delegateRoot.feature.quantity > 0)
                return i18ndcp("kpublictransport", "bike/wheelchair spaces on a train/bus", "One space", "%1 spaces", delegateRoot.feature.quantity);
            return "";
        }
    }
}

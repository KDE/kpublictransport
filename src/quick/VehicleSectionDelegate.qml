/*
    SPDX-FileCopyrightText: ⓒ 2019 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport

/** Single vehicle section element for the top-down vehicle layout view.
 *  @since 25.08
 */
KPublicTransport.VehicleSectionItem {
    id: delegateRoot

    /** The vehicle section to display. */
    required property KPublicTransport.vehicleSection vehicleSection

    section: delegateRoot.vehicleSection // TODO rename section property in VehicleSectionItem to vehicleSection

    /** User tapped any of the visual elements of this delegate. */
    signal tapped(eventPoint: eventPoint, button: int)

    TapHandler {
        enabled: delegateRoot.vehicleSection.sectionFeatures.length > 0 && delegateRoot.vehicleSection.disruptionEffect !== KPublicTransport.Disruption.NoService
        onTapped: (eventPoint, button) => { delegateRoot.tapped(eventPoint, button); }
    }

    ColumnLayout {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.right
        anchors.leftMargin: Kirigami.Units.largeSpacing
        spacing: Kirigami.Units.smallSpacing

        RowLayout {
            spacing: Kirigami.Units.smallSpacing
            visible: delegateRoot.vehicleSection.disruptionEffect !== KPublicTransport.Disruption.NoService
            Repeater {
                model: delegateRoot.section.sectionFeatures
                delegate: KPublicTransport.FeatureIcon {
                    required property KPublicTransport.feature modelData
                    feature: modelData
                    Layout.preferredHeight: Kirigami.Units.iconSizes.small
                    Layout.preferredWidth: Kirigami.Units.iconSizes.small
                }
            }
        }
        QQC2.Label {
            visible: delegateRoot.section.classes != KPublicTransport.VehicleSection.UnknownClass
            text: delegateRoot.section.classesName
            color: delegateRoot.vehicleSection.disruptionEffect === KPublicTransport.Disruption.NoService ?
                    Kirigami.Theme.disabledTextColor :  Kirigami.Theme.textColor
        }
        KPublicTransport.OccupancyIndicator {
            occupancy: delegateRoot.vehicleSection.load
            Layout.preferredHeight: Kirigami.Units.iconSizes.small
            Layout.preferredWidth: Kirigami.Units.iconSizes.small
        }

        TapHandler {
            enabled: delegateRoot.vehicleSection.sectionFeatures.length > 0 && delegateRoot.vehicleSection.disruptionEffect !== KPublicTransport.Disruption.NoService
            onTapped: (eventPoint, button) => { delegateRoot.tapped(eventPoint, button); }
        }
    }
}

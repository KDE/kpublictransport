/*
    SPDX-FileCopyrightText: ⓒ 2025 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport

/** Combined icon and textual representation of a single occupancy information.
 *  This can be a global one or one for a single seating class.
 *  @since 25.08
 */
RowLayout {
    id: delegateRoot
    /** Full occupancy information, if available */
    property KPublicTransport.loadInfo occupancyInfo
    /** Occupancy level, if the full information isn't available. */
    property int occupancy: delegateRoot.occupancyInfo.load

    KPublicTransport.OccupancyIndicator {
        id: occupancyIcon
        occupancy: delegateRoot.occupancy
        Layout.preferredHeight: Kirigami.Units.iconSizes.smallMedium
        Layout.preferredWidth: Kirigami.Units.iconSizes.smallMedium
    }
    QQC2.Label {
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignHCenter
        text: {
            const classes = KPublicTransport.ClassUtil.fromString(delegateRoot.occupancyInfo.seatingClass)
            if (classes === KPublicTransport.VehicleSection.FirstClass || classes === KPublicTransport.VehicleSection.SecondClass) {
                return i18ndc("kpublictransport", "seating class type: occupancy level", "%1: %2", KPublicTransport.ClassUtil.displayName(classes), occupancyIcon.Accessible.name);
            }
            return occupancyIcon.Accessible.name;
        }
    }
}

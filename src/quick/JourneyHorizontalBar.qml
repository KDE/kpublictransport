/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>
    SPDX-FileCopyrightText: 2023 Carl Schwan <carl@carlschwan.eu>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport

/** Display a journey as a horizontal bar with elements for the individual journey sections.
 *  @since 25.04
 */
RowLayout {
    id: root

    /** The journey to display. */
    property KPublicTransport.journey journey

    spacing: Kirigami.Units.smallSpacing

    Repeater {
        id: repeater
        model: root.journey.sections
        delegate: TransportNameControl {
            id: delegateRoot

            required property KPublicTransport.journeySection modelData
            journeySection: modelData

            Layout.fillWidth: true
            Layout.maximumWidth: delegateRoot.modelData.mode === KPublicTransport.JourneySection.PublicTransport ? Number.POSITIVE_INFINITY : implicitWidth
            // TODO scale by duration when we have enough space
            // TODO cancelation indicators
            // TODO warning indicators for suspicously long segments
        }
    }
}

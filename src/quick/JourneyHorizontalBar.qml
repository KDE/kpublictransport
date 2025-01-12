/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>
    SPDX-FileCopyrightText: 2023 Carl Schwan <carl@carlschwan.eu>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

pragma ComponentBehavior: Bound

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
    Layout.fillWidth: true

    // minimum width we need to show the journey without eliding/clipping/etc
    readonly property real __minimumWidth: {
        if (repeater.count != root.journey.sections.length || repeater.count === 0) // still being populated
            return 0.0;
        let s = 0.0;
        for (const v of root.children) {
            if (v as TransportNameControl)
                s += v.implicitWidth
        }
        s += (repeater.count - 1) * root.spacing;
        return s;
    }

    Repeater {
        id: repeater
        model: root.journey.sections
        delegate: TransportNameControl {
            id: delegateRoot

            required property KPublicTransport.journeySection modelData
            journeySection: modelData

            Layout.fillWidth: true
            Layout.maximumWidth: delegateRoot.modelData.mode === KPublicTransport.JourneySection.PublicTransport ? Number.POSITIVE_INFINITY : implicitWidth
            Layout.minimumWidth: root.__minimumWidth < root.width ? implicitWidth : 0

            // when we have the space, size public transport sections based on their duration
            Layout.preferredWidth: implicitWidth + (delegateRoot.modelData.mode === KPublicTransport.JourneySection.PublicTransport ? (delegateRoot.journeySection.duration / root.journey.duration) * (root.width - (root.journey.sections.length * root.spacing) - root.__minimumWidth) : 0)

            // TODO cancelation indicators
            // TODO warning indicators for suspicously long segments
        }
    }
}

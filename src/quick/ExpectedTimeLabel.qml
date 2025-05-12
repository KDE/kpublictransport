// SPDX-FileCopyrightText: 2024 Carl Schwan <carl@carlschwan.eu>
// SPDX-License-Identifier: LGPL-2.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.coreaddons as CoreAddons
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport

/**
 *  Element for showing expected/scheduled departure or arrival times at a stopover.
 *
 *  @since 25.08
 */
RowLayout {
    id: root

    /** Stopover to which this time applies to.
     *  This is used to check for other disruptions that might apply, such as a cancelation.
     */
    required property KPublicTransport.stopover stopover
    /** Delay in minutes at the stop. */
    required property int delay
    /** Scheduled time, formatted as string already. */
    required property string scheduledTime
    /** Indicate whether the expected time is known. */
    required property bool hasExpectedTime

    readonly property bool delayed: Math.abs(root.delay) > 1 || root.stopover.disruptionEffect === KPublicTransport.Disruption.NoService
    spacing: 0

    Kirigami.Heading {
        level: 5
        text: if (root.stopover.disruptionEffect === KPublicTransport.Disruption.NoService) {
            return i18ndc("kpublictransport", "a train/bus journey canceled by its operator", "Canceled") + (root.scheduledTime ? ' · ' : '');
        } else if (root.delay > 0) {
            return i18ndc("kpublictransport", "duration of the delay", "Delayed %1", CoreAddons.Format.formatDuration(root.delay * 60 * 1000, CoreAddons.FormatTypes.AbbreviatedDuration | CoreAddons.FormatTypes.HideSeconds)) + (root.scheduledTime ? ' · ' : '');
        } else if (root.delay < 0) {
            return i18ndc("kpublictransport", "earlier arrival/departure", "%1 earlier", CoreAddons.Format.formatDuration(-root.delay * 60 * 1000, CoreAddons.FormatTypes.AbbreviatedDuration | CoreAddons.FormatTypes.HideSeconds)) + (root.scheduledTime ? ' · ' : '');
        } else if (root.hasExpectedTime) {
            return i18ndc("kpublictransport", "@info", "On time") + (root.scheduledTime ? ' · ' : '');
        } else {
            return '';
        }
        color: root.delayed ? Kirigami.Theme.negativeTextColor : Kirigami.Theme.positiveTextColor
        font.weight: Font.DemiBold
    }

    QQC2.Label {
        opacity: 0.8
        text: root.scheduledTime
        font.strikeout: root.delayed
    }
}

// SPDX-FileCopyrightText: 2024 Carl Schwan <carl@carlschwan.eu>
// SPDX-License-Identifier: LGPL-2.0-or-later

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport

/** Visual representation of a journey section in a horizontal bar display.
 *  Also usable as a stand-alone transport line indicator.
 *
 *  Public transport sections are shown in line colors (or inverted text colors if none available),
 *  all other section modes are shown in regular text colors without background.
 */
Kirigami.Padding {
    id: root

    /** The journey section to represent.
     *  Setting this (and leaving all other properties untouched) is the easiest and preferred
     *  way of using this.
     *
     *  If set all other properties are populated from this automatically.
     *  If not set, at least line and journeySectionMode need to be specified instead.
     */
    property KPublicTransport.journeySection journeySection

    /** Line information of the journey section. */
    property KPublicTransport.line line: journeySection.route.line

    /** Journey section mode.
     *  @see KPublicTransport::JourneySection::Mode
     */
    property int journeySectionMode: root.journeySection.mode === KPublicTransport.JourneySection.Invalid ? KPublicTransport.JourneySection.PublicTransport : root.journeySection.mode

    /** Description of the journey section mode.
     *  Not displayed in the UI but used as an a11y text for mode icons.
     */
    property string modeName: root.journeySection.label

    /** Icon representing the mode of transport or the line logo. */
    property string iconName: root.journeySection.mode === KPublicTransport.JourneySection.Invalid ? root.line.iconName : root.journeySection.iconName
    /** Displayed name of the public transport line. */
    property string lineName: root.line.name

    /** The lower limit of the width this item can take **/
    readonly property int minimumWidth: Kirigami.Units.iconSizes.smallMedium + Kirigami.Units.smallSpacing * 2

    /**
     * Whether the item should try to adapt to a lack of space (width)
     * Default: false
    **/
    property bool squashToFit: false

    leftPadding: Kirigami.Units.smallSpacing
    rightPadding: Kirigami.Units.smallSpacing
    topPadding: Kirigami.Units.smallSpacing
    bottomPadding: Kirigami.Units.smallSpacing

    Rectangle {
        id: background

        function isDark(color) {
            return color.hslLightness < 0.5
        }

        border.color: isDark(background.color) == isDark(Kirigami.Theme.backgroundColor) ? lineName.color : background.color

        radius: Kirigami.Units.cornerRadius
        color: root.line.hasColor ? root.line.color : Kirigami.Theme.textColor
        visible: root.journeySectionMode === KPublicTransport.JourneySection.PublicTransport

        anchors.fill: parent

        z: -1
    }

    contentItem: Item {
        implicitWidth: Kirigami.Units.iconSizes.smallMedium
            + (lineName.visible
                ? Kirigami.Units.smallSpacing + lineName.implicitWidth
                : 0)
        implicitHeight: Kirigami.Units.iconSizes.smallMedium

        KPublicTransport.TransportIcon {
            id: transportIcon

            color: background.visible
                ? lineName.color
                : Kirigami.Theme.textColor

            isMask: true
            iconHeight: Kirigami.Units.iconSizes.smallMedium
            source: root.iconName
            Accessible.name: root.modeName

            width: Kirigami.Units.iconSizes.smallMedium
            height: Kirigami.Units.iconSizes.smallMedium

            anchors.verticalCenter: parent.verticalCenter

            x: lineName.visible
                ? (parent.width - width - Kirigami.Units.smallSpacing
                    - lineName.width) / 2
                : (parent.width - width) / 2
        }

        Kirigami.Heading {
            id: lineName

            readonly property bool isDarkTheme: Kirigami.Theme.backgroundColor.hslLightness < 0.4

            color: {
                const backgroundIsDark = background.color.hslLightness < 0.4;

                if (root.line.hasTextColor) {
                    const foregroundIsLight = root.line.textColor.hslLightness >= 0.4;
                    if (foregroundIsLight === backgroundIsDark) {
                        return root.line.textColor;
                    }
                    // fallthrough and use our own color has the line text color doesn't offer enough contrast
                    // Test case U4 in Berlin
                }

                if (backgroundIsDark)
                    return isDarkTheme ? Kirigami.Theme.textColor : Kirigami.Theme.backgroundColor;
                return isDarkTheme ? Kirigami.Theme.backgroundColor : Kirigami.Theme.textColor;
            }

            level: 4
            text: root.lineName
            visible: text.length > 0 && root.journeySectionMode === KPublicTransport.JourneySection.PublicTransport && !root.line.hasLogo &&
                    !(squashToFit && lineName.contentWidth > lineName.width)

            font.weight: Font.DemiBold
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight

            width: visible
                ? Math.min(implicitWidth,
                    Math.max(0, parent.width
                        - transportIcon.width
                        - Kirigami.Units.smallSpacing))
                : 0

            height: Kirigami.Units.iconSizes.smallMedium

            anchors.verticalCenter: parent.verticalCenter

            x: transportIcon.x + transportIcon.width
                + (visible ? Kirigami.Units.smallSpacing : 0)
        }
    }

}

/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami

/** Displays a transport line or mode logo/icon.
 *  Mainly to hide ugly implementation details of Icon not
 *  handling non-square SVG assets in the way we need it here.
 *
 *  @since 25.04
 */
Loader {
    id: root

    // properties match those of Icon
    property string source
    property bool isMask: false
    property color color

    /** Icon height (and width for squre ones) */
    property int iconHeight: Kirigami.Units.iconSizes.smallMedium

    // internal
    property bool __isIcon: !source.startsWith("file:")

    Layout.preferredWidth: root.implicitWidth
    Layout.preferredHeight: root.implicitHeight

    active: true

    Component {
        id: iconComponent

        Kirigami.Icon {
            id: __icon

            implicitWidth: root.iconHeight
            implicitHeight: root.iconHeight

            source: root.source
            isMask: root.isMask
            color: root.color
            anchors.fill: parent
        }
    }

    Component {
        id: imageComponent

        Image {
            id: __image

            property int implicitWidth: Math.round(root.iconHeight * __image.implicitWidth / __image.implicitHeight)
            property int implicitHeight: root.iconHeight

            source: root.source
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            sourceSize.height: root.iconHeight
        }
    }

    sourceComponent: root.__isIcon ? iconComponent : imageComponent
}

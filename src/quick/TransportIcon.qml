/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami

/** Displays a transport line or mode logo/icon.
 *  Mainly to hide ugly implementation details of Icon not
 *  handling non-square SVG assets in the way we need it here.
 *
 *  @since 25.04
 */
Item {
    id: root
    // properties match those of Icon
    property string source
    property alias isMask: __icon.isMask
    property alias color: __icon.color

    /** Icon height (and width for squre ones) */
    property int iconHeight: Kirigami.Units.iconSizes.smallMedium

    // internal
    property bool __isIcon: !source.startsWith("file:")

    implicitWidth: __isIcon ? root.iconHeight : Math.round(root.iconHeight * __image.implicitWidth / __image.implicitHeight)
    implicitHeight: root.iconHeight

    Layout.preferredWidth: root.implicitWidth
    Layout.preferredHeight: root.implicitHeight

    Kirigami.Icon {
        id: __icon
        source: root.__isIcon ? root.source : ""
        visible: source !== ""
        anchors.fill: parent
    }
    Image {
        id: __image
        source: root.__isIcon ? "" : root.source
        visible: source !== ""
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
        sourceSize.height: root.iconHeight
    }
}

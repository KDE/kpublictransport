/*
    SPDX-FileCopyrightText: 2021-2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Controls as QQC2
import org.kde.i18n.localeData

/** Combo box for showing a list of countries.
 *  The model is expected to be CoverageCountryModel.
 */
QQC2.ComboBox {
    id: root

    /** The currently selected country, as a KCountry object. */
    readonly property var currentCountry: Country.fromAlpha2(currentValue)

    /** Initially selected country. */
    property string initialCountry

    displayText: currentCountry ? (currentCountry.emojiFlag + ' ' + currentCountry.name) : ""
    valueRole: "code"

    delegate: QQC2.ItemDelegate {
        id: delegate
        required property string code
        text: {
            const c = Country.fromAlpha2(delegate.code);
            return "<span style='font.family: \"emoji\">'" + c.emojiFlag + '</span> ' + c.name;
        }
        width: parent ? parent.width : undefined

        Accessible.name: Country.fromAlpha2(delegate.code).name
        Accessible.onPressAction: delegate.clicked()
    }

    Component.onCompleted: {
        if (initialCountry) {
            currentIndex = Math.max(indexOfValue(initialCountry), 0);
        }
    }

    Accessible.name: currentCountry.name
    Accessible.description: i18nd("publictransport", "Select country")
    Accessible.onPressAction: root.popup.open()
}

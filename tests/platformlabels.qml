/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport

Kirigami.ApplicationWindow {
    GridLayout {
        rows: 4
        columns: 3
        rowSpacing: Kirigami.Units.largeSpacing
        columnSpacing: Kirigami.Units.largeSpacing * 4
        flow: GridLayout.TopToBottom

        Repeater {
            model: [Line.Train, Line.Bus, Line.Ferry, Line.Air]
            Kirigami.Icon {
                required property int modelData
                source: LineMode.iconName(modelData)
                Layout.preferredWidth: Kirigami.Units.iconSizes.medium
                Layout.preferredHeight: Kirigami.Units.iconSizes.medium
            }
        }

        Repeater {
            model: [Line.Train, Line.Bus, Line.Ferry, Line.Air]
            Label {
                required property int modelData
                text: Platform.displayString(modelData)
            }
        }

        Repeater {
            model: [Line.Train, Line.Bus, Line.Ferry, Line.Air]
            Label {
                required property int modelData
                text: Platform.displayString(modelData, "4", Locale.LongFormat)
            }
        }

        Repeater {
            model: [Line.Train, Line.Bus, Line.Ferry, Line.Air]
            Label {
                required property int modelData
                text: Platform.displayString(modelData, "4", Locale.ShortFormat)
            }
        }
    }
}

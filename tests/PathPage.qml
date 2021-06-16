/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import org.kde.kirigami 2.12 as Kirigami
import org.kde.kpublictransport 1.0

Kirigami.ScrollablePage {
    property var path

    Component {
        id: pathDelegate
        Kirigami.BasicListItem {
            text: modelData.description + " (" + modelData.distance + "m)"
        }
    }

    ListView {
        model: path.sections
        delegate: pathDelegate
    }
}

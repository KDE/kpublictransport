/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.12
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import org.kde.kirigami 2.7 as Kirigami
import org.kde.kosmindoormap 1.0

Kirigami.Page {
    title: map.floorLevels.hasName(map.view.floorLevel) ? map.floorLevels.name(map.view.floorLevel) : ("Floor " + map.floorLevels.name(map.view.floorLevel));
    property point coordinate
    property alias map: map
    property alias debug: infoModel.debug

    topPadding: 0
    bottomPadding: 0
    leftPadding: 0
    rightPadding: 0

    // prevent swipe to the right changing pages, we want to pan the map instead
    // TODO in theory we could make this conditional to having panned the map all the way to the right
    Kirigami.ColumnView.preventStealing: true

    actions {
        left: Kirigami.Action {
            iconName: "go-down-symbolic"
            enabled: map.floorLevels.hasFloorLevelBelow(map.view.floorLevel)
            onTriggered: map.view.floorLevel = map.floorLevels.floorLevelBelow(map.view.floorLevel)
        }
        right: Kirigami.Action {
            iconName: "go-up-symbolic"
            enabled: map.floorLevels.hasFloorLevelAbove(map.view.floorLevel)
            onTriggered: map.view.floorLevel = map.floorLevels.floorLevelAbove(map.view.floorLevel)
        }
    }

    OSMElementInformationModel {
        id: infoModel
        debug: true
    }

    Component {
        id: infoStringDelegate
        Row {
            QQC2.Label {
                visible: row.keyLabel != ""
                text: row.keyLabel + ": "
                color: row.category == OSMElementInformationModel.DebugCategory ? Kirigami.Theme.disabledTextColor : Kirigami.Theme.textColor
            }
            QQC2.Label {
                text: row.value
                color: row.category == OSMElementInformationModel.DebugCategory ? Kirigami.Theme.disabledTextColor : Kirigami.Theme.textColor
            }
        }
    }

    Component {
        id: infoLinkDelegate
        Row {
            QQC2.Label {
                visible: row.keyLabel != ""
                text: row.keyLabel + ": "
                color: row.category == OSMElementInformationModel.DebugCategory ? Kirigami.Theme.disabledTextColor : Kirigami.Theme.textColor
            }
            QQC2.Label {
                text: "<a href=\"" + row.url + "\">" + row.value + "</a>"
                color: row.category == OSMElementInformationModel.DebugCategory ? Kirigami.Theme.disabledTextColor : Kirigami.Theme.textColor
                onLinkActivated: Qt.openUrlExternally(link)
            }
        }
    }

    Component {
        id: infoAddressDelegate
        QQC2.Label {
            text: (row.value.street + " " + row.value.houseNumber + "\n" + row.value.postalCode + " " + row.value.city + "\n" + row.value.country).trim()
        }
    }

    Kirigami.OverlaySheet {
        id: elementDetailsSheet

        header: Column {
            Kirigami.Heading {
                text: infoModel.name
            }
            Kirigami.Heading {
                text: infoModel.category
                level: 4
                visible: text != ""
            }
        }

        ListView {
            model: infoModel

            section.property: "categoryLabel"
            section.delegate: Kirigami.Heading {
                x: Kirigami.Units.largeSpacing
                level: 4
                text: section
                color: section == "Debug" ? Kirigami.Theme.disabledTextColor : Kirigami.Theme.textColor
                height: implicitHeight + Kirigami.Units.largeSpacing
                verticalAlignment: Qt.AlignBottom
            }
            section.criteria: ViewSection.FullString
            section.labelPositioning: ViewSection.CurrentLabelAtStart | ViewSection.InlineLabels

            delegate: Loader {
                property var row: model
                x: Kirigami.Units.largeSpacing
                sourceComponent: {
                    switch (row.type) {
                        case OSMElementInformationModel.Link:
                            return infoLinkDelegate;
                        case OSMElementInformationModel.PostalAddress:
                            return infoAddressDelegate;
                        default:
                            return infoStringDelegate;
                    }
                }
            }
        }

        onSheetOpenChanged: {
            if (sheetOpen == false) {
                infoModel.clear()
            }
        }
    }

    IndoorMap {
        id: map
        anchors.fill: parent

        IndoorMapScale {
            map: map
            anchors.left: map.left
            anchors.bottom: map.bottom
            width: 0.3 * map.width
        }

        IndoorMapAttributionLabel {
            anchors.right: map.right
            anchors.bottom: map.bottom
        }

        onElementPicked: {
            infoModel.element = element;
            if (infoModel.name != "" || infoModel.debug) {
                elementDetailsSheet.sheetOpen = true;
            }
        }
    }

    onCoordinateChanged: map.mapLoader.loadForCoordinate(coordinate.y, coordinate.x);
}

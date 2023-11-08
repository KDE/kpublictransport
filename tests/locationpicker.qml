/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15 as QQC2
import org.kde.kirigami 2.17 as Kirigami
import org.kde.kitemmodels 1.0
import org.kde.i18n.localeData 1.0
import org.kde.kpublictransport 1.0

Kirigami.ApplicationWindow {
    title: "Location Picker Example"
    reachableModeEnabled: false

    width: 540
    height: 720

    pageStack.initialPage: locationPickerPage

    Manager {
        id: ptMgr
    }

    Component {
        id: locationPickerPage
        Kirigami.ScrollablePage {
            actions.contextualActions: [
                Kirigami.Action {
                    text: "Remove All"
                    onTriggered: locationHistoryModel.clear()
                }
            ]
            header: ColumnLayout {
                QQC2.ComboBox {
                    id: countryCombo
                    model: {
                        var countries = new Array();
                        for (const b of ptMgr.backends) {
                            for (const t of [CoverageArea.Realtime, CoverageArea.Regular, CoverageArea.Any]) {
                                for (const c of b.coverageArea(t).regions) {
                                    if (c != 'UN' && c != 'EU') {
                                        countries.push(c.substr(0, 2));
                                    }
                                }
                            }
                        }
                        return [...new Set(countries)].sort();
                    }
                    Layout.fillWidth: true
                    readonly property var currentCountry: Country.fromAlpha2(currentValue)
                    displayText: currentCountry.emojiFlag + ' ' + currentCountry.name
                    delegate: QQC2.ItemDelegate {
                        text: {
                            const c = Country.fromAlpha2(modelData);
                            return c.emojiFlag + ' ' + c.name;
                        }
                        width: parent ? parent.width : undefined
                    }
                    Component.onCompleted: {
                        countryCombo.currentIndex = countryCombo.indexOfValue(Qt.locale().name.match(/_([A-Z]{2})/)[1])
                    }
                }
                Kirigami.SearchField {
                    id: queryTextField
                    Layout.fillWidth: true
                    onAccepted: {
                        if (text !== "") {
                            var loc = locationQueryModel.request.location;
                            loc.name = text;
                            loc.country = countryCombo.currentValue;
                            locationQueryModel.request.location = loc;
                            locationQueryModel.request.type = Location.Stop
                        }
                    }
                }
                QQC2.ButtonGroup { buttons: sortGroup.children }
                RowLayout {
                    id: sortGroup
                    QQC2.RadioButton {
                        text: "Name"
                        onCheckedChanged: {
                            historySortModel.sortRole = "locationName";
                            historySortModel.sortOrder = Qt.AscendingOrder;
                        }
                    }
                    QQC2.RadioButton {
                        checked: true
                        text: "Most Recent"
                        onCheckedChanged: {
                            historySortModel.sortRole = "lastUsed";
                            historySortModel.sortOrder = Qt.DescendingOrder;
                        }
                    }
                    QQC2.RadioButton {
                        text: "Most Often"
                        onCheckedChanged: {
                            historySortModel.sortRole = "useCount";
                            historySortModel.sortOrder = Qt.DescendingOrder;
                        }
                    }
                }
            }

            LocationQueryModel {
                id: locationQueryModel
                manager: ptMgr
                queryDelay: 500
            }
            LocationHistoryModel {
                id: locationHistoryModel
            }
            KSortFilterProxyModel {
                id: historySortModel
                sourceModel: locationHistoryModel
                sortRole: "lastUsed"
                sortOrder: Qt.DescendingOrder
            }

            Component {
                id: historyDelegate
                Kirigami.SwipeListItem {
                    readonly property var sourceModel: ListView.view.model
                    contentItem: QQC2.Label {
                        text: model.location.name
                    }
                    actions: [
                        Kirigami.Action {
                            iconName: "edit-delete"
                            text: "Remove history entry"
                            onTriggered: {
                                sourceModel.removeRows(model.index, 1)
                            }
                        }
                    ]
                    onClicked: {
                        locationHistoryModel.addLocation(model.location);
                    }
                }
            }

            Component {
                id: queryResultDelegate
                Kirigami.BasicListItem {
                    text: model.location.name
                    onClicked: {
                        locationHistoryModel.addLocation(model.location);
                        queryTextField.text = "";
                    }
                }
            }

            ListView {
                id: historyView
                model: queryTextField.text === "" ? historySortModel : locationQueryModel
                delegate: queryTextField.text === "" ? historyDelegate : queryResultDelegate

                QQC2.BusyIndicator {
                    anchors.centerIn: parent
                    running: locationQueryModel.loading
                }

                QQC2.Label {
                    anchors.centerIn: parent
                    width: parent.width
                    text: locationQueryModel.errorMessage
                    color: Kirigami.Theme.negativeTextColor
                    wrapMode: Text.Wrap
                }
            }
        }
    }
}

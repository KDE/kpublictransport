/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kitemmodels
import org.kde.i18n.localeData
import org.kde.kpublictransport as PublicTransport
import org.kde.kirigamiaddons.delegates as Delegates
import './private' as Private

Kirigami.ScrollablePage {
    id: root

    /**
     * Initially selected country.
     * If not specified the country from the current locale is used.
     */
    property string initialCountry: Qt.locale().name.match(/_([A-Z]{2})/)[1]
    required property PublicTransport.Manager publicTransportManager
    property PublicTransport.location location

    property alias historySortRoleName: historySortModel.sortRoleName
    signal historySortRoleChanged(string sortRoleName)

    /** See LocationRequest::downloadAssets.
     *  @since 25.12
     */
    property bool downloadAssets: false

    Kirigami.PromptDialog {
        id: clearConfirmDialog
        title: i18ndc("kpublictransport", "@title:dialog", "Clear History")
        subtitle: i18ndc("kpublictransport", "@info", "Do you really want to remove all previously searched locations?")
        standardButtons: QQC2.Dialog.Cancel
        customFooterActions: [
            Kirigami.Action {
                text: i18ndc("kpublictransport", "@action:button", "Remove")
                icon.name: "edit-clear-history-symbolic"
                onTriggered: {
                    locationHistoryModel.clear();
                    clearConfirmDialog.close();
                }
            }
        ]
    }

    QQC2.ActionGroup { id: sortActionGroup }

    actions: [
        QQC2.Action {
            text: i18ndc("kpublictransport", "@action", "Clear history")
            icon.name: "edit-clear-history-symbolic"
            onTriggered: clearConfirmDialog.open()
        },
        Kirigami.Action { separator: true },
        QQC2.Action {
            QQC2.ActionGroup.group: sortActionGroup
            checkable: true
            checked: historySortModel.sortRoleName === "locationName"
            text: i18ndc("kpublictransport", "@action", "Sort by name")
            icon.name: 'sort-name-symbolic'
            onTriggered: historySortModel.sortRoleName = "locationName"
        },
        QQC2.Action {
            QQC2.ActionGroup.group: sortActionGroup
            checkable: true
            checked: historySortModel.sortRoleName === "lastUsed"
            text: i18ndc("kpublictransport", "@action", "Most recently used")
            onTriggered: historySortModel.sortRoleName = "lastUsed"
        },
        QQC2.Action {
            QQC2.ActionGroup.group: sortActionGroup
            checkable: true
            checked: historySortModel.sortRoleName === "useCount"
            text: i18ndc("kpublictransport", "@action", "Most often used")
            onTriggered: historySortModel.sortRoleName = "useCount"
        }
    ]

    function updateQuery(): void {
        if (queryTextField.text !== "" && countryCombo.currentValue !== "") {
            locationQueryModel.request = {
                location: {
                    name: queryTextField.text,
                    country: countryCombo.currentValue
                },
                types: PublicTransport.Location.Stop | PublicTransport.Location.Address,
                downloadAssets: root.downloadAssets
            };
        }
    }

    header: ColumnLayout {
        spacing: Kirigami.Units.smallSpacing

        Private.CountryComboBox {
            id: countryCombo
            Layout.topMargin: Kirigami.Units.smallSpacing
            Layout.leftMargin: Kirigami.Units.smallSpacing
            Layout.rightMargin: Kirigami.Units.smallSpacing
            Layout.fillWidth: true
            model: PublicTransport.CoverageCountryModel {
                manager: root.publicTransportManager
            }
            initialCountry: root.initialCountry
            onCurrentValueChanged: root.updateQuery();
        }

        Kirigami.SearchField {
            id: queryTextField
            Layout.leftMargin: Kirigami.Units.smallSpacing
            Layout.rightMargin: Kirigami.Units.smallSpacing
            Layout.fillWidth: true
            onAccepted: root.updateQuery();
        }

        Kirigami.Separator {
            Layout.fillWidth: true
        }
    }

    PublicTransport.LocationQueryModel {
        id: locationQueryModel
        manager: root.publicTransportManager
        queryDelay: 500
    }

    readonly property PublicTransport.LocationHistoryModel locationHistoryModel: PublicTransport.LocationHistoryModel {
        id: locationHistoryModel
    }

    KSortFilterProxyModel {
        id: historySortModel
        sourceModel: locationHistoryModel
        sortOrder: sortRoleName == "locationName" ? Qt.AscendingOrder : Qt.DescendingOrder
        sortCaseSensitivity: Qt.CaseInsensitive
        onSortRoleChanged: root.historySortRoleChanged(sortRoleName)
    }

    component BaseDelegate : Delegates.RoundedItemDelegate {
        id: delegate

        required property int index
        required property PublicTransport.location location

        readonly property string subtitle: {
            const country = Country.fromAlpha2(location.country)
            const region = CountrySubdivision.fromCode(location.region)

            if (location.locality && location.name !== location.locality && location.country && location.region) {
                return i18ndc("publictransport", "locality, region, country", "%1, %2, %3",
                             location.locality,
                             region ? region.name : location.region,
                             country ? country.name : location.country)
            } else if (location.locality && location.name !== location.locality && location.country) {
                return i18ndc("publictransport", "locality, country", "%1, %2",
                             location.locality,
                             country ? country.name : location.country)
            } else if (location.region && location.country) {
                return i18ndc("publictransport", "region, country", "%1, %2",
                             region ? region.name : location.region,
                             country ? country.name : location.country)
            } else if (location.country) {
                return country ? country.name : location.country;
            } else {
                return " "
            }
        }

        icon {
            name: location.iconName
            width: Kirigami.Units.iconSizes.medium
            height: Kirigami.Units.iconSizes.medium
        }

        text: location.name

        Accessible.name: {
            const country = Country.fromAlpha2(location.country)
            const region = CountrySubdivision.fromCode(location.region)

            if (location.locality && location.name !== location.locality && location.region && location.country) {
                return i18ndc("publictransport", "location name, locality, region, country", "%1, %2, %3, %4",
                             location.name,
                             location.locality,
                             region ? region.name : location.region,
                             country ? country.name : location.country)
            } else if (location.locality && location.name !== location.locality && location.country) {
                return i18ndc("publictransport", "location name, locality, country", "%1, %2, %3",
                             location.name,
                             location.locality,
                             country ? country.name : location.country)
            } else if (location.region && location.country) {
                return i18ndc("publictransport", "location name, region, country", "%1, %2, %3",
                             location.name,
                             region ? region.name : location.region,
                             country ? country.name : location.country)
            } else if (location.country) {
                return i18ndc("publictransport", "location name, country", "%1, %2",
                             location.name,
                             country ? country.name : location.country);
            } else {
                return location.name
            }
        }

        Accessible.description: ''
        Accessible.onPressAction: delegate.clicked()
    }

    Component {
        id: historyDelegate

        BaseDelegate {
            id: delegate

            required property bool removable
            readonly property PublicTransport.LocationHistoryModel sourceModel: ListView.view.model

            contentItem: RowLayout {
                spacing: Kirigami.Units.smallSpacing

                Delegates.SubtitleContentItem {
                    itemDelegate: delegate
                    subtitle: delegate.subtitle
                }

                QQC2.ToolButton {
                    icon.name: "edit-delete-symbolic"
                    text: i18ndc("publictransport", "@action:button", "Remove history entry")
                    display: QQC2.ToolButton.IconOnly
                    onClicked: {
                        sourceModel.removeRows(delegate.index, 1)
                    }
                    enabled: delegate.removable
                }
            }

            onClicked: {
                root.location = delegate.location;
                locationHistoryModel.addLocation(delegate.location);
                QQC2.ApplicationWindow.window.pageStack.goBack();
            }
        }
    }

    Component {
        id: queryResultDelegate

        BaseDelegate {
            id: delegate

            contentItem: Delegates.SubtitleContentItem {
                Accessible.ignored: true
                itemDelegate: delegate
                subtitle: delegate.subtitle
            }

            onClicked: {
                root.location = location
                locationHistoryModel.addLocation(location);
                QQC2.ApplicationWindow.window.pageStack.goBack();
                queryTextField.clear();
            }
        }
    }

    ListView {
        id: locationView
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

        Kirigami.PlaceholderMessage {
            text: i18ndc("publictransport", "@info:placeholder", "No locations found")
            visible: locationView.count === 0 && !locationQueryModel.loading && queryTextField.text !== ""
            anchors.centerIn: parent
            width: parent.width - Kirigami.Units.gridUnit * 4
        }
    }

    Component.onCompleted: {
        if (locationView.count === 0)
            queryTextField.forceActiveFocus();
    }
}

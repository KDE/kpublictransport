// SPDX-FileCopyrightText: 2019-2021 Volker Krause <vkrause@kde.org>
// SPDX-FileCopyrightText: 2023 Carl Schwan <carl@carlschwan.eu>
// SPDX-License-Identifier: LGPL-2.0-or-later

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kitemmodels
import org.kde.kpublictransport as KPublicTransport
import org.kde.itinerary
import org.kde.kirigamiaddons.formcard as FormCard

Kirigami.ScrollablePage {
    id: root

    property KPublicTransport.JourneyQueryModel journeyModel

    /**
     * Trigerred when an user selected a journey
     */
    signal journeySelected(var journey)

    Kirigami.Theme.inherit: false
    Kirigami.Theme.colorSet: Kirigami.Theme.Window

    ListView {
        id: journeyView

        clip: true

        delegate: FormCard.FormCard {
            id: top

            width: ListView.view.width

            required property int index
            required property var journey

            Repeater {
                id: journeyRepeater
                delegate: JourneySectionDelegate {
                    Layout.fillWidth: true
                    modelLength: journeyRepeater.count - 1
                }
                model: journeyView.currentIndex === top.index ? top.journey.sections : 0
            }

            JourneySummaryDelegate {
                id: summaryButton

                journey: top.journey
                visible: journeyView.currentIndex !== top.index
                onClicked: journeyView.currentIndex = top.index

                Layout.fillWidth: true
            }

            FormCard.FormDelegateSeparator {
                visible: journeyView.currentIndex === top.index
                above: selectButton
            }

            FormCard.FormButtonDelegate {
                id: selectButton

                text: i18ndc("kpublictransport", "@action:button", "Select")
                icon.name: "checkmark"
                visible: journeyView.currentIndex === top.index
                enabled: top.journey.disruptionEffect !== Disruption.NoService
                onClicked: root.journeySelected(top.journey)
            }
        }

        section {
            property: "scheduledDepartureDate"
            delegate: FormCard.FormHeader {
                title: {
                    const date = new Date(section);
                    const today = new Date();
                    if (date.setHours(0,0,0,0) == today.setHours(0,0,0,0)) {
                        return i18nd("kpublictransport", "Today");
                    }
                    return i18ndc("kpublictransport", "weekday, date", "%1, %2", Qt.locale().dayName(date.getDay(), Locale.LongFormat), Qt.locale().toString(date, Locale.ShortFormat));
                }


                width: ListView.view.width
                topPadding: Kirigami.Units.smallSpacing
            }
        }

        model: KSortFilterProxyModel {
            id: sortedJourneyModel

            sourceModel: root.journeyModel
            sortRole: KPublicTransport.JourneyQueryModel.ScheduledDepartureTime
            dynamicSortFilter: true
            Component.onCompleted: Util.sortModel(sortedJourneyModel, 0, Qt.Ascending)
        }

        spacing: Kirigami.Units.largeSpacing

        header: VerticalNavigationButton {
            visible: journeyModel.canQueryPrevious
            width: journeyView.width
            text: i18ndc("kpublictransport", "@action:button", "Load earlier connections")
            iconName: "go-up-symbolic"
            onClicked: journeyModel.queryPrevious()
        }

        footer: VerticalNavigationButton {
            visible: journeyModel.canQueryNext
            width: journeyView.width
            iconName: "go-down-symbolic"
            text: i18ndc("kpublictransport", "@action:button", "Load later connections")
            onClicked: journeyModel.queryNext()

            FormCard.FormCard {
                visible: journeyModel.attributions.length > 0

                FormCard.FormTextDelegate {
                    text: i18nd("kpublictransport", "Data providers:")
                    description: KPublicTransport.attributionSummary(journeyModel.attributions)
                    onLinkActivated: Qt.openUrlExternally(link)
                }
            }
        }

        QQC2.BusyIndicator {
            anchors.centerIn: parent
            running: journeyModel.loading && journeyView.count === 0
        }

        QQC2.Label {
            anchors.centerIn: parent
            width: parent.width - Kirigami.Units.gridUnit * 4
            text: journeyModel.errorMessage
            color: Kirigami.Theme.negativeTextColor
            wrapMode: Text.Wrap
        }
    }

    footer: ColumnLayout {
        spacing: 0
        height: indicator.running ? layout.implicitHeight : 0
        visible: journeyModel.loading && journeyView.count !== 0

        Behavior on height {
            NumberAnimation { duration: Kirigami.Units.shortDuration }
        }

        Kirigami.Separator {
            Layout.fillWidth: true
        }

        RowLayout {
            id: layout

            QQC2.BusyIndicator {
                id: indicator
                running: journeyModel.loading && journeyView.count !== 0
            }

            QQC2.Label {
                text: i18nd("kpublictransport", "Still fetching results…")
            }

            Item {
                Layout.fillWidth: true
            }
        }
    }
}

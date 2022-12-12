/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15 as QQC2
import QtLocation 5.11 as QtLocation
import QtPositioning 5.11
import org.kde.kirigami 2.19 as Kirigami
import org.kde.kpublictransport 1.0
import org.kde.kpublictransport.onboard 1.0

Kirigami.ApplicationWindow {
    title: "Onboard API Demo"
    reachableModeEnabled: false

    width: 540
    height: 720

    pageStack.initialPage: onboardPage

    OnboardStatus {
        id: onboardStatus
        positionUpdateInterval: 10
        journeyUpdateInterval: 60
    }

    Component {
        id: onboardPage

        Kirigami.Page {
            QQC2.SwipeView {
                id: swipeView
                anchors.fill: parent

                Kirigami.Page {
                    header: Kirigami.FormLayout {
                        QQC2.Label {
                            text: onboardStatus.status
                            Kirigami.FormData.label: "Status"
                        }
                        QQC2.Label {
                            text: onboardStatus.latitude + " x " + onboardStatus.longitude
                            Kirigami.FormData.label: "Position"
                        }
                        QQC2.Label {
                            text: onboardStatus.speed
                            Kirigami.FormData.label: "Speed"
                        }
                        QQC2.Label {
                            text: onboardStatus.heading
                            Kirigami.FormData.label: "Heading"
                        }
                    }

                    Kirigami.ColumnView.preventStealing: true

                    QtLocation.Plugin {
                        id: mapPlugin
                        required.mapping: QtLocation.Plugin.AnyMappingFeatures
                        preferred: ["osm"]
                    }

                    QtLocation.Map {
                        id: map
                        anchors.fill: parent
                        center: QtPositioning.coordinate(onboardStatus.latitude, onboardStatus.longitude)
                        plugin: mapPlugin

                        QtLocation.MapQuickItem {
                            coordinate: QtPositioning.coordinate(onboardStatus.latitude, onboardStatus.longitude)
                            anchorPoint { x: icon.width / 2; y: icon.height / 2 }
                            visible: onboardStatus.hasPosition
                            sourceItem: Kirigami.Icon {
                                id: icon
                                source: "go-up-symbolic"
                                width: height
                                height: Kirigami.Units.iconSizes.large
                                color: Kirigami.Theme.negativeTextColor
                                rotation: onboardStatus.heading
                                transformOrigin: Item.Center
                                onTransformOriginChanged: icon.transformOrigin = Item.Center
                            }
                        }
                    }
                }

                JourneySectionPage {
                    journeySection: onboardStatus.journey.sections[0]
                }
            }

            footer: Kirigami.NavigationTabBar {
                actions: [
                    Kirigami.Action {
                        text: "Position"
                        icon.name: 'map-symbolic'
                        onTriggered: swipeView.currentIndex = 0
                        checked: swipeView.currentIndex === 0
                    },
                    Kirigami.Action {
                        text: "Journey"
                        icon.name: 'path-mode-polyline'
                        onTriggered: swipeView.currentIndex = 1;
                        checked: swipeView.currentIndex === 1
                    }
                ]
            }
        }
    }
}

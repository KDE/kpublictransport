/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import QtLocation as QtLocation
import QtPositioning
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport
import org.kde.kpublictransport.onboard

Kirigami.ApplicationWindow {
    title: "Onboard API Demo"

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
                        QQC2.Label {
                            text: onboardStatus.altitude
                            Kirigami.FormData.label: "Altitude"
                        }
                    }

                    Kirigami.ColumnView.preventStealing: true

                    QtLocation.Plugin {
                        id: mapPlugin
                        name: "osm"
                        QtLocation.PluginParameter { name: "osm.useragent"; value: "KPublicTransport Onboard API demo" }
                        QtLocation.PluginParameter { name: "osm.mapping.providersrepository.address"; value: "https://autoconfig.kde.org/qtlocation/" }
                    }

                    QtLocation.Map {
                        id: map
                        anchors.fill: parent
                        center: QtPositioning.coordinate(onboardStatus.latitude, onboardStatus.longitude)
                        plugin: mapPlugin
                        zoomLevel: 14

                        PinchHandler {
                            id: pinch
                            target: null
                            onActiveChanged: if (active) {
                                map.startCentroid = map.toCoordinate(pinch.centroid.position, false)
                            }
                            onScaleChanged: (delta) => {
                                map.zoomLevel += Math.log2(delta)
                                map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position)
                            }
                            onRotationChanged: (delta) => {
                                map.bearing -= delta
                                map.alignCoordinateToPoint(map.startCentroid, pinch.centroid.position)
                            }
                            grabPermissions: PointerHandler.TakeOverForbidden
                        }
                        WheelHandler {
                            id: wheel
                            rotationScale: 1/120
                            property: "zoomLevel"
                        }
                        DragHandler {
                            id: drag
                            target: null
                            onTranslationChanged: (delta) => map.pan(-delta.x, -delta.y)
                        }
                        Shortcut {
                            enabled: map.zoomLevel < map.maximumZoomLevel
                            sequence: StandardKey.ZoomIn
                            onActivated: map.zoomLevel = Math.round(map.zoomLevel + 1)
                        }
                        Shortcut {
                            enabled: map.zoomLevel > map.minimumZoomLevel
                            sequence: StandardKey.ZoomOut
                            onActivated: map.zoomLevel = Math.round(map.zoomLevel - 1)
                        }

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
                                rotation: onboardStatus.hasHeading ? onboardStatus.heading : 0
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

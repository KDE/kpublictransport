// SPDX-FileCopyrightText: 2025 Volker Krause <vkrause@kde.org>
// SPDX-License-Identifier: LGPL-2.0-or-later

import QtQuick
import QtQuick.Layouts
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport

Kirigami.Page {
    width: 600
    height: 800

    contentItem: ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        KPublicTransport.TransportNameControl {
            lineName: "Test"
            iconName: "car"
            journeySectionMode: KPublicTransport.JourneySection.PublicTransport
        }

        // light on dark
        RowLayout {
            KPublicTransport.TransportNameControl {
                line: ({
                    mode: KPublicTransport.Line.Train,
                    name: "U1",
                    color: "#65BD00",
                    textColor: "white"
                })
            }
            KPublicTransport.TransportNameControl {
                line: ({
                    mode: KPublicTransport.Line.Train,
                    name: "U1",
                    color: "#65BD00"
                })
            }
        }

        // dark on light
        RowLayout {
            KPublicTransport.TransportNameControl {
                journeySection: ({
                    mode: KPublicTransport.JourneySection.PublicTransport,
                    route: {
                        line: {
                            mode: KPublicTransport.Line.Metro,
                            name: "U4",
                            color: "#FFD900",
                            textColor: "black"
                        }
                    }
                })
            }
            KPublicTransport.TransportNameControl {
                journeySection: ({
                    mode: KPublicTransport.JourneySection.PublicTransport,
                    route: {
                        line: {
                            mode: KPublicTransport.Line.Metro,
                            name: "U4",
                            color: "#FFD900"
                        }
                    }
                })
            }
        }
        KPublicTransport.TransportNameControl {
            journeySection: ({
                mode: KPublicTransport.JourneySection.Walking
            })
        }

        RowLayout {
            KPublicTransport.TransportNameControl {
                journeySection: ({
                    mode: KPublicTransport.JourneySection.IndividualTransport,
                    individualTransport: { mode: KPublicTransport.IndividualTransport.Bike }
                })
            }
            KPublicTransport.TransportNameControl {
                journeySection: ({
                    mode: KPublicTransport.JourneySection.PublicTransport,
                    route: {
                        line: {
                            mode: KPublicTransport.Line.Bus,
                            name: "123"
                        }
                    }
                })
                Layout.fillWidth: true
            }
            KPublicTransport.TransportNameControl {
                journeySection: ({
                    mode: KPublicTransport.JourneySection.Transfer
                })
            }
            KPublicTransport.TransportNameControl {
                journeySection: ({
                    mode: KPublicTransport.JourneySection.PublicTransport,
                    route: {
                        line: {
                            mode: KPublicTransport.Line.LongDistanceTrain,
                            name: "TGV 9876"
                        }
                    }
                })
                Layout.fillWidth: true
            }
            KPublicTransport.TransportNameControl {
                journeySection: ({
                    mode: KPublicTransport.JourneySection.RentedVehicle,
                    rentalVehicle: { type: KPublicTransport.RentalVehicle.ElectricKickScooter }
                })
            }
        }

        KPublicTransport.JourneyHorizontalBar {
            Layout.fillWidth: true
            journey: ({
                sections: [
                    {
                        mode: KPublicTransport.JourneySection.IndividualTransport,
                        individualTransport: { mode: KPublicTransport.IndividualTransport.Walk },
                        scheduledDepartureTime: "2024-12-13T12:00:00",
                        scheduledArrivalTime: "2024-12-13T13:00:00"
                    },
                    {
                        mode: KPublicTransport.JourneySection.PublicTransport,
                        route: {
                            line: {
                                mode: KPublicTransport.Line.Bus,
                                name: "123"
                            }
                        },
                        scheduledDepartureTime: "2024-12-13T13:10:00",
                        scheduledArrivalTime: "2024-12-13T14:00:00"
                    },
                    {
                        mode: KPublicTransport.JourneySection.Waiting
                    },
                    {
                        mode: KPublicTransport.JourneySection.PublicTransport,
                        route: {
                            line: {
                                mode: KPublicTransport.Line.LongDistanceTrain,
                                name: "TGV 9876"
                            }
                        },
                        disruptionEffect: KPublicTransport.Disruption.NoService,
                        scheduledDepartureTime: "2024-12-13T15:00:00",
                        scheduledArrivalTime: "2024-12-13T22:00:00"
                    },
                    {
                        mode: KPublicTransport.JourneySection.RentedVehicle,
                        rentalVehicle: { type: KPublicTransport.RentalVehicle.Bicycle },
                        scheduledDepartureTime: "2024-12-13T22:10:00",
                        scheduledArrivalTime: "2024-12-13T22:30:00"
                    }
                ]
            })
        }
    }
}

/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport

Kirigami.OverlaySheet {
    id: locationDetailsSheet
    property KPublicTransport.location location

    header: Kirigami.Heading {
        text: "Location Details"
    }

    ColumnLayout {
        QQC2.Label {
            text: "Name: " + locationDetailsSheet.location.name
        }
        QQC2.Label {
            text: "Street:" + locationDetailsSheet.location.streetAddress
        }
        QQC2.Label {
            text: "ZIP: " + locationDetailsSheet.location.postalCode
        }
        QQC2.Label {
            text: "City: " + locationDetailsSheet.location.locality
        }
        QQC2.Label {
            text: "Region: " + locationDetailsSheet.location.region
        }
        QQC2.Label {
            text: "Country: " + locationDetailsSheet.location.country
        }
        QQC2.Label {
            text: "Lat: " + locationDetailsSheet.location.latitude
        }
        QQC2.Label {
            text: "Lon: " + locationDetailsSheet.location.longitude
        }
        Repeater {
            model: locationDetailsSheet.location.identifierTypes
            QQC2.Label {
                required property string modelData
                text: "Identifiers (" + modelData + "): " + locationDetailsSheet.location.identifier(modelData)
            }

        }
        QQC2.ToolButton {
            icon.name: "map-symbolic"
            text: "Station Map"
            onClicked: {
                applicationWindow().pageStack.push(indoorMapPage, {coordinate: Qt.point(location.longitude, location.latitude)});
                locationDetailsSheet.close();
            }
        }
        QQC2.ToolButton {
            icon.name: "map-globe"
            text: "View on OSM"
            onClicked: Qt.openUrlExternally("https://www.openstreetmap.org/#map=18/" + locationDetailsSheet.location.latitude + "/" + locationDetailsSheet.location.longitude)
        }
    }
}

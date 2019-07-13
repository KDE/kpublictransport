/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 2.1 as QQC2
import org.kde.kirigami 2.0 as Kirigami

Kirigami.OverlaySheet {
    id: locationDetailsSheet
    property var location

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
        QQC2.Label {
            text: "Identifiers: " + _queryMgr.locationIds(locationDetailsSheet.location)
        }
        QQC2.ToolButton {
            icon.name: "map-symbolic"
            text: "View on map"
            onClicked: Qt.openUrlExternally("https://www.openstreetmap.org/#map=18/" + locationDetailsSheet.location.latitude + "/" + locationDetailsSheet.location.longitude)
        }
    }
}

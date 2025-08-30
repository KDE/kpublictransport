/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

pragma ComponentBehavior: Bound

import QtCore as QtCore
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import QtLocation as QtLocation
import QtPositioning as QtPositioning
import org.kde.kirigami as Kirigami
import org.kde.kitemmodels
import org.kde.i18n.localeData as I18nLocaleData
import org.kde.kirigamiaddons.delegates as Delegates
import org.kde.kpublictransport as PublicTransport

import "globals.js" as Globals

Delegates.RoundedItemDelegate {
    id: delegate

    signal locationPicked()
    signal errorOccurred(string errorString)

    property bool active: false
    readonly property alias available: positionSource.valid
    readonly property bool validPosition: positionSource.accuracyAcceptable && positionSource.ageAcceptable

    property PublicTransport.location location

    property bool waitingForPermission: false
    property bool waitingForLocation: false
    property bool waitingForAddress: false

    icon {
        name: "map-symbolic"
        width: Kirigami.Units.iconSizes.medium
        height: Kirigami.Units.iconSizes.medium
    }
    text: i18nd("kpublictransport", "Current Location");
    checkable: true
    checked: waitingForPermission || waitingForLocation || waitingForAddress
    focusPolicy: Qt.StrongFocus
    onClicked: {
        if (waitingForLocation || waitingForAddress) {
            // not resetting waitForPermission since we don't know whether the user aborted the request.
            waitingForLocation = false;
            waitingForAddress = false;
            return;
        }

        if (locationPermission.status !== Qt.PermissionStatus.Granted) {
            waitingForPermission = true;
            locationPermission.request();
            return;
        }

        waitingForPermission = false;

        if (positionSource.positionAcceptable) {
            delegate.lookupAddress();
        } else {
            delegate.waitingForLocation = true;
        }
    }

    Component {
        id: qtLocationOSMPluginComponent
        QtLocation.Plugin {
            name: "osm"
            QtLocation.PluginParameter { name: "osm.useragent"; value: "org.kde.kpublictransport/" + Application.name + "/" + Application.version }
            QtLocation.PluginParameter { name: "osm.mapping.providersrepository.address"; value: "https://autoconfig.kde.org/qtlocation/" }
        }
    }

    function lookupAddress() : void {
        if (waitingForAddress) {
            return;
        }

        console.assert(positionSource.positionAcceptable);

        if (!Globals.osmPlugin) {
            Globals.osmPlugin = qtLocationOSMPluginComponent.createObject();
        }
        reverseGeocodeModel.plugin = Globals.osmPlugin;
        reverseGeocodeModel.query = positionSource.position.coordinate;
        reverseGeocodeModel.update();
        waitingForAddress = true;
    }

    contentItem: Delegates.SubtitleContentItem {
        itemDelegate: delegate
        subtitle: {
            if (delegate.waitingForLocation) {
                if (!positionSource.positionAvailable || !positionSource.ageAcceptable) {
                    return i18nd("kpublictransport", "Determining Location…");
                } else if (!positionSource.accuracyAcceptable) {
                    return i18nd("kpublictransport", "Waiting for more accurate location…");
                }
            } else if (delegate.waitingForAddress) {
                return i18nd("kpublictransport", "Looking up address…");
            } else {
                return "";
            }
        }
    }

    // TODO Refresh WifiMonitor when permission is granted here.
    QtCore.LocationPermission {
        id: locationPermission
        accuracy: QtCore.LocationPermission.Precise
        onStatusChanged: {
            if (delegate.waitingForPermission && status === Qt.PermissionStatus.Granted) {
                delegate.waitingForLocation = true;
            }
            delegate.waitingForPermission = false;
        }
    }

    QtPositioning.PositionSource {
        id: positionSource

        // Minimum required position accuracy for GPS location in meters.
        readonly property int minimumPositionAccuracy: 50
        // Maximum age of last position update in milliseconds.
        readonly property int maximumPositionAge: 60 * 1000

        readonly property bool positionAvailable: position.latitudeValid && position.longitudeValid && position.horizontalAccuracyValid

        readonly property bool positionAcceptable: accuracyAcceptable && ageAcceptable
        readonly property bool accuracyAcceptable: positionAvailable && position.horizontalAccuracy < minimumPositionAccuracy
        readonly property bool ageAcceptable: positionAvailable && !isNaN(position.timestamp.getTime())
            && new Date().getTime() - position.timestamp.getTime() < maximumPositionAge

        active: delegate.visible && delegate.active && locationPermission.status === Qt.PermissionStatus.Granted
        updateInterval: 1000
        // NOTE supportedPositioningMethods is only available once the permission has been granted.
        // Unable to assign [undefined] to QFlags<QDeclarativePositionSource::PositioningMethod> ???
        // preferredPositioningMethods: QtPositioning.PositionSource.SatellitePositioningMethods

        Component.onCompleted: {
            preferredPositioningMethods = QtPositioning.PositionSource.SatellitePositioningMethods;
        }

        onPositionChanged: {
            if (positionAcceptable) {
                delegate.location.latitude = position.coordinate.latitude;
                delegate.location.longitude = position.coordinate.longitude;
            }
        }

        onPositionAcceptableChanged: {
            if (positionAcceptable && delegate.waitingForLocation) {
                delegate.location.latitude = position.coordinate.latitude;
                delegate.location.longitude = position.coordinate.longitude;
                delegate.waitingForLocation = false;
                delegate.lookupAddress();
            }
        }
    }

    // Position timeout.
    Timer {
        interval: 20000
        repeat: false
        running: delegate.waitingForLocation
        onTriggered: {
            if (positionSource.positionAvailable) {
                // We got a position but it was too old or too inaccurate.
                delegate.errorOccurred(i18nd("kpublictransport", "Failed to determine accurate enough location."));
            } else {
                delegate.errorOccurred(i18nd("kpublictransport", "Failed to determine location."));
            }
            delegate.waitingForLocation = false;
        }
    }

    QtLocation.GeocodeModel {
        id: reverseGeocodeModel
        // plugin is set on demand.
        autoUpdate: false
        limit: 1
        onLocationsChanged: {
            if (count >= 1) {
                // TODO share this with FormPlaceEditorDelegate.
                const location = reverseGeocodeModel.get(0).address;
                delegate.location.streetAddress = location.street + " " + location.streetNumber;
                delegate.location.postalCode = location.postalCode
                delegate.location.locality = location.city;
                delegate.location.addressCountry = I18nLocaleData.Country.fromName(location.countryCode).alpha2;
                delegate.location.region = location.state;
                // TODO KContact address formatter? But it's really only as a rough confirmation of the location,
                // probably doesn't need to include the city and all.
                delegate.location.name = delegate.location.streetAddress;

                if (delegate.waitingForAddress) {
                    delegate.waitingForAddress = false;
                    console.log("Determined current location:", delegate.location);
                    delegate.locationPicked();
                }
            }
        }
        onErrorStringChanged: {
            if (errorString) {
                delegate.errorOccurred(errorString);
                delegate.waitingForAddress = false;
            }
        }
    }
}

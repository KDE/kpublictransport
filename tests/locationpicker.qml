/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.kirigami as Kirigami
import org.kde.kpublictransport as KPublicTransport
import org.kde.kpublictransport.ui as KPublicTransport

Kirigami.ApplicationWindow {
    title: "Location Picker Example"

    width: 540
    height: 720

    KPublicTransport.Manager { id: ptMgr }

    pageStack.initialPage: KPublicTransport.StopPickerPage {
        id: stopPicker
        initialCountry: 'CH'
        publicTransportManager: ptMgr
        historySortRoleName: "locationName"
        downloadAssets: true
        showUseCurrentLocationButton: true

        onLocationChanged: () => { console.log(stopPicker.location); }
    }
}

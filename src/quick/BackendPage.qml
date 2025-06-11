/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

import QtNetwork as QtNetwork
import QtQuick
import QtQuick.Layouts
import QtQuick.Controls as QQC2
import org.kde.i18n.localeData
import org.kde.kirigami as Kirigami
import org.kde.kirigamiaddons.delegates as Delegates
import org.kde.kpublictransport as KPublicTransport

/** Page to enabling/disabling backends manually. */
Kirigami.ScrollablePage {
    id: root

    /** KPublicTransport.Manager that is configured by this page. */
    property alias publicTransportManager: backendModel.manager

    /** Action to manually trigger online update of backend configurations. */
    property Kirigami.Action onlineUpdateAction: Kirigami.Action {
        text: i18nd("kpublictransport", "Check for Updates")
        icon.name: "system-software-update"
        enabled: root.publicTransportManager.updateResult !== KPublicTransport.UpdateResult.InProgress
              && (QtNetwork.NetworkInformation.reachability === QtNetwork.NetworkInformation.Reachability.Online
               || QtNetwork.NetworkInformation.reachability === QtNetwork.NetworkInformation.Reachability.Unknown)
        visible: root.publicTransportManager.updateResult !== KPublicTransport.UpdateResult.UpdatesDisabled
        onTriggered: root.publicTransportManager.checkForUpdates(true)
    }

    Connections {
        target: root.publicTransportManager
        function onUpdateResultChanged() {
            switch (root.publicTransportManager.updateResult) {
                case KPublicTransport.UpdateResult.NoUpdate:
                    showPassiveNotification(i18nd("kpublictransport", "Already up to date."), "short");
                    break;
                case KPublicTransport.UpdateResult.UpdateSuccessful:
                    showPassiveNotification(i18nd("kpublictransport", "Update successful."), "short");
                    break;
                case KPublicTransport.UpdateResult.NetworkError:
                case KPublicTransport.UpdateResult.FilesystemError:
                case KPublicTransport.UpdateResult.IncompatibleVersion:
                case KPublicTransport.UpdateResult.FileFormatError:
                    showPassiveNotification(i18nd("kpublictransport", "Update failed."), "short");
                    break;
            }
        }
    }

    title: i18nd("kpublictransport", "Public Transport Information Sources")

    KPublicTransport.BackendModel {
        id: backendModel
        mode: KPublicTransport.BackendModel.GroupByCountry
    }

    Component {
        id: backendDelegate

        Delegates.RoundedItemDelegate {
            id: delegateRoot
            enabled: model.itemEnabled
            text: model.name

            contentItem: Item {
                anchors.margins: Kirigami.Units.largeSpacing
                implicitHeight: childrenRect.height

                QQC2.Label {
                    id: nameLabel
                    text: model.name
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.right: securityIcon.left
                    anchors.rightMargin: Kirigami.Units.largeSpacing
                    // try to retain trailing abbreviations when we have to elide
                    elide: text.endsWith(")") ? Text.ElideMiddle : Text.ElideRight
                    Accessible.ignored: true
                }
                Kirigami.Icon {
                    id: securityIcon
                    source: model.isSecure ? "channel-secure-symbolic" : "channel-insecure-symbolic"
                    color: model.isSecure ? Kirigami.Theme.positiveTextColor : Kirigami.Theme.negativeTextColor
                    width: height
                    height: Kirigami.Units.gridUnit
                    anchors.top: parent.top
                    anchors.right: toggle.left
                }
                QQC2.Switch {
                    id: toggle
                    checked: model.backendEnabled
                    onToggled: model.backendEnabled = checked
                    anchors.top: parent.top
                    anchors.right: parent.right
                }
                QQC2.Label {
                    anchors.top: nameLabel.bottom
                    anchors.left: parent.left
                    anchors.right: toggle.left
                    anchors.topMargin: Kirigami.Units.smallSpacing
                    text: model.description
                    font.italic: true
                    wrapMode: Text.WordWrap
                }
            }

            onClicked: {
                toggle.toggle(); // does not trigger the signal handler for toggled...
                model.backendEnabled = toggle.checked;
            }
            Accessible.onToggleAction: delegateRoot.clicked()
        }
    }

    ListView {
        model: backendModel
        delegate: backendDelegate

        section {
            property: "countryCode"
            delegate: Kirigami.ListSectionHeader {
                width: ListView.view.width
                text: {
                    switch (section) {
                    case "":
                    case "UN":
                        return i18nd("kpublictransport", "Global");
                    case "EU":
                        return i18nd("kpublictransport", "🇪🇺 European Union");
                    default:
                        const c = Country.fromAlpha2(section);
                        return i18ndc("kpublictransport", "emoji flag, country name", "%1 %2", c.emojiFlag, c.name);
                    }
                }
                Accessible.name: {
                    switch (section) {
                        case "":
                        case "UN":
                            return i18nd("kpublictransport", "Global")
                        case "EU":
                            return i18nd("kpublictransport", "European Union");
                        default:
                            return Country.fromAlpha2(section).name;
                    }
                }
            }
            criteria: ViewSection.FullString
        }
    }
}

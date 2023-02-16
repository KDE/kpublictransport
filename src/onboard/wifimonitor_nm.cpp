/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "wifimonitor_p.h"

#include <NetworkManagerQt/Manager>
#include <NetworkManagerQt/WirelessSetting>

using namespace KPublicTransport;

WifiMonitor::WifiMonitor(QObject *parent)
    : QObject(parent)
{
    const auto getSsid = [this](){
        const auto connections = NetworkManager::activeConnections();
        for (const auto &con : connections) {
            if (con->type() != NetworkManager::ConnectionSettings::Wireless) {
                continue;
            }
            setSsid(QString::fromUtf8(con->connection()->settings()->setting(NetworkManager::Setting::Wireless).staticCast<NetworkManager::WirelessSetting>()->ssid()));
            break;
        }
    };

    connect(NetworkManager::notifier(), &NetworkManager::Notifier::activatingConnectionChanged, this, getSsid);
    connect(NetworkManager::notifier(), &NetworkManager::Notifier::activeConnectionAdded, this, getSsid);
    connect(NetworkManager::notifier(), &NetworkManager::Notifier::activeConnectionRemoved, this, getSsid);
    connect(NetworkManager::notifier(), &NetworkManager::Notifier::networkingEnabledChanged, this, &WifiMonitor::statusChanged);
    connect(NetworkManager::notifier(), &NetworkManager::Notifier::wirelessEnabledChanged, this, &WifiMonitor::statusChanged);

    getSsid();
}

WifiMonitor::~WifiMonitor() = default;

WifiMonitor::Status WifiMonitor::status() const
{
    if (!NetworkManager::isNetworkingEnabled()) {
        return NotAvailable;
    }

    return NetworkManager::isWirelessEnabled() ? Available : WifiNotEnabled;
}

void WifiMonitor::requestPermissions()
{
}

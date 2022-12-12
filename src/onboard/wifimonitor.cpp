/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "wifimonitor_p.h"

using namespace KPublicTransport;

QString WifiMonitor::ssid() const
{
    return m_ssid;
}

void WifiMonitor::setSsid(const QString &ssid)
{
    if (m_ssid == ssid) {
        return;
    }

    m_ssid = ssid;
    Q_EMIT wifiChanged();
}

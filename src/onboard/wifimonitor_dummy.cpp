/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "wifimonitor_p.h"

using namespace KPublicTransport;

WifiMonitor::WifiMonitor(QObject *parent)
    : QObject(parent)
{
}

WifiMonitor::~WifiMonitor() = default;

WifiMonitor::Status WifiMonitor::status() const
{
    return NotAvailable;
}

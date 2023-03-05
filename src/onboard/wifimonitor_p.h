/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_WIFIMONITOR_H
#define KPUBLICTRANSPORT_WIFIMONITOR_H

#include <QObject>

#include <memory>

namespace KPublicTransport {

class WifiMonitorBackend;

/** Monitors to which Wifi access point the system is currently connected, if any. */
class WifiMonitor : public QObject
{
    Q_OBJECT
public:
    explicit WifiMonitor(QObject *parent = nullptr);
    ~WifiMonitor();

    enum Status {
        NotAvailable, ///< Wifi monitoring is generally not available on this platform/in this build
        Available, ///< Wifi monitoring is available (!= Wifi is available or even in use/enabled)
        WifiNotEnabled, ///< Wifi monitoring is not available due to a user-controlled platform setting
        LocationServiceNotEnabled, ///< Wifi monitoring is not available due to a user-controlled platform setting
        NoPermission, ///< Wifi monitoring is not available due to missing permissions
    };
    Q_ENUM(Status)
    Status status() const;

    QString ssid() const;
    void requestPermissions();

Q_SIGNALS:
    void wifiChanged();
    void statusChanged();

private:
    friend class WifiMonitorBackend;
    void setSsid(const QString &ssid);

    QString m_ssid;
};

}

#endif // KPUBLICTRANSPORT_WIFIMONITOR_H

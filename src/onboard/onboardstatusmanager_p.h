/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_ONBOARDSTATUSMANAGER_H
#define KPUBLICTRANSPORT_ONBOARDSTATUSMANAGER_H

#include "onboardstatus.h"
#include "positiondata_p.h"
#include "wifimonitor_p.h"

#include <KPublicTransport/Journey>

#include <QObject>
#include <QTimer>

#include <memory>

class OnboardStatusTest;
class QNetworkAccessManager;

namespace KPublicTransport {

class AbstractOnboardBackend;

/** Singular backend for the OnbardStatus frontend objects.
 *  @internal
 */
class OnboardStatusManager : public QObject
{
    Q_OBJECT
public:
    ~OnboardStatusManager();
    static OnboardStatusManager* instance();

    OnboardStatus::Status status() const;
    PositionData currentPosition() const;
    bool supportsPosition() const;
    Journey currentJourney() const;
    bool supportsJourney() const;

    void registerFrontend(const OnboardStatus *status);
    void unregisterFrontend(const OnboardStatus *status);

    void requestPosition();
    void requestJourney();

    void requestPermissions();

Q_SIGNALS:
    void statusChanged();
    void positionChanged();
    void supportsPositionChanged();
    void journeyChanged();
    void supportsJourneyChanged();

private:
    friend class ::OnboardStatusTest;

    explicit OnboardStatusManager(QObject *parent = nullptr);
    void loadAccessPointData();
    void loadBackend(const QString &id);
    void wifiChanged();
    void setStatus(OnboardStatus::Status status);
    void positionUpdated(const PositionData &pos);
    void journeyUpdated(const Journey &jny);

    void requestUpdate();
    void requestForceUpdate();
    void scheduleUpdate(bool force);

    QNetworkAccessManager* nam();

    /** @internal exported for unit tests only */
    KPUBLICTRANSPORTONBOARD_EXPORT static std::unique_ptr<AbstractOnboardBackend> createBackend(const QString &id);

    WifiMonitor m_wifiMonitor;

    struct AccessPointInfo {
        QString ssid;
        QString backendId;

        inline bool operator<(const AccessPointInfo &other) const { return ssid < other.ssid; }
        inline bool operator<(const QString &otherSsid) const { return ssid < otherSsid; }
    };
    std::vector<AccessPointInfo> m_accessPointData;

    OnboardStatus::Status m_status = OnboardStatus::NotConnected;
    PositionData m_currentPos;
    PositionData m_previousPos;
    Journey m_journey;

    QNetworkAccessManager *m_nam = nullptr;
    std::unique_ptr<AbstractOnboardBackend> m_backend;

    std::vector<const OnboardStatus*> m_frontends;
    QTimer m_positionUpdateTimer;
    QTimer m_journeyUpdateTimer;
    bool m_pendingPositionUpdate = false;
    bool m_pendingJourneyUpdate = false;
};

}

#endif // KPUBLICTRANSPORT_ONBOARDSTATUSMANAGER_H

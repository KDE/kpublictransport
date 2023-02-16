/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_ONBOARDSTATUS_H
#define KPUBLICTRANSPORT_ONBOARDSTATUS_H

#include "kpublictransportonboard_export.h"

#include <QObject>

#include <memory>

namespace KPublicTransport {
class Journey;
class OnboardStatusPrivate;

/** Access to public transport onboard API.
 *
 *  Instances of this class act as a lightweight frontend to an internal
 *  singleton, for easy integration with QML.
 */
class KPUBLICTRANSPORTONBOARD_EXPORT OnboardStatus : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Status status READ status NOTIFY statusChanged)

    /** Current geographic position, @c NAN if not available. */
    Q_PROPERTY(float latitude READ latitude NOTIFY positionChanged)
    Q_PROPERTY(float longitude READ longitude NOTIFY positionChanged)
    Q_PROPERTY(bool hasPosition READ hasPosition NOTIFY positionChanged)

    /** Current speed in km/h. */
    Q_PROPERTY(float speed READ speed NOTIFY positionChanged)
    Q_PROPERTY(bool hasSpeed READ hasSpeed NOTIFY positionChanged)

    /** Current heading in degree, NAN if unknown. */
    Q_PROPERTY(float heading READ heading NOTIFY positionChanged)
    Q_PROPERTY(bool hasHeading READ hasHeading NOTIFY positionChanged)

    /** The current journey. */
    Q_PROPERTY(KPublicTransport::Journey journey READ journey NOTIFY journeyChanged)
    Q_PROPERTY(bool hasJourney READ hasJourney NOTIFY journeyChanged)

    /** Update polling intervals in seconds. */
    Q_PROPERTY(int positionUpdateInterval READ positionUpdateInterval WRITE setPositionUpdateInterval NOTIFY updateIntervalChanged)
    Q_PROPERTY(int journeyUpdateInterval READ journeyUpdateInterval WRITE setJourneyUpdateInterval NOTIFY updateIntervalChanged)

public:
    explicit OnboardStatus(QObject *parent = nullptr);
    ~OnboardStatus();

    enum Status {
        NotConnected, ///< Wi-Fi monitoring functional, but currently not connected to an onboard Wi-Fi.
        Onboard, ///< currently connected to a known onboard Wi-Fi system.
        MissingPermissions, ///< Wi-Fi monitoring not functional due to missing application permissions.
        WifiNotEnabled, ///< Wi-Fi monitoring is not possible due to Wi-Fi being disabled.
        LocationServiceNotEnabled, ///< Wi-Fi monitoring is not possible due to the location service being disabled (Android only).
        NotAvailable, ///< Wi-Fi monitoring is generally not available on this platform.
    };
    Q_ENUM(Status)
    Status status() const;

    float latitude() const;
    float longitude() const;
    bool hasPosition() const;

    float speed() const;
    bool hasSpeed() const;

    float heading() const;
    bool hasHeading() const;

    KPublicTransport::Journey journey() const;
    bool hasJourney() const;

    int positionUpdateInterval() const;
    void setPositionUpdateInterval(int interval);
    int journeyUpdateInterval() const;
    void setJourneyUpdateInterval(int interval);

    /** Request one time update of the position status.
     *  For recurring updates, use the polling interval setting instead.
     */
    Q_INVOKABLE void requestPosition();
    /** Request one time journey data update, if available.
     *  For recurring updates, use the polling interval setting instead.
     */
    Q_INVOKABLE void requestJourney();

    /** Request application permission needed for Wi-Fi montioring.
     *  Only relevant on Android, does nothing on other platforms.
     *  @see Status::MissingPermissions
     */
    Q_INVOKABLE void requestPermissions();

Q_SIGNALS:
    void statusChanged();
    void positionChanged();
    void journeyChanged();
    void updateIntervalChanged();

private:
    std::unique_ptr<OnboardStatusPrivate> d;
};

}

#endif // KPUBLICTRANSPORT_ONBOARDSTATUS_H

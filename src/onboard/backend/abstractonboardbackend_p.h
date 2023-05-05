/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_ABSTRACTONBOARDBACKEND_H
#define KPUBLICTRANSPORT_ABSTRACTONBOARDBACKEND_H

#include <QObject>

class QNetworkAccessManager;

namespace KPublicTransport {
class Journey;
class PositionData;

/** Base class for backends interacting with the onboard API endpoints. */
class AbstractOnboardBackend : public QObject
{
    Q_OBJECT
public:
    ~AbstractOnboardBackend();

    /** Whether the backend supports querying position information. */
    virtual bool supportsPosition() const = 0;
    /** Whether the backend supports querying journey information. */
    virtual bool supportsJourney() const = 0;

    /** Get the current position information. */
    virtual void requestPosition(QNetworkAccessManager *nam) = 0;
    /** Get the current journey information. */
    virtual void requestJourney(QNetworkAccessManager *nam) = 0;

Q_SIGNALS:
    void positionReceived(const KPublicTransport::PositionData &pos);
    void journeyReceived(const KPublicTransport::Journey &journey);

protected:
    explicit AbstractOnboardBackend(QObject *parent);
};

}

#endif // KPUBLICTRANSPORT_ABSTRACTONBOARDBACKEND_H

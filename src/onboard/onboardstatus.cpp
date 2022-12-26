/*
    SPDX-FileCopyrightText: 2022 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "onboardstatus.h"
#include "onboardstatusmanager_p.h"

#include <KPublicTransport/Journey>

#include <cmath>

using namespace KPublicTransport;

namespace KPublicTransport {
class OnboardStatusPrivate
{
public:
    int positionUpdateInterval = -1;
    int journeyUpdateInterval = -1;
};
}

OnboardStatus::OnboardStatus(QObject *parent)
    : QObject(parent)
    , d(new OnboardStatusPrivate)
{
    auto mgr = OnboardStatusManager::instance();
    connect(mgr, &OnboardStatusManager::statusChanged, this, &OnboardStatus::statusChanged);
    connect(mgr, &OnboardStatusManager::positionChanged, this, &OnboardStatus::positionChanged);
    connect(mgr, &OnboardStatusManager::journeyChanged, this, &OnboardStatus::journeyChanged);
    OnboardStatusManager::instance()->registerFrontend(this);
}

OnboardStatus::~OnboardStatus()
{
    OnboardStatusManager::instance()->unregisterFrontend(this);
}

OnboardStatus::Status OnboardStatus::status() const
{
    return OnboardStatusManager::instance()->status();
}

float OnboardStatus::latitude() const
{
    return OnboardStatusManager::instance()->currentPosition().latitude;
}

float OnboardStatus::longitude() const
{
    return OnboardStatusManager::instance()->currentPosition().longitude;
}

bool OnboardStatus::hasPosition() const
{
    return OnboardStatusManager::instance()->currentPosition().hasCoordinate();
}

float OnboardStatus::speed() const
{
    return OnboardStatusManager::instance()->currentPosition().speed;
}

bool OnboardStatus::hasSpeed() const
{
    return !std::isnan(speed());
}

float OnboardStatus::heading() const
{
    return OnboardStatusManager::instance()->currentPosition().heading;
}

bool OnboardStatus::hasHeading() const
{
    return !std::isnan(heading());
}

Journey OnboardStatus::journey() const
{
    return OnboardStatusManager::instance()->currentJourney();
}

bool OnboardStatus::hasJourney() const
{
    return !OnboardStatusManager::instance()->currentJourney().sections().empty();
}

int OnboardStatus::positionUpdateInterval() const
{
    return d->positionUpdateInterval;
}

void OnboardStatus::setPositionUpdateInterval(int interval)
{
    if (d->positionUpdateInterval == interval) {
        return;
    }

    d->positionUpdateInterval = interval;
    Q_EMIT updateIntervalChanged();
}

int OnboardStatus::journeyUpdateInterval() const
{
    return d->journeyUpdateInterval;
}

void OnboardStatus::setJourneyUpdateInterval(int interval)
{
    if (d->journeyUpdateInterval == interval) {
        return;
    }

    d->journeyUpdateInterval = interval;
    Q_EMIT updateIntervalChanged();
}

void OnboardStatus::requestPosition()
{
    OnboardStatusManager::instance()->requestPosition();
}

void OnboardStatus::requestJourney()
{
    OnboardStatusManager::instance()->requestJourney();
}

#include "moc_onboardstatus.cpp"

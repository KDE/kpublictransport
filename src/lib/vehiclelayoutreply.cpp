/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "vehiclelayoutreply.h"
#include "reply_p.h"
#include "vehiclelayoutrequest.h"
#include "logging.h"
#include "backends/abstractbackend.h"
#include "backends/cache.h"

#include <KPublicTransport/Platform>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/Vehicle>

#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class VehicleLayoutReplyPrivate: public ReplyPrivate {
public:
    void finalizeResult() override {}

    VehicleLayoutRequest request;
    Vehicle vehicle;
    Platform platform;
    Stopover departure;
};
}

VehicleLayoutReply::VehicleLayoutReply(const VehicleLayoutRequest &req, QObject *parent)
    : Reply(new VehicleLayoutReplyPrivate, parent)
{
    Q_D(VehicleLayoutReply);
    d->request = req;
}

VehicleLayoutReply::~VehicleLayoutReply() = default;

VehicleLayoutRequest VehicleLayoutReply::request() const
{
    Q_D(const VehicleLayoutReply);
    return d->request;
}

Vehicle VehicleLayoutReply::vehicle() const
{
    Q_D(const VehicleLayoutReply);
    return d->vehicle;
}

Platform VehicleLayoutReply::platform() const
{
    Q_D(const VehicleLayoutReply);
    return d->platform;
}

Stopover VehicleLayoutReply::departure() const
{
    Q_D(const VehicleLayoutReply);
    return d->departure;
}

static bool isOneSidedCar(VehicleSection::Type type)
{
    return type == VehicleSection::PowerCar || type == VehicleSection::ControlCar;
}

void VehicleLayoutReply::addResult(const Vehicle &vehicle, const Platform &platoform, const Stopover &departure)
{
    Q_D(VehicleLayoutReply);
    d->vehicle = vehicle;
    d->platform = platoform;
    d->departure = departure;

    if (!d->vehicle.sections().empty()) {
        // normalize section order
        auto sections = d->vehicle.takeSections();
        std::sort(sections.begin(), sections.end(), [](const auto &lhs, const auto &rhs) {
            return lhs.platformPositionBegin() < rhs.platformPositionBegin();
        });

        // we have no connections at the ends
        sections.front().setConnectedSides(sections.front().connectedSides() & ~VehicleSection::Front);
        sections.back().setConnectedSides(sections.back().connectedSides() & ~VehicleSection::Back);

        for (auto it = sections.begin(); it != sections.end(); ++it) {
            // engines and power cars have no connections either
            if ((*it).type() == VehicleSection::Engine) {
                (*it).setConnectedSides(VehicleSection::NoSide);
            }

            if (it == sections.begin()) {
                continue;
            }

            // connect control cars in the middle of the train to the correct side
            if (isOneSidedCar((*(it - 1)).type()) && isOneSidedCar((*it).type())) {
                (*it).setConnectedSides((*it).connectedSides() & ~VehicleSection::Front);
            }

            // make sure connections are symmetric
            if (((*(it - 1)).connectedSides() & VehicleSection::Back) == 0) {
                (*it).setConnectedSides((*it).connectedSides() & ~VehicleSection::Front);
            }
            if (((*it).connectedSides() & VehicleSection::Front) == 0) {
                (*(it - 1)).setConnectedSides((*(it - 1)).connectedSides() & ~VehicleSection::Back);
            }
        }

        d->vehicle.setSections(std::move(sections));
    }

    d->pendingOps--;
    d->emitFinishedIfDone(this);
}

void VehicleLayoutReply::addError(const AbstractBackend *backend, Reply::Error error, const QString &errorMsg)
{
    if (error == Reply::NotFoundError) {
        // TODO add negative cache entry
    } else {
        qCDebug(Log) << backend->backendId() << error << errorMsg;
    }
    Reply::addError(error, errorMsg);
}

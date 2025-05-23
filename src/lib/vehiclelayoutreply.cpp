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
    Stopover stopover;
};
}

VehicleLayoutReply::VehicleLayoutReply(const VehicleLayoutRequest &req, QObject *parent)
    : Reply(new VehicleLayoutReplyPrivate, parent)
{
    Q_D(VehicleLayoutReply);
    d->request = req;
    d->stopover = req.stopover();
}

VehicleLayoutReply::~VehicleLayoutReply() = default;

VehicleLayoutRequest VehicleLayoutReply::request() const
{
    Q_D(const VehicleLayoutReply);
    return d->request;
}

Stopover VehicleLayoutReply::stopover() const
{
    Q_D(const VehicleLayoutReply);
    return d->stopover;
}

static bool isOneSidedCar(VehicleSection::Type type)
{
    return type == VehicleSection::PowerCar || type == VehicleSection::ControlCar;
}

void VehicleLayoutReply::addResult(const Stopover &stopover)
{
    Q_D(VehicleLayoutReply);
    d->stopover = Stopover::merge(d->stopover, stopover);

    if (!d->stopover.vehicleLayout().sections().empty()) {
        // normalize section order
        auto vehicle = d->stopover.vehicleLayout();
        auto sections = vehicle.takeSections();
        std::sort(sections.begin(), sections.end(), [](const auto &lhs, const auto &rhs) {
            return lhs.platformPositionBegin() < rhs.platformPositionBegin();
        });

        // we have no connections at the ends
        sections.front().setConnectedSides(sections.front().connectedSides() & ~VehicleSection::Front);
        sections.back().setConnectedSides(sections.back().connectedSides() & ~VehicleSection::Back);

        // if the leading car in driving direction is a PassengerCar, turn it into a ControlCar
        if (vehicle.direction() == Vehicle::Forward && sections.front().type() == VehicleSection::PassengerCar) {
            sections.front().setType(VehicleSection::ControlCar);
        } else if (vehicle.direction() == Vehicle::Backward && sections.back().type() == VehicleSection::PassengerCar) {
            sections.back().setType(VehicleSection::ControlCar);
        }

        for (auto it = sections.begin(); it != sections.end(); ++it) {
            // engines and power cars have no connections either
            if ((*it).type() == VehicleSection::Engine) {
                (*it).setConnectedSides(VehicleSection::NoSide);
            }

            if (it == sections.begin()) {
                continue;
            }

            // connect control cars in the middle of the train to the correct side
            // only do that when two cars back isn't a control car either, ie. the preceeding car
            // actually has a connection to the front. Otherwise trains consisting of e.g. 4 consecutive
            // control cars get layouted wrongly.
            if (isOneSidedCar((*(it - 1)).type()) && isOneSidedCar((*it).type()) && ((*(it - 1)).connectedSides() & VehicleSection::Front)) {
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

        vehicle.setSections(std::move(sections));
        d->stopover.setVehicleLayout(std::move(vehicle));
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

#include "moc_vehiclelayoutreply.cpp"

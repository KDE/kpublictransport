/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsbackend.h"
#include "gbfsservice.h"
#include "gbfsstore.h"
#include "gbfsjob.h"

#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/RentalVehicle>

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace KPublicTransport;

GBFSBackend::GBFSBackend() = default;
GBFSBackend::~GBFSBackend() = default;

AbstractBackend::Capabilities GBFSBackend::capabilities() const
{
    return Secure;
}

static bool isServiceApplicable(const GBFSService &s, const LocationRequest &req)
{
    if (req.hasCoordinate()) {
        return s.boundingBox.contains(QPointF(req.longitude(), req.latitude()));
    } else {
        // TODO
    }
    return false;
}

struct QueryContext {
    bool stillStarting = true;
    bool hasError = false;
    int pendingJobs = 0;
    std::vector<Location> result;
    QString errorMessage;
};

static void appendResults(const GBFSService &service, const LocationRequest &req, std::vector<Location> &result)
{
    GBFSStore store(service.systemId);

    RentalVehicleNetwork network;
    const auto sysInfoDoc = store.loadData(GBFS::SystemInformation);
    const auto sysInfo = sysInfoDoc.object().value(QLatin1String("data")).toObject();
    network.setName(sysInfo.value(QLatin1String("name")).toString());

    const auto stationsDoc = store.loadData(GBFS::StationInformation);
    const auto stations = stationsDoc.object().value(QLatin1String("data")).toObject().value(QLatin1String("stations")).toArray();

    std::vector<QString> selectedStationIds;
    for (const auto stationV : stations) {
        const auto station = stationV.toObject();
        const auto lat = station.value(QLatin1String("lat")).toDouble();
        const auto lon = station.value(QLatin1String("lon")).toDouble();
        if (Location::distance(lat, lon, req.latitude(), req.longitude()) > req.maximumDistance()) {
            continue;
        }
        Location loc;
        loc.setCoordinate(lat, lon);
        loc.setName(station.value(QLatin1String("name")).toString());
        const auto stationId = station.value(QLatin1String("station_id")).toString();
        loc.setIdentifier(service.systemId, stationId);
        // TODO cover more properties

        RentalVehicleStation s;
        s.setNetwork(network);
        s.setCapacity(station.value(QLatin1String("capacity")).toInt(-1));
        loc.setRentalVehicleStation(s);

        selectedStationIds.push_back(stationId);
        result.push_back(loc);
    }

    const auto statusDoc = store.loadData(GBFS::StationStatus);
    const auto status = statusDoc.object().value(QLatin1String("data")).toObject().value(QLatin1String("stations")).toArray();
    for (const auto statV : status) {
        const auto stat = statV.toObject();
        const auto id = stat.value(QLatin1String("station_id")).toString();
        const auto it = std::find(selectedStationIds.begin(), selectedStationIds.end(), id);
        if (it == selectedStationIds.end()) {
            continue;
        }

        auto &loc = result[result.size() - selectedStationIds.size() + std::distance(selectedStationIds.begin(), it)];
        auto s = loc.rentalVehicleStation();
        s.setAvailableVehicles(stat.value(QLatin1String("num_bikes_available")).toInt(-1));
        loc.setRentalVehicleStation(s);
    }
}

bool GBFSBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    // (1) find all applicable services
    // (2) fetch updates where needed
    // (3) look for matching locations in their data

    QueryContext *context = nullptr;
    const auto &services = GBFSServiceRepository::services();
    for (const auto &s : services) {
        if (!isServiceApplicable(s, req) || s.discoveryUrl.scheme() != QLatin1String("https")) {
            continue;
        }
        qDebug() << "  " << s.systemId << "applicable for request";

        if (!context) {
            context = new QueryContext;
        }

        context->pendingJobs++;
        auto updateJob = new GBFSJob(nam, reply);
        QObject::connect(updateJob, &GBFSJob::finished, reply, [this, context, reply, updateJob, req]() {
            context->pendingJobs--;
            updateJob->deleteLater();
            if (updateJob->error() != GBFSJob::NoError) {
                context->errorMessage = updateJob->errorMessage();
                context->hasError = true;
            } else {
                appendResults(updateJob->service(), req, context->result);
            }

            if (context->pendingJobs == 0 &&  !context->stillStarting) {
                if (context->hasError) {
                    addError(reply, Reply::NetworkError, context->errorMessage);
                } else {
                    addResult(reply, std::move(context->result));
                }
                delete context;
            }
        });
        updateJob->discoverAndUpdate(s);
    }

    if (context && context->pendingJobs == 0) {
        if (!context->result.empty()) {
            addResult(reply, std::move(context->result));
        }
        delete context;
        return false;
    } else if (context) {
        context->stillStarting = false;
    }
    return true;
}

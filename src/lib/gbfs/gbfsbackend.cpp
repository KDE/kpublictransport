/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsbackend.h"
#include "gbfsservice.h"
#include "gbfsstore.h"
#include "gbfsjob.h"
#include "gbfsvehicletypes.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/RentalVehicle>

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <functional>

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
    std::vector<Attribution> attributions;
    QString errorMessage;
};

static QString stationIdToString(const QJsonValue &id)
{
    if (id.isDouble()) {
        return QString::number(id.toInt());
    }
    return id.toString();
}

static RentalVehicle::VehicleType gbfs2kptVehicleType(const GBFSVehicleType &vehicle)
{
    static constexpr struct {
        GBFSVehicleType::FormFactor formFactor;
        GBFSVehicleType::PropulsionType propulsion;
        RentalVehicle::VehicleType type;
    } const type_map[] = {
        { GBFSVehicleType::UndefinedFormFactor, GBFSVehicleType::UndefinedPropulsion, RentalVehicle::Unknown },
        { GBFSVehicleType::Bicycle, GBFSVehicleType::Human, RentalVehicle::Bicycle },
        { GBFSVehicleType::Bicycle, GBFSVehicleType::ElectricAssist, RentalVehicle::Pedelec },
        { GBFSVehicleType::Scooter, GBFSVehicleType::Electric, RentalVehicle::ElectricKickScooter },
        { GBFSVehicleType::Scooter, GBFSVehicleType::ElectricAssist, RentalVehicle::ElectricKickScooter },
        { GBFSVehicleType::Moped, GBFSVehicleType::Electric, RentalVehicle::ElectricMoped },
        { GBFSVehicleType::Car, GBFSVehicleType::Electric, RentalVehicle::Car },
        { GBFSVehicleType::Car, GBFSVehicleType::Combustion, RentalVehicle::Car },
    };

    for (const auto &map : type_map) {
        if (map.formFactor == vehicle.formFactor && map.propulsion == vehicle.propulsionType) {
            return map.type;
        }
    }

    qDebug() << "unhandled vehicle type:" << vehicle.formFactor << vehicle.propulsionType;
    return RentalVehicle::Unknown;
}

// we get some address values just being " , "...
static QString cleanAddress(const QString &input)
{
    if (std::any_of(input.begin(), input.end(), std::mem_fn(&QChar::isLetter))) {
        return input;
    }
    return {};
}

static void appendResults(const GBFSService &service, const LocationRequest &req, QueryContext *context)
{
    GBFSStore store(service.systemId);
    GBFSVehicleTypes vehicleTypes(service);

    RentalVehicleNetwork network;
    const auto sysInfoDoc = store.loadData(GBFS::SystemInformation);
    const auto sysInfo = sysInfoDoc.object().value(QLatin1String("data")).toObject();
    network.setName(sysInfo.value(QLatin1String("name")).toString());

    const auto stationsDoc = store.loadData(GBFS::StationInformation);
    const auto stations = stationsDoc.object().value(QLatin1String("data")).toObject().value(QLatin1String("stations")).toArray();

    std::vector<QString> selectedStationIds;
    for (const auto &stationV : stations) {
        const auto station = stationV.toObject();
        const auto lat = station.value(QLatin1String("lat")).toDouble();
        const auto lon = station.value(QLatin1String("lon")).toDouble();
        if (Location::distance(lat, lon, req.latitude(), req.longitude()) > req.maximumDistance()) {
            continue;
        }
        Location loc;
        loc.setType(Location::RentedVehicleStation);
        loc.setCoordinate(lat, lon);
        loc.setName(station.value(QLatin1String("name")).toString());
        const auto stationId = stationIdToString(station.value(QLatin1String("station_id")));
        loc.setIdentifier(service.systemId, stationId);
        loc.setStreetAddress(cleanAddress(station.value(QLatin1String("address")).toString()));
        loc.setPostalCode(station.value(QLatin1String("post_code")).toString());
        // TODO cover more properties

        RentalVehicleStation s;
        s.setNetwork(network);
        s.setCapacity(station.value(QLatin1String("capacity")).toInt(-1));
        loc.setData(s);

        selectedStationIds.push_back(stationId);
        context->result.push_back(loc);
    }

    const auto statusDoc = store.loadData(GBFS::StationStatus);
    const auto status = statusDoc.object().value(QLatin1String("data")).toObject().value(QLatin1String("stations")).toArray();
    for (const auto &statV : status) {
        const auto stat = statV.toObject();
        const auto id = stationIdToString(stat.value(QLatin1String("station_id")));
        const auto it = std::find(selectedStationIds.begin(), selectedStationIds.end(), id);
        if (it == selectedStationIds.end()) {
            continue;
        }

        auto &loc = context->result[context->result.size() - selectedStationIds.size() + std::distance(selectedStationIds.begin(), it)];
        auto s = loc.rentalVehicleStation();
        s.setAvailableVehicles(stat.value(QLatin1String("num_bikes_available")).toInt(-1));
        loc.setData(s);
    }

    const auto floatingDoc = store.loadData(GBFS::FreeBikeStatus);
    const auto floating = floatingDoc.object().value(QLatin1String("data")).toObject().value(QLatin1String("bikes")).toArray();
    for (const auto &bikeV : floating) {
        const auto bike = bikeV.toObject();
        if (bike.value(QLatin1String("is_reserved")).toBool() || bike.value(QLatin1String("is_disabled")).toBool()) {
            continue;
        }
        const auto lat = bike.value(QLatin1String("lat")).toDouble();
        const auto lon = bike.value(QLatin1String("lon")).toDouble();
        if (Location::distance(lat, lon, req.latitude(), req.longitude()) > req.maximumDistance()) {
            continue;
        }

        Location loc;
        loc.setName(network.name());
        loc.setType(Location::RentedVehicle);
        loc.setCoordinate(lat, lon);
        const auto stationId = bike.value(QLatin1String("bike_id")).toString();
        loc.setIdentifier(service.systemId, stationId);

        // TODO remaining range, deep rental links
        RentalVehicle vehicle;
        vehicle.setNetwork(network);
        const auto vehicleType = vehicleTypes.vehicleType(bike.value(QLatin1String("vehicle_type_id")).toString());
        vehicle.setType(gbfs2kptVehicleType(vehicleType));
        loc.setData(vehicle);

        context->result.push_back(loc);
    }

    Attribution attr;
    attr.setLicense(sysInfo.value(QLatin1String("license_id")).toString());
    attr.setLicenseUrl(QUrl(sysInfo.value(QLatin1String("license_url")).toString()));
    attr.setName(sysInfo.value(QLatin1String("attribution_organization_name")).toString());
    if (attr.name().isEmpty()) {
        attr.setName(network.name());
    }
    attr.setUrl(QUrl(sysInfo.value(QLatin1String("attribution_url")).toString()));
    if (attr.url().isEmpty()) {
        attr.setUrl(QUrl(sysInfo.value(QLatin1String("url")).toString()));
    }

    if (attr.hasLicense()) {
        context->attributions.push_back(std::move(attr));
    }
}

bool GBFSBackend::queryLocation(const LocationRequest &req, LocationReply *reply, QNetworkAccessManager *nam) const
{
    if ((req.types() & (Location::RentedVehicleStation | Location::RentedVehicle)) == 0) {
        return false;
    }

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
                appendResults(updateJob->service(), req, context);
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
            addAttributions(reply, std::move(context->attributions));
            addResult(reply, std::move(context->result));
        }
        delete context;
        return false;
    } else if (context) {
        context->stillStarting = false;
        return true;
    }
    return false;
}

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "gbfsbackend.h"
#include "gbfsservice.h"
#include "gbfsstore.h"
#include "gbfsjob.h"
#include "gbfsreader.h"
#include "gbfsvehicletypes.h"

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Location>
#include <KPublicTransport/LocationReply>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/RentalVehicle>

#include <QCoreApplication>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>

#include <cmath>
#include <functional>

using namespace KPublicTransport;

GBFSBackend::GBFSBackend()
{
    QTimer::singleShot(std::chrono::seconds(10), Qt::CoarseTimer, QCoreApplication::instance(), []() { GBFSStore::expire(); });
}

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
        { GBFSVehicleType::Scooter, GBFSVehicleType::UndefinedPropulsion, RentalVehicle::ElectricKickScooter },
        { GBFSVehicleType::Moped, GBFSVehicleType::Electric, RentalVehicle::ElectricMoped },
        { GBFSVehicleType::Moped, GBFSVehicleType::UndefinedPropulsion, RentalVehicle::ElectricMoped },
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
    if (std::any_of(input.begin(), input.end(), std::mem_fn(qOverload<>(&QChar::isLetter)))) {
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
    const auto sysInfo = GBFSReader::dataObject(sysInfoDoc);
    network.setName(sysInfo.value(QLatin1String("name")).toString());

    const auto stationsDoc = store.loadData(GBFS::StationInformation);
    const auto stations = GBFSReader::dataValue(stationsDoc, QLatin1String("stations")).toArray();

    std::vector<QString> selectedStationIds;
    for (const auto &stationV : stations) {
        const auto station = stationV.toObject();
        const auto lat = GBFSReader::readLatitude(station);
        const auto lon = GBFSReader::readLongitude(station);
        if (std::isnan(lat) || std::isnan(lon) || Location::distance(lat, lon, req.latitude(), req.longitude()) > req.maximumDistance()) {
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
        const auto vehicleCapacities = station.value(QLatin1String("vehicle_capacity")).toObject();
        for (auto it = vehicleCapacities.begin(); it != vehicleCapacities.end(); ++it) {
            const auto type = gbfs2kptVehicleType(vehicleTypes.vehicleType(it.key()));
            s.setCapacity(type, it.value().toInt(-1));
        }

        loc.setData(s);
        selectedStationIds.push_back(stationId);
        context->result.push_back(loc);
    }

    const auto statusDoc = store.loadData(GBFS::StationStatus);
    const auto status = GBFSReader::dataValue(statusDoc, QLatin1String("stations")).toArray();
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
        const auto availableVehicleTypes = stat.value(QLatin1String("vehicle_types_available")).toArray();
        for (const auto &v : availableVehicleTypes) {
            const auto obj = v.toObject();
            const auto type = gbfs2kptVehicleType(vehicleTypes.vehicleType(obj.value(QLatin1String("vehicle_type_id")).toString()));
            s.setAvailableVehicles(type, obj.value(QLatin1String("count")).toInt(-1));
        }

        loc.setData(s);
    }

    const auto floatingDoc = store.loadData(GBFS::FreeBikeStatus);
    const auto floating = GBFSReader::dataValue(floatingDoc, QLatin1String("bikes")).toArray();
    for (const auto &bikeV : floating) {
        const auto bike = bikeV.toObject();
        if (bike.value(QLatin1String("is_reserved")).toBool() || bike.value(QLatin1String("is_disabled")).toBool()) {
            continue;
        }
        const auto lat = GBFSReader::readLatitude(bike);
        const auto lon = GBFSReader::readLongitude(bike);
        const bool selectedByCoord = !std::isnan(lat) && !std::isnan(lon) && Location::distance(lat, lon, req.latitude(), req.longitude()) > req.maximumDistance();

        // GBFS v2.1: docked vehicle status - TODO do we want to drop the corresponding station in that case?
        const auto id = stationIdToString(bike.value(QLatin1String("station_id")));
        const auto it = std::find(selectedStationIds.begin(), selectedStationIds.end(), id);
        if (it == selectedStationIds.end() && !selectedByCoord) {
            continue;
        }

        Location loc;
        loc.setName(network.name());
        loc.setType(Location::RentedVehicle);
        if (selectedByCoord) {
            loc.setCoordinate(lat, lon);
        } else {
            const auto &station = context->result[context->result.size() - selectedStationIds.size() + std::distance(selectedStationIds.begin(), it)];
            loc.setCoordinate(station.latitude(), station.longitude());
        }
        const auto bikeId = bike.value(QLatin1String("bike_id")).toString();
        loc.setIdentifier(service.systemId, bikeId);

        // TODO deep rental links
        RentalVehicle vehicle;
        vehicle.setNetwork(network);

        auto vehicleTypeId = bike.value(QLatin1String("vehicle_type_id")).toString();
        if (vehicleTypeId.isEmpty()) { // non-compliant format used eg. by Lime
            vehicleTypeId = bike.value(QLatin1String("vehicle_type")).toString();
        }
        const auto vehicleType = vehicleTypes.vehicleType(vehicleTypeId);
        vehicle.setType(gbfs2kptVehicleType(vehicleType));
        if (!vehicleType.name.isEmpty()) {
            loc.setName(vehicleType.name);
        }

        const auto range = bike.value(QLatin1String("current_range_meters")).toInt();
        if (range > 0) { // there's too many reporting 0 for unknown that we can assume 0 means actually empty...
            vehicle.setRemainingRange(range);
        }

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
        updateJob->setRequestedData({GBFS::StationInformation, GBFS::StationStatus, GBFS::FreeBikeStatus, GBFS::VehicleTypes});
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
                if (context->hasError && context->result.empty()) {
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

/*
    SPDX-FileCopyrightText: 2019 Nicolas Fella <nicolas.fella@gmx.de>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORTQMLPLUGIN_H
#define KPUBLICTRANSPORTQMLPLUGIN_H

#include <QQmlEngine>
#include <QQmlExtensionPlugin>

#include <KPublicTransport/BackendModel>
#include <KPublicTransport/CoverageArea>
#include <KPublicTransport/Equipment>
#include <KPublicTransport/IndividualTransport>
#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyQueryModel>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Line>
#include <KPublicTransport/LocationHistoryModel>
#include <KPublicTransport/LocationQueryModel>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/Manager>
#include <KPublicTransport/Path>
#include <KPublicTransport/PathModel>
#include <KPublicTransport/Platform>
#include <KPublicTransport/RentalVehicle>
#include <KPublicTransport/StopoverQueryModel>
#include <KPublicTransport/StopoverRequest>
#include <KPublicTransport/Vehicle>
#include <KPublicTransport/VehicleLayoutQueryModel>
#include <KPublicTransport/VehicleLayoutRequest>

struct ManagerForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::Manager)
    QML_NAMED_ELEMENT(Manager)
};

struct StopoverQueryModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::StopoverQueryModel)
    QML_NAMED_ELEMENT(StopoverQueryModel)
};

struct JourneyQueryModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::JourneyQueryModel)
    QML_NAMED_ELEMENT(JourneyQueryModel)
};

struct LocationHistoryModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::LocationHistoryModel)
    QML_NAMED_ELEMENT(LocationHistoryModel)
};

struct LocationQueryModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::LocationQueryModel)
    QML_NAMED_ELEMENT(LocationQueryModel)
};

struct BackendModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::BackendModel)
    QML_NAMED_ELEMENT(BackendModel)
};

struct VehicleLayoutQueryModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::VehicleLayoutQueryModel)
    QML_NAMED_ELEMENT(VehicleLayoutQueryModel)
};

struct PathModelForeign {
    Q_GADGET
    QML_ELEMENT
    QML_FOREIGN(KPublicTransport::PathModel)
    QML_NAMED_ELEMENT(PathModel)
};

namespace DisruptionForeign
{
Q_NAMESPACE
QML_NAMED_ELEMENT(Disruption)
QML_FOREIGN_NAMESPACE(KPublicTransport::Disruption)
};

namespace LoadForeign
{
Q_NAMESPACE
QML_NAMED_ELEMENT(Load)
QML_FOREIGN_NAMESPACE(KPublicTransport::Load)
};

struct CoverageArea {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::CoverageArea)
    QML_VALUE_TYPE(coverageArea)
};

struct EquipmentForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Equipment)
    QML_VALUE_TYPE(equipment)
};

struct LocationForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Location)
    QML_VALUE_TYPE(location)
};

struct IndividualTransportForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::IndividualTransport)
    QML_VALUE_TYPE(individualTransport)
};

struct JourneyRequestForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::JourneyRequest)
    QML_VALUE_TYPE(journeyRequest)
};

struct JourneySectionForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::JourneySection)
    QML_VALUE_TYPE(journeySection)
};

struct LineForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Line)
    QML_VALUE_TYPE(line)
};

struct LocationRequestForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::LocationRequest)
    QML_VALUE_TYPE(locationRequest)
};

struct PathSectionForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::PathSection)
    QML_VALUE_TYPE(pathSection)
};

struct PlatformForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Platform)
    QML_VALUE_TYPE(platform)
};

struct RentalVehicleForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::RentalVehicle)
    QML_VALUE_TYPE(rentalVehicle)
};

struct StopoverRequestForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::StopoverRequest)
    QML_VALUE_TYPE(stopoverRequest)
};

struct VehicleForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Vehicle)
    QML_VALUE_TYPE(vehicle)
};

struct VehicleLayoutRequestForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::VehicleLayoutRequest)
    QML_VALUE_TYPE(vehicleLayoutRequest)
};

struct VehicleSectionForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::VehicleSection)
    QML_VALUE_TYPE(vehicleSection)
};

struct RouteForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Route)
    QML_VALUE_TYPE(route)
};

struct StopoverForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Stopover)
    QML_VALUE_TYPE(stopover)
};

struct JourneyForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Journey)
    QML_VALUE_TYPE(journey)
};

class KPublicTransportQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

    void registerTypes(const char* uri) override;
};

#endif // KPUBLICTRANSPORTQMLPLUGIN_H


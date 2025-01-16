/*
    SPDX-FileCopyrightText: 2019 Nicolas Fella <nicolas.fella@gmx.de>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORTQMLPLUGIN_H
#define KPUBLICTRANSPORTQMLPLUGIN_H

#include <QQmlEngine>
#include <QQmlExtensionPlugin>

#include <KPublicTransport/Attribution>
#include <KPublicTransport/Backend>
#include <KPublicTransport/BackendModel>
#include <KPublicTransport/CoverageArea>
#include <KPublicTransport/Equipment>
#include <KPublicTransport/Feature>
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

#define FOREIGN_ENUM_GADGET(Class) \
class Class ## Derived: public KPublicTransport::Class \
{ \
    Q_GADGET \
}; \
namespace Class ## DerivedForeign \
{ \
    Q_NAMESPACE \
    QML_NAMED_ELEMENT(Class) \
    QML_FOREIGN_NAMESPACE(Class ## Derived) \
} \


struct AttributionForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Attribution)
    QML_VALUE_TYPE(attribution)
    QML_UNCREATABLE("only provided from C++ API")
};

struct BackendForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Backend)
    QML_VALUE_TYPE(backend)
};

struct BackendModelForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::BackendModel)
    QML_NAMED_ELEMENT(BackendModel)
};

struct CoverageArea {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::CoverageArea)
    QML_VALUE_TYPE(coverageArea)
};
FOREIGN_ENUM_GADGET(CoverageArea)

namespace DisruptionForeign
{
Q_NAMESPACE
QML_NAMED_ELEMENT(Disruption)
QML_FOREIGN_NAMESPACE(KPublicTransport::Disruption)
};

struct EquipmentForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Equipment)
    QML_VALUE_TYPE(equipment)
};
FOREIGN_ENUM_GADGET(Equipment)

struct FeatureForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Feature)
    QML_VALUE_TYPE(feature)
    QML_UNCREATABLE("only provided from C++ API")
};
FOREIGN_ENUM_GADGET(Feature)

struct FeatureType
{
    Q_GADGET
    QML_ANONYMOUS
public:
    Q_INVOKABLE [[nodiscard]] static QString typeIconName(KPublicTransport::Feature::Type type)
    {
        return KPublicTransport::Feature::typeIconName(type);
    }
};

struct IndividualTransportForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::IndividualTransport)
    QML_VALUE_TYPE(individualTransport)
    QML_STRUCTURED_VALUE
};
FOREIGN_ENUM_GADGET(IndividualTransport)

struct JourneyForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Journey)
    QML_VALUE_TYPE(journey)
    QML_STRUCTURED_VALUE
};

struct JourneyRequestForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::JourneyRequest)
    QML_VALUE_TYPE(journeyRequest)
    QML_STRUCTURED_VALUE
};
FOREIGN_ENUM_GADGET(JourneyRequest)

struct JourneyQueryModelForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::JourneyQueryModel)
    QML_NAMED_ELEMENT(JourneyQueryModel)
};

struct JourneySectionForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::JourneySection)
    QML_VALUE_TYPE(journeySection)
    QML_STRUCTURED_VALUE
};
FOREIGN_ENUM_GADGET(JourneySection)

struct LineForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Line)
    QML_VALUE_TYPE(line)
    QML_STRUCTURED_VALUE
};
FOREIGN_ENUM_GADGET(Line)
struct LineMode
{
    Q_GADGET
    QML_ANONYMOUS
public:
    Q_INVOKABLE [[nodiscard]] static QString iconName(KPublicTransport::Line::Mode mode)
    {
        return KPublicTransport::Line::modeIconName(mode);
    }
};

namespace LoadForeign
{
Q_NAMESPACE
QML_NAMED_ELEMENT(Load)
QML_FOREIGN_NAMESPACE(KPublicTransport::Load)
};

struct LoadInfoForeign
{
    Q_GADGET
    QML_FOREIGN(KPublicTransport::LoadInfo)
    QML_VALUE_TYPE(loadInfo)
    QML_STRUCTURED_VALUE
};

struct LocationForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Location)
    QML_VALUE_TYPE(location)
    QML_STRUCTURED_VALUE
};
FOREIGN_ENUM_GADGET(Location)

struct LocationHistoryModelForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::LocationHistoryModel)
    QML_NAMED_ELEMENT(LocationHistoryModel)
};

struct LocationRequestForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::LocationRequest)
    QML_VALUE_TYPE(locationRequest)
    QML_STRUCTURED_VALUE
};
FOREIGN_ENUM_GADGET(LocationRequest)

struct LocationQueryModelForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::LocationQueryModel)
    QML_NAMED_ELEMENT(LocationQueryModel)
};

struct ManagerForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Manager)
    QML_NAMED_ELEMENT(Manager)
};

struct PathForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Path)
    QML_VALUE_TYPE(path)
};

struct PathModelForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::PathModel)
    QML_NAMED_ELEMENT(PathModel)
};

struct PathSectionForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::PathSection)
    QML_VALUE_TYPE(pathSection)
};
FOREIGN_ENUM_GADGET(PathSection)

struct PlatformForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Platform)
    QML_VALUE_TYPE(platform)
};
FOREIGN_ENUM_GADGET(Platform)

struct RentalVehicleForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::RentalVehicle)
    QML_VALUE_TYPE(rentalVehicle)
    QML_STRUCTURED_VALUE
};
FOREIGN_ENUM_GADGET(RentalVehicle)

struct RouteForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Route)
    QML_VALUE_TYPE(route)
    QML_STRUCTURED_VALUE
};

struct StopoverForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Stopover)
    QML_VALUE_TYPE(stopover)
};

struct StopoverRequestForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::StopoverRequest)
    QML_VALUE_TYPE(stopoverRequest)
    QML_STRUCTURED_VALUE
};
FOREIGN_ENUM_GADGET(StopoverRequest)

struct StopoverQueryModelForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::StopoverQueryModel)
    QML_NAMED_ELEMENT(StopoverQueryModel)
};

struct VehicleForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::Vehicle)
    QML_VALUE_TYPE(vehicle)
    QML_UNCREATABLE("only provided from C++ API")
};
FOREIGN_ENUM_GADGET(Vehicle)

struct VehicleLayoutRequestForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::VehicleLayoutRequest)
    QML_VALUE_TYPE(vehicleLayoutRequest)
    QML_STRUCTURED_VALUE
};
FOREIGN_ENUM_GADGET(VehicleLayoutRequest)

struct VehicleLayoutQueryModelForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::VehicleLayoutQueryModel)
    QML_NAMED_ELEMENT(VehicleLayoutQueryModel)
};

struct VehicleSectionForeign {
    Q_GADGET
    QML_FOREIGN(KPublicTransport::VehicleSection)
    QML_VALUE_TYPE(vehicleSection)
    QML_UNCREATABLE("only provided from C++ API")
};
FOREIGN_ENUM_GADGET(VehicleSection)


class KPublicTransportQmlPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT

    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

    void registerTypes(const char* uri) override;
};

#endif // KPUBLICTRANSPORTQMLPLUGIN_H


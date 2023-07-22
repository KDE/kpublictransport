/*
    SPDX-FileCopyrightText: 2019 Nicolas Fella <nicolas.fella@gmx.de>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kpublictransportqmlplugin.h"
#include "linemetadatawrapper.h"

#include <QQmlEngine>
#include <QQmlContext>

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
#include <KPublicTransport/StopoverRequest>
#include <KPublicTransport/StopoverQueryModel>
#include <KPublicTransport/Vehicle>
#include <KPublicTransport/VehicleLayoutQueryModel>
#include <KPublicTransport/VehicleLayoutRequest>

void KPublicTransportQmlPlugin::registerTypes(const char*)
{
    qRegisterMetaType<KPublicTransport::CoverageArea>();
    qRegisterMetaType<KPublicTransport::CoverageArea::Type>();
    qRegisterMetaType<KPublicTransport::Equipment>();
    qRegisterMetaType<KPublicTransport::Journey>();
    qRegisterMetaType<KPublicTransport::Line>();
    qRegisterMetaType<KPublicTransport::Line::Mode>();
    qRegisterMetaType<KPublicTransport::LoadInfo>();
    qRegisterMetaType<KPublicTransport::Location>();
    qRegisterMetaType<KPublicTransport::Platform>();
    qRegisterMetaType<KPublicTransport::RentalVehicle>();
    qRegisterMetaType<KPublicTransport::RentalVehicleStation>();
    qRegisterMetaType<KPublicTransport::Stopover>();
    qRegisterMetaType<KPublicTransport::IndividualTransport>();

#define REGISTER_METAOBJECT(Type) \
    qmlRegisterUncreatableMetaObject(KPublicTransport::Type::staticMetaObject, "org.kde.kpublictransport", 1, 0, #Type, {});

    REGISTER_METAOBJECT(CoverageArea)
    REGISTER_METAOBJECT(Disruption)
    REGISTER_METAOBJECT(Equipment)
    REGISTER_METAOBJECT(IndividualTransport)
    REGISTER_METAOBJECT(JourneyRequest)
    REGISTER_METAOBJECT(JourneySection)
    REGISTER_METAOBJECT(Line)
    REGISTER_METAOBJECT(Load)
    REGISTER_METAOBJECT(Location)
    REGISTER_METAOBJECT(LocationRequest)
    REGISTER_METAOBJECT(PathSection)
    REGISTER_METAOBJECT(Platform)
    REGISTER_METAOBJECT(RentalVehicle)
    REGISTER_METAOBJECT(StopoverRequest)
    REGISTER_METAOBJECT(Vehicle)
    REGISTER_METAOBJECT(VehicleLayoutRequest)
    REGISTER_METAOBJECT(VehicleSection)

    qmlRegisterType<KPublicTransport::Manager>("org.kde.kpublictransport", 1, 0, "Manager");
    qmlRegisterType<KPublicTransport::JourneyQueryModel>("org.kde.kpublictransport", 1, 0, "JourneyQueryModel");
    qmlRegisterType<KPublicTransport::LocationHistoryModel>("org.kde.kpublictransport", 1, 0, "LocationHistoryModel");
    qmlRegisterType<KPublicTransport::LocationQueryModel>("org.kde.kpublictransport", 1, 0, "LocationQueryModel");
    qmlRegisterType<KPublicTransport::BackendModel>("org.kde.kpublictransport", 1, 0, "BackendModel");
    qmlRegisterType<KPublicTransport::StopoverQueryModel>("org.kde.kpublictransport", 1, 0, "StopoverQueryModel");
    qmlRegisterType<KPublicTransport::VehicleLayoutQueryModel>("org.kde.kpublictransport", 1, 0, "VehicleLayoutQueryModel");
    qmlRegisterType<KPublicTransport::PathModel>("org.kde.kpublictransport", 1, 0, "PathModel");

    qmlRegisterSingletonType("org.kde.kpublictransport", 1, 0, "LineMetaData", [](QQmlEngine*, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(KPublicTransport::LineMetaDataWrapper());
    });
}

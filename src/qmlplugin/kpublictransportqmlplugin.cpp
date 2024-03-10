/*
    SPDX-FileCopyrightText: 2019 Nicolas Fella <nicolas.fella@gmx.de>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kpublictransportqmlplugin.h"
#include "linemetadatawrapper.h"

#include <QQmlEngine>
#include <QQmlContext>

#include <KPublicTransport/CoverageArea>
#include <KPublicTransport/Equipment>
#include <KPublicTransport/IndividualTransport>
#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Line>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/Path>
#include <KPublicTransport/Platform>
#include <KPublicTransport/RentalVehicle>
#include <KPublicTransport/StopoverRequest>
#include <KPublicTransport/Vehicle>
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
    REGISTER_METAOBJECT(Equipment)
    REGISTER_METAOBJECT(IndividualTransport)
    REGISTER_METAOBJECT(JourneyRequest)
    REGISTER_METAOBJECT(JourneySection)
    REGISTER_METAOBJECT(Line)
    REGISTER_METAOBJECT(Location)
    REGISTER_METAOBJECT(LocationRequest)
    REGISTER_METAOBJECT(PathSection)
    REGISTER_METAOBJECT(Platform)
    REGISTER_METAOBJECT(RentalVehicle)
    REGISTER_METAOBJECT(StopoverRequest)
    REGISTER_METAOBJECT(Vehicle)
    REGISTER_METAOBJECT(VehicleLayoutRequest)
    REGISTER_METAOBJECT(VehicleSection)

    qmlRegisterSingletonType("org.kde.kpublictransport", 1, 0, "LineMetaData", [](QQmlEngine*, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(KPublicTransport::LineMetaDataWrapper());
    });
}

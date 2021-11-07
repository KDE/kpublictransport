/*
    SPDX-FileCopyrightText: 2019 Nicolas Fella <nicolas.fella@gmx.de>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kpublictransportqmlplugin.h"
#include "linemetadatawrapper.h"

#include <QQmlEngine>
#include <QQmlContext>

#include <KPublicTransport/BackendModel>
#include <KPublicTransport/Equipment>
#include <KPublicTransport/IndividualTransport>
#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyQueryModel>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Line>
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
    qRegisterMetaType<KPublicTransport::Equipment>();
    qRegisterMetaType<KPublicTransport::Line>();
    qRegisterMetaType<KPublicTransport::Line::Mode>();
    qRegisterMetaType<KPublicTransport::LoadInfo>();
    qRegisterMetaType<KPublicTransport::Location>();
    qRegisterMetaType<KPublicTransport::Platform>();
    qRegisterMetaType<KPublicTransport::RentalVehicle>();
    qRegisterMetaType<KPublicTransport::Stopover>();
    qRegisterMetaType<KPublicTransport::IndividualTransport>();
    // backward compat
    qRegisterMetaType<KPublicTransport::StopoverRequest>("KPublicTransport::DepartureRequest");

    qmlRegisterUncreatableMetaObject(KPublicTransport::Disruption::staticMetaObject, "org.kde.kpublictransport", 1, 0, "Disruption", {});
    qmlRegisterUncreatableMetaObject(KPublicTransport::Load::staticMetaObject, "org.kde.kpublictransport", 1, 0, "Load", {});

    qmlRegisterUncreatableType<KPublicTransport::Line>("org.kde.kpublictransport", 1, 0, "Line", {});
    qmlRegisterUncreatableType<KPublicTransport::Location>("org.kde.kpublictransport", 1, 0, "Location", {});
    qmlRegisterUncreatableType<KPublicTransport::JourneySection>("org.kde.kpublictransport", 1, 0, "JourneySection", {});
    qmlRegisterUncreatableType<KPublicTransport::Vehicle>("org.kde.kpublictransport", 1, 0, "Vehicle", {});
    qmlRegisterUncreatableType<KPublicTransport::VehicleSection>("org.kde.kpublictransport", 1, 0, "VehicleSection", {});
    qmlRegisterUncreatableType<KPublicTransport::PathSection>("org.kde.kpublictransport", 1, 0, "PathSection", {});
    qmlRegisterUncreatableType<KPublicTransport::Platform>("org.kde.kpublictransport", 1, 0, "Platform", {});
    qmlRegisterUncreatableType<KPublicTransport::RentalVehicle>("org.kde.kpublictransport", 1, 0, "RentalVehicle", {});
    qmlRegisterUncreatableType<KPublicTransport::Equipment>("org.kde.kpublictransport", 1, 0, "Equipment", {});

    qmlRegisterUncreatableType<KPublicTransport::JourneyRequest>("org.kde.kpublictransport", 1, 0, "JourneyRequest", {});
    qmlRegisterUncreatableType<KPublicTransport::LocationRequest>("org.kde.kpublictransport", 1, 0, "LocationRequest", {});
    qmlRegisterUncreatableType<KPublicTransport::StopoverRequest>("org.kde.kpublictransport", 1, 0, "StopoverRequest", {});
    qmlRegisterUncreatableType<KPublicTransport::VehicleLayoutRequest>("org.kde.kpublictransport", 1, 0, "VehicleLayoutRequery", {});
    qmlRegisterUncreatableType<KPublicTransport::IndividualTransport>("org.kde.kpublictransport", 1, 0, "IndividualTransport", {});
    // backward compat
    qmlRegisterUncreatableType<KPublicTransport::StopoverRequest>("org.kde.kpublictransport", 1, 0, "DepartureRequest", {});

    qmlRegisterType<KPublicTransport::Manager>("org.kde.kpublictransport", 1, 0, "Manager");
    qmlRegisterType<KPublicTransport::JourneyQueryModel>("org.kde.kpublictransport", 1, 0, "JourneyQueryModel");
    qmlRegisterType<KPublicTransport::LocationQueryModel>("org.kde.kpublictransport", 1, 0, "LocationQueryModel");
    qmlRegisterType<KPublicTransport::BackendModel>("org.kde.kpublictransport", 1, 0, "BackendModel");
    qmlRegisterType<KPublicTransport::StopoverQueryModel>("org.kde.kpublictransport", 1, 0, "StopoverQueryModel");
    qmlRegisterType<KPublicTransport::VehicleLayoutQueryModel>("org.kde.kpublictransport", 1, 0, "VehicleLayoutQueryModel");
    qmlRegisterType<KPublicTransport::PathModel>("org.kde.kpublictransport", 1, 0, "PathModel");
    // backward compat
    qmlRegisterType<KPublicTransport::StopoverQueryModel>("org.kde.kpublictransport", 1, 0, "DepartureQueryModel");

    qmlRegisterSingletonType("org.kde.kpublictransport", 1, 0, "LineMetaData", [](QQmlEngine*, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(KPublicTransport::LineMetaDataWrapper());
    });
}

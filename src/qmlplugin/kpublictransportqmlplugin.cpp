/*
    SPDX-FileCopyrightText: 2019 Nicolas Fella <nicolas.fella@gmx.de>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kpublictransportqmlplugin.h"

#include "linemetadatawrapper.h"

#include <KPublicTransport/ClassUtil>

#include <QQmlEngine>
#include <QQmlContext>

void KPublicTransportQmlPlugin::registerTypes(const char*)
{
    qmlRegisterSingletonType("org.kde.kpublictransport", 1, 0, "LineMetaData", [](QQmlEngine*, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(KPublicTransport::LineMetaDataWrapper());
    });
    qmlRegisterSingletonType("org.kde.kpublictransport", 1, 0, "LineMode", [](QQmlEngine*, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(LineMode());
    });
    qmlRegisterSingletonType("org.kde.kpublictransport", 1, 0, "RentalVehicleType", [](QQmlEngine*, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(KPublicTransport::RentalVehicle());
    });
    qmlRegisterSingletonType("org.kde.kpublictransport", 1, 0, "IndividualTransportMode", [](QQmlEngine*, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(KPublicTransport::IndividualTransport());
    });
    qmlRegisterSingletonType("org.kde.kpublictransport", 1, 0, "JourneySectionMode", [](QQmlEngine*, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(KPublicTransport::JourneySection());
    });
    qmlRegisterSingletonType("org.kde.kpublictransport", 1, 0, "FeatureType", [](QQmlEngine*, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(FeatureType());
    });
    qmlRegisterSingletonType("org.kde.kpublictransport", 1, 0, "ClassUtil", [](QQmlEngine*, QJSEngine *engine) -> QJSValue {
        return engine->toScriptValue(KPublicTransport::ClassUtil());
    });
}

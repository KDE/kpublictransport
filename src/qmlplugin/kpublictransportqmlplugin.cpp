/*
    Copyright (C) 2019 Nicolas Fella <nicolas.fella@gmx.de>

    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU Library General Public License as published by
    the Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
    License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "kpublictransportqmlplugin.h"

#include <QQmlEngine>
#include <QQmlContext>

#include <KPublicTransport/BackendModel>
#include <KPublicTransport/DepartureQueryModel>
#include <KPublicTransport/DepartureRequest>
#include <KPublicTransport/Journey>
#include <KPublicTransport/JourneyQueryModel>
#include <KPublicTransport/JourneyRequest>
#include <KPublicTransport/Line>
#include <KPublicTransport/LocationQueryModel>
#include <KPublicTransport/LocationRequest>
#include <KPublicTransport/Manager>
#include <KPublicTransport/Platform>
#include <KPublicTransport/Vehicle>
#include <KPublicTransport/VehicleLayoutQueryModel>
#include <KPublicTransport/VehicleLayoutRequest>

void KPublicTransportQmlPlugin::registerTypes(const char*)
{
    qRegisterMetaType<KPublicTransport::Location>();
    qRegisterMetaType<KPublicTransport::Platform>();

    qmlRegisterUncreatableMetaObject(KPublicTransport::Disruption::staticMetaObject, "org.kde.kpublictransport", 1, 0, "Disruption", {});

    qmlRegisterUncreatableType<KPublicTransport::Line>("org.kde.kpublictransport", 1, 0, "Line", {});
    qmlRegisterUncreatableType<KPublicTransport::JourneySection>("org.kde.kpublictransport", 1, 0, "JourneySection", {});
    qmlRegisterUncreatableType<KPublicTransport::Vehicle>("org.kde.kpublictransport", 1, 0, "Vehicle", {});
    qmlRegisterUncreatableType<KPublicTransport::VehicleSection>("org.kde.kpublictransport", 1, 0, "VehicleSection", {});
    qmlRegisterUncreatableType<KPublicTransport::Platform>("org.kde.kpublictransport", 1, 0, "Platform", {});

    qmlRegisterUncreatableType<KPublicTransport::DepartureRequest>("org.kde.kpublictransport", 1, 0, "DepartureRequest", {});
    qmlRegisterUncreatableType<KPublicTransport::JourneyRequest>("org.kde.kpublictransport", 1, 0, "JourneyRequest", {});
    qmlRegisterUncreatableType<KPublicTransport::LocationRequest>("org.kde.kpublictransport", 1, 0, "LocationRequest", {});
    qmlRegisterUncreatableType<KPublicTransport::VehicleLayoutRequest>("org.kde.kpublictransport", 1, 0, "VehicleLayoutRequery", {});

    qmlRegisterType<KPublicTransport::Manager>("org.kde.kpublictransport", 1, 0, "Manager");
    qmlRegisterType<KPublicTransport::DepartureQueryModel>("org.kde.kpublictransport", 1, 0, "DepartureQueryModel");
    qmlRegisterType<KPublicTransport::JourneyQueryModel>("org.kde.kpublictransport", 1, 0, "JourneyQueryModel");
    qmlRegisterType<KPublicTransport::LocationQueryModel>("org.kde.kpublictransport", 1, 0, "LocationQueryModel");
    qmlRegisterType<KPublicTransport::BackendModel>("org.kde.kpublictransport", 1, 0, "BackendModel");
    qmlRegisterType<KPublicTransport::VehicleLayoutQueryModel>("org.kde.kpublictransport", 1, 0, "VehicleLayoutQueryModel");
}

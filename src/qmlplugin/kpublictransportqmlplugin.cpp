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

#include <KPublicTransport/DepartureQueryModel>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Line>
#include <KPublicTransport/Manager>

void KPublicTransportQmlPlugin::registerTypes(const char*)
{
    qmlRegisterUncreatableType<KPublicTransport::Line>("org.kde.kpublictransport", 1, 0, "Line", {});
    qmlRegisterUncreatableType<KPublicTransport::Manager>("org.kde.kpublictransport", 1, 0, "Manager", {});
    qmlRegisterUncreatableType<KPublicTransport::JourneySection>("org.kde.kpublictransport", 1, 0, "JourneySection", {});

    qmlRegisterType<KPublicTransport::DepartureQueryModel>("org.kde.kpublictransport", 1, 0, "DepartureQueryModel");
}

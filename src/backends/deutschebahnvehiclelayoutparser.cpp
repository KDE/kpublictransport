/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#include "deutschebahnvehiclelayoutparser.h"

#include <QJsonDocument>
#include <QJsonObject>

using namespace KPublicTransport;

bool DeutscheBahnVehicleLayoutParser::parse(const QByteArray &data)
{
    auto doc = QJsonDocument::fromJson(data);
    auto obj = doc.object().value(QLatin1String("data")).toObject().value(QLatin1String("istformation")).toObject();

    vehicle.setName(obj.value(QLatin1String("zuggattung")).toString() + QLatin1Char(' ') + obj.value(QLatin1String("zugnummer")).toString());
    // TODO
    return true;
}

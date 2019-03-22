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

#include "hafasbackend.h"

#include <QJsonObject>
#include <QMetaEnum>

using namespace KPublicTransport;

void HafasBackend::setLineModeMap(const QJsonObject& obj)
{
    const auto idx = Line::staticMetaObject.indexOfEnumerator("Mode");
    Q_ASSERT(idx >= 0);
    const auto me = Line::staticMetaObject.enumerator(idx);
    for (auto it = obj.begin(); it != obj.end(); ++it) {
        m_lineModeMap[it.key().toInt()] = static_cast<Line::Mode>(me.keyToValue(it.value().toString().toUtf8().constData()));
    }
}

QString HafasBackend::locationIdentifierType() const
{
    return m_locationIdentifierType.isEmpty() ? backendId() : m_locationIdentifierType;
}

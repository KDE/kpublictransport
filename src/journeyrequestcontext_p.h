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

#ifndef KPUBLICTRANSPORT_JOURNEYREQUESTCONTEXT_P_H
#define KPUBLICTRANSPORT_JOURNEYREQUESTCONTEXT_P_H

#include <QDateTime>
#include <QVariant>

namespace KPublicTransport {

class AbstractBackend;

/** Backend-specific request information. */
class JourneyRequestContext
{
public:
    explicit JourneyRequestContext();
    ~JourneyRequestContext();
    bool operator<(const AbstractBackend *other) const;

    const AbstractBackend *backend = nullptr;

    enum QueryType {
        Normal,
        Next,
        Previous
    };
    QueryType type = Normal;
    // for departure/next this is the time of the last previously found departure time
    // for departure/previous this is the first previously found departure time
    // for arrival/next this is the last previously found arrival time
    // for arrival/previous this is the first previously found arrival time
    QDateTime dateTime;
    QVariant backendData;
};

}

#endif // KPUBLICTRANSPORT_JOURNEYREQUESTCONTEXT_P_H

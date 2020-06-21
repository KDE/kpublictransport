/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_LOAD_H
#define KPUBLICTRANSPORT_LOAD_H

#include "datatypes.h"

namespace KPublicTransport {

/** Vehicle load categories. */
namespace Load
{
    KPUBLICTRANSPORT_EXPORT Q_NAMESPACE

    /** Vehicle load categories. */
    enum Category {
        Unknown, ///< no load information are available
        Low,
        Medium,
        High,
        Full, ///< no remaining seats
    };
    Q_ENUM_NS(Category)
}

class LoadInfoPrivate;

/** Vehicle load information.
 *  This consists of a load category and additional
 *  specifiers for which part of the vehicle this applies to,
 *  such as the class or vehicle section.
 */
class LoadInfo
{
    KPUBLICTRANSPORT_GADGET(LoadInfo)
    /** Load category. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Load::Category, load, setLoad)
    /** Seating class, empty if not applicable.
     *  TODO should this be the same enum as in VehicleSection?
     */
    KPUBLICTRANSPORT_PROPERTY(QString, seatingClass, setSeatingClass)
    // TODO vehicle section, once we have a backend reporting this (SBB has that in theory I think)
public:
};

}

Q_DECLARE_METATYPE(KPublicTransport::LoadInfo)

#endif // KPUBLICTRANSPORT_LOAD_H

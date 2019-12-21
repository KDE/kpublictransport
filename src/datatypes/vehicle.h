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

#ifndef KPUBLICTRANSPORT_VEHICLE_H
#define KPUBLICTRANSPORT_VEHICLE_H

#include <kpublictransport_export.h>

#include "datatypes.h"

namespace KPublicTransport {

class VehicleSectionPrivate;

/** Information about a part of a vehicle.
 *  This typically describes a coach of a train.
 */
class KPUBLICTRANSPORT_EXPORT VehicleSection
{
    KPUBLICTRANSPORT_GADGET(VehicleSection)

    /** Human readable identifier of this section, typically the coach number.
     *  Can be empty for sections closed to passengers, such as train engines.
     */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)

    // TODO relative position in vehicle
    // TODO relative position in platform
    // TODO type of section
    // TODO features of section, and class information
};

class VehiclePrivate;

/** Information about the vehicle used on a journey.
 *  This is typically only available for trains, and describes their coach layout.
 */
class KPUBLICTRANSPORT_EXPORT Vehicle
{
    KPUBLICTRANSPORT_GADGET(Vehicle)
    /** Journey sections for consumption by QML. */
    Q_PROPERTY(QVariantList sections READ sectionsVariant)

    // TODO vehicle name/number

public:
    /** The vehicle sections. */
    const std::vector<VehicleSection>& sections() const;
    /** Moves the vehicle sections out of this object. */
    std::vector<VehicleSection>&& takeSections();
    /** Sets the vehicle sections. */
    void setSections(std::vector<VehicleSection> &&sections);

private:
    QVariantList sectionsVariant() const;
};

}

#endif // KPUBLICTRANSPORT_VEHICLE_H

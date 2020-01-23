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

#ifndef KPUBLICTRANSPORT_PLATFORM_H
#define KPUBLICTRANSPORT_PLATFORM_H

#include <kpublictransport_export.h>

#include "datatypes.h"

namespace KPublicTransport {

class PlatformSectionPrivate;

/** Information about a part of a platform. */
class KPUBLICTRANSPORT_EXPORT PlatformSection
{
    KPUBLICTRANSPORT_GADGET(PlatformSection)

    /** Human readable identifier of this platform section. */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)

    /*+ Begin of this section in relative platform coordinates. */
    KPUBLICTRANSPORT_PROPERTY(float, begin, setBegin)
    /** End of this section in relative platform coordinates. */
    KPUBLICTRANSPORT_PROPERTY(float, end, setEnd)

    /** Serializes one platform section to JSON. */
    static QJsonObject toJson(const PlatformSection &section);
    /** Serializes a vector of vehicle sections to JSON. */
    static QJsonArray toJson(const std::vector<PlatformSection> &sections);
    /** Deserialize an object from JSON. */
    static PlatformSection fromJson(const QJsonObject &obj);
    /** Deserialize a vector of platform sections from JSON. */
    static std::vector<PlatformSection> fromJson(const QJsonArray &array);
};

class PlatformPrivate;

/** Information about the layout of a station platform. */
class KPUBLICTRANSPORT_EXPORT Platform
{
    KPUBLICTRANSPORT_GADGET(Platform)

    // TODO how does this work with the Czech way of identying tracks/platforms?
    /** Human readable identifier of this platform.
     *  Typically a number.
     */
    KPUBLICTRANSPORT_PROPERTY(QString, name, setName)

    /** Length of the platform, in meter.
     *  Value is negative if the information is not available.
     *  Useful for display scaling from relative platform coordinates.
     */
    KPUBLICTRANSPORT_PROPERTY(int, length, setLength)

    /** Platform sections for consumption by QML. */
    Q_PROPERTY(QVariantList sections READ sectionsVariant)

public:
    /** The platform sections. */
    const std::vector<PlatformSection>& sections() const;
    /** Moves the platform sections out of this object. */
    std::vector<PlatformSection>&& takeSections();
    /** Sets the platform sections. */
    void setSections(std::vector<PlatformSection> &&sections);

    /** Serializes one platform object to JSON. */
    static QJsonObject toJson(const Platform &platform);
    /** Deserialize an object from JSON. */
    static Platform fromJson(const QJsonObject &obj);

private:
    QVariantList sectionsVariant() const;
};

}

Q_DECLARE_METATYPE(KPublicTransport::Platform)

#endif // KPUBLICTRANSPORT_PLATFORM_H

/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_PLATFORM_H
#define KPUBLICTRANSPORT_PLATFORM_H

#include "kpublictransport_export.h"

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

    // TODO how does this work with the Czech way of identifying tracks/platforms?
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
    /** Returns @c true if this object contains no information beyond default values. */
    bool isEmpty() const;

    /** The platform sections. */
    const std::vector<PlatformSection>& sections() const;
    /** Moves the platform sections out of this object. */
    std::vector<PlatformSection>&& takeSections();
    /** Sets the platform sections. */
    void setSections(std::vector<PlatformSection> &&sections);

    /** Merge two platform instances. */
    static Platform merge(const Platform &lhs, const Platform &rhs);

    /** Serializes one platform object to JSON. */
    static QJsonObject toJson(const Platform &platform);
    /** Serializes a vector of platform objects to JSON. */
    static QJsonArray toJson(const std::vector<Platform> &platforms);
    /** Deserialize an object from JSON. */
    static Platform fromJson(const QJsonObject &obj);
    /** Deserialize an array from JSON. */
    static std::vector<Platform> fromJson(const QJsonArray &array);

private:
    QVariantList sectionsVariant() const;
};

}

Q_DECLARE_METATYPE(KPublicTransport::Platform)

#endif // KPUBLICTRANSPORT_PLATFORM_H

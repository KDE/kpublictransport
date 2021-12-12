/*
    SPDX-FileCopyrightText: 2021 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_COVERAGEAREA_H
#define KPUBLICTRANSPORT_COVERAGEAREA_H

#include "datatypes.h"

class QJsonObject;
class QStringList;

namespace KPublicTransport {

class CoverageAreaPrivate;
class Location;

/** Describes the area a specific KPublicTransport::Backend can provide information for. */
class KPUBLICTRANSPORT_EXPORT CoverageArea
{
    KPUBLICTRANSPORT_GADGET(CoverageArea)
public:
    /** Coverage quality as defined by the Transport API Repository format. */
    enum Type {
        Realtime,
        Regular,
        Any
    };
    KPUBLICTRANSPORT_PROPERTY(Type, type, setType)

    /** ISO 3166-1/2 codes of covered regions.
     *  Note that actual coverage might be small (e.g. just a city inside the given region).
     */
    KPUBLICTRANSPORT_PROPERTY(QStringList, regions, setRegions)

    /** UIC company codes of operators covered by this backend. */
    KPUBLICTRANSPORT_PROPERTY(QStringList, uicCompanyCodes, setUicCompanyCodes)
    /** VDV organization ids of operators covered by this backend. */
    KPUBLICTRANSPORT_PROPERTY(QStringList, vdvOrganizationIds, setVdvOrganizationIds)

public:
    /** Checks whether this coverage area is empty.
     *  coversLocation() would always return @p false for empty areas.
     */
    bool isEmpty() const;

    /** Returns @c true if this area covers the entire world. */
    bool isGlobal() const;

    /** Checks whether @p loc is covered by this area. */
    bool coversLocation(const Location &loc) const;

    /** Checks whether this includes the entire country @p country. */
    bool hasNationWideCoverage(const QString &country) const;

    /** Read a single coverage area information from a JSON object
     *  in Transport API Repository format.
     */
    static CoverageArea fromJson(const QJsonObject &obj);
};

}

#endif // KPUBLICTRANSPORT_COVERAGEAREA_H

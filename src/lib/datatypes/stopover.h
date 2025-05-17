/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_STOPOVER_H
#define KPUBLICTRANSPORT_STOPOVER_H

#include "datatypes.h"
#include "disruption.h"
#include "line.h"
#include "load.h"
#include "location.h"
#include "platform.h"
#include "vehicle.h"

class QDateTime;

namespace KPublicTransport {

class StopoverPrivate;

/** Information about an arrival and/or departure of a vehicle at a stop area. */
class KPUBLICTRANSPORT_EXPORT Stopover
{
    KPUBLICTRANSPORT_GADGET(Stopover)

    /** Planned arrival time. */
    KPUBLICTRANSPORT_PROPERTY(QDateTime, scheduledArrivalTime, setScheduledArrivalTime)
    /** Actual arrival time, if available.
     *  Set to invalid to indicate real-time data is not available.
     */
    KPUBLICTRANSPORT_PROPERTY(QDateTime, expectedArrivalTime, setExpectedArrivalTime)
    /** @c true if this has real-time data. */
    Q_PROPERTY(bool hasExpectedArrivalTime READ hasExpectedArrivalTime STORED false)
    /** Difference to schedule in minutes. */
    Q_PROPERTY(int arrivalDelay READ arrivalDelay STORED false)

    /** Planned departure time. */
    KPUBLICTRANSPORT_PROPERTY(QDateTime, scheduledDepartureTime, setScheduledDepartureTime)
    /** Actual departure time, if available.
     *  Set to invalid to indicate real-time data is not available.
     */
    KPUBLICTRANSPORT_PROPERTY(QDateTime, expectedDepartureTime, setExpectedDepartureTime)
    /** @c true if this has real-time data. */
    Q_PROPERTY(bool hasExpectedDepartureTime READ hasExpectedDepartureTime STORED false)
    /** Difference to schedule in minutes. */
    Q_PROPERTY(int departureDelay READ departureDelay STORED false)

    /** Planned departure platform. */
    KPUBLICTRANSPORT_PROPERTY(QString, scheduledPlatform, setScheduledPlatform)
    /** Actual departure platform, in case real-time information are available. */
    KPUBLICTRANSPORT_PROPERTY(QString, expectedPlatform, setExpectedPlatform)
    /** @c true if real-time platform information are available. */
    Q_PROPERTY(bool hasExpectedPlatform READ hasExpectedPlatform STORED false)
    /** @c true if we have real-time platform information and the platform changed. */
    Q_PROPERTY(bool platformChanged READ platformChanged STORED false)

    /** The departing route. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Route, route, setRoute)

    /** The stop point of this departure. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Location, stopPoint, setStopPoint)

    /** Disruption effect on this arrival or departure, if any. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Disruption::Effect, disruptionEffect, setDisruptionEffect)
    /** General human-readable notes on this service, e.g. details about a disruption. */
    KPUBLICTRANSPORT_PROPERTY(QStringList, notes, setNotes)

    /** Vehicle load information for departure from this stopover
     *  Contains LoadInfo objects for consumption by QML.
     */
    Q_PROPERTY(QList<KPublicTransport::LoadInfo> loadInformation READ loadInformationList STORED false)

    /** Vehicle coach layout information at this stopover. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Vehicle, vehicleLayout, setVehicleLayout)
    /** Platform layout information. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Platform, platformLayout, setPlatformLayout)

    /** Features of the vehicle used on this section.
     *  This is identical to departureVehicleLayout.features and provided for convenience
     *  for cases where no more detailed vehicle information are available.
     */
    Q_PROPERTY(std::vector<KPublicTransport::Feature> features READ features)

    /** Maximum occpancy leaving this stop, over all classes. */
    Q_PROPERTY(KPublicTransport::Load::Category maximumOccupancy READ maximumOccupancy STORED false)

public:
    [[nodiscard]] bool hasExpectedArrivalTime() const;
    [[nodiscard]] int arrivalDelay() const;
    [[nodiscard]] bool hasExpectedDepartureTime() const;
    [[nodiscard]] int departureDelay() const;
    [[nodiscard]] bool hasExpectedPlatform() const;
    [[nodiscard]] bool platformChanged() const;

    /** Adds a note. This will check for duplicates and normalize the notes. */
    void addNote(const QString &note);
    void addNotes(const QStringList &notes);

    /** Expected vehicle load for departing from this stopover. */
    [[nodiscard]] const std::vector<LoadInfo>& loadInformation() const;
    /** Moves the load information out of this object for modification. */
    std::vector<LoadInfo>&& takeLoadInformation();
    /** Set the expected vehicle load information for departing from this stopover. */
    void setLoadInformation(std::vector<LoadInfo>&& loadInfo);

    /** Vehicle features.
     *  This is identical to departureVehicleLayout.features and provided for convenience
     *  for cases where no more detailed vehicle information are available.
     */
    [[nodiscard]] const std::vector<KPublicTransport::Feature>& features() const;
    [[nodiscard]] std::vector<KPublicTransport::Feature>&& takeFeatures();
    void setFeatures(std::vector<KPublicTransport::Feature> &&features);

    [[nodiscard]] Load::Category maximumOccupancy() const;

    /** Backend-specific identifiers for the trip this stopover is on. */
    [[nodiscard]] QString tripIdentifier(QAnyStringView identifierType) const;
    [[nodiscard]] bool hasTripIdentifier(QAnyStringView identifierType) const;
    void setTripIdentifier(const QString &identifierType, const QString &id);
    /** Returns @c true if there is any trip identifier set at all.
     *  This is usually a prerequisite for efficient trip queries.
     */
    [[nodiscard]] bool hasTripIdentifiers() const;

    /** Augment line meta data.
     *  @param download when set to @c true trigger download of missing assets.
     */
    void applyMetaData(bool download);

    /** Checks if to instances refer to the same departure (which does not necessarily mean they are exactly equal). */
    static bool isSame(const Stopover &lhs, const Stopover &rhs);

    /** Merge two departure instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    static Stopover merge(const Stopover &lhs, const Stopover &rhs);

    /** Serializes one object to JSON. */
    static QJsonObject toJson(const Stopover &stopover);
    /** Serializes a vector of departure objects to JSON. */
    static QJsonArray toJson(const std::vector<Stopover> &deps);
    /** Deserialize an object from JSON. */
    static Stopover fromJson(const QJsonObject &obj);
    /** Deserialize a list of departures from JSON. */
    static std::vector<Stopover> fromJson(const QJsonArray &array);

private:
    [[nodiscard]] Q_DECL_HIDDEN QList<LoadInfo> loadInformationList() const;
};

}

Q_DECLARE_METATYPE(KPublicTransport::Stopover)

#endif // KPUBLICTRANSPORT_STOPOVER_H

/*
    Copyright (C) 2018 Volker Krause <vkrause@kde.org>

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

#ifndef KPUBLICTRANSPORT_JOURNEY_H
#define KPUBLICTRANSPORT_JOURNEY_H

#include "datatypes.h"
#include "disruption.h"
#include "line.h"
#include "location.h"

#include <QDateTime>

#include <vector>

namespace KPublicTransport {

class JourneySectionPrivate;

/** A segment of a journey plan. */
class KPUBLICTRANSPORT_EXPORT JourneySection
{
    KPUBLICTRANSPORT_GADGET(JourneySection)
    /** Mode of transport for this section. */
    Q_PROPERTY(Mode mode READ mode WRITE setMode)

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

    /** Duration of the section in seconds. */
    Q_PROPERTY(int duration READ duration STORED false)
    /** Distance of the section in meter. */
    KPUBLICTRANSPORT_PROPERTY(int, distance, setDistance)

    /** Departure location of this segment. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Location, from, setFrom)
    /** Arrival location of this segment. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Location, to, setTo)
    /** Route to take on this segment. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Route, route, setRoute)

    /** Planned departure platform. */
    KPUBLICTRANSPORT_PROPERTY(QString, scheduledDeparturePlatform, setScheduledDeparturePlatform)
    /** Actual departure platform, in case real-time information are available. */
    KPUBLICTRANSPORT_PROPERTY(QString, expectedDeparturePlatform, setExpectedDeparturePlatform)
    /** @c true if real-time platform information are available. */
    Q_PROPERTY(bool hasExpectedDeparturePlatform READ hasExpectedDeparturePlatform STORED false)
    /** @c true if we have real-time platform information and the platform changed. */
    Q_PROPERTY(bool departurePlatformChanged READ departurePlatformChanged STORED false)

    /** Planned arrival platform. */
    KPUBLICTRANSPORT_PROPERTY(QString, scheduledArrivalPlatform, setScheduledArrivalPlatform)
    /** Actual arrival platform, in case real-time information are available. */
    KPUBLICTRANSPORT_PROPERTY(QString, expectedArrivalPlatform, setExpectedArrivalPlatform)
    /** @c true if real-time platform information are available. */
    Q_PROPERTY(bool hasExpectedArrivalPlatform READ hasExpectedArrivalPlatform STORED false)
    /** @c true if we have real-time platform information and the platform changed. */
    Q_PROPERTY(bool arrivalPlatformChanged READ arrivalPlatformChanged STORED false)

    /** Disruption effect on this section, if any. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Disruption::Effect, disruptionEffect, setDisruptionEffect)
    /** General human-readable notes on this service, e.g. details about a disruption. */
    KPUBLICTRANSPORT_PROPERTY(QStringList, notes, setNotes)

public:
    /** Mode of transport. */
    enum Mode {
        Invalid,
        PublicTransport,
        Transfer,
        Walking,
        Waiting
    };
    Q_ENUM(Mode)
    Mode mode() const;
    void setMode(Mode mode);

    bool hasExpectedDepartureTime() const;
    int departureDelay() const;
    bool hasExpectedArrivalTime() const;
    int arrivalDelay() const;

    int duration() const;

    bool hasExpectedDeparturePlatform() const;
    bool departurePlatformChanged() const;
    bool hasExpectedArrivalPlatform() const;
    bool arrivalPlatformChanged() const;

    /** Adds a note. This will check for duplicates and normalize the notes. */
    void addNote(const QString &note);
    void addNotes(const QStringList &notes);

    /** Checks if two instances refer to the same journey section (which does not necessarily mean they are exactly equal). */
    static bool isSame(const JourneySection &lhs, const JourneySection &rhs);

    /** Merge two instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    static JourneySection merge(const JourneySection &lhs, const JourneySection &rhs);

    /** Serializes one journey section to JSON. */
    static QJsonObject toJson(const JourneySection &section);
    /** Serializes a vector of journey sections to JSON. */
    static QJsonArray toJson(const std::vector<JourneySection> &sections);
    /** Deserialize an object from JSON. */
    static JourneySection fromJson(const QJsonObject &obj);
    /** Deserialize a vector of journey sections from JSON. */
    static std::vector<JourneySection> fromJson(const QJsonArray &array);
};

class JourneyPrivate;

/** A journey plan. */
class KPUBLICTRANSPORT_EXPORT Journey
{
    KPUBLICTRANSPORT_GADGET(Journey)
    /** Journey sections for consumption by QML. */
    Q_PROPERTY(QVariantList sections READ sectionsVariant)
    /** Departure time of the journey, according to schedule. */
    Q_PROPERTY(QDateTime scheduledDepartureTime READ scheduledDepartureTime STORED false)
    /** @c true if this has real-time data. */
    Q_PROPERTY(bool hasExpectedDepartureTime READ hasExpectedDepartureTime STORED false)
    /** Difference to schedule in minutes. */
    Q_PROPERTY(int departureDelay READ departureDelay STORED false)

    /** Arrival time of the journey, according to schedule. */
    Q_PROPERTY(QDateTime scheduledArrivalTime READ scheduledArrivalTime STORED false)
    /** @c true if this has real-time data. */
    Q_PROPERTY(bool hasExpectedArrivalTime READ hasExpectedArrivalTime STORED false)
    /** Difference to schedule in minutes. */
    Q_PROPERTY(int arrivalDelay READ arrivalDelay STORED false)

    /** Duration of the entire journey in seconds. */
    Q_PROPERTY(int duration READ duration STORED false)
    /** Number of changes on this journey. */
    Q_PROPERTY(int numberOfChanges READ numberOfChanges STORED false)
    /** Worst disruption effect of any of the journey sections. */
    Q_PROPERTY(KPublicTransport::Disruption::Effect disruptionEffect READ disruptionEffect STORED false)

public:
    /** The journey sections. */
    const std::vector<JourneySection>& sections() const;
    /** Moves the journey sections out of this object. */
    std::vector<JourneySection>&& takeSections();
    /** Sets the journey sections. */
    void setSections(std::vector<JourneySection> &&sections);

    QDateTime scheduledDepartureTime() const;
    bool hasExpectedDepartureTime() const;
    int departureDelay() const;

    QDateTime scheduledArrivalTime() const;
    bool hasExpectedArrivalTime() const;
    int arrivalDelay() const;

    int duration() const;
    int numberOfChanges() const;
    Disruption::Effect disruptionEffect() const;

    /** Checks if two instances refer to the same journey (which does not necessarily mean they are exactly equal). */
    static bool isSame(const Journey &lhs, const Journey &rhs);

    /** Merge two instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    static Journey merge(const Journey &lhs, const Journey &rhs);

    /** Serializes one journey object to JSON. */
    static QJsonObject toJson(const Journey &journey);
    /** Serializes a vector of journey objects to JSON. */
    static QJsonArray toJson(const std::vector<Journey> &journeys);
    /** Deserialize an object from JSON. */
    static Journey fromJson(const QJsonObject &obj);

private:
    QVariantList sectionsVariant() const;
};

}

Q_DECLARE_METATYPE(KPublicTransport::JourneySection)
Q_DECLARE_METATYPE(KPublicTransport::Journey)

#endif // KPUBLICTRANSPORT_JOURNEY_H

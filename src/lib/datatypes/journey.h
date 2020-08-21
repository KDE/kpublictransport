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
#include "load.h"
#include "location.h"

#include <QDateTime>

#include <vector>

namespace KPublicTransport {

class JourneySectionPrivate;
class RentalVehicle;
class Stopover;

/** A segment of a journey plan. */
class KPUBLICTRANSPORT_EXPORT JourneySection
{
    KPUBLICTRANSPORT_GADGET(JourneySection)

public:
    /** Mode of transport.
     *  These categories are fairly coarse, for a more detailed break-down of PublicTransport see Line::Mode.
     */
    enum Mode {
        Invalid = 0,
        PublicTransport = 1,
        Transfer = 2,
        Walking = 4,
        Waiting = 8,
        RentedVehicle = 16, ///< free floating or dock-based rental bike service, electric scooters, car sharing services, ie. any vehicle you drive yourself but that isn't your own
    };
    Q_ENUM(Mode)
    Q_DECLARE_FLAGS(Modes, Mode)
    Q_FLAG(Modes)

    /** Mode of transport for this section. */
    KPUBLICTRANSPORT_PROPERTY(Mode, mode, setMode)

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

    /** Intermediate stops for consumption by QML. */
    Q_PROPERTY(QVariantList intermediateStops READ intermediateStopsVariant)

    /** All departure information represented as Stopover object. */
    Q_PROPERTY(KPublicTransport::Stopover departure READ departure STORED false)
    /** All arrival information represented as Stopover object. */
    Q_PROPERTY(KPublicTransport::Stopover arrival READ arrival STORED false)

    /** CO₂ emission during this journey section, in gram.
     *  In case the backend doesn't provide this value, it is estimated based on the
     *  distance travelled during this section and the mode of transport, based on
     *  average emission values from https://en.wikipedia.org/wiki/Environmental_impact_of_transport
     *  This value can be 0 (e.g. in case of walk or wait sections), or -1 if no
     *  information is available.
     */
    KPUBLICTRANSPORT_PROPERTY(int, co2Emission, setCo2Emission)

    /** Vehicle load information for this journey section.
     *  Contains LoadInfo objects for consumption by QML.
     */
    Q_PROPERTY(QVariantList loadInformation READ loadInformationVariant STORED false)

    /** Information about a rental vehicle, for sections using one. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::RentalVehicle, rentalVehicle, setRentalVehicle)

public:
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

    /** Intermediate stop-overs along this journey section.
     *  This does not include the departure and arrival stops, and might be empty on backends not providing this information.
     */
    const std::vector<Stopover>& intermediateStops() const;
    /** Moves the intermediate stops out of this object. */
    std::vector<Stopover>&& takeIntermediateStops();
    /** Set the intermediate stops. */
    void setIntermediateStops(std::vector<Stopover> &&stops);

    /** Returns the departure stopover of this journey section.
     *  This is the same information as accessible by individual properties,
     *  so this is mainly useful if you have to interface with code expecting a Stopover object.
     */
    Stopover departure() const;
    /** Returns the arrival stopover of this journey section.
     *  This is the same information as accessible by individual properties,
     *  so this is mainly useful if you have to interface with code expecting a Stopover object.
     */
    Stopover arrival() const;

    /** Vehicle load information for this journey section, if available. */
    const std::vector<LoadInfo>& loadInformation() const;
    /** Moves the load information out of this object for modification. */
    std::vector<LoadInfo>&& takeLoadInformation();
    /** Set the vehicle load information for this journey section. */
    void setLoadInformation(std::vector<LoadInfo>&& loadInfo);

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

private:
    QVariantList intermediateStopsVariant() const;
    QVariantList loadInformationVariant() const;
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
    /** Deserialize a list of journey from JSON. */
    static std::vector<Journey> fromJson(const QJsonArray &array);

private:
    QVariantList sectionsVariant() const;
};

}

Q_DECLARE_OPERATORS_FOR_FLAGS(KPublicTransport::JourneySection::Modes)
Q_DECLARE_METATYPE(KPublicTransport::JourneySection)
Q_DECLARE_METATYPE(KPublicTransport::Journey)

#endif // KPUBLICTRANSPORT_JOURNEY_H

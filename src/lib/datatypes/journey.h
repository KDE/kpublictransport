/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPUBLICTRANSPORT_JOURNEY_H
#define KPUBLICTRANSPORT_JOURNEY_H

#include "datatypes.h"
#include "disruption.h"
#include "individualtransport.h"
#include "line.h"
#include "load.h"
#include "location.h"
#include "path.h"
#include "platform.h"
#include "vehicle.h"

#include <QDateTime>

#include <vector>

namespace KPublicTransport {

class JourneySectionPrivate;
class RentalVehicle;
class Stopover;

/** A segment of a journey plan.
 *
 *  Also used for trips, ie. a single full vehicle run along a route.
 *
 *  This consists of a departure and an arrival stopover as well as zero or more intermediate stopovers.
 *  For extracting sub-journeys those can be addresses by a numeric index. Index 0 refers to the departure,
 *  1 to N refer to the n-th intermediate stopover and N + 1 refers to the arrival, for N intermediate stops.
 */
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
        IndividualTransport = 32, ///< using your own vehicle (bike, car, etc).
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

    /** The departure stopover of this journey section.
     *  Several properties of this are forwarded as properties on the journey section object
     *  for convenience.
     */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Stopover, departure, setDeparture)
    /** The arrival stopover of this jouney section.
     *  Several properties of this are forwarded as properties on the journey section object
     *  for convenience.
     */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Stopover, arrival, setArrival)

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
    Q_PROPERTY(QList<KPublicTransport::LoadInfo> loadInformation READ loadInformationList WRITE setLoadInformationList STORED false)

    /** Information about a rental vehicle, for sections using one. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::RentalVehicle, rentalVehicle, setRentalVehicle)

    /** Movement path for this journey section.
     *  This can be navigation instructions for individual transport modes and transfers,
     *  or the path a public transport vehicle takes.
     */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Path, path, setPath)

    /** Vehicle coach layout information at departure. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Vehicle, departureVehicleLayout, setDepartureVehicleLayout)
    /** Platform layout information at departure. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Platform, departurePlatformLayout, setDeparturePlatformLayout)
    /** Vehicle coach layout information at arrival.
     *  Note that this does not necessarily need to be the same as departureVehicleLayout, as e.g. trains
     *  can be split up or merged along the way.
     */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Vehicle, arrivalVehicleLayout, setArrivalVehicleLayout)
    /** Platform layout information at arrival. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::Platform, arrivalPlatformLayout, setArrivalPlatformLayout)

    /** Individual transport details for sections using your own vehicle. */
    KPUBLICTRANSPORT_PROPERTY(KPublicTransport::IndividualTransport, individualTransport, setIndividualTransport)

    /** Features of the vehicle used on this section.
     *  This is identical to departureVehicleLayout.features and provided for convenience
     *  for cases where no more detailed vehicle information are available.
     */
    Q_PROPERTY(std::vector<KPublicTransport::Feature> features READ features)

    /** The best available icon to represent this journey section.
     *  Can be a qrc: or file: URL or an XDG icon name.
     */
    Q_PROPERTY(QString iconName READ iconName STORED false)

    /** Label shortly describing this transport for display. */
    Q_PROPERTY(QString label READ label STORED false)

    /** Maximum occpancy over all classes. */
    Q_PROPERTY(KPublicTransport::Load::Category maximumOccupancy READ maximumOccupancy STORED false)

public:
    [[nodiscard]] bool hasExpectedDepartureTime() const;
    [[nodiscard]] int departureDelay() const;
    [[nodiscard]] bool hasExpectedArrivalTime() const;
    [[nodiscard]] int arrivalDelay() const;

    [[nodiscard]] int duration() const;

    [[nodiscard]] bool hasExpectedDeparturePlatform() const;
    [[nodiscard]] bool departurePlatformChanged() const;
    [[nodiscard]] bool hasExpectedArrivalPlatform() const;
    [[nodiscard]] bool arrivalPlatformChanged() const;

    /** Adds a note. This will check for duplicates and normalize the notes. */
    void addNote(const QString &note);
    void addNotes(const QStringList &notes);

    /** Intermediate stop-overs along this journey section.
     *  This does not include the departure and arrival stops, and might be empty on backends not providing this information.
     */
    [[nodiscard]] const std::vector<Stopover>& intermediateStops() const;
    /** Moves the intermediate stops out of this object. */
    std::vector<Stopover>&& takeIntermediateStops();
    /** Set the intermediate stops. */
    void setIntermediateStops(std::vector<Stopover> &&stops);

    /** Vehicle load information for this journey section, if available. */
    [[nodiscard]] const std::vector<LoadInfo>& loadInformation() const;
    /** Set the vehicle load information for this journey section. */
    void setLoadInformation(std::vector<LoadInfo>&& loadInfo);

    /** Augment line meta data.
     *  @param download if set to @p true, trigger the download of locally missing assets.
     */
    void applyMetaData(bool download);

    /** Checks if two instances refer to the same journey section (which does not necessarily mean they are exactly equal). */
    [[nodiscard]] static bool isSame(const JourneySection &lhs, const JourneySection &rhs);

    /** Merge two instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    [[nodiscard]] static JourneySection merge(const JourneySection &lhs, const JourneySection &rhs);

    /** Serializes one journey section to JSON. */
    [[nodiscard]] static QJsonObject toJson(const JourneySection &section);
    /** Serializes a vector of journey sections to JSON. */
    [[nodiscard]] static QJsonArray toJson(const std::vector<JourneySection> &sections);
    /** Deserialize an object from JSON. */
    [[nodiscard]] static JourneySection fromJson(const QJsonObject &obj);
    /** Deserialize a vector of journey sections from JSON. */
    [[nodiscard]] static std::vector<JourneySection> fromJson(const QJsonArray &array);

    /** Vehicle features.
     *  This is identical to departureVehicleLayout.features and provided for convenience
     *  for cases where no more detailed vehicle information are available.
     */
    [[nodiscard]] const std::vector<KPublicTransport::Feature>& features() const;
    [[nodiscard]] std::vector<KPublicTransport::Feature>&& takeFeatures();
    void setFeatures(std::vector<KPublicTransport::Feature> &&features);

    [[nodiscard]] QString iconName() const;

    /** Icon representing the journey section mode @p mode.
     *  Can be a qrc: or file: URL or an XDG icon name.
     */
    Q_INVOKABLE [[nodiscard]] static QString modeIconName(KPublicTransport::JourneySection::Mode mode);

    [[nodiscard]] QString label() const;
    [[nodiscard]] Load::Category maximumOccupancy() const;

    /** Backend-specific journey section identifiers. */
    [[nodiscard]] QString identifier(QAnyStringView identifierType) const;
    [[nodiscard]] bool hasIdentifier(QAnyStringView identifierType) const;
    void setIdentifier(const QString &identifierType, const QString &id);
    /** Returns @c true if there is any identifier set at all.
     *  This is usually a prerequisite for efficient trip queries.
     */
    [[nodiscard]] bool hasIdentifiers() const;

    /** Retrieve stopover at index @p idx. */
    [[nodiscard]] Stopover stopover(qsizetype idx) const;
    /** Set the stopover at index @p idx.
     *  If @p idx is not a valid index nothing is done.
     */
    void setStopovver(qsizetype idx, const Stopover &stop);

    /** Returns the index of @p stop in this journey section.
     *  @returns -1 if @p stop isn't found.
     */
    [[nodiscard]] qsizetype indexOfStopover(const Stopover &stop) const;

    /** Returns the sub-journey starting from index @p begin until
     *  @p end (inclusive).
     *
     *  Both @p begin and @p end have to be valid indices and @p end has to
     *  be strictly larger than @p begin, otherwise an invalid journey section
     *  is returned.
     */
    [[nodiscard]] JourneySection subsection(qsizetype begin, qsizetype end) const;

private:
    [[nodiscard]] Q_DECL_HIDDEN QVariantList intermediateStopsVariant() const;
    [[nodiscard]] Q_DECL_HIDDEN QList<LoadInfo> loadInformationList() const;
    Q_DECL_HIDDEN void setLoadInformationList(const QList<LoadInfo> &loadInfo);
};

Q_DECLARE_OPERATORS_FOR_FLAGS(JourneySection::Modes)

class JourneyPrivate;

/** A journey plan. */
class KPUBLICTRANSPORT_EXPORT Journey
{
    KPUBLICTRANSPORT_GADGET(Journey)
    /** Journey sections for consumption by QML. */
    Q_PROPERTY(QList<KPublicTransport::JourneySection> sections READ sectionsList WRITE setSectionsList)
    /** Departure time of the journey, according to schedule. */
    Q_PROPERTY(QDateTime scheduledDepartureTime READ scheduledDepartureTime STORED false)
    /** @c true if this has real-time data. */
    Q_PROPERTY(bool hasExpectedDepartureTime READ hasExpectedDepartureTime STORED false)
    /** Actual departure time, if available.
     *  Set to invalid to indicate real-time data is not available.
     */
    Q_PROPERTY(QDateTime expectedDepartureTime READ expectedDepartureTime STORED false)
    /** Difference to schedule in minutes. */
    Q_PROPERTY(int departureDelay READ departureDelay STORED false)

    /** Arrival time of the journey, according to schedule. */
    Q_PROPERTY(QDateTime scheduledArrivalTime READ scheduledArrivalTime STORED false)
    /** @c true if this has real-time data. */
    Q_PROPERTY(bool hasExpectedArrivalTime READ hasExpectedArrivalTime STORED false)
    /** Actual arrival time, if available.
     *  Set to invalid to indicate real-time data is not available.
     */
    Q_PROPERTY(QDateTime expectedArrivalTime READ expectedArrivalTime STORED false)
    /** Difference to schedule in minutes. */
    Q_PROPERTY(int arrivalDelay READ arrivalDelay STORED false)

    /** Duration of the entire journey in seconds. */
    Q_PROPERTY(int duration READ duration STORED false)
    /** Number of changes on this journey. */
    Q_PROPERTY(int numberOfChanges READ numberOfChanges STORED false)
    /** Worst disruption effect of any of the journey sections. */
    Q_PROPERTY(KPublicTransport::Disruption::Effect disruptionEffect READ disruptionEffect STORED false)

    /** Total travelled distance of the entire journey in meter.
     *  That is, the sum of the distances of all sections.
     */
    Q_PROPERTY(int distance READ distance STORED false)
    /** Total CO2 emissions for the entire journey in gram.
     *  That is, the sum of the emissions of all sections.
     */
    Q_PROPERTY(int co2Emission READ co2Emission STORED false)

    /** Maximum occpancy in all journey sections, over all classes. */
    Q_PROPERTY(KPublicTransport::Load::Category maximumOccupancy READ maximumOccupancy STORED false)

public:
    /** The journey sections. */
    [[nodiscard]] const std::vector<JourneySection>& sections() const;
    /** Moves the journey sections out of this object. */
    [[nodiscard]] std::vector<JourneySection>&& takeSections();
    /** Sets the journey sections. */
    void setSections(std::vector<JourneySection> &&sections);

    [[nodiscard]] QDateTime scheduledDepartureTime() const;
    [[nodiscard]] bool hasExpectedDepartureTime() const;
    [[nodiscard]] QDateTime expectedDepartureTime() const;
    [[nodiscard]] int departureDelay() const;

    [[nodiscard]] QDateTime scheduledArrivalTime() const;
    [[nodiscard]] bool hasExpectedArrivalTime() const;
    [[nodiscard]] QDateTime expectedArrivalTime() const;
    [[nodiscard]] int arrivalDelay() const;

    [[nodiscard]] int duration() const;
    [[nodiscard]] int numberOfChanges() const;
    [[nodiscard]] Disruption::Effect disruptionEffect() const;

    [[nodiscard]] int distance() const;
    [[nodiscard]] int co2Emission() const;
    [[nodiscard]] Load::Category maximumOccupancy() const;

    /** Augment line meta data.
     *  @param download if set to @p true, trigger the download of locally missing assets.
     */
    void applyMetaData(bool download);

    /** Checks if two instances refer to the same journey (which does not necessarily mean they are exactly equal). */
    [[nodiscard]] static bool isSame(const Journey &lhs, const Journey &rhs);

    /** Merge two instances.
     *  This assumes isSame(lhs, rhs) and tries to preserve the most detailed information.
     */
    [[nodiscard]] static Journey merge(const Journey &lhs, const Journey &rhs);

    /** Serializes one journey object to JSON. */
    [[nodiscard]] static QJsonObject toJson(const Journey &journey);
    /** Serializes a vector of journey objects to JSON. */
    [[nodiscard]] static QJsonArray toJson(const std::vector<Journey> &journeys);
    /** Deserialize an object from JSON. */
    [[nodiscard]] static Journey fromJson(const QJsonObject &obj);
    /** Deserialize a list of journey from JSON. */
    [[nodiscard]] static std::vector<Journey> fromJson(const QJsonArray &array);

private:
    [[nodiscard]] Q_DECL_HIDDEN QList<JourneySection> sectionsList() const;
    Q_DECL_HIDDEN void setSectionsList(const QList<JourneySection> &sections);
};

}

Q_DECLARE_METATYPE(KPublicTransport::JourneySection)
Q_DECLARE_METATYPE(KPublicTransport::Journey)

#endif // KPUBLICTRANSPORT_JOURNEY_H

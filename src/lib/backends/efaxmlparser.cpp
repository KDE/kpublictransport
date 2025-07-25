/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "efaxmlparser.h"
#include "efamodeoftransport.h"
#include "logging.h"
#include "scopedxmlstreamreader.h"
#include "ifopt/ifoptutil.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QDateTime>
#include <QDebug>
#include <QXmlStreamReader>

using namespace Qt::Literals::StringLiterals;
using namespace KPublicTransport;

constexpr inline const auto WGS84 = "WGS84[DD.ddddd]"_L1;

void EfaXmlParser::parseLocationCommon(Location &loc, const ScopedXmlStreamReader &reader) const
{
    if (const auto coordSys = reader.attributes().value("mapName"); coordSys.empty() || coordSys == WGS84) {
        if (reader.attributes().hasAttribute("x"_L1) && reader.attributes().hasAttribute("y"_L1)) {
            loc.setLatitude(reader.attributes().value("y"_L1).toDouble());
            loc.setLongitude(reader.attributes().value("x"_L1).toDouble());
        }
    } else {
        qCWarning(Log) << "Coordinate system not supported!" <<coordSys;
    }

    // can be already set on loc, so don't reset it if missing here
    const auto locality = reader.attributes().value(QLatin1String("place")).toString();
    if (!locality.isEmpty()) {
        loc.setLocality(locality);
    }

    const auto id = reader.attributes().value(QLatin1String("stopID")).toString();
    if (!id.isEmpty()) {
        if (!isDummyStopId(id)) {
            loc.setIdentifier(m_locationIdentifierType, id);
        }
    } else {
        loc.setIdentifier(m_locationIdentifierType, reader.attributes().value(QLatin1String("stateless")).toString());
    }

    // check if IFOPT identifiers are present, in decreasing level of detail
    for (const auto &attr : {QLatin1String("pointGid"), QLatin1String("areaGid"), QLatin1String("gid")}) {
        const auto id = reader.attributes().value(attr);
        if (IfoptUtil::isValid(id)) {
            loc.setIdentifier(IfoptUtil::identifierType(), id.toString());
            break;
        }
    }

    const auto type = reader.attributes().value(QLatin1String("anyType"));
    if (type == QLatin1String("stop")) {
        loc.setType(Location::Stop);
    } else if (!type.isEmpty()) {
        qCDebug(Log) << "Unhandled EFA location type:" << type;
    } else if (!id.isEmpty() && !isDummyStopId(id)) {
        loc.setType(Location::Stop);
    }
}

Location EfaXmlParser::parseItdOdvAssignedStop(const ScopedXmlStreamReader &reader) const
{
    Location loc;
    parseLocationCommon(loc, reader);
    loc.setName(reader.attributes().value(QLatin1String("nameWithPlace")).toString());
    loc.setType(Location::Stop);
    return loc;
}

Location EfaXmlParser::parseOdvNameElem(ScopedXmlStreamReader &reader) const
{
    Location loc;
    parseLocationCommon(loc, reader);
    loc.setName(reader.readElementText(QXmlStreamReader::SkipChildElements));
    return loc;
}

std::vector<Location> EfaXmlParser::parseStopFinderResponse(const QByteArray &data)
{
    std::vector<Location> res;
    QXmlStreamReader xsr(data);
    ScopedXmlStreamReader reader(xsr);
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("itdOdvAssignedStop") && reader.attributes().hasAttribute(QLatin1String("stopID"))) {
            res.push_back(parseItdOdvAssignedStop(reader));
        } else if (reader.name() == QLatin1String("odvNameElem")) {
            if (reader.attributes().hasAttribute(QLatin1String("stopID"))) {
                res.push_back(parseOdvNameElem(reader));
            } else if (reader.attributes().value(QLatin1String("anyType")) == QLatin1String("stop")
                && reader.attributes().hasAttribute(QLatin1String("stateless")))
            {
                res.push_back(parseOdvNameElem(reader));
            }
        }
    }
    return res;
}

static QDateTime parseDateTime(ScopedXmlStreamReader &&reader)
{
    QDateTime dt;
    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdDate")) {
            QDate d(
                reader.attributes().value(QLatin1String("year")).toInt(),
                reader.attributes().value(QLatin1String("month")).toInt(),
                reader.attributes().value(QLatin1String("day")).toInt());
            dt.setDate(d);
        } else if (reader.name() == QLatin1String("itdTime")) {
            QTime t(
                reader.attributes().value(QLatin1String("hour")).toInt(),
                reader.attributes().value(QLatin1String("minute")).toInt(), 0);
            dt.setTime(t);
        }
    }

    return dt;
}

[[nodiscard]] static QString parseItdOperator(ScopedXmlStreamReader &&reader)
{
    QString opName;
    while (reader.readNextElement()) {
        if (opName.isEmpty() && reader.name() == "name"_L1) {
            opName = reader.readElementText();
        }
    }
    return opName;
}

struct {
    const char *name;
    Load::Category category;
} static constexpr const occupancy_load_map[] = {
    { "MANY_SEATS", Load::Low },
    { "FEW_SEATS", Load::Medium },
    { "STANDING_ONLY", Load::High },
};

Stopover EfaXmlParser::parseDmDeparture(ScopedXmlStreamReader &&reader) const
{
    Stopover dep;
    dep.setScheduledPlatform(reader.attributes().value(QLatin1String("platformName")).toString());

    Location stop;
    const auto stopId = reader.attributes().value(QLatin1String("stopID")).toString();
    const auto stopIt = m_locations.find(stopId);
    if (stopIt != m_locations.end()) {
        stop = stopIt.value();
    }

    parseLocationCommon(stop, reader);
    stop.setName(reader.attributes().value(QLatin1String("stopName")).toString());
    stop.setType(Location::Stop);
    dep.setStopPoint(stop);

    const auto occupancy = reader.attributes().value(QLatin1String("occupancy"));
    if (!occupancy.isEmpty()) {
        LoadInfo load;
        for (const auto &map : occupancy_load_map) {
            if (occupancy == QLatin1String(map.name)) {
                load.setLoad(map.category);
                break;
            }
        }
        dep.setLoadInformation({load});
    }

    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdServingLine")) {
            Line line;
            line.setName(reader.attributes().value(QLatin1String("number")).toString());
            line.setMode(EfaModeOfTransport::motTypeToLineMode(reader.attributes().value(QLatin1String("motType")).toInt()));
            Route route;
            route.setDirection(reader.attributes().value(QLatin1String("direction")).toString());
            line.setOperatorName(parseItdOperator(reader.subReader()));
            route.setLine(line);
            dep.setRoute(route);
        } else if (reader.name() == QLatin1String("itdDateTime")) {
            dep.setScheduledDepartureTime(parseDateTime(reader.subReader()));
        } else if (reader.name() == QLatin1String("itdInfoLinkList")) {
            dep.addNotes(parseInfoLink(reader.subReader()));
        }
    }

    return dep;
}

std::vector<Stopover> EfaXmlParser::parseDmResponse(const QByteArray &data)
{
    std::vector<Stopover> res;
    QXmlStreamReader xsr(data);
    ScopedXmlStreamReader reader(xsr);
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("itdRequest")) {
            m_requestContext.sessionId = reader.attributes().value(QLatin1String("sessionID")).toString();
        } else if (reader.name() == QLatin1String("itdDepartureMonitorRequest")) {
            m_requestContext.requestId = reader.attributes().value(QLatin1String("requestID")).toString();
        } else if (reader.name() == QLatin1String("itdOdvAssignedStop") && reader.attributes().hasAttribute(QLatin1String("stopID"))) {
            const auto loc = parseItdOdvAssignedStop(reader);
            m_locations[loc.identifier(m_locationIdentifierType)] = loc;
        } else if (reader.name() == QLatin1String("itdDeparture")) {
            res.push_back(parseDmDeparture(reader.subReader()));
        }
    }

    return res;
}

void EfaXmlParser::parseTripDeparture(ScopedXmlStreamReader &&reader, JourneySection &section) const
{
    Location loc;
    parseLocationCommon(loc, reader);
    loc.setName(reader.attributes().value(QLatin1String("name")).toString());

    section.setFrom(loc);
    // ### are those the correct ones? there's also just "platform"
    section.setScheduledDeparturePlatform(reader.attributes().value(QLatin1String("plannedPlatformName")).toString());
    section.setExpectedDeparturePlatform(reader.attributes().value(QLatin1String("platformName")).toString());

    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdDateTime")) {
            section.setExpectedDepartureTime(parseDateTime(reader.subReader()));
        } else if (reader.name() == QLatin1String("itdDateTimeTarget")) {
            section.setScheduledDepartureTime(parseDateTime(reader.subReader()));
        }
    }
}

void EfaXmlParser::parseTripArrival(ScopedXmlStreamReader &&reader, JourneySection &section) const
{
    Location loc;
    parseLocationCommon(loc, reader);
    loc.setName(reader.attributes().value(QLatin1String("name")).toString());

    section.setTo(loc);
    // ### are those the correct ones? there's also just "platform"
    section.setScheduledArrivalPlatform(reader.attributes().value(QLatin1String("plannedPlatformName")).toString());
    section.setExpectedArrivalPlatform(reader.attributes().value(QLatin1String("platformName")).toString());

    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdDateTime")) {
            section.setExpectedArrivalTime(parseDateTime(reader.subReader()));
        } else if (reader.name() == QLatin1String("itdDateTimeTarget")) {
            section.setScheduledArrivalTime(parseDateTime(reader.subReader()));
        }
    }
}

Stopover EfaXmlParser::parsePartialTripIntermediateStop(ScopedXmlStreamReader &&reader) const
{
    Location loc;
    parseLocationCommon(loc, reader);
    loc.setName(reader.attributes().value(QLatin1String("name")).toString());

    Stopover stop;
    stop.setStopPoint(loc);
    stop.setScheduledPlatform(reader.attributes().value(QLatin1String("platform")).toString());

    bool result = false;
    std::optional<int64_t> arrDelay, depDelay;
    if (reader.attributes().value("depValid") == "1"_L1) {
        depDelay = reader.attributes().value("depDelay"_L1).toInt(&result);
        if (!result) {
            depDelay = {};
        }
    }
    if (reader.attributes().value("arrValid") == "1"_L1) {
        arrDelay = reader.attributes().value("depDelay"_L1).toInt(&result);
        if (!result) {
            arrDelay = {};
        }
    }

    bool seenItdDateTime = false;
    while (reader.readNextSibling()) {
        if (reader.name() == "itdDateTime"_L1) {
            const auto dt = parseDateTime(reader.subReader());
            if (dt.isValid()) {
                if (!seenItdDateTime) {
                    stop.setScheduledArrivalTime(dt);
                    if (arrDelay) {
                        stop.setExpectedArrivalTime(dt.addSecs(60 * (*arrDelay)));
                    }
                } else {
                    stop.setScheduledDepartureTime(dt);
                    if (depDelay) {
                        stop.setExpectedArrivalTime(dt.addSecs(60 * (*depDelay)));
                    }
                }
            }
            seenItdDateTime = true;
        }
    }

    // sometimes we only get invalid itdDateTime elements, e.g. in the UK. Semantics of that
    // is unclear, their own website doesn't show those stops at all
    if (!stop.scheduledArrivalTime().isValid() && !stop.scheduledDepartureTime().isValid()) {
        stop.setDisruptionEffect(Disruption::NoService);
    }

    return stop;
}

std::vector<Stopover> EfaXmlParser::parsePartialTripStopSequence(ScopedXmlStreamReader &&reader) const
{
    std::vector<Stopover> stops;
    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdPoint")) {
            stops.push_back(parsePartialTripIntermediateStop(reader.subReader()));
        }
    }

    if (stops.size() >= 2) { // includes departure/arrival stops too
        stops.erase(std::prev(stops.end()));
        stops.erase(stops.begin());
    }

    return stops;
}

struct {
    int type;
    JourneySection::Mode mode;
} static const journey_section_types[] = {
    { 97, JourneySection::Waiting }, // technically: "do not change"?
    { 98, JourneySection::Transfer },
    { 99, JourneySection::Walking },
    { 100, JourneySection::Walking },
};

std::vector<JourneySection> EfaXmlParser::parseTripPartialRoute(ScopedXmlStreamReader &&reader) const
{
    std::vector<JourneySection> result;
    JourneySection section;
    if (reader.attributes().value(QLatin1String("type")) == QLatin1String("IT")) {
        section.setMode(JourneySection::Walking);
    }

    QPolygonF sectionPoly, transferPoly;
    std::vector<PathDescription> pathDesc;
    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdPoint")) {
            const auto type = reader.attributes().value(QLatin1String("usage"));
            if (type == QLatin1String("departure")) {
                parseTripDeparture(reader.subReader(), section);
            } else if (type == QLatin1String("arrival")) {
                parseTripArrival(reader.subReader(), section);
            }
        } else if (reader.name() == QLatin1String("itdMeansOfTransport")) {
            const auto type = reader.attributes().value(QLatin1String("type")).toInt();
            for (const auto &m : journey_section_types) {
                if (m.type == type) {
                    section.setMode(m.mode);
                    break;
                }
            }

            if (type < 90) {
                Line line;
                line.setName(reader.attributes().value(QLatin1String("shortname")).toString());
                const auto prodName = reader.attributes().value(QLatin1String("productName"));
                if (prodName == QLatin1String("Fussweg")) {
                    section.setMode(JourneySection::Walking);
                } else {
                    line.setModeString(prodName.toString());
                }
                line.setMode(EfaModeOfTransport::motTypeToLineMode(reader.attributes().value(QLatin1String("motType")).toInt()));
                Route route;
                route.setDirection(reader.attributes().value(QLatin1String("destination")).toString());
                line.setOperatorName(parseItdOperator(reader.subReader()));
                route.setLine(line);
                section.setRoute(route);
                section.setMode(JourneySection::PublicTransport);
            } else if (type > 100) {
                const auto itMode = motTypeToIndividualTransportMode(type);
                section.setIndividualTransport(itMode);
                section.setMode(JourneySection::IndividualTransport);
            }
        } else if (reader.name() == QLatin1String("infoLink")) {
            section.addNotes(parseInfoLink(reader.subReader()));
        } else if (reader.name() == QLatin1String("itdInfoTextList")) {
            auto subReader = reader.subReader();
            while (subReader.readNextSibling()) {
                if (subReader.name() == QLatin1String("infoTextListElem")) {
                    section.addNote(subReader.readElementText());
                }
            }
        } else if (reader.name() == QLatin1String("itdStopSeq")) {
            section.setIntermediateStops(parsePartialTripStopSequence(reader.subReader()));
        } else if (reader.name() == QLatin1String("itdPathCoordinates")) {
            sectionPoly = parsePathCoordinates(reader.subReader());
        } else if (reader.name() == QLatin1String("itdInterchangePathCoordinates")) {
            auto subreader = reader.subReader();
            while (subreader.readNextSibling()) {
                if (subreader.name() == QLatin1String("itdPathCoordinates")) {
                    transferPoly = parsePathCoordinates(subreader.subReader());
                }
            }
        } else if (reader.name() == QLatin1String("itdITPathDescription") && !sectionPoly.isEmpty()) {
            auto subreader = reader.subReader();
            while (subreader.readNextSibling()) {
                if (subreader.name() == QLatin1String("itdITPathDescriptionList")) {
                    pathDesc = parsePathDescriptionList(subreader.subReader());
                }
            }
        }
    }

    if (!pathDesc.empty()) {
        resolvePathDescription(pathDesc);
        if (!transferPoly.empty() && section.mode() == JourneySection::PublicTransport) {
            // path description is actually for a subsequent transfer section
            const auto path = assemblePath(pathDesc, transferPoly);
            JourneySection transferSection;
            transferSection.setMode(JourneySection::Transfer);
            transferSection.setScheduledDepartureTime(section.scheduledArrivalTime());
            const auto travelTime = std::accumulate(pathDesc.begin(), pathDesc.end(), 0, [](auto accu, const auto &desc) {
                return accu + desc.travelTime;
            });
            transferSection.setScheduledArrivalTime(section.scheduledArrivalTime().addSecs(travelTime));
            Location from;
            from.setLatitude(path.startPoint().y());
            from.setLongitude(path.startPoint().x());
            transferSection.setFrom(std::move(from));
            Location to;
            to.setLatitude(path.endPoint().y());
            to.setLongitude(path.endPoint().x());
            transferSection.setTo(std::move(to));
            transferSection.setPath(std::move(path));
            result.push_back(std::move(transferSection));
        } else if (section.mode() == JourneySection::Walking) {
            // path description is for this section
            section.setPath(assemblePath(pathDesc, sectionPoly));
        }
    }
    if (!sectionPoly.isEmpty() && section.path().isEmpty()) {
        section.setPath(polygonToPath(sectionPoly));
    }

    result.insert(result.begin(), std::move(section));
    return result;
}

Journey EfaXmlParser::parseTripRoute(ScopedXmlStreamReader &&reader) const
{
    Journey journey;
    std::vector<JourneySection> sections;

    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("itdPartialRoute")) {
            auto sec = parseTripPartialRoute(reader.subReader());
            std::move(sec.begin(), sec.end(), std::back_inserter(sections));
        }
    }

    journey.setSections(std::move(sections));
    return journey;
}

std::vector<Journey> EfaXmlParser::parseTripResponse(const QByteArray &data)
{
    //qDebug().noquote() << data;
    std::vector<Journey> res;
    QXmlStreamReader xsr(data);
    ScopedXmlStreamReader reader(xsr);
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("itdRequest")) {
            m_requestContext.sessionId = reader.attributes().value(QLatin1String("sessionID")).toString();
        } else if (reader.name() == QLatin1String("itdTripRequest")) {
            m_requestContext.requestId = reader.attributes().value(QLatin1String("requestID")).toString();
        } else if (reader.name() == QLatin1String("itdRoute")) {
            res.push_back(parseTripRoute(reader.subReader()));
        }
    }
    return res;
}

QStringList EfaXmlParser::parseInfoLink(ScopedXmlStreamReader &&reader) const
{
    QStringList l;
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("infoLinkText") || reader.name() == QLatin1String("subtitle")
            || reader.name() == QLatin1String("wmlText") || reader.name() == QLatin1String("htmlText"))
        {
            l.push_back(reader.readElementText());
        }
    }
    return l;
}

QPolygonF EfaXmlParser::parsePathCoordinates(ScopedXmlStreamReader &&reader) const
{
    QPolygonF poly;
    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdCoordinateString")) {
            poly = parsePathCoordinatesElement(reader);
        }
    }
    return poly;
}

std::vector<EfaXmlParser::PathDescription> EfaXmlParser::parsePathDescriptionList(ScopedXmlStreamReader &&reader) const
{
    std::vector<PathDescription> descs;
    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("itdITPathDescriptionElem")) {
            PathDescription desc;
            auto elemReader = reader.subReader();
            while (elemReader.readNextSibling()) {
                if (elemReader.name() == "itdCoord"_L1) {
                    if (const auto coordSys = elemReader.attributes().value("mapName"); coordSys.empty() || coordSys == WGS84) {
                        desc.point.setX(elemReader.attributes().value("x"_L1).toDouble());
                        desc.point.setY(elemReader.attributes().value("y"_L1).toDouble());
                    }
                } else if (elemReader.name() == QLatin1String("fromPathCoordIdx")) {
                    desc.fromIndex = elemReader.readElementText().toInt();
                } else if (elemReader.name() == QLatin1String("toPathCoordIdx")) {
                    desc.toIndex = elemReader.readElementText().toInt();
                } else if (elemReader.name() == QLatin1String("streetname")) {
                    desc.description = elemReader.readElementText();
                } else if (elemReader.name() == QLatin1String("traveltime")) {
                    desc.travelTime = elemReader.readElementText().toInt();
                } else if (elemReader.name() == QLatin1String("niveau")) {
                    // seems to match OSM floor level, but is always "0" for elevators/escalators
                    desc.niveau = elemReader.readElementText().toInt();
                } else if (elemReader.name() == QLatin1String("genAttrList")) {
                    const auto attrs = parseGenericAttributeList(elemReader.subReader());
                    const auto indoorType = attrs.value(QStringLiteral("INDOOR_TYPE"));
                    if (indoorType == QLatin1String("STAIRS")) {
                        desc.maneuver = PathSection::Stairs;
                    } else if (indoorType == QLatin1String("LIFT")) {
                        desc.maneuver = PathSection::Elevator;
                    } else if (indoorType == QLatin1String("ESCALATOR")) {
                        desc.maneuver = PathSection::Escalator;
                    }

                    bool floorLevelDifferenceValid = false;
                    const auto floorLevelDifference = attrs.value(QStringLiteral("FLOOR_LEVEL_DIFFERENCE")).toInt(&floorLevelDifferenceValid);
                    if (floorLevelDifferenceValid) {
                        desc.niveauDelta = floorLevelDifference;
                    }
                }
                // NOTE: skyDirection seems flipped by 180°, ie. pointing to the start point, should we ever need that
                // turnDirection, turningManoeuvre, from/toPathLink??
            }
            descs.push_back(std::move(desc));
        }
    }
    return descs;
}

void EfaXmlParser::resolvePathDescription(std::vector<PathDescription> &descs) const
{
    if (descs.size() < 3) {
        return;
    }

    for (auto it = std::next(descs.begin()); it != std::prev(descs.end()); ++it) {
        if ((*it).maneuver != PathSection::Stairs && (*it).maneuver != PathSection::Elevator && (*it).maneuver != PathSection::Escalator) {
            continue;
        }
        const auto niveauBefore = (*std::prev(it)).niveau;
        const auto niveauAfter = (*std::next(it)).niveau;
        if (niveauAfter != niveauBefore && (*it).niveauDelta == 0) {
            (*it).niveauDelta = niveauAfter - niveauBefore;
        }
    }
}

Path EfaXmlParser::assemblePath(const std::vector<PathDescription> &descs, const QPolygonF &poly) const
{
    Path path;
    std::vector<PathSection> sections;

    for (const auto &desc : descs) {
        if (desc.fromIndex < 0 || desc.toIndex < 0 || desc.fromIndex >= poly.size() || desc.toIndex >= poly.size() || desc.toIndex < desc.fromIndex) {
            qCWarning(Log) << "weird polygon indexes?" << desc.fromIndex << desc.toIndex << poly.size();
            continue;
        }
        PathSection section;
        QPolygonF subPoly;
        subPoly.reserve(desc.toIndex - desc.fromIndex + 1);
        std::copy(poly.begin() + desc.fromIndex, poly.begin() + desc.toIndex + 1, std::back_inserter(subPoly));
        section.setPath(subPoly);
        section.setDescription(desc.description);
        section.setManeuver(desc.maneuver);
        section.setFloorLevelChange(desc.niveauDelta);
        sections.push_back(std::move(section));
    }

    path.setSections(std::move(sections));
    return path;
}

QHash<QString, QString> EfaXmlParser::parseGenericAttributeList(ScopedXmlStreamReader &&reader) const
{
    return parseKeyValueList(std::move(reader), QLatin1String("genAttrElem"), QLatin1String("name"), QLatin1String("value"));
}

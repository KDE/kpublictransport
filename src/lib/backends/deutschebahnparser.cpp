/*
    SPDX-FileCopyrightText: 2024 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "deutschebahnparser.h"
#include "hafasmgateparser.h"
#include "datatypes/featureutil_p.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace Qt::Literals;
using namespace KPublicTransport;

std::vector<Location> DeutscheBahnParser::parseLocations(const QByteArray &data, const HafasMgateParser &hafasParser)
{
    const auto array = QJsonDocument::fromJson(data).array();
    std::vector<Location> locs;
    locs.reserve(array.size());
    for (const auto &locV : array) {
        const auto locObj = locV.toObject();
        Location loc = hafasParser.fromLocationId(locObj.value("id"_L1).toString());
        loc.setName(locObj.value("name"_L1).toString());
        loc.setLatitude(locObj.value("lat"_L1).toDouble());
        loc.setLongitude(locObj.value("lon"_L1).toDouble());
        // TODO type (ST, ADR, POI)
        hafasParser.setLocationIdentifier(loc, locObj.value("extId"_L1).toString());
        locs.push_back(std::move(loc));
    }
    return locs;
}

struct {
    const char *name;
    Line::Mode mode;
} static constexpr const product_to_mode_map[] = {
    { "ICE", Line::LongDistanceTrain },
    { "EC_IC", Line::LongDistanceTrain },
    { "IR", Line::Train },
    { "REGIONAL", Line::LocalTrain },
    { "SBAHN", Line::RapidTransit },
    { "BUS", Line::Bus },
    { "SCHIFF", Line::Boat },
    { "UBAHN", Line::Metro },
    { "TRAM", Line::Tramway },
    { "ANRUFPFLICHTIG", Line::Taxi },
};

[[nodiscard]] static Route parseRoute(const QJsonObject &lineObj)
{
    Line line;
    const auto product = lineObj.value("produktGattung"_L1).toString();
    for (const auto &m :product_to_mode_map) {
        if (QLatin1StringView(m.name) == product) {
            line.setMode(m.mode);
            break;
        }
    }
    if (line.mode() == Line::Unknown) {
        qDebug() << "Unkown product category" << product;
    }

    if (product == "TRAM"_L1 || product == "BUS"_L1) {
        line.setName(lineObj.value("linienNummer"_L1).toString());
    } else {
        line.setName(lineObj.value("mittelText"_L1).toString());
    }

    Route route;
    if (product == "REGIONAL"_L1) {
        route.setName(lineObj.value("name"_L1).toString());
    }

    route.setLine(line);
    return route;
}

template <typename T>
static void applyNotes(T &obj, const QJsonArray &notesArray)
{
    for (const auto &notesV : notesArray) {
        const auto notesObj = notesV.toObject();
        obj.addNote(notesObj.value("text"_L1).toString());
        if (const auto type = notesObj.value("type"_L1).toString(); type == "HALT_AUSFALL"_L1) {
            obj.setDisruptionEffect(Disruption::NoService);
        }
    }
}

std::vector<Stopover> DeutscheBahnParser::parseStopovers(const QJsonArray &stopsArray, bool isDeparture, const HafasMgateParser &hafasParser)
{
    std::vector<Stopover> stops;
    stops.reserve(stopsArray.size());
    for (const auto &stopV : stopsArray) {
        const auto stopObj = stopV.toObject();
        Stopover stop;

        if (isDeparture) {
            stop.setScheduledDepartureTime(QDateTime::fromString(stopObj.value("zeit"_L1).toString(), Qt::ISODate));
            stop.setExpectedDepartureTime(QDateTime::fromString(stopObj.value("ezZeit"_L1).toString(), Qt::ISODate));
        } else {
            stop.setScheduledArrivalTime(QDateTime::fromString(stopObj.value("zeit"_L1).toString(), Qt::ISODate));
            stop.setExpectedArrivalTime(QDateTime::fromString(stopObj.value("ezZeit"_L1).toString(), Qt::ISODate));
        }
        stop.setScheduledPlatform(stopObj.value("gleis"_L1).toString());
        stop.setExpectedPlatform(stopObj.value("ezGleis"_L1).toString());

        Location loc;
        hafasParser.setLocationIdentifier(loc, stopObj.value("bahnhofsId"_L1).toString());
        const auto vias = stopObj.value("ueber"_L1).toArray();
        if (!vias.isEmpty()) {
            loc.setName(isDeparture ? vias.first().toString() : vias.last().toString());
        }
        stop.setStopPoint(loc);

        const auto lineObj = stopObj.value("verkehrmittel"_L1).toObject();
        auto route = parseRoute(lineObj);
        route.setDirection(stopObj.value("terminus"_L1).toString());
        stop.setRoute(route);

        applyNotes(stop, stopObj.value("meldungen"_L1).toArray());
        stops.push_back(std::move(stop));
    }

    return stops;
}

template <typename T>
static void applyRisNotes(T &obj, const QJsonArray &risNotesArray)
{
    for (const auto &risNoteV : risNotesArray) {
        const auto risNote = risNoteV.toObject();
        obj.addNote(risNote.value("value"_L1).toString());
        const auto key = risNote.value("key"_L1).toString();
        if (key == "text.realtime.stop.cancelled"_L1) {
            obj.setDisruptionEffect(Disruption::NoService);
        }
    }
}

std::vector<Journey> DeutscheBahnParser::parseJourneys(const QJsonArray &journeysArray, const HafasMgateParser &hafasParser)
{
    std::vector<Journey> journeys;
    journeys.reserve(journeysArray.size());
    for (const auto &journeyV : journeysArray) {
        const auto journeyObj = journeyV.toObject();
        Journey journey;

        std::vector<JourneySection> sections;
        const auto sectionArray = journeyObj.value("verbindungsAbschnitte"_L1).toArray();
        for (const auto &sectionV : sectionArray) {
            const auto sectionObj = sectionV.toObject();
            JourneySection section;

            section.setScheduledDepartureTime(QDateTime::fromString(sectionObj.value("abfahrtsZeitpunkt"_L1).toString(), Qt::ISODate));
            section.setExpectedDepartureTime(QDateTime::fromString(sectionObj.value("ezAbfahrtsZeitpunkt"_L1).toString(), Qt::ISODate));
            section.setScheduledArrivalTime(QDateTime::fromString(sectionObj.value("ankunftsZeitpunkt"_L1).toString(), Qt::ISODate));
            section.setExpectedArrivalTime(QDateTime::fromString(sectionObj.value("ezAnkunftsZeitpunkt"_L1).toString(), Qt::ISODate));

            Location from;
            from.setName(sectionObj.value("abfahrtsOrt"_L1).toString());
            hafasParser.setLocationIdentifier(from, sectionObj.value("abfahrtsOrtExtId"_L1).toString());
            section.setFrom(from);

            Location to;
            to.setName(sectionObj.value("ankunftsOrt"_L1).toString());
            hafasParser.setLocationIdentifier(to, sectionObj.value("ankunftsOrtExtId"_L1).toString());
            section.setTo(to);

            const auto routeObj = sectionObj.value("verkehrsmittel"_L1).toObject();
            const auto type = routeObj.value("typ"_L1).toString();
            if (type == "WALK"_L1) {
                section.setMode(JourneySection::Walking);
            } else {
                section.setMode(JourneySection::PublicTransport);
            }

            std::vector<Stopover> intermediateStops;
            const auto stopsArray = sectionObj.value("halte"_L1).toArray();
            intermediateStops.reserve(stopsArray.size());
            for (const auto &stopV :stopsArray) {
                const auto stopObj = stopV.toObject();
                Stopover stop;

                stop.setScheduledDepartureTime(QDateTime::fromString(stopObj.value("abfahrtsZeitpunkt"_L1).toString(), Qt::ISODate));
                stop.setExpectedDepartureTime(QDateTime::fromString(stopObj.value("ezAbfahrtsZeitpunkt"_L1).toString(), Qt::ISODate));
                stop.setScheduledArrivalTime(QDateTime::fromString(stopObj.value("ankunftsZeitpunkt"_L1).toString(), Qt::ISODate));
                stop.setExpectedArrivalTime(QDateTime::fromString(stopObj.value("ezAnkunftsZeitpunkt"_L1).toString(), Qt::ISODate));
                stop.setScheduledPlatform(stopObj.value("gleis"_L1).toString());
                stop.setExpectedPlatform(stopObj.value("ezGleis"_L1).toString());

                Location stopPoint = hafasParser.fromLocationId(stopObj.value("id"_L1).toString());
                stopPoint.setName(stopObj.value("name"_L1).toString());
                hafasParser.setLocationIdentifier(stopPoint, stopObj.value("extId"_L1).toString());
                stop.setStopPoint(stopPoint);

                applyNotes(stop, stopObj.value("himMeldungen"_L1).toArray());
                applyNotes(stop, stopObj.value("priorisierteMeldungen"_L1).toArray());
                applyRisNotes(stop, stopObj.value("risNotizen"_L1).toArray());

                const auto occupancyArray = stopObj.value("auslastungsmeldungen"_L1).toArray();
                std::vector<LoadInfo> occupancies;
                occupancies.reserve(occupancyArray.size());
                for (const auto &occupancyV : occupancyArray) {
                    const auto occupancyObj = occupancyV.toObject();
                    const auto level = HafasParser::parseLoadLevel(occupancyObj.value("stufe"_L1).toInt(-1));
                    if (level == Load::Unknown) {
                        continue;
                    }
                    LoadInfo load;
                    load.setLoad(level);
                    load.setSeatingClass(occupancyObj.value("klasse"_L1).toString());
                    occupancies.push_back(std::move(load));
                }
                stop.setLoadInformation(std::move(occupancies));

                intermediateStops.push_back(std::move(stop));
            }

            if (intermediateStops.size() >= 2) {
                section.setDeparture(intermediateStops.front());
                section.setArrival(intermediateStops.back());
                intermediateStops.pop_back();
                intermediateStops.erase(intermediateStops.begin(), std::next(intermediateStops.begin()));
            }
            section.setIntermediateStops(std::move(intermediateStops));

            auto route = parseRoute(routeObj);
            route.setDirection(routeObj.value("richtung"_L1).toString());
            auto line = route.line();

            std::vector<Feature> features;
            const auto trainAttributes = routeObj.value("zugattribute"_L1).toArray();
            for (const auto &trainAttrV : trainAttributes) {
                const auto trainAttrObj = trainAttrV.toObject();
                const auto key = trainAttrObj.value("key"_L1).toString();
                if (key == "BEF"_L1) {
                    line.setOperatorName(trainAttrObj.value("value"_L1).toString());
                    continue;
                }

                auto value = trainAttrObj.value("value"_L1).toString();
                const auto affectedSegment = trainAttrObj.value("teilstreckenHinweis"_L1).toString();
                if (!affectedSegment.isEmpty() && affectedSegment != '('_L1 + section.from().name() + " - "_L1 + section.to().name() + ')'_L1) {
                    value += ' '_L1 + affectedSegment;
                }

                const auto type = trainAttrObj.value("kategorie"_L1).toString();
                if (type == "INFORMATION"_L1 || type == "FAHRRADMITNAHME"_L1 || type == "BORDBISTRO"_L1) {
                    const auto remarkData = HafasMgateParser::lookupRemarkData(u"A", key);
                    if (remarkData.msg == FeatureRemark) {
                        Feature f(remarkData.featureType, remarkData.featureAvailability);
                        f.setName(value);
                        FeatureUtil::add(features, std::move(f));
                        continue;
                    }
                    if (remarkData.msg == IgnoreRemark) {
                        continue;
                    }
                    if (remarkData.msg == UndefinedRemark) {
                        qDebug() << "unknown vehicle attribute" << type << key << value;
                    }
                }

                section.addNote(value);
            }
            section.setFeatures(std::move(features));

            route.setLine(line);
            section.setRoute(route);

            applyNotes(section, sectionObj.value("himMeldungen"_L1).toArray());
            applyNotes(section, sectionObj.value("priorisierteMeldungen"_L1).toArray());
            applyRisNotes(section, sectionObj.value("risNotizen"_L1).toArray());
            sections.push_back(std::move(section));
        }

        journey.setSections(std::move(sections));
        journeys.push_back(std::move(journey));
    }

    return journeys;
}

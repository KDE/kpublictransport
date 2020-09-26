/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasqueryparser.h"
#include "hafasjourneyresponse_p.h"
#include "logging.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QXmlStreamReader>

#include <zlib.h>

using namespace KPublicTransport;

HafasQueryParser::HafasQueryParser() = default;
HafasQueryParser::~HafasQueryParser() = default;

std::vector<Stopover> HafasQueryParser::parseStationBoardResponse(const QByteArray &data, bool isArrival)
{
    clearErrorState();
    qDebug().noquote() << data;
    std::vector<Stopover> res;

    QXmlStreamReader reader;
    if (data.startsWith("<Journey")) { // SBB and RT don't reply with valid XML...
        reader.addData("<dummyRoot>");
        reader.addData(data);
        reader.addData("</dummyRoot>");
    } else {
        reader.addData(data);
    }

    Location stopPoint;
    while (!reader.atEnd()) {
        const auto token = reader.readNext();
        switch (token) {
            case QXmlStreamReader::StartElement:
                if (reader.name() == QLatin1String("St")) {
                    stopPoint.setName(reader.attributes().value(QLatin1String("name")).toString());
                    setLocationIdentifier(stopPoint, reader.attributes().value(QLatin1String("evaId")).toString());
                } else if (reader.name() == QLatin1String("Journey")) {
                    auto dt = QDateTime::fromString(reader.attributes().value(QLatin1String("fpDate")) + reader.attributes().value(QLatin1String("fpTime")), QStringLiteral("dd.MM.yyhh:mm"));
                    if (dt.date().year() < 2000) {
                        dt = dt.addYears(100);
                    }
                    const auto delayStr = reader.attributes().value(QLatin1String("e_delay"));
                    const auto delaySecs = delayStr.toInt() * 60;
                    Stopover dep;
                    if (isArrival) {
                        dep.setScheduledArrivalTime(dt);
                        if (!delayStr.isEmpty()) {
                            dep.setExpectedArrivalTime(dt.addSecs(delaySecs));
                        }
                    } else {
                        dep.setScheduledDepartureTime(dt);
                        if (!delayStr.isEmpty()) {
                            dep.setExpectedDepartureTime(dt.addSecs(delaySecs));
                        }
                    }
                    dep.setScheduledPlatform(reader.attributes().value(QLatin1String("platform")).toString());
                    dep.setExpectedPlatform(reader.attributes().value(QLatin1String("newpl")).toString());

                    if (reader.attributes().value(QLatin1String("delay")) == QLatin1String("cancel")) {
                        dep.setDisruptionEffect(Disruption::NoService);
                    }

                    Route route;
                    route.setDirection(reader.attributes().value(QLatin1String("targetLoc")).toString());
                    Line line;
                    line.setName(reader.attributes().value(QLatin1String("hafasname")).toString());
                    if (line.name().isEmpty()) {
                        const auto prod = reader.attributes().value(QLatin1String("prod"));
                        const auto idx = prod.indexOf(QLatin1Char('#'));
                        line.setName(prod.left(idx).toString().simplified());
                    }

                    line.setMode(parseLineMode(reader.attributes().value(QLatin1String("class"))));
                    // TODO line mode from second part of prod attribute, if class not set
                    route.setLine(line);
                    dep.setRoute(route);

                    dep.setStopPoint(stopPoint);
                    res.push_back(dep);
                }
                break;
            default:
                break;
        }
    }

    return res;
}

std::vector<Location> HafasQueryParser::parseGetStopResponse(const QByteArray &data)
{
    clearErrorState();

    // remove garbage around JSON payload
    const auto startIdx = data.indexOf('{');
    const auto endIdx = data.lastIndexOf('}');
    const auto jsonData = data.mid(startIdx, endIdx - startIdx + 1);

    QJsonParseError parseError;
    const auto doc = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qCWarning(Log) << parseError.errorString() << jsonData;
    }
    const auto suggestions = doc.object().value(QLatin1String("suggestions")).toArray();
    std::vector<Location> res;
    res.reserve(suggestions.size());
    for (const auto &suggestion : suggestions) {
        const auto obj = suggestion.toObject();
        const auto extId = obj.value(QLatin1String("extId")).toString();
        if (extId.isEmpty()) {
            continue; // not a stop/station
        }
        Location loc;
        setLocationIdentifier(loc, extId);
        loc.setName(obj.value(QLatin1String("value")).toString());
        loc.setLatitude(obj.value(QLatin1String("ycoord")).toString().toInt() / 1000000.0);
        loc.setLongitude(obj.value(QLatin1String("xcoord")).toString().toInt() / 1000000.0);
        res.push_back(loc);
    }

    return res;
}

std::vector<Location> HafasQueryParser::parseQueryLocationResponse(const QByteArray &data)
{
    clearErrorState();

    const auto doc = QJsonDocument::fromJson(data);
    //qDebug().noquote() << doc.toJson();
    const auto stops = doc.object().value(QLatin1String("stops")).toArray();
    std::vector<Location> res;
    res.reserve(stops.size());
    for (const auto &stop : stops) {
        const auto obj = stop.toObject();
        Location loc;
        setLocationIdentifier(loc, obj.value(QLatin1String("extId")).toString());
        loc.setName(obj.value(QLatin1String("name")).toString());
        loc.setLatitude(obj.value(QLatin1String("y")).toString().toInt() / 1000000.0);
        loc.setLongitude(obj.value(QLatin1String("x")).toString().toInt() / 1000000.0);
        res.push_back(loc);
    }
    return res;
}

static QByteArray gzipDecompress(const QByteArray &data)
{
    QByteArray rawData;
    z_stream stream;
    unsigned char buffer[1024];

    stream.zalloc = nullptr;
    stream.zfree = nullptr;
    stream.opaque = nullptr;
    stream.avail_in = data.size();
    stream.next_in = reinterpret_cast<unsigned char*>(const_cast<char*>(data.data()));

    auto ret = inflateInit2(&stream, 15 + 32); // see docs, the magic numbers enable gzip decoding
    if (ret != Z_OK) {
        qCWarning(Log) << "Failed to initialize zlib stream.";
        return {};
    }

    do {
        stream.avail_out = sizeof(buffer);
        stream.next_out = buffer;

        ret = inflate(&stream, Z_NO_FLUSH);
        if (ret != Z_OK && ret != Z_STREAM_END) {
            qCWarning(Log) << "Zlib decoding failed!" << ret;
            break;
        }

        rawData.append(reinterpret_cast<char*>(buffer), sizeof(buffer) - stream.avail_out);
    } while (stream.avail_out == 0);
    inflateEnd(&stream);

    return rawData;
}

static QDateTime parseDateTime(const QDate &baseDate, uint16_t time)
{
    if (time == 0xffff) { // value is unset
        return {};
    }

    const auto days = time / 2400;
    const auto hours = (time / 100) % 24;
    const auto mins = time % 100;

    auto dt = QDateTime(baseDate, QTime(hours, mins));
    return dt.addDays(days);
}

std::vector<Journey> HafasQueryParser::parseQueryJourneyResponse(const QByteArray &data)
{
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
#warning Hafas binary response parsing not implemented on big endian architectures!
    Q_UNUSED(data);
    return {};
#endif
    clearErrorState();

    // yes, this is gzip compressed rather than using the HTTP compression transparently...
    const auto rawData = gzipDecompress(data);

    if (rawData.size() < (int)sizeof(HafasJourneyResponseHeader)) {
        qCWarning(Log) << "Response too small for header structure.";
        return {};
    }
    const auto header = reinterpret_cast<const HafasJourneyResponseHeader*>(rawData.constData());
    qDebug() << header->version << header->numJourneys;

    if (rawData.size() < (int)(sizeof(HafasJourneyResponseExtendedHeader) + header->extendedHeaderOffset)) {
        qCWarning(Log) << "Response too short for extended header structure.";
        return {};
    }
    const auto extHeader = reinterpret_cast<const HafasJourneyResponseExtendedHeader*>(rawData.constData() + header->extendedHeaderOffset);
    if (extHeader->length < (int)sizeof(HafasJourneyResponseExtendedHeader)) {
        qCWarning(Log) << "Extended header is shorter than expected" << extHeader->length;
        return {};
    }
    if (extHeader->errorCode != 0) {
        qCDebug(Log) << "Journey query returned error" << extHeader->errorCode;
        // TODO we could distinguish between not found and service errors here
        m_error = Reply::NotFoundError;
        return {};
    }

    const auto detailsHeader = reinterpret_cast<const HafasJourneyResponseDetailsHeader*>(rawData.constData() + extHeader->detailsOffset);
    qDebug() << "details header:" << detailsHeader->version;

    HafasJourneyResponseStringTable stringTable(rawData, header->stringTableOffset, extHeader->encodingStr);
    QDate baseDate(1979, 12, 31);
    baseDate = baseDate.addDays(header->date);

    std::vector<Journey> journeys;
    journeys.reserve(header->numJourneys);
    for (int journeyIdx = 0; journeyIdx < header->numJourneys; ++journeyIdx) {
        const auto journeyInfo = reinterpret_cast<const HafasJourneyResponseJourney*>(rawData.constData() + sizeof(HafasJourneyResponseHeader) + journeyIdx * sizeof(HafasJourneyResponseJourney));
        qDebug() << "section count: " << journeyInfo->numSections;

        const auto journeyDetailsOffset = *reinterpret_cast<const uint16_t*>(rawData.constData()
            + extHeader->detailsOffset
            + detailsHeader->journeyDetailsIndexOffset
            + journeyIdx * sizeof(uint16_t));

        std::vector<JourneySection> sections;
        sections.reserve(journeyInfo->numSections);
        for (int sectionIdx = 0; sectionIdx < journeyInfo->numSections; ++sectionIdx) {
            const auto sectionInfo = reinterpret_cast<const HafasJourneyResponseSection*>(rawData.constData()
                + sizeof(HafasJourneyResponseHeader)
                + journeyInfo->sectionsOffset
                + sectionIdx * sizeof(HafasJourneyResponseSection));
            qDebug() << stringTable.lookup(sectionInfo->lineNameStr) << sectionInfo->type;

            Location from;
            const auto fromInfo = reinterpret_cast<const HafasJourneyResponseStation*>(rawData.constData()
                + header->stationTableOffset
                + sectionInfo->departureStationIdx * sizeof(HafasJourneyResponseStation));
            from.setName(stringTable.lookup(fromInfo->nameStr));
            from.setLatitude(fromInfo->latitude / 1000000.0);
            from.setLongitude(fromInfo->longitude / 1000000.0);
            setLocationIdentifier(from, QString::number(fromInfo->id));

            Location to;
            const auto toInfo = reinterpret_cast<const HafasJourneyResponseStation*>(rawData.constData()
                + header->stationTableOffset
                + sectionInfo->arrivalStationIdx * sizeof(HafasJourneyResponseStation));
            to.setName(stringTable.lookup(toInfo->nameStr));
            to.setLatitude(toInfo->latitude / 1000000.0);
            to.setLongitude(toInfo->longitude / 1000000.0);
            setLocationIdentifier(to, QString::number(toInfo->id));

            JourneySection section;
            section.setFrom(from);
            section.setTo(to);

            section.setScheduledDepartureTime(parseDateTime(baseDate, sectionInfo->scheduledDepartureTime));
            section.setScheduledArrivalTime(parseDateTime(baseDate, sectionInfo->scheduledArrivalTime));

            const auto journeyAttrIndex = *reinterpret_cast<const uint16_t*>(rawData.constData()
                + extHeader->journeyAttributesIndexOffset + journeyIdx * sizeof(uint16_t));
            auto attr = HafasJourneyResponse::attribute(rawData.constData(), extHeader, journeyAttrIndex);
            while (!attr->atEnd()) {
                qDebug() << "journey attr" << stringTable.lookup(attr->keyStr) << stringTable.lookup(attr->valueStr);
                ++attr;
            }

            if (sectionInfo->type == HafasJourneyResponseSectionMode::PublicTransport) {
                Route route;
                Line line;
                line.setName(stringTable.lookup(sectionInfo->lineNameStr).trimmed());

                auto attr = HafasJourneyResponse::attribute(rawData.constData(), extHeader, sectionInfo->sectionAttributeIndex);
                while (!attr->atEnd()) {
                    qDebug() << "section attr" << stringTable.lookup(attr->keyStr) << stringTable.lookup(attr->valueStr);
                    const auto key = stringTable.lookup(attr->keyStr);
                    if (key == QLatin1String("Direction")) {
                        const auto dir = stringTable.lookup(attr->valueStr);
                        if (dir != QLatin1String("---")) {
                            route.setDirection(dir.trimmed());
                        }
                    } else if (key == QLatin1String("Class")) {
                        line.setMode(parseLineMode(stringTable.lookup(attr->valueStr)));
                    }
                    ++attr;
                }

                const auto *commentPtr = reinterpret_cast<const uint16_t*>(rawData.constBegin() + header->commentTableOffset + sectionInfo->commentIdx);
                const auto commentCount = *commentPtr;
                for (int i = 0; i < commentCount; ++i) {
                    ++commentPtr;
                    // format: XX - <human readable comment>, where XX is two character code for the comment
                    const auto note = stringTable.lookup(*commentPtr);
                    if (note.size() > 5 && note.midRef(2, 3) == QLatin1String(" - ")) {
                        section.addNote(note.mid(5));
                    } else {
                        section.addNote(note);
                    }
                }

                route.setLine(line);
                section.setRoute(route);
                section.setMode(JourneySection::PublicTransport);
                section.setScheduledDeparturePlatform(stringTable.lookup(sectionInfo->scheduledDeparturePlatformStr));
                section.setScheduledArrivalPlatform(stringTable.lookup(sectionInfo->scheduledArrivalPlatformStr));

                const auto sectionDetail = reinterpret_cast<const HafasJourneyResponseSectionDetail*>(rawData.constData()
                    + extHeader->detailsOffset
                    + journeyDetailsOffset
                    + detailsHeader->sectionDetailsOffset
                    + detailsHeader->sectionDetailsSize * sectionIdx);
                qDebug() << "section detail" << sectionDetail->expectedArrivalPlatformStr <<  sectionDetail->expectedDeparturePlatformStr;
                section.setExpectedDeparturePlatform(stringTable.lookup(sectionDetail->expectedDeparturePlatformStr));
                section.setExpectedArrivalPlatform(stringTable.lookup(sectionDetail->expectedArrivalPlatformStr));

                section.setExpectedDepartureTime(parseDateTime(baseDate, sectionDetail->expectedDepartureTime));
                section.setExpectedArrivalTime(parseDateTime(baseDate, sectionDetail->expectedArrivalTime));

                std::vector<Stopover> stops;
                stops.reserve(sectionDetail->numStops);
                for (int i = 0; i < sectionDetail->numStops; ++i) {
                    const auto stopInfo = reinterpret_cast<const HafasJourneyResponseStop*>(rawData.constData() + extHeader->detailsOffset + detailsHeader->stopsOffset + i * detailsHeader->stopsSize);

                    Location loc;
                    const auto locInfo = reinterpret_cast<const HafasJourneyResponseStation*>(rawData.constData()
                        + header->stationTableOffset
                        + stopInfo->stationIdx * sizeof(HafasJourneyResponseStation));
                    loc.setName(stringTable.lookup(locInfo->nameStr));
                    loc.setLatitude(locInfo->latitude / 1000000.0);
                    loc.setLongitude(locInfo->longitude / 1000000.0);

                    Stopover stop;
                    stop.setStopPoint(loc);
                    stop.setScheduledArrivalTime(parseDateTime(baseDate, stopInfo->scheduledArrivalTime));
                    stop.setScheduledDepartureTime(parseDateTime(baseDate, stopInfo->scheduledDepartureTime));
                    stop.setExpectedArrivalTime(parseDateTime(baseDate, stopInfo->expectedArrivalTime));
                    stop.setExpectedDepartureTime(parseDateTime(baseDate, stopInfo->expectedDepartureTime));
                    stop.setScheduledPlatform(stringTable.lookup(stopInfo->scheduledDeparturePlatformStr));
                    stop.setExpectedPlatform(stringTable.lookup(stopInfo->expectedDeparturePlatformStr));

                    stops.push_back(stop);
                }
                section.setIntermediateStops(std::move(stops));

            } else if (sectionInfo->type == HafasJourneyResponseSectionMode::Walk) {
                section.setMode(JourneySection::Walking);
            } else if (sectionInfo->type == HafasJourneyResponseSectionMode::Transfer1 || sectionInfo->type == HafasJourneyResponseSectionMode::Transfer2) {
                section.setMode(JourneySection::Transfer);
            } else {
                qCWarning(Log) << "Unknown section mode:" << sectionInfo->type;
            }

            sections.push_back(section);
        }

        const auto disruptionTable = HafasJourneyResponse::disruptionTable(rawData.constData(), extHeader);
        auto disruption = disruptionTable->firstDisruptionForJourney(journeyIdx);
        while (disruption) {
            qDebug() << "disruption" << stringTable.lookup(disruption->idStr) << stringTable.lookup(disruption->titleStr) << stringTable.lookup(disruption->messageStr)
                << stringTable.lookup(disruption->startStr) << stringTable.lookup(disruption->endStr) << disruption->bitmask << disruption->section;
            sections[disruption->section].addNote(stringTable.lookup(disruption->titleStr));
            sections[disruption->section].addNote(stringTable.lookup(disruption->messageStr));

            auto attr = HafasJourneyResponse::attribute(rawData.constData(), extHeader, disruption->disruptionAttributeIndex);
            while (!attr->atEnd()) {
                qDebug() << "disruption attr" << stringTable.lookup(attr->keyStr) << stringTable.lookup(attr->valueStr);
                ++attr;
            }

            disruption = disruption->next(disruptionTable);
        }

        Journey journey;
        journey.setSections(std::move(sections));
        journeys.push_back(journey);
    }

    return journeys;
}

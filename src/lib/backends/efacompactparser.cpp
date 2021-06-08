/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "efacompactparser.h"
#include "logging.h"
#include "scopedxmlstreamreader.h"
#include "ifopt/ifoptutil.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Location>
#include <KPublicTransport/Stopover>

#include <QDateTime>
#include <QDebug>
#include <QXmlStreamReader>

using namespace KPublicTransport;

static void parseCompactCoordinate(const QString &text, Location &loc)
{
    const auto coords = text.split(QLatin1Char(','));
    if (coords.size() == 2) {
        loc.setLatitude(coords[1].toFloat());
        loc.setLongitude(coords[0].toFloat());
    }
}

static void parseCompactIfopt(ScopedXmlStreamReader &reader, Location &loc)
{
    if (reader.name() == QLatin1String("pgid")) {
        const auto id = reader.readElementText();
        if (IfoptUtil::isValid(id)) {
            loc.setIdentifier(QStringLiteral("ifopt"), id);
        }
    } else if (reader.name() == QLatin1String("gid")) {
        const auto id = reader.readElementText();
        if (IfoptUtil::isValid(id) && loc.identifier(QLatin1String("ifopt")).isEmpty()) {
            loc.setIdentifier(QStringLiteral("ifopt"), id);
        }
    }
}

Location EfaCompactParser::parseCompactSf(ScopedXmlStreamReader &&reader) const
{
    Location loc;

    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("n")) {
            loc.setName(reader.readElementText());
        } else if (reader.name() == QLatin1String("ty")) {
            const auto type = reader.readElementText();
            if (type == QLatin1String("stop")) {
                loc.setType(Location::Stop);
            } else {
                qCDebug(Log) << "unhandled location type:" << type;
            }
        } else if (reader.name() == QLatin1String("r")) {
            auto sub = reader.subReader();
            while (sub.readNextSibling()) {
                if (sub.name() == QLatin1String("c")) {
                    parseCompactCoordinate(sub.readElementText(), loc);
                } else if (sub.name() == QLatin1String("id")) {
                    const auto id = sub.readElementText();
                    if (!id.isEmpty()) {
                        loc.setIdentifier(m_locationIdentifierType, id);
                    }
                } else if (sub.name() == QLatin1String("pc")) {
                    loc.setLocality(sub.readElementText());
                } else {
                    parseCompactIfopt(sub, loc);
                }
            }
        }
    }

    return loc;
}

std::vector<Location> EfaCompactParser::parseStopFinderResponse(const QByteArray &data) const
{
    std::vector<Location> res;
    QXmlStreamReader xsr(data);
    ScopedXmlStreamReader reader(xsr);
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("p")) {
            const auto l = parseCompactSf(reader.subReader());
            if (!l.isEmpty()) {
                res.push_back(l);
            }
        }
    }
    return res;
}

static std::pair<QDateTime, QDateTime> parseCompactTimePair(ScopedXmlStreamReader &&reader)
{
    QDateTime scheduledDt, expectedDt;

    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("da")) {
            scheduledDt.setDate(QDate::fromString(reader.readElementText(), QStringLiteral("yyyyMMdd")));
        } else if (reader.name() == QLatin1String("t")) {
            scheduledDt.setTime(QTime::fromString(reader.readElementText(), QStringLiteral("hhmm")));
        } else if (reader.name() == QLatin1String("rda")) {
            expectedDt.setDate(QDate::fromString(reader.readElementText(), QStringLiteral("yyyyMMdd")));
        } else if (reader.name() == QLatin1String("rt")) {
            expectedDt.setTime(QTime::fromString(reader.readElementText(), QStringLiteral("hhmm")));
        }
    }

    return std::make_pair(scheduledDt, expectedDt);
}

QStringList EfaCompactParser::parseNotes(ScopedXmlStreamReader &&reader) const
{
    QStringList ns;
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("tx")) {
            ns.push_back(reader.readElementText());
        }
    }
    return ns;
}

Stopover EfaCompactParser::parseCompactDp(ScopedXmlStreamReader &&reader) const
{
    Stopover dep;
    Location loc;
    bool clearRealtime = false;
    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("n")) {
            loc.setName(reader.readElementText());
        } else if (reader.name() == QLatin1String("realtime")) {
            clearRealtime = reader.readElementText() == QLatin1String("0");
        } else if (reader.name() == QLatin1String("rts")) {
            const auto rts = reader.readElementText();
            if (rts == QLatin1String("TRIP_CANCELLED")) {
                dep.setDisruptionEffect(Disruption::NoService);
            }
        } else if (reader.name() == QLatin1String("st")) {
            const auto st = parseCompactTimePair(reader.subReader());
            dep.setScheduledDepartureTime(st.first);
            dep.setExpectedDepartureTime(st.second);
        } else if (reader.name() == QLatin1String("m")) {
            Route route;
            Line line;
            auto subReader = reader.subReader();
            while (subReader.readNextSibling()) {
                if (subReader.name() == QLatin1String("des")) {
                    route.setDirection(subReader.readElementText());
                } else if (subReader.name() == QLatin1String("nu")) {
                    line.setName(subReader.readElementText());
                } else if (subReader.name() == QLatin1String("n")) {
                    line.setModeString(subReader.readElementText());
                } else if (subReader.name() == QLatin1String("ty")) {
                    line.setMode(motTypeToLineMode(subReader.readElementText().toInt()));
                }
            }
            route.setLine(line);
            dep.setRoute(route);
        } else if (reader.name() == QLatin1String("r")) {
            auto subReader = reader.subReader();
            while (subReader.readNextSibling()) {
                if (subReader.name() == QLatin1String("id")) {
                    loc.setIdentifier(m_locationIdentifierType, subReader.readElementText());
                } else if (subReader.name() == QLatin1String("pl")) {
                    dep.setScheduledPlatform(subReader.readElementText());
                }
            }
        } else if (reader.name() == QLatin1String("c")) {
            parseCompactCoordinate(reader.readElementText(), loc);
        } else if (reader.name() == QLatin1String("ns")) {
            dep.setNotes(parseNotes(reader.subReader()));
        } else {
            parseCompactIfopt(reader, loc);
        }
    }

    dep.setStopPoint(loc);
    if (clearRealtime) {
        dep.setExpectedDepartureTime({});
    }
    return dep;
}

std::vector<Stopover> EfaCompactParser::parseDmResponse(const QByteArray &data) const
{
    std::vector<Stopover> res;
    QXmlStreamReader xsr(data);
    ScopedXmlStreamReader reader(xsr);
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("dp")) {
            res.push_back(parseCompactDp(reader.subReader()));
        }
    }

    return res;
}

void EfaCompactParser::parseTripSectionHalf(ScopedXmlStreamReader &&reader, JourneySection &section) const
{
    Location loc;
    std::pair<QDateTime, QDateTime> dts;
    QString platform;

    bool isArr = true;
    while (reader.readNextSibling()) {
        if (reader.name() == QLatin1String("n") && loc.name().isEmpty()) {
            loc.setName(reader.readElementText());
        } else if (reader.name() == QLatin1String("de")) {
            loc.setName(reader.readElementText());
        } else if (reader.name() == QLatin1String("u")) {
            isArr = reader.readElementText() == QLatin1String("arrival");
        } else if (reader.name() == QLatin1String("st")) {
            dts = parseCompactTimePair(reader.subReader());
        } else if (reader.name() == QLatin1String("r")) {
            ScopedXmlStreamReader subReader(reader.subReader());
            while (subReader.readNextSibling()) {
                if (subReader.name() == QLatin1String("id")) {
                    loc.setIdentifier(m_locationIdentifierType, subReader.readElementText());
                } else if (subReader.name() == QLatin1String("pc")) {
                    loc.setLocality(subReader.readElementText());
                } else if (subReader.name() == QLatin1String("pl") || subReader.name() == QLatin1String("divaPl")) {
                    platform = subReader.readElementText();
                } else if (subReader.name() == QLatin1String("c")) {
                    parseCompactCoordinate(subReader.readElementText(), loc);
                }
            }
        } else {
            parseCompactIfopt(reader, loc);
        }
    }

    if (isArr) {
        section.setTo(loc);
        section.setScheduledArrivalTime(dts.first);
        section.setExpectedArrivalTime(dts.second);
        section.setScheduledArrivalPlatform(platform);
    } else {
        section.setFrom(loc);
        section.setScheduledDepartureTime(dts.first);
        section.setExpectedDepartureTime(dts.second);
        section.setScheduledDeparturePlatform(platform);
    }
}

JourneySection EfaCompactParser::parseTripSection(ScopedXmlStreamReader &&reader) const
{
    JourneySection section;
    section.setMode(JourneySection::PublicTransport);

    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("p")) {
            parseTripSectionHalf(reader.subReader(), section);
        } else if (reader.name() == QLatin1String("m")) {
            Route route;
            Line line;
            auto subReader = reader.subReader();
            while (subReader.readNextSibling()) {
                if (subReader.name() == QLatin1String("des")) {
                    route.setDirection(subReader.readElementText());
                } else if (subReader.name() == QLatin1String("nu")) {
                    line.setName(subReader.readElementText());
                } else if (subReader.name() == QLatin1String("n")) {
                    line.setModeString(subReader.readElementText());
                } else if (subReader.name() == QLatin1String("ty")) {
                    const auto secType = subReader.readElementText().toInt();
                    switch (secType) {
                        case 99:
                        case 100:
                            section.setMode(JourneySection::Walking);
                            break;
                        case 98:
                        case 105:
                            section.setMode(JourneySection::Transfer);
                            break;
                    }
                } else if (subReader.name() == QLatin1String("co")) {
                    line.setMode(motTypeToLineMode(subReader.readElementText().toInt()));
                }
            }

            // fix messed up mode name values
            if (line.modeString().startsWith(line.name() + QLatin1Char(' '))) {
                line.setModeString(line.modeString().mid(line.name().size() + 1));
            } else if (line.modeString().endsWith(QLatin1Char(' ') + line.name())) {
                line.setModeString(line.modeString().left(line.modeString().size() - line.name().size() - 1));
            }

            if (section.mode() == JourneySection::PublicTransport) {
                route.setLine(line);
                section.setRoute(route);
            }
        } else if (reader.name() == QLatin1String("ns")) {
            section.setNotes(parseNotes(reader.subReader()));
        } else if (reader.name() == QLatin1String("realtime")) {
            if (reader.readElementText() == QLatin1String("0")) { // expected time fields are set in all cases
                section.setExpectedArrivalTime({});
                section.setExpectedDepartureTime({});
            }
        } else if (reader.name() == QLatin1String("pss")) {
            std::vector<Stopover> stops;
            auto subReader = reader.subReader();
            while (subReader.readNextSibling()) {
                if (subReader.name() == QLatin1String("s")) {
                    const auto stopParams = subReader.readElementText().split(QLatin1Char(';'));
                    if (stopParams.size() <= 13) {
                        continue;
                    }

                    // semicolon separated list with the following content
                    // 0: station id
                    // 1: station name
                    // 2: date as yyyyMMdd
                    // 3: time as hhmm
                    // 4: location coordinate, colon separated as <lon>:<lat>:WGS84[DD.ddddd]
                    // 5: delay in minutes, presumably for fields 2/3
                    // 6: integer of unknown meaning - same as <a>
                    // 7: platform - same as <divaPl>
                    // 8: date as yyyyMMdd - only set on departure?
                    // 9: time as hhmm - only set on departure?
                    // 10: delay in minutes, presumably for fields 8/9
                    // 11: integer of unknown meaning
                    // 12: IFOPT station id (see also <gid>)
                    // 13: IFOPT stop/platform id (see also <pgid>)

                    Location loc;
                    loc.setIdentifier(m_locationIdentifierType, stopParams[0]);
                    loc.setName(stopParams[1]);

                    const auto coord = stopParams[4].split(QLatin1Char(':'));
                    if (coord.size() < 2) {
                        continue;
                    }
                    loc.setCoordinate(coord[1].toFloat(), coord[0].toFloat());

                    if (IfoptUtil::isValid(stopParams[13])) {
                        loc.setIdentifier(QStringLiteral("ifopt"), stopParams[13]);
                    } else if (IfoptUtil::isValid(stopParams[12])) {
                        loc.setIdentifier(QStringLiteral("ifopt"), stopParams[12]);
                    }

                    const auto dt = QDateTime::fromString(stopParams[2] + stopParams[3], QStringLiteral("yyyyMMddhhmm"));
                    if (!dt.isValid()) {
                        continue;
                    }
                    bool result = false;
                    auto delay = stopParams[5].toInt(&result);
                    if (!result) {
                        delay = -1;
                    }

                    Stopover stop;
                    stop.setStopPoint(loc);
                    stop.setScheduledPlatform(stopParams[7]);
                    stop.setScheduledDepartureTime(dt);
                    if (delay >= 0) {
                        stop.setExpectedDepartureTime(dt.addSecs(delay * 60));
                    }

                    stops.push_back(stop);
                }
            }

            if (stops.size() >= 2) { // exclude departure/arrival stops
                stops.erase(std::prev(stops.end()));
                stops.erase(stops.begin());
            }
            section.setIntermediateStops(std::move(stops));
        } else if (reader.name() == QLatin1String("pt")) {
            section.setPath(parsePathCoordinatesElement(reader));
        }
        // TODO interchange tag - should we turn this into transfer sections?
    }
    return section;
}

Journey EfaCompactParser::parseCompactTp(ScopedXmlStreamReader &&reader) const
{
    Journey jny;
    std::vector<JourneySection> sections;

    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("l")) {
            sections.push_back(parseTripSection(reader.subReader()));
        }
    }

    jny.setSections(std::move(sections));
    return jny;
}

std::vector<Journey> EfaCompactParser::parseTripResponse(const QByteArray &data) const
{
    //qDebug().noquote() << data;
    std::vector<Journey> res;
    QXmlStreamReader xsr(data);
    ScopedXmlStreamReader reader(xsr);
    while (reader.readNextElement()) {
        if (reader.name() == QLatin1String("tp")) {
            res.push_back(parseCompactTp(reader.subReader()));
        }
    }

    return res;
}

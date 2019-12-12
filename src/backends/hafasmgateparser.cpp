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

#include "hafasmgateparser.h"
#include "logging.h"

#include <KPublicTransport/Departure>
#include <KPublicTransport/Journey>
#include <KPublicTransport/Line>

#include <QColor>
#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace KPublicTransport;

HafasMgateParser::HafasMgateParser() = default;
HafasMgateParser::~HafasMgateParser() = default;

static std::vector<Ico> parseIcos(const QJsonArray &icoL)
{
    std::vector<Ico> icos;
    icos.reserve(icoL.size());
    for (const auto &icoV : icoL) {
        const auto icoObj = icoV.toObject();
        Ico ico;
        const auto fg = icoObj.value(QLatin1String("fg")).toObject();
        if (!fg.isEmpty()) {
            ico.fg = QColor(fg.value(QLatin1String("r")).toInt(), fg.value(QLatin1String("g")).toInt(), fg.value(QLatin1String("b")).toInt());
        }
        const auto bg = icoObj.value(QLatin1String("bg")).toObject();
        if (!bg.isEmpty()) {
            ico.bg = QColor(bg.value(QLatin1String("r")).toInt(), bg.value(QLatin1String("g")).toInt(), bg.value(QLatin1String("b")).toInt());
        }
        icos.push_back(ico);
    }
    return icos;
}

static std::vector<QString> parseRemarks(const QJsonArray &remL)
{
    std::vector<QString> rems;
    rems.reserve(remL.size());
    for (const auto &remV : remL) {
        const auto remObj = remV.toObject();
        rems.push_back(remObj.value(QLatin1String("txtN")).toString());
    }
    return rems;
}

static QStringList parseMessageList(const QJsonObject &obj, const std::vector<QString> &remarks)
{
    const auto msgL = obj.value(QLatin1String("msgL")).toArray();
    QStringList notes;
    for (const auto &msgV : msgL) {
        const auto msgObj = msgV.toObject();
        const auto remX = msgObj.value(QLatin1String("remX")).toInt();
        if (static_cast<size_t>(remX) >= remarks.size()) {
            qCDebug(Log) << "Invalid remark index:" << remX;
            continue;
        }
        const auto rem = remarks[remX];
        if (rem.isEmpty()) {
            continue;
        }
        notes.push_back(rem);
    }
    return notes;
}

std::vector<Location> HafasMgateParser::parseLocations(const QJsonArray &locL) const
{
    std::vector<Location> locs;
    locs.reserve(locL.size());
    for (const auto &locV : locL) {
        const auto locObj = locV.toObject();

        // resolve references to the master location
        const auto masterIdx = locObj.value(QLatin1String("mMastLocX")).toInt(-1);
        if (masterIdx >= 0 && masterIdx < (int)locs.size()) {
            locs.push_back(locs[masterIdx]);
            continue;
        }

        Location loc;
        loc.setName(locObj.value(QLatin1String("name")).toString());
        setLocationIdentifier(loc, locObj.value(QLatin1String("extId")).toString());
        const auto coordObj = locObj.value(QLatin1String("crd")).toObject();
        loc.setCoordinate(coordObj.value(QLatin1String("y")).toDouble() / 1000000.0, coordObj.value(QLatin1String("x")).toDouble() / 1000000.0);
        locs.push_back(loc);
    }
    return locs;
}

std::vector<Line> HafasMgateParser::parseLines(const QJsonArray &prodL, const std::vector<Ico> &icos) const
{
    std::vector<Line> lines;
    lines.reserve(prodL.size());
    for (const auto &prodV : prodL) {
        const auto prodObj = prodV.toObject();
        Line line;
        line.setName(prodObj.value(QLatin1String("name")).toString());
        line.setMode(parseLineMode(prodObj.value(QLatin1String("cls")).toInt()));

        const auto icoIdx = prodObj.value(QLatin1String("icoX")).toInt();
        if ((unsigned int)icoIdx < icos.size()) {
            line.setColor(icos[icoIdx].bg);
            line.setTextColor(icos[icoIdx].fg);
        }

        lines.push_back(line);
    }

    return lines;
}

std::vector<Departure> HafasMgateParser::parseStationBoardResponse(const QJsonObject &obj) const
{
    const auto commonObj = obj.value(QLatin1String("common")).toObject();
    const auto icos = parseIcos(commonObj.value(QLatin1String("icoL")).toArray());
    const auto locs = parseLocations(commonObj.value(QLatin1String("locL")).toArray());
    const auto lines = parseLines(commonObj.value(QLatin1String("prodL")).toArray(), icos);
    const auto remarks = parseRemarks(commonObj.value(QLatin1String("remL")).toArray());

    std::vector<Departure> res;
    const auto jnyL = obj.value(QLatin1String("jnyL")).toArray();
    res.reserve(jnyL.size());

    for (const auto &jny : jnyL) {
        const auto jnyObj = jny.toObject();
        const auto stbStop = jnyObj.value(QLatin1String("stbStop")).toObject();

        Departure dep;
        Route route;
        route.setDirection(jnyObj.value(QLatin1String("dirTxt")).toString());
        const auto lineIdx = jnyObj.value(QLatin1String("prodX")).toInt(-1);
        if (lineIdx >= 0 && (unsigned int)lineIdx < lines.size()) {
            route.setLine(lines[lineIdx]);
        }

        const auto dateStr = jnyObj.value(QLatin1String("date")).toString();
        dep.setScheduledDepartureTime(parseDateTime(dateStr, stbStop.value(QLatin1String("dTimeS")), stbStop.value(QLatin1String("dTZOffset"))));
        dep.setExpectedDepartureTime(parseDateTime(dateStr, stbStop.value(QLatin1String("dTimeR")), stbStop.value(QLatin1String("dTZOffset"))));
        dep.setScheduledArrivalTime(parseDateTime(dateStr, stbStop.value(QLatin1String("aTimeS")), stbStop.value(QLatin1String("aTZOffset"))));
        dep.setExpectedArrivalTime(parseDateTime(dateStr, stbStop.value(QLatin1String("aTimeR")),  stbStop.value(QLatin1String("aTZOffset"))));

        dep.setScheduledPlatform(stbStop.value(QLatin1String("dPlatfS")).toString());
        dep.setExpectedPlatform(stbStop.value(QLatin1String("dPlatfR")).toString());
        if (dep.scheduledPlatform().isEmpty()) {
            dep.setScheduledPlatform(stbStop.value(QLatin1String("aPlatfS")).toString());
        }
        if (dep.expectedPlatform().isEmpty()) {
            dep.setExpectedPlatform(stbStop.value(QLatin1String("aPlatfR")).toString());
        }

        const auto startLocIdx = stbStop.value(QLatin1String("locX")).toInt(-1);
        if (startLocIdx >= 0 && (unsigned int)startLocIdx < locs.size()) {
            dep.setStopPoint(locs[startLocIdx]);
        }

        const auto stopL = jnyObj.value(QLatin1String("stopL")).toArray();
        bool foundLoop = false; // check for loops, circular lines have no destination
        for (int i = 1; i < stopL.size() && !foundLoop; ++i) {
            const auto locX = stopL.at(i).toObject().value(QLatin1String("locX")).toInt(-1);
            if (locX == startLocIdx) {
                foundLoop = true;
            }
        }
        const auto destLocX = stopL.last().toObject().value(QLatin1String("locX")).toInt(-1);
        if (!foundLoop && destLocX >= 0 && (unsigned int)destLocX < locs.size() && startLocIdx != destLocX) {
            route.setDestination(locs[destLocX]);
        }

        dep.addNotes(parseMessageList(jnyObj, remarks));
        dep.setRoute(route);
        res.push_back(dep);
    }

    return res;
}

bool HafasMgateParser::parseError(const QJsonObject& obj) const
{
    if (obj.value(QLatin1String("err")).toString() != QLatin1String("OK")) {
        m_error = Reply::NotFoundError;
        m_errorMsg = obj.value(QLatin1String("errTxt")).toString();
        return false;
    }

    m_error = Reply::NoError;
    m_errorMsg.clear();
    return true;
}


std::vector<Departure> HafasMgateParser::parseDepartures(const QByteArray &data) const
{
    const auto topObj = QJsonDocument::fromJson(data).object();
    //qDebug().noquote() << QJsonDocument(topObj).toJson();
    const auto svcResL = topObj.value(QLatin1String("svcResL")).toArray();

    for (const auto &v : svcResL) {
        const auto obj = v.toObject();
        if (obj.value(QLatin1String("meth")).toString() == QLatin1String("StationBoard")) {
            if (parseError(obj)) {
                return parseStationBoardResponse(obj.value(QLatin1String("res")).toObject());
            }
            return {};
        }
    }

    return {};
}

std::vector<Location> HafasMgateParser::parseLocations(const QByteArray &data) const
{
    const auto topObj = QJsonDocument::fromJson(data).object();
    const auto svcResL = topObj.value(QLatin1String("svcResL")).toArray();

    for (const auto &v : svcResL) {
        const auto obj = v.toObject();
        const auto meth = obj.value(QLatin1String("meth")).toString();
        if (meth == QLatin1String("LocMatch") || meth == QLatin1String("LocGeoPos")) {
            if (parseError(obj)) {
                const auto resObj = obj.value(QLatin1String("res")).toObject();
                if (resObj.contains(QLatin1String("locL"))) {
                    return parseLocations(resObj.value(QLatin1String("locL")).toArray());
                }
                if (resObj.contains(QLatin1String("match"))) {
                    return parseLocations(resObj.value(QLatin1String("match")).toObject().value(QLatin1String("locL")).toArray());
                }
                qCDebug(Log).noquote() << "Failed to parse location query response:" << QJsonDocument(obj).toJson();
                return {};
            }
            return {};
        }
    }

    return {};
}

std::vector<Journey> HafasMgateParser::parseJourneys(const QByteArray &data) const
{
    const auto topObj = QJsonDocument::fromJson(data).object();
    const auto svcResL = topObj.value(QLatin1String("svcResL")).toArray();

    for (const auto &v : svcResL) {
        const auto obj = v.toObject();
        if (obj.value(QLatin1String("meth")).toString() == QLatin1String("TripSearch")) {
            if (parseError(obj)) {
                return parseTripSearch(obj.value(QLatin1String("res")).toObject());
            }
            return {};
        }
    }

    return {};
}

std::vector<Journey> HafasMgateParser::parseTripSearch(const QJsonObject &obj) const
{
    const auto commonObj = obj.value(QLatin1String("common")).toObject();
    const auto icos = parseIcos(commonObj.value(QLatin1String("icoL")).toArray());
    const auto locs = parseLocations(commonObj.value(QLatin1String("locL")).toArray());
    const auto lines = parseLines(commonObj.value(QLatin1String("prodL")).toArray(), icos);
    const auto remarks = parseRemarks(commonObj.value(QLatin1String("remL")).toArray());

    std::vector<Journey> res;
    const auto outConL = obj.value(QLatin1String("outConL")).toArray();
    res.reserve(outConL.size());

    for (const auto &outConV: outConL) {
        const auto outCon = outConV.toObject();

        const auto dateStr = outCon.value(QLatin1String("date")).toString();

        const auto secL = outCon.value(QLatin1String("secL")).toArray();
        std::vector<JourneySection> sections;
        sections.reserve(secL.size());


        for (const auto &secV : secL) {
            const auto secObj = secV.toObject();
            JourneySection section;

            const auto dep = secObj.value(QLatin1String("dep")).toObject();
            section.setScheduledDepartureTime(parseDateTime(dateStr, dep.value(QLatin1String("dTimeS")), dep.value(QLatin1String("dTZOffset"))));
            section.setExpectedDepartureTime(parseDateTime(dateStr, dep.value(QLatin1String("dTimeR")), dep.value(QLatin1String("dTZOffset"))));
            auto locIdx = dep.value(QLatin1String("locX")).toInt();
            if ((unsigned int)locIdx < locs.size()) {
                section.setFrom(locs[locIdx]);
            }
            section.setScheduledDeparturePlatform(dep.value(QLatin1String("dPlatfS")).toString());
            section.setExpectedDeparturePlatform(dep.value(QLatin1String("dPlatfR")).toString());
            if (dep.value(QLatin1String("dCncl")).toBool()) {
                section.setDisruptionEffect(Disruption::NoService);
            }

            const auto arr = secObj.value(QLatin1String("arr")).toObject();
            section.setScheduledArrivalTime(parseDateTime(dateStr, arr.value(QLatin1String("aTimeS")), arr.value(QLatin1String("aTZOffset"))));
            section.setExpectedArrivalTime(parseDateTime(dateStr, arr.value(QLatin1String("aTimeR")), arr.value(QLatin1String("aTZOffset"))));
            locIdx = arr.value(QLatin1String("locX")).toInt();
            if ((unsigned int)locIdx < locs.size()) {
                section.setTo(locs[locIdx]);
            }
            section.setScheduledArrivalPlatform(arr.value(QLatin1String("aPlatfS")).toString());
            section.setExpectedArrivalPlatform(arr.value(QLatin1String("aPlatfR")).toString());
            if (arr.value(QLatin1String("aCncl")).toBool()) {
                section.setDisruptionEffect(Disruption::NoService);
            }

            const auto typeStr = secObj.value(QLatin1String("type")).toString();
            if (typeStr == QLatin1String("JNY")) {
                section.setMode(JourneySection::PublicTransport);

                const auto jnyObj = secObj.value(QLatin1String("jny")).toObject();
                Route route;
                route.setDirection(jnyObj.value(QLatin1String("dirTxt")).toString());
                const auto lineIdx = jnyObj.value(QLatin1String("prodX")).toInt();
                if ((unsigned int)lineIdx < lines.size()) {
                    route.setLine(lines[lineIdx]);
                }
                section.setRoute(route);

                if (jnyObj.value(QLatin1String("isCncl")).toBool()) {
                    section.setDisruptionEffect(Disruption::NoService);
                }

                section.addNotes(parseMessageList(jnyObj, remarks));
            } else if (typeStr == QLatin1String("WALK")) {
                section.setMode(JourneySection::Walking);
            } else if (typeStr == QLatin1String("TRSF")) {
                section.setMode(JourneySection::Transfer);
            }

            sections.push_back(section);
        }

        Journey journey;
        journey.setSections(std::move(sections));
        res.push_back(journey);
    }

    return res;
}

QDateTime HafasMgateParser::parseDateTime(const QString &date, const QJsonValue &time, const QJsonValue &tzOffset)
{
    const auto timeStr = time.toString();
    if (date.isEmpty() || timeStr.isEmpty()) {
        return {};
    }

    int dayOffset = 0;
    if (timeStr.size() > 6) {
        dayOffset = timeStr.leftRef(timeStr.size() - 6).toInt();
    }

    auto dt = QDateTime::fromString(date + timeStr.rightRef(6), QStringLiteral("yyyyMMddhhmmss"));
    dt = dt.addDays(dayOffset);
    if (!tzOffset.isNull() && !tzOffset.isUndefined()) {
        dt.setOffsetFromUtc(tzOffset.toInt() * 60);
    }

    return dt;
}

/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasmgateparser.h"
#include "logging.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Line>
#include <KPublicTransport/Stopover>

#include <QColor>
#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace KPublicTransport;

// REM or HIM elements
struct Message {
    QString text;
    Disruption::Effect effect = Disruption::NormalService;
};

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

static const struct {
    const char *type;
    const char *code;
} ignored_remarks[] = {
    { "A", "1" }, // different name formats for the line, used by SBB
    { "A", "2" },
    { "A", "3" },
    { "A", "4" }, // same as above, containing product, line number and journey number
    { "A", "OPERATOR" }, // operator information should be a dedicated field if we ever need it
    { "H", "wagenstand_v2" }, // contains a pointless note about checking trip details
    { "I", "FD" }, // SBB line number?
    { "I", "JF" }, // SBB: JSON structure containing the coach layout - TODO how can we expose that via our vehicle layout API?
    { "I", "RN" }, // SBB: some unknown number for buses
    { "I", "TC" }, // SBB: some unknown number for buses
    { "I", "XC" }, // SBB: some XML structure of unknown content
    { "I", "XG" }, // SBB: some XML structure of unknown content
    { "I", "XP" }, // SBB: some XML structure of unknown content
    { "I", "XT" }, // SBB: some XML structure of unknown content
};

static std::vector<Message> parseRemarks(const QJsonArray &remL)
{
    std::vector<Message> rems;
    rems.reserve(remL.size());
    for (const auto &remV : remL) {
        const auto remObj = remV.toObject();

        const auto type = remObj.value(QLatin1String("type")).toString();
        const auto code = remObj.value(QLatin1String("code")).toString();
        bool skip = false;
        for (const auto &ignored_remark : ignored_remarks) {
            if (type == QLatin1String(ignored_remark.type) && code == QLatin1String(ignored_remark.code)) {
                skip = true;
                break;
            }
        }
        if (skip) {
            rems.push_back({}); // make sure the indices still match!
            continue;
        }

        Message m;
        m.text = remObj.value(QLatin1String("txtN")).toString();
        if (code == QLatin1String("text.realtime.stop.cancelled")) {
            m.effect = Disruption::NoService;
        }
        rems.push_back(std::move(m));
    }
    return rems;
}

static std::vector<Message> parseWarnings(const QJsonArray &himL)
{
    std::vector<Message> hims;
    hims.reserve(himL.size());
    for (const auto &himV : himL) {
        const auto himObj = himV.toObject();
        Message m;
        m.text = himObj.value(QLatin1String("head")).toString() + QLatin1Char('\n')
               + himObj.value(QLatin1String("lead")).toString() + QLatin1Char('\n')
               + himObj.value(QLatin1String("text")).toString();
        hims.push_back(m);
    }
    return hims;
}

template <typename T>
static void parseMessageList(T &elem, const QJsonObject &obj, const std::vector<Message> &remarks, const std::vector<Message> &warnings)
{
    const auto msgL = obj.value(QLatin1String("msgL")).toArray();
    QStringList notes;
    for (const auto &msgV : msgL) {
        const auto msgObj = msgV.toObject();
        const auto msgType = msgObj.value(QLatin1String("type")).toString();

        const std::vector<Message> *source = nullptr;
        if (msgType == QLatin1String("REM")) {
            source = &remarks;
        } else if (msgType == QLatin1String("HIM")) {
            source = &warnings;
        } else {
            qDebug() << "unsupported message type:" << msgType;
            continue;
        }

        const auto remX = msgObj.value(QLatin1String("remX")).toInt();
        if (static_cast<size_t>(remX) >= source->size()) {
            qCDebug(Log) << "Invalid message index:" << remX << msgType;
            continue;
        }
        const auto msg = (*source)[remX];
        elem.addNote(msg.text);
        if (msg.effect == Disruption::NoService) {
            elem.setDisruptionEffect(msg.effect);
        }
    }
}

static constexpr const Load::Category load_value_map[] = {
    Load::Unknown,
    Load::Low, // 1
    Load::Medium, // 2
    Load::High, // 3
    Load::Full // 4
};

static std::vector<LoadInfo> parseLoadInformation(const QJsonArray &tcocL)
{
    std::vector<LoadInfo> loadInfos;
    loadInfos.reserve(tcocL.size());
    for (const auto &tcocV : tcocL) {
        const auto tcocObj = tcocV.toObject();
        LoadInfo loadInfo;
        const auto r = qBound(0, tcocObj.value(QLatin1String("r")).toInt(), 4);
        loadInfo.setLoad(load_value_map[r]);
        const auto c = tcocObj.value(QLatin1String("c")).toString();
        loadInfo.setSeatingClass(c == QLatin1String("FIRST") ? QStringLiteral("1") : QStringLiteral("2"));
        loadInfos.push_back(std::move(loadInfo));
    }
    return loadInfos;
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
        loc.setType(locObj.value(QLatin1String("type")).toString() == QLatin1Char('S') ? Location::Stop : Location::Place);
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

std::vector<Stopover> HafasMgateParser::parseStationBoardResponse(const QJsonObject &obj) const
{
    const auto commonObj = obj.value(QLatin1String("common")).toObject();
    const auto icos = parseIcos(commonObj.value(QLatin1String("icoL")).toArray());
    const auto locs = parseLocations(commonObj.value(QLatin1String("locL")).toArray());
    const auto lines = parseLines(commonObj.value(QLatin1String("prodL")).toArray(), icos);
    const auto remarks = parseRemarks(commonObj.value(QLatin1String("remL")).toArray());
    const auto warnings = parseWarnings(commonObj.value(QLatin1String("himL")).toArray());

    std::vector<Stopover> res;
    const auto jnyL = obj.value(QLatin1String("jnyL")).toArray();
    res.reserve(jnyL.size());

    for (const auto &jny : jnyL) {
        const auto jnyObj = jny.toObject();
        const auto stbStop = jnyObj.value(QLatin1String("stbStop")).toObject();

        Stopover dep;
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
        if (stbStop.value(QLatin1String("dCncl")).toBool()) {
            dep.setDisruptionEffect(Disruption::NoService);
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

        parseMessageList(dep, jnyObj, remarks, warnings);
        parseMessageList(dep, stbStop, remarks, warnings);
        dep.setRoute(route);
        res.push_back(dep);
    }

    return res;
}

bool HafasMgateParser::parseError(const QJsonObject& obj) const
{
    const auto err = obj.value(QLatin1String("err")).toString();
    if (!err.isEmpty() && err != QLatin1String("OK")) {
        m_error = err == QLatin1String("LOCATION") ? Reply::NotFoundError : Reply::UnknownError;
        m_errorMsg = obj.value(QLatin1String("errTxt")).toString();
        if (m_errorMsg.isEmpty()) {
            m_errorMsg = err;
        }
        return false;
    }

    m_error = Reply::NoError;
    m_errorMsg.clear();
    return true;
}


std::vector<Stopover> HafasMgateParser::parseDepartures(const QByteArray &data) const
{
    const auto topObj = QJsonDocument::fromJson(data).object();
    if (!parseError(topObj)) {
        return {};
    }

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
    if (!parseError(topObj)) {
        return {};
    }

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
    if (!parseError(topObj)) {
        return {};
    }

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

static std::vector<LoadInfo> parseLoad(const QJsonObject &obj, const std::vector<LoadInfo> &loadInfos)
{
    const auto dTrnCmpSX = obj.value(QLatin1String("dTrnCmpSX")).toObject();
    const auto tcocX = dTrnCmpSX.value(QLatin1String("tcocX")).toArray();
    std::vector<LoadInfo> load;
    load.reserve(tcocX.size());
    for (const auto &v : tcocX) {
        const auto i = v.toInt();
        if (i >= 0 && i < (int)loadInfos.size()) {
            load.push_back(loadInfos[i]);
        }
    }
    return load;
}

std::vector<Journey> HafasMgateParser::parseTripSearch(const QJsonObject &obj) const
{
    const auto commonObj = obj.value(QLatin1String("common")).toObject();
    const auto icos = parseIcos(commonObj.value(QLatin1String("icoL")).toArray());
    const auto locs = parseLocations(commonObj.value(QLatin1String("locL")).toArray());
    const auto lines = parseLines(commonObj.value(QLatin1String("prodL")).toArray(), icos);
    const auto remarks = parseRemarks(commonObj.value(QLatin1String("remL")).toArray());
    const auto warnings = parseWarnings(commonObj.value(QLatin1String("himL")).toArray());
    const auto loadInfos = parseLoadInformation(commonObj.value(QLatin1String("tcocL")).toArray());

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

                const auto stopL = jnyObj.value(QLatin1String("stopL")).toArray();
                if (stopL.size() > 2) { // we don't want departure/arrival stops in here
                    std::vector<Stopover> stops;
                    stops.reserve(stopL.size() - 2);
                    for (auto it = std::next(stopL.begin()); it != std::prev(stopL.end()); ++it) {
                        const auto stopObj = (*it).toObject();
                        // TODO how does this look for individual stop skips during disruptions?
                        Stopover stop;
                        const auto locIdx = stopObj.value(QLatin1String("locX")).toInt();
                        if ((unsigned int)locIdx < locs.size()) {
                            stop.setStopPoint(locs[locIdx]);
                        }
                        stop.setScheduledDepartureTime(parseDateTime(dateStr, stopObj.value(QLatin1String("dTimeS")), stopObj.value(QLatin1String("dTZOffset"))));
                        stop.setExpectedDepartureTime(parseDateTime(dateStr, stopObj.value(QLatin1String("dTimeR")), stopObj.value(QLatin1String("dTZOffset"))));
                        stop.setScheduledArrivalTime(parseDateTime(dateStr, stopObj.value(QLatin1String("aTimeS")), stopObj.value(QLatin1String("aTZOffset"))));
                        stop.setExpectedArrivalTime(parseDateTime(dateStr, stopObj.value(QLatin1String("aTimeR")), stopObj.value(QLatin1String("aTZOffset"))));
                        stop.setScheduledPlatform(stopObj.value(QLatin1String("dPlatfS")).toString());
                        stop.setExpectedPlatform(stopObj.value(QLatin1String("dPlatfR")).toString());
                        stop.setLoadInformation(parseLoad(stopObj, loadInfos));
                        stops.push_back(stop);
                    }
                    section.setIntermediateStops(std::move(stops));
                }

                parseMessageList(section, jnyObj, remarks, warnings);
                section.setLoadInformation(parseLoad(dep, loadInfos));
            } else if (typeStr == QLatin1String("WALK")) {
                section.setMode(JourneySection::Walking);
                section.setDistance(secObj.value(QLatin1String("gis")).toObject().value(QLatin1String("dist")).toInt());
            } else if (typeStr == QLatin1String("TRSF")) {
                section.setMode(JourneySection::Transfer);
                section.setDistance(secObj.value(QLatin1String("gis")).toObject().value(QLatin1String("dist")).toInt());
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

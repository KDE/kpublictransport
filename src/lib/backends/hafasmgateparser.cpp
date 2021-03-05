/*
    SPDX-FileCopyrightText: 2018 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "hafasmgateparser.h"
#include "hafasvehiclelayoutparser.h"
#include "logging.h"
#include "datatypes/loadutil_p.h"
#include "geo/polylinedecoder_p.h"

#include <KPublicTransport/Journey>
#include <KPublicTransport/Line>
#include <KPublicTransport/Platform>
#include <KPublicTransport/Stopover>
#include <KPublicTransport/Vehicle>

#include <QColor>
#include <QDateTime>
#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

using namespace KPublicTransport;

// REM or HIM elements
struct Message {
    QVariant content;
    Disruption::Effect effect = Disruption::NormalService;
    LoadInfo loadInfo;
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

static constexpr const Load::Category load_value_map[] = {
    Load::Unknown,
    Load::Low, // 1
    Load::Medium, // 2
    Load::High, // 3
    Load::Full // 4
};

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
    { "I", "RN" }, // SBB: some unknown number for buses
    { "I", "TC" }, // SBB: some unknown number for buses
    { "I", "XC" }, // SBB: some XML structure of unknown content
    { "I", "XG" }, // SBB: some XML structure of unknown content
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
        if (type == QLatin1Char('I') && code == QLatin1String("JF")) {
            m.content = HafasVehicleLayoutParser::parseTrainFormation(remObj.value(QLatin1String("txtN")).toString().toUtf8());
        } else if (type == QLatin1Char('I') && code == QLatin1String("XP")) {
            m.content = HafasVehicleLayoutParser::parsePlatformSectors(remObj.value(QLatin1String("txtN")).toString().toUtf8());
        } else if (type == QLatin1Char('A') && (code.startsWith(QLatin1String("text.occup.loc.")) || code.startsWith(QLatin1String("text.occup.jny.")))) {
            static QRegularExpression rx(QStringLiteral("\\.(max|1st|2nd)\\.1([1-4])$"));
            const auto match = rx.match(code);
            if (match.hasMatch()) {
                m.loadInfo.setLoad(load_value_map[match.captured(2).toInt()]);
                if (match.captured(1) != QLatin1String("max")) {
                    m.loadInfo.setSeatingClass(match.captured(1).left(1));
                }
            } else {
                m.content = remObj.value(QLatin1String("txtN")).toString();
            }
        } else {
            // generic text
            m.content = remObj.value(QLatin1String("txtN")).toString();
            if (code == QLatin1String("text.realtime.stop.cancelled") || code == QLatin1String("text.realtime.stop.entry.exit.disabled")) {
                m.effect = Disruption::NoService;
            }
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
        m.content = QString(himObj.value(QLatin1String("head")).toString() + QLatin1Char('\n')
               + himObj.value(QLatin1String("lead")).toString() + QLatin1Char('\n')
               + himObj.value(QLatin1String("text")).toString());
        hims.push_back(m);
    }
    return hims;
}

template <typename Func>
static void processMessageList(const QJsonObject &obj, const std::vector<Message> &remarks, const std::vector<Message> &warnings, Func func)
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
        const auto &msg = (*source)[remX];
        func(msg, msgObj);
    }
}

template <typename T>
static void applyMessage(T &elem, const Message &msg)
{
    if (msg.content.type() == QVariant::String) {
        elem.addNote(msg.content.toString());
    }
    if (msg.effect == Disruption::NoService) {
        elem.setDisruptionEffect(msg.effect);
    }
    if (msg.loadInfo.load() != Load::Unknown) {
        elem.setLoadInformation(LoadUtil::merge(elem.loadInformation(), {msg.loadInfo}));
    }
}

template <typename T>
static void parseMessageList(T &elem, const QJsonObject &obj, const std::vector<Message> &remarks, const std::vector<Message> &warnings)
{
    processMessageList(obj, remarks, warnings, [&elem](const Message &msg, const QJsonObject&) {
        applyMessage(elem, msg);
    });
}

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

static void setPlatformLayout(Stopover &stop, const Platform &platform) { stop.setPlatformLayout(platform); }
static void setPlatformLayout(JourneySection &jny, const Platform &platform) { jny.setDeparturePlatformLayout(platform); }
static void setVehicleLayout(Stopover &stop, const Vehicle &vehicle) { stop.setVehicleLayout(vehicle); }
static void setVehicleLayout(JourneySection &jny, const Vehicle &vehicle) { jny.setDepartureVehicleLayout(vehicle); }

template <typename T>
static void parseTrainComposition(const QJsonObject &obj, T &result,
                                  const std::vector<LoadInfo> &loadInfos,
                                  const std::vector<Platform> &platforms,
                                  const std::vector<Vehicle> &vehicles)
{
    const auto dTrnCmpSX = obj.value(QLatin1String("dTrnCmpSX")).toObject();

    // load
    const auto tcocX = dTrnCmpSX.value(QLatin1String("tcocX")).toArray();
    std::vector<LoadInfo> load;
    load.reserve(tcocX.size());
    for (const auto &v : tcocX) {
        const auto i = v.toInt();
        if (i >= 0 && i < (int)loadInfos.size()) {
            load.push_back(loadInfos[i]);
        }
    }
    result.setLoadInformation(LoadUtil::merge(std::move(load), result.loadInformation()));

    // platform
    const auto tcpdX = dTrnCmpSX.value(QLatin1String("tcpdX")).toInt(-1);
    if (tcpdX >= 0 && tcpdX < (int)platforms.size()) {
        setPlatformLayout(result, platforms[tcpdX]);
    }

    // vehicle
    const auto stcGX = dTrnCmpSX.value(QLatin1String("stcGX")).toArray();
    const auto vehicleIdx = stcGX.empty() ? -1 : stcGX.at(0).toInt(-1);
    if (vehicleIdx >= 0 && vehicleIdx < (int)vehicles.size()) {
        setVehicleLayout(result, vehicles[vehicleIdx]);
    }
}

static std::vector<Path> parsePaths(const QJsonArray &polyL, const std::vector<Location> &locs)
{
    std::vector<Path> paths;
    paths.reserve(polyL.size());
    for (const auto &polyV : polyL) {
        const auto polyObj = polyV.toObject();

        // path coordinate index to location mapping
        const auto ppLocRefL = polyObj.value(QLatin1String("ppLocRefL")).toArray();
        // 2-dimensional differential encoded coordinates
        const auto crdEncYX = polyObj.value(QLatin1String("crdEncYX")).toString().toUtf8();
        PolylineDecoder<2> crdEncYXDecoder(crdEncYX.constData());
        // crdEncDist: 1-dimensional integer values with differential encoding containing distances in meters
        // crdEncZ: 1-dimensional, always 0?
        // crdEncS: 1-dimensional, unknown meaning, but very low-entropy data
        // crdEncF: 1-dimensional, always 0?

        std::vector<PathSection> sections;
        sections.reserve(ppLocRefL.size() - 1);
        int prevPpIdx = 0;
        QPointF prevCoord;
        for (const auto ppLocRefV : ppLocRefL) {
            const auto ppLocRef = ppLocRefV.toObject();
            const auto ppIdx = ppLocRef.value(QLatin1String("ppIdx")).toInt();
            if (ppIdx == 0 || ppIdx < prevPpIdx) {
                continue;
            }

            QPolygonF poly;
            poly.reserve(prevPpIdx - ppIdx + 2);
            if (!prevCoord.isNull()) {
                poly.push_back(prevCoord);
            }
            crdEncYXDecoder.readPolygon(poly, ppIdx - prevPpIdx + 1);
            if (!poly.empty()) {
                prevCoord = poly.back();
            }

            PathSection section;
            section.setPath(std::move(poly));
            prevPpIdx = ppIdx;

            const auto locX = ppLocRef.value(QLatin1String("locX")).toInt();
            if (locX >= 0 && locX < (int)locs.size()) {
                section.setDescription(locs[locX].name());
            }

            sections.push_back(std::move(section));
        }

        Path path;
        path.setSections(std::move(sections));
        paths.push_back(std::move(path));
    }
    return paths;
}

static Path parsePolyG(const QJsonObject &obj, const std::vector<Path> &paths)
{
    const auto polyG = obj.value(QLatin1String("polyG")).toObject();
    const auto polyXL = polyG.value(QLatin1String("polyXL")).toArray();
    if (polyXL.size() != 1) {
        return {};
    }
    const auto polyX = polyXL.at(0).toInt();
    if (polyX >= 0 && polyX < (int)paths.size()) {
        return paths[polyX];
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
    const auto warnings = parseWarnings(commonObj.value(QLatin1String("himL")).toArray());
    const auto loadInfos = parseLoadInformation(commonObj.value(QLatin1String("tcocL")).toArray());
    const auto paths = parsePaths(commonObj.value(QLatin1String("polyL")).toArray(), locs);
    const auto platforms = HafasVehicleLayoutParser::parsePlatforms(commonObj);
    const auto vehicles = HafasVehicleLayoutParser::parseVehicleLayouts(commonObj);

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
            const auto fromIdx = dep.value(QLatin1String("locX")).toInt(-1);
            if ((unsigned int)fromIdx < locs.size()) {
                section.setFrom(locs[fromIdx]);
            }
            section.setScheduledDeparturePlatform(dep.value(QLatin1String("dPlatfS")).toString());
            section.setExpectedDeparturePlatform(dep.value(QLatin1String("dPlatfR")).toString());
            if (dep.value(QLatin1String("dCncl")).toBool()) {
                section.setDisruptionEffect(Disruption::NoService);
            }

            const auto arr = secObj.value(QLatin1String("arr")).toObject();
            section.setScheduledArrivalTime(parseDateTime(dateStr, arr.value(QLatin1String("aTimeS")), arr.value(QLatin1String("aTZOffset"))));
            section.setExpectedArrivalTime(parseDateTime(dateStr, arr.value(QLatin1String("aTimeR")), arr.value(QLatin1String("aTZOffset"))));
            const auto toIdx = arr.value(QLatin1String("locX")).toInt(-1);
            if ((unsigned int)toIdx < locs.size()) {
                section.setTo(locs[toIdx]);
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
                        if (stopObj.value(QLatin1String("aCncl")).toBool() || stopObj.value(QLatin1String("dCncl")).toBool()) {
                            stop.setDisruptionEffect(Disruption::NoService);
                        }
                        parseMessageList(stop, stopObj, remarks, warnings);
                        processMessageList(jnyObj, remarks, warnings, [&stop, locIdx](const Message &msg, const QJsonObject &msgObj) {
                            const auto fromIdx = msgObj.value(QLatin1String("fLocX")).toInt(-1);
                            const auto toIdx = msgObj.value(QLatin1String("tLocX")).toInt(-1);
                            if (fromIdx != toIdx || fromIdx != locIdx) {
                                return;
                            }
                            if (msg.content.userType() == qMetaTypeId<Platform>()) {
                                stop.setPlatformLayout(Platform::merge(stop.platformLayout(), msg.content.value<Platform>()));
                            } else if (msg.content.userType() == qMetaTypeId<Vehicle>()) {
                                stop.setVehicleLayout(Vehicle::merge(stop.vehicleLayout(), msg.content.value<Vehicle>()));
                            }
                            applyMessage(stop, msg);
                        });
                        parseTrainComposition(stopObj, stop, loadInfos, platforms, vehicles);
                        stops.push_back(stop);
                    }
                    section.setIntermediateStops(std::move(stops));
                }

                processMessageList(jnyObj, remarks, warnings, [&section, fromIdx, toIdx](const Message &msg, const QJsonObject &msgObj) {
                    const auto from = msgObj.value(QLatin1String("fLocX")).toInt(-1);
                    const auto to = msgObj.value(QLatin1String("tLocX")).toInt(-1);
                    if (from >= 0 && to >= 0 && from != fromIdx && toIdx != to && from == to) {
                        return;
                    }
                    if (msg.content.userType() == qMetaTypeId<Platform>()) {
                        if (from == to && to == toIdx) {
                            section.setArrivalPlatformLayout(Platform::merge(section.arrivalPlatformLayout(), msg.content.value<Platform>()));
                        } else {
                            section.setDeparturePlatformLayout(Platform::merge(section.departurePlatformLayout(), msg.content.value<Platform>()));
                        }
                    } else if (msg.content.userType() == qMetaTypeId<Vehicle>()) {
                        if (from == to && to == toIdx) {
                            section.setArrivalVehicleLayout(Vehicle::merge(section.arrivalVehicleLayout(), msg.content.value<Vehicle>()));
                        } else {
                            section.setDepartureVehicleLayout(Vehicle::merge(section.departureVehicleLayout(), msg.content.value<Vehicle>()));
                        }
                    }
                    applyMessage(section, msg);
                });
                parseTrainComposition(dep, section, loadInfos, platforms, vehicles);
                section.setPath(parsePolyG(jnyObj, paths));
            } else if (typeStr == QLatin1String("WALK") || typeStr == QLatin1String("TRSF")) {
                const auto gis = secObj.value(QLatin1String("gis")).toObject();
                section.setDistance(gis.value(QLatin1String("dist")).toInt());
                section.setPath(parsePolyG(gis, paths));
                section.setMode(typeStr == QLatin1String("WALK") ? JourneySection::Walking : JourneySection::Transfer);
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

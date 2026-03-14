/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "mode.h"

#include <datatypes/json_p.h>

#include <QJsonArray>
#include <QJsonObject>
#include <QMetaEnum>

using namespace Qt::Literals;
using namespace KPublicTransport;

template <typename ModeT>
struct ModeMap {
    ModeT siriMode;
    Line::Mode mode;
};

template <typename T>
static constexpr const T mode_map = {};

// complete mapping between SIRI modes and our modes
template <>
constexpr const ModeMap<Siri::Mode::VehicleMode> mode_map<Siri::Mode::VehicleMode>[] = {
    { Siri::Mode::VehicleMode::air, Line::Air },
    { Siri::Mode::VehicleMode::bus, Line::Bus },
    { Siri::Mode::VehicleMode::cableway, Line::AerialLift },
    { Siri::Mode::VehicleMode::water, Line::Ferry },
    { Siri::Mode::VehicleMode::funicular, Line::Funicular },
    { Siri::Mode::VehicleMode::lift, Line::AerialLift },
    { Siri::Mode::VehicleMode::rail, Line::Train },
    { Siri::Mode::VehicleMode::snowAndIce, Line::Unknown },
    { Siri::Mode::VehicleMode::metro, Line::Metro },
    { Siri::Mode::VehicleMode::taxi, Line::Taxi },
    { Siri::Mode::VehicleMode::tram, Line::Tramway },
    { Siri::Mode::VehicleMode::trolleybus, Line::Bus },
    { Siri::Mode::VehicleMode::monorail, Line::Train },
    { Siri::Mode::VehicleMode::coach, Line::Coach },
    { Siri::Mode::VehicleMode::other, Line::Unknown },
    { Siri::Mode::VehicleMode::unknown, Line::Unknown },
};

// partial maps between SIRI submodes and our modes, only containing deviations from the default
template<>
constexpr const ModeMap<Siri::Mode::BusSubmode> mode_map<Siri::Mode::BusSubmode>[] = {
    { Siri::Mode::BusSubmode::demandAndResponseBus, Line::Taxi },
};

template<>
constexpr const ModeMap<Siri::Mode::MetroSubmode> mode_map<Siri::Mode::MetroSubmode>[] = {
    { Siri::Mode::MetroSubmode::urbanRailway, Line::RapidTransit },
};

template <>
constexpr const ModeMap<Siri::Mode::RailSubmode> mode_map<Siri::Mode::RailSubmode>[] = {
    { Siri::Mode::RailSubmode::local, Line::LocalTrain },
    { Siri::Mode::RailSubmode::highSpeedRail, Line::LongDistanceTrain },
    { Siri::Mode::RailSubmode::suburbanRailway, Line::RapidTransit },
    { Siri::Mode::RailSubmode::regionalRail, Line::LocalTrain },
    { Siri::Mode::RailSubmode::longDistance, Line::LongDistanceTrain },
    { Siri::Mode::RailSubmode::international, Line::LongDistanceTrain },
    { Siri::Mode::RailSubmode::sleeperRailService, Line::LongDistanceTrain },
    { Siri::Mode::RailSubmode::nightRail, Line::LongDistanceTrain },
    { Siri::Mode::RailSubmode::airportLinkRail, Line::RapidTransit },
    { Siri::Mode::RailSubmode::railShuttle, Line::Shuttle },
};

template <>
constexpr const ModeMap<Siri::Mode::WaterSubmode> mode_map<Siri::Mode::WaterSubmode>[] = {
    { Siri::Mode::WaterSubmode::postBoat, Line::Boat },
    { Siri::Mode::WaterSubmode::airportBoatLink, Line::Boat },
    { Siri::Mode::WaterSubmode::sightseeingService, Line::Boat },
    { Siri::Mode::WaterSubmode::schoolBoat, Line::Boat },
    { Siri::Mode::WaterSubmode::riverBus, Line::Boat },
    { Siri::Mode::WaterSubmode::canalBarge, Line::Boat },
};

template <typename T>
[[nodiscard]] static T modeFromString(QStringView mode)
{
    auto me = QMetaEnum::fromType<T>();
    bool ok = false;
    const auto m = static_cast<T>(me.keyToValue(mode.toUtf8().constData(), &ok));
    return ok ? m : T::unknown;
}

static Line::Mode modeToMode(Siri::Mode::VehicleMode siriMode)
{
    const auto it = std::ranges::find_if(mode_map<Siri::Mode::VehicleMode>, [siriMode](const auto &m) { return m.siriMode == siriMode; });
    return (it == std::end(mode_map<Siri::Mode::VehicleMode>)) ? Line::Unknown : (*it).mode;
}

template <typename T>
[[nodiscard]] static std::optional<Line::Mode> submodeToMode(T mode)
{
    if constexpr (requires(T) { mode_map<T>[0]; }) {
        const auto it = std::ranges::find_if(mode_map<T>, [mode](const auto &m) { return m.siriMode == mode; });
        if (it == std::end(mode_map<T>)) {
            return {};
        }
        return (*it).mode;
    }
    return {};
}

Siri::Mode Siri::Mode::fromString(QStringView mode, QStringView subMode)
{
    Mode m(modeFromString<Siri::Mode::VehicleMode>(mode));
    m.m_submode = submodeFromString(detail::num<>(), subMode, m.mode());
    if (m.mode() == VehicleMode::unknown && m.hasSubmode()) {
        m.m_mode = std::visit([](auto &&m) -> VehicleMode { return modeForSubmode(m); }, *m.m_submode);
    }

    if (m.mode() == VehicleMode::unknown && (!mode.isEmpty() || !subMode.isEmpty()) && mode != QLatin1StringView(Mode::toString(VehicleMode::unknown))) {
        qDebug() << "unable to resolve SIRI mode:" << mode << subMode;
    }

    return m;
}

Line::Mode Siri::Mode::toMode() const
{
    if (m_submode) {
        if (auto m = std::visit([](auto &&m) -> std::optional<Line::Mode> { return submodeToMode(m); }, *m_submode); m) {
            return *m;
        }
    }
    return modeToMode(m_mode);
}

std::vector<Siri::Mode> Siri::Mode::fromMode(Line::Mode mode)
{
    std::vector<Siri::Mode> result;
    fromModeSubmodeImpl<Siri::Mode::VehicleMode>(mode, result);
    fromModeSubmode(detail::num<>(), mode, result);
    return result;
}

std::vector<Siri::Mode> Siri::Mode::fromModes(const std::vector<Line::Mode> &modes)
{
    std::vector<Siri::Mode> result;
    for (auto m : modes) {
        fromModeSubmodeImpl<Siri::Mode::VehicleMode>(m, result);
    }
    // processing all submodes last is necessary for the below deduplication logic to work
    for (auto m : modes) {
        fromModeSubmode(detail::num<>(), m, result);
    }
    return result;
}

std::strong_ordering Siri::Mode::operator<=>(const Mode &other) const
{
    const auto modeCmp = m_mode <=> other.m_mode;
    if (modeCmp == std::strong_ordering::equal) {
        if (!m_submode && !other.m_submode) {
            return std::strong_ordering::equal;
        }
        if (!m_submode) {
            return std::strong_ordering::less;
        }
        if (!other.m_submode) {
            return std::strong_ordering::greater;
        }
        return (*m_submode) <=> (*other.m_submode);
    }
    return modeCmp;
}

template <typename T>
std::optional<Siri::Mode::Submode> Siri::Mode::submodeEnumKeyLookup(QStringView key)
{
    auto me = QMetaEnum::fromType<T>();
    bool ok = false;
    const auto m = static_cast<T>(me.keyToValue(key.toUtf8().constData(), &ok));
    if (ok) {
        return m;
    }
    return {};
}

template <typename T>
void Siri::Mode::fromModeSubmodeImpl(Line::Mode mode, std::vector<Mode> &result)
{
    if constexpr (requires(T) { mode_map<T>[0]; }) {
        for (const auto &m : mode_map<T>) {
            if (m.mode == mode) {
                Mode res(Siri::Mode::VehicleMode::unknown);;
                if constexpr (std::is_same_v<T, Siri::Mode::VehicleMode>) {
                    res = Mode(m.siriMode);
                } else {
                    res = Mode(modeForSubmode(m.siriMode), m.siriMode);
                }
                auto it = std::lower_bound(result.begin(), result.end(), res);
                // this is sufficient as we process submodes last
                if (it != result.end() && ((*it) == res)) {
                    continue;
                }
                if (it != result.begin() && ((*std::prev(it)).contains(res))) {
                    continue;
                }
                result.insert(it, res);
            }
        }
    }
}

bool Siri::Mode::contains(const Siri::Mode &other) const
{
    return m_mode == other.m_mode && (!m_submode.has_value() || (other.m_submode.has_value() && m_submode == other.m_submode));
}

const char* Siri::Mode::modeString() const
{
    return toString(m_mode);
}

const char* Siri::Mode::submodeString() const
{
    if (m_submode) {
        return std::visit([](auto &&m) { return Siri::Mode::toString(m); }, *m_submode);
    }
    return nullptr;
}

const char* Siri::Mode::submodeTypeName() const
{
    if (m_submode) {
        return std::visit([](auto &&m) { return QMetaEnum::fromType<std::decay_t<decltype(m)>>().name(); }, *m_submode);
    }
    return nullptr;
}

Siri::Mode Siri::Mode::fromJson(const QJsonObject &json)
{
    return Siri::Mode::fromString(json.value("mode"_L1).toString(), json.value("submode"_L1).toString());
}

std::vector<Siri::Mode> Siri::Mode::fromJson(const QJsonArray &json)
{
    auto res = Json::fromJson<Siri::Mode>(json);
    std::sort(res.begin(), res.end());
    return res;
}

std::vector<Siri::Mode> Siri::Mode::intersection(const std::vector<Siri::Mode> &modes1, const std::vector<Siri::Mode> &modes2)
{
    assert(std::ranges::is_sorted(modes1));
    assert(std::ranges::is_sorted(modes2));

    std::vector<Siri::Mode> res;
    for (auto it1 = modes1.begin(), it2 = modes2.begin(); it1 != modes1.end() && it2 != modes2.end();) {
        const auto cmp = (*it1) <=> (*it2);
        if (cmp == std::strong_ordering::equal) {
            res.push_back(*it1);
            ++it1;
            ++it2;
            continue;
        }
        if (cmp == std::strong_ordering::less) {
            if (!(*it1).hasSubmode() && (*it1).mode() == (*it2).mode()) {
                res.push_back(*it2),
                ++it2;
            } else {
                ++it1;
            }
            continue;
        }
        if (cmp == std::strong_ordering::greater) {
            if (!(*it2).hasSubmode() && (*it1).mode() == (*it2).mode()) {
                res.push_back(*it1),
                ++it1;
            } else {
                ++it2;
            }
            continue;
        }
    }
    return res;
}

#include "moc_mode.cpp"

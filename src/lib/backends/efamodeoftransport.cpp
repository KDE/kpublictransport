/*
    SPDX-FileCopyrightText: 2019-2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "efamodeoftransport.h"
#include "logging.h"

#include <QUrlQuery>

#include <vector>

using namespace Qt::Literals;
using namespace KPublicTransport;

// comments below are EFA names found in XML responses (usually translated)
// the mapping isn't necessary 100% obvious everywhere
static constexpr const Line::Mode mot_map[] = {
    Line::Train, // 0
    Line::RapidTransit, // 1 "Commuter railway"
    Line::Metro, // 2 "Subway"
    Line::RapidTransit, // 3 "City rail" / "Stadtbahn"
    Line::Tramway, // 4
    Line::Bus, // 5
    Line::Bus, // 6 "Regional bus"
    Line::Bus, // 7 "Express bus"
    Line::Funicular, // 8 "Cable car/Rack railway" TODO this would also be Line::AerialLift
    Line::Ferry, // 9
    Line::Taxi, // 10 "Taxi on demand"
    Line::Unknown, // 11 "Other"
    Line::Air, // 12 "Airplane"
    Line::LocalTrain, // 13
    Line::LongDistanceTrain,
    Line::LongDistanceTrain,
    Line::LongDistanceTrain, // 14-16 "Train (intercity)"
    Line::Bus, // 17 "Rail replacement service"
    Line::RailShuttle, // 18 "Rail shuttle"
    Line::Bus, // 19 "Peoples bus" / "Bürgerbus"
    Line::Bus, // 20 "Rufbus" / on-demand but line-based busses
    Line::Coach, // 21 "Fernbus" / long distance bus services
};

Line::Mode EfaModeOfTransport::motTypeToLineMode(int mot)
{
    if (mot < (int)std::size(mot_map)) {
        return mot_map[mot];
    }
    qCDebug(Log) << "Unknown means of transport: " << mot;
    return Line::Unknown;
}

void EfaModeOfTransport::lineModesToQuery(const std::vector<Line::Mode> &lineModes, QUrlQuery &query)
{
    if (lineModes.empty()) {
        return;
    }

    for (auto mode : lineModes) {
        for (std::size_t i = 0; i < std::size(mot_map); ++i) {
            if (mode == mot_map[i]) {
                const QString key = QLatin1String("inclMOT_") + QString::number(i);
                if (!query.hasQueryItem(key)) {
                    query.addQueryItem(key, QStringLiteral("on"));
                }
            }
        }
    }

    query.addQueryItem(u"includedMeans"_s, u"checkbox"_s);
}

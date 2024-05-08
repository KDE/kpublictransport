/*
    SPDX-FileCopyrightText: 2023 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "platformlayout.h"

#include <KPublicTransport/Stopover>

using namespace KPublicTransport;

static void expandPlatformRange(std::vector<QString> &sections, const QString &range)
{
    if (range.isEmpty()) {
        return;
    }

    // TODO
    sections.push_back(range);
}

static void addPlatformSectionsForVehicleSections(std::vector<QString> &sections, const Stopover &stopover, const VehicleSection &coach)
{
    if (coach.hasPlatformPosition()) {
        const auto platformSections = stopover.platformLayout().sections();
        for (const auto &s : platformSections) {
            if (s.name().isEmpty() || s.begin() > coach.platformPositionEnd() || s.end() < coach.platformPositionBegin()) {
                continue;
            }
            sections.push_back(s.name());
        }
        return;
    }

    expandPlatformRange(sections, coach.platformSectionName());
}

static QString mergeSections(std::vector<QString> &&sections)
{
    std::sort(sections.begin(), sections.end());
    sections.erase(std::unique(sections.begin(), sections.end()), sections.end());
    if (sections.empty()) {
        return {};
    }

    QStringList l;
    for (std::size_t i = 0; i < sections.size(); ++i) {
        if (sections[i].size() > 1) {
            l.push_back(sections[i]);
            continue;
        }

        std::size_t j = i + 1;
        for (; j < sections.size(); ++j) {
            if (sections[j].size() != 1 || sections[j][0].cell() - sections[j-1][0].cell() != 1) {
                break;
            }
        }
        if (j - i == 1) {
            l.push_back(sections[i]);
        } else {
            l.push_back(sections[i] + QLatin1Char('-') + sections[j - 1]);
            i = j - 1;
        }
    }

    return l.join(QLatin1String(","));
}

QString PlatformLayout::sectionsForVehicle(const Stopover &stopover)
{
    std::vector<QString> secs;
    const auto coachs = stopover.vehicleLayout().sections();
    for (const auto &coach : coachs) {
        if (coach.type() == VehicleSection::Engine || coach.type() == VehicleSection::PowerCar) {
            continue;
        }
        addPlatformSectionsForVehicleSections(secs, stopover, coach);
    }
    return mergeSections(std::move(secs));
}

QString PlatformLayout::sectionsForClass(const Stopover &stopover, VehicleSection::Class cls)
{
    std::vector<QString> secs;
    const auto coachs = stopover.vehicleLayout().sections();
    for (const auto &coach : coachs) {
        if (coach.classes() & cls) {
            addPlatformSectionsForVehicleSections(secs, stopover, coach);
        }
    }
    return mergeSections(std::move(secs));
}

QString PlatformLayout::sectionsForVehicleSection(const Stopover &stopover, const QString &coachName)
{
    std::vector<QString> secs;
    const auto coachs = stopover.vehicleLayout().sections();
    for (const auto &coach : coachs) {
        if (coach.name() == coachName) {
            addPlatformSectionsForVehicleSections(secs, stopover, coach);
        }
    }
    return mergeSections(std::move(secs));
}

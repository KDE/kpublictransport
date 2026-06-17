/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "backends/localbackendutils.h"
#include "datatypes/line.h"
#include "datatypes/stopinformation.h"
#include "locationutil_p.h"

#include <KPublicTransport/Location>
#include <KPublicTransport/LocationRequest>

#include <QCryptographicHash>
#include <QString>

#include <cmath>
#include <set>
#include <vector>

using namespace KPublicTransport;

using namespace Qt::StringLiterals;

// Ported from https://docs.rs/strsim/latest/src/strsim/lib.rs.html#233 with minor changes
qsizetype levenshteinDistance(const QStringView a, const QStringView b)
{
    const auto bLen = b.size();

    std::vector<qsizetype> cache(bLen);
    std::iota(cache.begin(), cache.end(), 1);

    auto result = bLen;

    for (qsizetype i = 0; i < a.size(); i++) {
        const auto aElem = a[i];

        result = i + 1;
        auto distanceB = i;

        for (qsizetype j = 0; j < b.size(); j++) {
            const auto bElem = b[j];

            const auto cost = qsizetype(aElem != bElem);
            const auto distanceA = distanceB + cost;
            distanceB = cache[j];
            result = std::min({result + 1, distanceA, distanceB + 1});
            cache[j] = result;
        }
    }

    return result;
}

float normalizedLevenshtein(QStringView a, QStringView b)
{
    return 1.0 - float(levenshteinDistance(a, b)) / float(std::max(a.size(), b.size()));
}

float LocationUtil::score(const LocationRequest &request, const Location &loc)
{
    float score = 0.0;

    if (request.hasCoordinate()) {
        // As long as under 2000km away, boost up to one point
        const auto dist = Location::distance(request.latitude(), request.longitude(), loc.latitude(), loc.longitude());
        score += (std::max(2000.0f * 1000.0f - float(dist), 0.0f)) / (2000.0f * 1000.0f);
    }

    if (!request.name().isEmpty()) {
        const auto tokenizeRe = QRegularExpression(uR"(( |-|\/))"_s);

        const auto searchS = LocalBackendUtils::normalizeName(request.name());
        const auto locNameS = LocalBackendUtils::normalizeName(loc.name());
        const auto search = QStringView(searchS).split(tokenizeRe, Qt::SkipEmptyParts);
        const auto locName = QStringView(locNameS).split(tokenizeRe, Qt::SkipEmptyParts);

        float tokenScore = 0.0f;

        for (const auto token : search) {
            bool contains = std::any_of(locName.begin(), locName.end(), [&](QStringView locToken) {
                return levenshteinDistance(token, locToken) < 2;
            });
            if (contains) {
                tokenScore += 1;
            }
        }

        const float normalizedTokenScore = (tokenScore / float(search.size())) * 0.7f + (tokenScore / float(locName.size())) * 0.3f;

        score += normalizedTokenScore;

        const float normalizedLevenshteinDistance = normalizedLevenshtein(searchS, locNameS);

        score += normalizedLevenshteinDistance * 0.6f;
    }

    if (loc.type() == Location::Stop) {
        // People are most likely searching for stations
        score += 1.0;
        if (!loc.stopInformation().lines().empty()) {
            const auto lines = loc.stopInformation().lines();
            float modeScore = 0.0;

            std::set<Line::Mode> modes;

            for (const auto &line : lines) {
                modes.insert(line.mode());
            }

            for (const auto &mode : modes) {
                switch (mode) {
                case Line::Mode::LongDistanceTrain:
                case Line::Mode::Air:
                    modeScore += 0.4;
                    break;
                case Line::Mode::Train:
                case Line::Mode::LocalTrain:
                    modeScore += 0.2;
                    break;
                case Line::Mode::Coach:
                    modeScore += 0.1;
                    break;
                default:
                    break;
                }
            }

            score += modeScore;
        }
    }

    // prefer the one inside the viewbox
    if (request.viewbox().isValid()) {
        const auto in = request.viewbox().contains(QPointF(loc.longitude(), loc.latitude()));
        if (in) {
            score += 1.0;
        }
    }

    // prefer matching country, if that was specified in the request
    if (request.location().country().size() == 2) {
        const auto lhsMatch = request.location().country() == loc.country();
        if (lhsMatch) {
            score += 1.0;
        }
    }

    return score;
}

bool LocationUtil::sortLessThan(const LocationRequest &request,
                                const Location &lhs,
                                const Location &rhs)
{
    return score(request, lhs) > score(request, rhs);
}

static QString normalizeString(const QString &str)
{
    QString n;
    n.reserve(str.size());
    for (const auto c : str) {
        if (c.isLetter() || c.isDigit()) {
            n.push_back(c.toCaseFolded());
        }
    }
    return n;
}

QString LocationUtil::cacheKey(const Location &loc)
{
    if (loc.hasCoordinate()) {
        return QString::number((int) (loc.latitude() * 1000000)) + QLatin1Char('x')
               + QString::number((int) (loc.longitude() * 1000000));
    }

    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(normalizeString(loc.name()).toUtf8());
    hash.addData(normalizeString(loc.streetAddress()).toUtf8());
    hash.addData(normalizeString(loc.postalCode()).toUtf8());
    hash.addData(normalizeString(loc.locality()).toUtf8());
    hash.addData(normalizeString(loc.region()).toUtf8());
    hash.addData(normalizeString(loc.country()).toUtf8());

    return QString::fromUtf8(hash.result().toHex());
}

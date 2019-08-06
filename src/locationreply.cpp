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

#include "locationreply.h"
#include "reply_p.h"
#include "locationrequest.h"
#include "datatypes/locationutil_p.h"
#include "logging.h"

#include <KPublicTransport/Location>

#include <QDebug>

using namespace KPublicTransport;

namespace KPublicTransport {
class LocationReplyPrivate: public ReplyPrivate {
public:
    void finalizeResult() override;

    LocationRequest request;
    std::vector<Location> locations;
};
}

void LocationReplyPrivate::finalizeResult()
{
    if (locations.empty()) {
        return;
    }
    error = Reply::NoError;
    errorMsg.clear();

    // merge all duplicates, as there is no natural order for name searches this is done in O(n²) for now
    for (auto it = locations.begin(); it != locations.end(); ++it) {
        for (auto mergeIt = it + 1; mergeIt != locations.end();) {
            if (Location::isSame(*it, *mergeIt)) {
                *it = Location::merge(*it, *mergeIt);
                mergeIt = locations.erase(mergeIt);
            } else {
                ++mergeIt;
            }
        }
    }

    std::sort(locations.begin(), locations.end(), [this](const auto &lhs, const auto &rhs) {
        return LocationUtil::sortLessThan(request, lhs, rhs);
    });
}

LocationReply::LocationReply(const LocationRequest &req, QObject *parent)
    : Reply(new LocationReplyPrivate, parent)
{
    Q_D(LocationReply);
    d->request = req;
}

LocationReply::~LocationReply() = default;

LocationRequest LocationReply::request() const
{
    Q_D(const LocationReply);
    return d->request;
}

const std::vector<Location>& LocationReply::result() const
{
    Q_D(const LocationReply);
    return d->locations;
}

std::vector<Location>&& LocationReply::takeResult()
{
    Q_D(LocationReply);
    return std::move(d->locations);
}

void LocationReply::addResult(std::vector<Location> &&res)
{
    Q_D(LocationReply);
    // remove implausible results
    for (auto it = res.begin(); it != res.end();) {
        // we sometimes seem to get bogus places in Antartica
        if ((*it).hasCoordinate() && (*it).latitude() < -65.0) {
            qCDebug(Log) << "Dropping location in Antarctica" << (*it).name() << (*it).latitude() << (*it).longitude();
            it = res.erase(it);
            continue;
        }
        ++it;
    }

    if (!res.empty()) {
        if (d->locations.empty()) {
            d->locations = std::move(res);
        } else {
            d->locations.insert(d->locations.end(), res.begin(), res.end());
        }
        d->emitUpdated(this);
    }

    d->pendingOps--;
    d->emitFinishedIfDone(this);
}

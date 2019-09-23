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

#include "journeyrequest.h"
#include "requestcontext_p.h"
#include "datatypes/json_p.h"

#include <KPublicTransport/Location>

#include <QDateTime>
#include <QDebug>
#include <QSharedData>

#include <unordered_map>

using namespace KPublicTransport;

namespace KPublicTransport {
class JourneyRequestPrivate : public QSharedData {
public:
    Location from;
    Location to;
    QDateTime dateTime;
    JourneyRequest::DateTimeMode dateTimeMode = JourneyRequest::Departure;
    std::vector<RequestContext> contexts;
};
}

JourneyRequest::JourneyRequest() :
    d(new JourneyRequestPrivate)
{
}

JourneyRequest::JourneyRequest(const Location &from, const Location &to)
    : d(new JourneyRequestPrivate)
{
    d->from = from;
    d->to = to;
}

JourneyRequest::JourneyRequest(JourneyRequest&&) noexcept = default;
JourneyRequest::JourneyRequest(const JourneyRequest&) = default;
JourneyRequest::~JourneyRequest() = default;
JourneyRequest& JourneyRequest::operator=(const JourneyRequest&) = default;

bool JourneyRequest::isEmpty() const
{
    return d->to.isEmpty() && d->from.isEmpty();
}

Location JourneyRequest::from() const
{
    return d->from;
}

void JourneyRequest::setFrom(const Location &from)
{
    d.detach();
    d->from = from;
}

Location JourneyRequest::to() const
{
    return d->to;
}

void JourneyRequest::setTo(const Location &to)
{
    d.detach();
    d->to = to;
}

QDateTime JourneyRequest::dateTime() const
{
    if (!d->dateTime.isValid()) {
        d->dateTime = QDateTime::currentDateTime();
    }
    return d->dateTime;
}

void JourneyRequest::setDateTime(const QDateTime& dt)
{
    d.detach();
    d->dateTime = dt;
}

JourneyRequest::DateTimeMode JourneyRequest::dateTimeMode() const
{
    return d->dateTimeMode;
}

void JourneyRequest::setDateTimeMode(JourneyRequest::DateTimeMode mode)
{
    d.detach();
    d->dateTimeMode = mode;
}

void JourneyRequest::setDepartureTime(const QDateTime &dt)
{
    d.detach();
    d->dateTime = dt;
    d->dateTimeMode = Departure;
}

void JourneyRequest::setArrivalTime(const QDateTime &dt)
{
    d.detach();
    d->dateTime = dt;
    d->dateTimeMode = Arrival;
}

RequestContext JourneyRequest::context(const AbstractBackend *backend) const
{
    const auto it = std::lower_bound(d->contexts.begin(), d->contexts.end(), backend);
    if (it != d->contexts.end() && (*it).backend == backend) {
        return *it;
    }

    RequestContext context;
    context.backend = backend;
    return context;
}

const std::vector<RequestContext>& JourneyRequest::contexts() const
{
    return d->contexts;
}

void JourneyRequest::setContext(const AbstractBackend *backend, RequestContext &&context)
{
    d.detach();
    const auto it = std::lower_bound(d->contexts.begin(), d->contexts.end(), backend);
    if (it != d->contexts.end() && (*it).backend == backend) {
        (*it) = std::move(context);
    } else {
        d->contexts.insert(it, std::move(context));
    }
}

void JourneyRequest::purgeLoops(const JourneyRequest &baseRequest)
{
    RequestContext::purgeLoops(d->contexts, baseRequest.contexts());
}

QJsonObject JourneyRequest::toJson(const KPublicTransport::JourneyRequest &req)
{
    auto obj = Json::toJson(req);
    obj.insert(QStringLiteral("from"), Location::toJson(req.from()));
    obj.insert(QStringLiteral("to"), Location::toJson(req.to()));
    return obj;
}

#include "moc_journeyrequest.cpp"

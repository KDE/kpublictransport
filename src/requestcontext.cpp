/*
    Copyright (C) 2019 Volker Krause <vkrause@kde.org>

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

#include "requestcontext_p.h"

using namespace KPublicTransport;

RequestContext::RequestContext() = default;
RequestContext::~RequestContext() = default;

bool RequestContext::operator==(const RequestContext &other) const
{
    return backend == other.backend
        && type == other.type
        && dateTime == other.dateTime
        && backendData == other.backendData;
}

bool RequestContext::operator<(const AbstractBackend *other) const
{
    return backend < other;
}

void RequestContext::purgeLoops(std::vector<RequestContext> &contexts, const std::vector<RequestContext> &baseContexts)
{
    for (auto it = contexts.begin(); it != contexts.end();) {
        const auto baseIt = std::lower_bound(baseContexts.begin(), baseContexts.end(), (*it).backend);
        if (baseIt != baseContexts.end() && (*baseIt) == (*it)) {
            it = contexts.erase(it);
        } else {
            ++it;
        }
    }
}

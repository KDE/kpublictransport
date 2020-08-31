/*
    SPDX-FileCopyrightText: 2019 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
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

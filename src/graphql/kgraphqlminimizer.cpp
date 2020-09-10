/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kgraphqlminimizer_p.h"

#include <QByteArray>

KGraphQLMinimizer::KGraphQLMinimizer() = default;
KGraphQLMinimizer::~KGraphQLMinimizer() = default;

QByteArray KGraphQLMinimizer::minimizeQuery(const QByteArray &query)
{
    m_out.clear();
    m_out.reserve(query.size());

    for (auto it = query.begin(); it != query.end(); ++it) {
        char c = (*it);
        if (c == '\r') c = '\n';
        if (c == '#') {
            while ((*it) != '\n' && it != query.end()) ++it;
            appendSpaceCompress('\n');
            continue;
        }
        appendSpaceCompress(c);
    }

    return std::move(m_out);
}

void KGraphQLMinimizer::appendSpaceCompress(char c)
{
    if (!std::isspace(c)) {
        m_out.push_back(c);
        return;
    }

    if (m_out.isEmpty()) {
        return;
    }
    if (std::isspace(m_out.back())) {
        if (c == '\n') {
            m_out.back() = c;
        }
        return;
    }

    m_out.push_back(c);
}

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
    if (m_out.isEmpty()) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            m_out.push_back(c);
        }
        return;
    }

    const auto prev = m_out.back();
    if (std::isspace(static_cast<unsigned char>(prev))) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            if (c == '\n') {
                m_out.back() = c;
            }
        } else {
            if (isPunctuator(c)) {
                m_out.back() = c;
            } else {
                m_out.push_back(c);
            }
        }
        return;
    }

    if (!std::isspace(static_cast<unsigned char>(c)) || !isPunctuator(prev)) {
        m_out.push_back(c);
    }
}

bool KGraphQLMinimizer::isPunctuator(char c) const
{
    static const char punctuators[] = "!$(),.:=@[]{|}";
    return std::binary_search(std::begin(punctuators), std::end(punctuators), c);
}

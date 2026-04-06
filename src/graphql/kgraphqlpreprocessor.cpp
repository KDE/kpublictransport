/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kgraphqlpreprocessor_p.h"

#include <QByteArray>
#include <QDebug>
#include <QFile>

using namespace Qt::Literals;

KGraphQLPreprocessor::KGraphQLPreprocessor() = default;
KGraphQLPreprocessor::~KGraphQLPreprocessor() = default;

void KGraphQLPreprocessor::setSearchPaths(const QStringList &paths)
{
    m_searchPaths = paths;
}

bool KGraphQLPreprocessor::processQueryFromFile(QStringView fileName)
{
    for (const auto &searchPath : m_searchPaths) {
        const QString path = searchPath + '/'_L1 + fileName;
        QFile f(path);
        if (!f.open(QFile::ReadOnly)) {
            if (QFile::exists(path)) {
                qWarning() << "Failed to load GraphQL query from file:" << fileName << f.errorString();
                return false;
            }
            continue;
        }
        return processQuery(f.readAll());
    }
    return false;
}

bool KGraphQLPreprocessor::processQuery(QByteArrayView query)
{
    for (auto it = query.begin(); it != query.end(); ++it) {
        char c = (*it);
        if (c == '\r') {
            c = '\n';
        }
        if (c == '#') {
            const auto beginIt = it;
            while ((*it) != '\n' && it != query.end()) {
                ++it;
            }
            QByteArrayView line(beginIt, it);
            if (line.startsWith("#include <") && line.endsWith('>')) {
                if (!processQueryFromFile(QString::fromUtf8(line.mid(10, line.size() - 11)))) {
                    return false;
                }
            } else {
                appendSpaceCompress('\n');
            }
            continue;
        }
        appendSpaceCompress(c);
    }

    return true;
}

QByteArray KGraphQLPreprocessor::query() const
{
    return m_out;
}

void KGraphQLPreprocessor::appendSpaceCompress(char c)
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

bool KGraphQLPreprocessor::isPunctuator(char c)
{
    static constexpr const char punctuators[] = "!$(),.:=@[]{|}";
    return std::binary_search(std::begin(punctuators), std::end(punctuators), c);
}

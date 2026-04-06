/*
    SPDX-FileCopyrightText: 2026 Volker Krause <vkrause@kde.org>
    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KGRAPHQLPREPROCESSOR_H
#define KGRAPHQLPREPROCESSOR_H

#include <QByteArray>
#include <QStringList>

/**
 * GraphQL query preprocessor.
 * @internal
 */
class KGraphQLPreprocessor
{
public:
    explicit KGraphQLPreprocessor();
    ~KGraphQLPreprocessor();
    void setSearchPaths(const QStringList &paths);

    bool processQueryFromFile(QStringView fileName);
    bool processQuery(QByteArrayView query);

    [[nodiscard]] QByteArray query() const;

private:
    void appendSpaceCompress(char c);
    [[nodiscard]] static bool isPunctuator(char c);

    QStringList m_searchPaths;
    QByteArray m_out;
};

#endif

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KGRAPHQLMINIMIZER_H
#define KGRAPHQLMINIMIZER_H

#include <QByteArray>

/**
 * GraphQL query string minimizer
 * @internal
 */
class KGraphQLMinimizer
{
public:
    explicit KGraphQLMinimizer();
    ~KGraphQLMinimizer();

    QByteArray minimizeQuery(const QByteArray &query);

private:
    void appendSpaceCompress(char c);
    bool isPunctuator(char c) const;

    QByteArray m_out;
};

#endif // KGRAPHQLMINIMIZER_H

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef WIKIDATAQUERYMANAGER_H
#define WIKIDATAQUERYMANAGER_H

#include <QObject>

class QNetworkAccessManager;
class QNetworkReply;

namespace Wikidata {
class Query;

/** Executes wikidata queries. */
class QueryManager : public QObject
{
    Q_OBJECT
public:
    explicit QueryManager(QObject *parent = nullptr);
    ~QueryManager() override;

    /** Set the email address used in the User-Agent header.
     *  Setting this is mandatory, queries will not be executred without this.
     */
    void setUserAgentEmailAddress(const QString &email);

    /** Execute @p query. */
    void execute(Query *query);

private:
    void executeNextSubQuery(Query *query);
    void subQueryFinished(Query *query, QNetworkReply *reply);
    [[nodiscard]] QNetworkAccessManager* nam();

    QNetworkAccessManager *m_nam = nullptr;
    QString m_email;
};

}

#endif // WIKIDATAQUERYMANAGER_H

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef WIKIDATAQUERYMANAGER_H
#define WIKIDATAQUERYMANAGER_H

#include <QObject>

class WikidataQuery;
class QNetworkAccessManager;
class QNetworkReply;

/** Executes wikidata queries. */
class WikidataQueryManager : public QObject
{
    Q_OBJECT
public:
    explicit WikidataQueryManager(QObject *parent = nullptr);
    ~WikidataQueryManager();

    void execute(WikidataQuery *query);

private:
    void executeNextSubQuery(WikidataQuery *query);
    void subQueryFinished(WikidataQuery *query, QNetworkReply *reply);
    QNetworkAccessManager *m_nam;
};

#endif // WIKIDATAQUERYMANAGER_H

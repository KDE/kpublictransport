/*
    Copyright (C) 2020 Volker Krause <vkrause@kde.org>

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
    void subQueryFinished(WikidataQuery *query, QNetworkReply *reply);
    QNetworkAccessManager *m_nam;
};

#endif // WIKIDATAQUERYMANAGER_H

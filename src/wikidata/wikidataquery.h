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

#ifndef WIKIDATAQUERY_H
#define WIKIDATAQUERY_H

#include <QObject>

#include <vector>

class QNetworkReply;
class QNetworkRequest;

/** Wikidata multi-entity retrieval query. */
class WikidataQuery : public QObject
{
Q_OBJECT
public:
    explicit WikidataQuery(QObject *parent = nullptr);
    ~WikidataQuery();

    void setItems(std::vector<QString> &&items);

    enum Error {
        NoError,
        NetworkError
    };
    Error error();

Q_SIGNALS:
    void partialResult(const QJsonObject &entities);
    void finished();

private:
    friend class WikidataQueryManager;
    QNetworkRequest nextRequest();
    /** Returns @true if this query is complete, @false if another request is needed. */
    bool processReply(QNetworkReply *reply);

    std::vector<QString> m_items;
    std::size_t m_nextBatch = 0;
    Error m_error = NoError;
};

#endif // WIKIDATAQUERY_H

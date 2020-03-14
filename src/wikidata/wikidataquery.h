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

/** Base class for Wikidata queries. */
class WikidataQuery : public QObject
{
    Q_OBJECT
public:
    explicit WikidataQuery(QObject *parent = nullptr);
    ~WikidataQuery();

    enum Error {
        NoError,
        NetworkError
    };
    Error error();

Q_SIGNALS:
    void finished();

protected:
    friend class WikidataQueryManager;
    virtual QNetworkRequest nextRequest() = 0;
    /** Returns @true if this query is complete, @false if another request is needed. */
    virtual bool processReply(QNetworkReply *reply) = 0;

    Error m_error = NoError;
};

/** Wikidata multi-entity retrieval query. */
class WikidataEntitiesQuery : public WikidataQuery
{
    Q_OBJECT
public:
    explicit WikidataEntitiesQuery(QObject *parent = nullptr);
    ~WikidataEntitiesQuery();

    void setItems(std::vector<QString> &&items);

Q_SIGNALS:
    void partialResult(const QJsonObject &entities);

private:
    QNetworkRequest nextRequest() override;
    bool processReply(QNetworkReply *reply) override;

    std::vector<QString> m_items;
    std::size_t m_nextBatch = 0;
};

/** Wikidata image metadata query. */
class WikidataImageMetadataQuery : public WikidataQuery
{
    Q_OBJECT
public:
    explicit WikidataImageMetadataQuery(QObject *parent = nullptr);
    ~WikidataImageMetadataQuery();

    void setImages(std::vector<QString> &&images);

Q_SIGNALS:
    void partialResult(const QJsonObject &metaData);

private:
    QNetworkRequest nextRequest() override;
    bool processReply(QNetworkReply *reply) override;

    std::vector<QString> m_images;
    std::size_t m_nextBatch = 0;
};

#endif // WIKIDATAQUERY_H

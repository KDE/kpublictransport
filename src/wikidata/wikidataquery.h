/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef WIKIDATAQUERY_H
#define WIKIDATAQUERY_H

#include "entities.h"

#include <QObject>

#include <vector>

class QNetworkReply;
class QNetworkRequest;
class QUrlQuery;

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
    QUrlQuery commonUrlQuery() const;

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

    void setItems(std::vector<Wikidata::Q> &&items);
    std::vector<Wikidata::Item>&& takeResult();

Q_SIGNALS:
    void partialResult(WikidataEntitiesQuery *query);

private:
    QNetworkRequest nextRequest() override;
    bool processReply(QNetworkReply *reply) override;

    std::vector<Wikidata::Q> m_items;
    std::size_t m_nextBatch = 0;
    std::vector<Wikidata::Item> m_result;
};

/** Wikidata image metadata query. */
class WikidataImageMetadataQuery : public WikidataQuery
{
    Q_OBJECT
public:
    explicit WikidataImageMetadataQuery(QObject *parent = nullptr);
    ~WikidataImageMetadataQuery();

    void setImages(std::vector<QString> &&images);
    std::vector<Wikidata::Image>&& takeResult();

Q_SIGNALS:
    void partialResult(WikidataImageMetadataQuery *query);

private:
    QNetworkRequest nextRequest() override;
    bool processReply(QNetworkReply *reply) override;

    std::vector<QString> m_images;
    std::size_t m_nextBatch = 0;
    std::vector<Wikidata::Image> m_result;
};

#endif // WIKIDATAQUERY_H

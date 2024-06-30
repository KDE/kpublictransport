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

namespace Wikidata {
class QueryManager;

/** Base class for Wikidata queries. */
class Query : public QObject
{
    Q_OBJECT
public:
    explicit Query(QObject *parent = nullptr);
    ~Query() override;

    enum Error {
        NoError,
        NetworkError
    };
    [[nodiscard]] Error error() const;

Q_SIGNALS:
    void finished();

protected:
    [[nodiscard]] static QUrlQuery commonUrlQuery();

    friend class QueryManager;
    [[nodiscard]] virtual QNetworkRequest nextRequest() = 0;
    /** Returns @true if this query is complete, @false if another request is needed. */
    [[nodiscard]] virtual bool processReply(QNetworkReply *reply) = 0;

    Error m_error = NoError;
};

/** Wikidata multi-entity retrieval query. */
class EntitiesQuery : public Query
{
    Q_OBJECT
public:
    explicit EntitiesQuery(QObject *parent = nullptr);
    ~EntitiesQuery() override;

    void setItems(std::vector<Wikidata::Q> &&items);
    [[nodiscard]] std::vector<Wikidata::Item> takeResult();

Q_SIGNALS:
    void partialResult(EntitiesQuery *query);

private:
    [[nodiscard]] QNetworkRequest nextRequest() override;
    [[nodiscard]] bool processReply(QNetworkReply *reply) override;

    std::vector<Wikidata::Q> m_items;
    std::size_t m_nextBatch = 0;
    std::vector<Wikidata::Item> m_result;
};

/** Wikidata image metadata query. */
class ImageMetadataQuery : public Query
{
    Q_OBJECT
public:
    explicit ImageMetadataQuery(QObject *parent = nullptr);
    ~ImageMetadataQuery() override;

    void setImages(std::vector<QString> &&images);
    [[nodiscard]] std::vector<Wikidata::Image> takeResult();

Q_SIGNALS:
    void partialResult(ImageMetadataQuery *query);

private:
    [[nodiscard]] QNetworkRequest nextRequest() override;
    [[nodiscard]] bool processReply(QNetworkReply *reply) override;

    std::vector<QString> m_images;
    std::size_t m_nextBatch = 0;
    std::vector<Wikidata::Image> m_result;
};

}

#endif // WIKIDATAQUERY_H

/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KGRAPHQL_H
#define KGRAPHQL_H

#include <QExplicitlySharedDataPointer>

#include <functional>
#include <memory>

class QJsonObject;
class QJsonValue;
class QNetworkAccessManager;
class QNetworkReply;
class QNetworkRequest;
class QObject;
class QUrl;

class KGraphQLRequest;
class KGraphQLReply;

/** GraphQL query functions. */
namespace KGraphQL
{
    /** Perform a GraphQL query. */
    void query(const KGraphQLRequest &request, QNetworkAccessManager *nam, const std::function<void(const KGraphQLReply&)> &callback, QObject *replyParent = nullptr);
}

class KGraphQLRequestPrivate;

/** A GraphQL query request. */
class KGraphQLRequest
{
public:
    explicit KGraphQLRequest();
    explicit KGraphQLRequest(const QUrl &url);
    KGraphQLRequest(const KGraphQLRequest&);
    KGraphQLRequest(KGraphQLRequest&&) noexcept;
    ~KGraphQLRequest();
    KGraphQLRequest& operator=(const KGraphQLRequest&);

    /** Sets the endpoint to perform the query on. */
    void setUrl(const QUrl &url);

    /** Set GraphQL query to perform. */
    void setQuery(const QString &query);
    /** Read GraphQL query from a file. */
    void setQueryFromFile(const QString &fileName);

    /** Sets query variable @p name to @p value. */
    void setVariable(const QString &name, const QJsonValue &value);

    /** Access to the underlying HTTP request. */
    QNetworkRequest& networkRequest();
    const QNetworkRequest& networkRequest() const;

    /** @internal */
    QByteArray rawData() const;

private:
    QExplicitlySharedDataPointer<KGraphQLRequestPrivate> d;
};

class KGraphQLReplyPrivate;

/** A GraphQL reply. */
class KGraphQLReply
{
public:
    KGraphQLReply(KGraphQLReply&&) noexcept;
    KGraphQLReply(const KGraphQLReply&) = delete;
    KGraphQLReply& operator=(const KGraphQLReply) = delete;
    ~KGraphQLReply();

    /** Error type. */
    enum Error {
        NoError,
        NetworkError,
        QueryError
    };
    /** Result status. */
    Error error() const;
    /** Error message.
     *  Returns an empty string if error() return NoError.
     */
    QString errorString() const;

    /** Result data, valid in case of error() returning NoError. */
    QJsonObject data() const;

    /** The underlying QNetworkReply instance. */
    QNetworkReply* networkReply() const;

    /** @internal */
    QByteArray rawData() const;

private:
    friend void KGraphQL::query(const KGraphQLRequest &request, QNetworkAccessManager *nam, const std::function<void(const KGraphQLReply&)> &callback, QObject *replyParent);
    KGraphQLReply(QNetworkReply *reply);

    std::unique_ptr<KGraphQLReplyPrivate> d;
};

#endif // KGRAPHQL_H

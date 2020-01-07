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

#include "kgraphql.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

class KGraphQLRequestPrivate : public QSharedData
{
public:
    KGraphQLRequestPrivate();

    QNetworkRequest m_request;
    QString m_query;
    QJsonObject m_variables;
};

KGraphQLRequestPrivate::KGraphQLRequestPrivate()
{
    m_request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/json"));
}

KGraphQLRequest::KGraphQLRequest() :
    d(new KGraphQLRequestPrivate)
{
}

KGraphQLRequest::KGraphQLRequest(const QUrl& url) :
    d(new KGraphQLRequestPrivate)
{
    d->m_request.setUrl(url);
}

KGraphQLRequest::KGraphQLRequest(const KGraphQLRequest&) = default;
KGraphQLRequest::KGraphQLRequest(KGraphQLRequest &&) noexcept = default;
KGraphQLRequest::~KGraphQLRequest() = default;
KGraphQLRequest& KGraphQLRequest::operator=(const KGraphQLRequest&) = default;

void KGraphQLRequest::setUrl(const QUrl &url)
{
    d.detach();
    d->m_request.setUrl(url);
}

void KGraphQLRequest::setQuery(const QString &query)
{
    d.detach();
    d->m_query = query;
}

void KGraphQLRequest::setQueryFromFile(const QString &fileName)
{
    QFile f(fileName);
    if (!f.open(QFile::ReadOnly)) {
        qWarning() << "Failed to load GraphQL query from file:" << fileName << f.errorString();
        return;
    }

    d.detach();
    d->m_query = QString::fromUtf8(f.readAll());
}

void KGraphQLRequest::setVariable(const QString &name, const QJsonValue &value)
{
    d.detach();
    d->m_variables.insert(name, value);
}

QNetworkRequest& KGraphQLRequest::networkRequest()
{
    return d->m_request;
}

const QNetworkRequest& KGraphQLRequest::networkRequest() const
{
    return d->m_request;
}

QByteArray KGraphQLRequest::rawData() const
{
    QJsonObject obj;
    obj.insert(QStringLiteral("query"), d->m_query);
    if (!d->m_variables.isEmpty()) {
        obj.insert(QStringLiteral("variables"), d->m_variables);
    }
    return QJsonDocument(obj).toJson(QJsonDocument::Compact);
}


class KGraphQLReplyPrivate
{
public:
    QNetworkReply *m_reply = nullptr;
    QByteArray m_data;
    QJsonObject m_result;
};

KGraphQLReply::KGraphQLReply(QNetworkReply *reply)
    : d(new KGraphQLReplyPrivate)
{
    d->m_reply = reply;
    if (d->m_reply->error() == QNetworkReply::NoError || d->m_reply->error() == QNetworkReply::InternalServerError) {
        d->m_data = reply->readAll();
        d->m_result = QJsonDocument::fromJson(d->m_data).object();
    }
}

KGraphQLReply::KGraphQLReply(KGraphQLReply &&) noexcept = default;

KGraphQLReply::~KGraphQLReply()
{
    d->m_reply->deleteLater();
}

KGraphQLReply::Error KGraphQLReply::error() const
{
    if (d->m_reply->error() != QNetworkReply::NoError && d->m_result.isEmpty()) {
        return NetworkError;
    }
    if (d->m_result.contains(QLatin1String("data"))) {
        return NoError;
    }
    return QueryError;
}

QString KGraphQLReply::errorString() const
{
    switch (error()) {
        case NoError:
            return {};
        case NetworkError:
            return d->m_reply->errorString();
        case QueryError:
        {
            const auto errorArray = d->m_result.value(QLatin1String("errors")).toArray();
            QStringList errors;
            errors.reserve(errorArray.size());
            for (const auto &errorValue : errorArray) {
                const auto errorObj = errorValue.toObject();
                const auto msg = QString::fromUtf8("%1 (line: %2, column: %3)")
                    .arg(errorObj.value(QLatin1String("message")).toString())
                    .arg(errorObj.value(QLatin1String("locations")).toArray().at(0).toObject().value(QLatin1String("line")).toInt())
                    .arg(errorObj.value(QLatin1String("locations")).toArray().at(0).toObject().value(QLatin1String("column")).toInt());
                errors.push_back(msg);
            }
            return errors.join(QLatin1Char('\n'));
        }
    }
    return {};
}

QJsonObject KGraphQLReply::data() const
{
    return d->m_result.value(QLatin1String("data")).toObject();
}



void KGraphQL::query(const KGraphQLRequest &request, QNetworkAccessManager *nam, const std::function<void(const KGraphQLReply&)> &callback)
{
    auto reply = nam->post(request.networkRequest(), request.rawData());
    QObject::connect(reply, &QNetworkReply::finished, nam, [reply, callback]() {
        callback(KGraphQLReply(reply));
        reply->deleteLater();
    });
}

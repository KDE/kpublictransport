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

#include "overpassquerymanager.h"
#include "overpassquery.h"

#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QNetworkReply>
#include <QStandardPaths>
#include <QTimer>
#include <QUrl>
#include <QUrlQuery>

#include <chrono>
#include <deque>

using namespace OSM;

namespace OSM {
struct OverpassQueryTask {
    OverpassQuery *query = nullptr;
    QRectF bbox;
    bool forceReload = false;
};

struct OverpassQueryExecutor {
    QUrl endpoint;
    std::chrono::seconds cooldownTime = std::chrono::seconds(3);
    QDateTime nextSlot;
    std::unique_ptr<OverpassQueryTask> task;
};

class OverpassQueryManagerPrivate {
public:
    void executeTasks();
    void taskFinished(OverpassQueryExecutor *executor, QNetworkReply *reply);
    void checkQueryFinished(OverpassQuery *query) const;
    void cancelQuery(OverpassQuery *query);

    OverpassQueryManager *q;
    QNetworkAccessManager *m_nam;
    QTimer *m_nextTaskTimer;
    std::vector<OverpassQueryExecutor> m_executors;
    std::deque<std::unique_ptr<OverpassQueryTask>> m_tasks;
};
}

static const char* executor_configs[] = {
    "https://overpass-api.de/api/interpreter",
    "https://overpass.kumi.systems/api/interpreter",
};

OverpassQueryManager::OverpassQueryManager(QObject *parent)
    : QObject(parent)
    , d(new OverpassQueryManagerPrivate)
{
    d->q = this;
    d->m_nam = new QNetworkAccessManager(this);
    d->m_nam->setRedirectPolicy(QNetworkRequest::NoLessSafeRedirectPolicy);
    d->m_nam->setStrictTransportSecurityEnabled(true);
    d->m_nam->enableStrictTransportSecurityStore(true, QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.osm/hsts/"));

    auto diskCache = new QNetworkDiskCache;
    diskCache->setCacheDirectory(QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/org.kde.osm/overpass-cache/"));
    diskCache->setMaximumCacheSize(1'000'000'000); // 1GB
    d->m_nam->setCache(diskCache);

    d->m_nextTaskTimer = new QTimer(this);
    d->m_nextTaskTimer->setSingleShot(true);
    connect(d->m_nextTaskTimer, &QTimer::timeout, this, [this]() { d->executeTasks(); });

    for (const auto &config : executor_configs) {
        OverpassQueryExecutor executor;
        executor.endpoint = QUrl(QString::fromUtf8(config));
        d->m_executors.push_back(std::move(executor));
    }
}

OverpassQueryManager::~OverpassQueryManager() = default;

void OverpassQueryManager::execute(OverpassQuery *query)
{
    // validate input
    if (query->query().isEmpty() || query->boundingBox().isNull() || !query->boundingBox().isValid() || query->tileSize().isNull() || !query->tileSize().isValid()) {
        query->m_error = OverpassQuery::QueryError;
        QTimer::singleShot(0, query, &OverpassQuery::finished);
        return;
    }

    // generate tasks for the query
    const auto xTileCount = std::max<int>(1, query->boundingBox().width() / query->tileSize().width());
    const auto yTileCount = std::max<int>(1, query->boundingBox().height() / query->tileSize().height());
    const auto xTileSize = query->boundingBox().width() / xTileCount;
    const auto yTileSize = query->boundingBox().height() / yTileCount;
    qDebug() << "Creating" << xTileCount * yTileCount << "tasks with tile size" << xTileSize << "x" << yTileSize;
    for (auto x = 0; x < xTileCount; ++x) {
        for (auto y = 0; y < yTileCount; ++y) {
            auto task = std::make_unique<OverpassQueryTask>();
            task->query = query;
            task->bbox = { query->boundingBox().x() + x * xTileSize, query->boundingBox().y() + y * yTileSize, xTileSize, yTileSize };
            d->m_tasks.push_back(std::move(task));
        }
    }

    d->executeTasks();
}

void OverpassQueryManagerPrivate::executeTasks()
{
    const auto now = QDateTime::currentDateTimeUtc();
    std::chrono::seconds nextSlot = std::chrono::hours(1);

    for (auto &executor : m_executors) {
        if (m_tasks.empty()) { // nothing to do
            return;
        }

        if (executor.task) { // executor is busy already
            continue;
        }

        if (executor.nextSlot > now) { // executor is still in rate limit cooldown
            nextSlot = std::min(std::chrono::seconds(now.secsTo(executor.nextSlot)), nextSlot);
            nextSlot += std::chrono::seconds(1); // for msec rounding errors that would other wise give us a busy loop
            if (m_tasks.front()->forceReload) {
                continue;
            }
        }

        executor.task = std::move(m_tasks.front());
        m_tasks.pop_front();

        // actually execute query
        auto url = executor.endpoint;
        QUrlQuery params;
        params.addQueryItem(QStringLiteral("data"), executor.task->query->query(executor.task->bbox));
        url.setQuery(params);
        QNetworkRequest req(url);
        req.setAttribute(QNetworkRequest::CacheLoadControlAttribute, executor.task->forceReload ? QNetworkRequest::PreferNetwork : QNetworkRequest::AlwaysCache);
        auto reply = m_nam->get(req);
        // TODO enable stream parsing for XML replies by connecting to QNetworkReply::readyRead
        QObject::connect(reply, &QNetworkReply::finished, q, [this, &executor, reply]() {
            taskFinished(&executor, reply);
            reply->deleteLater();
        });
    }

    m_nextTaskTimer->start(nextSlot);
}

void OverpassQueryManagerPrivate::taskFinished(OverpassQueryExecutor *executor, QNetworkReply *reply)
{
    auto query = executor->task->query;
    if (reply->error() == QNetworkReply::UnknownContentError && reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 429) {
        // rate limiting error
        executor->cooldownTime *= 2;
        qDebug() << "rate limit error, increasing cooldown time to" << executor->cooldownTime.count() << "seconds";
        m_tasks.push_back(std::move(executor->task));
    } else if (reply->error() == QNetworkReply::ContentNotFoundError && !executor->task->forceReload) {
        // cache miss, retry from network
        executor->task->forceReload = true;
        m_tasks.push_back(std::move(executor->task));
    } else if (reply->error() != QNetworkReply::NoError) {
        // TODO disable affected executors here and reschedule the failed task, rather than cancelling entirely
        qDebug() << reply->error() << reply->errorString() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute) << reply->readAll();
        query->m_error = OverpassQuery::NetworkError;
        cancelQuery(query);
    } else {
        const auto queryError = query->processReply(reply);
        // on query timeout, break up the task in 4 sub-tasks, if we are allowed to
        if (queryError == OverpassQuery::QueryTimeout
            && executor->task->bbox.width() > query->minimumTileSize().width()
            && executor->task->bbox.height() > query->minimumTileSize().height())
        {
            qDebug() << "Splitting task due to query timeout:" << executor->task->bbox;
            const auto xTileSize = executor->task->bbox.width() / 2.0;
            const auto yTileSize = executor->task->bbox.height() / 2.0;
            for (auto x = 0; x < 2; ++x) {
                for (auto y = 0; y < 2; ++y) {
                    auto task = std::make_unique<OverpassQueryTask>();
                    task->query = query;
                    task->bbox = { executor->task->bbox.x() + x * xTileSize, executor->task->bbox.y() + y * yTileSize, xTileSize, yTileSize };
                    m_tasks.push_back(std::move(task));
                }
            }
        }
        else if (queryError != OverpassQuery::NoError) {
            if (executor->task->forceReload) {
                query->m_error = queryError;
                cancelQuery(query);
            } else {
                // query error in cached result, retry
                executor->task->forceReload = true;
                m_tasks.push_back(std::move(executor->task));
            }
        }
    }

    // free the executor for the next query
    executor->task.reset();
    executor->nextSlot = QDateTime::currentDateTimeUtc().addSecs(executor->cooldownTime.count());

    checkQueryFinished(query);
    executeTasks();
}

void OverpassQueryManagerPrivate::checkQueryFinished(OverpassQuery *query) const
{
    if (std::any_of(m_executors.begin(), m_executors.end(), [query](const auto &executor) { return executor.task && executor.task->query == query; })
        || std::any_of(m_tasks.begin(), m_tasks.end(), [query](const auto &task) { return task->query == query; }))
        return;
    emit query->finished();
}

void OverpassQueryManagerPrivate::cancelQuery(OverpassQuery *query)
{
    qDebug() << "cancelling query...";
    m_tasks.erase(std::remove_if(m_tasks.begin(), m_tasks.end(), [query](const auto &task) { return task->query == query; }), m_tasks.end());
    checkQueryFinished(query);
}

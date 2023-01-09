/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "overpassquery.h"
#include "io.h"

#include <QNetworkReply>

using namespace OSM;

OverpassQuery::OverpassQuery(QObject* parent)
    : QObject(parent)
{
}

OverpassQuery::~OverpassQuery() = default;

QString OverpassQuery::query() const
{
    return m_query;
}

QString OverpassQuery::query(const QRectF &bbox) const
{
    const QString bboxStr = QString::number(bbox.y()) + QLatin1Char(',') + QString::number(bbox.x()) + QLatin1Char(',') + QString::number(bbox.y() + bbox.height()) + QLatin1Char(',') + QString::number(bbox.x() + bbox.width());
    auto q = m_query;
    return q.replace(QLatin1String("{{bbox}}"), bboxStr);
}

void OverpassQuery::setQuery(const QString &query)
{
    m_query = query;
}

QRectF OverpassQuery::boundingBox() const
{
    return m_bbox;
}

void OverpassQuery::setBoundingBox(const QRectF &bbox)
{
    m_bbox = bbox;
}

QSizeF OverpassQuery::tileSize() const
{
    return m_tileSize;
}

void OverpassQuery::setTileSize(const QSizeF &tileSize)
{
    m_tileSize = tileSize;
}

QSizeF OverpassQuery::minimumTileSize() const
{
    return m_minimumTileSize;
}

void OverpassQuery::setMinimumTileSize(const QSizeF &minTileSize)
{
    m_minimumTileSize = minTileSize;
}

OverpassQuery::Error OverpassQuery::error() const
{
    return m_error;
}

const DataSet& OverpassQuery::result() const
{
    return m_result;
}

DataSet&& OverpassQuery::takeResult()
{
    return std::move(m_result);
}

OverpassQuery::Error OverpassQuery::processReply(QNetworkReply *reply)
{
    auto reader = OSM::IO::readerForMimeType(u"application/vnd.openstreetmap.data+xml", &m_result);
    if (!reader) {
        qWarning() << "No support for reading OSM XML available!";
        return QueryError;
    }
    reader->read(reply);
    if (!reader->errorString().isEmpty()) {
        qWarning() << "Query error:" << reader->errorString();
        qWarning() << "Request:" << reply->request().url();
        return reader->errorString().contains(QLatin1String("timed out"), Qt::CaseInsensitive) ? QueryTimeout : QueryError;
    }
    qDebug() << "Nodes:" << m_result.nodes.size();
    qDebug() << "Ways:" << m_result.ways.size();
    qDebug() << "Relations:" << m_result.relations.size();
    return NoError;
}
